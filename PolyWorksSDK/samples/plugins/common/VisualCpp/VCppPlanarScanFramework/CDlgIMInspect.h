#pragma once

// =================================================================================================
//   Plug-in dialog for IMInspect.
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
//   Plug-in dialog class for IMInspect.
// -------------------------------------------------------------------------------------------------
class CDlgIMInspect : public CDlgCompanyName
{
    DECLARE_MESSAGE_MAP()

public:

    // Public member functions
    ////////////////////////////

    CDlgIMInspect( CWnd* pParent_ = nullptr );
    virtual ~CDlgIMInspect();

    // Dialog Data
    enum { IDD = IDD_COMPANYNAME_INSPECT };

    bool ScanEnd() override;

    bool DialogCreate() override;
    void DialogUpdate() override;

    // MFC virtual functions
    virtual void DoDataExchange( CDataExchange* pDX_ );
    virtual BOOL OnInitDialog();

    // MFC message handlers
    afx_msg void OnClickCreateNewDevicePositionOnScan();
    afx_msg void OnClickedPointCloudDataStructure();
    afx_msg void OnClickedPolygonalDataStructure();
    afx_msg void OnClickedUseAutomaticViewpoint();
    afx_msg void OnKillFocusDataObjectName();

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    void EnableScanControls( bool enable_ ) override;
    void CompagnyNameCreateNewDevicePosition() override;
    // Protected member variables
    ///////////////////////////////

private:

    // Private member functions
    /////////////////////////////

    const wchar_t* DefaultNameSurfaceScanCmdNameGet() const;

    long WindowPositionXGet() override;
    void WindowPositionXSet( long position_ ) override;
    long WindowPositionYGet() override;
    void WindowPositionYSet( long position_ ) override;

    // Private member variables
    /////////////////////////////

    bool m_isChangingDataStructOnCreateNew;

    // Dialog controls
    CEdit   m_dataObjectName;
    CButton m_pointCloudDataStructure;
    CButton m_polygonalDataStructure;
    CButton m_useAutomaticViewpoint;
    CButton m_createNewDevicePositionOnScanButton;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
