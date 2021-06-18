// =================================================================================================
//   Polyworks SDK interface implementation
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameNotificationHandlerConnectionPoint.h"

#include <atlbase.h>
#include <atlcom.h>
#include <string>

#include "IMCOMInterfaceInclude.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================


// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// Returns a string corresponding to a given transformation type
// -------------------------------------------------------------------------------------------------
static std::wstring TransformationStringGet( ETransformTypes transformationType_ )
{
    std::wstring transformation;
    switch ( transformationType_ )
    {
        case E_TRANSFORM_MIRROR:
            transformation = L"mirrored";
            break;
        case E_TRANSFORM_ROTATION_TRANSLATION:
            transformation = L"rotated or translated";
            break;
        case E_TRANSFORM_SCALING:
            transformation = L"rescaled"; break;
        default:
            transformation = L"transformed";
            break;
    }
    return L"Data Object " + transformation;
}

// =================================================================================================
// TODO : For each method of each notification interface, you may implement a given behavior or return
// E_NOTIMPL if nothing specific needs to be done.

// =================================================================================================
// IIMDataObjectNotifications.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CDataObjectNotificationSink::OnDataObjectsAdded( SAFEARRAY* uniqueIDs_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Data Object added" );
}

STDMETHODIMP CDataObjectNotificationSink::OnDataObjectsDeleted( SAFEARRAY* uniqueIDs_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Data Object deleted" );
}

STDMETHODIMP CDataObjectNotificationSink::OnDataObjectsEdited( SAFEARRAY* uniqueIDs_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Data Object edited" );
}

STDMETHODIMP CDataObjectNotificationSink::OnDataObjectsTransformed( SAFEARRAY* uniqueIDs_, ETransformTypes transformationType_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, TransformationStringGet( transformationType_ ).c_str() );
}

// =================================================================================================
// IIMDataObjectNotifications.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CReferenceObjectNotificationSink::OnReferenceObjectsAdded( SAFEARRAY* uniqueIDs_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Reference Object added" );
}

STDMETHODIMP CReferenceObjectNotificationSink::OnReferenceObjectsDeleted( SAFEARRAY* uniqueIDs_ )
{
    // TODO : specialize a behavior when Reference Object were deleted
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Reference Object deleted" );
}

STDMETHODIMP CReferenceObjectNotificationSink::OnReferenceObjectsEdited( SAFEARRAY* uniqueIDs_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Reference Object edited" );
}

STDMETHODIMP CReferenceObjectNotificationSink::OnReferenceObjectsTransformed( SAFEARRAY* uniqueIDs_, ETransformTypes transformationType_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, TransformationStringGet( transformationType_ ).c_str() );
}

// =================================================================================================
// IIMDataObjectNotifications.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CInspectProjectNotificationSink::OnCurrentPieceChanged( BSTR uniqueIDs_ )
{
    return m_feedback.OnBSTRNotification( uniqueIDs_, L"Piece changed" );
}

STDMETHODIMP CInspectProjectNotificationSink::OnCurrentPieceSaved( BSTR uniqueIDs_ )
{
    return m_feedback.OnBSTRNotification( uniqueIDs_, L"Piece saved" );
}

// =================================================================================================
// IIMDataObjectGroupNotifications
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CDataObjectGroupNotificationSink::OnDataObjectGroupsAdded( SAFEARRAY* uniqueIDs_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Data Object Group added" );
}

STDMETHODIMP CDataObjectGroupNotificationSink::OnDataObjectGroupsDeleted( SAFEARRAY* uniqueIDs_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Data Object Group deleted" );
}

STDMETHODIMP CDataObjectGroupNotificationSink::OnDataObjectGroupsRenamed( SAFEARRAY* uniqueIDs_ )
{
    return m_feedback.OnSafeArrayNotification( uniqueIDs_, L"Data Object Group renamed" );
}
