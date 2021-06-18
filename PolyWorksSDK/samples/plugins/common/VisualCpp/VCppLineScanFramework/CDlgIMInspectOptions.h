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
//   Plug-in base dialog class
// -------------------------------------------------------------------------------------------------
class CDlgIMInspectOptions : public CIMDlgOptionsBase
{
    DECLARE_DYNAMIC( CDlgIMInspectOptions )
    DECLARE_MESSAGE_MAP()

public:

    // Public member functions
    ////////////////////////////

    CDlgIMInspectOptions( CWnd* pParent_ = nullptr );
    virtual ~CDlgIMInspectOptions();

    // Dialog Data
    enum { IDD = IDD_OPTIONS_INSPECT };

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
    void PropertyGridHoleBoundaryScanInit();
    void PropertyGridGeneralInit();
    void PropertyGridRealTimeQualityMeshingInit();
    void PropertyGridRTMPolygonalModelsInit();
    void PropertyGridRTMQualityMetricsInit();
    void PropertyGridFilteringInit();
    void PropertyGridSurfaceScanInit();
    void PropertyGridSharpEdgeScanInit();

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
