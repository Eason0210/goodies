// =================================================================================================
//   TODO: This class acts as an abstraction layer between your proprietary SDK and the plug-in.
//         You have to adapt it to your needs. The communication with the plug-in is done
//         through the receiver interface.
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include "stdafx.h"

#include "CCompanyNameSDKStub.h"

#include <PolyWorksSDK/COM/IIMMessageCenter.h>
#include <comutil.h>
#include <string>
#include <time.h>

#include "CComMessageFilter.h"
#include "CCompanyNameProbe.h"
#include "IReceiver.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
//   Constructor
//
// Parameter: pReceiver_ : Pointer to the object implementing the IReceiver interface
// -------------------------------------------------------------------------------------------------
CCompanyNameSDKStub::CCompanyNameSDKStub( IReceiver* pReceiver_ )
: m_pReceiver( pReceiver_ )
, m_connected( false )
, m_hDeviceCommunicationThreadEventOnOff( nullptr )
, m_hDeviceCommunicationThreadEventSuspended( nullptr )
, m_hDeviceCommunicationThreadEventResumed( nullptr )
, m_hDeviceCommunicationThread( nullptr )
, m_deviceCommunicationThreadState( E_THREAD_OFF )
, m_hDeviceCommunicationThreadEventStopped( nullptr )
{
}

// =================================================================================================
//   Destructor
// -------------------------------------------------------------------------------------------------
CCompanyNameSDKStub::~CCompanyNameSDKStub()
{
}

// =================================================================================================
//   Show the device properties dialog
//
// Parameter: HWND : Handle of the parent window
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::ConfigurationDialogShow( HWND /*parent_*/ )
{
    // TODO: Replace the code below by your own configuration dialog if needed
    //       otherwize remove it and return VARIANT_FALSE in function HasPropertiesDlg()
    std::wstring errorMessage = L"Properties dialog not implemented";
    CComPtr< IIMMessageCenter > pMessageCenter;
    if ( ( GITGetInterfaceFromGlobal(
               theCompanyNameProbe().m_cookieHost,
               IID_IIMMessageCenter,
               ( void** )&pMessageCenter ) == S_OK ) &&
         ( pMessageCenter != nullptr ) )
    {
        pMessageCenter->MessageBox( E_MESSAGE_TYPE_ERROR, _bstr_t( errorMessage.c_str() ) );
    }

    return true;
}

// =================================================================================================
//   Connect to the device
//
// Return: true if connected, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::Connect()
{
    DeviceCommunicationThreadLaunch();
    DeviceCommunicationThreadResume();

    // TODO: Initiate the connection with the device

    // TODO: Put m_connected to true only if connexion succeeded
    m_connected = true;

    return m_connected;
}

// =================================================================================================
//   Disconnect from the device
//
// Return: true if connected, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::Disconnect()
{

    DeviceCommunicationThreadKill();

    // TODO: Terminate the connection with the device

    // TODO: Put m_connected to false only if successfully disconnected
    m_connected = false;

    return !m_connected;
}

// =================================================================================================
//   Thread for device communication
//
// Parameter: pStub_ : pointer to the SDK stub
//
// Return: 0
// -------------------------------------------------------------------------------------------------
static unsigned __stdcall DeviceCommunicationThread( void* pStub_ )
{
    CCompanyNameSDKStub* pStub = static_cast< CCompanyNameSDKStub* >( pStub_ );

    if ( pStub == nullptr )
    {
        return 0;
    }

    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );

    {   // Begin scope for the COM message filter

        CRAIIComMessageFilter messageFilter;

        // Wait until the Initial Suspension is off
        ::WaitForSingleObject( pStub->m_hDeviceCommunicationThreadEventOnOff, INFINITE );
        ::SetEvent( pStub->m_hDeviceCommunicationThreadEventResumed );

        long timestamp = GetExpireTime( 5000 );

        DWORD dummy = 0;
        while ( pStub->m_deviceCommunicationThreadState != E_THREAD_OFF )
        {
            if ( ::CoWaitForMultipleHandles( 0, 20, 1, &pStub->m_hDeviceCommunicationThreadEventOnOff, &dummy ) == S_OK )
            {
                // Release thread
                ::SetEvent( pStub->m_hDeviceCommunicationThreadEventSuspended );
                ::WaitForSingleObject( pStub->m_hDeviceCommunicationThreadEventOnOff, INFINITE );
                ::SetEvent( pStub->m_hDeviceCommunicationThreadEventResumed );
            }

            SProbePosition position;

            // TODO: Check if a probed point is available
            //       To keep it simple for this code sample, we poll the device for any new points
            //       generated randomly.

            if ( HasTimeExpired( timestamp ) )
            {
                position.dX = double( double( rand() ) / ( RAND_MAX + 1.0 ) * 1000 );   // TODO: Generate a random position to fake device
                position.dY = double( double( rand() ) / ( RAND_MAX + 1.0 ) * 1000 );   // TODO: Generate a random position to fake device
                position.dZ = double( double( rand() ) / ( RAND_MAX + 1.0 ) * 1000 );   // TODO: Generate a random position to fake device

                // Transmit recorded points
                pStub->m_pReceiver->OnPointAcquired( position );

                timestamp = GetExpireTime( 5000 );
            }

            // TODO: Report the real-time position of the probe
            position.dX = double( double( rand() ) / ( RAND_MAX + 1.0 ) * 1000 );   // TODO: Generate a random position to fake device
            position.dY = double( double( rand() ) / ( RAND_MAX + 1.0 ) * 1000 );   // TODO: Generate a random position to fake device
            position.dZ = double( double( rand() ) / ( RAND_MAX + 1.0 ) * 1000 );   // TODO: Generate a random position to fake device
            pStub->m_pReceiver->OnPositionChanged( position );

            // TODO: Check/Update probe diameter
            //       If your device or SDK allows it, you could update the probe diameter in response to a change that happens after being connected.
            // pStub->m_pReceiver->UpdateProbeDiameter( probeDiameter );

            // TODO: Check/Update device status
            //       If your device or SDK allows it, you could update the device status in response to a change that happens after being connected.
            // pStub->m_pReceiver->UpdateDeviceStatus( deviceStatus );
        }

    }   // End scope for the COM message filter

    CoUninitialize();

    ::SetEvent( pStub->m_hDeviceCommunicationThreadEventStopped );

    return 0;
}

// =================================================================================================
//   Kill the device communication thread
// -------------------------------------------------------------------------------------------------
void CCompanyNameSDKStub::DeviceCommunicationThreadKill()
{
    if ( m_hDeviceCommunicationThread == nullptr )
    {
        return;
    }

    DeviceCommunicationThreadResume();
    m_deviceCommunicationThreadState = E_THREAD_OFF;

    // Keep processing COM messages while waiting for the thread to end
    DWORD handleIndex = 0;
    if ( ::CoWaitForMultipleHandles( 0, 5000, 1, &m_hDeviceCommunicationThreadEventStopped, &handleIndex ) != S_OK )
    {
        ::TerminateThread( m_hDeviceCommunicationThread, 0 );
    }

    ::CloseHandle( m_hDeviceCommunicationThreadEventOnOff );
    ::CloseHandle( m_hDeviceCommunicationThreadEventSuspended );
    ::CloseHandle( m_hDeviceCommunicationThreadEventResumed );
    ::CloseHandle( m_hDeviceCommunicationThread );
    ::CloseHandle( m_hDeviceCommunicationThreadEventStopped );

    m_hDeviceCommunicationThread = nullptr;
}

// =================================================================================================
//   Launch the device communication thread
// -------------------------------------------------------------------------------------------------
BOOL CCompanyNameSDKStub::DeviceCommunicationThreadLaunch()
{
    DeviceCommunicationThreadKill();

    // Create 4 inter-thread synchronization event objects
    m_hDeviceCommunicationThreadEventOnOff =
        ::CreateEvent(
            nullptr,             // no security
            FALSE,               // auto-reset
            FALSE,               // initially unsignaled
            nullptr );           // no name

    m_hDeviceCommunicationThreadEventSuspended =
        ::CreateEvent(
            nullptr,             // no security
            FALSE,               // auto-reset
            FALSE,               // initially unsignaled
            nullptr );           // no name

    m_hDeviceCommunicationThreadEventResumed =
        ::CreateEvent(
            nullptr,             // no security
            FALSE,               // auto-reset
            FALSE,               // initially unsignaled
            nullptr );           // no name

    m_hDeviceCommunicationThreadEventStopped =
        ::CreateEvent(
            nullptr,             // no security
            FALSE,               // auto-reset
            FALSE,               // initially unsignaled
            nullptr );           // no name

    m_deviceCommunicationThreadState = E_THREAD_SUSPENDED;   // Start with the mouse suspended

    DWORD dwThreadID;

    if ( nullptr == ( m_hDeviceCommunicationThread =
                          reinterpret_cast< HANDLE >( ::_beginthreadex(
                                                          nullptr,         // no security atts
                                                          0,               // default stack
                                                          DeviceCommunicationThread,
                                                          this,            // argument: pointer to object
                                                          0,               // creation flags
                                                          reinterpret_cast< unsigned* >( &dwThreadID ) ) ) ) )
    {
        ::CloseHandle( m_hDeviceCommunicationThreadEventOnOff );
        ::CloseHandle( m_hDeviceCommunicationThreadEventSuspended );
        ::CloseHandle( m_hDeviceCommunicationThreadEventResumed );
        ::CloseHandle( m_hDeviceCommunicationThreadEventStopped );

        m_deviceCommunicationThreadState = E_THREAD_OFF;

        return FALSE;
    }

    return TRUE;
}

// =================================================================================================
//   Resume the device communication thread
// -------------------------------------------------------------------------------------------------
BOOL CCompanyNameSDKStub::DeviceCommunicationThreadResume()
{
    if ( m_deviceCommunicationThreadState == E_THREAD_SUSPENDED )
    {
        m_deviceCommunicationThreadState = E_THREAD_ON;
        ::SetEvent( m_hDeviceCommunicationThreadEventOnOff );
        ::WaitForSingleObject( m_hDeviceCommunicationThreadEventResumed, INFINITE );
    }

    return TRUE;
}

// =================================================================================================
//   Suspend the device communication thread
// -------------------------------------------------------------------------------------------------
BOOL CCompanyNameSDKStub::DeviceCommunicationThreadSuspend()
{
    if ( m_deviceCommunicationThreadState != E_THREAD_ON )
    {
        return TRUE;
    }

    m_deviceCommunicationThreadState = E_THREAD_SUSPENDED;
    ::SetEvent( m_hDeviceCommunicationThreadEventOnOff );
    if ( ::WaitForSingleObject( m_hDeviceCommunicationThreadEventSuspended, 60000 ) != WAIT_OBJECT_0 )
    {
        DeviceCommunicationThreadKill();
        return FALSE;
    }

    return TRUE;
}
