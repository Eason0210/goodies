using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace CSharpWallCreation
{
    public partial class MainForm : Form
    {
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
        // Main action of this application
        // -----------------------------------------------------------------------------------------
        private void ButtonStart_Click(object sender, EventArgs e)
        {
            IMEditLib.IMEdit imEditObject = new IMEditLib.IMEdit();

            TextLog.Text = "";

            // If the server does not exists, return
            if ( imEditObject == null )
            {
                return;
            }

            // Obtain PolyWorks|Modeler's current project
            IMEditLib.IIMEditProject projectObject = null;
            imEditObject.ProjectGetCurrent( out projectObject );

            if ( projectObject == null )
            {
                imEditObject = null;
                return;
            }

            // Obtain a Command Center from the current PolyWorks|Modeler project
            IMEditLib.IIMCommandCenter imCommandCenter = null;
            projectObject.CommandCenterCreate(out imCommandCenter);

            // Send commands
            String buffer;
            int result;

            if ( imCommandCenter != null )
            {
                buffer = "FILE NEW_PROJECT";
                TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                imCommandCenter.CommandExecute( buffer );

                buffer = "TREEVIEW MODEL VIEW DEFAULT_STATIC FLAT";
                TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                imCommandCenter.CommandExecute( buffer );

                buffer = String.Concat( "FILE IMPORT_MODEL POLYGONAL_FILE ( \"", TextSource.Text, "\" )" );
                TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                result = imCommandCenter.CommandExecute( buffer );

                // If the previous operation was not a success, we're finished
                if ( imCommandCenter.ReturnValueIsSuccess( result ) != 0 )
                {
                    buffer = "EDIT PLANE CREATE XY_PLANE";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "EDIT OBJECT INVERT_ORIENTATION";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "SELECT TRIANGLES ALL";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "EDIT TRIANGLES OFFSET NORMAL ( -1.0, \"On\", \"Off\", 180.0 )";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "SELECT TRIANGLES ALL";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "EDIT TRIANGLES SLICE_WITH_A_PLANE INSERT_INTERSECTION";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "SELECT TRIANGLES USING_PLANES BELOW";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "EDIT DELETE LAST";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "TREEVIEW OBJECT VIEW HIDE";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "VIEW POSE CENTER";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );

                    buffer = "EDIT TRIANGLES CREATE_WALLS ( 3.0 )";
                    TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                    imCommandCenter.CommandExecute( buffer );
                }
            }

            // Cleanup
            imCommandCenter = null;
            projectObject = null;
            imEditObject = null;
        }
    }
}