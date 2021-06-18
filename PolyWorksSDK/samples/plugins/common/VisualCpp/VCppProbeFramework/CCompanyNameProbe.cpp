// =================================================================================================
//   Plug-in implementation
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include "stdafx.h"

#include "CCompanyNameProbe.h"

#include <PolyWorksSDK/COM/IIMCommandCenter.h>
#include <PolyWorksSDK/COM/IIMCommandCenter_i.c>
#include <PolyWorksSDK/COM/IIMInputEventsReceiver.h>
#include <PolyWorksSDK/COM/IIMInputEventsReceiver_i.c>
#include <PolyWorksSDK/COM/IIMMessageCenter.h>
#include <PolyWorksSDK/COM/IIMMessageCenter_i.c>
#include <PolyWorksSDK/COM/IIMPointCloud.h>
#include <PolyWorksSDK/COM/IIMPointCloud_i.c>
#include <PolyWorksSDK/COM/IIMProbeFeedback.h>
#include <PolyWorksSDK/COM/IIMProbeFeedback_i.c>
#include <PolyWorksSDK/COM/IIMSoundCenter.h>
#include <PolyWorksSDK/COM/IIMSoundCenter_i.c>
#include <assert.h>
#include <comutil.h>
#include <limits.h>
#include <time.h>

#include "CComMessageFilter.h"
#include "CCompanyNameProbeSettings.h"
#include "CCompanyNameSDKStub.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

#ifndef E_BUSY
#define E_BUSY              _HRESULT_TYPEDEF_( 0x800700AAL )
#endif // #ifndef E_BUSY

static const DWORD BUSY_TIMEOUT = 100;

// Pre-allocated memory size for probed data
static const int PROBED_DATA_VECTOR_RESERVED_SIZE = 512;

// TODO: Identify the probing modes
static wchar_t* _RecordModeNames[ E_NB_USER_MODES ] =
{
    L"Single",
    L"Continuous Time",
    L"Continuous Distance"
};

EProbingModeTypes _RecordModeTypes[ E_NB_USER_MODES ] =
{
    E_PROBING_MODE_TYPE_SINGLE,
    E_PROBING_MODE_TYPE_CONTINUOUS_TIME,
    E_PROBING_MODE_TYPE_CONTINUOUS_DISTANCE
};

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

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
long GetExpireTime( long duration )    // duration in msec
{
    double clock_time = ( double ) clock() * ( 1000.0 / ( double ) CLOCKS_PER_SEC );
    return duration + ( long ) clock_time;
}

// =================================================================================================
//   Check if the time stamp has been reached
//
// Parameter: expire_time : time stamp
//
// Return: true if expired, false otherwise
// -------------------------------------------------------------------------------------------------
bool HasTimeExpired( long expire_time )
{
    double clock_time = ( double ) clock() * ( 1000.0 / ( double ) CLOCKS_PER_SEC );
    return ( clock_time - expire_time ) >= 0;
}

// =================================================================================================
//   See IGlobalInterfaceTable::GetInterfaceFromGlobal
// -------------------------------------------------------------------------------------------------
HRESULT GITGetInterfaceFromGlobal( DWORD dwCookie_, REFIID riid_, void** ppv_ )
{
    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** ) &pGIT );

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
HRESULT GITRegisterInterfaceInGlobal( IUnknown* pUnk_, REFIID riid_, DWORD* pdwCookie_ )
{
    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** ) &pGIT );

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
HRESULT GITRevokeInterfaceFromGlobal( DWORD& dwCookie_, UINT retriesWhenBusy_ /* = 0 */ )
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
        ( void** ) &pGIT );

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


// =================================================================================================
//   Return the singleton
//
// Return: The plug-in singleton
// -------------------------------------------------------------------------------------------------
CCompanyNameProbe& theCompanyNameProbe()
{
    static CCompanyNameProbe _probe;
    return _probe;
}

// =================================================================================================
//   Constructor
// -------------------------------------------------------------------------------------------------
CCompanyNameProbe::CCompanyNameProbe()
: m_aborting( false )
, m_currentMode( E_FIRST_USER_MODE )
, m_ProbingIsPaused( false )
, m_hAppCommunicationThreadEventOnOff( nullptr )
, m_hAppCommunicationThreadEventSuspended( nullptr )
, m_hAppCommunicationThreadEventResumed( nullptr )
, m_hAppCommunicationThread( nullptr )
, m_appCommunicationThreadState( E_THREAD_OFF )
, m_hAppCommunicationThreadEventStopped( nullptr )
, m_cookieCommandCenter( 0 )
, m_cookieFeedback( 0 )
, m_cookieHost( 0 )
, m_cookieInputEventsReceiver( 0 )
, m_cookiePtCloud( 0 )
, m_isRevokingInputEventsReceiver( false )
, m_lastRecordedPointDelay( 1 )
, m_lastRecordedPointDistance( 0.0 )
, m_lastProbedPointTimeForNextUpdate( 0 )
, m_hasRecordedFirstContinuousPoint( false )
, m_probeDiameter( -1.0 )
, m_status( EDeviceStatus::E_DEVICE_STATUS_NOT_READY )
, m_dataAddToOne( true )
, m_probePositionNew( false )
{
    InitializeCriticalSection( &m_dataRead );
    InitializeCriticalSection( &m_dataWrite );
    InitializeCriticalSection( &m_probePositionGuard );

    m_pDeviceSDKStub.reset( new CCompanyNameSDKStub( this ) );
}

// =================================================================================================
//   Destructor
// -------------------------------------------------------------------------------------------------
CCompanyNameProbe::~CCompanyNameProbe()
{
    m_pDeviceSDKStub.reset( nullptr );

    DeleteCriticalSection( &m_dataRead );
    DeleteCriticalSection( &m_dataWrite );
    DeleteCriticalSection( &m_probePositionGuard );
}

// =================================================================================================
//   Determine if next point can be recorded in continuous time
//
// Return: true if can record the next point
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::CanRecordNextPointTime()
{
    // Always accept the first point if it has not been recorded yet
    if ( !m_hasRecordedFirstContinuousPoint )
    {
        m_hasRecordedFirstContinuousPoint = true;
        return true;
    }

    return HasTimeExpired( m_lastProbedPointTimeForNextUpdate );
}

// =================================================================================================
//   Determine if next point can be recorded in continuous distance
//
// Parameter: position_ : Position coordinate
//
// Return: true if can record the next point
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::CanRecordNextPointDistance( const SProbePosition& position_ )
{
    // Always accept the first point if it has not been recorded yet
    if ( !m_hasRecordedFirstContinuousPoint )
    {
        m_hasRecordedFirstContinuousPoint = true;
        return true;
    }

    SProbePosition lastProbedPosition;
    ProbedPointGetLast( lastProbedPosition );

    double distanceBetweenPoints = 0;

    // TODO: Compute the distance between position_ and lastProbedPosition
    //       and put the value in distanceBetweenPoints

    return distanceBetweenPoints >= m_lastRecordedPointDistance;
}

// =================================================================================================
//   Enable or disable the continuous mode in the application
//
// Parameter: enable_ : true to enable, false otherwise
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::ContinuousModeEnabled( bool enable_ )
{
    CComPtr< IIMProbeFeedback2 > pIIMProbeFeedback2;
    GITGetInterfaceFromGlobal(
        m_cookieFeedback,
        IID_IIMProbeFeedback2,
        ( void** ) &pIIMProbeFeedback2 );
    if ( pIIMProbeFeedback2 != nullptr )
    {
        pIIMProbeFeedback2->ContinuousModeEnabled( enable_ ? VARIANT_TRUE : VARIANT_FALSE );
    }
}

// =================================================================================================
//   Called by the application when the user ends the connection with the plug-in.
//
// Return: true if successfully disconnected, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::EndConnection()
{
    // Stop everything
    ProbingEnd( false );

    ThreadsKill();

    GITRevokeInterfaceFromGlobal( m_cookieFeedback );

    // TODO: Disconnect from device here
    bool retVal = m_pDeviceSDKStub->Disconnect();

    // Put retval to true to indicate that we should be disconnecting now

    return retVal;
}

// =================================================================================================
//   Send a MSCL command to be executed by the application
//
// Parameter: command_ : MSCL command
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ExecuteCommandOnApp( const wchar_t* command_ )
{
    bool success = false;

    CComPtr< IIMCommandCenter > pCommandCenter;
    if ( ( m_cookieCommandCenter != 0 ) &&
         ( GITGetInterfaceFromGlobal( m_cookieCommandCenter, IID_IIMCommandCenter, ( void** ) &pCommandCenter ) == S_OK ) &&
         ( pCommandCenter != nullptr ) )
    {
        long retVal    = 0;
        long isSuccess = 0;

        // Execute the command
        if ( ( pCommandCenter->CommandExecute( command_, &retVal ) == S_OK ) &&
             ( pCommandCenter->ReturnValueIsSuccess( retVal, &isSuccess ) == S_OK ) &&
             ( isSuccess == 1 ) )
        {
            success = true;
        }
    }

    return success;
}

// =================================================================================================
//   Called by the application when the user initiate the connection with the plug-in.
//
// Parameter: pFeedback_ : Pointer to the IIMProbeFeedback interface
//
// Return: true if successfully connected, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::InitConnection( IIMProbeFeedback* pFeedback_ )
{
    // TODO: Uncomment the lines below if necessary.
    //       In order to avoid conflict while accessing hardware or software resources that might be used by
    //       another non-probing plug-in (probing plug-ins are already exclusive), it is recommended to send commands
    //       (if any exist) via the IIMCommandCenter interface in order to close and disconnect any existing plug-in that
    //       might use the same resources before attempting to connect to those resources in this plug-in.
    //       For example, if you have a probing plug-in that uses the same tracking system as an existing scanning plug-in,
    //       then you might want to call any related "DIGITIZE DEVICE CONNECT( "Off" )"
    //       command as one of the very first steps in this IIMProbe::InitConnection method.
    //
    //// If the plug-in CompanyNameScanner is present, make sure it is not connected
    // ExecuteCommandOnApp( L"DIGITIZE DEVICE CONNECT( \"Off\" )" );


    // TODO: Connect and initialize the device here
    //       Use IsError if needed
    //       Return false if there's any problem
    if ( !m_pDeviceSDKStub->Connect() )
    {
        return false;
    }

    // TODO: Obtain the current value of the probe's diameter from your device or SDK, and assign this value to m_probeDiameter
    // const double yourProbeDiameterValue;
    // UpdateProbeDiameter( yourProbeDiameterValue );

    // TODO: Obtain the current value of the device's status from your device or SDK, and assign this value to m_status
    // const double yourStatusValue;
    // m_status = yourStatusValue;
    // UpdateDeviceStatus( yourStatusValue );

    if ( pFeedback_ != nullptr )
    {
        GITRegisterInterfaceInGlobal( pFeedback_, IID_IIMProbeFeedback, &m_cookieFeedback );
    }

    // Start the threads to begin sending real-time positions to the host application
    return ThreadsStart();
}

// =================================================================================================
//   Return continuous mode state
//
// Return: true if mode is continuous, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::IsCurrentModeContinuous()
{
    bool modeIsContinuous = false;
    // TODO: Set modeIsContinuous to true when the mode is a continuous mode
    if ( ( m_currentMode == E_CONTINUOUS_TIME_MODE ) ||
         ( m_currentMode == E_CONTINUOUS_DISTANCE_MODE ) )
    {
        modeIsContinuous = true;
    }
    return modeIsContinuous;
}

// =================================================================================================
//   Verify is there is an error and give feedback to the user
//
// Parameter: error_ : TRUE for error, FALSE otherwise
//
// Return: true if error, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::IsError( BOOL error_ )
{
    if ( error_ == FALSE )
    {
        // Temporary problem
        if ( false /* TODO: Replace false by a check for temporary 'Over limit' state
                      (or any temporary state that can jeopardize the precision of the data) here */)
        {
            // Play a sound or use any other nonblocking feedback
            CComPtr< IIMSoundCenter > pSoundCenter;
            if ( ( GITGetInterfaceFromGlobal(
                       m_cookieHost,
                       IID_IIMSoundCenter,
                       ( void** )&pSoundCenter ) == S_OK ) &&
                 ( pSoundCenter != nullptr ) )
            {
                // TODO: Change the sound name if necessary
                pSoundCenter->Play( _bstr_t( L"Error" ) );
            }
        }
        else  // Otherwise, display a message
        {
            // TODO: Change 'Message' for more accurate information
            std::wstring errorMessage = L"Message";
            CComPtr< IIMMessageCenter > pMessageCenter;
            if ( ( GITGetInterfaceFromGlobal(
                       m_cookieHost,
                       IID_IIMMessageCenter,
                       ( void** )&pMessageCenter ) == S_OK ) &&
                 ( pMessageCenter != nullptr ) )
            {
                // TODO: Change the message type if necessary
                pMessageCenter->MessageBox( E_MESSAGE_TYPE_ERROR, _bstr_t( errorMessage.c_str() ) );
            }
        }

        return true;
    }

    return false;
}

// =================================================================================================
//   Return the mode name
//
// Parameter: mode_ : mode ID
//
// Return: mode name
// -------------------------------------------------------------------------------------------------
LPWSTR CCompanyNameProbe::ModeNameGet( ERecordModes mode_ )
{
    if ( mode_ < E_FIRST_USER_MODE )
    {
        mode_ = ( ERecordModes ) E_FIRST_USER_MODE;
    }
    if ( mode_ > E_LAST_USER_MODE )
    {
        mode_ = E_LAST_USER_MODE;
    }
    return _RecordModeNames[ ( short ) mode_ ];
}

// =================================================================================================
//   Set the current mode
//
// Parameter: mode_ : mode ID
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::ModeSet( ERecordModes mode_ )
{
    m_currentMode = mode_;
}

// =================================================================================================
//   Return the mode type
//
// Parameter: mode_ : Mode ID
//
// Return: Mode type
// -------------------------------------------------------------------------------------------------
EProbingModeTypes CCompanyNameProbe::ModeTypeGet( ERecordModes mode_ )
{
    if ( mode_ < E_FIRST_USER_MODE )
    {
        mode_ = ( ERecordModes ) E_FIRST_USER_MODE;
    }
    if ( mode_ > E_LAST_USER_MODE )
    {
        mode_ = E_LAST_USER_MODE;
    }
    return _RecordModeTypes[ ( short ) mode_ ];
}

// =================================================================================================
//   Format and sends new points to the application
//
// Paramter : nbPtsSent_ : Number of points sent
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ProbedDataSend( long& nbPtsSent_ )
{
    bool       result      = false;
    long       nbPtsToSend = 0;
    SAFEARRAY* pCoords     = nullptr;
    SAFEARRAY* pVector     = nullptr;

    // Protection between ThreadProcWorker and a concurrent call to ProbingEnd
    {
        EnterCriticalSection( &m_dataRead );
        std::vector< SProbePosition >& data = m_dataAddToOne ? m_dataOne : m_dataTwo;

        // Change the container to use for new recordings
        // can continue to record data while we run the code below.
        ProbedDataSwitchContainer();

        // Prepare points to send
        ULONG dataSize = static_cast< ULONG >( data.size() );
        if ( dataSize > 0 )
        {
            pCoords = SafeArrayCreateVector( VT_R4, 0, 3 * dataSize );
            pVector = SafeArrayCreateVector( VT_R4, 0, 3 * dataSize );
            std::vector< SProbePosition >::iterator itDataCurrent = data.begin();
            std::vector< SProbePosition >::iterator itDataEnd     = data.end();
            for ( ; itDataCurrent != itDataEnd; ++itDataCurrent )
            {
                // Position.
                long  index = nbPtsToSend * 3;
                float value = ( float )( itDataCurrent->dX );
                SafeArrayPutElement( pCoords, &index, &value );
                ++index;
                value = ( float )( itDataCurrent->dY );
                SafeArrayPutElement( pCoords, &index, &value );
                ++index;
                value = ( float )( itDataCurrent->dZ );
                SafeArrayPutElement( pCoords, &index, &value );

                // Direction, from the tip toward the base of the probe.
                index = nbPtsToSend * 3;
                value = ( float )( itDataCurrent->dZI );
                SafeArrayPutElement( pVector, &index, &value );
                ++index;
                value = ( float )( itDataCurrent->dZJ );
                SafeArrayPutElement( pVector, &index, &value );
                ++index;
                value = ( float )( itDataCurrent->dZK );
                SafeArrayPutElement( pVector, &index, &value );

                ++nbPtsToSend;
            }
            data.clear();
        }

        LeaveCriticalSection( &m_dataRead );
    }

    // Transfert new points.
    if ( nbPtsToSend > 0 )
    {
        CComPtr< IIMPointCloud > pIIMPointCloud;
        GITGetInterfaceFromGlobal( m_cookiePtCloud, IID_IIMPointCloud, ( void** ) &pIIMPointCloud );
        if ( pIIMPointCloud != nullptr )
        {
            if ( pIIMPointCloud->PointsAdd( &pCoords, &pVector, nullptr ) == S_OK )
            {
                result     = true;
                nbPtsSent_ = nbPtsToSend;
            }
        }
    }
    else
    {
        result = true;
    }

    // Clean-up.
    if ( pCoords != nullptr )
    {
        SafeArrayDestroy( pCoords );
    }
    if ( pVector != nullptr )
    {
        SafeArrayDestroy( pVector );
    }

    return result;
}

// =================================================================================================
//   Swap data containers
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::ProbedDataSwitchContainer()
{
    EnterCriticalSection( &m_dataWrite );
    m_dataAddToOne = !m_dataAddToOne;
    LeaveCriticalSection( &m_dataWrite );
}

// =================================================================================================
//   Sending points to the application
//
// Parameter: pDelay_ : time to wait before entering in the function again
//
// Return: true if at least one point has been sent, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ProbedPointSend( long* pDelay_ )
{
    long nbPtsSent = 0;
    ProbedDataSend( nbPtsSent );

    // Wait for 50 ms before coming through this method again in continuous mode.
    // This will allow for better performances by sending batches of points to the host application,
    // thus minimizing the overhead cost of each COM call.
    long delay = 0;
    if ( IsCurrentModeContinuous() )
    {
        delay = 50;
    }

    if ( pDelay_ != nullptr )
    {
        *pDelay_ = delay;
    }

    return nbPtsSent != 0;
}

// =================================================================================================
//   Updates the last probed point information
//
// Parameter: probedPosition_ : position and direction of the probe
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ProbedPointSetLast( const SProbePosition& probedPosition_ )
{
    EnterCriticalSection( &m_probePositionGuard );
    m_lastRecordedPoint = probedPosition_;
    LeaveCriticalSection( &m_probePositionGuard );
    return true;
}

// =================================================================================================
//   Gets the current position and direction of the probe
//
// Parameter: probePosition_ : position and direction of the probe
//
// Return: true if a new position since the last function call, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ProbePositionAndDirectionGet( SProbePosition& probePosition_ )
{
    EnterCriticalSection( &m_probePositionGuard );

    probePosition_ = m_probePosition;
    bool probePositionWasNew = m_probePositionNew;
    m_probePositionNew = false;

    LeaveCriticalSection( &m_probePositionGuard );

    return probePositionWasNew;
}

// =================================================================================================
//   Sets the current position and direction of the probe
//
// Parameter: probePosition_ : Current position and direction of the probe
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::ProbePositionAndDirectionSet( const SProbePosition& probePosition_ )
{
    EnterCriticalSection( &m_probePositionGuard );
    m_probePosition    = probePosition_;
    m_probePositionNew = true;
    LeaveCriticalSection( &m_probePositionGuard );
}

// =================================================================================================
//   Sends the current position and direction of the probe to the application
//
// Return: Time to wait before entering in the function again
// -------------------------------------------------------------------------------------------------
long CCompanyNameProbe::ProbePositionAndDirectionSend()
{
    // Next update will be in 50 ms
    const long suggestedDelay = 50;

    // Get a working copy of the last known position
    SProbePosition probePosition;
    if ( ProbePositionAndDirectionGet( probePosition ) )
    {
        // Try first with IIMProbeFeedback2.
        CComPtr< IIMProbeFeedback2 > pIIMProbeFeedback2;
        GITGetInterfaceFromGlobal(
            m_cookieFeedback,
            IID_IIMProbeFeedback2,
            ( void** ) &pIIMProbeFeedback2 );
        if ( pIIMProbeFeedback2 != nullptr )
        {
            pIIMProbeFeedback2->CurrentProbePositionAndDirectionSet(
                probePosition.dX,
                probePosition.dY,
                probePosition.dZ,
                probePosition.dZI,
                probePosition.dZJ,
                probePosition.dZK );
        }
        else
        {
            // Otherwise try with IIMProbeFeedback.
            CComPtr< IIMProbeFeedback > pIIMProbeFeedback;
            GITGetInterfaceFromGlobal(
                m_cookieFeedback,
                IID_IIMProbeFeedback,
                ( void** ) &pIIMProbeFeedback );
            if ( pIIMProbeFeedback != nullptr )
            {
                pIIMProbeFeedback->CurrentProbePositionSet(
                    probePosition.dX,
                    probePosition.dY,
                    probePosition.dZ );
            }
        }
    }

    return suggestedDelay;
}

// =================================================================================================
//   Returns the last probed point
//
// Parameter: probedPosition_ : Last probed point
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::ProbedPointGetLast( SProbePosition& probedPosition_ )
{
    EnterCriticalSection( &m_probePositionGuard );
    probedPosition_ = m_lastRecordedPoint;
    LeaveCriticalSection( &m_probePositionGuard );
}

// =================================================================================================
//   Add the probed point to the plug-in container
//
// Parameter: probedPosition_ : Probed point
// Parameter: fromProbingEnd_ : Is function called from ProbingEnd
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ProbedPointRecord(
    const SProbePosition& probedPosition_,
    bool                  fromProbingEnd_ )
{
    // If ProbeEnd() if already executing, point will not be added since probing is already ending.
    if ( !fromProbingEnd_ && m_aborting )
    {
        return false;
    }

    // Synchronization between ThreadProcWorker and the main thread.
    EnterCriticalSection( &m_dataWrite );

    if ( m_dataAddToOne )
    {
        m_dataOne.push_back( probedPosition_ );
    }
    else
    {
        m_dataTwo.push_back( probedPosition_ );
    }

    LeaveCriticalSection( &m_dataWrite );

    return true;
}

// =================================================================================================
//   Ends the probing
//
// Parameter: probeLastPoint_ : Probe a last point as compensation point
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ProbingEnd( bool probeLastPoint_ )
{
    if ( m_aborting )
    {
        return false;
    }

    m_aborting = true;

    AppCommunicationThreadKill();

    // Flush any remaining points
    ProbedPointSend( nullptr );

    bool completeProbingEnd = true;
    if ( probeLastPoint_ )
    {
        // Send the last point in non-continuous mode.
        ContinuousModeEnabled( false );

        // Record and send last point.
        SProbePosition probePosition;
        ProbePositionAndDirectionGet( probePosition );
        ProbedPointRecord( probePosition, true );

        completeProbingEnd = ProbedPointSend( nullptr );

        // Reset the current mode type
        ContinuousModeEnabled( IsCurrentModeContinuous() );
    }

    // Completes the end of probing
    if ( completeProbingEnd )
    {
        // Final update of the position and direction of the probe
        ProbePositionAndDirectionSend();

        GITRevokeInterfaceFromGlobal( m_cookiePtCloud, 5 );

        ModeSet( E_FIRST_USER_MODE );

        // As probing is done, reset Remote Mouse usage based on configuration
        UseProbeAsMouseSet( theCompanyNameProbeSettings().UseProbeAsMouseGet() );
    }

    m_aborting = false;

    if ( AppCommunicationThreadLaunch() )
    {
        AppCommunicationThreadResume();
    }

    return completeProbingEnd;
}

// =================================================================================================
//   Start the probing
//
// Parameter: pCloud_ : Pointer to the point cloud
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ProbingStart( IIMPointCloud* pCloud_ )
{
    m_aborting = false;

    bool isConnected = true /* TODO: Replace true by a check to see if we're connected to the device here, Ex: IsDeviceConnected() */;
    if ( !isConnected )
    {
        if ( !InitConnection( nullptr ) )
        {
            return false;
        }
    }

    // Get ready to use the Continuous modes
    m_lastRecordedPointDelay           = theCompanyNameProbeSettings().ContinuousTimeDelayGet();
    m_lastRecordedPointDistance        = theCompanyNameProbeSettings().ContinuousDistanceDistGet() * theCompanyNameProbeSettings().HostUnitsScalingFactorGet();
    m_lastProbedPointTimeForNextUpdate = 0;
    m_lastRecordedPoint.dX             = 0;
    m_lastRecordedPoint.dY             = 0;
    m_lastRecordedPoint.dZ             = 0;
    m_lastRecordedPoint.dZI            = 0;
    m_lastRecordedPoint.dZJ            = 0;
    m_lastRecordedPoint.dZK            = 0;
    m_hasRecordedFirstContinuousPoint  = false;

    // TODO: Validate the probe, if needed
    //       Use IsError if needed

    // TODO: Wait until we're ready to acquire points

    // As probing is started, disable Remote Mouse usage
    UseProbeAsMouseSet( false );

    // Set the mode according to the settings
    ModeSet( theCompanyNameProbeSettings().ModeGet() );

    // Pre-allocate memory for probed data in order to optimize data recording speed
    m_dataOne.reserve( PROBED_DATA_VECTOR_RESERVED_SIZE );
    m_dataTwo.reserve( PROBED_DATA_VECTOR_RESERVED_SIZE );

    if ( pCloud_ != nullptr )
    {
        GITRegisterInterfaceInGlobal( pCloud_, IID_IIMPointCloud, &m_cookiePtCloud );
    }

    return true;
}

// =================================================================================================
//   Verify and configure the probing based on the current probe
//
// Parameter: bImmediateFlag : Verify immediately
// Parameter: mode           : Recording mode
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::SetupCurrentProbe( BOOL bImmediateFlag, ERecordModes mode )
{
    static long expire_time = 0;

    if ( bImmediateFlag || HasTimeExpired( expire_time ) )
    {
        switch ( mode )
        {
            case E_SINGLE_MODE:
            case E_CONTINUOUS_TIME_MODE:
            case E_CONTINUOUS_DISTANCE_MODE:
                // TODO: Validate the current probe and make sure the acquisition can
                //       be made correctly in this mode using that probe.
                //       Use IsError if needed
                break;
        }

        expire_time = GetExpireTime( ( long ) 1000 ); // do the guts every second at most
    }
}

// =================================================================================================
//   Kill all the threads
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::ThreadsKill()
{
    ModeSet( E_FIRST_USER_MODE );

    AppCommunicationThreadKill();
}

// =================================================================================================
//   Start all the threads
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::ThreadsStart()
{
    UseProbeAsMouseSet( theCompanyNameProbeSettings().UseProbeAsMouseGet() );

    // Launch the threads
    if ( !AppCommunicationThreadLaunch() )
    {
        return false;
    }

    AppCommunicationThreadResume();

    return true;
}

// =================================================================================================
//   Disable the transmission of input events to the application
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::TransmissionDisable()
{
    // Indicates that input events should not be transmitted anymore to the host application

    if ( ( m_cookieInputEventsReceiver != 0 ) &&
         !m_isRevokingInputEventsReceiver )
    {
        // Protect the access to the GIT for the input events,
        // in case the thread tries to use it before terminating.
        m_isRevokingInputEventsReceiver = true;

        GITRevokeInterfaceFromGlobal( m_cookieInputEventsReceiver, 5 );

        if ( m_cookiePtCloud == 0 )
        {
            // If probing is not started, reset Remote Mouse usage based on configuration
            UseProbeAsMouseSet( theCompanyNameProbeSettings().UseProbeAsMouseGet() );
        }

        m_isRevokingInputEventsReceiver = false;
    }
}

// =================================================================================================
//   Enable the transmission of input events to the application
//
// Parameter: pInputEventsReceiver_ : Pointer to the application events receiver
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::TransmissionEnable( IIMInputEventsReceiver* pInputEventsReceiver_ )
{
    // Indicates that input events should now be transmitted to the host application

    bool isConnected = true /* TODO: Replace true by a check to see if we're connected to the device here, Ex: IsDeviceConnected() */;
    if ( !isConnected )
    {
        // Input events can't be transmitted to the host application if we're not connected to the device
        return false;
    }

    if ( ( pInputEventsReceiver_ == nullptr ) ||  // Invalid receiver
         ( m_cookieInputEventsReceiver != 0 ) )   // Transmission already activated
    {
        return false;
    }

    GITRegisterInterfaceInGlobal( pInputEventsReceiver_, IID_IIMInputEventsReceiver, &m_cookieInputEventsReceiver );

    if ( m_cookieInputEventsReceiver == 0 )
    {
        return false;
    }

    if ( m_cookiePtCloud == 0 )
    {
        // If probing is not started, disable Remote Mouse usage
        UseProbeAsMouseSet( false );
    }

    return true;
}

// =================================================================================================
//   Sets the scaling factor
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::UnitsScalingFactorSet()
{
    // TODO: Change the device's units here

    // Keep track of the current distance value, in the new units
    m_lastRecordedPointDistance = theCompanyNameProbeSettings().ContinuousDistanceDistGet() * theCompanyNameProbeSettings().HostUnitsScalingFactorGet();
}

// =================================================================================================
//   Specifies whether the probing device is used as a mouse
//
// Parameter: useProbeAsMouse_ : true if probing device is used as a mouse
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::UseProbeAsMouseSet( bool useProbeAsMouse_ )
{
    // TODO: Change the Remote Mouse of the device here
}

// =================================================================================================
//   Thread that handle the communication with the application
//
// Parameter: pProbe_ : Pointer to the plug-in object
//
// Return: 0
// -------------------------------------------------------------------------------------------------
static unsigned __stdcall AppCommunicationThread( void* pProbe_ )
{
    CCompanyNameProbe* pProbe = static_cast< CCompanyNameProbe* >( pProbe_ );

    if ( pProbe == nullptr )
    {
        return 0;
    }

    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );
    {   // Begin scope for the COM message filter

        CRAIIComMessageFilter messageFilter;

        // Wait until the Initial Suspension is off
        ::WaitForSingleObject( pProbe->m_hAppCommunicationThreadEventOnOff, INFINITE );
        ::SetEvent( pProbe->m_hAppCommunicationThreadEventResumed );

        long  probePointSendTimeForNextUpdate            = 0;
        long  probePositionAndDirectionTimeForNextUpdate = 0;
        DWORD dummy;

        while ( pProbe->m_appCommunicationThreadState != E_THREAD_OFF )
        {
            if ( ::CoWaitForMultipleHandles( 0, 20, 1, &pProbe->m_hAppCommunicationThreadEventOnOff, &dummy ) == S_OK )
            {
                // Release main thread
                ::SetEvent( pProbe->m_hAppCommunicationThreadEventSuspended );
                ::WaitForSingleObject( pProbe->m_hAppCommunicationThreadEventOnOff, INFINITE );
                ::SetEvent( pProbe->m_hAppCommunicationThreadEventResumed );
            }

            // Transmit recorded points
            bool probedPointSent = false;
            if ( !pProbe->m_aborting &&
                 HasTimeExpired( probePointSendTimeForNextUpdate ) )
            {
                long delay = 0;
                probedPointSent                 = pProbe->ProbedPointSend( &delay );
                probePointSendTimeForNextUpdate = GetExpireTime( delay );
            }

            // Update position and direction
            if ( !pProbe->m_aborting )
            {
                if ( probedPointSent ||
                     HasTimeExpired( probePositionAndDirectionTimeForNextUpdate ) )
                {
                    long delay = pProbe->ProbePositionAndDirectionSend();
                    probePositionAndDirectionTimeForNextUpdate = GetExpireTime( delay );
                }
            }
        }
    }   // End scope for the COM message filter

    CoUninitialize();

    ::SetEvent( pProbe->m_hAppCommunicationThreadEventStopped );

    return 0;
}

// =================================================================================================
//   Kill the application communication thread
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::AppCommunicationThreadKill()
{
    if ( m_hAppCommunicationThread == nullptr )
    {
        return;
    }

    AppCommunicationThreadResume();
    m_appCommunicationThreadState = E_THREAD_OFF;

    // Keep processing COM messages while waiting for the thread to end
    DWORD handleIndex = 0;
    if ( ::CoWaitForMultipleHandles( 0, 5000, 1, &m_hAppCommunicationThreadEventStopped, &handleIndex ) != S_OK )
    {
        ::TerminateThread( m_hAppCommunicationThread, 0 );
    }

    ::CloseHandle( m_hAppCommunicationThreadEventOnOff );
    ::CloseHandle( m_hAppCommunicationThreadEventSuspended );
    ::CloseHandle( m_hAppCommunicationThreadEventResumed );
    ::CloseHandle( m_hAppCommunicationThread );
    ::CloseHandle( m_hAppCommunicationThreadEventStopped );
    m_hAppCommunicationThread = nullptr;
}

// =================================================================================================
//   Launch the application communication thread
// -------------------------------------------------------------------------------------------------
BOOL CCompanyNameProbe::AppCommunicationThreadLaunch()
{
    AppCommunicationThreadKill();

    // create 4 inter-thread synchronization event objects
    m_hAppCommunicationThreadEventOnOff =
        ::CreateEvent(
            nullptr,             // no security
            FALSE,               // auto-reset
            FALSE,               // initially unsignaled
            nullptr );           // no name

    m_hAppCommunicationThreadEventSuspended =
        ::CreateEvent(
            nullptr,              // no security
            FALSE,                // auto-reset
            FALSE,                // initially unsignaled
            nullptr );            // no name

    m_hAppCommunicationThreadEventResumed =
        ::CreateEvent(
            nullptr,             // no security
            FALSE,               // auto-reset
            FALSE,               // initially unsignaled
            nullptr );           // no name

    m_hAppCommunicationThreadEventStopped =
        ::CreateEvent(
            nullptr,             // no security
            FALSE,               // auto-reset
            FALSE,               // initially unsignaled
            nullptr );           // no name

    m_appCommunicationThreadState = E_THREAD_SUSPENDED;   // start with the mouse suspended

    DWORD dwThreadID;
    // create a secondary thread to do the I/O
    if ( nullptr == ( m_hAppCommunicationThread =
                          reinterpret_cast< HANDLE >( ::_beginthreadex(
                                                          nullptr,            // no security atts
                                                          0,                  // default stack
                                                          AppCommunicationThread,
                                                          this,               // argument: pointer to object
                                                          0,                  // creation flags
                                                          reinterpret_cast< unsigned* >( &dwThreadID ) ) ) ) )
    {
        ::CloseHandle( m_hAppCommunicationThreadEventOnOff );
        ::CloseHandle( m_hAppCommunicationThreadEventSuspended );
        ::CloseHandle( m_hAppCommunicationThreadEventResumed );
        ::CloseHandle( m_hAppCommunicationThreadEventStopped );
        m_appCommunicationThreadState = E_THREAD_OFF;
        return FALSE;
    }

    return TRUE;
}

// =================================================================================================
//   Resume the application communication thread
// -------------------------------------------------------------------------------------------------
BOOL CCompanyNameProbe::AppCommunicationThreadResume( void )
{
    if ( m_appCommunicationThreadState == E_THREAD_SUSPENDED )
    {
        m_appCommunicationThreadState = E_THREAD_ON;
        ::SetEvent( m_hAppCommunicationThreadEventOnOff );     // signal Mouse Thread
        ::WaitForSingleObject( m_hAppCommunicationThreadEventResumed, INFINITE );
    }

    return TRUE;
}

// =================================================================================================
//   Suspend the application communication thread
// -------------------------------------------------------------------------------------------------
BOOL CCompanyNameProbe::AppCommunicationThreadSuspend()
{
    if ( m_appCommunicationThreadState != E_THREAD_ON )
    {
        return TRUE;
    }

    m_appCommunicationThreadState = E_THREAD_SUSPENDED;
    ::SetEvent( m_hAppCommunicationThreadEventOnOff );     // signal Mouse Thread
    if ( ::WaitForSingleObject( m_hAppCommunicationThreadEventSuspended, 60000 ) != WAIT_OBJECT_0 )
    {
        AppCommunicationThreadKill();
        return FALSE;
    }

    return TRUE;
}

// =================================================================================================
//   Thread to end the probing
//
// Parameter: pProbe_ : Pointer to the plug-in object
//
// Return: 0
// -------------------------------------------------------------------------------------------------
static unsigned __stdcall EndProbingThread( void* pProbe_ )
{
    CCompanyNameProbe* pProbe = static_cast< CCompanyNameProbe* >( pProbe_ );

    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );
    {   // Begin scope for the COM message filter

        CRAIIComMessageFilter messageFilter;

        // This thread signals the application that the acquisition has ended
        if ( pProbe->m_cookieFeedback != 0 )
        {
            CComPtr< IIMProbeFeedback > pFeedback;
            GITGetInterfaceFromGlobal( pProbe->m_cookieFeedback, IID_IIMProbeFeedback, ( void** )&pFeedback );
            if ( pFeedback != nullptr )
            {
                pFeedback->ProbingEnd();
            }
        }
    }   // End scope for the COM message filter

    CoUninitialize();

    return 0;
}

// =================================================================================================
//   Thread to end the connection
// -------------------------------------------------------------------------------------------------
static unsigned __stdcall EndConnectionThread( void* pProbe_ )
{
    CCompanyNameProbe* pProbe = static_cast< CCompanyNameProbe* >( pProbe_ );

    CoInitializeEx( nullptr, COINIT_APARTMENTTHREADED );
    {   // Begin scope for the COM message filter
        CRAIIComMessageFilter messageFilter;

        // This thread signals the application that the acquisition has ended
        if ( pProbe->m_cookieFeedback != 0 )
        {
            CComPtr< IIMProbeFeedback > pFeedback;
            GITGetInterfaceFromGlobal( pProbe->m_cookieFeedback, IID_IIMProbeFeedback, ( void** )&pFeedback );
            if ( pFeedback != nullptr )
            {
                pFeedback->ConnectionEnd();
            }
        }

    }   // End scope for the COM message filter
    CoUninitialize();

    return 0;
}

// =================================================================================================
//   Launch the EndProbing thread
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::EndProbingThreadLaunch()
{
    DWORD dwThreadID;

    // create a thread
    if ( nullptr == ( reinterpret_cast< HANDLE >( ::_beginthreadex(
                                                      nullptr,               // no security atts
                                                      0,                     // default stack
                                                      EndProbingThread,
                                                      this,                  // argument: pointer to object
                                                      0,                     // creation flags
                                                      reinterpret_cast< unsigned* >( &dwThreadID ) ) ) ) )
    {
        return false;
    }

    return true;
}

// =================================================================================================
//   Launch the EndConnection thread
//
// Return: true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbe::EndConnectionThreadLaunch()
{
    DWORD dwThreadID;

    // Create a thread
    if ( nullptr == ( reinterpret_cast< HANDLE >( ::_beginthreadex(
                                                      nullptr,                            // no security attributes
                                                      0,                                  // default stack
                                                      EndConnectionThread,
                                                      this,                               // argument: pointer to object
                                                      0,                                  // creation flags
                                                      reinterpret_cast< unsigned* >( &dwThreadID ) ) ) ) )
    {
        return false;
    }

    return true;
}

// =================================================================================================
//   Pop-up the plug-in properties dialog
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::PropertiesDlgShow()
{
    if ( m_pDeviceSDKStub.get() != nullptr )
    {
        m_pDeviceSDKStub->ConfigurationDialogShow( nullptr );
    }
}

// =================================================================================================
//   Called by the stub when user press a device button
//
// Parameter: buttonIdentifier_ : Button identifier
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::OnButtonPressed( const unsigned int buttonIdentifier_ )
{
    // buttonIdentifier_ is 1 for acquisition and 2 for end of probing

    if ( IsTransmissionEnabled() )
    {
        // Button events transmission is activated
        CComPtr< IIMInputEventsReceiver > pInputEventsReceiver;

        // Protect the access to the GIT for the input events.
        if ( !m_isRevokingInputEventsReceiver )
        {
            GITGetInterfaceFromGlobal(
                m_cookieInputEventsReceiver,
                IID_IIMInputEventsReceiver,
                ( void** ) &pInputEventsReceiver );
        }

        if ( pInputEventsReceiver != nullptr )
        {
            pInputEventsReceiver->ButtonEvent( E_BUTTON_EVENT_PRESSED, buttonIdentifier_ );
        }

        return;
    }

    // TODO: Handle your pressed button event here
    //       For this case, we handle the end the probing with the button
    if ( buttonIdentifier_ == 2 )
    {
        // Save last position in case we need it for compensation
        SProbePosition positionAndDirection( m_lastRecordedPoint.dX, m_lastRecordedPoint.dY, m_lastRecordedPoint.dZ,
                                             m_lastRecordedPoint.dZI, m_lastRecordedPoint.dZJ, m_lastRecordedPoint.dZK );
        ProbePositionAndDirectionSet( positionAndDirection );

        EndProbingThreadLaunch();
    }
}

// =================================================================================================
//   Called by the stub when user release a device button
//
// Parameter: buttonIdentifier_ : Button identifier
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::OnButtonReleased( const unsigned int buttonIdentifier_ )
{
    // buttonIdentifier_ is 1 for acquisition and 2 for end of probing

    if ( IsTransmissionEnabled() )
    {
        // Button events transmission is activated
        CComPtr< IIMInputEventsReceiver > pInputEventsReceiver;

        // Protect the access to the GIT for the input events.
        if ( !m_isRevokingInputEventsReceiver )
        {
            GITGetInterfaceFromGlobal(
                m_cookieInputEventsReceiver,
                IID_IIMInputEventsReceiver,
                ( void** ) &pInputEventsReceiver );
        }

        if ( pInputEventsReceiver != nullptr )
        {
            pInputEventsReceiver->ButtonEvent( E_BUTTON_EVENT_RELEASED, buttonIdentifier_ );
        }
    }

    // TODO: Handle your released button event here
}

// =================================================================================================
//   Called by the stub to notify of a change in the connection state
//
// Parameter: connected_ : connection state
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::UpdateConnectionState( const bool connected_ )
{
    if ( !connected_ )
    {
        EndConnectionThreadLaunch();
    }
}

// =================================================================================================
//   Called by the stub to notify a device status change
//
// Parameter: status_ : Device status
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::UpdateDeviceStatus( const EDeviceStatus status_ )
{
    // TODO: This is an how you can report the device status to the application.  HasStatus() has to return VARIANT_TRUE
    //       to see it. If you have to frequently update the device status, this function should only update a member
    //       variable and the AppCommunicationThread taking care of transmitting the status with the code below.

    if ( status_ != m_status )
    {
        CComPtr< IIMProbeFeedback3 > pFeedback3;

        m_status = status_;

        if ( ( m_cookieFeedback != 0 ) &&
             ( GITGetInterfaceFromGlobal( m_cookieFeedback, IID_IIMProbeFeedback3, ( void** ) &pFeedback3 ) == S_OK ) &&
             ( pFeedback3 != nullptr ) )
        {
            pFeedback3->StatusSet( m_status );
        }
    }
}

// =================================================================================================
//   Called by the stub to send a new probed point
//
// Parameter: update_ : Probed point
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::OnPointAcquired( const SProbePosition& update_ )
{
    long timeStamp = GetExpireTime( 0 );

    // Record the point
    if ( ProbedPointRecord( update_, false ) )
    {
        ProbedPointSetLast( update_ );
        m_lastProbedPointTimeForNextUpdate = timeStamp + m_lastRecordedPointDelay;
    }
    else
    {
        m_lastProbedPointTimeForNextUpdate = 0;
    }
}

// =================================================================================================
//   Called by the stub to send a new position
//
// Parameter: update_ : Position point
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::OnPositionChanged( const SProbePosition& update_ )
{
    // In continuous mode, check if point need to be recorded
    if ( ( ( m_currentMode == E_CONTINUOUS_TIME_MODE ) && CanRecordNextPointTime() ) ||
         ( (   m_currentMode == E_CONTINUOUS_DISTANCE_MODE ) && CanRecordNextPointDistance( update_ ) ) )
    {
        // Record the point
        long timeStamp = GetExpireTime( 0 );

        if ( ProbedPointRecord( update_, false ) )
        {
            ProbedPointSetLast( update_ );
            m_lastProbedPointTimeForNextUpdate = timeStamp + m_lastRecordedPointDelay;
        }
    }

    // Sending the current position of the tip
    ProbePositionAndDirectionSet( update_ );
}

// =================================================================================================
//   Called by the stub to send a new probe diameter
//
// Parameter: diameter_ : Diameter
// -------------------------------------------------------------------------------------------------
void CCompanyNameProbe::UpdateProbeDiameter( const double diameter_ )
{
    // TODO: This is an how you can report the probe diameter to the application. If you have to frequently update the
    //       diameter, this function should only update a member variable and the AppCommunicationThread taking care of
    //       transmitting the new value with the code below.

    if ( diameter_ != m_probeDiameter )
    {
        CComPtr< IIMProbeFeedback3 > pFeedback3;

        m_probeDiameter = diameter_;

        if ( ( m_cookieFeedback != 0 ) &&
             ( GITGetInterfaceFromGlobal( m_cookieFeedback, IID_IIMProbeFeedback3, ( void** ) &pFeedback3 ) == S_OK ) &&
             ( pFeedback3 != nullptr ) )
        {
            pFeedback3->DiameterSet( diameter_ * theCompanyNameProbeSettings().HostUnitsScalingFactorGet() );
        }
    }
}
