// =================================================================================================
//   Thread Helper Implementation.
//
// Author: InnovMetric Software Inc., Date: 2014-06-04
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CThreadHelper.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const DWORD timeoutThreadKill    = 5000;         // 5 secondes
static const DWORD timeoutThreadResume  = INFINITE;
static const DWORD timeoutThreadSuspend = 60000;        // 1 minute

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
CThreadHelper::CThreadHelper()
: m_hOnOffEvent( nullptr )
, m_hSuspendedEvent( nullptr )
, m_hThreadResumedEvent( nullptr )
, m_hThread( nullptr )
, m_enControl( E_CONTROL_OFF )
{

}


// =================================================================================================
//   Dtor.
// -------------------------------------------------------------------------------------------------
CThreadHelper::~CThreadHelper()
{
    ThreadReset();
}


// =================================================================================================
//   Release the main thread.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CThreadHelper::MainThreadRelease()
{
    DWORD handleIndex = 0;
    if ( ::CoWaitForMultipleHandles( 0, 0, 1, &m_hOnOffEvent, &handleIndex ) == S_OK &&
         handleIndex == 0 )
    {
        // release main thread
        ::SetEvent( m_hSuspendedEvent );
        ::CoWaitForMultipleHandles( 0, INFINITE, 1, &m_hOnOffEvent, &handleIndex );
        ::SetEvent( m_hThreadResumedEvent );
    }

    return true;
}


// =================================================================================================
//   Terminate the thread.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CThreadHelper::ThreadKill()
{
    // boiler plate stuff
    if ( m_hThread == nullptr )      // if Thread already not running
    {
        return true;
    }

    if ( !ThreadResume() )
    {
        return false;
    }

    m_enControl = E_CONTROL_OFF;
    DWORD handleIndex = 0;
    if ( ::CoWaitForMultipleHandles( 0, timeoutThreadKill, 1, &m_hThread, &handleIndex ) != S_OK )
    {
        if ( ::TerminateThread( m_hThread, 0 ) == FALSE )
        {
            return false;
        }
    }

    return ThreadReset();
}


// =================================================================================================
//   Launch the thread.
//
// Parameter: threadProc_ : Thread processor
// Parameter: pParam_     : Instance pointer
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CThreadHelper::ThreadLaunch( unsigned( __stdcall* threadProc_ )( void* ), void* pParam_ )
{
    if ( ( threadProc_ == nullptr ) ||
         ( pParam_ == nullptr ) )
    {
        return false;
    }

    // boiler plate stuff
    if ( m_hThread != nullptr )      // if Thread already running
    {
        ThreadKill();
    }

    // create 3 interthread synchronization event objects
    m_hOnOffEvent = ::CreateEvent(
        nullptr,                           // no security
        FALSE,                             // auto-reset
        FALSE,                             // initially unsignalled
        nullptr );                         // no name

    m_hSuspendedEvent = ::CreateEvent(
        nullptr,                               // no security
        FALSE,                                 // auto-reset
        FALSE,                                 // initially unsignalled
        nullptr );                             // no name

    m_hThreadResumedEvent = ::CreateEvent(
        nullptr,                                   // no security
        FALSE,                                     // auto-reset
        FALSE,                                     // initially unsignalled
        nullptr );                                 // no name

    m_enControl = E_CONTROL_SUSPENDED;   // start with the thread suspended

    DWORD dwThreadID;
    // create a secondary thread to do the I/O
    if ( nullptr == ( m_hThread = reinterpret_cast< HANDLE >( ::_beginthreadex(
                                                                  nullptr,            // no security atts
                                                                  0,                  // default stack
                                                                  threadProc_,
                                                                  pParam_,               // argument: pointer to object
                                                                  0,                     // creation flags
                                                                  reinterpret_cast< unsigned* >( &dwThreadID ) ) ) ) )
    {
        ThreadReset();
        return false;
    }

    return true;
}


// =================================================================================================
//   Reset the thread.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CThreadHelper::ThreadReset()
{
    if ( m_hOnOffEvent != nullptr )
    {
        ::CloseHandle( m_hOnOffEvent );
        m_hOnOffEvent = nullptr;
    }

    if ( m_hSuspendedEvent != nullptr )
    {
        ::CloseHandle( m_hSuspendedEvent );
        m_hSuspendedEvent = nullptr;
    }

    if ( m_hThreadResumedEvent != nullptr )
    {
        ::CloseHandle( m_hThreadResumedEvent );
        m_hThreadResumedEvent = nullptr;
    }

    m_enControl = E_CONTROL_OFF;

    if ( m_hThread != nullptr )
    {
        ::CloseHandle( m_hThread );
        m_hThread = nullptr;
    }

    return true;
}


// =================================================================================================
//   Resume the thread execution.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CThreadHelper::ThreadResume()
{
    // boiler plate stuff
    if ( m_enControl == E_CONTROL_SUSPENDED )
    {
        m_enControl = E_CONTROL_ON;
        ::SetEvent( m_hOnOffEvent );
        DWORD handleIndex = 0;
        ::CoWaitForMultipleHandles( 0, timeoutThreadResume, 1, &m_hThreadResumedEvent, &handleIndex );
    }

    return true;
}


// =================================================================================================
//   Suspend the thread execution.
//
// Return : true if successful, false otherwise
// -------------------------------------------------------------------------------------------------
bool CThreadHelper::ThreadSuspend()
{
    // boiler plate stuff
    if ( m_enControl != E_CONTROL_ON )
    {
        return true;
    }

    m_enControl = E_CONTROL_SUSPENDED;
    ::SetEvent( m_hOnOffEvent );
    DWORD handleIndex = 0;
    if ( ::CoWaitForMultipleHandles( 0, timeoutThreadSuspend, 1, &m_hSuspendedEvent, &handleIndex ) != S_OK )
    {
        ThreadKill();
        return false;
    }

    return true;
}

// =================================================================================================
//   Waits until suspend is turn off.
//
// Return : S_OK if successful
// -------------------------------------------------------------------------------------------------
HRESULT CThreadHelper::WaitUntilSuspendOff()
{
    DWORD   handleIndex = 0;
    HRESULT result      = ::CoWaitForMultipleHandles( 0, INFINITE, 1, &m_hOnOffEvent, &handleIndex );

    ::SetEvent( m_hThreadResumedEvent );

    return result;
}
