#pragma once

// =================================================================================================
// Plug-in dialog
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/Base/CWString.h>
#include <afxdialogex.h>

#include "CompanyNameConst.h"
#include "resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CCompanyNameScannerSettings;
class ICompanyNameScanner;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
//   Plug-in dialog class.
// -------------------------------------------------------------------------------------------------
class CDlgCompanyName : public CDialogEx
{
    DECLARE_DYNAMIC( CDlgCompanyName )
    DECLARE_MESSAGE_MAP()

public:
    // ---------------- Public Types  --------------------------------------------------------------

    enum class EActions
    {
        NoAction,
        Scanning,
        Modifying
    };

    // ---------------- Public Methods  ------------------------------------------------------------
    CDlgCompanyName( ICompanyNameScanner& plugin_, CCompanyNameScannerSettings& settings_, CWnd* pParent = nullptr );   // standard constructor
    virtual ~CDlgCompanyName() = default;

// Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_DIALOG_SCAN };
#endif

    // MFC virtual functions
    virtual void OnDestroy();
    virtual BOOL OnInitDialog();
    virtual void OnCancel();
    virtual void OnOK();

    // MFC message handlers
    afx_msg void OnMove( int x_, int y_ );
    afx_msg void OnBnClickedButtonModPolModel();
    afx_msg void OnKillFocusDataObjectName();

    BOOL DialogCreate();
    void DialogDestroy();
    void ControlsUpdate();
    void ControlsUpdate( EActions action_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------
    virtual void DoDataExchange( CDataExchange* pDX );    // DDX/DDV support

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    // MFC controls
    CButton m_btnScan;
    CButton m_btnClose;
    CButton m_btnModify;
    CButton m_newDevicePositionOnScan;
    CEdit   m_dataObjectName;

    // Initialization flag
    bool m_dialogInitialized = false;

    // Current action
    EActions m_action = EActions::NoAction;

    // Settings of the plug-in
    CCompanyNameScannerSettings& m_settings;

    // Interface to the plug-in
    ICompanyNameScanner& m_plugin;

public:
    afx_msg void OnClickCreateNewDevicePositionOnScan();
};
