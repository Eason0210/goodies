using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace CSharpSimpleAlignment
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
            IMAlignLib.IMAlign imAlignObject = new IMAlignLib.IMAlign();

            TextLog.Text = "";

            // If the server does not exists, return
            if ( imAlignObject == null )
            {
                return;
            }

            // Obtain IMAlign's current project
            IMAlignLib.IIMAlignProject imAlignProject = null;
            imAlignObject.ProjectGetCurrent( out imAlignProject );

            if ( imAlignProject == null )
            {
                imAlignObject = null;
                return;
            }

            // Obtain a Command Center from the current IMAlign project
            IMAlignLib.IIMCommandCenter imCommandCenter = null;
            imAlignProject.CommandCenterCreate( out imCommandCenter );

            // Send commands
            String buffer;

            if ( imCommandCenter != null )
            {
                buffer = "FILE NEW_PROJECT";
                TextLog.Text = String.Concat (TextLog.Text, buffer, "\r\n" );
                imCommandCenter.CommandExecute( buffer );

                buffer = "CONFIG DIGITIZERS NAME ( \"Generic Close Range (in mm)\" )";
                TextLog.Text = String.Concat( TextLog.Text, buffer, "\r\n" );
                imCommandCenter.CommandExecute( buffer );

                buffer = String.Concat( "FILE IMPORT_IMAGE 3D_DIGITIZED_DATASET PLANAR_GRID DIRECTORY ( \"", TextSource.Text, "\", , \"PIF\" )" );
                TextLog.Text = String.Concat( TextLog.Text, buffer , "\r\n" );
                imCommandCenter.CommandExecute( buffer );

                buffer = "ALIGN START(0.000001, 10)";
                TextLog.Text = String.Concat( TextLog.Text, buffer , "\r\n" );
                imCommandCenter.CommandExecute( buffer );

                buffer = String.Concat( "FILE SAVE_PROJECT_AS( \"", TextDestination.Text, "\\workspace.pwk\", \"IMAlign Project\" )" );
                TextLog.Text = String.Concat( TextLog.Text, buffer , "\r\n" );
                imCommandCenter.CommandExecute( buffer );
            }

            // Cleanup
            imCommandCenter = null;
            imAlignProject = null;
            imAlignObject = null;
        }
    }
}