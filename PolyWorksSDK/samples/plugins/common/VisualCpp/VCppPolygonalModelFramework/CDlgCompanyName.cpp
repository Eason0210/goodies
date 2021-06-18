// =================================================================================================
// Plug-in dialog class implementation.
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CDlgCompanyName.h"

#include "ApplicationUtils.h"
#include "CCompanyNameScannerSettings.h"
#include "ICompanyNameScanner.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================

IMPLEMENT_DYNAMIC( CDlgCompanyName, CDialogEx )

// =================================================================================================
// Contructor
//
// Parameter: plugin_   : Interface of the plugin
// Parameter: settings_ : Settings
// Parameter: pParent   : Parent dialog
// -------------------------------------------------------------------------------------------------
CDlgCompanyName::CDlgCompanyName( ICompanyNameScanner& plugin_, CCompanyNameScannerSettings& settings_, CWnd* pParent /*=nullptr*/ )
: CDialogEx( IDD_DIALOG_SCAN, pParent )
, m_plugin( plugin_ )
, m_settings( settings_ )
{
}

// =================================================================================================
//   MFC function to transfer data between GUI and variables.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::DoDataExchange( CDataExchange* pDX )
{
    CDialogEx::DoDataExchange( pDX );

    DDX_Control( pDX, IDOK, m_btnScan );
    DDX_Control( pDX, IDCANCEL, m_btnClose );
    DDX_Control( pDX, IDC_BUTTON_MOD_POL_MODEL, m_btnModify );
    DDX_Control( pDX, IDC_EDIT_DATA_OBJECT_NAME, m_dataObjectName );
    DDX_Control( pDX, IDC_CHECK_NEW_DEVICE_POSITION, m_newDevicePositionOnScan );
}

// =================================================================================================
// Messages map
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CDlgCompanyName, CDialogEx )
    ON_WM_MOVE()
    ON_BN_CLICKED( IDC_BUTTON_MOD_POL_MODEL, &CDlgCompanyName::OnBnClickedButtonModPolModel )
    ON_EN_KILLFOCUS( IDC_EDIT_DATA_OBJECT_NAME, &CDlgCompanyName::OnKillFocusDataObjectName )
    ON_BN_CLICKED( IDC_CHECK_NEW_DEVICE_POSITION, &CDlgCompanyName::OnClickCreateNewDevicePositionOnScan )
END_MESSAGE_MAP()

// =================================================================================================
//   Creates the dialog.
// -------------------------------------------------------------------------------------------------
BOOL CDlgCompanyName::DialogCreate()
{
    ASSERT( m_lpszTemplateName != nullptr );

    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    const bool result = Create( m_lpszTemplateName, m_pParentWnd );

    AfxSetResourceHandle( oldInstance );

    return result;
}

// =================================================================================================
//   Destroys the dialog.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::DialogDestroy()
{
    m_plugin.ScanningDlgClosed();

    ExecuteCommandOnApp( L"DIGITIZE DEVICE CONNECT( \"Off\" )", true );

    m_dialogInitialized = false;

    // TODO: Destroy any resources allocated when the dialog was created
}

// =================================================================================================
// Update the controls for a given action
//
// Parameter: action_ : Current action
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::ControlsUpdate( EActions action_ )
{
    switch ( action_ )
    {
        case EActions::NoAction:
            m_dataObjectName.EnableWindow( true );
            m_newDevicePositionOnScan.EnableWindow( true );
            m_btnScan.EnableWindow( true );
            m_btnScan.SetWindowText( L"Start Scan" );
            m_btnClose.EnableWindow( true );
            m_btnModify.EnableWindow( true );
            break;
        case EActions::Scanning:
            m_dataObjectName.EnableWindow( false );
            m_newDevicePositionOnScan.EnableWindow( false );
            m_btnScan.EnableWindow( true );
            m_btnScan.SetWindowText( L"End Scan" );
            m_btnClose.EnableWindow( true );
            m_btnModify.EnableWindow( false );
            break;
        case EActions::Modifying:
            m_dataObjectName.EnableWindow( false );
            m_newDevicePositionOnScan.EnableWindow( false );
            m_btnScan.EnableWindow( false );
            m_btnClose.EnableWindow( false );
            m_btnModify.EnableWindow( true );
            break;
    }

    m_action = action_;
}

// =================================================================================================
// Update the controls
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::ControlsUpdate()
{
    const std::wstring objectName = m_plugin.ObjectNameGet();
    m_dataObjectName.SetWindowText( objectName.c_str() );

    m_newDevicePositionOnScan.SetCheck( m_settings.NewDevicePositionCreateOnScanGet() ? BST_CHECKED : BST_UNCHECKED );

    UpdateData( FALSE );
}

// =================================================================================================
//   Reaction to the WM_INITDIALOG message.
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
    int x = m_settings.WindowPositionXGet();
    int y = m_settings.WindowPositionYGet();
    int w = rect.right;
    int h = rect.bottom;

    // TODO: For added safety, you could make sure that the dialog is within the boundaries of the desktop

    // Move the dialog to its new position
    MoveWindow( x, y, w, h, FALSE );

    m_dialogInitialized = true;

    ControlsUpdate( EActions::NoAction );
    ControlsUpdate();

    return TRUE;
}

// =================================================================================================
//   Reaction to a move.
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
        m_settings.WindowPositionXSet( rect.left );
        m_settings.WindowPositionYSet( rect.top );
    }
}

// =================================================================================================
//   Reaction to the WM_DESTROY message.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnDestroy()
{
    DialogDestroy();

    __super::OnDestroy();
}

// =================================================================================================
//   Reaction to Close button press
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnCancel()
{
    m_settings.SettingsSave();

    ExecuteCommandOnApp( L"DIGITIZE DEVICE SCAN END", true, true, false );

    m_dialogInitialized = false;

    m_plugin.ScanningDlgCloseRequest();
}

// =================================================================================================
//   Reaction to the Scan Start/End button press
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnOK()
{
    if ( m_action == EActions::Scanning )
    {
        ExecuteCommandOnApp( L"DIGITIZE DEVICE SCAN END", true, true, false );
    }
    else
    {
        ControlsUpdate( EActions::Scanning );

        // Before the new scan, if required, create a new device position
        if ( m_settings.NewDevicePositionCreateOnScanGet() )
        {
            if ( !ExecuteCommandOnApp( L"ALIGN DEVICE_POSITION CREATE( , , \"On\" )", true, true, false ) )
            {
                ControlsUpdate( EActions::NoAction );
                return;
            }
        }

        if ( !ExecuteCommandOnApp( L"DIGITIZE DEVICE SCAN START", true, true, false ) )
        {
            ControlsUpdate( EActions::NoAction );
        }
    }
}

// =================================================================================================
//   Reaction to the Modify Selected Object Data button press
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnBnClickedButtonModPolModel()
{
    ControlsUpdate( EActions::Modifying );

    // Retrieve the selection from the treeview
    std::wstring dataObjectsCount;
    ValueStrGetFromApp( L"TREEVIEW DATA COUNT SELECTED GET", dataObjectsCount, false );
    if ( dataObjectsCount != L"1" )
    {
        IMMessageBox( E_MESSAGE_TYPE_INFORMATION, L"Select a single data object in the treeview to replace its polygonal model" );
        ControlsUpdate( EActions::NoAction );
        return;
    }

    // Retrieve the unique id of the data object
    std::wstring uniqueID;
    ValueStrGetFromApp( L"TREEVIEW OBJECT PROPERTIES UNIQUE_ID GET", uniqueID, false );
    if ( uniqueID.empty() )
    {
        ControlsUpdate( EActions::NoAction );
        return;
    }

    // Replace the data for this polygonal model
    m_plugin.PolygonalModelReplace( uniqueID );

    // Center the display to the new data
    ExecuteCommandOnApp( L"VIEW POSE CENTER", true, false, false );

    ControlsUpdate( EActions::NoAction );
}

// =================================================================================================
//   Reaction to data object name kill focus.
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnKillFocusDataObjectName()
{
    CString dataObject;
    m_dataObjectName.GetWindowText( dataObject );

    // Make sure data object name is unique
    const std::wstring uniqueDataObject = ObtainUniqueNameFromApp( static_cast< LPCWSTR >( dataObject ) );

    // Send new name to application
    const std::wstring cmd = L"DIGITIZE DEVICE SCAN SURFACE DATA_OBJECT NAME(\"" + uniqueDataObject + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Reaction to the Create New Device Position On scan start check box
//
// -------------------------------------------------------------------------------------------------
void CDlgCompanyName::OnClickCreateNewDevicePositionOnScan()
{
    const bool createNewDevicePositionOnScan = m_newDevicePositionOnScan.GetCheck() == BST_CHECKED;
    m_settings.NewDevicePositionCreateOnScanSet( createNewDevicePositionOnScan );
}
