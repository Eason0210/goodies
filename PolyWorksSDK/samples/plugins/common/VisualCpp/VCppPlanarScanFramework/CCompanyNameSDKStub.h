#pragma once

// =================================================================================================
//   SDK Communication Stub.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "CompanyNameConst.h"
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

    CCompanyNameSDKStub( CCompanyNameScannerReceiver& receiver_ );
    virtual ~CCompanyNameSDKStub();

    bool Connect();
    bool Disconnect( bool notifyHost_ = true );
    bool IsConnected() { return m_isConnected; }
    bool ScanningEnd();
    bool ScanningStart();

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    SScanData AcquiredDataGet();

    // Protected member variables
    ///////////////////////////////

private:

    // Private member functions
    /////////////////////////////

    static unsigned int __stdcall CommunicationThreadProc( void* pCommunicationStub_ );

    // Private member variables
    /////////////////////////////

    CCompanyNameScannerReceiver& m_receiver;

    // Communication thread
    CThreadHelper m_communicationThread;

    HANDLE m_hScanStartEvent = nullptr;
    HANDLE m_hScanEndEvent   = nullptr;
    bool   m_isConnected     = false;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
