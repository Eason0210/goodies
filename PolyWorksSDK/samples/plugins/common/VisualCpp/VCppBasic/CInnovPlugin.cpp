// CInnovPlugin.cpp : Implementation of CInnovPlugin
#include "stdafx.h"

#include "CInnovPlugin.h"

#include <PolyWorksSDK/COM/IIMMessageCenter_i.c>
#include <PolyWorksSDK/COM/IIMSoundCenter_i.c>
#include <comutil.h>
#include <string>

#include "VCppBasic.h"

#pragma warning( disable: 4996 )

/////////////////////////////////////////////////////////////////////////////
// CInnovPlugin

CInnovPlugin::CInnovPlugin()
{
}


//////////////// IIMPlugin ////////////////////////

STDMETHODIMP CInnovPlugin::PlgNameGet(
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    // The name should not be longer than 31 characters
    *pName_ = ::SysAllocString( L"VCppBasic" );

    return ( *pName_ != NULL ) ? S_OK : E_OUTOFMEMORY;
}


STDMETHODIMP CInnovPlugin::PlgVersionGet(
    /* [out] */ long* pMajor_,
    /* [out] */ long* pMinor_,
    /* [out] */ long* pDot_ )
{
    *pMajor_ = 1;
    *pMinor_ = 0;
    *pDot_   = 0;

    return S_OK;
}


STDMETHODIMP CInnovPlugin::Load(
    /* [in] */ IIMHost*       pIIMHost_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( ( pIIMHost_ == nullptr ) ||
         ( pReturnVal_ == nullptr ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 1;

    // Do nothing to accept all hosts (IMAlign, PolyWorks|Inspector, PolyWorks|Modeler, etc.)
    // or do the following to accept only specific hosts (PolyWorks|Inspector in this case)
    //    CComQIPtr< IIMInspect > pIMInspect( pIIMHost_ );
    //    if ( pIMInspect != nullptr )
    //    {
    //        theDlgIMInspect().Init( &m_Receiver );
    //    }
    //    else
    //    {
    //        *pReturnVal_ = 0;
    //    }

    // Obtain the message center interface
    m_pMessageCenter = CComQIPtr< IIMMessageCenter >( pIIMHost_ );
    if ( m_pMessageCenter == nullptr )
    {
        *pReturnVal_ = 0;
    }

    // Obtain the sound center interface
    m_pSoundCenter = CComQIPtr< IIMSoundCenter >( pIIMHost_ );
    if ( m_pSoundCenter == nullptr )
    {
        *pReturnVal_ = 0;
    }

    if ( *pReturnVal_ == 1 )
    {
        return S_OK;
    }

    return S_FALSE;
}


STDMETHODIMP CInnovPlugin::Unload(
    /* [retval][out] */ long* pReturnVal_ )
{

    *pReturnVal_ = 1;

    return ( *pReturnVal_ == 1 ) ? S_OK : S_FALSE;
}



//////////////// IIMCommand ////////////////////////

STDMETHODIMP CInnovPlugin::CmdNameGet(
    /* [out] */ BSTR __RPC_FAR* pCmdName_ )
{
    ::SysFreeString( *pCmdName_ );

    *pCmdName_ = ::SysAllocString( L"VISUAL_CPP_PLUGIN SHOW_MESSAGE" );

    return ( *pCmdName_ != NULL ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CInnovPlugin::CmdDescGet(
    /* [out] */ BSTR __RPC_FAR* pCmdDesc_ )
{
    ::SysFreeString( *pCmdDesc_ );

    *pCmdDesc_ = ::SysAllocString( L"Shows a message from the Visual C++ sample plug-in" );

    return ( *pCmdDesc_ != NULL ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CInnovPlugin::Execute(
    /* [retval][out] */ long __RPC_FAR* pReturnVal_ )
{
    *pReturnVal_ = 1;

    m_pMessageCenter->MessageBox( E_MESSAGE_TYPE_INFORMATION, _bstr_t( L"Visual C++ sample plug-in command invoked" ) );
    m_pSoundCenter->Play( _bstr_t( L"Error" ) );

    return ( *pReturnVal_ == 1 ) ? S_OK : S_FALSE;
}

STDMETHODIMP CInnovPlugin::MenuLocationGet(
    /* [out] */ BSTR __RPC_FAR* pMenuLoc_ )
{
    ::SysFreeString( *pMenuLoc_ );

    *pMenuLoc_ = ::SysAllocString( L"Visual C++ sample\\Show Message" );

    return ( *pMenuLoc_ != NULL ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CInnovPlugin::MenuDescGet(
    /* [out] */ BSTR __RPC_FAR* pMenuDesc_ )
{
    // We use the same description as the command
    return CmdDescGet( pMenuDesc_ );
}


//////////////// IIMLanguage ////////////////////////

STDMETHODIMP CInnovPlugin::LanguageSet(
    /* [in] */ BSTR           pLanguage_,
    /* [in] */ BSTR           pFontName_,
    /* [in] */ ECharacterSets charSet_ )
{
    // If possible, use this info to set the same language and font as the application loading the plug-in
    return S_OK;
}


//////////////// IIMProbe ////////////////////////

STDMETHODIMP CInnovPlugin::CanChangeUnits(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ )
{
    return E_NOTIMPL;
}

STDMETHODIMP CInnovPlugin::CanUseDeviceAsMouse(
    /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ )
{
    if ( pCanUseAsMouse_ != nullptr )
    {
        *pCanUseAsMouse_ = VARIANT_FALSE;    // Use VARIANT_TRUE if mouse mode is supported
        return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP CInnovPlugin::CompensationMethodGet(
    /* [retval][out] */ ECompensationMethods* pCompensationMethod_ )
{
    if ( pCompensationMethod_ != nullptr )
    {
        *pCompensationMethod_ = E_COMPENSATION_METHOD_LAST_POINT_POSITION;  // Choose appropriate value
        return S_OK;
    }

    return S_FALSE;
}

STDMETHODIMP CInnovPlugin::ConnectionEnd(
    /* [retval][out] */ long* pReturnVal_ )
{
    *pReturnVal_ = /* Disconnect from hardware here */ true ? 1 : 0;
    return *pReturnVal_ ? S_OK : S_FALSE;
}


STDMETHODIMP CInnovPlugin::ConnectionInit(
    /* [in] */ IIMProbeFeedback* pFeedback_,
    /* [retval][out] */ long*    pReturnVal_ )
{
    *pReturnVal_ = /* Disconnect to hardware here, keep pFeedback_ if successful */ true ? 1 : 0;
    return *pReturnVal_ ? S_OK : S_FALSE;
}


STDMETHODIMP CInnovPlugin::DeviceNameGet(
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( L"Visual C++ sample plug-in" );

    return ( *pName_ != NULL ) ? S_OK : E_OUTOFMEMORY;
}


STDMETHODIMP CInnovPlugin::DiameterGet(
    /* [retval][out] */ double* pDiameter_ )
{
    if ( pDiameter_ == nullptr )
    {
        return S_FALSE;
    }

    *pDiameter_ = 0.0;

    if ( !false /* Check for connection here */ )
    {
        return S_FALSE;
    }

    double diameter = 5.6 /* Obtain probe diameter here */;

    // TODO: If your device do not support directly application units,
    //       make sure that diameter is converted into application units using
    //       theSettings().HostUnitsScalingFactorGet()

    if ( diameter > 0.0 )
    {
        *pDiameter_ = diameter;
    }

    return S_OK;
}


STDMETHODIMP CInnovPlugin::HasPropertiesDlg(
    /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ )
{
    *pHasPropertiesDlg_ = VARIANT_TRUE; // Use VARIANT_FALSE if there are no dialog available
    return S_OK;
}


STDMETHODIMP CInnovPlugin::MeasurementStart(
    /* [ out, retval ] */ long* pReturnVal_ )
{
    m_pMessageCenter->MessageBox( E_MESSAGE_TYPE_INFORMATION, L"Measurement started" );
    *pReturnVal_ = E_MEASUREMENT_START_STARTED_CONTINUOUS_MEASURE;
    return S_OK;
}


STDMETHODIMP CInnovPlugin::MeasurementStop(
    /* [ out, retval ] */ long* pReturnVal_ )
{
    m_pMessageCenter->MessageBox( E_MESSAGE_TYPE_INFORMATION, L"Measurement stopped" );
    *pReturnVal_ = 1;
    return S_OK;
}


STDMETHODIMP CInnovPlugin::ModeSet( short modeNb_ )
{
    wchar_t message[ 1024 ];
    swprintf( message, L"Mode set to %d", modeNb_ );
    m_pMessageCenter->MessageBox( E_MESSAGE_TYPE_INFORMATION, message );
    return S_OK;
}


STDMETHODIMP CInnovPlugin::ModeGet(
    /* [out] */ short* pModeNb_ )
{
    *pModeNb_ = 1;
    return S_OK;
}


STDMETHODIMP CInnovPlugin::ModesGetNb(
    /* [retval][out] */ short* pModeNb_ )
{
    *pModeNb_ = 2;
    return S_OK;
}


STDMETHODIMP CInnovPlugin::ModeNameGet(
    /* [in] */ short  modeNb_,
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( modeNb_ == 1 ? L"First mode" : L"Other mode" );

    return ( *pName_ != NULL ) ? S_OK : E_OUTOFMEMORY;
}


STDMETHODIMP CInnovPlugin::NeedMeasurementButtons(
    /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ )
{
    *pNeedButtons_ = VARIANT_FALSE;
    return S_OK;
}


STDMETHODIMP CInnovPlugin::ProbingEnd()
{
    m_pMessageCenter->MessageBox( E_MESSAGE_TYPE_INFORMATION, L"Probing ended" );

    return S_OK;
}


STDMETHODIMP CInnovPlugin::ProbingStart(
    /* [in] */ IIMPointCloud* pCloud_,
    /* [in] */ VARIANT_BOOL /* sendLastPoint_ */ )
{
    m_pMessageCenter->MessageBox( E_MESSAGE_TYPE_INFORMATION, L"Probing started" );
    return S_OK;
}


STDMETHODIMP CInnovPlugin::PropertiesDlgShow()
{
    m_pMessageCenter->MessageBox( E_MESSAGE_TYPE_INFORMATION, L"Properties dialog" );

    return S_OK;
}


STDMETHODIMP CInnovPlugin::TransformationMatrixGet(
    /* [out][in] */ SAFEARRAY** pTransMat_ )
{
    return E_NOTIMPL;
}


STDMETHODIMP CInnovPlugin::TransformationMatrixSet(
    /* [in] */ SAFEARRAY** pTransMat_ )
{
    return E_NOTIMPL;
}


STDMETHODIMP CInnovPlugin::UnitsGet(
    /* [out] */ double __RPC_FAR* pUnits_ )
{
    return E_NOTIMPL;
}


STDMETHODIMP CInnovPlugin::UnitsSet(
    /* [in] */ double units_ )
{
    return E_NOTIMPL;
}

STDMETHODIMP CInnovPlugin::UseAutoViewpointGet(
    /* [out] */ VARIANT_BOOL __RPC_FAR* pUseAutoViewpoint_ )
{
    return S_OK;
}

STDMETHODIMP CInnovPlugin::UseAutoViewpointSet(
    /* [in] */ VARIANT_BOOL useAutoViewpoint_ )
{
    return S_OK;
}


STDMETHODIMP CInnovPlugin::UseDeviceAsMouseGet(
    /* [out] */ VARIANT_BOOL __RPC_FAR* pUseAsMouse_ )
{
    if ( pUseAsMouse_ == nullptr )
    {
        return S_FALSE;
    }

    *pUseAsMouse_ = VARIANT_FALSE;

    return S_OK;
}


STDMETHODIMP CInnovPlugin::UseDeviceAsMouseSet(
    /* [in] */ VARIANT_BOOL useAsMouse_ )
{
    std::wstring message = L"Use probe as mouse set to:";
    message += ( useAsMouse_ == VARIANT_TRUE ? L"true" : L"false" );
    m_pMessageCenter->MessageBox( E_MESSAGE_TYPE_INFORMATION, _bstr_t( message.c_str() ) );

    return S_OK;
}


STDMETHODIMP CInnovPlugin::SharedMatrixNameGet(
    /* [out] */ BSTR* pSharedMatrixName_ )
{
    return E_NOTIMPL;
}


STDMETHODIMP CInnovPlugin::SharedMatrixNameSet(
    /* [in] */ BSTR pSharedMatrixName_ )
{
    return E_NOTIMPL;
}


STDMETHODIMP CInnovPlugin::UseTransformationMatrixGet(
    /* [out] */ VARIANT_BOOL __RPC_FAR* /* useMatrix_ */ )
{
    return E_NOTIMPL;
}


STDMETHODIMP CInnovPlugin::UseTransformationMatrixSet(
    /* [in] */ VARIANT_BOOL /* useMatrix_ */ )
{
    return E_NOTIMPL;
}

//////////////// IIMSettings ////////////////////////

STDMETHODIMP CInnovPlugin::DoubleSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = 1;
        return S_OK;
    }
    return S_FALSE;
}


STDMETHODIMP CInnovPlugin::DoubleSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ double __RPC_FAR*       pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    // settingIndex_ should be validated, and if more than one setting is available,
    // settingIndex_ should be used to give the info about the right setting
    if ( pSettingName_ != nullptr )
    {
        ::SysFreeString( *pSettingName_ );
        *pSettingName_ = ::SysAllocString( L"VCPP_SAMPLE_DOUBLE_SETTING" ); // Beware of the 31 characters maximum!
    }
    if ( pDefaultValue_ != nullptr )
    {
        *pDefaultValue_ = 5264.463;
    }
    // These are the recommended values for those parameters:
    if ( pIsUserSpecific_ != nullptr )
    {
        *pIsUserSpecific_ = VARIANT_TRUE;   // VARIANT_TRUE means the setting be saved in the user's config
                                            // VARIANT_FALSE would save it globally for everyone that uses the same Polyworks installation
    }
    if ( pIsHostSpecific_ != nullptr )
    {
        *pIsHostSpecific_ = VARIANT_FALSE;  // VARIANT_FALSE means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
                                            // VARIANT_TRUE would reserve a different value for each software
    }
    // PolyWorks|Inspector only:
    if ( pIsProjectSetting_ != nullptr )
    {
        *pIsProjectSetting_ = VARIANT_FALSE;  // VARIANT_FALSE means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
                                              // VARIANT_TRUE would include it in PolyWorks|Inspector application settings when saving the project
                                              // NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be VARIANT_TRUE for such a saving to work
    }

    return S_OK;
}


STDMETHODIMP CInnovPlugin::LongSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = 1;
        return S_OK;
    }
    return S_FALSE;
}


STDMETHODIMP CInnovPlugin::LongSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ long __RPC_FAR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    // settingIndex_ should be validated, and if more than one setting is available,
    // settingIndex_ should be used to give the info about the right setting
    if ( pSettingName_ != nullptr )
    {
        ::SysFreeString( *pSettingName_ );
        *pSettingName_ = ::SysAllocString( L"VCPP_SAMPLE_LONG_SETTING" ); // Beware of the 31 characters maximum!
    }
    if ( pDefaultValue_ != nullptr )
    {
        *pDefaultValue_ = 867;
    }
    // These are the recommended values for those parameters:
    if ( pIsUserSpecific_ != nullptr )
    {
        *pIsUserSpecific_ = VARIANT_TRUE;   // VARIANT_TRUE means the setting be saved in the user's config
                                            // VARIANT_FALSE would save it globally for everyone that uses the same Polyworks installation
    }
    if ( pIsHostSpecific_ != nullptr )
    {
        *pIsHostSpecific_ = VARIANT_FALSE;  // VARIANT_FALSE means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
                                            // VARIANT_TRUE would reserve a different value for each software
    }
    // PolyWorks|Inspector only:
    if ( pIsProjectSetting_ != nullptr )
    {
        *pIsProjectSetting_ = VARIANT_FALSE;  // VARIANT_FALSE means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
                                              // VARIANT_TRUE would include it in PolyWorks|Inspector application settings when saving the project
                                              // NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be VARIANT_TRUE for such a saving to work
    }

    return S_OK;
}


STDMETHODIMP CInnovPlugin::StringSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = 1;
        return S_OK;
    }
    return S_FALSE;
}


STDMETHODIMP CInnovPlugin::StringSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ BSTR __RPC_FAR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    // settingIndex_ should be validated, and if more than one setting is available,
    // settingIndex_ should be used to give the info about the right setting
    if ( pSettingName_ != nullptr )
    {
        ::SysFreeString( *pSettingName_ );
        *pSettingName_ = ::SysAllocString( L"VCPP_SAMPLE_STRING_SETTING" ); // Beware of the 31 characters maximum!
    }
    if ( pDefaultValue_ != nullptr )
    {
        ::SysFreeString( *pDefaultValue_ );
        *pDefaultValue_ = ::SysAllocString( L"Sample string setting" );
    }
    // These are the recommended values for those parameters:
    if ( pIsUserSpecific_ != nullptr )
    {
        *pIsUserSpecific_ = VARIANT_TRUE;   // VARIANT_TRUE means the setting be saved in the user's config
                                            // VARIANT_FALSE would save it globally for everyone that uses the same Polyworks installation
    }
    if ( pIsHostSpecific_ != nullptr )
    {
        *pIsHostSpecific_ = VARIANT_FALSE;  // VARIANT_FALSE means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
                                            // VARIANT_TRUE would reserve a different value for each software
    }
    // PolyWorks|Inspector only:
    if ( pIsProjectSetting_ != nullptr )
    {
        *pIsProjectSetting_ = VARIANT_FALSE;  // VARIANT_FALSE means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
                                              // VARIANT_TRUE would include it in PolyWorks|Inspector application settings when saving the project
                                              // NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be VARIANT_TRUE for such a saving to work
    }

    return S_OK;
}

//////////////// IIMUnitsUser ////////////////////////

STDMETHODIMP CInnovPlugin::UnitsScalingFactorSet(
    /* [in] */ double scalingFactor_ )
{
    // A PolyWorks plug-in implementing the UnitsScalingFactorSet method should:
    //
    // - use the specified units scaling factor to convert data to be sent
    //   to the application from plug-in units to host application units
    // - use the specified units scaling factor to convert data sent by
    //   the application from host application units to plug-in units

    ( void ) scalingFactor_;

    // TODO: Store scaling factor using theSettings().HostUnitsScalingFactorSet( scalingFactor_ )

    return S_OK;
}
