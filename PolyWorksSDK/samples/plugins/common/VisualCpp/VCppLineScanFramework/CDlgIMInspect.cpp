// =================================================================================================
//   Plug-in dialog for PolyWorks|Inspector implementation.
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
#include <assert.h>
#include <float.h>

#include "ApplicationUtils.h"
#include "CCompanyNameScannerReceiver.h"
#include "CCompanyNameScannerSettings.h"
#include "CDlgSaveAsProfile.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const wchar_t* const _sSurfaceScanType   = L"Surface";
static const wchar_t* const _sBoundaryScanType  = L"Surface and Boundary";
static const wchar_t* const _sSharpEdgeScanType = L"Sharp Edge";

static const wchar_t* const _sDataTypePolygonalModel = L"Polygonal Model";
static const wchar_t* const _sDataTypePointCloud     = L"Point Cloud from Mesh";

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
//   Return application boundary scanning type activation state.
//
// Return : 0 if "Surface", 1 if "Surface and Boundary", 2 if "Sharp Edge"
// -------------------------------------------------------------------------------------------------
static int IMIScanTypeGet()
{
    std::wstring scanType;
    ValueStrGetFromApp( g_cmdDigitizeDeviceScanTypeGet, scanType );

    if ( scanType == _sSharpEdgeScanType )
    {
        return 2;
    }
    else if ( scanType == _sBoundaryScanType )
    {
        return 1;
    }

    return 0;
}

// =================================================================================================
//   Constructor
// -------------------------------------------------------------------------------------------------
CDlgIMInspect::CDlgIMInspect( CWnd* pParent_ /*= nullptr*/ )
: CDlgCompanyName( IDD, pParent_ )
, m_scanType( 0 )
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
    ON_BN_CLICKED( IDC_RADIO_SURFACE_SCAN,              OnClickedScanType )
    ON_BN_CLICKED( IDC_RADIO_SURFACE_AND_BOUNDARY_SCAN, OnClickedScanType )
    ON_BN_CLICKED( IDC_RADIO_SHARP_EDGE_SCAN,           OnClickedScanType )
    ON_BN_CLICKED( IDC_BUTTON_OPTIONS,                  OnClickedOptions )
    ON_BN_CLICKED( IDC_CHECK_REALTIME_COMPARISON,       OnClickedRealTimeComparison )
    ON_CBN_SELCHANGE( IDC_COMBO_DATA_OBJECT_SURFACE,  OnSelChangeDataObjectsSurface )
    ON_CBN_SELCHANGE( IDC_COMBO_DATA_OBJECT_BOUNDARY, OnSelChangeDataObjectsBoundary )
    ON_BN_CLICKED( IDC_CHECK_RTQM,                 OnClickedRTQM )
    ON_BN_CLICKED( IDC_RADIO_RTQM_POINT_CLOUD,     OnClickedRTQMPointCloud )
    ON_BN_CLICKED( IDC_RADIO_RTQM_POLYGONAL_MODEL, OnClickedRTQMPolygonalModel )
    ON_EN_KILLFOCUS( IDC_EDIT_DATA_OBJECT_NAME_SURFACE,  OnKillFocusDataObjectNameSurface )
    ON_EN_KILLFOCUS( IDC_EDIT_DATA_OBJECT_NAME_BOUNDARY, OnKillFocusDataObjectNameBoundary )
    ON_CBN_SELCHANGE( IDC_COMBO_SCAN_PROFILE, OnSelChangeScanProfile )
    ON_BN_CLICKED( IDC_BUTTON_SAVE_AS_PROFILE,       OnClickedSaveAsProfile )
    ON_BN_CLICKED( IDC_BUTTON_DELETE_PROFILE,        OnClickedDeleteProfile )
    ON_BN_CLICKED( IDC_CHECK_CLIPPING_PLANE,         OnClickedClippingPlane )
    ON_BN_CLICKED( IDC_BUTTON_CLIPPING_PLANE_DEFINE, OnClickedClippingPlaneDefine )
    ON_WM_SETFOCUS()

    ON_MESSAGE( WM_COMP_NAME_PLUGIN_UPDATE_PROFILES, OnUpdateProfiles )
END_MESSAGE_MAP()


// =================================================================================================
//   Creates the PolyWorks|Inspector dialog
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
    return g_cmdConfigModifyDefaultNameSurfaceScanGet;
}


// =================================================================================================
//   Updates data name and combo
//
// Parameter : dataObjectName_ : data object name
// Parameter : dataObjects_    : data object combo
// Parameter : scanType_       : scan type
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::DataObjectsUpdate( CEdit& dataObjectName_, CComboBox& dataObjects_, EScanTypes scanType_ )
{
    dataObjectName_.Clear();

    // Get the application Data Object names
    TWStrings    objectNames;
    std::wstring currentChoice;

    if ( m_pReceiver != nullptr )
    {
        m_pReceiver->ScanningObjectsGet( scanType_, objectNames, currentChoice );
    }

    dataObjects_.ResetContent();
    dataObjects_.AddString( L"(Create New)" );

    unsigned int currentSelection = 0;
    for ( unsigned int curIndex = 0; curIndex < objectNames.size(); curIndex++ )
    {
        const std::wstring& name = objectNames[ curIndex ];
        dataObjects_.AddString( name.c_str() );

        if ( name == currentChoice )
        {
            // Select the current choice
            currentSelection = curIndex + 1;
        }
    }

    dataObjects_.SetCurSel( currentSelection );

    dataObjectName_.SetWindowText( currentChoice.c_str() );
}

// =================================================================================================
//   Updates the dialog
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::DialogUpdate()
{
    // Get the scan type from the application
    m_scanType = IMIScanTypeGet();
    UpdateData( FALSE );

    // Get RTM activation state from the application because it may have changed
    std::wstring rtmActivationState;
    ValueStrGetFromApp( g_cmdDigitizeLineScanSurfaceRTQMGet, rtmActivationState );
    bool useRTM = rtmActivationState == L"On";

    std::wstring clippingPlane;
    ValueStrGetFromApp( g_cmdDigitizeClippingPlaneGet, clippingPlane );
    m_clippingPlane.SetCheck( clippingPlane == L"On" ? BST_CHECKED : BST_UNCHECKED );

    std::wstring clippingPlaneDateTime( L"Undefined" );
    ValueStrGetFromApp( g_cmdDigitizeClippingPlaneDefinedGet, clippingPlane );
    if ( clippingPlane == L"On" )
    {
        ValueDateTimeGetFromApp( g_cmdDigitizeClippingPlaneDefinedDateTimeGet, clippingPlaneDateTime );
    }
    m_clippingPlaneDateTime.SetWindowTextW( clippingPlaneDateTime.c_str() );

    theCompanyNameScannerSettings().IMIRealTimeMeshingSet( useRTM );
    m_rtqm.SetCheck( useRTM ? BST_CHECKED : BST_UNCHECKED );

    std::wstring rtqmDataType;
    ValueStrGetFromApp( g_cmdDigitizeLineScanSurfaceRTQMFinalDataObjDataTypeGet, rtqmDataType );
    const bool isPolModel = rtqmDataType == _sDataTypePolygonalModel;
    m_rtqmPointCloud.SetCheck( isPolModel ? BST_UNCHECKED : BST_CHECKED );
    m_rtqmPolygonalModel.SetCheck( isPolModel ? BST_CHECKED : BST_UNCHECKED );

    DataObjectsUpdate( m_dataObjectNameSurface,  m_dataObjectsSurface,  E_SCAN_TYPE_SURFACE );
    DataObjectsUpdate( m_dataObjectNameBoundary, m_dataObjectsBoundary, E_SCAN_TYPE_SHARP_EDGE );

    m_realTimeComparison.SetCheck( theCompanyNameScannerSettings().IMIRealTimeInspectionGet() ? BST_CHECKED : BST_UNCHECKED );

    EnableScanControls( !IsScanning() );

    // Ask the base class to do the rest
    __super::DialogUpdate();
}

// =================================================================================================
//   MFC function to transfer data between GUI and variables.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::DoDataExchange( CDataExchange* pDX_ )
{
    __super::DoDataExchange( pDX_ );

    DDX_Control( pDX_, IDC_RADIO_SURFACE_SCAN,              m_surfaceScanType );
    DDX_Control( pDX_, IDC_RADIO_SURFACE_AND_BOUNDARY_SCAN, m_surfaceAndBoundaryScanType );
    DDX_Control( pDX_, IDC_RADIO_SHARP_EDGE_SCAN,           m_sharpEdgeScanType );
    DDX_Radio( pDX_, IDC_RADIO_SURFACE_SCAN, m_scanType );
    DDX_Control( pDX_, IDC_COMBO_DATA_OBJECT_SURFACE,      m_dataObjectsSurface );
    DDX_Control( pDX_, IDC_COMBO_DATA_OBJECT_BOUNDARY,     m_dataObjectsBoundary );
    DDX_Control( pDX_, IDC_CHECK_RTQM,                     m_rtqm );
    DDX_Control( pDX_, IDC_STATIC_RTQM_DATA_TYPE,          m_rtqmDataType );
    DDX_Control( pDX_, IDC_RADIO_RTQM_POINT_CLOUD,         m_rtqmPointCloud );
    DDX_Control( pDX_, IDC_RADIO_RTQM_POLYGONAL_MODEL,     m_rtqmPolygonalModel );
    DDX_Control( pDX_, IDC_EDIT_DATA_OBJECT_NAME_SURFACE,  m_dataObjectNameSurface );
    DDX_Control( pDX_, IDC_EDIT_DATA_OBJECT_NAME_BOUNDARY, m_dataObjectNameBoundary );
    DDX_Control( pDX_, IDC_CHECK_REALTIME_COMPARISON,      m_realTimeComparison );
    DDX_Control( pDX_, IDC_STATIC_SCAN_PROFILE,            m_staticScanningProfile );
    DDX_Control( pDX_, IDC_COMBO_SCAN_PROFILE,             m_comboScanningProfile );
    DDX_Control( pDX_, IDC_BUTTON_SAVE_AS_PROFILE,         m_saveAsProfile );
    DDX_Control( pDX_, IDC_BUTTON_DELETE_PROFILE,          m_deleteProfile );
    DDX_Control( pDX_, IDC_CHECK_CLIPPING_PLANE,           m_clippingPlane );
    DDX_Control( pDX_, IDC_BUTTON_CLIPPING_PLANE_DEFINE,   m_clippingPlaneDefine );
    DDX_Control( pDX_, IDC_EDIT_CLIPPING_PLANE_DATE_TIME,  m_clippingPlaneDateTime );
}


// =================================================================================================
//   Activates or deactivates controls related to scanning.
//
// Parameter : enable_ : true to activate, false to deactivate
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::EnableScanControls( bool enable_ )
{
    m_surfaceScanType.EnableWindow( enable_ );
    m_surfaceAndBoundaryScanType.EnableWindow( enable_ );
    m_sharpEdgeScanType.EnableWindow( enable_ );

    bool useRTM      = ( m_rtqm.GetCheck() == BST_CHECKED );
    bool isSharpEdge = ( m_sharpEdgeScanType.GetCheck() == BST_CHECKED );

    m_dataObjectsSurface.EnableWindow( enable_ && !isSharpEdge );

    bool isCreatingNewDataObject = ( m_dataObjectsSurface.GetCurSel() == 0 );
    m_rtqm.EnableWindow( enable_ && !isSharpEdge && isCreatingNewDataObject );
    m_rtqmDataType.EnableWindow( enable_ && !isSharpEdge && useRTM );
    m_rtqmPointCloud.EnableWindow( enable_ && !isSharpEdge && useRTM );
    m_rtqmPolygonalModel.EnableWindow( enable_ && !isSharpEdge && useRTM );
    m_dataObjectNameSurface.EnableWindow( enable_ && !isSharpEdge && isCreatingNewDataObject );

    bool isBoundary = ( m_surfaceAndBoundaryScanType.GetCheck() == BST_CHECKED );
    isCreatingNewDataObject = ( m_dataObjectsBoundary.GetCurSel() == 0 );
    m_dataObjectsBoundary.EnableWindow( enable_ && ( isBoundary || isSharpEdge ) );
    m_dataObjectNameBoundary.EnableWindow( enable_ && ( isBoundary || isSharpEdge ) && isCreatingNewDataObject );

    m_realTimeComparison.EnableWindow( enable_ && !isSharpEdge && !useRTM );

    bool clippingPlane = ( m_clippingPlane.GetCheck() == BST_CHECKED );
    m_clippingPlane.EnableWindow( enable_ && !isSharpEdge );
    m_clippingPlaneDateTime.EnableWindow( enable_ && !isSharpEdge && clippingPlane );
    m_clippingPlaneDefine.EnableWindow( enable_ && !isSharpEdge && clippingPlane );

    m_staticScanningProfile.EnableWindow( enable_ );
    m_comboScanningProfile.EnableWindow( enable_ );
    m_saveAsProfile.EnableWindow( enable_ );
    m_deleteProfile.EnableWindow( enable_ );
}

// =================================================================================================
//   Handling the WM_INITDIALOG message
// -------------------------------------------------------------------------------------------------
BOOL CDlgIMInspect::OnInitDialog()
{
    if ( m_pReceiver != nullptr )
    {
        // Synchronise RTM in application with plug-in setting
        bool useRTM = theCompanyNameScannerSettings().IMIRealTimeMeshingGet();
        m_pReceiver->EnableRealTimeMeshing( useRTM );
    }

    // Ask the base class to do the rest
    return __super::OnInitDialog();
}

// =================================================================================================
//   Handling the define clipping plane check box.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedClippingPlaneDefine()
{
    ExecuteCommandOnApp( g_cmdDigitizeClippingPlaneDefineShowWindow, true, true );
}

// =================================================================================================
//   Handling the clipping plane check box.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedClippingPlane()
{
    const bool         use = ( m_clippingPlane.GetCheck() == BST_CHECKED );
    const std::wstring clippingPlane( use ? L"On" : L"Off" );

    ValueStrSetToApp( g_cmdDigitizeClippingPlaneSet, clippingPlane, true );

    EnableScanControls( !IsScanning() );
}

// =================================================================================================
//   Handling the surface scan type radio button.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedScanType()
{
    std::wstring scanTypeStr;
    UpdateData( TRUE );
    switch ( m_scanType )
    {
        case 2:
            scanTypeStr = _sSharpEdgeScanType;
            break;
        case 1:
            scanTypeStr = _sBoundaryScanType;
            break;
        default:
            scanTypeStr = _sSurfaceScanType;
            break;
    }

    ValueStrSetToApp( g_cmdDigitizeDeviceScanTypeSet, scanTypeStr, true );

    EnableScanControls( !IsScanning() );
}

// =================================================================================================
//   Handling the Options button
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedOptions()
{
    if ( m_pReceiver != nullptr )
    {
        m_pReceiver->DlgIMInspectOptionsShow( this );
    }
}


// =================================================================================================
//   Handling the Real-time Comparison check box
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedRealTimeComparison()
{
    // Set Real-time Comparison config
    theCompanyNameScannerSettings().IMIRealTimeInspectionSet( m_realTimeComparison.GetCheck() == BST_CHECKED );
}


// =================================================================================================
//   Handling the Real-time quality check-box.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedRTQM()
{
    const bool rtqmEnabled = m_rtqm.GetCheck() == BST_CHECKED;

    theCompanyNameScannerSettings().IMIRealTimeMeshingSet( rtqmEnabled );

    if ( m_pReceiver )
    {
        m_pReceiver->EnableRealTimeMeshing( rtqmEnabled );
    }
}

// =================================================================================================
//   Handling the Point Cloud data type radio button.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedRTQMPointCloud()
{
    std::wstring cmd = std::wstring( g_cmdDigitizeLineScanSurfaceRTQMFinalDataObjDataTypeSet ) + L"(\"" + std::wstring( _sDataTypePointCloud ) + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Handling the Polygonal Model data type radio button.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedRTQMPolygonalModel()
{
    std::wstring cmd = std::wstring( g_cmdDigitizeLineScanSurfaceRTQMFinalDataObjDataTypeSet ) + L"(\"" + std::wstring( _sDataTypePolygonalModel ) + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Handling the surface data object name kill focus.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnKillFocusDataObjectNameSurface()
{
    CString dataObjectNameText;
    m_dataObjectNameSurface.GetWindowText( dataObjectNameText );

    // Make sure data object name is unique
    std::wstring dataObjectName = ObtainUniqueNameFromApp( dataObjectNameText.GetString() );

    // Send new name to application
    std::wstring cmd = std::wstring( g_cmdDigitizeDeviceScanSurfaceDataObjectName ) + L"(\"" + dataObjectName + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Handling the surface data object change.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnSelChangeDataObjectsSurface()
{
    // Update Data objet name editbox visibility
    bool isCreatingNewObject = ( m_dataObjectsSurface.GetCurSel() == 0 );

    std::wstring dataObjectName;
    if ( isCreatingNewObject )
    {
        // Get default name from application
        ValueStrGetFromApp( DefaultNameSurfaceScanCmdNameGet(), dataObjectName );

        // Make sure object name is unique
        dataObjectName = ObtainUniqueNameFromApp( dataObjectName );
    }
    else
    {
        CString currentData;
        m_dataObjectsSurface.GetLBText( m_dataObjectsSurface.GetCurSel(), currentData );
        dataObjectName = currentData.GetString();
    }

    // Send new data object name to application
    std::wstring cmd = std::wstring( g_cmdDigitizeDeviceScanSurfaceDataObjectName ) + L"(\"" + dataObjectName + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Handling the set focus message.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnSetFocus( CWnd* pOldWnd_ )
{
    if ( pOldWnd_ != this )
    {
        DialogUpdate();
    }
}

// =================================================================================================
//   Handling the boundary data object name kill focus.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnKillFocusDataObjectNameBoundary()
{
    CString dataObjectNameText;
    m_dataObjectNameBoundary.GetWindowText( dataObjectNameText );

    // Make sure data object name is unique
    std::wstring dataObjectName = ObtainUniqueNameFromApp( dataObjectNameText.GetString() );

    // Send new name to application
    std::wstring cmd = std::wstring( g_cmdDigitizeDeviceScanBoundaryDataObjectName ) + L"(\"" + dataObjectName + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Handling the boundary data object change.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnSelChangeDataObjectsBoundary()
{
    // Update Data objet name editbox visibility
    bool isCreatingNewObject = ( m_dataObjectsBoundary.GetCurSel() == 0 );

    std::wstring dataObjectName;
    if ( isCreatingNewObject )
    {
        // Get default name from application
        ValueStrGetFromApp( g_cmdConfigModifyDefaultNameBoundaryScanGet, dataObjectName );

        // Make sure object name is unique
        dataObjectName = ObtainUniqueNameFromApp( dataObjectName );
    }
    else
    {
        CString currentData;
        m_dataObjectsBoundary.GetLBText( m_dataObjectsBoundary.GetCurSel(), currentData );
        dataObjectName = currentData.GetString();
    }

    // Send new data object name to application
    std::wstring cmd = std::wstring( g_cmdDigitizeDeviceScanBoundaryDataObjectName ) + L"(\"" + dataObjectName + L"\")";
    ExecuteCommandOnApp( cmd.c_str(), true, false, true );
}

// =================================================================================================
//   Handling the boundary data object change.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnSelChangeScanProfile()
{
    int profilesComboIndex = m_comboScanningProfile.GetCurSel();

    if ( profilesComboIndex >= 0 && static_cast< size_t >( profilesComboIndex ) < m_profileCmdArgNames.size() )
    {
        const std::wstring profileCmdArgName = m_profileCmdArgNames[ profilesComboIndex ];

        std::wstring cmd;
        cmd  = L"DIGITIZE DEVICE SCAN PROFILE ( \"";
        cmd += profileCmdArgName;
        cmd += L"\" )";
        if ( ExecuteCommandOnApp( cmd.c_str(), true, true ) )
        {
            m_profilesComboIndex = profilesComboIndex;
        }
        else
        {
            m_comboScanningProfile.SetCurSel( m_profilesComboIndex );
        }
    }
    else
    {
        assert( 0 );
    }
}

// =================================================================================================
//   Handling the Save As profile button.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedSaveAsProfile()
{
    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    CDlgSaveAsProfile dlg( this );

    dlg.Init( m_pReceiver );
    dlg.DoModal();

    AfxSetResourceHandle( oldInstance );
}

// =================================================================================================
//   Handling the Delete profile button.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::OnClickedDeleteProfile()
{
    if ( m_profilesComboIndex >= 0 && static_cast< size_t >( m_profilesComboIndex ) < m_profileCmdArgNames.size() )
    {
        const std::wstring profileCmdArgName = m_profileCmdArgNames[ m_profilesComboIndex ];

        std::wstring cmd;
        cmd  = L"DIGITIZE DEVICE SCAN PROFILE DELETE ( \"";
        cmd += profileCmdArgName;
        cmd += L"\" )";
        ExecuteCommandOnApp( cmd.c_str(), true, true );
    }
    else
    {
        assert( 0 );
    }
}

// =================================================================================================
//   Update Profiles handler
// -------------------------------------------------------------------------------------------------
LRESULT CDlgIMInspect::OnUpdateProfiles( WPARAM /*wParam_*/, LPARAM /*lParam_*/ )
{
    ProfilesControlUpdate();

    return 0L;
}

// =================================================================================================
//   Update Profiles controls.
// -------------------------------------------------------------------------------------------------
void CDlgIMInspect::ProfilesControlUpdate()
{
    m_comboScanningProfile.ResetContent();
    m_profilesComboIndex = -1;
    m_profileCmdArgNames.clear();
    m_profileTooltips.clear();

    TWStrings    profileDisplayNames;
    TWStrings    profileAdditionalInfos;
    std::wstring currentProfile;

    auto* pScanningProfilesUser = dynamic_cast< CScanningProfilesUser* >( m_pReceiver );
    if ( pScanningProfilesUser == nullptr )
    {
        return;
    }

    pScanningProfilesUser->ScanningProfilesGet( m_profileCmdArgNames, profileDisplayNames, profileAdditionalInfos, currentProfile );

    // Must be the same size.
    if ( m_profileCmdArgNames.size() != profileDisplayNames.size() )
    {
        return;
    }

    for ( int iProfile = 0; static_cast< size_t >( iProfile ) < m_profileCmdArgNames.size(); ++iProfile )
    {
        std::wstring profileCmdArgName = m_profileCmdArgNames[ iProfile ];

        // If the displayName is empty, it is a user profile (not translated) and
        // the cmdArgName is used as dislpayName.
        bool         isUserProfile         = profileDisplayNames[ iProfile ].empty();
        std::wstring profileDisplayName    = isUserProfile ? profileCmdArgName : profileDisplayNames[ iProfile ];
        std::wstring profileAdditionalInfo = static_cast< size_t >( iProfile ) < profileAdditionalInfos.size() ? profileAdditionalInfos[ iProfile ] : L"";

        m_comboScanningProfile.AddString( profileDisplayName.c_str() );

        // Additional info as a tooltip
        std::wstring toolTipStr = profileDisplayName;
        if ( !profileAdditionalInfo.empty() )
        {
            toolTipStr += L" ";
            toolTipStr += profileAdditionalInfo;
        }

        m_profileTooltips.push_back( toolTipStr );

        if ( profileCmdArgName == currentProfile )
        {
            m_profilesComboIndex = iProfile;
        }
    }

    m_comboScanningProfile.TooltipsSet( m_profileTooltips );
    m_comboScanningProfile.SetCurSel( m_profilesComboIndex );

    EnableScanControls( !IsScanning() );
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

    bool wasScanning = IsScanning() && m_pReceiver->IsAcquisitionStarted();

    if ( __super::ScanEnd() )
    {
        bool isRealTimeMeshing = ( m_rtqm.GetState() == BST_CHECKED );
        if ( isRealTimeMeshing &&
             wasScanning &&
             !theCompanyNameScannerSettings().TestModeGet() &&
             m_pReceiver->NbPointsRecordedGet() > 0 )
        {
            ExecuteCommandOnApp( g_cmdDigitizeLineScanSurfaceRQTMFinalDataObjCreate, true, false, false );
        }

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
