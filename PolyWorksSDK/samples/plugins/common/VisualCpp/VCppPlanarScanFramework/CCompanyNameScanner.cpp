// =================================================================================================
//   Implementation of CCompanyNameScanner.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameScanner.h"

#include <PolyWorksSDK/COM/IIMAlign.h>
#include <PolyWorksSDK/COM/IIMAlign_i.c>
#include <PolyWorksSDK/COM/IIMCommand.h>
#include <PolyWorksSDK/COM/IIMCommand_i.c>
#include <PolyWorksSDK/COM/IIMHost_i.c>
#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspect_i.c>
#include <assert.h>
#include <atlcomcli.h>
#include <sstream>

#include "ApplicationUtils.h"
#include "CCompanyNameScannerSettings.h"
#include "CDlgIMAlign.h"
#include "CDlgIMInspect.h"
#include "Diagnostics.h"
#include "SafeArrayConversion.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

extern bool g_diagnostics;

static const wchar_t* _pluginMenuLocation = L"CompanyName\\Planar Scanner...";

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

/////////////////////////////////////////////////////////////////////////////
// CCompanyNameScanner

CCompanyNameScanner::CCompanyNameScanner()
{
}

//////////////// IIMPlugin ////////////////////////

STDMETHODIMP CCompanyNameScanner::PlgNameGet(
    /* [out] */ BSTR* pName_ )
{
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
    int major = 1;
    int minor = 0;
    int dot   = 0;
    // TODO: Set appropriate version info
    *pMajor_ = ( long ) major;
    *pMinor_ = ( long ) minor;
    *pDot_   = ( long ) dot;

    return S_OK;
}


STDMETHODIMP CCompanyNameScanner::Load(
    /* [in] */ IIMHost*       pIIMHost_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( ( pIIMHost_ == nullptr ) ||
         ( pReturnVal_ == nullptr ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    EHostApplication app = E_APPLICATION_UNKNOWN;

    // We can accept IMInspect...
    CComQIPtr< IIMInspect > pIMInspect( pIIMHost_ );
    if ( pIMInspect != nullptr )
    {
        app = E_APPLICATION_IMINSPECT;

        // Obtains IIMCommandCenter from IMInspect project
        CComPtr< IIMInspectProject > pIMInspectProject;
        pIMInspect->ProjectGetCurrent( &pIMInspectProject );

        if ( pIMInspectProject != nullptr )
        {
            CComPtr< IIMCommandCenter > pCommandCenter;
            pIMInspectProject->CommandCenterCreate( &( pCommandCenter ) );

            if ( pCommandCenter != nullptr )
            {
                GITRegisterInterfaceInGlobal( pCommandCenter, IID_IIMCommandCenter, &g_cookieCommandCenter );
            }
        }

        *pReturnVal_ = 1;
    }
    else
    {
        // ... or IMAlign
        CComQIPtr< IIMAlign > pIMAlign( pIIMHost_ );
        if ( pIMAlign != nullptr )
        {
            app = E_APPLICATION_IMALIGN;

            // Obtains IIMCommandCenter from IMAlign project
            CComPtr< IIMAlignProject > pIMAlignProject;
            pIMAlign->ProjectGetCurrent( &pIMAlignProject );

            if ( pIMAlignProject != nullptr )
            {
                CComPtr< IIMCommandCenter > pCommandCenter;
                pIMAlignProject->CommandCenterCreate( &( pCommandCenter ) );

                if ( pCommandCenter != nullptr )
                {
                    GITRegisterInterfaceInGlobal( pCommandCenter, IID_IIMCommandCenter, &g_cookieCommandCenter );
                }
            }

            *pReturnVal_ = 1;
        }
    }

    if ( *pReturnVal_ == 1 )
    {
        theCompanyNameScannerSettings().Initialize( app );

        if ( GITRegisterInterfaceInGlobal( pIIMHost_, IID_IIMHost, &g_cookieHost ) != S_OK )
        {
            *pReturnVal_ = 0;
        }
    }

    return ( *pReturnVal_ == 1 ) ? S_OK : S_FALSE;
}


STDMETHODIMP CCompanyNameScanner::Unload(
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( m_Receiver.m_pDlgCompanyName != nullptr )
    {
        // Save the settings for next time
        theCompanyNameScannerSettings().SettingsSave();

        m_Receiver.m_pDlgCompanyName->ScanEnd();
    }

    m_Receiver.InterfacePopdown();

    *pReturnVal_ = ( m_Receiver.Disconnect() ? 1 : 0 );

    // Release the IIMCommandCenter
    GITRevokeInterfaceFromGlobal( g_cookieCommandCenter );

    GITRevokeInterfaceFromGlobal( g_cookieHost );

    return ( *pReturnVal_ == 1 ) ? S_OK : S_FALSE;
}

//////////////// IIMScanner ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningDeviceNameGet( /* [retval][out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( g_PluginName );
    assert( *pName_ != nullptr );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CCompanyNameScanner::ScanningConnectionInit(
    /* [in] */ IIMScannerFeedback* pScannerFeedback_,
    /* [retval][out] */ long*      pReturnVal_ )
{
    if ( pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    if ( !m_Receiver.Connect() )
    {
        return S_FALSE;
    }

    if ( pScannerFeedback_ != nullptr )
    {
        GITRegisterInterfaceInGlobal( pScannerFeedback_, IID_IIMScannerFeedback, &g_cookieScannerFeedback );
    }

    // Synchronize the host application with our own settings
    m_Receiver.UpdateFromSettings();

    *pReturnVal_ = 1;

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ScanningConnectionEnd( /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ != nullptr )
    {
        *pReturnVal_ = m_Receiver.Disconnect() ? 1 : 0;
        return ( *pReturnVal_ ) ? S_OK : S_FALSE;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ScanningDlgShow()
{
    return ( m_Receiver.InterfacePopup() ) ? S_OK : S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ScanningDlgClose()
{
    return ( m_Receiver.InterfacePopdown() ) ? S_OK : S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::ScanNameDefaultGet(
    /* [retval][out] */ BSTR* /* pName_ */ )
{
    // This method is now obsolete

    return E_NOTIMPL;
}

STDMETHODIMP CCompanyNameScanner::ScanNameSet(
    /* [in] */ BSTR /* name_ */ )
{
    // This method is now obsolete

    return E_NOTIMPL;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxEdgeLengthGet(
    /* [retval][out] */ double* pMaxEdgeLength_ )
{
    if ( pMaxEdgeLength_ != nullptr )
    {
        *pMaxEdgeLength_ = theCompanyNameScannerSettings().IMAMaxEdgeLengthGet();
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxEdgeLengthSet(
    /* [in] */ double maxEdgeLength_ )
{
    theCompanyNameScannerSettings().IMAMaxEdgeLengthSet( maxEdgeLength_ );
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshInterpolationStepGet(
    /* [retval][out] */ double* pInterpolationStep_ )
{
    if ( pInterpolationStep_ != nullptr )
    {
        *pInterpolationStep_ = theCompanyNameScannerSettings().IMAInterpolationStepGet();
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::MeshInterpolationStepSet(
    /* [in] */ double interpolationStep_ )
{
    theCompanyNameScannerSettings().IMAInterpolationStepSet( interpolationStep_ );
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxAngleGet(
    /* [retval][out] */ double* pMaxAngle_ )
{
    if ( pMaxAngle_ != nullptr )
    {
        *pMaxAngle_ = theCompanyNameScannerSettings().IMAMaxAngleGet();
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CCompanyNameScanner::MeshMaxAngleSet(
    /* [in] */ double maxAngle_ )
{
    theCompanyNameScannerSettings().IMAMaxAngleSet( maxAngle_ );
    return S_OK;
}

//////////////// IIMScanner2 ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningDeviceMenuLocationGet( /* [retval][out] */ BSTR* pMenuPath_ )
{
    ::SysFreeString( *pMenuPath_ );

    *pMenuPath_ = ::SysAllocString( _pluginMenuLocation );
    assert( *pMenuPath_ != nullptr );

    return ( *pMenuPath_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

//////////////// IIMScanner3 ////////////////////////
STDMETHODIMP CCompanyNameScanner::OnScanningEvent( /* [in] */ EScanningEvents event_ )
{
    // TODO: React to the scanning events that might happen in the host application
    // Ex:
    //if( event_ == E_SCANNING_EVENT_LEAVING_SCAN_MODE )
    //{
    //    // Any reaction to this event...
    //}

    switch ( event_ )
    {
        case E_SCANNING_EVENT_DEVICE_SELECTED:
        case E_SCANNING_EVENT_UPDATE_APP_SETTINGS:
            m_Receiver.UpdateFromSettings();
            break;
        case E_SCANNING_EVENT_APP_SETTING_MODIFIED:
            m_Receiver.UpdateSettingsFromApp();
            break;
    }

    return S_OK;
}

//////////////// IIMScanner4 ////////////////////////
STDMETHODIMP CCompanyNameScanner::DeviceDeprecatedNamesGet( /* [out][in] */ SAFEARRAY** /*pNames_*/ )
{
    // TODO: Implement this method only if your plug-in changes name and there
    //       are existing scripts using the deprecated name(s).
    return E_NOTIMPL;
}


STDMETHODIMP CCompanyNameScanner::ScanningOptionsDlgShow()
{
    const EHostApplication host = theCompanyNameScannerSettings().HostApplicationGet();
    if ( host == E_APPLICATION_IMINSPECT )
    {
        return S_FALSE;
    }
    else if ( host == E_APPLICATION_IMALIGN )
    {
        m_Receiver.DlgIMAlignOptionsShow( nullptr );
    }

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::HasScanningOptionsDlg( /* [retval][out] */ VARIANT_BOOL* pHasOptionsDlg_ )
{
    if ( pHasOptionsDlg_ != nullptr )
    {
        const EHostApplication host = theCompanyNameScannerSettings().HostApplicationGet();
        if ( host == E_APPLICATION_IMINSPECT ||
             host == E_APPLICATION_IMALIGN )
        {
            *pHasOptionsDlg_ = VARIANT_TRUE;
        }
        else
        {
            *pHasOptionsDlg_ = VARIANT_FALSE;
        }
    }
    return S_FALSE;
}

//////////////// IIMPlanarScanner ////////////////////////

STDMETHODIMP CCompanyNameScanner::ScanningStart(
    /* [in] */ IIMPlanarGrid* pPlanarGrid_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( pPlanarGrid_ == nullptr || pReturnVal_ == nullptr )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    if ( !m_Receiver.ScanningStart( pPlanarGrid_ ) )
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

    *pReturnVal_ = 0;

    if ( !m_Receiver.ScanningEnd() )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 1;

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ConvertToPolygonalModelGet(
    /* [retval][out] */ VARIANT_BOOL* pConvertToPolygonalModel_ )
{
    if ( pConvertToPolygonalModel_ != nullptr )
    {
        *pConvertToPolygonalModel_ = theCompanyNameScannerSettings().IMIConvertToPolygonalGet() ? VARIANT_TRUE : VARIANT_FALSE;
    }

    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::ConvertToPolygonalModelSet(
    /* [in] */ VARIANT_BOOL convertToPolygonalModel_ )
{
    theCompanyNameScannerSettings().IMIConvertToPolygonalSet( convertToPolygonalModel_ == VARIANT_TRUE );

    return S_OK;
}

//////////////// IIMCommandEnum ////////////////////////

STDMETHODIMP CCompanyNameScanner::CmdsGetNb(
    /* [retval][out] */ long* pArgNb_ )
{
    // TODO: Adjust this value according to the number of commands your plug-in has
    *pArgNb_ = 0;
    return S_OK;
}

STDMETHODIMP CCompanyNameScanner::CmdGet(
    /* [in] */ long /*number_*/,
    /* [out] */ IIMCommand** /*pIIMCommand_*/ )
{
    // TODO: If your plug-in has commands, uncomment the code below and instantiate the command objects here.
    //       Each command should be implemented in a class that derives from CCompanyNameCmd, implementing
    //       all of the pure virtual methods and overring any required COM methods (such as ArgsTest if the
    //       command has arguments, for example).
    //       See the VCppCommands sample for more information.
//    if ( number_ == 0 )
//    {
//        // Command 0: TODO: Short description of the command
//        CCompanyNameCmd0* pCmd = new CCompanyNameCmd0( m_Receiver );
//        if ( pCmd == nullptr )
//        {
//            return S_FALSE;
//        }
//        return pCmd->QueryInterface( IID_IIMCommand, (void**)pIIMCommand_ );
//    }
//    else if ( number_ == 1 )
//    {
//        ...
//    }

    return S_FALSE;
}


//////////////// IIMLanguage ////////////////////////

STDMETHODIMP CCompanyNameScanner::LanguageSet(
    /* [in] */ BSTR pLanguage_,
    /* [in] */ BSTR pFontName_,
    /* [in] */ ECharacterSets /*charSet_*/ )
{
    // Validate the parameters
    if ( ( pLanguage_ == nullptr ) || ( wcslen( pLanguage_ ) == 0 ) ||
         ( pFontName_ == nullptr ) || ( wcslen( pFontName_ ) == 0 ) )
    {
        return S_FALSE;
    }

    // TODO: Translate the dialogs in the appropriate language
    //       If this is not required, then remove this method
    //       and all references to IIMLanguage

    return S_OK;
}

//////////////// IIMScanningObjectsUser /////////////

STDMETHODIMP CCompanyNameScanner::ScanningObjectsSet(
    /* [in] */ EScanTypes  scanType_,
    /* [in] */ SAFEARRAY** pArrayObjects_,
    /* [in] */ BSTR        currentChoice_ )
{
    if ( pArrayObjects_ == nullptr ||
         currentChoice_ == nullptr )
    {
        return S_FALSE;
    }

    TWStrings objectNames;
    SafeArrayConversion::SafeArrayStringsGet( pArrayObjects_, objectNames );

    m_Receiver.ScanningObjectsSet( scanType_, objectNames, currentChoice_ );

    return S_OK;
}

//////////////// IIMSettings ////////////////////////

STDMETHODIMP CCompanyNameScanner::DoubleSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return theCompanyNameScannerSettings().DoubleSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::DoubleSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ double*       pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameScannerSettings().DoubleSettingGet(
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
    return theCompanyNameScannerSettings().LongSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::LongSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ long*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameScannerSettings().LongSettingGet(
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
    return theCompanyNameScannerSettings().StringSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::StringSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ BSTR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameScannerSettings().StringSettingGet(
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
    return theCompanyNameScannerSettings().MatrixSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameScanner::MatrixSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ SAFEARRAY**   pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameScannerSettings().MatrixSettingGet(
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

    if ( theCompanyNameScannerSettings().HostUnitsScalingFactorSet( scalingFactor_ ) )
    {
        // TODO: Make appropriate calls to ensure appropriate propagation of new units for data conversion

        return S_OK;
    }

    return S_FALSE;
}


/////////////////////////////////////////////////////////////////////////////
// CCompanyNameCmd

//////////////// IUnknown ////////////////////////

// =============================================================================
STDMETHODIMP CCompanyNameCmd::QueryInterface( REFIID riid_, void** ppv_ )
{
    if ( ( riid_ == IID_IUnknown ) || ( riid_ == IID_IIMCommand ) )
    {
        *ppv_ = static_cast< IIMCommand* >( this );
    }
    else if ( riid_ == IID_IIMCommand2 )
    {
        *ppv_ = static_cast< IIMCommand2* >( this );
    }
    else
    {
        *ppv_ = nullptr;
        return E_NOINTERFACE;
    }

    ( ( IUnknown* ) *ppv_ )->AddRef();

    return S_OK;
}

// =============================================================================
STDMETHODIMP_( ULONG )
CCompanyNameCmd::AddRef()
{
    return InterlockedIncrement( &m_nRefCount );
}

// =============================================================================
STDMETHODIMP_( ULONG )
CCompanyNameCmd::Release()
{
    long nRefCount = 0;

    nRefCount = InterlockedDecrement( &m_nRefCount );

    if ( nRefCount == 0 )
    {
        delete this;
    }

    return nRefCount;
}

//////////////// IIMCommand ////////////////////////

// =============================================================================
STDMETHODIMP CCompanyNameCmd::CmdNameGet(
    /* [out] */ BSTR* pCmdName_ )
{
    ::SysFreeString( *pCmdName_ );

    *pCmdName_ = ::SysAllocString( CmdNameStrGet() );

    return ( *pCmdName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

// =============================================================================
STDMETHODIMP CCompanyNameCmd::CmdDescGet(
    /* [out] */ BSTR* pCmdDesc_ )
{
    ::SysFreeString( *pCmdDesc_ );

    *pCmdDesc_ = ::SysAllocString( DescStrGet() );

    return ( *pCmdDesc_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

// =============================================================================
STDMETHODIMP CCompanyNameCmd::Execute(
    /* [retval][out] */ long* pReturnVal_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;
    HRESULT res                 = Execute2( nullptr, &retCode );

    *pReturnVal_ = ( retCode != E_CMD_SUCCEEDED ) ? 0 : 1;
    return res;
}

// =============================================================================
STDMETHODIMP CCompanyNameCmd::MenuLocationGet(
    /* [out] */ BSTR* pMenuLoc_ )
{
    ::SysFreeString( *pMenuLoc_ );

    if ( MenuLocationStrGet() != nullptr )
    {
        *pMenuLoc_ = ::SysAllocString( MenuLocationStrGet() );
    }

    return ( *pMenuLoc_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

// =============================================================================
STDMETHODIMP CCompanyNameCmd::MenuDescGet(
    /* [out] */ BSTR* pMenuDesc_ )
{
    ::SysFreeString( *pMenuDesc_ );

    *pMenuDesc_ = ::SysAllocString( DescStrGet() );

    return ( *pMenuDesc_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

//////////////// IIMCommand2 ////////////////////////

// =============================================================================
STDMETHODIMP CCompanyNameCmd::ArgsTest(
    /* [in] */ IIMCommandArgumentEnum*       /*pIIMCommandArgumentEnum_*/,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    if ( pReturnCode_ == nullptr )
    {
        return S_FALSE;
    }

    *pReturnCode_ = E_CMD_SUCCEEDED;
    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameCmd::CmdDeprecatedNamesGet(
    /* [out][in] */ SAFEARRAY** /*pNames_*/ )
{
    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameCmd::CmdIsObsolete(
    /* [out] */ VARIANT_BOOL* pIsObsolete_,
    /* [out] */ BSTR*         pSupersedingCmd_ )
{
    if ( ( pIsObsolete_ == nullptr ) || ( pSupersedingCmd_ == nullptr ) )
    {
        return S_FALSE;
    }

    *pIsObsolete_     = VARIANT_FALSE;
    *pSupersedingCmd_ = nullptr;

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameCmd::CmdNoteGet(
    /* [retval][out] */ BSTR* pCmdNote_ )
{
    if ( pCmdNote_ != nullptr )
    {
        *pCmdNote_ = nullptr;
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameCmd::ParamsGet(
    /* [out] */ IIMCommandParameterEnum** pIIMCommandParameterEnum_ )
{
    if ( pIIMCommandParameterEnum_ != nullptr )
    {
        *pIIMCommandParameterEnum_ = nullptr;
        return S_OK;
    }
    return S_FALSE;
}
