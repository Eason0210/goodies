#pragma once

// =================================================================================================
//   Plug-in base dialog.
//
// Copyright © InnovMetric Softwares Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "resource.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Plug-in base dialog class.
// -------------------------------------------------------------------------------------------------
class CDlgIMAlignOptions : public CDialog
{
    DECLARE_DYNAMIC( CDlgIMAlignOptions )
    DECLARE_MESSAGE_MAP()

public:

    // Public member functions
    ////////////////////////////

    CDlgIMAlignOptions( CWnd* pParent_ = nullptr );
    virtual ~CDlgIMAlignOptions();

    // Dialog Data
    enum { IDD = IDD_OPTIONS_ALIGN };

    virtual void DialogUpdate();

    // MFC virtual functions
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    virtual void DoDataExchange( CDataExchange* pDX_ );

    // MFC message handlers
    afx_msg void OnMove( int x_, int y_ );

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    // Protected member variables
    ///////////////////////////////

private:

    // Private member functions
    /////////////////////////////

    long WindowPositionXGet();
    void WindowPositionXSet( long position_ );
    long WindowPositionYGet();
    void WindowPositionYSet( long position_ );

    // Private member variables
    /////////////////////////////

    bool m_dialogInitialized;

    // Dialog Controls
    CEdit m_maxEdgeLength;
    CEdit m_interpolationStep;
    CEdit m_maxAngle;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
