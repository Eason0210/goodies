using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace CSharpReadAndFit
{
    public partial class MainForm : Form
    {
        // =========================================================================================
        // ========================================= Members =======================================

        private IMInspectLib.IMInspect m_imInspect = null;

        // =========================================================================================
        // ========================================= Methods =======================================

        // =========================================================================================
        // Constructor
        // -----------------------------------------------------------------------------------------
        public MainForm()
        {
            InitializeComponent();
        }

        // =========================================================================================
        // Upon loading the form
        // -----------------------------------------------------------------------------------------
        private void MainForm_Load( object sender, EventArgs e )
        {
            m_imInspect = new IMInspectLib.IMInspect();
        }

        // =========================================================================================
        // Cleanup upon destruction of the form
        // -----------------------------------------------------------------------------------------
        private void MainForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            m_imInspect = null;
        }

        // =========================================================================================
        // Main action of this application
        // -----------------------------------------------------------------------------------------
        private void ButtonSend_Click(object sender, EventArgs e)
        {
            LabelResult.Text = "";

            // If the server does not exists, return
            if ( m_imInspect == null )
            {
                return;
            }

            // Obtain PolyWorks|Inspector's current project
            IMInspectLib.IIMInspectProject imInspectProject = null;
            m_imInspect.ProjectGetCurrent( out imInspectProject );

            if ( imInspectProject == null )
            {
                return;
            }

            // Read the file and fill the coordinates and normals lists
            System.Collections.Generic.List<float> coordinates = new System.Collections.Generic.List<float>();
            System.Collections.Generic.List<float> normals = new System.Collections.Generic.List<float>();
            System.Collections.Generic.List<Byte> colors = new System.Collections.Generic.List<Byte>();

            if ( !FillArraysFromFile( TextFileName.Text, ref coordinates, ref normals ) )
            {
                return;
            }

            // Set all points to a blue color
            for ( int index = 0; index < coordinates.Count; index += 3 )
            {
                colors.Add( 32 );
                colors.Add( 32 );
                colors.Add( 224 );
            }

            // Obtain the name of the file, without the path
            string[] tokens = TextFileName.Text.Split( new Char[] { '\\' } );
            string objectName = tokens[ tokens.Length - 1 ];

            // Create a point cloud in the current PolyWorks|Inspector project
            IMInspectLib.IIMPointCloud imPointCloud = null;
            imInspectProject.PointCloudCreateData( out imPointCloud, objectName, 0 );

            // Send the points to the point cloud
            if ( imPointCloud != null )
            {
                Array coordinatesArray = coordinates.ToArray();
                Array normalsArray = normals.ToArray();
                Array colorsArray = colors.ToArray();

                imPointCloud.PointsAdd( ref coordinatesArray, ref normalsArray, ref colorsArray );
            }

            // Obtain a Command Center from the current PolyWorks|Inspector project
            IMInspectLib.IIMCommandCenter imCommandCenter = null;
            imInspectProject.CommandCenterCreate( out imCommandCenter );

            // Send commands to fit a sphere on all the elements of this new object
            String script;
            String sphereName;

            if ( imCommandCenter != null )
            {
                imCommandCenter.CommandExecute( "TREEVIEW OBJECT SELECT NONE" );
                imCommandCenter.CommandExecute( String.Concat( "TREEVIEW OBJECT_ELEMENTS SELECT ALL ( \"", objectName, "\" ) " ) );

                // Perform the fit and obtain the fitted sphere's name
                script = String.Concat( "version \"5.0\"", "\n", 
                                        "DECLARE nbSpheres", "\n",
                                        "DECLARE lastSphereName", "\n",
                                        "MACRO END_ON_ERROR ( \"On\" )", "\n",
                                        "FEATURE PRIMITIVE SPHERE FIT_SELECTED_ELEMENTS", "\n",
                                        "TREEVIEW PRIMITIVE SPHERE COUNT GET( nbSpheres )", "\n",
                                        "TREEVIEW PRIMITIVE SPHERE NAME GET( $nbSpheres, lastSphereName )", "\n" );

                int returnValue = imCommandCenter.ScriptExecuteFromBuffer( script, "" );
                if ( imCommandCenter.ReturnValueIsSuccess( returnValue ) == 1 )
                {
                    returnValue = imCommandCenter.ScriptVariableGetValueAsString( "lastSphereName", 1, out sphereName );
                    if ( imCommandCenter.ReturnValueIsSuccess( returnValue ) == 1 )
                    {
                        LabelResult.Text = String.Concat( "Sphere \"", sphereName, "\" was successfully fitted" );
                    }
                }
                
                if ( imCommandCenter.ReturnValueIsSuccess( returnValue ) == 0 )
                {                    
                    LabelResult.Text = "The fitting was unsuccessful";
                }
            }

            // Cleanup
            imPointCloud = null;
            imCommandCenter = null;
            imInspectProject = null;
        }

        // =========================================================================================
        // ======================================== Utilities ======================================

        // =========================================================================================
        // Reads an ASCII file containing lines made of 6 values (X,Y,Z,I,J,K)
        // and fills a coordinates and a normals lists with those values
        // -----------------------------------------------------------------------------------------
        private bool FillArraysFromFile(
            String filename_,
            ref System.Collections.Generic.List<float> coordinates_,
            ref System.Collections.Generic.List<float> normals_)
        {
            // Validate file name
            if ( !File.Exists( filename_ ) )
            {
                return false;
            }

            // Open the file for reading
            StreamReader reader = new StreamReader( filename_ );
            String line;
            bool success = true;

            // Read the first six tokens (X,Y,Z,I,J,K) on each line of the file
            // and convert them to double-precision floating point values
            while ( ( line = reader.ReadLine() ) != null )
            {
                string[] tokens = line.Split( new Char[] { ' ' } );

                if ( tokens.Length < 6 )
                {
                    success = false;

                    break;
                }

                // Recording coordinates
                coordinates_.Add( Convert.ToSingle( tokens[ 0 ] ) );
                coordinates_.Add( Convert.ToSingle( tokens[ 1 ] ) );
                coordinates_.Add( Convert.ToSingle( tokens[ 2 ] ) );

                // Recording normals
                normals_.Add( Convert.ToSingle( tokens[ 3 ] ) );
                normals_.Add( Convert.ToSingle( tokens[ 4 ] ) );
                normals_.Add( Convert.ToSingle( tokens[ 5 ] ) );
            }

            reader.Close();

            return success;
        }
    }
}