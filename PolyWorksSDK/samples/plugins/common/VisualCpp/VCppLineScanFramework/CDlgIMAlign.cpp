// =================================================================================================
//   Plug-in dialog for IMAlign implementation.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CDlgIMAlign.h"

#include <PolyWorksSDK/COM/IIMAlign.h>
#include <PolyWorksSDK/COM/IIMAlignProject_i.c>
#include <float.h>
#include <sstream>

#include "ApplicationUtils.h"
#include "CCompanyNameScannerReceiver.h"
#include "CCompanyNameScannerSettings.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================
static const wchar_t* const _cmdDigitizeDeviceScanSurfaceImageName = L"DIGITIZE DEVICE SCAN SURFACE IMAGE NAME";

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

// =================================================================================================
//   Constructor.
// -------------------------------------------------------------------------------------------------
CDlgIMAlign::CDlgIMAlign( CWnd* pParent_ /*= nullptr*/ )
: CDlgCompanyName( IDD, pParent_ )
{

}


// =================================================================================================
//   Destructor.
// -------------------------------------------------------------------------------------------------
CDlgIMAlign::~CDlgIMAlign()
{

}


// =================================================================================================
// Message map.
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CDlgIMAlign, CDlgCompanyName )
    ON_BN_CLICKED( IDC_BUTTON_OPTIONS, &CDlgIMAlign::OnClickedOptions )
    ON_EN_KILLFOCUS( IDC_EDIT_SCAN_NAME, &CDlgIMAlign::OnKillFocusScanName )
END_MESSAGE_MAP()


// =================================================================================================
//   Creates the IMAlign dialog.
// -------------------------------------------------------------------------------------------------
bool CDlgIMAlign::DialogCreate()
{
    // Ask the base class to do the rest of the creation
    return CompanyNameDialogCreate();
}


// =================================================================================================
//   Updates the dialog.
// -------------------------------------------------------------------------------------------------
void CDlgIMAlign::DialogUpdate()
{
    // Get the application scan name
    TWStrings    objectNames;
    std::wstring currentChoice;

    if ( m_pReceiver != nullptr )
    {
        m_pReceiver->ScanningObjectsGet( E_SCAN_TYPE_SURFACE, objectNames, currentChoice );
    }

    m_scanName.SetWindowText( currentChoice.c_str() );

    // Display number of points
    if ( m_pReceiver != nullptr )
    {
        UpdateNbPoints( static_cast< int >( m_pReceiver->NbPointsRecordedGet() ) );
    }

    // Ask the base class to do the rest
    __super::DialogUpdate();
}


// =================================================================================================
//   MFC function to transfer data between GUI and variables.
// -------------------------------------------------------------------------------------------------
void CDlgIMAlign::DoDataExchange( CDataExchange* pDX_ )
{
    __super::DoDataExchange( pDX_ );

    DDX_Control( pDX_, IDC_EDIT_SCAN_NAME,        m_scanName );
    DDX_Control( pDX_, IDC_EDIT_NUMBER_OF_POINTS, m_nbPoints );
}


// =================================================================================================
//   Activates or deactivates controls related to scanning.
//
// Parameter : enable_ : true to activate, false to deactivate
// -------------------------------------------------------------------------------------------------
void CDlgIMAlign::EnableScanControls( bool enable_ )
{
    // TODO: Set the enabled state of all the "Auto-organize parameters" according to the value of enable_
    m_scanName.EnableWindow( enable_ );
}

// =================================================================================================
//   Handling the Options button.
// -------------------------------------------------------------------------------------------------
void CDlgIMAlign::OnClickedOptions()
{
    if ( m_pReceiver != nullptr )
    {
        m_pReceiver->DlgIMAlignOptionsShow( this );
    }
}

// =================================================================================================
//   Handling the WM_INITDIALOG message.
// -------------------------------------------------------------------------------------------------
BOOL CDlgIMAlign::OnInitDialog()
{
    // Ask the base class to do the rest
    BOOL result = __super::OnInitDialog();

    m_nbPoints.SetWindowText( L"0" );

    return result;
}

// =================================================================================================
//   Handling scan name edit box kill focus.
// -------------------------------------------------------------------------------------------------
void CDlgIMAlign::OnKillFocusScanName()
{
    CString scanNameText;
    m_scanName.GetWindowText( scanNameText );

    // Send new name to application
    std::wstring cmd = std::wstring( _cmdDigitizeDeviceScanSurfaceImageName ) + L"(\"" + scanNameText.GetString() + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}


// =================================================================================================
//   Update the number of points on the dialog.
//
// Parameter : nbPoints_ : number of points
// -------------------------------------------------------------------------------------------------
void CDlgIMAlign::UpdateNbPoints( int nbPoints_ )
{
    m_nbPoints.SetWindowText( ValueToString( nbPoints_ ).c_str() );
}


// =================================================================================================
//   Obtain the X position of the window.
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgIMAlign::WindowPositionXGet()
{
    return theCompanyNameScannerSettings().IMAWindowPositionXGet();
}


// =================================================================================================
//   Set the X position of the window.
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgIMAlign::WindowPositionXSet( long position_ )
{
    theCompanyNameScannerSettings().IMAWindowPositionXSet( position_ );
}


// =================================================================================================
//   Obtain the Y position of the window.
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgIMAlign::WindowPositionYGet()
{
    return theCompanyNameScannerSettings().IMAWindowPositionYGet();
}


// =================================================================================================
//   Sets the Y position of the window.
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgIMAlign::WindowPositionYSet( long position_ )
{
    theCompanyNameScannerSettings().IMAWindowPositionYSet( position_ );
}
