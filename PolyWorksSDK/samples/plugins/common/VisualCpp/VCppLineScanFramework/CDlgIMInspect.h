#pragma once

// =================================================================================================
//   Plug-in dialog for PolyWorks|Inspector.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IMTypes.h>

#include "CDlgCompanyName.h"
#include "TooltipComboBox.h"
#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Plug-in dialog class for PolyWorks|Inspector.
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

    void DataObjectsUpdate( CEdit& dataObjectName_, CComboBox& dataObjects_, EScanTypes scanType_ );

    void ProfilesControlUpdate();

    // MFC virtual functions
    virtual void DoDataExchange( CDataExchange* pDX_ );
    BOOL         OnInitDialog() override;

    // MFC message handlers
    afx_msg void OnClickedScanType();
    afx_msg void OnClickedOptions();
    afx_msg void OnClickedRealTimeComparison();
    afx_msg void OnClickedRTQM();
    afx_msg void OnClickedRTQMPointCloud();
    afx_msg void OnClickedRTQMPolygonalModel();
    afx_msg void OnKillFocusDataObjectNameSurface();
    afx_msg void OnKillFocusDataObjectNameBoundary();
    afx_msg void OnSelChangeDataObjectsSurface();
    afx_msg void OnSelChangeDataObjectsBoundary();
    afx_msg void OnSelChangeScanProfile();
    afx_msg void OnClickedSaveAsProfile();
    afx_msg void OnClickedDeleteProfile();
    afx_msg void OnClickedClippingPlane();
    afx_msg void OnClickedClippingPlaneDefine();

    afx_msg void    OnSetFocus( CWnd* pOldWnd_ );
    afx_msg LRESULT OnUpdateProfiles( WPARAM wParam_, LPARAM lParam_ );

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    void EnableScanControls( bool enable_ ) override;

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

    TWStrings m_profileCmdArgNames;  // Profiles names
    int       m_profilesComboIndex;  // Profiles combobox index
    TWStrings m_profileTooltips;     // Profiles tooltips
    int       m_scanType;            // Radio button index for the scan type

    // Dialog controls
    CButton   m_surfaceScanType;
    CButton   m_surfaceAndBoundaryScanType;
    CButton   m_sharpEdgeScanType;
    CComboBox m_dataObjectsSurface;
    CComboBox m_dataObjectsBoundary;
    CButton   m_rtqm;
    CStatic   m_rtqmDataType;
    CButton   m_rtqmPointCloud;
    CButton   m_rtqmPolygonalModel;
    CEdit     m_dataObjectNameSurface;
    CEdit     m_dataObjectNameBoundary;
    CButton   m_realTimeComparison;
    CButton   m_clippingPlane;
    CEdit     m_clippingPlaneDateTime;
    CButton   m_clippingPlaneDefine;

    CStatic          m_staticScanningProfile;
    CTooltipComboBox m_comboScanningProfile;
    CButton          m_saveAsProfile;
    CButton          m_deleteProfile;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
