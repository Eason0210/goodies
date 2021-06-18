/* *****************************************************************************
 * File: Program.cs
 *
 * Description :
 *
 *      Defines the entry point for the console application.
 *      This application demonstrates how to interact with the Workspace Manager
 *      and its modules. The application shows how to run a command, how to start
 *      a new module, how to get a list of the already running modules and how 
 *      to get an access to a specific module using its project name.
 * -----------------------------------------------------------------------------
 * InnovMetric Inc. Copyright ( C ) 2016
 *                            All rights reserved
 *
 * ************************************************************************** */
using System;

namespace CSharpManageModules
{
    class Program
    {
        /* *****************************************************************************
         * Name: ModuleCommandCenterGet
         *
         * Description : 
         *
         *   Returns the command center for a specific module.
         *
         * Parameter: imInspect_ : Module interface
         *
         * Return: Module command center
         * -------------------------------------------------------------------------- */
        static IMInspectLib.IIMCommandCenter ModuleCommandCenterGet(IMInspectLib.IIMInspect imInspect_)
        {
            if( imInspect_ == null )
            {
                return null;
            }

            IMInspectLib.IIMInspectProject imInspectProject = null;
            imInspect_.ProjectGetCurrent(out imInspectProject);

            if (imInspectProject == null)
            {
                return null;
            }

            // Obtain a Command Center from the current PolyWorks|Inspector project
            IMInspectLib.IIMCommandCenter imInspectCommandCenter = null;
            imInspectProject.CommandCenterCreate(out imInspectCommandCenter);
            return imInspectCommandCenter;
        }

        /* *****************************************************************************
         * Name: Main
         *
         * Description : 
         *
         *   Main routine
         *
         * Parameter: args : array of arguments
         * -------------------------------------------------------------------------- */
        [STAThread]
        static void Main(string[] args)
        {
            // Create a COM Message Filter to prevent COM calls from being rejected if the server application is temporarily busy
            using ( var comMessageFilter = IM.CComMessageFilter.Create() )
            {
                System.Diagnostics.Debug.Assert( comMessageFilter != null );
                long cmdExecRes = 0;

                // Start the Workspace Manager
                IMWorkspaceManagerLib.IIMWorkspaceManager2 workspaceManager2;

                string progID = "InnovMetric.PolyWorks.WorkspaceManager";
                // With the line above, your program will attempt to connect exclusively with the last installed version of PolyWorks, regardless of what version it is. 
                // If the user wants to work with a specific version of PolyWorks, change the progID to the desired version (a.s "InnovMetric.PolyWorks.WorkspaceManager.18".
                try
                {
                    workspaceManager2 = Activator.CreateInstance(Type.GetTypeFromProgID(progID)) as IMWorkspaceManagerLib.IIMWorkspaceManager2;
                }
                catch
                {
                    return;
                }

                // Get the Workspace Manager command center
                IMWorkspaceManagerLib.IIMCommandCenter wmCommandCenter = null;
                workspaceManager2.CommandCenterCreate(out wmCommandCenter);
                if( wmCommandCenter == null )
                {
                    return;
                }

                // Execute a command on the Workspace Manager
                cmdExecRes = wmCommandCenter.CommandExecute( "MACRO PAUSE( \"Message\", \"Workspace Manager started\" )" );

                // Release the Workspace Manager command center
                System.Runtime.InteropServices.Marshal.ReleaseComObject(wmCommandCenter);
                wmCommandCenter = null;

                // Start a new module and use an empty project
                IMInspectLib.IIMInspect imInspect = workspaceManager2.ModuleStart(IMWorkspaceManagerLib.EPWModuleTypes.E_PW_MODULE_TYPE_IMINSPECT, null, null) as IMInspectLib.IIMInspect;
                // Instead of the ModuleStart that start an empty project, you can uncomment one of the following lines to use a
                // specific workspace project. Use null to use the current workspace. If a workspace is specified, the workspace
                // must be open in the Workspace Manager.
                //IMInspectLib.IIMInspect imInspect = workspaceManager2.ModuleStart(IMWorkspaceManagerLib.EPWModuleTypes.E_PW_MODULE_TYPE_IMINSPECT, null, "Inspector Project") as IMInspectLib.IIMInspect;
                //IMInspectLib.IIMInspect imInspect = workspaceManager2.ModuleStart(IMWorkspaceManagerLib.EPWModuleTypes.E_PW_MODULE_TYPE_IMINSPECT, "C:\\Users\\jsmith\\Documents\\PolyWorks\\MyWorkspace.pwk", "Inspector Project") as IMInspectLib.IIMInspect;
                IMInspectLib.IIMCommandCenter imInspectCommandCenter = ModuleCommandCenterGet(imInspect);
                if( imInspectCommandCenter == null )
                {
                    return;
                }

                // Release the module itself
                imInspect = null;

                // Execute a command on the PolyWorks|Inspector module
                cmdExecRes = imInspectCommandCenter.CommandExecute("MACRO PAUSE( \"Message\", \"Module started\" )");

                // Release the PolyWorks|Inspector command center interface
                System.Runtime.InteropServices.Marshal.ReleaseComObject(imInspectCommandCenter);
                imInspectCommandCenter = null;

                // Get a list of PolyWorks|Inspector running modules
                Array workspaces = null;
                Array projects = null;
                workspaceManager2.RunningModulesGet(IMWorkspaceManagerLib.EPWModuleTypes.E_PW_MODULE_TYPE_IMINSPECT, out workspaces, out projects);
                if (workspaces == null || projects == null)
                {
                    return;
                }

                // Get a pointer to an already running module
                imInspect = workspaceManager2.ModuleGet(workspaces.GetValue(0) as String, projects.GetValue(0) as String ) as IMInspectLib.IIMInspect;
                imInspectCommandCenter = ModuleCommandCenterGet(imInspect);
                if (imInspectCommandCenter == null)
                {
                    return;
                }

                // Release the module itself
                System.Runtime.InteropServices.Marshal.ReleaseComObject(imInspect);
                imInspect = null;

                // Execute a command on the PolyWorks|Inspector module
                cmdExecRes = imInspectCommandCenter.CommandExecute("MACRO PAUSE( \"Message\", \"Command executed\" )" );

                // Close the PolyWorks|Inspector module
                cmdExecRes = imInspectCommandCenter.CommandExecute("FILE EXIT");

                // Release the PolyWorks|Inspector module to make sure its not used anymore by the current application.
                // Note that any call to the module fails when the COM server is closed (including this one).
                System.Runtime.InteropServices.Marshal.ReleaseComObject(imInspectCommandCenter);
                imInspectCommandCenter = null;

                // Release the Workspace Manager
                // This last release should also close the Workspace Manager
                System.Runtime.InteropServices.Marshal.ReleaseComObject(workspaceManager2);
                workspaceManager2 = null;
            }
        }
    }
}
