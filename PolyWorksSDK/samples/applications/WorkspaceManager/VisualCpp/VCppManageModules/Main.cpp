/* *****************************************************************************
 * File: Main.cpp
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

// ===========================================================================
// INCLUDED FILES
// ===========================================================================
#include <PolyWorksSDK/COM/IIMCommandCenter.h>
#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspectProject.h>
#include <PolyWorksSDK/COM/IIMWorkspaceManager2.h>
#include <PolyWorksSDK/COM/IIMWorkspaceManager2_i.c>
#include <PolyWorksSDK/COM/IMWorkspaceManager_i.c>
#include <atlcomcli.h>
#include <atlsafe.h>

#include "CComMessageFilter.h"

// ===========================================================================
// CONSTANTS
// ===========================================================================

// ===========================================================================
// GLOBAL VARIABLES
// ===========================================================================

// ===========================================================================
// CLASS DEFINITIONS
// ===========================================================================
class CCOMInitRAII
{
public:
    CCOMInitRAII()
    {
        m_hr = CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );
    }
    ~CCOMInitRAII()
    {
        if ( SUCCEEDED( m_hr ) )
        {
            CoUninitialize();
        }
    }

    HRESULT m_hr;
};

// ===========================================================================
// FUNCTION DEFINITIONS
// ===========================================================================

/* *****************************************************************************
 *   Returns the command center for a specific module.
 *
 * Parameter: pIUnkown_ : Module interface
 *
 * Return: Pointer to the command center
 * -------------------------------------------------------------------------- */
CComPtr< IIMCommandCenter > ModuleCommandCenterGet( IUnknown* pIUnknown_ )
{
    CComQIPtr< IIMInspect > pIIMInspect( pIUnknown_ );
    if ( pIIMInspect != nullptr )
    {
        CComPtr< IIMInspectProject > pIIMInspectProject;
        pIIMInspect->ProjectGetCurrent( &pIIMInspectProject );
        if ( pIIMInspectProject != nullptr )
        {
            CComPtr< IIMCommandCenter > pCommandCenter;
            pIIMInspectProject->CommandCenterCreate( &pCommandCenter );
            return pCommandCenter;
        }
    }

    return nullptr;
}

/* *****************************************************************************
 *   Main routine
 *
 * Parameter: argc   : nb of arguments
 * Parameter: argv[] : array of arguments
 * -------------------------------------------------------------------------- */
int main( int /*argc*/, char* /*argv*/ [] )
{
    long cmdExecRes = 0;

    // Initialize the COM library
    CCOMInitRAII          comInitRAII;
    CRAIIComMessageFilter comMsgFilter;

    // Start the Workspace Manager.
    CComPtr< IIMWorkspaceManager2 > pIIMWorkspaceManager2;

    CLSID progID = CLSID_IMWorkspaceManager;
    // With the line above, your program will attempt to connect exclusively with the version of PolyWorks
    // you're currently working with. If the user upgrades to a more recent version of PolyWorks, your program
    // will not attempt to connect to it.
    // Instead, to let your program attempt to work with the latest version of PolyWorks installed on the
    // user's computer, uncomment the following line and make sure hr is not an error code before continuing.
    //hr = CLSIDFromProgID( L"InnovMetric.PolyWorks.WorkspaceManager", &progID );

    HRESULT hr = CoCreateInstance(
        progID,
        nullptr,
        CLSCTX_SERVER,
        IID_IIMWorkspaceManager2,
        ( void** ) &pIIMWorkspaceManager2 );

    if ( !SUCCEEDED( hr ) || ( pIIMWorkspaceManager2 == nullptr ) )
    {
        return EXIT_FAILURE;
    }

    // Get the Workspace Manager command center
    CComPtr< IIMCommandCenter > pCommandCenter;
    hr = pIIMWorkspaceManager2->CommandCenterCreate( &pCommandCenter );

    if ( !SUCCEEDED( hr ) || ( pCommandCenter == nullptr ) )
    {
        return EXIT_FAILURE;
    }

    // Execute a command on the Workspace Manager
    pCommandCenter->CommandExecute( _T( "MACRO PAUSE( \"Message\", \"Workspace Manager started\" )" ), &cmdExecRes );

    // Release the Workspace Manager command center
    pCommandCenter = nullptr;

    // Start a new module and use an empty project
    CComPtr< IUnknown > pIUnknown;
    hr = pIIMWorkspaceManager2->ModuleStart( E_PW_MODULE_TYPE_IMINSPECT, nullptr, nullptr, &pIUnknown );
    // Instead of the ModuleStart that start an empty project, you can uncomment one of the following lines to use a
    // specific workspace project. Use nullptr to use the current workspace. If a workspace is specified, the workspace
    // must be open in the Workspace Manager.
    // hr = pIIMWorkspaceManager2->ModuleStart( E_PW_MODULE_TYPE_IMINSPECT, nullptr,                                                          _T( "Inspector Project" ), &pIUnknown );
    // hr = pIIMWorkspaceManager2->ModuleStart( E_PW_MODULE_TYPE_IMINSPECT, _T( "C:\\Users\\jsmith\\Documents\\PolyWorks\\MyWorkspace.pwk" ), _T( "Inspector Project" ), &pIUnknown );
    if ( !SUCCEEDED( hr ) || ( pIUnknown == nullptr ) )
    {
        return EXIT_FAILURE;
    }

    // Get a pointer to the command center interface
    CComPtr< IIMCommandCenter > pIMInspectCommandCenter = ModuleCommandCenterGet( pIUnknown );
    if ( pIMInspectCommandCenter == nullptr )
    {
        return EXIT_FAILURE;
    }

    // Release the module itself
    pIUnknown = nullptr;

    // Execute a command on the PolyWorks|Inspector module
    hr = pIMInspectCommandCenter->CommandExecute( _T( "MACRO PAUSE( \"Message\", \"Module started\" )" ), &cmdExecRes );

    // Release the PolyWorks|Inspector command center interface
    pIMInspectCommandCenter = nullptr;

    // Get a list of PolyWorks|Inspector running modules
    LPSAFEARRAY pWorkspaces;
    LPSAFEARRAY pProjects;
    hr = pIIMWorkspaceManager2->RunningModulesGet( E_PW_MODULE_TYPE_IMINSPECT, &pWorkspaces, &pProjects );
    if ( !SUCCEEDED( hr ) || ( pWorkspaces == nullptr ) || ( pProjects == nullptr ) )
    {
        return EXIT_FAILURE;
    }

    CComSafeArray< BSTR > pWorkspacesSA;
    pWorkspacesSA.Attach( pWorkspaces );
    CComSafeArray< BSTR > pProjectsSA;
    pProjectsSA.Attach( pProjects );

    // Get a pointer to an already running module
    hr = pIIMWorkspaceManager2->ModuleGet( pWorkspacesSA[ 0 ], pProjectsSA[ 0 ], &pIUnknown );

    pIMInspectCommandCenter = ModuleCommandCenterGet( pIUnknown );
    if ( !SUCCEEDED( hr ) || ( pIMInspectCommandCenter == nullptr ) )
    {
        return EXIT_FAILURE;
    }

    // Release the module itself
    pIUnknown = nullptr;

    // Execute a command on the PolyWorks|Inspector module
    pIMInspectCommandCenter->CommandExecute( _T( "MACRO PAUSE( \"Message\", \"Command executed\" )" ), &cmdExecRes );

    // Close the PolyWorks|Inspector module
    pIMInspectCommandCenter->CommandExecute( _T( "FILE EXIT" ), &cmdExecRes );

    // Release the PolyWorks|Inspector module to make sure it is not used anymore by the current application.
    // Note that from this point on any call to the module may fail if the COM server is already closed
    // following the FILE EXIT command, including the final release performed below.
    pIMInspectCommandCenter = nullptr;

    // Release the Workspace Manager
    // This last release should also close the Workspace Manager
    pIIMWorkspaceManager2 = nullptr;

    return EXIT_SUCCESS;
}
