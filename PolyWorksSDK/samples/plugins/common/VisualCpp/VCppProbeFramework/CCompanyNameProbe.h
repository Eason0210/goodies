#ifndef _CCOMPANYNAMEPROBE_FRIDAY_OCTOBER252013_091510_H_
#define _CCOMPANYNAMEPROBE_FRIDAY_OCTOBER252013_091510_H_
// =================================================================================================
//   Plug-in implementation
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include <PolyWorksSDK/COM/IMTypes.h>
#include <float.h>
#include <memory>
#include <vector>

#include "IReceiver.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================
class CCompanyNameProbe;
class CCompanyNameSDKStub;

struct IIMInputEventsReceiver;
struct IIMPointCloud;
struct IIMProbeFeedback;
struct IIMProbeFeedback2;

struct SProbeRecordData;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// Thread state
enum EThreadState
{
    E_THREAD_OFF,
    E_THREAD_ON,
    E_THREAD_SUSPENDED,
};

// TODO: Polyworks compensation methods supported
enum ECompMethods
{
    E_COMP_METHOD_FIRST_POINT_VECTOR,
    E_COMP_METHOD_LAST_POINT_POSITION,
    E_COMP_METHOD_APPROACH_DIRECTION,
    E_NB_COMP_METHOD
};

// TODO: Identify the probing modes
const enum ERecordModes
{
    // Modes available to users should appear between
    // E_FIRST_USER_MODE and E_LAST_USER_MODE inclusively
    // E_NB_USER_MODES must always follow E_LAST_USER_MODE.
    E_FIRST_USER_MODE          = 0,
    E_SINGLE_MODE              = E_FIRST_USER_MODE, // This mode must be present
    E_CONTINUOUS_TIME_MODE     = 1,                 // Optional
    E_CONTINUOUS_DISTANCE_MODE = 2,                 // Optional
    E_LAST_USER_MODE           = E_CONTINUOUS_DISTANCE_MODE,
    E_NB_USER_MODES
};

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// TODO: Adapt the following struct as needed
struct SProbePosition
{
    SProbePosition()
    :  dX( FLT_MAX )
    , dY( FLT_MAX )
    , dZ( FLT_MAX )
    , dZI( FLT_MAX )
    , dZJ( FLT_MAX )
    , dZK( FLT_MAX )
    {}

    SProbePosition( double positionX_,
                    double positionY_,
                    double positionZ_,
                    double directionZI_,
                    double directionZJ_,
                    double directionZK_ )
    : dX( positionX_ )
    , dY( positionY_ )
    , dZ( positionZ_ )
    , dZI( directionZI_ )
    , dZJ( directionZJ_ )
    , dZK( directionZK_ )
    {}

    double dX, dY, dZ;      // probe origin
    double dZI, dZJ, dZK;   // probe z-axis vector
};

// =================================================================================================
//   Plug-in implementation
// -------------------------------------------------------------------------------------------------
class CCompanyNameProbe : public IReceiver
{
public:
    virtual ~CCompanyNameProbe();

    virtual bool InitConnection( IIMProbeFeedback* pFeedback_ );
    virtual bool EndConnection();

    bool ProbingEnd( bool probeLastPoint_ );
    bool ProbingStart( IIMPointCloud* pCloud_ );

    bool CanRecordNextPointTime();
    bool CanRecordNextPointDistance( const SProbePosition& position_ );

    void ContinuousModeEnabled( bool enable_ );
    bool IsCurrentModeContinuous();

    short             ModeNbGet() { return static_cast< short >( E_NB_USER_MODES ); }
    void              ModeSet( ERecordModes mode_ );
    wchar_t*          ModeNameGet( ERecordModes mode_ );
    EProbingModeTypes ModeTypeGet( ERecordModes mode_ );

    void UnitsScalingFactorSet();
    void UseProbeAsMouseSet( bool useProbeAsMouse_ );

    long ProbePositionAndDirectionSend();
    void ProbePositionAndDirectionSet( const SProbePosition& position_ );
    bool ProbedPointRecord( const SProbePosition& position_, bool fromProbingEnd_ );
    bool ProbedPointSend( long* pDelay_ );
    bool ProbedPointSetLast( const SProbePosition& position_ );

    bool IsError( BOOL error_ );
    void SetupCurrentProbe( BOOL bImmediateFlag, ERecordModes mode );

    bool EndConnectionThreadLaunch();
    bool EndProbingThreadLaunch();

    bool IsTransmissionEnabled() const { return m_cookieInputEventsReceiver != 0; }
    bool TransmissionEnable( IIMInputEventsReceiver* pInputEventsReceiver_ );
    void TransmissionDisable();

    void PropertiesDlgShow();

    // IReceiver interface functions
    void OnButtonPressed( const unsigned int buttonIdentifier_ );
    void OnButtonReleased( const unsigned int buttonIdentifier_ );
    void UpdateConnectionState( const bool connected_ );
    void UpdateDeviceStatus( const EDeviceStatus status_ );
    void OnPointAcquired( const SProbePosition& update_ );
    void OnPositionChanged( const SProbePosition& update_ );
    void UpdateProbeDiameter( const double diameter_ );

    bool         m_aborting;
    ERecordModes m_currentMode;
    bool         m_ProbingIsPaused;

    DWORD m_cookieCommandCenter;
    DWORD m_cookieFeedback;
    DWORD m_cookieHost;
    DWORD m_cookieInputEventsReceiver;
    DWORD m_cookiePtCloud;

    bool m_isRevokingInputEventsReceiver;

    long   m_lastRecordedPointDelay;
    double m_lastRecordedPointDistance;
    long   m_lastProbedPointTimeForNextUpdate;
    bool   m_hasRecordedFirstContinuousPoint;

    // Probing information
    double        m_probeDiameter;
    EDeviceStatus m_status;

private:
    bool ExecuteCommandOnApp( const wchar_t* command_ );

    bool ProbePositionAndDirectionGet( SProbePosition& probePosition_ );
    bool ProbedDataSend( long& nbPtsSent_ );
    void ProbedDataSwitchContainer();
    void ProbedPointGetLast( SProbePosition& probedPosition_ );

    bool ThreadsStart();
    void ThreadsKill();

    // Communication thread with the application
    friend unsigned __stdcall AppCommunicationThread( void* pStub_ );
    void                      AppCommunicationThreadKill();
    BOOL                      AppCommunicationThreadLaunch();
    BOOL                      AppCommunicationThreadResume( void );
    BOOL                      AppCommunicationThreadSuspend();

    EThreadState m_appCommunicationThreadState;
    HANDLE       m_hAppCommunicationThread;
    HANDLE       m_hAppCommunicationThreadEventOnOff;
    HANDLE       m_hAppCommunicationThreadEventResumed;
    HANDLE       m_hAppCommunicationThreadEventStopped;
    HANDLE       m_hAppCommunicationThreadEventSuspended;

    // Probed data containers
    bool                          m_dataAddToOne;
    CRITICAL_SECTION              m_dataRead;
    CRITICAL_SECTION              m_dataWrite;
    std::vector< SProbePosition > m_dataOne;
    std::vector< SProbePosition > m_dataTwo;

    // Last probed point
    SProbePosition m_lastRecordedPoint;

    // Latest probe position
    CRITICAL_SECTION m_probePositionGuard;
    SProbePosition   m_probePosition;
    bool             m_probePositionNew;

    // Stub talking with the device hardware
    std::unique_ptr< CCompanyNameSDKStub > m_pDeviceSDKStub;

    friend CCompanyNameProbe& theCompanyNameProbe();
    CCompanyNameProbe();
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

CCompanyNameProbe& theCompanyNameProbe();

HRESULT GITGetInterfaceFromGlobal( DWORD dwCookie_, REFIID riid_, void** ppv_ );
HRESULT GITRegisterInterfaceInGlobal( IUnknown* pUnk_, REFIID riid_, DWORD* pdwCookie_ );
HRESULT GITRevokeInterfaceFromGlobal( DWORD& dwCookie_, UINT retriesWhenBusy_ = 0 );

long GetExpireTime( long duration );
bool HasTimeExpired( long expire_time );

#endif // _CCOMPANYNAMEPROBE_FRIDAY_OCTOBER252013_091510_H_
