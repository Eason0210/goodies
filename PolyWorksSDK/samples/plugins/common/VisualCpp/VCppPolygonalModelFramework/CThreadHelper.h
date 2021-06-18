#pragma once

// =================================================================================================
//   Thread Helper.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================


// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

enum EControlFlag
{
    E_CONTROL_OFF,
    E_CONTROL_ON,
    E_CONTROL_SUSPENDED,
};

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Thread Helper Class.
// -------------------------------------------------------------------------------------------------
class CThreadHelper
{
public:

    // Public member functions
    ////////////////////////////

    CThreadHelper();
    virtual ~CThreadHelper();

    bool IsEnableControl() { return m_enControl != E_CONTROL_OFF; }
    bool MainThreadRelease();
    bool ThreadKill();
    bool ThreadLaunch( unsigned( __stdcall* threadProc_ )( void* ), void* pParam_ );
    bool    ThreadReset();
    bool    ThreadResume();
    bool    ThreadSuspend();
    HRESULT WaitUntilSuspendOff();

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

    // Private member variables
    /////////////////////////////

    HANDLE       m_hOnOffEvent;
    HANDLE       m_hSuspendedEvent;
    HANDLE       m_hThreadResumedEvent;
    HANDLE       m_hThread;
    EControlFlag m_enControl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
