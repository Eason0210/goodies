#ifndef _CCOMMESSAGEFILTER_MONDAY_JUNE022014_123828_H_
#define _CCOMMESSAGEFILTER_MONDAY_JUNE022014_123828_H_
// =================================================================================================
//   CComMessageFilter class declaration.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCUDED FILES ==========================================
#include <atlcomcli.h>
#include <objidl.h>

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// ===========================================================================
// Possibles options when application tells the plug-in to retry a COM call
// ===========================================================================
enum EMessageFilterClientOnRetryLater
{
    E_MESSAGE_FILTER_CLIENT_RETRY_ALWAYS,  // Always retry
    E_MESSAGE_FILTER_CLIENT_RETRY_CONFIRM, // Always retry but also display a message after 30 seconds delay
    // "Module cannot execute command. It is busy."
    E_MESSAGE_FILTER_CLIENT_RETRY_NEVER    // Never retry
};

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CComMessageFilter : public IMessageFilter
{
public:
    CComMessageFilter( EMessageFilterClientOnRetryLater clientOnRetryLater_ = E_MESSAGE_FILTER_CLIENT_RETRY_ALWAYS );
    virtual ~CComMessageFilter();

    void Register();
    void UnRegister();

    // IUnknown
    STDMETHODIMP QueryInterface( REFIID riid_, void** ppObj_ );
    STDMETHODIMP_( ULONG ) AddRef();
    STDMETHODIMP_( ULONG ) Release();

    // IMessageFilter
    STDMETHODIMP_( DWORD ) HandleInComingCall(
        /* [in] */ DWORD dwCallType,
        /* [in] */ HTASK htaskCaller,
        /* [in] */ DWORD dwTickCount,
        /* [in] */ LPINTERFACEINFO lpInterfaceInfo );

    STDMETHODIMP_( DWORD ) RetryRejectedCall(
        /* [in] */ HTASK htaskCallee,
        /* [in] */ DWORD dwTickCount,
        /* [in] */ DWORD dwRejectType );

    STDMETHODIMP_( DWORD ) MessagePending(
        /* [in] */ HTASK htaskCallee,
        /* [in] */ DWORD dwTickCount,
        /* [in] */ DWORD dwPendingType );

private:

    long                             m_refCount;
    CComPtr< IMessageFilter >        m_pPreviousMessageFilter;
    EMessageFilterClientOnRetryLater m_clientOnRetryLater;

private:
    // Not implemented
    CComMessageFilter( const CComMessageFilter& );
    const CComMessageFilter& operator=( const CComMessageFilter& );
};



class CRAIIComMessageFilter
{
public:
    CRAIIComMessageFilter( EMessageFilterClientOnRetryLater clientOnRetryLater_ = E_MESSAGE_FILTER_CLIENT_RETRY_ALWAYS );
    ~CRAIIComMessageFilter();
private:
    CComPtr< CComMessageFilter > m_comMessageFilter;
private:
    // Not implemented
    CRAIIComMessageFilter( const CRAIIComMessageFilter& );
    const CRAIIComMessageFilter& operator=( const CRAIIComMessageFilter& );

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================


#endif // _CCOMMESSAGEFILTER_MONDAY_JUNE022014_123828_H_
