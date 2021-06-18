// =================================================================================================
//   Polyworks SDK interface implementation
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include "stdafx.h"

#include "CCompanyNameProbePlugin.h"

#include <PolyWorksSDK/COM/IIMCommandCenter.h>
#include <PolyWorksSDK/COM/IIMHost_i.c>
#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspect_i.c>
#include <PolyWorksSDK/COM/IIMSettingsRepository.h>
#include <PolyWorksSDK/COM/IIMSettingsRepository_i.c>

#include "CCompanyNameProbe.h"
#include "CCompanyNameProbeSettings.h"
#include "Diagnostics.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================
const wchar_t* PLUGIN_NAME = L"CompanyName Probe Plugin";         // The name should not be longer than 31 characters

extern bool g_diagnostics;

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// #######################################################################
// IIMPlugin
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::PlgNameGet(
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( PLUGIN_NAME );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::PlgVersionGet(
    /* [out] */ long* pMajor_,
    /* [out] */ long* pMinor_,
    /* [out] */ long* pDot_ )
{
    *pMajor_ = 1;
    *pMinor_ = 0;
    *pDot_   = 0;

    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::Load(
    /* [in] */ IIMHost*       pIIMHost_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( ( pIIMHost_ == nullptr ) ||
         ( pReturnVal_ == nullptr ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    // Configure diagnostics
    DiagnosticConfigurationUpdate();

    // TODO Using the g_diagnostics value, implement special case to diagnose the plug-in
    if ( g_diagnostics )
    {
        // The diagnostic is enabled, let the user know.
        const wchar_t* pMessage = L"Diagnostics are activated for this plug-in.\n\nDiagnostics can be deactivated on the Plug-ins page of the Workspace Manager options.";
        ::MessageBoxW( nullptr, pMessage, L"Diagnostics", MB_OK );
    }

    // Check if it is PolyWorks|Inspector
    CComQIPtr< IIMInspect > pIMInspect( pIIMHost_ );
    if ( pIMInspect != nullptr )
    {
        // For now, only PolyWorks|Inspector can load a probing plug-in
        *pReturnVal_ = 1;

        // Get the project, in order to obtain a CommandCenter
        CComPtr< IIMInspectProject > pIMInspectProject;
        pIMInspect->ProjectGetCurrent( &pIMInspectProject );
        if ( pIMInspectProject != nullptr )
        {
            CComPtr< IIMCommandCenter > pCommandCenter;
            pIMInspectProject->CommandCenterCreate( &pCommandCenter );
            if ( pCommandCenter != nullptr )
            {
                GITRegisterInterfaceInGlobal( pCommandCenter, IID_IIMCommandCenter, &theCompanyNameProbe().m_cookieCommandCenter );
            }
        }
    }

    // TODO: Set *pReturnVal_ to 1 for any other module that can use your plug-in

    if ( *pReturnVal_ == 1 )
    {
        // Keep the host
        GITRegisterInterfaceInGlobal( pIIMHost_, IID_IIMHost, &( theCompanyNameProbe().m_cookieHost ) );
    }

    return ( *pReturnVal_ ) ? S_OK : S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::Unload(
    /* [retval][out] */ long* pReturnVal_ )
{
    ConnectionEnd( pReturnVal_ );

    // Release the CommandCenter
    GITRevokeInterfaceFromGlobal( theCompanyNameProbe().m_cookieCommandCenter );

    // Release the Host
    GITRevokeInterfaceFromGlobal( theCompanyNameProbe().m_cookieHost );

    return S_OK;
}


// #######################################################################
// IIMDeviceCamera
// #######################################################################

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::HasCamera(
    /* [retval][out] */ VARIANT_BOOL* pHasCamera_ )
{
    if ( pHasCamera_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if your device has a camera.
        *pHasCamera_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CameraActivationStateGet(
    /* [retval][out] */ VARIANT_BOOL* pActivationState_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasCamera method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CameraActivationStateSet(
    /* [in] */ VARIANT_BOOL activationState_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasCamera method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CameraViewDlgShow()
{
    // TODO: Show the camera view dialog box here, if any. This should be a modeless dialog box.
    //
    //       You can obtain a IIMDeviceCameraFeedback interface pointer
    //       by calling QueryInterface on the IIMProbeFeedback pointer received
    //       when IIMProbe::ConnectionInit is called.
    //
    //       IIMDeviceCameraFeedback::CameraActivationStateSet should be called
    //       when the camera activation state changes.
    //
    //       IIMDeviceCameraFeedback::CameraActivationStateSet should be called
    //       when the camera activation state changes, and
    //       IIMDeviceCameraFeedback::CameraViewClickBehaviorSet should be called
    //       when the current camera view click behavior changes.
    //
    //       IIMDeviceCameraFeedback::CameraViewHandleSet should be called to
    //       send the handle of the window or control that displays the camera view.
    //       Call this method again with a nullptr value when the window or control
    //       is destroyed.
    //
    //       Finally, IIMDeviceCameraFeedback::CameraViewDlgClosed should be called
    //       when the camera view dialog box is closed.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CameraViewDlgClose()
{
    // TODO: Close the camera view dialog box here, if any.

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CameraViewIsClickBehaviorSupported(
    /* [in] */ ECameraViewClickBehavior clickBehavior_,
    /* [retval][out] */ VARIANT_BOOL*   pIsSupported_ )
{
    if ( pIsSupported_ != nullptr )
    {
        switch ( clickBehavior_ )
        {
            case E_CAMERA_VIEW_CLICK_GO_TO:
                // TODO: Use VARIANT_TRUE if your camera view supports clicking to move the camera.
                *pIsSupported_ = VARIANT_FALSE;
                break;
            case E_CAMERA_VIEW_CLICK_FIND:
                // TODO: Use VARIANT_TRUE if your camera view supports clicking to move and find a target.
                *pIsSupported_ = VARIANT_FALSE;
                break;
            case E_CAMERA_VIEW_CLICK_MEASURE:
                // TODO: Use VARIANT_TRUE if your camera view supports clicking to move, find and measure a target.
                *pIsSupported_ = VARIANT_FALSE;
                break;
            default:
                *pIsSupported_ = VARIANT_FALSE;
                break;
        }
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CameraViewClickBehaviorGet(
    /* [retval][out] */ ECameraViewClickBehavior* pClickBehavior_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE to any behavior
    //       in the CameraViewIsClickBehaviorSupported method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CameraViewClickBehaviorSet(
    /* [in] */ ECameraViewClickBehavior clickBehavior_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE to any behavior
    //       in the CameraViewIsClickBehaviorSupported method.
    return E_NOTIMPL;
}

// #######################################################################
// IIMDeviceLevel
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanProvideGravityDirection(
    /* [retval][out] */ VARIANT_BOOL* pCanProvideGravityDirection_ )
{
    if ( pCanProvideGravityDirection_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if your device can provide the direction of gravity.
        *pCanProvideGravityDirection_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanProvideRealTimeAngles(
    /* [retval][out] */ VARIANT_BOOL* pCanProvideRealTimeAngles_ )
{
    if ( pCanProvideRealTimeAngles_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if your device can provide real-time angle readings from its level.
        *pCanProvideRealTimeAngles_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::GravityDirectionGet(
    /* [out] */ double* pI_,
    /* [out] */ double* pJ_,
    /* [out] */ double* pK_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanProvideGravityDirection method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::RealTimeAnglesGet(
    /* [out] */ double*            pAngleX_,
    /* [out] */ double*            pAngleY_,
    /* [out] */ double*            pAngleZ_,
    /* [out] */ ELevelAngleStatus* pStatusX_,
    /* [out] */ ELevelAngleStatus* pStatusY_,
    /* [out] */ ELevelAngleStatus* pStatusZ_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanProvideRealTimeAngles method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StabilityToleranceGet(
    /* [retval][out] */ double* pTolerance_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanProvideRealTimeAngles method.
    //       The stability tolerance should be added to the plug-in's other double settings.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StabilityToleranceSet(
    /* [in] */ double tolerance_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanProvideRealTimeAngles method.
    //       The stability tolerance should be added to the plug-in's other double settings.

    return E_NOTIMPL;
}


// #######################################################################
// IIMDeviceLevel2
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanUseLevelCompensation(
    /* [retval][out] */ VARIANT_BOOL* pCanUseLevelCompensation_ )
{
    if ( pCanUseLevelCompensation_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if your device allows level compensation.
        *pCanUseLevelCompensation_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::LevelCompensationStatusGet(
    /* [retval][out] */ ELevelCompensationStatus* pStatus_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseLevelCompensation method.
    //       Whenever the level compensation status changes, you should inform the application
    //       using the LevelCompensationStatusSet method from the IIMDeviceLevelFeedback interface.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseLevelCompensationGet(
    /* [retval][out] */ VARIANT_BOOL* pUseLevelCompensation_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseLevelCompensation method.
    //       Whenever the level compensation usage changes, you should inform the application
    //       using the UseLevelCompensationSet method from the IIMDeviceLevelFeedback interface.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseLevelCompensationSet(
    /* [in] */ VARIANT_BOOL useLevelCompensation_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseLevelCompensation method.

    return E_NOTIMPL;
}


// #######################################################################
// IIMInputEventsEmitter
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::TransmissionEnable(
    /* [in] */ IIMInputEventsReceiver* pInputEventsReceiver_ )
{
    if ( pInputEventsReceiver_ == nullptr )
    {
        return S_FALSE;
    }

    return theCompanyNameProbe().TransmissionEnable( pInputEventsReceiver_ ) ? S_OK : S_FALSE;
}

// =============================================================================

STDMETHODIMP CCompanyNameProbePlugin::TransmissionDisable()
{
    theCompanyNameProbe().TransmissionDisable();

    return S_OK;
}


// #######################################################################
// IIMLanguage
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::LanguageSet(
    /* [in] */ BSTR           pLanguage_,
    /* [in] */ BSTR           pFontName_,
    /* [in] */ ECharacterSets charSet_ )
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

// #######################################################################
// IIMPowerSource
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanProvidePowerStatus(
    /* [retval][out] */ VARIANT_BOOL* pCanProvidePowerStatus_ )
{
    if ( pCanProvidePowerStatus_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if your device provides information about its power status.
        *pCanProvidePowerStatus_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::PowerStatusGet (
    /* [ out ] */ EPowerSources* pSource_,
    /* [ out ] */ short*         pBatteryLevelPercentage_,
    /* [ out ] */ BSTR*          pDetails_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanProvidePowerStatus method.
    //       Whenever the power status changes, you should inform the application
    //       using the PowerStatusSet method from the IIMPowerSourceFeedback interface.
    return E_NOTIMPL;
}


// #######################################################################
// IIMProbe
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanChangeUnits(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ )
{
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanUseDeviceAsMouse(
    /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ )
{
    if ( pCanUseAsMouse_ != nullptr )
    {
        // TODO: Use VARIANT_FALSE if your device does not support mouse control
        *pCanUseAsMouse_ = VARIANT_TRUE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CompensationMethodGet(
    /* [retval][out] */ ECompensationMethods* pCompensationMethod_ )
{
    if ( pCompensationMethod_ != nullptr )
    {
        switch ( theCompanyNameProbeSettings().CompensationMethodGet() )
        {
            case E_COMP_METHOD_FIRST_POINT_VECTOR:
                *pCompensationMethod_ = E_COMPENSATION_METHOD_FIRST_POINT_VECTOR;
                return S_OK;    // TODO: Comment assignment and return S_FALSE if this method is not supported

            case E_COMP_METHOD_LAST_POINT_POSITION:
                // *pCompensationMethod_ = E_COMPENSATION_METHOD_LAST_POINT_POSITION;
                return S_FALSE;  // TODO: Uncomment assignment and return S_OK if this method is supported

            case E_COMP_METHOD_APPROACH_DIRECTION:
                // *pCompensationMethod_ = E_COMPENSATION_METHOD_APPROACH_DIRECTION;
                return S_FALSE;  // TODO: Uncomment assignment and return S_OK if this method is supported

            default:
                return S_FALSE;
        }
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ConnectionEnd(
    /* [retval][out] */ long* pReturnVal_ )
{
    *pReturnVal_ = theCompanyNameProbe().EndConnection() ? 1 : 0;
    return *pReturnVal_ ? S_OK : S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ConnectionInit(
    /* [in] */ IIMProbeFeedback* pFeedback_,
    /* [retval][out] */ long*    pReturnVal_ )
{
    *pReturnVal_ = theCompanyNameProbe().InitConnection( pFeedback_ ) ? 1 : 0;
    return *pReturnVal_ ? S_OK : S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::DeviceNameGet(
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    // TODO: This name will allow users to select your plug-in; use an appropriate device name
    *pName_ = ::SysAllocString( L"CompanyName Device" );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::DiameterGet(
    /* [retval][out] */ double* pDiameter_ )
{
    if ( pDiameter_ == nullptr )
    {
        return S_FALSE;
    }

    // TODO: If your device does not directly support application units,
    //       make sure that diameter is converted into application units using
    //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()
    const double diameter = theCompanyNameProbe().m_probeDiameter /* * theCompanyNameProbeSettings().HostUnitsScalingFactorGet() */;
    *pDiameter_ = diameter;
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::HasPropertiesDlg(
    /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ )
{
    // TODO: Change to VARIANT_FALSE if you have no dialog to display
    *pHasPropertiesDlg_ = VARIANT_TRUE;
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::MeasurementStart(
    /* [ out, retval ] */ long* pReturnVal_ )
{
    // TODO: Do something here if you need this method to start a measurement
    //       Should be used mainly for devices without buttons or similar triggers
    //       Note that there are many possible return values for this method.
    *pReturnVal_ = E_MEASUREMENT_START_FAILED;
    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::MeasurementStop(
    /* [ out, retval ] */ long* pReturnVal_ )
{
    // TODO: Do something here if you need this method to stop a measurement
    //       Should be used mainly for devices without buttons or similar triggers
    *pReturnVal_ = 1;
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ModeSet( short modeNb_ )
{
    theCompanyNameProbeSettings().ModeSet( ( ERecordModes ) modeNb_ );
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ModeGet(
    /* [out] */ short* pModeNb_ )
{
    *pModeNb_ = theCompanyNameProbeSettings().ModeGet();
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ModesGetNb(
    /* [retval][out] */ short* pModeNb_ )
{
    // TODO: If your device only has one probing mode, or if the mode cannot
    //       be changed for an outside application, you can give zero as
    //       the number of modes, remove the ModeNbGet method, and skip
    //       all of the code related to mode selection.
    *pModeNb_ = theCompanyNameProbe().ModeNbGet();
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ModeNameGet(
    /* [in] */ short  modeNb_,
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( theCompanyNameProbe().ModeNameGet( ( ERecordModes ) modeNb_ ) );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::NeedMeasurementButtons(
    /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ )
{
    // TODO: Use VARIANT_TRUE if you need to use the MeasurementStart and MeasurementStop methods
    //       Should be used mainly for devices without buttons or similar triggers
    *pNeedButtons_ = VARIANT_FALSE;
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ProbingEnd()
{
    // This deprecated method should always behave like IIMProbe2::ProbingEnd2( VARIANT_TRUE )
    return ProbingEnd2( VARIANT_TRUE );
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ProbingStart(
    /* [in] */ IIMPointCloud* pCloud_,
    /* [in] */ VARIANT_BOOL /* sendLastPoint_ */ )
{

    return theCompanyNameProbe().ProbingStart( pCloud_ ) ? S_OK : S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::PropertiesDlgShow()
{
    // TODO: If you need to stop probing with your device in order to change its properties,
    //       then uncomment the two blocks of code below to end and then restart probing

    //     // To synchronize with any changes made through the dialog,
    //     // we'll have to end the current probing
    //     CComPtr< IIMPointCloud > pCloud;
    //     if ( theCompanyNameProbe().m_cookiePtCloud != 0 )
    //     {
    //         GITGetInterfaceFromGlobal( theCompanyNameProbe().m_cookiePtCloud, IID_IIMPointCloud, (void**)&pCloud );
    //         if ( pCloud != nullptr )
    //         {
    //             theCompanyNameProbe().m_ProbingIsPaused = true;
    //             theCompanyNameProbe().ProbingEnd();
    //         }
    //     }

    theCompanyNameProbe().PropertiesDlgShow();

    //     // Start the probing again
    //     if ( pCloud != nullptr )
    //     {
    //         theCompanyNameProbe().ProbingStart( pCloud );
    //         theCompanyNameProbe().m_ProbingIsPaused = false;
    //     }
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::TransformationMatrixGet(
    /* [out][in] */ SAFEARRAY** /* pTransMat_ */ )
{
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::TransformationMatrixSet(
    /* [in] */ SAFEARRAY** /* pTransMat_ */ )
{
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UnitsGet(
    /* [out] */ double __RPC_FAR* pUnits_ )
{
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UnitsSet(
    /* [in] */ double units_ )
{
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseAutoViewpointGet(
    /* [out] */ VARIANT_BOOL __RPC_FAR* pUseAutoViewpoint_ )
{
    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseAutoViewpointSet(
    /* [in] */ VARIANT_BOOL useAutoViewpoint_ )
{
    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseDeviceAsMouseGet(
    /* [out] */ VARIANT_BOOL __RPC_FAR* pUseAsMouse_ )
{
    if ( pUseAsMouse_ == nullptr )
    {
        return S_FALSE;
    }

    *pUseAsMouse_ = theCompanyNameProbeSettings().UseProbeAsMouseGet() ? VARIANT_TRUE : VARIANT_FALSE;

    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseDeviceAsMouseSet(
    /* [in] */ VARIANT_BOOL useAsMouse_ )
{
    theCompanyNameProbeSettings().UseProbeAsMouseSet( ( useAsMouse_ == VARIANT_TRUE ) ? true : false );

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::SharedMatrixNameGet(
    /* [out] */ BSTR* /* pSharedMatrixName_ */ )
{
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::SharedMatrixNameSet(
    /* [in] */ BSTR /* pSharedMatrixName_ */ )
{
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseTransformationMatrixGet(
    /* [out] */ VARIANT_BOOL __RPC_FAR* /* useMatrix_ */ )
{
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseTransformationMatrixSet(
    /* [in] */ VARIANT_BOOL /* useMatrix_ */ )
{
    return E_NOTIMPL;
}


// #######################################################################
// IIMProbe2
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanChangeContinuousDistanceModeDistance(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ )
{
    if ( pCanChangeDistance_ != nullptr )
    {
        // TODO: Use VARIANT_FALSE if you do not support a Continuous distance mode.
        //       You should also ignore or remove all other references to the Continuous distance mode.
        *pCanChangeDistance_ = VARIANT_TRUE;
        return S_OK;
    }

    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanChangeContinuousTimeModeTime(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ )
{
    if ( pCanChangeTime_ != nullptr )
    {
        // TODO: Use VARIANT_FALSE if you do not support a Continuous time mode.
        //       You should also ignore or remove all other references to the Continuous time mode.
        *pCanChangeTime_ = VARIANT_TRUE;
        return S_OK;
    }

    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanFindTarget(
    /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ )
{
    if ( pCanFindTarget_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you want to order your device
        //       to find a target.
        *pCanFindTarget_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanGoHome(
    /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ )
{
    if ( pCanGoHome_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you want to order your device
        //       to go to a Home position.
        *pCanGoHome_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanGoXYZ(
    /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ )
{
    if ( pCanGoXYZ_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you want to order your device
        //       to move to or target a specific location.
        *pCanGoXYZ_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ContinuousDistanceModeDistanceGet(
    /* [retval][out] */ double* pDistance_ )
{
    if ( pDistance_ == nullptr )
    {
        return S_FALSE;
    }

    // Since the distance was saved in millimeters, we have to scale it by the units
    // in order to obtain the correct distance value for those units
    *pDistance_ = theCompanyNameProbeSettings().ContinuousDistanceDistGet() *
                  theCompanyNameProbeSettings().HostUnitsScalingFactorGet();

    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ContinuousDistanceModeDistanceSet(
    /* [in] */ double distance_ )
{
    // Always save the distance in millimeters
    theCompanyNameProbeSettings().ContinuousDistanceDistSet( distance_ / theCompanyNameProbeSettings().HostUnitsScalingFactorGet() );

    // Keep track of the current distance value, in the current units
    theCompanyNameProbe().m_lastRecordedPointDistance = distance_;

    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ContinuousTimeModeTimeGet(
    /* [retval][out] */ long* pTime_ )
{
    if ( pTime_ != nullptr )
    {
        // Obtain the time, in milliseconds, from the saved settings
        *pTime_ = theCompanyNameProbeSettings().ContinuousTimeDelayGet();
        return S_OK;
    }

    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ContinuousTimeModeTimeSet(
    /* [in] */ long time_ )
{
    // Note that this time should be saved in milliseconds
    theCompanyNameProbeSettings().ContinuousTimeDelaySet( time_ );

    // Keep track of the current time value
    theCompanyNameProbe().m_lastRecordedPointDelay = time_;

    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::FindTarget(
    /* [in] */ double searchRadius_,
    /* [in] */ double approximateDistance_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanFindTarget method
    //       Make sure values are converted from application units using
    //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()

    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::FindTargetParametersGet(
    /* [out] */ double* pSearchRadius_,
    /* [out] */ double* pApproximateDistance_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanFindTarget method.
    //       The parameters should be added to the plug-in's other double settings.

    // TODO: Since distance parameters are saved using mm,
    //       make sure settings values are converted to application units using
    //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()

    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::FindTargetParametersSet(
    /* [in] */ double searchRadius_,
    /* [in] */ double approximateDistance_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanFindTarget method.
    //       The parameters should be added to the plug-in's other double settings.

    // TODO: Since distance parameters are saved using mm,
    //       make sure settings values are converted from application units using
    //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()

    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::GoHome( void )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanGoHome method.
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::GoXYZ(
    /* [in] */ double X_,
    /* [in] */ double Y_,
    /* [in] */ double Z_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanGoXYZ method.
    //       Make sure values are converted from application units using
    //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()

    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::GoXYZCoordinatesGet(
    /* [out] */ double* pX_,
    /* [out] */ double* pY_,
    /* [out] */ double* pZ_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanGoXYZ method.
    //       The coordinates should be added to the plug-in's other double settings.

    // TODO: Since position parameters are saved using mm,
    //       make sure settings values are converted to application units using
    //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()

    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::GoXYZCoordinatesSet(
    /* [in] */ double X_,
    /* [in] */ double Y_,
    /* [in] */ double Z_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanGoXYZ method.
    //       The coordinates should be added to the plug-in's other double settings.

    // TODO: Since position parameters are saved using mm,
    //       make sure settings values are converted from application units using
    //       theCompanyNameScannerSettings().HostUnitsScalingFactorGet()

    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::NextPointIsCompensationPoint()
{
    // TODO: Implement this method only if you need to know when a
    //       compensation point is about to be measured.
    //       This can be used to take a more relaxed measurement,
    //       i.e. a faster or a less precise measurement.
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ProbingEnd2(
    /* [in] */ VARIANT_BOOL probeLastPoint_ )
{
    return theCompanyNameProbe().ProbingEnd( probeLastPoint_ == VARIANT_TRUE ) ? S_OK : S_FALSE;
}


// #######################################################################
// IIMProbe3
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::HasTemperature(
    /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ )
{
    if ( pHasTemperature_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you want to display a temperature value.
        *pHasTemperature_ = VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::HasRelativeHumidity(
    /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ )
{
    if ( pHasHumidity_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you want to display a relative humidity value.
        *pHasHumidity_ = VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::HasAirPressure(
    /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ )
{
    if ( pHasAirPressure_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you want to display an air pressure value.
        *pHasAirPressure_ = VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::HasStatus(
    /* [retval][out] */ VARIANT_BOOL* pHasStatus_ )
{
    if ( pHasStatus_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you want to display your device's status.
        *pHasStatus_ = VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::TemperatureGet(
    /* [retval][out] */ double* pTemperature_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasTemperature method.
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::RelativeHumidityGet(
    /* [retval][out] */ double* pHumidity_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasRelativeHumidity method.
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::AirPressureGet(
    /* [retval][out] */ double* pAirPressure_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasAirPressure method.
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StatusGet(
    /* [retval][out] */ EDeviceStatus* pStatus_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasStatus method.
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ReflectorSet(
    /* [in] */ BSTR               reflectorName_,
    /* [defaultvalue][in] */ BSTR standardReflectorName_ )
{
    // TODO: Implement this method only if your device uses reflectors as probes.
    //       The reflectorName_ (and only reflectorName_) should be added to the
    //       plug-in's other string settings, and saved like this:
    //       theCompanyNameProbeSettings().ReflectorNameSet( std::wstring( reflectorName_ ) );
    //
    //       If standardReflectorName_ is nullptr, then reflectorName_ should be the
    //       name of one of the standard reflectors (see StandardReflectorInfoGet).
    //
    //       If standardReflectorName_ is not nullptr, then reflectorName_ represents
    //       a special reflector, based on a standard reflector whose name is
    //       standardReflectorName_ (which might be needed by the device).
    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ReflectorGet(
    /* [ out ] */ BSTR* pReflectorName_ )
{
    // TODO: Implement this method only if your device uses reflectors as probes.
    //       The implementation should look like this:
    //       if ( pReflectorName_ != nullptr )
    //       {
    //           // Obtain the name of the reflector or special reflector from the saved settings
    //           *pReflectorName_ = ::SysAllocString( theCompanyNameProbeSettings().ReflectorNameGet() );
    //           return S_OK;
    //       }
    //       return S_FALSE;

    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StandardReflectorsGetNb(
    /* [ retval ][ out ] */ short* pReflectorNb_ )
{
    if ( pReflectorNb_ != nullptr )
    {
        // TODO: If your device uses reflectors as probes, replace the zero with
        //       the number of standard reflectors supported by your device.
        *pReflectorNb_ = 0;
        return S_OK;
    }
    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StandardReflectorInfoGet(
    /* [ in ]  */ short   reflectorIndex_,
    /* [ out ] */ BSTR*   pReflectorName_,
    /* [ out ] */ double* pReflectorOffset_ )
{
    // TODO: Implement this method only if your device uses reflectors as probes.
    //       The implementation should look like this:
    //       if ( ( pReflectorName_ != nullptr ) && ( pReflectorOffset_ != nullptr ) )
    //       {
    //           // Obtain the name of the specified reflector from the device
    //           *pReflectorName_ = ::SysAllocString( theCompanyNameProbe().StandardReflectorNameGet( reflectorIndex_ ) );
    //           // Obtain the offset (radius) of the specified reflector from the device
    //           *pReflectorOffset_ = theCompanyNameProbe().StandardReflectorOffsetGet( reflectorIndex_ );
    //           return S_OK;
    //       }
    //       return S_FALSE;

    return E_NOTIMPL;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ProbeTypeGet(
    /* [retval][out] */ EProbeTypes* pProbeType_ )
{
    if ( pProbeType_ != nullptr )
    {
        // TODO: If your device is currently using a reflector, you should
        //       return E_PROBE_TYPE_REFLECTOR instead.
        *pProbeType_ = E_PROBE_TYPE_PROBE;
        return S_OK;
    }
    return S_FALSE;
}


// #######################################################################
// IIMProbe4
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanChangeCompensationMethod(
    /* [ retval ][ out ] */ VARIANT_BOOL* pCanChangeMethod_ )
{
    if ( pCanChangeMethod_ != nullptr )
    {
        // TODO: If you want your plug-in to be configured to use either compensation
        //       method (E_COMPENSATION_METHOD_FIRST_POINT_VECTOR or
        //       E_COMPENSATION_METHOD_LAST_POINT_POSITION or
        //       E_COMPENSATION_METHOD_APPROACH_DIRECTION),
        //       then return VARIANT_TRUE instead of VARIANT_FALSE.
        //       You will then have to adjust the rest of your plug-in to
        //       make sure it behaves correctly for each compensation method:
        //       - E_COMPENSATION_METHOD_FIRST_POINT_VECTOR: always send a probe
        //         direction along with probe position when calling IIMPointCloud::PointsAdd
        //       - E_COMPENSATION_METHOD_LAST_POINT_POSITION: always send one last position
        //         when your IIMProbe2::ProbingEnd2 is called with probeLastPoint_ set
        //         to VARIANT_TRUE (see the ProbingEnd2 method above)
        //       - E_COMPENSATION_METHOD_APPROACH_DIRECTION: always send position when
        //         probing is started to ensure correct computation of approach direction
        *pCanChangeMethod_ = VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CompensationMethodSet(
    /* [ in ] */ ECompensationMethods compensationMethod_ )
{
    // TODO: Uncomment the code below if you return VARIANT_TRUE to the
    //       CanChangeCompensationMethod method above.

    //    ECompMethods method = E_NB_COMP_METHOD;
    //
    //    switch ( compensationMethod_ )
    //    {
    //        case E_COMPENSATION_METHOD_FIRST_POINT_VECTOR :
    //            method = E_COMP_METHOD_FIRST_POINT_VECTOR;
    //            break; // TODO: Comment assignment and return S_FALSE if this method is not supported
    //
    //        case E_COMPENSATION_METHOD_LAST_POINT_POSITION :
    //            method = E_COMP_METHOD_LAST_POINT_POSITION;
    //            break; // TODO: Comment assignment and return S_FALSE if this method is not supported
    //
    //        case E_COMPENSATION_METHOD_APPROACH_DIRECTION :
    //            // method = E_COMP_METHOD_APPROACH_DIRECTION;
    //            return S_FALSE; // TODO: Uncomment assignment and break if this method is supported
    //
    //        default :
    //            return S_FALSE;
    //    }
    //
    //    theCompanyNameProbeSettings().CompensationMethodSet( method );

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CompensationPointAutomaticTriggerDistanceGet(
    /* [ retval ][ out ] */ double* pDistanceInUnits_ )
{
    if ( pDistanceInUnits_ == nullptr )
    {
        return S_FALSE;
    }

    *pDistanceInUnits_ = theCompanyNameProbeSettings().AutomaticTriggerDistanceGet() *
                         theCompanyNameProbeSettings().HostUnitsScalingFactorGet();

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CompensationPointAutomaticTriggerDistanceSet(
    /* [ in ] */ double distanceInUnits_ )
{
    theCompanyNameProbeSettings().AutomaticTriggerDistanceSet(
        distanceInUnits_ / theCompanyNameProbeSettings().HostUnitsScalingFactorGet() );

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseCompensationPointAutomaticTriggerGet(
    /* [ retval ][ out ] */ VARIANT_BOOL* pUseAutomaticTrigger_ )
{
    if ( pUseAutomaticTrigger_ == nullptr )
    {
        return S_FALSE;
    }

    *pUseAutomaticTrigger_ = theCompanyNameProbeSettings().UseAutomaticTriggerGet() ? VARIANT_TRUE : VARIANT_FALSE;

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseCompensationPointAutomaticTriggerSet(
    /* [ in ] */ VARIANT_BOOL useAutomaticTrigger_ )
{
    theCompanyNameProbeSettings().UseAutomaticTriggerSet( useAutomaticTrigger_ == VARIANT_TRUE );
    return S_OK;
}


// #######################################################################
// IIMProbe5
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::UseMeasurementAutomaticTriggerGet(
    /* [ retval ][ out ] */ VARIANT_BOOL* pUseMeasurementAutomaticTrigger_ )
{
    if ( pUseMeasurementAutomaticTrigger_ == nullptr )
    {
        return S_FALSE;
    }

    *pUseMeasurementAutomaticTrigger_ =
        theCompanyNameProbeSettings().UseMeasurementAutomaticTriggerGet() ? VARIANT_TRUE : VARIANT_FALSE;

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseMeasurementAutomaticTriggerSet(
    /* [ in ] */ VARIANT_BOOL useMeasurementAutomaticTrigger_ )
{
    theCompanyNameProbeSettings().UseMeasurementAutomaticTriggerSet( useMeasurementAutomaticTrigger_ == VARIANT_TRUE );
    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::MeasurementAutomaticTriggerStabilityDelayGet(
    /* [ retval ][ out ] */ long* pDelay_ )
{
    if ( pDelay_ == nullptr )
    {
        return S_FALSE;
    }

    *pDelay_ = theCompanyNameProbeSettings().MeasurementAutomaticTriggerStabilityDelayGet();

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::MeasurementAutomaticTriggerStabilityDelaySet(
    /* [ in ] */ long delay_ )
{
    theCompanyNameProbeSettings().MeasurementAutomaticTriggerStabilityDelaySet( delay_ );
    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::MeasurementAutomaticTriggerStabilityToleranceGet(
    /* [ retval ][ out ] */ double* pToleranceInUnits_ )
{
    if ( pToleranceInUnits_ == nullptr )
    {
        return S_FALSE;
    }

    *pToleranceInUnits_ = theCompanyNameProbeSettings().MeasurementAutomaticTriggerStabilityToleranceGet() *
                          theCompanyNameProbeSettings().HostUnitsScalingFactorGet();

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::MeasurementAutomaticTriggerStabilityToleranceSet(
    /* [ in ] */ double toleranceInUnits_ )
{
    theCompanyNameProbeSettings().MeasurementAutomaticTriggerStabilityToleranceSet(
        toleranceInUnits_ / theCompanyNameProbeSettings().HostUnitsScalingFactorGet() );

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ModeTypeGet(
    /* [in] */ short               modeNb_,
    /* [out] */ EProbingModeTypes* pType_ )
{
    if ( ( pType_ == nullptr ) ||
         ( modeNb_ < E_FIRST_USER_MODE ) ||
         ( modeNb_ > E_LAST_USER_MODE ) )
    {
        return S_FALSE;
    }

    *pType_ = theCompanyNameProbe().ModeTypeGet( ( ERecordModes ) modeNb_ );

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::NextProbingIsShankProbing()
{
    // TODO: Implement this method only if you want to check if the device can
    //       correctly perform shank probing or not when ProbingStart is called.
    //       An internal flag can be raised on this call which will make the next
    //       call to ProbingStart fail by returning S_FALSE if there is a problem
    //       (ex: a required shank calibration is missing).In any case, the
    //       internal flag must always be reset before returning from ProbingStart.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::GoXYZ2(
    /* [in] */ double       X_,
    /* [in] */ double       Y_,
    /* [in] */ double       Z_,
    /* [in] */ VARIANT_BOOL searchForTarget_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanGoXYZ method.
    //       Call GoXYZ method if searchForTarget_ is VARIANT_TRUE.
    //       Otherwise, implement appropriate procedure to avoid target search.

    if ( searchForTarget_ == VARIANT_TRUE )
    {
        return GoXYZ( X_, Y_, Z_ );
    }
    else
    {
        return E_NOTIMPL;
    }
}

// #######################################################################
// IIMProbe6
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::FindTargetOnGoXYZGet(
    /* [retval][out] */ VARIANT_BOOL* pFindTargetOnGoXYZ_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanGoXYZ method.
    //       The value should be added to the plug-in's other long settings.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::FindTargetOnGoXYZSet(
    /* [in] */ VARIANT_BOOL findTargetOnGoXYZ_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanGoXYZ method.
    //       The value should be added to the plug-in's other long settings.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanGoFront(
    /* [retval][out] */ VARIANT_BOOL* pCanGoFront_ )
{
    if ( pCanGoFront_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you want to order your device
        //       to go to a Front position.
        *pCanGoFront_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::GoFront( void )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanGoFront method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::HasUserEnvironmentalParameters(
    /* [retval][out] */ VARIANT_BOOL* pHasUserEnvParams_ )
{
    if ( pHasUserEnvParams_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if your device supports user-defined environmental parameters.
        //       and you want them to be changed outside of your plug-in.
        *pHasUserEnvParams_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::EnvironmentalParametersSourceGet(
    /* [retval][out] */ EEnvironmentalParametersSources* pEnvParamsSource_ )
{
    if ( pEnvParamsSource_ != nullptr )
    {
        // TODO: If your device is currently using user-defined environmental parameters,
        //       you should return E_ENV_PARAMS_SOURCE_USER instead.
        //       If you answered VARIANT_TRUE in the HasUserEnvironmentalParameters method,
        //       then the source should be added to the plug-in's other long settings.
        *pEnvParamsSource_ = E_ENV_PARAMS_SOURCE_DEVICE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::EnvironmentalParametersSourceSet(
    /* [in] */ EEnvironmentalParametersSources envParamsSource_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasUserEnvironmentalParameters method.
    //       The source should be added to the plug-in's other long settings.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UserTemperatureGet(
    /* [retval][out] */ double* pTemperature_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasUserEnvironmentalParameters method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UserTemperatureSet(
    /* [in] */ double temperature_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasUserEnvironmentalParameters method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UserRelativeHumidityGet(
    /* [retval][out] */ double* pHumidity_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasUserEnvironmentalParameters method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UserRelativeHumiditySet(
    /* [in] */ double humidity_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasUserEnvironmentalParameters method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UserAirPressureGet(
    /* [retval][out] */ double* pAirPressure_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasUserEnvironmentalParameters method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UserAirPressureSet(
    /* [in] */ double airPressure_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasUserEnvironmentalParameters method.
    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe7
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanChangeFace(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeFace_ )
{
    if ( pCanChangeFace_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if your device can change its active face.
        *pCanChangeFace_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::FaceGet(
    /* [retval][out] */ short* pFace_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanChangeFace method.
    //       Whenever the face changes, you should inform the application
    //       using the FaceSet method from the IIMProbeFeedback5 interface.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::FaceSet(
    /* [ in ] */ short face_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanChangeFace method.
    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe8
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::HasShank(
    /* [retval][out] */ VARIANT_BOOL* pHasShank_ )
{
    if ( pHasShank_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the current probe has a shank.
        //       Whenever the probe shank availability changes, you should inform the application
        //       using the HasShankSet method from the IIMProbeFeedback6 interface.

        *pHasShank_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ShankDiameterGet(
    /* [retval][out] */ double* pShankDiameterInUnits_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasShank method.
    //       Whenever the diameter of the probe shank changes, you should inform the application
    //       using the ShankDiameterSet method from the IIMProbeFeedback6 interface.

    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe9
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanChangeRealTimePositionSending(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeRealTimePositionSending_ )
{
    if ( pCanChangeRealTimePositionSending_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device can be ordered to start or stop sending real-time positions.
        *pCanChangeRealTimePositionSending_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanPowerSearchTarget(
    /* [retval][out] */ VARIANT_BOOL* pCanPowerSearchTarget_ )
{
    if ( pCanPowerSearchTarget_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device can be ordered to power search a target.
        *pCanPowerSearchTarget_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanUseAutomaticTargetRecognition(
    /* [retval][out] */ VARIANT_BOOL* pCanUseAutomaticTargetRecognition_ )
{
    if ( pCanUseAutomaticTargetRecognition_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device allows automatic target recognition.
        *pCanUseAutomaticTargetRecognition_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanUseLaserPointer(
    /* [retval][out] */ VARIANT_BOOL* pCanUseLaserPointer_ )
{
    if ( pCanUseLaserPointer_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device allows laser pointer activation.
        *pCanUseLaserPointer_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanUseTargetIllumination(
    /* [retval][out] */ VARIANT_BOOL* pCanUseTargetIllumination_ )
{
    if ( pCanUseTargetIllumination_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device allows target illumination.
        *pCanUseTargetIllumination_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanUseTargetLock(
    /* [retval][out] */ VARIANT_BOOL* pCanUseTargetLock_ )
{
    if ( pCanUseTargetLock_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device allows target lock.
        *pCanUseTargetLock_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::HasManualControlsDlg(
    /* [retval][out] */ VARIANT_BOOL* pHasManualControlsDialog_ )
{
    if ( pHasManualControlsDialog_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device has a manual controls dialog.
        *pHasManualControlsDialog_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ManualControlsDlgShow( void )
{
    // TODO: Show the manual controls dialog box here, if any.
    //       Otherwise, this whole function should do nothing but return S_OK.
    //
    //       You can obtain a IIMProbeFeedback9 interface pointer
    //       by calling QueryInterface on the IIMProbeFeedback pointer received
    //       when IIMProbe::ConnectionInit is called.
    //
    //       IIMProbeFeedback9::ManualControlsDlgClosed should be called
    //       when the manual controls dialog box is closed.

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::NextProbingIsSingleDirectionProbing( void )
{
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::SendRealTimePositionsGet(
    /* [retval][out] */ VARIANT_BOOL* pSendRealTimePositions_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanChangeRealTimePositionSending method.
    //       Whenever the real-time positions activation functionality changes, you should inform the application
    //       using the SendRealTimePositionsSet method from the IIMProbeFeedback8 interface.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::SendRealTimePositionsSet(
    /* [in] */ VARIANT_BOOL sendRealTimePositions_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanChangeRealTimePositionSending method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::PowerSearchTarget( void )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanPowerSearchTarget method

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StatusGet2(
    /* [out] */ BSTR*                  pDetails_,
    /* [retval][out] */ EDeviceStatus* pStatus_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasStatus method.
    //       Whenever the current status and details of the device changes, you should inform the application
    //       using the StatusSet2 method from the IIMProbeFeedback8 interface.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseAutomaticTargetRecognitionGet(
    /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTargetRecognition_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseAutomaticTargetRecognition method.
    //       Whenever the automatic target recognition usage changes, you should inform the application
    //       using the UseAutomaticTargetRecognitionSet method from the IIMProbeFeedback8 interface.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseAutomaticTargetRecognitionSet(
    /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseAutomaticTargetRecognition method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseLaserPointerGet(
    /* [retval][out] */ VARIANT_BOOL* pUseLaserPointer_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseLaserPointer method.
    //       Whenever the laser pointer usage changes, you should inform the application
    //       using the UseLaserPointerSet method from the IIMProbeFeedback8 interface.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseLaserPointerSet(
    /* [in] */ VARIANT_BOOL useLaserPointer_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseLaserPointer method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseTargetIlluminationGet(
    /* [retval][out] */ VARIANT_BOOL* pUseTargetIllumination_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseTargetIllumination method.
    //       Whenever the target illumination usage changes, you should inform the application
    //       using the UseTargetIlluminationSet method from the IIMProbeFeedback8 interface.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseTargetIlluminationSet(
    /* [in] */ VARIANT_BOOL useTargetIllumination_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseTargetIllumination method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseTargetLockGet(
    /* [retval][out] */ VARIANT_BOOL* pUseTargetLock_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseTargetLock method.
    //       Whenever the target lock usage changes, you should inform the application
    //       using the UseTargetLockSet method from the IIMProbeFeedback8 interface.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::UseTargetLockSet(
    /* [in] */ VARIANT_BOOL useTargetLock_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the CanUseTargetLock method.

    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe10
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanChangeContinuousMeasuringResumingOnTargetRecovery(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeResumeMeasuring_ )
{
    if ( pCanChangeResumeMeasuring_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device can configure the resuming of continuous measuring
        //       on target recovery.
        *pCanChangeResumeMeasuring_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ResumeContinuousMeasuringOnTargetRecoveryGet(
    /* [retval][out] */ VARIANT_BOOL* pResumeMeasuring_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the
    //       CanChangeContinuousMeasuringResumingOnTargetRecovery method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ResumeContinuousMeasuringOnTargetRecoverySet(
    /* [in] */ VARIANT_BOOL resumeMeasuring_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the
    //       CanChangeContinuousMeasuringResumingOnTargetRecovery method.

    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe11
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::HasMotorActivationState(
    /* [retval][out] */ VARIANT_BOOL* pHasActivationState_ )
{
    if ( pHasActivationState_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device has a motor activation state.
        //
        //       You can obtain a IIMProbeFeedback9 interface pointer
        //       by calling QueryInterface on the IIMProbeFeedback pointer received
        //       when IIMProbe::ConnectionInit is called.
        //
        //       IIMProbeFeedback9::MotorActivationStateSet should be called
        //       when the motor activation state changes.

        *pHasActivationState_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::CanDeactivateMotors(
    /* [retval][out] */ VARIANT_BOOL* pCanDeactivateMotors_ )
{
    if ( pCanDeactivateMotors_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if the device has motors that can be deactivated,
        //       but there is no way to know the current activation state of those motors
        //       (i.e. HasMotorActivationState returned VARIANT_FALSE).
        *pCanDeactivateMotors_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::MotorActivationStateGet(
    /* [retval][out] */ VARIANT_BOOL* pActivationState_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasMotorActivationState method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::MotorActivationStateSet(
    /* [in] */ VARIANT_BOOL activationState_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasMotorActivationState method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ManualControlsDlgClose()
{
    // TODO: Close the manual controls dialog box here, if any.

    return S_OK;
}

// #######################################################################
// IIMProbe12
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::IsCompensationMethodSupported(
    /* [in] */ ECompensationMethods   compensationMethod_,
    /* [retval][out] */ VARIANT_BOOL* pIsSupported_ )
{
    // TODO:  Uncomment this code if you implement more then one compensation method.

    //     if ( pIsSupported_ != nullptr )
    //     {
    //         switch( compensationMethod_ )
    //         {
    //             case E_COMPENSATION_METHOD_FIRST_POINT_VECTOR:
    //                 // TODO: Use VARIANT_TRUE if the device support this compensation method.
    //                 break;
    //             case E_COMPENSATION_METHOD_LAST_POINT_POSITION:
    //                 // TODO: Use VARIANT_TRUE if the device support this compensation method.
    //                 break;
    //             case E_COMPENSATION_METHOD_APPROACH_DIRECTION:
    //                 // TODO: Use VARIANT_TRUE if the device support this compensation method.
    //                 break;
    //
    //             default:
    //                 return S_FALSE;
    //         }
    //
    //         return S_OK;
    //     }

    return S_FALSE;
}

// #######################################################################
// IIMProbe13
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::LocalizationProbeSelectionDlgShow()
{
    // Note that only a few specific devices are allowed to use the localization functionality.
    // So typical probing plug-ins do not need to implement this method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::LocalizationProbeNameGet(
    /* [retval][out] */ BSTR* pProbeName_ )
{
    // Note that only a few specific devices are allowed to use the localization functionality.
    // So typical probing plug-ins do not need to implement this method.

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::LocalizationProbeActivate(
    /* [in] */ VARIANT_BOOL activate_ )
{
    // Note that only a few specific devices are allowed to use the localization functionality.
    // So typical probing plug-ins do not need to implement this method.

    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe14
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::ProbeGet(
    /* [ out ] */ BSTR* pProbeName_ )
{
    // TODO: Implement this method only if your device uses standard probes.
    //       The implementation should look like this:
    //       if ( pProbeName_ != nullptr )
    //       {
    //           // Obtain the name of the standard probe from the saved settings
    //           *pProbeName_ = ::SysAllocString( theCompanyNameProbeSettings().ProbeNameGet() );
    //           return S_OK;
    //       }
    //       return S_FALSE;

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ProbeSet(
    /* [in] */ BSTR probeName_ )
{
    // TODO: Implement this method only if your device uses standard probes.
    //       The probeName_ should be added to the plug-in's other string settings, and saved like this:
    //       theCompanyNameProbeSettings().ProbeNameSet( std::wstring( probeName_ ) );

    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StandardProbesGetNb(
    /* [ retval ][ out ] */ short* pProbeNb_ )
{
    if ( pProbeNb_ != nullptr )
    {
        // TODO: If your device uses standard probes, replace the zero with
        //       the number of standard probes supported by your device.
        *pProbeNb_ = 0;
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StandardProbeInfoGet(
    /* [ in ]  */ short   probeIndex_,
    /* [ out ] */ BSTR*   pProbeName_,
    /* [ ou t] */ double* pProbeDiameterInUnits_ )
{
    // TODO: Implement this method only if your device uses standard probes.
    //       The implementation should look like this:
    //       if ( pProbeName_ != nullptr )
    //       {
    //           // Obtain the name of the specified probe from the device
    //           *pProbeName_ = ::SysAllocString( theCompanyNameProbe().StandardProbeNameGet( probeIndex_ ) );
    //           // Obtain the diameter of the specified probe from the device
    //           *pProbeDiameterInUnits_ = theCompanyNameProbe().StandardProbeDiameterGet( probeIndex_ );
    //           return S_OK;
    //       }
    //       return S_FALSE;

    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe15
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::DeviceDeprecatedNamesGet(
    /* [out][in] */ SAFEARRAY** pNames_ )
{
    // TODO: Implement this method only if your plug-in changes name and there
    //       are existing scripts using the deprecated name(s).
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::ModeDeprecatedNamesGet(
    /* [in] */ short            modeIndex_,
    /* [out][in] */ SAFEARRAY** pNames_ )
{
    // TODO: Implement this method only if you change the names of probing modes
    //       and there are existing scripts using the deprecated name(s).
    //       If a mode name has not changed, you can return S_FALSE when
    //       modeIndex_ corresponds to that mode.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StandardReflectorDeprecatedNamesGet(
    /* [in] */ short            reflectorIndex_,
    /* [out][in] */ SAFEARRAY** pNames_ )
{
    // TODO: Implement this method only if you change the names of standard
    //       reflectors and there are existing scripts or custom reflectors
    //       using the deprecated name(s). If a reflector name has not changed,
    //       you can return S_FALSE when reflectorIndex_ corresponds to that
    //       reflector.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StandardProbeDeprecatedNamesGet(
    /* [in] */ short            probeIndex_,
    /* [out][in] */ SAFEARRAY** pNames_ )
{
    // TODO: Implement this method only if you change the name of a probe and
    //       there are existing scripts using the deprecated name(s). If
    //       a probe name has not changed, you can return S_FALSE when
    //       probeIndex_ corresponds to that probe.
    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe16
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::CanFindTargetUsingCamera(
    /* [retval][out] */ VARIANT_BOOL* pCanFindTargetUsingCamera_ )
{
    if ( pCanFindTargetUsingCamera_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if your device can find a target using its camera.
        *pCanFindTargetUsingCamera_ = VARIANT_FALSE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::FindTargetUsingCamera()
{
    // TODO: Implement this method only if *pCanFindTargetUsingCamera_ was set
    //       to true in CanFindTargetUsingCamera. This method should start
    //       the target finding process using its camera.
    return E_NOTIMPL;
}

// #######################################################################
// IIMProbe17
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::DeviceTypeGet(
    /* [retval][out] */ EDeviceTypes* pDeviceType_ )
{
    if ( pDeviceType_ != nullptr )
    {
        // TODO: Change the value assigned to one that fits your device.
        *pDeviceType_ = E_DEVICE_TYPE_UNDEFINED;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::IsToolTypeSupported(
    /* [in] */ EProbeTypes            probeType_,
    /* [retval][out] */ VARIANT_BOOL* pIsSupported_ )
{
    if ( pIsSupported_ != nullptr )
    {
        // TODO: Adjust this to return VARIANT_FALSE for values of EProbeTypes
        //       that are not supported.
        *pIsSupported_ = VARIANT_TRUE;
        return S_OK;
    }

    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StandardReflectorInfosSet(
    /* [in] */ SAFEARRAY** pNames_,
    /* [in] */ SAFEARRAY** pDiameters_ )
{
    // TODO: Implement this method only if your device uses reflectors as probes
    //       and the list of reflectors can vary from one device to the other.
    //       Use the pNames_ and pDiameter_ arrays to update the list of reflectors
    //       returned when the device is not connected.
    //       If your device uses reflectors but the list is fixed, you do not
    //       need to implement this method.
    return E_NOTIMPL;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StandardProbeInfosSet(
    /* [in] */ SAFEARRAY** pNames_,
    /* [in] */ SAFEARRAY** pDiameters_ )
{
    // TODO: Implement this method only if your device uses standard probes
    //       and the list of probes can vary from one device to the other.
    //       Use the pNames_ and pDiameter_ arrays to update the list of reflectors
    //       returned when the device is not connected.
    //       If your device uses standard probes but the list is fixed,
    //       you do not need to implement this method.
    return E_NOTIMPL;
}


// #######################################################################
// IIMPieceTemperature
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::HasPieceTemperature(
    /* [retval][out] */ VARIANT_BOOL* pHasPieceTemperature_ )
{
    if ( pHasPieceTemperature_ != nullptr )
    {
        // TODO: Use VARIANT_TRUE if you can provide a piece temperature value.
        //       You will then have to obtain a IIMPieceTemperatureFeedback interface pointer
        //       by calling QueryInterface on a IIMProbeFeedback interface pointer,
        //       and call IIMPieceTemperatureFeedback::PieceTemperatureSet whenever the
        //       piece temperature changes.
        *pHasPieceTemperature_ = VARIANT_FALSE;
        return S_OK;
    }
    return S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::PieceTemperatureGet(
    /* [retval][out] */ double* pPieceTemperature_ )
{
    // TODO: Implement this method if you answered VARIANT_TRUE in the HasPieceTemperature method.
    return E_NOTIMPL;
}

// #######################################################################
// IIMSettings
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::DoubleSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    return theCompanyNameProbeSettings().DoubleSettingsNbGet( nbSettings_ );
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::DoubleSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ double __RPC_FAR*       pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    return theCompanyNameProbeSettings().DoubleSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::LongSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    return theCompanyNameProbeSettings().LongSettingsNbGet( nbSettings_ );
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::LongSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ long __RPC_FAR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    return theCompanyNameProbeSettings().LongSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StringSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    return theCompanyNameProbeSettings().StringSettingsNbGet( nbSettings_ );
}


// =============================================================================
STDMETHODIMP CCompanyNameProbePlugin::StringSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ BSTR __RPC_FAR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    return theCompanyNameProbeSettings().StringSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}

// #######################################################################
// IIMSettings2
// #######################################################################

STDMETHODIMP CCompanyNameProbePlugin::MatrixSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    return theCompanyNameProbeSettings().MatrixSettingsNbGet( nbSettings_ );
}


STDMETHODIMP CCompanyNameProbePlugin::MatrixSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ SAFEARRAY**   pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    return theCompanyNameProbeSettings().MatrixSettingGet(
        settingIndex_,
        pSettingName_,
        pDefaultValue_,
        pIsUserSpecific_,
        pIsHostSpecific_,
        pIsProjectSetting_ );
}

// #######################################################################
// IIMSettings3
// #######################################################################

STDMETHODIMP CCompanyNameProbePlugin::OnSettingsChange(
    /* [in] */ SAFEARRAY* pSettingNames_ )
{
    // TODO : This function is called when the application has changed one or more
    //        of the plug-in's settings. This can happen for example during the
    //        execution of the CONFIG POP command.
    //        The pSettingNames_ parameter is an array containing the name of
    //        all parameters that were modified.
    //        You should perform whatever action is needed by your plug-in to
    //        adapt to the changed settings.
    //        Note that if your plug-in uses simple settings that are always read
    //        from the CCompanyNameProbeSettings object, you may not have
    //        anything to do in this function.

    return S_OK;
}

// #######################################################################
// IIMUnitsUser
// #######################################################################
STDMETHODIMP CCompanyNameProbePlugin::UnitsScalingFactorSet(
    /* [in] */ double scalingFactor_ )
{
    // A PolyWorks plug-in implementing the UnitsScalingFactorSet method should:
    //
    // - use the specified units scaling factor to convert data to be sent
    //   to the application from plug-in units to host application units
    // - use the specified units scaling factor to convert data sent by
    //   the application from host application units to plug-in units

    if ( theCompanyNameProbeSettings().HostUnitsScalingFactorSet( scalingFactor_ ) )
    {
        // TODO: Make appropriate calls to ensure appropriate propagation of new units for data conversion
        theCompanyNameProbe().UnitsScalingFactorSet();

        return S_OK;
    }

    return S_FALSE;
}
