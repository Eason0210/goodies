// =================================================================================================
//   Plug-in dialog base class implementation.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CDlgCompanyName.h"

#include <PolyWorksSDK/COM/IIMHost.h>
#include <PolyWorksSDK/COM/IIMScannerFeedback2.h>
#include <PolyWorksSDK/COM/IIMScannerFeedback2_i.c>
#include <assert.h>

#include "ApplicationUtils.h"
#include "CCompanyNameScannerReceiver.h"
#include "CCompanyNameScannerSettings.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const wchar_t* STR_NONE = L"None";

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

IMPLEMENT_DYNAMIC( CDlgCompanyName, CDialog )

// =================================================================================================
//   Constructor.
// -------------------------------------------------------------------------------------------------
CDlgCompanyName::CDlgCompanyName( UINT IDD_, CWnd* pParent_ /*=nullptr*/ )
: CDialog( IDD_, pParent_ )
, m_pReceiver( nullptr )
, m_scanIsStarted( false )
, m_dialogInitialized( false )
{

}


// =================================================================================================
//   Destructor.
// -------------------------------------------------------------------------------------------------
CDlgCompanyName::~CDlgCompanyName()
{
    if ( m_dialogInitialized )
    {
        OnCancel();
    }
}


// =================================================================================================
// Message map.
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CDlgCompanyName, CDialog )
    ON_WM_DESTROY()
    ON_WM_MOVE()
    ON_BN_CLICKED( IDC_CHECK_TEST_MODE, OnClickedTestMode )
END_MESSAGE_MAP()


// =================================================================================================
//   Destroys the dialog.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::DialogDestroy()
{
    // Notify the host application
    CComPtr< IIMScannerFeedback2 > pScannerFeedback;
    GITGetInterfaceFromGlobal( g_cookieScannerFeedback, IID_IIMScannerFeedback2, ( void** ) &pScannerFeedback );
    if ( pScannerFeedback != nullptr )
    {
        pScannerFeedback->ScanningDlgClosed();
    }

    std::wstring command = L"DIGITIZE DEVICE CONNECT";
    command += L"( \"Off\" )";
    ExecuteCommandOnApp( command.c_str(), true );

    m_dialogInitialized = false;

    // TODO: Destroy any resources allocated when the dialog was created
}


// =================================================================================================
//   Handling the Close button.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnCancel()
{
    ScanEnd();
    PreDestroy();

    m_dialogInitialized = false;

    if ( IsInit() )
    {
        m_pReceiver->InterfacePopdown();
    }
    else
    {
        __super::OnCancel();
    }
}


// =================================================================================================
//   Handling the Test Mode check box.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnClickedTestMode()
{
    // Set the Test Mode config
    theCompanyNameScannerSettings().TestModeSet( m_testMode.GetCheck() == BST_CHECKED );
}


// =================================================================================================
//   Handling the WM_DESTROY message.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnDestroy()
{
    DialogDestroy();

    __super::OnDestroy();
}


// =================================================================================================
//   Handling the WM_INITDIALOG message.
// -------------------------------------------------------------------------------------------------
BOOL CDlgCompanyName::OnInitDialog()
{
    BOOL result = __super::OnInitDialog();

    // Place the window to the correct place
    RECT rect;
    GetWindowRect( &rect );

    // Convert the coordinates for use with MoveWindow
    POINT pt;
    pt.x = rect.left;
    pt.y = rect.top;
    ScreenToClient( &pt );
    rect.right  = rect.right - rect.left;
    rect.bottom = rect.bottom - rect.top;
    rect.left   = pt.x;
    rect.top    = pt.y;

    // Set the new position
    int x = WindowPositionXGet();
    int y = WindowPositionYGet();
    int w = rect.right;
    int h = rect.bottom;

    // TODO: For added safety, you could make sure that the dialog is within the boundaries of the desktop

    // Move the dialog to its new position
    MoveWindow( x, y, w, h, FALSE );

    m_dialogInitialized = true;

    DialogUpdate();

    return result;
}


// =================================================================================================
//   Handling a move.
//
// Parameter : x_ : x position (not used)
// Parameter : y_ : y position (not used)
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnMove( int /*x_*/, int /*y_*/ )
{
    if ( m_dialogInitialized )
    {
        // Memorize the position of the window
        RECT rect;
        GetWindowRect( &rect );
        WindowPositionXSet( rect.left );
        WindowPositionYSet( rect.top );
    }
}


// =================================================================================================
//   Handling the Start/End Scan button.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnOK()
{
    if ( m_scanIsStarted )
    {
        ScanEnd();
    }
    else
    {
        ScanStart();
    }
}


// =================================================================================================
//   Handling certain changes.
//
// Parameter : event_ : info on the change
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::Observe( EEvents event_ )
{
    if ( !m_dialogInitialized )
    {
        return;
    }

    switch ( event_ )
    {
        case E_DATA_OBJECT_CHANGE:
            DialogUpdate();
            break;
        case E_DISCONNECT:
            ScanEnd();
            break;
        case E_PASS_START:
            // TODO: Disable the Start/End Scan button
            break;
        case E_PASS_STOP:
            // TODO: Enable the Start/End Scan button
            break;
        case E_SCAN_END:
            CompanyNameEnableScanControls( true );
            break;
        default:
            assert( 0 );
    }
}


// =================================================================================================
//   Creates the common part of the dialog.
// -------------------------------------------------------------------------------------------------
bool CDlgCompanyName::CompanyNameDialogCreate()
{
    ASSERT( m_lpszTemplateName != nullptr );

    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    bool result = ( Create( m_lpszTemplateName, m_pParentWnd ) == TRUE );

    AfxSetResourceHandle( oldInstance );

    return result;
}


// =================================================================================================
//   Activates or deactivates the controls related to scanning.
//
// Parameter : enable_ : true to activate, false to deactivate
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::CompanyNameEnableScanControls( bool enable_ )
{
    if ( !m_dialogInitialized )
    {
        return;
    }

    // Call the virtual method first
    EnableScanControls( enable_ );

    // TODO: Use enable_ to set the enabled state of the following controls:
    //       "Refresh delay",
    //       "Invert digitizing vectors"
    //       "Device vertical axis"
    //       "Scan line close-up zoom (%)"
    m_testMode.EnableWindow( enable_ );
    m_optionsButton.EnableWindow( enable_ );
    m_closeButton.EnableWindow( enable_ );

    if ( enable_ )
    {
        m_startScanButton.SetWindowText( L"Start Scan" );
    }
    else
    {
        m_startScanButton.SetWindowText( L"End Scan" );
    }

    m_scanIsStarted = !enable_;
}


// =================================================================================================
//   Synchronize controls value from configuration.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::DialogUpdate()
{
    // TODO: Use theCompanyNameScannerSettings().RefreshDelayGet() to set the value of the "Refresh delay" edit box
    // TODO: Use theCompanyNameScannerSettings().UseAutoViewpointGet() to set the value of the "Use automatic viewpoint" check box
    // TODO: Use theCompanyNameScannerSettings().InvertDigitizingVectorsGet() to set the value of the "Invert digitizing vectors" check box
    // TODO: Enable the "Device vertical axis" combo box and use theCompanyNameScannerSettings().DeviceVerticalAxisGet() to set its value
    // TODO: Use theCompanyNameScannerSettings().AutoViewpointZoomCloseUpGet() to set the value of the "Scan line close-up zoom (%)" edit box
    m_testMode.SetCheck( theCompanyNameScannerSettings().TestModeGet() ? BST_CHECKED : BST_UNCHECKED );

    UpdateData( FALSE );
}

// =================================================================================================
//   MFC function to transfer data between GUI and variables.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::DoDataExchange( CDataExchange* pDX_ )
{
    __super::DoDataExchange( pDX_ );

    DDX_Control( pDX_, IDC_CHECK_TEST_MODE, m_testMode );
    DDX_Control( pDX_, IDOK,                m_startScanButton );
    DDX_Control( pDX_, IDCANCEL,            m_closeButton );
    DDX_Control( pDX_, IDC_BUTTON_OPTIONS,  m_optionsButton );
}


// =================================================================================================
//   Pops down the dialog.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::Popdown()
{
    if ( m_dialogInitialized )
    {
        OnCancel();
    }
}


// =================================================================================================
//   Pops up the dialog.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::Popup()
{
    if ( !IsInit() )
    {
        return;
    }

    // TODO: if ( the dialog was not created yet )
    {
        DialogCreate();
    }

    //////////////////////////////////////////////////////////////////////////
    // From here on, we are going to make COM calls on the server,
    // which must be able to answer them (i.e. not be waiting on a
    // WaitForSingleObject, for example)
    //////////////////////////////////////////////////////////////////////////

    PreCreate();

    // TODO: Pop up the dialog but do not show it yet

    WindowStyleSet();

    // TODO: Show the dialog (don't show here if it is in the Dialog Zone)
}


// =================================================================================================
//   Pre-creates the dialog.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::PreCreate()
{
}


// =================================================================================================
//   Pre-destroys the dialog.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::PreDestroy()
{
}


// =================================================================================================
//   Ends a scan.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CDlgCompanyName::ScanEnd()
{
    if ( ExecuteCommandOnApp( L"DIGITIZE DEVICE SCAN END", true, true, false ) )
    {
        CompanyNameEnableScanControls( true );

        return true;
    }

    return false;
}


// =================================================================================================
//   Starts a scan.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CDlgCompanyName::ScanStart()
{
    if ( ExecuteCommandOnApp( L"DIGITIZE DEVICE SCAN START", true, true, false ) )
    {
        // Deactivates the controls
        CompanyNameEnableScanControls( false );

        return true;
    }

    return false;
}


// =================================================================================================
//   Uninitialize and popdown the dialog.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::Uninit()
{
    m_pReceiver = nullptr;

    Popdown();
}

// =================================================================================================
//   Change the style of the window so it fits with the Host.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::WindowStyleSet()
{
    if ( !m_dialogInitialized )
    {
        return;
    }

    if ( g_cookieHost == 0 )
    {
        return;
    }

    CComPtr< IIMHost > pHost;
    GITGetInterfaceFromGlobal( g_cookieHost, IID_IIMHost, ( void** )&pHost );

    HWND dialogHandle = nullptr;
    // TODO: Set dialogHandle to the handle of the dialog

    if ( pHost != nullptr )
    {
        long lhwnd = HandleToLong( dialogHandle );
        pHost->WindowStyleSet( &lhwnd );
    }

    // Modify the title of the window
    SetWindowText( L"CompanyName Line Scanner" );
}
