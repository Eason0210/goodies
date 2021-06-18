#pragma once

// =================================================================================================
//   SDK Communication Stub.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "CThreadHelper.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================
class CCompanyNameScannerReceiver;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   SDK Communication Stub.
// -------------------------------------------------------------------------------------------------
class CCompanyNameSDKStub
{
public:

    // Public member functions
    ////////////////////////////

    CCompanyNameSDKStub( CCompanyNameScannerReceiver* pReceiver_ = nullptr );
    virtual ~CCompanyNameSDKStub();

    bool Connect();
    bool Disconnect( bool notifyHost_ = true );
    bool IsConnected() { return m_isConnected; }
    bool ReceiveEnd();
    bool ReceiveStart();
    bool ScanningEnd();
    bool ScanningStart();

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    // Protected member variables
    ///////////////////////////////

private:

    // Private member functions
    /////////////////////////////
    friend unsigned __stdcall CommunicationThreadProc( void* pCompanyNameSDKStub_ );
    bool                      ThreadRun();

    // Private member variables
    /////////////////////////////

    CCompanyNameScannerReceiver* m_pReceiver;

    // Communication thread
    CThreadHelper m_communicationThread;

    bool m_isConnected;
    bool m_isPassStarted;

    // TODO: Remove. Used for the simulator
    int   m_nPoints;
    int   m_nLines;
    float m_xPos;
    float m_yPos;
    float m_zPos;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
