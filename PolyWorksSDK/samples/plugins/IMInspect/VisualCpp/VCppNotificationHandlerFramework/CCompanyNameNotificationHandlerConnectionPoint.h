#pragma once

// =================================================================================================
//   Classes that define sink objects implementing given notifications interface compatible with
// Inspector. It is not necessary to define a behavior for every method of a notification interface.
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <atlbase.h>
#include <atlcom.h>
#include <string>
#include <vector>
#include <wincrypt.h>
#include <winnt.h>

#include <optional>

#include "CCompanyNameNotificationFeedback.h"
#include "IMCOMInterfaceInclude.h"
#include "Resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

namespace ATL { class CComSingleThreadModel; }

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Class that receives notification of events concerning Data objects
// -------------------------------------------------------------------------------------------------
class CDataObjectNotificationSink :  public IIMDataObjectNotifications,
                                     public CComObjectRoot
{
public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CDataObjectNotificationSink()          = default;
    virtual ~CDataObjectNotificationSink() = default;

    BEGIN_COM_MAP( CDataObjectNotificationSink )
    COM_INTERFACE_ENTRY( IIMDataObjectNotifications )
    END_COM_MAP()

    static constexpr IID ID() { return __uuidof( IIMDataObjectNotifications ); }

    // IIMDataObjectNotifications
    STDMETHODIMP OnDataObjectsAdded( SAFEARRAY* uniqueIDs_ ) override;
    STDMETHODIMP OnDataObjectsDeleted( SAFEARRAY* uniqueIDs_ ) override;
    STDMETHODIMP OnDataObjectsEdited( SAFEARRAY* uniqueIDs_ ) override;
    STDMETHODIMP OnDataObjectsTransformed( SAFEARRAY* uniqueIDs_, ETransformTypes transformationType_ ) override;

    void Init( INotificationFeedback& feedback_ ) { m_feedback.Init( feedback_ ); }
private:
    // ---------------- Private Member Variables ---------------------------------------------------
    CCompanyNameNotificationFeedback m_feedback;
};

// =================================================================================================
//   Class that receives notification of events concerning Reference objects
// -------------------------------------------------------------------------------------------------
class CReferenceObjectNotificationSink : public CComObjectRoot,
                                         public IIMReferenceObjectNotifications
{
public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CReferenceObjectNotificationSink()          = default;
    virtual ~CReferenceObjectNotificationSink() = default;

    BEGIN_COM_MAP( CReferenceObjectNotificationSink )
    COM_INTERFACE_ENTRY( IIMReferenceObjectNotifications )
    END_COM_MAP()

    static constexpr IID ID() { return __uuidof( IIMReferenceObjectNotifications ); }

    // IIMReferenceObjectNotifications
    STDMETHODIMP OnReferenceObjectsAdded( SAFEARRAY* uniqueIDs_ ) override;
    STDMETHODIMP OnReferenceObjectsDeleted( SAFEARRAY* uniqueIDs_ ) override;
    STDMETHODIMP OnReferenceObjectsEdited( SAFEARRAY* uniqueIDs_ ) override;
    STDMETHODIMP OnReferenceObjectsTransformed( SAFEARRAY* uniqueIDs_, ETransformTypes transformationType_ ) override;

    void Init( INotificationFeedback& feedback_ ) { m_feedback.Init( feedback_ ); }
private:
    // ---------------- Private Member Variables ---------------------------------------------------
    CCompanyNameNotificationFeedback m_feedback;
};

// =================================================================================================
//   Class that receives notification regarding changes of the current Inspector project or piece.
// -------------------------------------------------------------------------------------------------
class CInspectProjectNotificationSink :   public CComObjectRoot,
                                          public IIMInspectorProjectNotifications
{
public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CInspectProjectNotificationSink()          = default;
    virtual ~CInspectProjectNotificationSink() = default;

    BEGIN_COM_MAP( CInspectProjectNotificationSink )
    COM_INTERFACE_ENTRY( IIMInspectorProjectNotifications )
    END_COM_MAP()

    static constexpr IID ID() { return __uuidof( IIMInspectorProjectNotifications ); }

    // IIMInspectorProjectNotifications
    STDMETHODIMP OnCurrentPieceChanged( BSTR uniqueIDs_ ) override;
    STDMETHODIMP OnCurrentPieceSaved( BSTR uniqueIDs_ ) override;

    void Init( INotificationFeedback& feedback_ ) { m_feedback.Init( feedback_ ); }
private:
    // ---------------- Private Member Variables ---------------------------------------------------
    CCompanyNameNotificationFeedback m_feedback;
};

// =================================================================================================
//   Class that receives notification regarding changes in Data Object Group
// -------------------------------------------------------------------------------------------------
class CDataObjectGroupNotificationSink : public CComObjectRoot,
                                         public IIMDataObjectGroupNotifications
{
public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CDataObjectGroupNotificationSink()          = default;
    virtual ~CDataObjectGroupNotificationSink() = default;

    BEGIN_COM_MAP( CDataObjectGroupNotificationSink )
    COM_INTERFACE_ENTRY( IIMDataObjectGroupNotifications )
    END_COM_MAP()

    static constexpr IID ID() { return __uuidof( IIMDataObjectGroupNotifications ); }

    // IIMDataObjectGroupNotifications
    STDMETHODIMP OnDataObjectGroupsAdded( SAFEARRAY* uniqueIDs_ ) override;
    STDMETHODIMP OnDataObjectGroupsDeleted( SAFEARRAY* uniqueIDs_ ) override;
    STDMETHODIMP OnDataObjectGroupsRenamed( SAFEARRAY* uniqueIDs_ ) override;

    void Init( INotificationFeedback& feedback_ ) { m_feedback.Init( feedback_ ); }
private:
    // ---------------- Private Member Variables ---------------------------------------------------
    CCompanyNameNotificationFeedback m_feedback;
};
