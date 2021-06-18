// =================================================================================================
//   Polyworks SDK interface implementation
//
// Copyright © InnovMetric Logiciels Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include "stdafx.h"

#include "CCompanyNameRotaryTablePlugin.h"

#include <PolyWorksSDK/COM/IIMHost_i.c>
#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspect_i.c>
#include <PolyWorksSDK/COM/IIMRotaryTableFeedback.h>
#include <PolyWorksSDK/COM/IIMRotaryTableFeedback_i.c>
#include <time.h>

#include "CComMessageFilter.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================
const wchar_t* const PLUGIN_NAME = L"CompanyName Rotary Table Plugin";         // The name should not be longer than 31 characters

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

#ifndef E_BUSY
#define E_BUSY              _HRESULT_TYPEDEF_( 0x800700AAL )
#endif // #ifndef E_BUSY

static const DWORD BUSY_TIMEOUT = 100;

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
//   Get a time stamp with an optional offset
//
// Parameter: duration : Offset added to the current time
//
// Return: Current time stamp + duration
// -------------------------------------------------------------------------------------------------
static long GetExpireTime( long duration )    // duration in msec
{
    double clock_time = ( double )clock() * ( 1000.0 / ( double )CLOCKS_PER_SEC );
    return duration + ( long )clock_time;
}

// =================================================================================================
//   Check if the time stamp has been reached
//
// Parameter: expire_time : time stamp
//
// Return: true if expired, false otherwise
// -------------------------------------------------------------------------------------------------
static bool HasTimeExpired( long expire_time )
{
    double clock_time = ( double )clock() * ( 1000.0 / ( double )CLOCKS_PER_SEC );
    return ( clock_time - expire_time ) >= 0;
}

// =================================================================================================
//   See IGlobalInterfaceTable::GetInterfaceFromGlobal
// -------------------------------------------------------------------------------------------------
static HRESULT GITGetInterfaceFromGlobal( DWORD dwCookie_, REFIID riid_, void** ppv_ )
{
    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** )&pGIT );

    if ( res != S_OK )
    {
        return res;
    }

    if ( pGIT == nullptr )
    {
        return S_FALSE;
    }

    res = pGIT->GetInterfaceFromGlobal( dwCookie_, riid_, ppv_ );

    return res;
}

// =================================================================================================
//   See IGlobalInterfaceTable::RegisterInterfaceInGlobal
// -------------------------------------------------------------------------------------------------
static HRESULT GITRegisterInterfaceInGlobal( IUnknown* pUnk_, REFIID riid_, DWORD* pdwCookie_ )
{
    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** )&pGIT );

    if ( res != S_OK )
    {
        return res;
    }

    if ( pGIT == nullptr )
    {
        return S_FALSE;
    }

    res = pGIT->RegisterInterfaceInGlobal( pUnk_, riid_, pdwCookie_ );

    return res;
}

// =================================================================================================
//   See IGlobalInterfaceTable::RevokeInterfaceFromGlobal
// -------------------------------------------------------------------------------------------------
static HRESULT GITRevokeInterfaceFromGlobal( DWORD& dwCookie_, UINT retriesWhenBusy_ = 0 )
{
    if ( dwCookie_ == 0 )
    {
        return S_OK;
    }

    // Reset the cookie first
    DWORD cookie = dwCookie_;
    dwCookie_ = 0;

    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** )&pGIT );

    if ( res != S_OK )
    {
        return res;
    }

    if ( pGIT == nullptr )
    {
        return S_FALSE;
    }

    // Loop if ressource is busy
    res = E_FAIL;
    for ( ; ; --retriesWhenBusy_ )
    {
        res = pGIT->RevokeInterfaceFromGlobal( cookie );
        if ( res != S_OK )
        {
            if ( ( retriesWhenBusy_ > 0 ) && ( res == E_BUSY ) )
            {
                // Wait if the ressource is busy
                HANDLE hDummyEvent  = ::CreateEvent( nullptr, FALSE, FALSE, nullptr );
                DWORD  dummyEventID = 0;
                ::CoWaitForMultipleHandles( NULL, BUSY_TIMEOUT, 1, &hDummyEvent, &dummyEventID );
                ::CloseHandle( hDummyEvent );

                // Loop only in this case
                continue;
            }
        }

        // Don't loop otherwise
        break;
    }

    return res;
}

// #######################################################################
// IIMPlugin
// #######################################################################
STDMETHODIMP CCompanyNameRotaryTablePlugin::PlgNameGet(
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( PLUGIN_NAME );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}


// =============================================================================
STDMETHODIMP CCompanyNameRotaryTablePlugin::PlgVersionGet(
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
STDMETHODIMP CCompanyNameRotaryTablePlugin::Load(
    /* [in] */ IIMHost*       pIIMHost_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( ( pIIMHost_ == nullptr ) || ( pReturnVal_ == nullptr ) )
    {
        return S_FALSE;
    }

    // Check if the host application is PolyWorks|Inspector
    // Set *pReturnVal_ to 1 only in this case, as the other modules cannot use rotary tables
    m_host       = CComQIPtr< IIMInspect >( pIIMHost_ );
    *pReturnVal_ = m_host != nullptr ? 1 : 0;

    return ( *pReturnVal_ ) ? S_OK : S_FALSE;
}


// =============================================================================
STDMETHODIMP CCompanyNameRotaryTablePlugin::Unload(
    /* [retval][out] */ long* pReturnVal_ )
{
    // Release the Host
    m_host.Release();

    *pReturnVal_ = 1;

    return S_OK;
}

// #######################################################################
// IIMRotaryTable
// #######################################################################
STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableNameGet(
    /* [retval][out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( L"CompanyName Rotary Table" );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableConnectionInit(
    /* [in] */ IIMRotaryTableFeedback* pIIMRotaryTableFeedback_ )
{
    // TODO : Initialize the connection to the rotary table
    bool isConnected = true;

    if ( !isConnected )
    {
        return S_FALSE;
    }

    // TODO : Update the current angle of the rotary table
    m_currentAngle = 0.0;

    // TODO : Remove these lines that are only here to simplify the sample
    m_isRotationInProgess = false;
    m_isHomingInProgress  = false;

    // TODO : Update the current status of the rotary table
    m_currentStatus = EDeviceStatus::E_DEVICE_STATUS_READY;
    m_currentStatusDetails.clear();

    if ( !m_deviceCommunicationThread.ThreadLaunch( DeviceCommunicationThread, this ) )
    {
        // Disconnect the rotary table
        RotaryTableConnectionEnd();
        return false;
    }

    if ( pIIMRotaryTableFeedback_ != nullptr )
    {
        GITRegisterInterfaceInGlobal( pIIMRotaryTableFeedback_, IID_IIMRotaryTableFeedback, &m_cookieFeedback );
    }

    m_deviceCommunicationThread.ThreadResume();

    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableConnectionEnd()
{
    m_deviceCommunicationThread.ThreadKill();

    GITRevokeInterfaceFromGlobal( m_cookieFeedback );

    // TODO : Close the connection to the rotary table

    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableDefaultStepGet(
    /* [retval][out] */ double* pStep_ )
{
    // TODO : Change the step value according to the rotary table specifications
    *pStep_ = 1.0;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableCanChangeSpeed(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeSpeed_ )
{
    // TODO : Indicate whether the rotary table displacement speed can be changed
    *pCanChangeSpeed_ = VARIANT_TRUE;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableDefaultSpeedGet(
    /* [retval][out] */ double* pSpeed_ )
{
    // TODO : Change the pSpeed_ value according to the rotary table specifications
    *pSpeed_ = 100.0;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableMaximumSpeedGet(
    /* [retval][out] */ double* pSpeed_ )
{
    // TODO : Change the pSpeed_ value according to the rotary table specifications
    *pSpeed_ = 100.0;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableMinimumSpeedGet(
    /* [retval][out] */ double* pSpeed_ )
{
    // TODO : Change the pSpeed_ value according to the rotary table specifications
    *pSpeed_ = 1.0;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableSpeedSet(
    /* [in] */ double speed_ )
{
    // TODO : Apply the speed parameter to the rotary table
    // Note that this method is never called while the rotary table is in movement
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableCanChangeAcceleration(
    /* [retval][out] */ VARIANT_BOOL* pCanChangeAcceleration_ )
{
    // TODO : Indicate whether the rotary table displacement acceleration can be changed
    *pCanChangeAcceleration_ = VARIANT_TRUE;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableDefaultAccelerationGet(
    /* [retval][out] */ double* pAcceleration_ )
{
    // TODO : Change pAcceleration_ value according to the rotary table specifications
    *pAcceleration_ = 100.0;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableMaximumAccelerationGet(
    /* [retval][out] */ double* pAcceleration_ )
{
    // TODO : Change pAcceleration_ value according to the rotary table specifications
    *pAcceleration_ = 100.0;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableMinimumAccelerationGet(
    /* [retval][out] */ double* pAcceleration_ )
{
    // TODO : Change pAcceleration_ value according to the rotary table specifications
    *pAcceleration_ = 0.01;
    return S_OK;
}


STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableAccelerationSet(
    /* [in] */ double acceleration_ )
{
    // TODO : Apply the acceleration parameter to the rotary table.
    // Note that this method is never called while the rotary table is in movement
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableAngleGet(
    /* [retval][out] */ double* pAngle_ )
{
    // TODO : Return the cached angle, or read the actual position of the table if possible
    *pAngle_ = m_currentAngle;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableStatusGet(
    /* [out] */ EDeviceStatus* pStatus_,
    /* [out] */ BSTR*          pDetails_ )
{
    *pStatus_ = m_currentStatus;

    if ( m_currentStatus == EDeviceStatus::E_DEVICE_STATUS_NOT_READY )
    {
        // TODO : Replace de empty details string below with additional information on the status, if possible, to let the user know why the table is not ready.
        ::SysFreeString( *pDetails_ );
        *pDetails_ = ::SysAllocString( L"" );
    }

    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableHomingIsRequired(
    /* [retval][out] */ VARIANT_BOOL* pIsHomingRequired_ )
{
    // TODO : Indicate whether the rotary table needs to rotate to a home position upon connection.
    *pIsHomingRequired_ = VARIANT_TRUE;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableRotateHome()
{
    // TODO : Ask the rotary table to go to its home position. The home operation should be asynchronous
    // for the application. The device thread should monitor the operation and notify the application
    // with the OnRotaryTableRotationCompleted method when the operation is completed.

    // TODO : Remove these lines that are only here to simplify the sample
    m_currentAngle       = 0.0;
    m_isHomingInProgress = true;

    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableRotate(
    /* [in] */ double             angle_,
    /* [in] */ ERotationDirection direction_ )
{
    // TODO : Ask the rotary table to move to the specified angle. Note that the angle_ is defined using
    // the PolyWorks convention. The angle value is always positive and represents a counterclockwise
    // rotation from the home position. The rotation operation should be asynchronous for the application.
    // The device thread should monitor the operation and notify the application
    // with the OnRotaryTableRotationCompleted method when the operation is completed.

    // TODO : Remove these lines that are only here to simplify the sample. The angle should be updated
    // by the device thread during the rotation.
    m_currentAngle        = angle_;
    m_isRotationInProgess = true;

    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableCanStop(
    /* [retval][out] */ VARIANT_BOOL* pCanStop_ )
{
    // TODO : Indicate whether the rotary table can be ordered to stop an ongoing rotation
    *pCanStop_ = VARIANT_TRUE;
    return S_OK;
}

STDMETHODIMP CCompanyNameRotaryTablePlugin::RotaryTableStop()
{
    // TODO : Stop an ongoing rotation
    return S_OK;
}

// =================================================================================================
//   Thread for device communication
//
// Parameter: pPlugin_ : pointer to the plug-in
//
// Return: 0
// -------------------------------------------------------------------------------------------------
static unsigned __stdcall DeviceCommunicationThread( void* pPlugin_ )
{
    CCompanyNameRotaryTablePlugin* pPlugin = static_cast< CCompanyNameRotaryTablePlugin* >( pPlugin_ );

    if ( pPlugin == nullptr )
    {
        return 0;
    }

    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );

    {   // Begin scope for the COM message filter

        CRAIIComMessageFilter messageFilter;

        // Wait until the Initial Suspension is off
        pPlugin->m_deviceCommunicationThread.WaitUntilSuspendOff();

        long angleTimeForNextUpdate = 0;

        DWORD dummy = 0;
        while ( pPlugin->m_deviceCommunicationThread.IsEnableControl() )
        {
            pPlugin->m_deviceCommunicationThread.MainThreadRelease();

            // TODO: Update the angle of the rotary table if the table has moved
            if ( HasTimeExpired( angleTimeForNextUpdate ) )
            {
                pPlugin->OnRotaryTableAngleChanged( pPlugin->m_currentAngle );

                // Update the position at a 10 Hz frequency
                angleTimeForNextUpdate = GetExpireTime( 100 );
            }

            // TODO : Notify the application that an ongoing rotation is completed
            bool rotationIsCompleted = true;
            if ( pPlugin->m_isRotationInProgess && rotationIsCompleted )
            {
                pPlugin->m_isRotationInProgess = false;

                // IMPORTANT : Make sure to update the current angle and status before notifying about completion
                pPlugin->OnRotaryTableAngleChanged( pPlugin->m_currentAngle );

                // TODO : Update the status if necessary (e.g. machine is in emergency stop)
                // pPlugin->OnRotaryTableStatusChanged( EDeviceStatus::E_DEVICE_STATUS_NOT_READY );

                // TODO : Notify the application about the completion of the rotation operation. Indicate
                // whether the operation is successful or not. If case of failure, the empty string can
                // be replaced with an explanation about the cause of failure.
                pPlugin->OnRotaryTableRotationCompleted( E_ROTARY_TABLE_COMMAND_STATUS_SUCCEEDED, L"" );
            }


            // TODO : Notify the application that the homing operation is completed
            bool homingIsCompleted = true;
            if ( pPlugin->m_isHomingInProgress && homingIsCompleted )
            {
                pPlugin->m_isHomingInProgress = false;

                // TODO : Notify the application about the completion of the homing operation. Indicate
                // whether the operation is successful or not. If case of failure, the empty string can
                // be replaced with an explanation about the cause of failure.
                pPlugin->OnRotaryTableHomingCompleted( E_ROTARY_TABLE_COMMAND_STATUS_SUCCEEDED, L"" );
            }
        }

    }   // End scope for the COM message filter

    CoUninitialize();

    return 0;
}

// =================================================================================================
//   Feedbacks to the host application
// -------------------------------------------------------------------------------------------------

void CCompanyNameRotaryTablePlugin::OnRotaryTableAngleChanged( double angle_ )
{
    m_currentAngle = angle_;

    CComPtr< IIMRotaryTableFeedback > pRotaryTableFeedback;
    GITGetInterfaceFromGlobal(
        m_cookieFeedback,
        IID_IIMRotaryTableFeedback,
        ( void** )&pRotaryTableFeedback );
    if ( pRotaryTableFeedback != nullptr )
    {
        pRotaryTableFeedback->RotaryTableCurrentAngleSet( m_currentAngle );
    }
}

void CCompanyNameRotaryTablePlugin::OnRotaryTableStatusChanged( EDeviceStatus status_, const std::wstring& details_ )
{
    m_currentStatus        = status_;
    m_currentStatusDetails = details_;

    CComPtr< IIMRotaryTableFeedback > pRotaryTableFeedback;
    GITGetInterfaceFromGlobal(
        m_cookieFeedback,
        IID_IIMRotaryTableFeedback,
        ( void** )&pRotaryTableFeedback );
    if ( pRotaryTableFeedback != nullptr )
    {
        pRotaryTableFeedback->RotaryTableStatusSet( m_currentStatus, CComBSTR( m_currentStatusDetails.c_str() ) );
    }
}

void CCompanyNameRotaryTablePlugin::OnRotaryTableRotationCompleted( ERotaryTableCommandStatus commandStatus_, const std::wstring& details_ )
{
    CComPtr< IIMRotaryTableFeedback > pRotaryTableFeedback;
    GITGetInterfaceFromGlobal(
        m_cookieFeedback,
        IID_IIMRotaryTableFeedback,
        ( void** )&pRotaryTableFeedback );
    if ( pRotaryTableFeedback != nullptr )
    {
        pRotaryTableFeedback->RotaryTableRotationCompleted( commandStatus_, CComBSTR( details_.c_str() ) );
    }
}

void CCompanyNameRotaryTablePlugin::OnRotaryTableHomingCompleted( ERotaryTableCommandStatus commandStatus_, const std::wstring& details_ )
{
    CComPtr< IIMRotaryTableFeedback > pRotaryTableFeedback;
    GITGetInterfaceFromGlobal(
        m_cookieFeedback,
        IID_IIMRotaryTableFeedback,
        ( void** )&pRotaryTableFeedback );
    if ( pRotaryTableFeedback != nullptr )
    {
        pRotaryTableFeedback->RotaryTableHomingCompleted( commandStatus_, CComBSTR( details_.c_str() ) );
    }
}

// TODO : Call this function whenever the plug-in detects that the connection to the rotary table has been lost so the application
// can perform a clean disconnection. Upon this call, the application will call RotaryTableConnectionEnd on the plug-in.
void CCompanyNameRotaryTablePlugin::OnRotaryTableConnectionLost()
{
    CComPtr< IIMRotaryTableFeedback > pRotaryTableFeedback;
    GITGetInterfaceFromGlobal(
        m_cookieFeedback,
        IID_IIMRotaryTableFeedback,
        ( void** )&pRotaryTableFeedback );
    if ( pRotaryTableFeedback != nullptr )
    {
        pRotaryTableFeedback->RotaryTableConnectionEnd();
    }
}
