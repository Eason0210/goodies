#ifndef _CCOMPANYNAMESDKSTUB_THURSDAY_OCTOBER242013_103723_H_
#define _CCOMPANYNAMESDKSTUB_THURSDAY_OCTOBER242013_103723_H_
// =================================================================================================
//   TODO: This class acts as an abstraction layer between your proprietary SDK and the plug-in.
//         You have to adapt it to your needs. The communication with the plug-in is done
//         through the receiver interface.
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include "CCompanyNameProbe.h"
#include "IReceiver.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   SDK stub class
// -------------------------------------------------------------------------------------------------
class CCompanyNameSDKStub
{
public:
    CCompanyNameSDKStub( IReceiver* pReceiver_ );
    ~CCompanyNameSDKStub();

    bool Connect();
    bool Disconnect();
    bool IsConnected() const { return m_connected; }

    bool ConfigurationDialogShow( HWND parent_ );

private:
    IReceiver* m_pReceiver;     // Receiver interface
    bool       m_connected;     // Connection state

    // Device communication thread
    friend unsigned __stdcall DeviceCommunicationThread( void* pStub_ );
    void                      DeviceCommunicationThreadKill();
    BOOL                      DeviceCommunicationThreadLaunch();
    BOOL                      DeviceCommunicationThreadResume();
    BOOL                      DeviceCommunicationThreadSuspend();

    EThreadState m_deviceCommunicationThreadState;
    HANDLE       m_hDeviceCommunicationThread;
    HANDLE       m_hDeviceCommunicationThreadEventOnOff;
    HANDLE       m_hDeviceCommunicationThreadEventResumed;
    HANDLE       m_hDeviceCommunicationThreadEventStopped;
    HANDLE       m_hDeviceCommunicationThreadEventSuspended;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

#endif // _CCOMPANYNAMESDKSTUB_THURSDAY_OCTOBER242013_103723_H_
