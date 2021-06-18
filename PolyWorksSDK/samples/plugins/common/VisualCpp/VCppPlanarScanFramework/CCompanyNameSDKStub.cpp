// =================================================================================================
//   SDK Communication Stub Implementation.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameSDKStub.h"

#include <PolyWorksSDK/COM/IIMScannerFeedback.h>
#include <PolyWorksSDK/COM/IIMScannerFeedback_i.c>
#include <atlcomcli.h>

#include "CComMessageFilter.h"
#include "CCompanyNameScannerReceiver.h"

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
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   Ctor.
// -------------------------------------------------------------------------------------------------
CCompanyNameSDKStub::CCompanyNameSDKStub( CCompanyNameScannerReceiver& receiver_ )
: m_receiver( receiver_ )
{
    m_hScanStartEvent = CreateEvent( nullptr, FALSE, FALSE, nullptr );
    m_hScanEndEvent   = CreateEvent( nullptr, FALSE, FALSE, nullptr );

    if ( !m_communicationThread.ThreadLaunch( &CCompanyNameSDKStub::CommunicationThreadProc, this ) ||
         !m_communicationThread.ThreadResume() )
    {
        ASSERT( 0 );
    }
}

// =================================================================================================
//   Dtor.
// -------------------------------------------------------------------------------------------------
CCompanyNameSDKStub::~CCompanyNameSDKStub()
{
    m_communicationThread.ThreadKill();

    CloseHandle( m_hScanStartEvent );
    CloseHandle( m_hScanEndEvent );

    Disconnect( false );
}

// =================================================================================================
// Get the grid data
//
// Return : Grid data
// -------------------------------------------------------------------------------------------------
SScanData CCompanyNameSDKStub::AcquiredDataGet()
{
    // Size of the planar grid
    const short width  = 200;
    const short height = 200;

    // Initialize with the digitizing vector and the size
    SScanData data( 0.0, 0.0, 1.0, width, height );

    // TODO: Remove. Used for the simulator
    // SIMULATION CODE BEGIN

    // Creating simulation data, format : x,y,z,row,col
    for ( short x = 10; x < width - 10; x++ )
    {
        for ( short y = 10; y < height - 10; y++ )
        {
            data.m_points.emplace_back(
                static_cast< float >( x ),
                static_cast< float >( y ),                                          // y
                static_cast< float >( rand() ) / RAND_MAX,                          // z
                y,                                                                  // row
                x );                                                                // col
        }
    }

    // SIMULATION CODE END

    return data;
}

// =================================================================================================
//   Initializes the connection.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::Connect()
{
    // Is already connected, no error
    if ( IsConnected() )
    {
        return true;
    }

    m_isConnected = true;

    // TODO: Connection with the device
    //m_isConnected = SDK_Connect( ... );

    return m_isConnected;
}

// =================================================================================================
//   Terminates the connection.
//
// Parameter : notifyHost_ : true to notify the host
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::Disconnect( bool notifyHost_ )
{
    bool isOK = true;

    // TODO: Disconnect from the device
    //isOK = SDK_Disconnect( ... );

    m_isConnected = false;

    // Notify the host that we are disconnecting
    if ( notifyHost_ && g_cookieScannerFeedback != 0 )
    {
        CComPtr< IIMScannerFeedback > pScannerFeedback;
        GITGetInterfaceFromGlobal( g_cookieScannerFeedback, IID_IIMScannerFeedback, ( void** ) &pScannerFeedback );
        if ( pScannerFeedback != nullptr )
        {
            pScannerFeedback->ScanningConnectionEnd();
        }
    }

    return isOK;
}

// =================================================================================================
//   Stop scanning.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::ScanningEnd()
{
    bool isOK = true;

    // TODO: Send command to end scanning if required

    SetEvent( m_hScanEndEvent );

    return isOK;
}

// =================================================================================================
//   Start scanning.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::ScanningStart()
{
    bool isOK = true;

    // TODO: Send command to start scanning

    SetEvent( m_hScanStartEvent );

    return isOK;
}

// =================================================================================================
//   Communication Thread.
//
// Parameter: pCompanyNameSDKStub_ : Communication stub instance pointer
//
// Return : 1 if successful, 0 otherwise
// -------------------------------------------------------------------------------------------------
unsigned int __stdcall CCompanyNameSDKStub::CommunicationThreadProc( void* pCompanyNameSDKStub_ )
{
    auto* pCompanyNameSDKStub = static_cast< CCompanyNameSDKStub* >( pCompanyNameSDKStub_ );
    if ( pCompanyNameSDKStub == nullptr )
    {
        ASSERT( 0 );
        return 0;
    }

    // This is the main thread where all of the communication is done
    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );
    {   // Begin scope for the COM message filter
        CRAIIComMessageFilter messageFilter;

        // wait until the Initial Suspension is off
        pCompanyNameSDKStub->m_communicationThread.WaitUntilSuspendOff();

        HANDLE handles[] = { pCompanyNameSDKStub->m_hScanEndEvent,
                             pCompanyNameSDKStub->m_hScanStartEvent };
        // Main loop.
        while ( pCompanyNameSDKStub->m_communicationThread.IsEnableControl() )
        {
            pCompanyNameSDKStub->m_communicationThread.MainThreadRelease();

            DWORD   handleIndex = 0;
            HRESULT res         = CoWaitForMultipleHandles( COWAIT_DEFAULT, 10, _countof( handles ), handles, &handleIndex );

            if ( res == S_OK )
            {
                switch ( handleIndex )
                {
                    case 0: // Scan End

                        pCompanyNameSDKStub->m_receiver.OnScanEnd();

                        break;

                    case 1: // Scan Start

                    {
                        SScanData data = pCompanyNameSDKStub->AcquiredDataGet();
                        pCompanyNameSDKStub->m_receiver.OnDataAcquired( data );
                    }

                    break;

                    default:
                        ASSERT( 0 );
                        break;
                }
            }
            else if ( res != RPC_S_CALLPENDING )
            {
                ASSERT( 0 );
            }
        } // MAIN loop.

    }   // End scope for the COM message filter
    CoUninitialize();

    return 0;
}
