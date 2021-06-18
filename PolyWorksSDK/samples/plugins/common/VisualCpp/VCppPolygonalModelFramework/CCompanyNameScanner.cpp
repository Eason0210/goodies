// =================================================================================================
// Implementation of CCompanyNameScanner.
//
// Copyright © InnovMetric Software Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameScanner.h"

#include <PolyWorksSDK/COM/IIMHost_i.c>
#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspect_i.c>
#include <PolyWorksSDK/COM/IIMInspectProject.h>
#include <PolyWorksSDK/COM/IIMInspectProject7_i.c>
#include <PolyWorksSDK/COM/IIMInspectProject_i.c>
#include <PolyWorksSDK/COM/IIMPolygonalModel_i.c>
#include <PolyWorksSDK/COM/IIMScannerFeedback.h>
#include <PolyWorksSDK/COM/IIMScannerFeedback2.h>
#include <PolyWorksSDK/COM/IIMScannerFeedback2_i.c>
#include <PolyWorksSDK/COM/IIMScannerFeedback_i.c>
#include <PolyWorksSDK/UI/IDialogZone.h>
#include <atlcomcli.h>
#include <sstream>

#include "ApplicationUtils.h"
#include "CompanyNameConst.h"
#include "CPolygonalModel.h"
#include "DataGenerator.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const wchar_t* g_pluginMenuLocation = L"CompanyName\\Polygonal Model Scanner...";

static const IM::CWString g_dialogZoneName = L"CompanyNamePolygonalModelScannerInterface";

// Message for main thread execution
enum
{
    WM_SCANNING_END = WM_APP,
};

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
// Hidden window message handler.
//
// Parameter : hwnd_   : MSDN
// Parameter : uMsg_   : MSDN
// Parameter : wParam_ : 0
// Parameter : lParam_ : 0
//
// return : MSDN
// -------------------------------------------------------------------------------------------------
static LRESULT CALLBACK SWindowProc( HWND hwnd_, UINT uMsg_, WPARAM wParam_, LPARAM lParam_ )
{
    if ( uMsg_ == WM_SCANNING_END )
    {
        return ExecuteCommandOnApp( L"DIGITIZE DEVICE SCAN END", true, true, false ) ? TRUE : FALSE;
    }

    return DefWindowProc( hwnd_, uMsg_, wParam_, lParam_ );
}

// =================================================================================================
// Constructor
// -------------------------------------------------------------------------------------------------
CCompanyNameScanner::CCompanyNameScanner()
: m_proxy( *this )
, m_messageWindow( SWindowProc, L"CompanyNamePolygonalModelScanner CMessageOnlyWindow" )
{
}

//////////////// IIMPlugin ////////////////////////

STDMETHODIMP CCompanyNameScanner::PlgNameGet(
    /* [out] */ BSTR* pName_ )
{
    if ( pName_ == nullptr )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( g_PluginName );
    assert( *pName_ != nullptr );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CCompanyNameScanner::PlgVersionGet(
    /* [out] */ long* pMajor_,
    /* [out] */ long* pMinor_,
    /* [out] */ long* pDot_ )
{
    if ( ( pMajor_ == nullptr ) || ( pMinor_ == nullptr ) || ( pDot_ == nullptr ) )
    {
        return S_FALSE;
    }

    // TODO: Set appropriate version info
    *pMajor_ = 1;
    *pMinor_ = 0;
    *pDot_   = 0;

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::Load(
    /* [in] */ IIMHost*       pIIMHost_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( ( pIIMHost_ == nullptr ) || ( pReturnVal_ == nullptr ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    // We can only accept IMInspect...
    CComQIPtr< IIMInspect > pIMInspect( pIIMHost_ );
    if ( pIMInspect == nullptr )
    {
        // If the IMInspect is not present, the application is NOT IMInspect
        return S_FALSE;
    }

    // Obtains IIMCommandCenter from IMInspect project
    CComPtr< IIMInspectProject > pIMInspectProject;
    pIMInspect->ProjectGetCurrent( &pIMInspectProject );
    if ( pIMInspectProject == nullptr )
    {
        return S_FALSE;
    }
    CComPtr< IIMCommandCenter > pCommandCenter;
    pIMInspectProject->CommandCenterCreate( &( pCommandCenter ) );
    if ( pCommandCenter == nullptr )
    {
        return S_FALSE;
    }
    if ( GITRegisterInterfaceInGlobal( pCommandCenter, IID_IIMCommandCenter, &g_cookieCommandCenter ) != S_OK )
    {
        return S_FALSE;
    }

    // Register the host interface
    if ( GITRegisterInterfaceInGlobal( pIIMHost_, IID_IIMHost, &g_cookieHost ) != S_OK )
    {
        GITRevokeInterfaceFromGlobal( g_cookieCommandCenter );
        return S_FALSE;
    }

    // Initialize the settings
    m_settings.SettingsAdd();

    // To ensure that the dlg will be initialized with the polygonal model default name of the application.
    ValueStrGetFromApp( L"CONFIG MODIFY DEFAULT_NAME SURFACE_SCAN GET", m_objectName );

    *pReturnVal_ = 1;
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::Unload(
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    m_proxy.Disconnect();

    // Save the settings
    m_settings.SettingsSave();

    // Release the IIMCommandCenter
    GITRevokeInterfaceFromGlobal( g_cookieCommandCenter );

    // Release the IIMHost
    GITRevokeInterfaceFromGlobal( g_cookieHost );

    *pReturnVal_ = 1;
    return S_OK;
}

//////////////// IIMLanguage ////////////////////////

STDMETHODIMP CCompanyNameScanner::LanguageSet(
    /* [in] */ BSTR pLanguage_,
    /* [in] */ BSTR pFontName_,
    /* [in] */ ECharacterSets /*charSet_*/ )
{
    // Validate the parameters
    if ( ( pLanguage_ == nullptr ) || ( pFontName_ == nullptr ) )
    {
        return S_FALSE;
    }
    const std::wstring language( pLanguage_, SysStringLen( pLanguage_ ) );
    const std::wstring fontName( pFontName_, SysStringLen( pFontName_ ) );
    if ( language.empty() || fontName.empty() )
    {
        return S_FALSE;
    }

    // TODO: Translate the dialogs in the appropriate language
    //       If this is not required, then remove this method
    //       and all references to IIMLanguage

    return S_OK;
}

//////////////// IIMUnitsUser ////////////////////////

STDMETHODIMP CCompanyNameScanner::UnitsScalingFactorSet(
    /* [in] */ double scalingFactor_ )
{
    // A PolyWorks plug-in implementing the UnitsScalingFactorSet method should:
    //
    // - use the specified units scaling factor to convert data to be sent
    //   to the application from plug-in units to host application units
    // - use the specified units scaling factor to convert data sent by
    //   the application from host application units to plug-in units
    m_hostUnitsScalingFactor = scalingFactor_;
    m_settings.HostUnitsScalingFactorSet( scalingFactor_ );
    m_proxy.HostUnitsScalingFactorSet( scalingFactor_ );

    // TODO: Make appropriate calls to ensure appropriate propagation of new units for data conversion

    return S_OK;
}

//////////////// IIMScanningObjectsUser /////////////

STDMETHODIMP CCompanyNameScanner::ScanningObjectsSet(
    /* [in] */ EScanTypes /* scanType_ */,
    /* [in] */ SAFEARRAY** /* pArrayObjects_ */,
    /* [in] */ BSTR currentChoice_ )
{
    m_objectName = currentChoice_;

    CDlgCompanyName* pDlg = m_pDlgCompanyName.get();
    if ( pDlg != nullptr )
    {
        pDlg->ControlsUpdate();
    }

    return S_OK;
}

//////////////// IIMSettings ////////////////////////

STDMETHODIMP CCompanyNameScanner::DoubleSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return m_settings.DoubleSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::DoubleSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ double*       pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return m_settings.DoubleSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}


STDMETHODIMP CCompanyNameScanner::LongSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return m_settings.LongSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::LongSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ long*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return m_settings.LongSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}


STDMETHODIMP CCompanyNameScanner::StringSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return m_settings.StringSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::StringSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ BSTR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return m_settings.StringSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}

//////////////// IIMSettings2 ////////////////////////

STDMETHODIMP CCompanyNameScanner::MatrixSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return m_settings.MatrixSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::MatrixSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ SAFEARRAY**   pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return m_settings.MatrixSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}

//////////////// IIMSettings3 ////////////////////////

STDMETHODIMP CCompanyNameScanner::OnSettingsChange(
    /* [in] */ SAFEARRAY* /*pSettingNames_*/ )
{
    // TODO : This function is called when the application has changed one or more
    //        of the plug-in's settings. This can happen for example during the
    //        execution of the CONFIG POP command.
    //        The pSettingNames_ parameter is an array containing the name of
    //        all parameters that were modified.
    //        You should perform whatever action is needed by your plug-in to
    //        adapt to the changed settings.
    //        Note that if your plug-in uses simple settings that are always read
    //        from the CCompanyNameScannerSettings object, you may not have
    //        anything to do in this function.

    return S_OK;
}

//////////////// IIMScanner ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningDeviceNameGet(
    /* [retval][out] */ BSTR* pName_ )
{
    if ( pName_ == nullptr )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( g_PluginName );
    assert( *pName_ != nullptr );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CCompanyNameScanner::ScanningConnectionInit(
    /* [in] */ IIMScannerFeedback* pScannerFeedback_,
    /* [retval][out] */ long*      pReturnVal_ )
{
    if ( ( pReturnVal_ == nullptr ) || ( pScannerFeedback_ == nullptr ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    // Keep track of the feedback interface
    if ( GITRegisterInterfaceInGlobal( pScannerFeedback_, IID_IIMScannerFeedback, &m_cookieScannerFeedback ) != S_OK )
    {
        return S_FALSE;
    }

    // Connect the device
    if ( !m_proxy.Connect() )
    {
        GITRevokeInterfaceFromGlobal( m_cookieScannerFeedback );
        return S_FALSE;
    }

    *pReturnVal_ = 1;
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanningConnectionEnd(
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    // Close the device connection
    m_proxy.Disconnect();

    if ( m_cookieScannerFeedback != 0 )
    {
        {
            CComPtr< IIMScannerFeedback > pScannerFeedback;
            GITGetInterfaceFromGlobal( m_cookieScannerFeedback, IID_IIMScannerFeedback, ( void** ) &pScannerFeedback );
            if ( pScannerFeedback != nullptr )
            {
                pScannerFeedback->ScanningConnectionEnd();
            }
        }

        // Release the feedback interface
        GITRevokeInterfaceFromGlobal( m_cookieScannerFeedback );
    }

    *pReturnVal_ = 1;
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanningDlgShow()
{
    if ( m_pDlgCompanyName == nullptr )
    {
        m_pDlgCompanyName = std::make_unique< CDlgCompanyName >( *this, m_settings );
    }

    if ( m_pDlgCompanyName != nullptr )
    {
        if ( m_pDlgCompanyName->GetSafeHwnd() == nullptr )
        {
            // Create the dialog
            if ( !m_pDlgCompanyName->DialogCreate() )
            {
                return S_FALSE;
            }

            // Attach the dialog to the Dialog Zone
            if ( !IM::DialogZoneGet()->DialogAdd( m_pDlgCompanyName->GetSafeHwnd(), g_dialogZoneName ) )
            {
                ScanningDlgCloseRequest();
                return S_FALSE;
            }
        }

        // Bring the dialog to foreground
        IM::DialogZoneGet()->DialogSetForeground( g_dialogZoneName );

        return S_OK;
    }

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanningDlgClose()
{
    ScanningDlgCloseRequest();
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanNameDefaultGet(
    /* [retval][out] */ BSTR* pName_ )
{
    // This method is now obsolete

    return E_NOTIMPL;
}

STDMETHODIMP CCompanyNameScanner::ScanNameSet(
    /* [in] */ BSTR name_ )
{
    // This method is now obsolete

    return E_NOTIMPL;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxEdgeLengthGet(
    /* [retval][out] */ double* /* pMaxEdgeLength_ */ )
{
    // This method is not used for this scanner model

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxEdgeLengthSet(
    /* [in] */ double /* maxEdgeLength_ */ )
{
    // This method is not used for this scanner model

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshInterpolationStepGet(
    /* [retval][out] */ double* /* pInterpolationStep_ */ )
{
    // This method is not used for this scanner model

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshInterpolationStepSet(
    /* [in] */ double /* interpolationStep_ */ )
{
    // This method is not used for this scanner model

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxAngleGet(
    /* [retval][out] */ double* /* pMaxAngle_ */ )
{
    // This method is not used for this scanner model

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxAngleSet(
    /* [in] */ double /* maxAngle_ */ )
{
    // This method is not used for this scanner model

    return S_OK;
}

//////////////// IIMScanner2 ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningDeviceMenuLocationGet(
    /* [retval][out] */ BSTR* pMenuPath_ )
{
    if ( pMenuPath_ == nullptr )
    {
        return S_FALSE;
    }
    ::SysFreeString( *pMenuPath_ );

    *pMenuPath_ = ::SysAllocString( g_pluginMenuLocation );
    assert( *pMenuPath_ != nullptr );

    return ( *pMenuPath_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

//////////////// IIMScanner3 ////////////////////////

STDMETHODIMP CCompanyNameScanner::OnScanningEvent(
    /* [in] */ EScanningEvents event_ )
{
    // TODO: React to the scanning events that might happen in the host application
    // Ex:
    //if( event_ == E_SCANNING_EVENT_LEAVING_SCAN_MODE )
    //{
    //    // Any reaction to this event...
    //}

    return S_OK;
}

//////////////// IIMScanner4 ////////////////////////

STDMETHODIMP CCompanyNameScanner::DeviceDeprecatedNamesGet(
    /* [out][in] */ SAFEARRAY** pNames_ )
{
    // TODO: Implement this method only if your plug-in changes name and there
    //       are existing scripts using the deprecated name(s).
    return E_NOTIMPL;
}

//////////////// IIMScanner5 ////////////////////////

STDMETHODIMP CCompanyNameScanner::HasScanningOptionsDlg(
    /* [retval][out] */ VARIANT_BOOL* pHasOptionsDlg_ )
{
    if ( pHasOptionsDlg_ == nullptr )
    {
        return S_FALSE;
    }

    // This plug-in does not have a scanning options dialog
    *pHasOptionsDlg_ = VARIANT_FALSE;
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanningOptionsDlgShow()
{
    // This plug-in does not have a scanning options dialog
    assert( false );
    return S_FALSE;
}

//////////////// IIMPolygonalScanner ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningStart(
    /* [in] */ IIMPolygonalModel* pPolygonalModel_,
    /* [retval][out] */ long*     pReturnVal_ )
{
    if ( pPolygonalModel_ == nullptr || pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;
    // Launch the scan on the device
    if ( !m_proxy.ScanningStart( *pPolygonalModel_ ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 1;
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanningEnd(
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    m_isScanningEndInProgress = true;
    *pReturnVal_              = 0;
    // End / Cancel the scan on the device
    const bool result = m_proxy.ScanningEnd();
    m_isScanningEndInProgress = false;
    if ( !result )
    {
        return S_FALSE;
    }

    // Re-center the display
    ExecuteCommandOnApp( L"VIEW POSE CENTER", true, false, false );

    // Notify GUI that scanning is completed
    CDlgCompanyName* pDlg = m_pDlgCompanyName.get();
    if ( pDlg != nullptr )
    {
        pDlg->ControlsUpdate( CDlgCompanyName::EActions::NoAction );
    }

    *pReturnVal_ = 1;
    return S_OK;
}

// =================================================================================================
// See ICompanyScannerName for details
// -------------------------------------------------------------------------------------------------
void CCompanyNameScanner::ScanningDlgCloseRequest()
{
    if ( m_pDlgCompanyName != nullptr )
    {
        if ( m_pDlgCompanyName->GetSafeHwnd() != nullptr )
        {
            // Detach from the Dialog Zone
            IM::IDialogZone* pDialogZone = IM::DialogZoneGet();
            if ( pDialogZone != nullptr )
            {
                pDialogZone->DialogRemove( g_dialogZoneName );
            }

            m_pDlgCompanyName->DestroyWindow();
        }

        m_pDlgCompanyName.reset();
    }
}

// =================================================================================================
// See ICompanyScannerName for details
// -------------------------------------------------------------------------------------------------
void CCompanyNameScanner::ScanningDlgClosed()
{
    // Notify the host application
    CComPtr< IIMScannerFeedback2 > pScannerFeedback;
    GITGetInterfaceFromGlobal( m_cookieScannerFeedback, IID_IIMScannerFeedback2, ( void** ) &pScannerFeedback );
    if ( pScannerFeedback != nullptr )
    {
        pScannerFeedback->ScanningDlgClosed();
    }
}

// =================================================================================================
// See ICompanyScannerName for details
//
// The uniqueID can be provided by multiple sources.
// One of these sources is the INotificationFeedback COM Interface. ( See sample VCppNotificationHandlerFramework )
// It allows the plug-in to keep the polygonal model up to date after a modification from the application side.
// It is also possible to obtain the unique identifier from the polygonal model object created when scanning.
// As per the implementation, the user must note that the plug-in is not requiring any connection to
// be able to access this polygonal model.
// A user can also use the function IIMPolygonalModel::PointsAndTrianglesGet to inspect/compare the changes done
// on the data before replacing them.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScanner::PolygonalModelReplace( TUniqueID uniqueId_ )
{
    // Retrieve the current selected polygonal model
    std::unique_ptr< CPolygonalModel > pPolygonalModel = PolygonalModelCreate( uniqueId_ );
    if ( pPolygonalModel == nullptr )
    {
        return;
    }

    // Verify the unique ID ( Should never fail but shows the functionality )
    if ( !Compare( pPolygonalModel->UniqueIDGet(), uniqueId_ ) )
    {
        return;
    }

    // Generate new data
    EDigitizingVectorDirections dir;
    PointF dirVector;
    std::vector< PointF >          coordinates;
    std::vector< TriangleIndexes > triangleIndexes;

    // Generate a new plane
    DataGenerator::CoordinatesGet( dir, dirVector, coordinates );

    // Make the messing of the plane
    DataGenerator::MeshingGet( coordinates, triangleIndexes );

    // Replace all of the existing data by the new ones
    pPolygonalModel->PointsAndTrianglesTransfer( m_hostUnitsScalingFactor, dir, dirVector, coordinates, triangleIndexes );
}

// =================================================================================================
// See ICompanyScannerName for details
// -------------------------------------------------------------------------------------------------
void CCompanyNameScanner::ScanningEndInMainThreadRequest()
{
    // We use this flag to avoid a double scan end. We will only make it happen if there is not
    // already going on.
    if ( m_isScanningEndInProgress )
    {
        return;
    }
    m_isScanningEndInProgress = true;

    // Post a message to the hidden window to execute the scan end in the main thread
    m_messageWindow.PostMessage( WM_SCANNING_END, 0, 0 );
}
