#pragma once

// =================================================================================================
//   Save As profile dialog.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "resource.h"
#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CCompanyNameScannerReceiver;

// =================================================================================================
//   Save As profile dialog class.
// -------------------------------------------------------------------------------------------------
class CDlgSaveAsProfile : public CDialog
{
    DECLARE_MESSAGE_MAP()

public:

    // Public member functions
    ////////////////////////////

    CDlgSaveAsProfile( CWnd* pParent_ = nullptr );
    virtual ~CDlgSaveAsProfile();
    void Init( CCompanyNameScannerReceiver* pReceiver_ ) { m_pReceiver = pReceiver_; }

    // Dialog Data
    enum { IDD = IDD_SAVE_AS_PROFILE };

    // MFC virtual functions
    virtual void DoDataExchange( CDataExchange* pDX_ );
    virtual BOOL OnInitDialog();
    virtual void OnOK();

    // MFC message handlers

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    // Protected member variables
    ///////////////////////////////

    CCompanyNameScannerReceiver* m_pReceiver;

private:

    // Private member functions
    /////////////////////////////

    virtual long WindowPositionXGet();
    virtual void WindowPositionXSet( long position_ );
    virtual long WindowPositionYGet();
    virtual void WindowPositionYSet( long position_ );

    // Private member variables
    /////////////////////////////

    TWStrings m_profileCmdArgNames;  // Profiles names
    TWStrings m_profileTooltips;     // Profiles tooltips

    // Dialog controls
    CComboBox m_comboUserProfile;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
