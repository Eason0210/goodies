#pragma once

// =================================================================================================
//   Feedback interface that wraps receiving a notification.
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class INotificationFeedback;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   CCompanyNameNotificationHandler
//   Allows an object to send the received notification content to an INotificationFeedback
// -------------------------------------------------------------------------------------------------
class CCompanyNameNotificationFeedback final
{
public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CCompanyNameNotificationFeedback()          = default;
    virtual ~CCompanyNameNotificationFeedback() = default;

    void    Init( INotificationFeedback& feedback_ ) { m_pFeedback = &feedback_; }
    HRESULT OnSafeArrayNotification( SAFEARRAY* uniqueIDs_, std::wstring&& msg_ );
    HRESULT OnBSTRNotification( BSTR uniqueID_, std::wstring&& msg_ );

private:
    // ---------------- Private Member Variables ---------------------------------------------------
    INotificationFeedback* m_pFeedback;
};
