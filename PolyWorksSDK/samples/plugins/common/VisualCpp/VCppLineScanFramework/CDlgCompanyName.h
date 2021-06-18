#pragma once

// =================================================================================================
//   Plug-in base dialog.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "CompanyNameConst.h"
#include "resource.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CCompanyNameScannerReceiver;
struct IIMCommandCenter;
struct IIMLineScan;

#define WM_COMP_NAME_PLUGIN_UPDATE_PROFILES ( WM_APP + 400 )

// =================================================================================================
//   Plug-in base dialog class.
// -------------------------------------------------------------------------------------------------
class CDlgCompanyName : public CDialog
{
    DECLARE_DYNAMIC( CDlgCompanyName )
    DECLARE_MESSAGE_MAP()

public:

    // Public member functions
    ////////////////////////////

    CDlgCompanyName( UINT IDD_, CWnd* pParent_ = nullptr );
    virtual ~CDlgCompanyName();

    virtual bool DialogCreate() = 0;
    virtual void DialogDestroy();
    virtual void DialogUpdate();

    void Init( CCompanyNameScannerReceiver* pReceiver_ ) { m_pReceiver = pReceiver_; }
    bool IsInit()                                        { return m_pReceiver != nullptr ? true : false; }
    bool IsScanning()                                    { return m_scanIsStarted; }
    void Uninit();

    virtual void Observe( EEvents event_ );

    void Popdown();
    void Popup();

    void PreCreate();
    void PreDestroy();

    virtual bool ScanEnd();
    virtual bool ScanStart();

    // MFC virtual functions
    virtual void OnDestroy();
    virtual BOOL OnInitDialog();
    virtual void OnCancel();
    virtual void OnOK();
    virtual void DoDataExchange( CDataExchange* pDX_ );

    // MFC message handlers
    afx_msg void OnClickedTestMode();
    afx_msg void OnMove( int x_, int y_ );

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    virtual void EnableScanControls( bool enable_ ) = 0;
    bool         CompanyNameDialogCreate();
    void         CompanyNameEnableScanControls( bool enable_ );

    // Protected member variables
    ///////////////////////////////

    CCompanyNameScannerReceiver* m_pReceiver;

private:

    // Private member functions
    /////////////////////////////

    virtual long WindowPositionXGet()                 = 0;
    virtual void WindowPositionXSet( long position_ ) = 0;
    virtual long WindowPositionYGet()                 = 0;
    virtual void WindowPositionYSet( long position_ ) = 0;

    void WindowStyleSet();

    // Private member variables
    /////////////////////////////

    bool m_scanIsStarted     = false;
    bool m_dialogInitialized = false;

    // Dialog controls
    CButton m_testMode;
    CButton m_startScanButton;
    CButton m_closeButton;
    CButton m_optionsButton;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
