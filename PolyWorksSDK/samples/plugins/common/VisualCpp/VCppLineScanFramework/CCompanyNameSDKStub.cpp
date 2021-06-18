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

#include "CComMessageFilter.h"
#include "CCompanyNameScannerReceiver.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

#define NB_POINTS   100     // TODO: Remove. Used for the simulator
#define NB_LINES    50      // TODO: Remove. Used for the simulator
#define POINT_DELAY 50      // TODO: Remove. Used for the simulator
#define POINT_STEP  1       // TODO: Remove. Used for the simulator
#define LINE_STEP   1       // TODO: Remove. Used for the simulator
#define EDGE        85      // TODO: Remove. Used for the simulator

enum EDataCode
{
    E_SDK_NOOP,
    E_SDK_CONNECT,
    E_SDK_SCAN_START,
    E_SDK_ACQUISITION_START,
    E_SDK_PASS_START,
    E_SDK_SCAN_LINE_INFO,
    E_SDK_SCAN_LINE_DATA,
    E_SDK_PASS_STOP,
    E_SDK_ACQUISITION_STOP,
    E_SDK_SCAN_STOP,
    E_SDK_DISCONNECT,
    E_SDK_CURSOR_SCAN_LINE_INFO,
    E_SDK_CURSOR_SCAN_LINE_DATA,
};

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

struct SScanLineInfo
{
    char  sensor_id[ 256 ];
    int   acquisition_number;
    int   num_xyzs;
    int   Status;
    int   logical_machine;
    float machine_X;
    float machine_Y;
    float machine_Z;
    float machine_Roll;   // Gives the digitizing direction (to compute the digitizing vector).
    float machine_Pitch;  // Could be replaced by ijk direction for simplification.
    float machine_Yaw;    //

    SScanLineInfo()
    : acquisition_number( 0 )
    , num_xyzs( 0 )
    , Status( 0 )
    , logical_machine( 0 )
    , machine_X( 0.0 )
    , machine_Y( 0.0 )
    , machine_Z( 0.0 )
    , machine_Roll( 0.0 )   // Gives the digitizing direction (to compute the digitizing vector).
    , machine_Pitch( 0.0 )  // Could be replaced by ijk direction for simplification.
    , machine_Yaw( -45.0 )  //
    {
        memset( sensor_id, 0, 256 * sizeof( char ) );
    }
};

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   Communication Thread.
//
// Parameter: pCompanyNameSDKStub_ : Communication stub instance pointer
//
// Return : 1 if successful, 0 otherwise
// -------------------------------------------------------------------------------------------------
unsigned __stdcall CommunicationThreadProc( void* pCompanyNameSDKStub_ )
{
    auto* pCompanyNameSDKStub = static_cast< CCompanyNameSDKStub* >( pCompanyNameSDKStub_ );
    if ( pCompanyNameSDKStub == nullptr )
    {
        ASSERT( 0 );
        return 0;
    }

    unsigned isOK = 0;

    // This is the main thread where all of the communication is done
    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );
    {
        CRAIIComMessageFilter messageFilter;

        isOK = pCompanyNameSDKStub->ThreadRun() ? 1 : 0;
    }
    CoUninitialize();

    return isOK;
}

// =================================================================================================
//   Ctor.
// -------------------------------------------------------------------------------------------------
CCompanyNameSDKStub::CCompanyNameSDKStub( CCompanyNameScannerReceiver* pReceiver_ /*= nullptr*/ )
: m_pReceiver( pReceiver_ )
, m_isConnected( false )
, m_isPassStarted( false )
, m_nPoints( 0 )    // TODO: Remove. Used for the simulator
, m_nLines( 0 )     // TODO: Remove. Used for the simulator
, m_xPos( 0.0 )     // TODO: Remove. Used for the simulator
, m_yPos( 0.0 )     // TODO: Remove. Used for the simulator
, m_zPos( 0.0 )     // TODO: Remove. Used for the simulator
{
    if ( pReceiver_ == nullptr )
    {
        ASSERT( 0 );
        return;
    }
}

// =================================================================================================
//   Dtor.
// -------------------------------------------------------------------------------------------------
CCompanyNameSDKStub::~CCompanyNameSDKStub()
{
    m_communicationThread.ThreadKill();

    Disconnect( false );
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
//   Stop receiving.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::ReceiveEnd()
{
    return m_communicationThread.ThreadKill();
}


// =================================================================================================
//   Start receiving.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::ReceiveStart()
{
    bool isOK = m_communicationThread.ThreadLaunch( CommunicationThreadProc, this );

    isOK = m_communicationThread.ThreadResume() && isOK;

    return isOK;
}


// =================================================================================================
//   Stop scanning.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::ScanningEnd()
{
    // TODO: Remove. Used for the simulator
    //================= Remove Begin ======================
    m_nLines = NB_LINES;
    //================= Remove End ======================

    bool isOK = true;

    // TODO: Send command to end scanning

    m_isPassStarted = false;

    return isOK;
}


// =================================================================================================
//   Start scanning.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::ScanningStart()
{
    // TODO: Remove. Used for the simulator
    //================= Remove Begin ======================
    m_nPoints = 0;
    m_nLines  = 0;
    m_xPos    = 1000.0;
    m_yPos    = 0.0;
    m_zPos    = 0.0;
    //================= Remove End ======================

    bool isOK = true;

    // TODO: Send command to start scanning

    return isOK;
}

// =================================================================================================
//   Communication Thread.
//
// Parameter: pCompanyNameSDKStub_ : Communication stub instance pointer
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameSDKStub::ThreadRun()
{
    if ( m_pReceiver == nullptr )
    {
        ASSERT( 0 );
        return false;
    }

    // wait until the Initial Suspension is off
    m_communicationThread.WaitUntilSuspendOff();

    SScanLineInfo line;
    SScanLineData scanLineData;

    char szScanData[ 24000 ];
    int  nData = E_SDK_NOOP;

    // Main loop.
    bool isOK = true;
    bool loop = true;
    while ( m_communicationThread.IsEnableControl() &&
            isOK && loop )
    {
        m_communicationThread.MainThreadRelease();

        long nNumberRead = 0;

        // TODO: Read from the device
        //isOK = SDK_Read( ... )

        // TODO: Remove. Used for the simulator
        //================= Remove Begin ======================
        if ( m_nLines < NB_LINES )
        {
            if ( m_isPassStarted )
            {
                if ( m_nPoints < NB_POINTS )
                {
                    // Skip points in the hole
                    if ( m_nPoints < 3 * NB_POINTS / 8 ||
                         m_nPoints > 5 * NB_POINTS / 8 ||
                         m_nLines  < 3 * NB_LINES  / 8 ||
                         m_nLines  > 5 * NB_LINES  / 8 )
                    {
                        PointF point( m_xPos + float( float( rand() ) / RAND_MAX * POINT_STEP / 10 ),
                                      m_yPos + float( float( rand() ) / RAND_MAX * POINT_STEP / 10 ),
                                      m_zPos + float( float( rand() ) / RAND_MAX * POINT_STEP / 10 ) );
                        scanLineData.m_pointsBuffer.push_back( point );
                    }

                    m_nPoints++;
                    if ( m_nPoints < EDGE )
                    {
                        m_yPos += POINT_STEP;
                    }
                    else
                    {
                        m_xPos += POINT_STEP;
                    }

                    continue;
                }
                else
                {
                    m_nLines++;
                    m_zPos += LINE_STEP;

                    m_nPoints = 0;
                    m_xPos    = 1000.0;
                    m_yPos    = 0.0;
                }

                nData = E_SDK_SCAN_LINE_DATA;
            }
            else
            {
                Sleep( 500 );

                if ( m_nLines == 0 )
                {
                    nData = E_SDK_PASS_START;
                }
            }
        }
        else if ( m_isPassStarted )
        {
            nData = E_SDK_PASS_STOP;
        }
        else
        {
            nData = E_SDK_NOOP;
        }
        //================= Remove End ======================

        switch ( nData )
        {
            case E_SDK_NOOP:
                break;

            case E_SDK_CONNECT:
                // TODO: Get device info for example

                m_pReceiver->ConnectionStateUpdate( true );

                break;

            case E_SDK_DISCONNECT:
                // TODO: Cleanup connection with the device

                m_pReceiver->ConnectionStateUpdate( false );

                loop = false;
                break;

            case E_SDK_ACQUISITION_START:
                // TODO: Communicate with the device if required

                m_pReceiver->DoAcquisitionStart();

                break;

            case E_SDK_ACQUISITION_STOP:
                // TODO: Communicate with the device if required

                m_pReceiver->DoAcquisitionEnd();

                break;

            case E_SDK_PASS_START:
                // TODO: Communicate with the device if required

                if ( m_pReceiver->DoPassStart() )
                {
                    m_isPassStarted = true;
                }

                break;

            case E_SDK_PASS_STOP:
                // TODO: Communicate with the device if required

                if ( m_pReceiver->DoPassEnd() )
                {
                    m_isPassStarted = false;
                }

                break;

            case E_SDK_SCAN_LINE_INFO:

                // TODO: Read device line info

                break;

            case E_SDK_CURSOR_SCAN_LINE_INFO:

                // TODO: Read device line info

                break;

            case E_SDK_SCAN_LINE_DATA:
            {
                EnterCriticalSection( &( m_pReceiver->m_DataWrite ) );

                // TODO: Read data from the device

                scanLineData.m_nbBytesRead = static_cast< long >( scanLineData.m_pointsBuffer.size() ) * SIZE_OF_POINT;
                scanLineData.m_Roll        = line.machine_Roll;
                scanLineData.m_Pitch       = line.machine_Pitch;
                scanLineData.m_Yaw         = line.machine_Yaw;

                m_pReceiver->m_Data.push_back( scanLineData );

                bool isOK = true;
                // TODO: Check for errors, and if an error is found, set isOK to false

                if ( isOK )
                {
                    m_pReceiver->m_Data.back().m_Roll  = line.machine_Roll;
                    m_pReceiver->m_Data.back().m_Pitch = line.machine_Pitch;
                    m_pReceiver->m_Data.back().m_Yaw   = line.machine_Yaw;

                    m_pReceiver->m_newRecordData = true;
                }
                else
                {
                    m_pReceiver->m_Data.resize( m_pReceiver->m_Data.size() - scanLineData.m_pointsBuffer.size() );
                }

                scanLineData.m_pointsBuffer.clear();

                LeaveCriticalSection( &( m_pReceiver->m_DataWrite ) );
            }
            break;

            case E_SDK_CURSOR_SCAN_LINE_DATA:
                // TODO: Read cursor data from the device

                m_pReceiver->CursorSend(
                    ( PointF* ) szScanData,
                    nNumberRead / SIZE_OF_POINT,
                    line.machine_Roll,
                    line.machine_Pitch,
                    line.machine_Yaw );

                break;

            default:
                ASSERT( 0 );
                break;
        }

        ::Sleep( 10 ); // Let other threads run
    }                  // MAIN loop.

    return true;
}
