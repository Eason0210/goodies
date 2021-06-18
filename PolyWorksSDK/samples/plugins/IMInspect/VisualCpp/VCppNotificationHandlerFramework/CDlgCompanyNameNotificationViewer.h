#pragma once
// =================================================================================================
//   Plug-in dialog for PolyWorks|Inspector.
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CCompanyNameNotificationHandlerConnectionPoint.h"
#include "CCompanyNameNotificationHandlerPlugin.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class INotificationActivationManager;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Plug-in dialog class for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
class CDlgCompanyNameNotificationViewer final : public CDialogEx
{
    DECLARE_DYNAMIC( CDlgCompanyNameNotificationViewer )

public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CDlgCompanyNameNotificationViewer( INotificationActivationManager& notificationManager_,
                                       CWnd*                           pParent = nullptr ); // standard constructor
    virtual ~CDlgCompanyNameNotificationViewer();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_COMPANYNAMENOTIFICATIONHANDLERDIALOG };
#endif

    afx_msg void OnNotificationSelChange();
    afx_msg void OnNotificationClickedCheck();
    afx_msg void OnClose();

    void        FillNotificationDropdown();
    void        OnNotificationReceived( const std::wstring& notification_, const std::wstring& uniqueID_ );
    inline bool IsVisibleGet() const            { return m_isDlgVisible; }
    inline bool IsVisibleSet( bool isVisible_ ) { return m_isDlgVisible = isVisible_; }
protected:
    // ---------------- Protected Methods ----------------------------------------------------------
    virtual void DoDataExchange( CDataExchange* pDX );    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
private:
    // ---------------- Private Member Variables ---------------------------------------------------
    int                             m_notificationIndex = 0;
    INotificationActivationManager& m_notificationManager;

    // Dialog controls
    CListBox  m_notificationLog;
    CListBox  m_uniqueIDLog;
    CButton   m_canReceiveNotification;
    CComboBox m_notification;
    bool      m_isDlgVisible = false;
};
