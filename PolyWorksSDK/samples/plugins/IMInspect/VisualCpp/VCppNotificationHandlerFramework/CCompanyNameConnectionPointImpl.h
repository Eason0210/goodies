#pragma once
// =================================================================================================
//     Allows an object that implements a connection point outgoing interface to receive
// notifications from Inspector.
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "INotificationFeedback.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Generic class that contains a sink as an instance of COutgoing that implements an IOutgoing
// interface.
// Wraps attaching and detaching to a connection point associated with the IOutgoing interface
// -------------------------------------------------------------------------------------------------
template< class COutgoing >
class CCompanyNameConnectionPointImpl final
{
public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CCompanyNameConnectionPointImpl( INotificationFeedback& feedback_ );
    virtual ~CCompanyNameConnectionPointImpl();

    bool NotificationActivationSet( bool activate_, IUnknown& unk_ );
    bool NotificationActivationGet() const { return m_isNotificationActivated; }
private:
    // ---------------- Private Methods ------------------------------------------------------------
    bool Advise( IUnknown& pCPC_ );
    bool Unadvise( IUnknown& pCPC_ );
    // ---------------- Private Member Variables ---------------------------------------------------
    // This variable was not changed into a CComPtr. The modifications necessary for it to work did not
    // take advantage of the self releasing mechanic since the call to release needed to be explicit in
    // the destructor. For simplicity, code was left as is.
    CComObject< COutgoing >* m_psink;
    DWORD                    m_cookie                  = 0;
    bool                     m_isNotificationActivated = false;
};

// =================================================================================================
//  Constructor
// -------------------------------------------------------------------------------------------------
template< class COutgoing >
inline CCompanyNameConnectionPointImpl< COutgoing >::CCompanyNameConnectionPointImpl( INotificationFeedback& feedback_ )
: m_psink{ nullptr }
{
    if ( CComObject< COutgoing >::CreateInstance( &m_psink ) == S_OK )
    {
        m_psink->AddRef();
        m_psink->Init( feedback_ );
    }
}

// =================================================================================================
//  Destructor
// -------------------------------------------------------------------------------------------------
template< class COutgoing >
inline CCompanyNameConnectionPointImpl< COutgoing >::~CCompanyNameConnectionPointImpl()
{
    m_psink->Release();
}

// =================================================================================================
//  Allows this connection point to receive notifications
// -------------------------------------------------------------------------------------------------
template< class COutgoing >
inline bool CCompanyNameConnectionPointImpl< COutgoing >::NotificationActivationSet( bool activate_, IUnknown& unk_ )
{
    if ( m_isNotificationActivated != activate_ )
    {
        m_isNotificationActivated = activate_;
        return activate_ ? Advise( unk_ ) : Unadvise( unk_ );
    }
    return true;
}

// =================================================================================================
//  Attach an instance implementing IOutgoing to an IConnectionPointContainer to
//  receive notifications
// -------------------------------------------------------------------------------------------------
template< typename COutgoing >
inline bool CCompanyNameConnectionPointImpl< COutgoing >::Advise( IUnknown& pCPC_ )
{
    return AtlAdvise( &pCPC_, m_psink, COutgoing::ID(), &m_cookie ) == S_OK;
}
// =================================================================================================
//  Attach an instance implementing IOutgoing to an IConnectionPointContainer to
//  stop receiving notifications
// -------------------------------------------------------------------------------------------------
template< typename COutgoing >
inline bool CCompanyNameConnectionPointImpl< COutgoing >::Unadvise( IUnknown& pCPC_ )
{
    return AtlUnadvise( &pCPC_, COutgoing::ID(), m_cookie ) == S_OK;
}
