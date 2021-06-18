#pragma once

// =================================================================================================
//   Plug-in dialog for IMAlign.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "CDlgCompanyName.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Plug-in dialog class for IMAlign.
// -------------------------------------------------------------------------------------------------
class CDlgIMAlign : public CDlgCompanyName
{
    DECLARE_MESSAGE_MAP()

public:

    // Public member functions
    ////////////////////////////

    CDlgIMAlign( CWnd* pParent_ = nullptr );
    virtual ~CDlgIMAlign();

    // Dialog Data
    enum { IDD = IDD_COMPANYNAME_ALIGN };

    void UpdateNbPoints( int nbPoints_ );

    bool DialogCreate() override;
    void DialogUpdate() override;

    // MFC virtual functions
    virtual void DoDataExchange( CDataExchange* pDX_ );
    virtual BOOL OnInitDialog();

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    void EnableScanControls( bool enable_ ) override;

    // MFC message handlers
    afx_msg void OnClickedOptions();
    afx_msg void OnKillFocusScanName();

    // Protected member variables
    ///////////////////////////////

private:

    // Private member functions
    /////////////////////////////

    long WindowPositionXGet() override;
    void WindowPositionXSet( long position_ ) override;
    long WindowPositionYGet() override;
    void WindowPositionYSet( long position_ ) override;

    // Private member variables
    /////////////////////////////

    // Dialog controls
    CEdit   m_scanName;
    CEdit   m_nbPoints;
    CButton m_optionsButton;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
