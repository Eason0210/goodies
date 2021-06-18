// =================================================================================================
//   CComMessageFilter class implementation.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CComMessageFilter.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

const int RETRY_TIME_IN_MS                  = 200;
const int TIME_BEFORE_ASKING_THE_USER_IN_MS = 30000;

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

//////////////////////////////////////////////////////////////////////////
// CRAIIComMessageFilter
//////////////////////////////////////////////////////////////////////////

// =================================================================================================
CRAIIComMessageFilter::CRAIIComMessageFilter( EMessageFilterClientOnRetryLater clientOnRetryLater_ )
: m_comMessageFilter( nullptr )
{
    m_comMessageFilter = new CComMessageFilter( clientOnRetryLater_ );
    m_comMessageFilter->Register();
}


// =================================================================================================
CRAIIComMessageFilter::~CRAIIComMessageFilter()
{
    m_comMessageFilter->UnRegister();
}


//////////////////////////////////////////////////////////////////////////
// CComMessageFilter
//////////////////////////////////////////////////////////////////////////

// =================================================================================================
CComMessageFilter::CComMessageFilter( EMessageFilterClientOnRetryLater clientOnRetryLater_ )
: m_refCount( 0 )
, m_pPreviousMessageFilter( nullptr )
, m_clientOnRetryLater( clientOnRetryLater_ )
{
}


// =================================================================================================
CComMessageFilter::~CComMessageFilter()
{
}


// =================================================================================================
void CComMessageFilter::Register()
{
    CoRegisterMessageFilter( this, &m_pPreviousMessageFilter );
}


// =================================================================================================
void CComMessageFilter::UnRegister()
{
    CoRegisterMessageFilter( m_pPreviousMessageFilter, nullptr );
    if ( m_pPreviousMessageFilter != nullptr )
    {
        m_pPreviousMessageFilter = nullptr;
    }
}


//////////////////////////////////////////////////////////////////////////
// IUnknown
//////////////////////////////////////////////////////////////////////////

// =================================================================================================
STDMETHODIMP CComMessageFilter::QueryInterface( REFIID riid_, void** ppObj_ )
{
    if ( ppObj_ == nullptr )
    {
        return E_INVALIDARG;
    }

    if ( riid_ != IID_IUnknown && riid_ != IID_IMessageFilter )
    {
        *ppObj_ = nullptr;
        return E_NOINTERFACE;
    }

    *ppObj_ = static_cast< IMessageFilter* >( this );
    ( ( IUnknown* )*ppObj_ )->AddRef();

    return S_OK;
}


// =================================================================================================
STDMETHODIMP_( ULONG )
CComMessageFilter::AddRef()
{
    int res = InterlockedIncrement( &m_refCount );

    return res;
}


// =================================================================================================
STDMETHODIMP_( ULONG )
CComMessageFilter::Release()
{
    long nRefCount = 0;

    nRefCount = InterlockedDecrement( &m_refCount );

    if ( nRefCount == 0 )
    {
        delete this;
    }

    return nRefCount;
}


//////////////////////////////////////////////////////////////////////////
// IMessageFilter
//////////////////////////////////////////////////////////////////////////

// =================================================================================================
STDMETHODIMP_( DWORD )
CComMessageFilter::HandleInComingCall(
    /* [in] */ DWORD dwCallType,
    /* [in] */ HTASK htaskCaller,
    /* [in] */ DWORD dwTickCount,
    /* [in] */ LPINTERFACEINFO lpInterfaceInfo )
{
    if ( dwCallType == CALLTYPE_TOPLEVEL_CALLPENDING )
    {
        return SERVERCALL_RETRYLATER;
    }

    if ( m_pPreviousMessageFilter != nullptr )
    {
        return m_pPreviousMessageFilter->HandleInComingCall( dwCallType, htaskCaller, dwTickCount, lpInterfaceInfo );
    }
    return SERVERCALL_ISHANDLED;
}


// =================================================================================================
STDMETHODIMP_( DWORD )
CComMessageFilter::RetryRejectedCall(
    /* [in] */ HTASK htaskCallee,
    /* [in] */ DWORD dwTickCount,
    /* [in] */ DWORD dwRejectType )
{
    if ( dwRejectType == SERVERCALL_RETRYLATER )
    {
        if ( m_clientOnRetryLater == E_MESSAGE_FILTER_CLIENT_RETRY_NEVER )
        {
            return DWORD( -1 ); // COM call is rejected
        }

        bool retry = true;
        if ( ( m_clientOnRetryLater == E_MESSAGE_FILTER_CLIENT_RETRY_CONFIRM ) &&
             ( dwTickCount >= TIME_BEFORE_ASKING_THE_USER_IN_MS ) )
        {
            retry = MessageBox(
                nullptr,
                L"Module cannot execute command. It is busy.",
                L"Server busy",
                MB_RETRYCANCEL | MB_ICONWARNING ) == IDRETRY;
        }

        if ( retry )
        {
            return RETRY_TIME_IN_MS;
        }
    }

    if ( m_pPreviousMessageFilter != nullptr )
    {
        return m_pPreviousMessageFilter->RetryRejectedCall( htaskCallee, dwTickCount, dwRejectType );
    }

    return DWORD( -1 );
}


// =================================================================================================
STDMETHODIMP_( DWORD ) CComMessageFilter::MessagePending(
    /* [in] */ HTASK htaskCallee,
    /* [in] */ DWORD dwTickCount,
    /* [in] */ DWORD dwPendingType )
{
    if ( m_pPreviousMessageFilter != nullptr )
    {
        return m_pPreviousMessageFilter->MessagePending( htaskCallee, dwTickCount, dwPendingType );
    }
    return PENDINGMSG_WAITDEFPROCESS;
}
