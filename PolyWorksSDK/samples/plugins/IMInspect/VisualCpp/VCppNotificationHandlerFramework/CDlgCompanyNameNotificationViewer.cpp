// =================================================================================================
//   ClgCompanyNameNotificationViewer.cpp : implementation file
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CDlgCompanyNameNotificationViewer.h"

#include <PolyWorksSDK/UI/FnDialog.h>
#include <afxdialogex.h>
#include <afxwin.h>
#include <CompanyNameNotificationHandler.h>
#include <iosfwd>
#include <sstream>

#include "Resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

constexpr wchar_t* const DATA_OBJECT_NOTIFICATION_NAME       = L"Data Object Notification";
constexpr wchar_t* const DATA_OBJECT_GROUP_NOTIFICATION_NAME = L"Data Object Group Notification";
constexpr wchar_t* const REFERENCE_OBJECT_NOTIFICATION_NAME  = L"Reference Object Notification";
constexpr wchar_t* const INSPECTOR_PROJECT_NOTIFICATION_NAME = L"Inspector Project Notification";

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// Converts a bool to an int mapped to checked state
// -------------------------------------------------------------------------------------------------
static int BoolToCheckedState( bool checked_ )
{
    return checked_ ? BST_CHECKED : BST_UNCHECKED;
}

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// ClgCompanyNameNotificationViewer dialog

IMPLEMENT_DYNAMIC( CDlgCompanyNameNotificationViewer, CDialogEx )

// =================================================================================================
// Constructor.
//
// Parameter: notificationManager_ : class
// Parameter: pParent_ : Parent window. NULL by default
// -------------------------------------------------------------------------------------------------
CDlgCompanyNameNotificationViewer::CDlgCompanyNameNotificationViewer( INotificationActivationManager& notificationManager_, CWnd* pParent /*=nullptr*/ )
: CDialogEx( IDD_COMPANYNAMENOTIFICATIONHANDLERDIALOG, pParent )
, m_notificationManager{ notificationManager_ }
{
}

// =================================================================================================
// Destructor
// -------------------------------------------------------------------------------------------------
CDlgCompanyNameNotificationViewer::~CDlgCompanyNameNotificationViewer() = default;

// =================================================================================================
// MSDN Documentation:
// Called by the framework to exchange and validate dialog data.
//
// Parameter: pDX_ : A pointer to a CDataExchange object
// -------------------------------------------------------------------------------------------------
void CDlgCompanyNameNotificationViewer::DoDataExchange( CDataExchange* pDX_ )
{
    CDialogEx::DoDataExchange( pDX_ );
    DDX_Control( pDX_, IDC_NOTIFICATION_ACTIVATION_CHECK, m_canReceiveNotification );
    DDX_Control( pDX_, IDC_LIST_EVENT,                    m_notificationLog );
    DDX_Control( pDX_, IDC_NOTIFICATION_DROPDOWN,         m_notification );
    DDX_Control( pDX_, IDC_LIST_UNIQUE_ID,                m_uniqueIDLog );
}


BEGIN_MESSAGE_MAP( CDlgCompanyNameNotificationViewer, CDialogEx )
    ON_CBN_SELCHANGE( IDC_NOTIFICATION_DROPDOWN, &CDlgCompanyNameNotificationViewer::OnNotificationSelChange )
    ON_BN_CLICKED( IDC_NOTIFICATION_ACTIVATION_CHECK, &CDlgCompanyNameNotificationViewer::OnNotificationClickedCheck )
    ON_WM_CLOSE()
END_MESSAGE_MAP()

// ClgCompanyNameNotificationViewer message handlers

// =================================================================================================
// Update notification activation state when notification is selected in dropdown
// -------------------------------------------------------------------------------------------------
void CDlgCompanyNameNotificationViewer::OnNotificationSelChange()
{
    m_notificationIndex = m_notification.GetCurSel();
    const ENotificationType notification = static_cast< ENotificationType >( m_notificationIndex );
    const bool isChecked                 = m_notificationManager.NotificationActivationStateGet( notification );
    m_canReceiveNotification.SetCheck( BoolToCheckedState( isChecked ) );
}

// =================================================================================================
// Change notification activation state
// -------------------------------------------------------------------------------------------------
void CDlgCompanyNameNotificationViewer::OnNotificationClickedCheck()
{
    m_notificationManager.NotificationActivationStateSet(
        static_cast< ENotificationType >( m_notificationIndex ),
        m_canReceiveNotification.GetCheck() == BST_CHECKED );
}

// =================================================================================================
// Change internal visible flag if dialog was not close by command
// -------------------------------------------------------------------------------------------------
void CDlgCompanyNameNotificationViewer::OnClose()
{
    m_isDlgVisible = false;
    __super::OnClose();
}

// =================================================================================================
// Update the dialog's dropdown with notification display names
// -------------------------------------------------------------------------------------------------
void CDlgCompanyNameNotificationViewer::FillNotificationDropdown()
{
    std::vector< std::wstring > notificationNames;
    notificationNames.resize( static_cast< size_t >( ENotificationType::E_COUNT ) );
    notificationNames[ static_cast< size_t >( ENotificationType::E_DATA_OBJECT ) ]       = DATA_OBJECT_NOTIFICATION_NAME;
    notificationNames[ static_cast< size_t >( ENotificationType::E_REFERENCE_OBJECT ) ]  = REFERENCE_OBJECT_NOTIFICATION_NAME;
    notificationNames[ static_cast< size_t >( ENotificationType::E_INSPECTOR_PROJECT ) ] = INSPECTOR_PROJECT_NOTIFICATION_NAME;
    notificationNames[ static_cast< size_t >( ENotificationType::E_DATA_OBJECT_GROUP ) ] = DATA_OBJECT_GROUP_NOTIFICATION_NAME;
    m_notification.ResetContent();
    for ( const std::wstring& notification : notificationNames )
    {
        m_notification.AddString( notification.c_str() );
    }
    m_notification.SetCurSel( m_notificationIndex );
}

// =================================================================================================
// Update the notification log with new notification content
// -------------------------------------------------------------------------------------------------
void CDlgCompanyNameNotificationViewer::OnNotificationReceived(
    const std::wstring& notification_,
    const std::wstring& uniqueID_ )
{
    m_notificationLog.AddString( notification_.c_str() );
    m_uniqueIDLog.AddString( uniqueID_.c_str() );
}
