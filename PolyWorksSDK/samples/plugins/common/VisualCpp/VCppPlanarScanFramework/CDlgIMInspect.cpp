// =================================================================================================
//   Plug-in dialog for IMInspect implementation.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CDlgIMInspect.h"

#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspectProject5.h>
#include <PolyWorksSDK/COM/IIMInspectProject5_i.c>
#include <float.h>

#include "ApplicationUtils.h"
#include "CCompanyNameScannerReceiver.h"
#include "CCompanyNameScannerSettings.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const wchar_t* const _sPolygonalModelNotFinalized = L"The meshing of the polygonal model has not yet been finalized. Do you want to finalize the meshing?\nAnswering No will remove scan passes.";

static const wchar_t* const _sConfigModifyDefaultNameSurfaceScanGet   = L"CONFIG MODIFY DEFAULT_NAME SURFACE_SCAN GET";
static const wchar_t* const _sDigitizeDeviceScanSurfaceDataObjectName = L"DIGITIZE DEVICE SCAN SURFACE DATA_OBJECT NAME";
static const wchar_t* const _sDigitizeDisplayAutomaticViewpoint       = L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT";
static const wchar_t* const _sDigitizeDisplayAutomaticViewpointGet    = L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT GET";

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

extern const wchar_t* g_sDigitizeDeviceSurfaceDataObjectDataStructureGet;

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   Constructor
// -------------------------------------------------------------------------------------------------
CDlgIMInspect::CDlgIMInspect( CWnd* pParent_ /*= nullptr*/ )
: CDlgCompanyName( IDD, pParent_ )
, m_isChangingDataStructOnCreateNew( false )
{

}


// =================================================================================================
//   Destructor
// -----------------------------------------------------------------------------
CDlgIMInspect::~CDlgIMInspect()
{
}


// =================================================================================================
// Message map.
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CDlgIMInspect, CDlgCompanyName )
    ON_BN_CLICKED( IDC_RADIO_POINT_CLOUD,             OnClickedPointCloudDataStructure )
    ON_BN_CLICKED( IDC_RADIO_POLYGONAL_MODEL,         OnClickedPolygonalDataStructure )
    ON_BN_CLICKED( IDC_CHECK_USE_AUTOMATIC_VIEWPOINT, OnClickedUseAutomaticViewpoint )
    ON_EN_KILLFOCUS( IDC_EDIT_DATA_OBJECT_NAME,       OnKillFocusDataObjectName )
    ON_BN_CLICKED( IDC_CHECK_CREATE_NEW_DEVICE_POSITION_ON_SCAN_START, OnClickCreateNewDevicePositionOnScan )
END_MESSAGE_MAP()


// =================================================================================================
//   Creates the IMInspect dialog
// -------------------------------------------------------------------------------------------------
bool CDlgIMInspect::DialogCreate()
{
    // Ask the base class to do the rest
    return CompanyNameDialogCreate();
}

// =================================================================================================
//   Get the application command used to retrieve default surface scan name.
//
// Return : Command name
// -------------------------------------------------------------------------------------------------
const wchar_t* CDlgIMInspect::DefaultNameSurfaceScanCmdNameGet() const
{
    return _sConfigModifyDefaultNameSurfaceScanGet;
}


// =================================================================================================
//   Updates the dialog
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::DialogUpdate()
{
    // Do nothing when changing data structure while data object is set to Create New
    if ( m_isChangingDataStructOnCreateNew )
    {
        return;
    }

    const bool convertToPolygonal = theCompanyNameScannerSettings().IMIConvertToPolygonalGet();
    m_pointCloudDataStructure.SetCheck( convertToPolygonal ? BST_UNCHECKED : BST_CHECKED );
    m_polygonalDataStructure.SetCheck( convertToPolygonal ? BST_CHECKED : BST_UNCHECKED );
    m_createNewDevicePositionOnScanButton.SetCheck( theCompanyNameScannerSettings().CreateNewDevicePositionOnScanGet() );
    m_dataObjectName.Clear();

    // Get the application Data Object names
    std::vector< std::wstring > objectNames;
    std::wstring currentChoice;

    if ( m_pReceiver != nullptr )
    {
        m_pReceiver->ScanningObjectsGet( E_SCAN_TYPE_SURFACE, objectNames, currentChoice );
    }

    m_dataObjectName.SetWindowText( currentChoice.c_str() );

    m_useAutomaticViewpoint.SetCheck( theCompanyNameScannerSettings().UseAutoViewpointGet() );

    EnableScanControls( true );

    // Ask the base class to do the rest
    __super::DialogUpdate();
}

// =================================================================================================
//   MFC function to transfer data between GUI and variables.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::DoDataExchange( CDataExchange* pDX_ )
{
    __super::DoDataExchange( pDX_ );

    DDX_Control( pDX_, IDC_EDIT_DATA_OBJECT_NAME,         m_dataObjectName );
    DDX_Control( pDX_, IDC_RADIO_POINT_CLOUD,             m_pointCloudDataStructure );
    DDX_Control( pDX_, IDC_RADIO_POLYGONAL_MODEL,         m_polygonalDataStructure );
    DDX_Control( pDX_, IDC_CHECK_USE_AUTOMATIC_VIEWPOINT, m_useAutomaticViewpoint );
    DDX_Control( pDX_, IDC_CHECK_CREATE_NEW_DEVICE_POSITION_ON_SCAN_START, m_createNewDevicePositionOnScanButton );
}


// =================================================================================================
//   Activates or deactivates controls related to scanning.
//
// Parameter : enable_ : true to activate, false to deactivate
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::EnableScanControls( bool enable_ )
{
    m_dataObjectName.EnableWindow( enable_ );
    m_pointCloudDataStructure.EnableWindow( enable_ );
    m_polygonalDataStructure.EnableWindow( enable_ );
    m_useAutomaticViewpoint.EnableWindow( enable_ );
    m_createNewDevicePositionOnScanButton.EnableWindow( enable_ );
    bool useRTM = ( m_polygonalDataStructure.GetCheck() == BST_CHECKED );
}

// =================================================================================================
//   Create new device position if needed
//
// Parameter : enable_ : true to activate, false to deactivate
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::CompagnyNameCreateNewDevicePosition()
{
    if ( theCompanyNameScannerSettings().CreateNewDevicePositionOnScanGet() )
    {

        m_pReceiver->CreateNewDevicePositionIfNeeded( true );
    }
}


// =================================================================================================
//   Reaction to the WM_INITDIALOG message
// -------------------------------------------------------------------------------------------------
BOOL CDlgIMInspect::OnInitDialog()
{
    // Ask the base class to do the rest
    return __super::OnInitDialog();
}

// =================================================================================================
//   Reaction to the Create New Device Position On scan start check box
//
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickCreateNewDevicePositionOnScan()
{
    const bool createNewDevicePositionOnScan = m_createNewDevicePositionOnScanButton.GetCheck() == BST_CHECKED;
    theCompanyNameScannerSettings().CreateNewDevicePositionOnScanSet( createNewDevicePositionOnScan );
}

// =================================================================================================
//   Reaction to the Point Cloud data structure radio button.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedPointCloudDataStructure()
{
    m_isChangingDataStructOnCreateNew = true;

    theCompanyNameScannerSettings().IMIConvertToPolygonalSet( false );

    m_isChangingDataStructOnCreateNew = false;

    // Get default name from application
    std::wstring dataObjectName;
    ValueStrGetFromApp( DefaultNameSurfaceScanCmdNameGet(), dataObjectName );

    // Make sure object name is unique
    dataObjectName = ObtainUniqueNameFromApp( dataObjectName );

    // Send new data object name to application
    std::wstring cmd = std::wstring( _sDigitizeDeviceScanSurfaceDataObjectName ) + L"(\"" + dataObjectName + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Reaction to the Polygonal Model data structure radio button.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedPolygonalDataStructure()
{
    m_isChangingDataStructOnCreateNew = true;

    theCompanyNameScannerSettings().IMIConvertToPolygonalSet( true );

    m_isChangingDataStructOnCreateNew = false;

    // Get default name from application
    std::wstring dataObjectName;
    ValueStrGetFromApp( DefaultNameSurfaceScanCmdNameGet(), dataObjectName );

    // Make sure object name is unique
    dataObjectName = ObtainUniqueNameFromApp( dataObjectName );

    // Send new data object name to application
    std::wstring cmd = std::wstring( _sDigitizeDeviceScanSurfaceDataObjectName ) + L"(\"" + dataObjectName + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Reaction to the Use Automatic Viewpoint check box
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedUseAutomaticViewpoint()
{
    const std::wstring useAutomaticViewpoint = ( m_useAutomaticViewpoint.GetCheck() == BST_CHECKED ? L"On" : L"Off" );

    std::wstring cmd = std::wstring( _sDigitizeDisplayAutomaticViewpoint ) + L"(\"" + useAutomaticViewpoint + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Reaction to data object name kill focus.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnKillFocusDataObjectName()
{
    CString dataObjectNameText;
    m_dataObjectName.GetWindowText( dataObjectNameText );

    // Make sure data object name is unique
    std::wstring dataObjectName = ObtainUniqueNameFromApp( dataObjectNameText.GetString() );

    // Send new name to application
    std::wstring cmd = std::wstring( _sDigitizeDeviceScanSurfaceDataObjectName ) + L"(\"" + dataObjectName + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Ends a scan
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CDlgIMInspect::ScanEnd()
{
    if ( !IsInit() )
    {
        return false;
    }

    if ( __super::ScanEnd() )
    {
        return true;
    }

    return false;
}


// =================================================================================================
//   Obtain the X position of the window
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgIMInspect::WindowPositionXGet()
{
    return theCompanyNameScannerSettings().IMIWindowPositionXGet();
}


// =================================================================================================
//   Set the X position of the window
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::WindowPositionXSet( long position_ )
{
    theCompanyNameScannerSettings().IMIWindowPositionXSet( position_ );
}


// =================================================================================================
//   Obtain the Y position of the window
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgIMInspect::WindowPositionYGet()
{
    return theCompanyNameScannerSettings().IMIWindowPositionYGet();
}


// =================================================================================================
//   Sets the Y position of the window
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::WindowPositionYSet( long position_ )
{
    theCompanyNameScannerSettings().IMIWindowPositionYSet( position_ );
}
