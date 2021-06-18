#pragma once

// =================================================================================================
//   Plug-in base dialog.
//
// Copyright © InnovMetric Softwares Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "CIMDlgOptionsBase.h"
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
class CDlgIMAlignOptions : public CIMDlgOptionsBase
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

    // MFC virtual functions

    // MFC message handlers

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////
    void PropertyEnableUpdate( DWORD propertyData_, BOOL enable_ ) override;

    // Protected member variables
    ///////////////////////////////

private:

    // Private member functions
    /////////////////////////////
    void PropertyGridGeneralInit();
    void PropertyGridSurfaceScanInit();
    void PropertyGridFilteringInit();

    long WindowPositionXGet() override;
    void WindowPositionXSet( long position_ ) override;
    long WindowPositionYGet() override;
    void WindowPositionYSet( long position_ ) override;

    void TreeViewInit() override;
    void PropertyGridInit( HTREEITEM selectedItem_ ) override;

    // Private member variables
    /////////////////////////////
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
