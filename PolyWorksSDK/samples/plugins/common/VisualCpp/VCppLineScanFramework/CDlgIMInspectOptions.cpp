// =================================================================================================
//   Plug-in dialog base class implementation.
//
// Copyright © InnovMetric Softwares Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CDlgIMInspectOptions.h"

#include "CCompanyNameScannerSettings.h"
#include "CIMPropertyGridCheckBoxProperty.h"
#include "CIMPropertyGridColorProperty.h"
#include "CIMPropertyGridCtrl.h"
#include "CIMPropertyGridProperty.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

enum EPropertyPage
{
    E_PROPERTY_PAGE_GENERAL = 0,
    E_PROPERTY_PAGE_SURFACE_SCAN,
    E_PROPERTY_PAGE_REAL_TIME_QUALITY_MESHING,
    E_PROPERTY_PAGE_POLYGONAL_MODELS,
    E_PROPERTY_PAGE_QUALITY_METRICS,
    E_PROPERTY_PAGE_FILTERING,
    E_PROPERTY_PAGE_HOLE_BOUNDARY_SCAN,
    E_PROPERTY_PAGE_SHARP_EDGE_SCAN,

    E_PROPERTY_PAGE_NB
};

enum EPropertyValue
{
    // General
    E_PROPERTY_VALUE_USE_AUDIO_FEEDBACK,
    E_PROPERTY_VALUE_USE_AUTOMATIC_VIEWPOINT,
    E_PROPERTY_VALUE_DEVICE_VERTICAL_AXIS,
    E_PROPERTY_VALUE_STANDARD_ZOOM,
    E_PROPERTY_VALUE_FEATURE_SCANNING_GUIDANCE_ZOOM,
    E_PROPERTY_VALUE_USE_PARALLEL_PROCESSING,
    E_PROPERTY_VALUE_USE_PRIORITIZE_ACQUISITION_SPEED,
    E_PROPERTY_VALUE_MESHING_SPEED,
    E_PROPERTY_VALUE_USE_FEATURE_SCANNING_GUIDANCE,
    E_PROPERTY_VALUE_SURFACE_HIGHLIGHT_COLOR,
    E_PROPERTY_VALUE_BOUNDARY_HIGHLIGHT_COLOR,
    // Surface Scan
    E_PROPERTY_VALUE_SPLIT_ZIGZAG_SCAN_PASSES,
    E_PROPERTY_VALUE_USE_EXTRACT_NORMAL_VECTORS,
    E_PROPERTY_VALUE_MIN_SEARCH_DISTANCE,
    E_PROPERTY_VALUE_MAX_SEARCH_DISTANCE,
    // Surface Scan >> Real-Time Quality Meshing
    E_PROPERTY_VALUE_SAMPLING_STEP,
    E_PROPERTY_VALUE_MAX_EDGE_LENGTH,
    E_PROPERTY_VALUE_MAX_ANGLE,
    E_PROPERTY_VALUE_RTM_MAX_DISTANCE,
    E_PROPERTY_VALUE_RTM_NUMBER_OF_BLENDING_STEPS,
    // Surface Scan >> Real-Time Quality Meshing >> Polygonal Models
    E_PROPERTY_VALUE_RTM_SMOOTH,
    E_PROPERTY_VALUE_RTM_SMOOTH_LEVEL,
    E_PROPERTY_VALUE_RTM_SMOOTH_CUSTOM_LEVEL_RADIUS,
    E_PROPERTY_VALUE_RTM_SMOOTH_CONSTRAIN_DISPLACEMENT,
    E_PROPERTY_VALUE_RTM_SMOOTH_MAX_DISPLACEMENT,
    E_PROPERTY_VALUE_RTM_SMOOTH_PRESERVE_FEATURES,
    E_PROPERTY_VALUE_RTM_REDUCE,
    E_PROPERTY_VALUE_RTM_REDUCE_LEVEL,
    E_PROPERTY_VALUE_RTM_REDUCE_CUSTOM_METHOD,
    E_PROPERTY_VALUE_RTM_REDUCE_CUSTOM_TOLERANCE,
    E_PROPERTY_VALUE_RTM_REDUCE_CUSTOM_REMAINING_PERCENT,
    E_PROPERTY_VALUE_RTM_REDUCE_CUSTOM_REMAINING_TRIANGLES,
    E_PROPERTY_VALUE_RTM_REDUCE_CONSTRAIN_EDGE_LENGTH,
    E_PROPERTY_VALUE_RTM_REDUCE_CONSTRAIN_MAX_EDGE_LENGTH,
    E_PROPERTY_VALUE_RTM_REDUCE_PREREDUCTION_TOLERANCE,
    // Surface Scan >> Real-Time Quality Meshing >> Quality Metrics
    E_PROPERTY_VALUE_RTM_DETECT_MISALIGNED_SCAN_PASSES,
    E_PROPERTY_VALUE_RTM_MAX_AVERAGE_DEVIATION,
    E_PROPERTY_VALUE_RTM_BEHAVIOR_WHEN_MISALIGNED,
    E_PROPERTY_VALUE_RTM_HIGH_SCANNER_TO_SURFACE_NORMAL_ANGLE,
    E_PROPERTY_VALUE_RTM_HIGHLIGHT_MAX_ANGLE,
    E_PROPERTY_VALUE_RTM_HIGHLIGHT_MAX_ANGLE_COLOR,
    E_PROPERTY_VALUE_RTM_LOW_SCAN_DENSITY_FOR_CURVATURE,
    E_PROPERTY_VALUE_RTM_MAX_DEVIATION_SURFACE,
    E_PROPERTY_VALUE_RTM_MAX_DEVIATION_SURFACE_COLOR,
    E_PROPERTY_VALUE_RTM_HIGH_NOISE_LEVEL,
    E_PROPERTY_VALUE_RTM_STANDARD_DEVIATION_THRESHOLD,
    E_PROPERTY_VALUE_RTM_STANDARD_DEVIATION_THRESHOLD_COLOR,
    // Filtering >> Filter scan lines
    E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES,
    E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES_STANDARD_DEVIATION,
    E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES_MAX_POINT_TO_POINT_DISTANCE,
    // Filtering >> Clipping plane
    E_PROPERTY_VALUE_FILTERING_CLIPPING_PLANE_REJECTION_DIST,
    // Surface and Boundary Scan
    E_PROPERTY_VALUE_MIN_HOLE_WIDTH,
    E_PROPERTY_VALUE_EXTERNAL_BOUNDARY_DETECTION,
    // Sharp Edge Scan
    E_PROPERTY_VALUE_EDGE_MAX_POINT_TO_POINT_DISTANCE,
    E_PROPERTY_VALUE_EDGE_MIN_ANGLE,

    E_PROPERTY_VALUE_NB
};

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

IMPLEMENT_DYNAMIC( CDlgIMInspectOptions, CIMDlgOptionsBase )

// =================================================================================================
// Message map.
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CDlgIMInspectOptions, CIMDlgOptionsBase )
END_MESSAGE_MAP()

// =================================================================================================
//   Ctor.
// -------------------------------------------------------------------------------------------------
CDlgIMInspectOptions::CDlgIMInspectOptions( CWnd* pParent_ /*=nullptr*/ )
: CIMDlgOptionsBase( IDD, pParent_ )
{
    // General
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Audio feedback",                                  L"DIGITIZE LINE_SCAN AUDIO_FEEDBACK" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Automatic viewpoint",                             g_cmdAutoViewpointSet );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_STRING, L"Device vertical axis",                            g_cmdAutoViewpointVerticalAxisSet );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_LONG,   L"Standard zoom (%)",                               g_cmdAutoViewpointCloseUpZoomSet );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_LONG,   L"Feature scanning guidance zoom (%)",              L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM FEATURE_SCANNING_GUIDANCE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Parallel processing",                             L"DIGITIZE LINE_SCAN PARALLEL_PROCESSING" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Prioritize acquisition speed over meshing speed", L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING PRIORITIZE_ACQUISITION_SPEED" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_STRING, L"Meshing speed",                                   L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING PRIORITIZE_ACQUISITION_SPEED MESHING_SPEED" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Feature scanning guidance",                       L"DIGITIZE LINE_SCAN FEATURE_SCANNING_GUIDANCE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_COLOR,  L"Surface highlight color",                         L"DIGITIZE LINE_SCAN FEATURE_SCANNING_GUIDANCE HIGHLIGHT_COLOR SURFACE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_COLOR,  L"Boundary highlight color",                        L"DIGITIZE LINE_SCAN FEATURE_SCANNING_GUIDANCE HIGHLIGHT_COLOR BOUNDARY" );
    // Surface Scan
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Split zigzag scan passes", L"DIGITIZE DEVICE SCAN SURFACE SPLIT_ZIGZAG_SCAN_PASSES" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Extract normal vectors",   L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Min search distance",      L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MIN_SEARCH_DISTANCE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max search distance",      L"DIGITIZE DEVICE SCAN SURFACE EXTRACT_NORMAL_VECTORS MAX_SEARCH_DISTANCE" );
    // Surface Scan >> Real-Time Quality Meshing
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Sampling step",            L"DATA SURFACE OPTIONS SCAN MESHING SAMPLING_STEP" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max edge length",          L"DATA SURFACE OPTIONS SCAN MESHING MAX_EDGE_LENGTH" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max angle",                L"DATA OPTIONS SCAN MESHING MAX_ANGLE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max distance",             L"DATA OPTIONS SCAN MESHING SCAN_PASS_MERGING MAX_DISTANCE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_LONG,   L"Number of blending steps", L"DATA OPTIONS SCAN MESHING SCAN_PASS_MERGING NB_BLENDING_STEPS" );
    // Surface Scan >> Real-Time Quality Meshing >> Polygonal Models
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Smooth",                            L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_STRING, L"Level",                             L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH LEVEL" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Custom level radius",               L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH LEVEL CUSTOM RADIUS" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Constrain displacement",            L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH USE_MAX_DISPLACEMENT" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max displacement",                  L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH MAX_DISPLACEMENT" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Preserve features",                 L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH PRESERVE_FEATURES" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Reduce",                            L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_STRING, L"Level",                             L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_STRING, L"Method",                            L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL CUSTOM METHOD" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Tolerance",                         L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL CUSTOM TOLERANCE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Remaining percentage of triangles", L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL CUSTOM REMAINING_PERCENTAGE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_LONG,   L"Remaining number of triangles",     L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL CUSTOM REMAINING_TRIANGLES" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Constrain edge length",             L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE USE_MAX_EDGE_LENGTH" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max edge length",                   L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE MAX_EDGE_LENGTH" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Prereduction tolerance",            L"DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE PREREDUCTION TOLERANCE" );
    // Surface Scan >> Real-Time Quality Meshing >> Quality Metrics
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Detect misaligned scan passes",        L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS DETECT_MISALIGNED_SCAN_PASSES" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max average deviation",                L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS DETECT_MISALIGNED_SCAN_PASSES MAX_AVERAGE_DEVIATION" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_STRING, L"Behavior when misaligned",             L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS DETECT_MISALIGNED_SCAN_PASSES BEHAVIOR" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"High scanner-to-surface-normal angle", L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES HIGH_SCANNER_TO_SURFACE_NORMAL_ANGLE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max angle",                            L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES HIGH_SCANNER_TO_SURFACE_NORMAL_ANGLE MAX_ANGLE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_COLOR,  L"Color",                                L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES HIGH_SCANNER_TO_SURFACE_NORMAL_ANGLE COLOR" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Low scan density for mesh curvature",  L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES LOW_SCAN_DENSITY_FOR_MESH_CURVATURE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max deviation to surface",             L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES LOW_SCAN_DENSITY_FOR_MESH_CURVATURE MAX_DEVIATION_TO_SURFACE" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_COLOR,  L"Color",                                L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES LOW_SCAN_DENSITY_FOR_MESH_CURVATURE COLOR" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"High noise level",                     L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES HIGH_NOISE_LEVEL" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Standard deviation threshold",         L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES HIGH_NOISE_LEVEL THRESHOLD" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_COLOR,  L"Color",                                L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES HIGH_NOISE_LEVEL COLOR" );
    // Filtering >> Filter scan lines
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"Filter scan lines",           L"DIGITIZE LINE_SCAN SCAN_LINE_FILTER" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Standard deviation",          L"DIGITIZE LINE_SCAN SCAN_LINE_FILTER STANDARD_DEVIATION" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max point-to-point distance", L"DIGITIZE LINE_SCAN SCAN_LINE_FILTER MAX_POINT_TO_POINT_DIST" );
    // Filtering >> Clipping plane
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Point rejection distance above plane", L"DIGITIZE LINE_SCAN SURFACE CLIPPING_PLANE POINT_REJECTION_DISTANCE" );
    // Surface and Boundary Scan
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Min hole width",              L"DIGITIZE DEVICE SCAN SURFACE_AND_BOUNDARY INTERNAL_BOUNDARIES MIN_HOLE_WIDTH" );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_BOOL,   L"External boundary detection", L"DIGITIZE DEVICE SCAN SURFACE_AND_BOUNDARY EXTERNAL_BOUNDARIES" );
    // Sharp Edge Scan
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Max point-to-point distance", g_cmdSharpEdgeMaxPointToPointDistSet );
    m_propertyValues.emplace_back( E_PROPERTY_TYPE_DOUBLE, L"Min angle",                   g_cmdSharpEdgeMinAngleSet );
}


// =================================================================================================
//   Dtor.
// -------------------------------------------------------------------------------------------------
CDlgIMInspectOptions::~CDlgIMInspectOptions()
{

}

// =================================================================================================
//   Initialize the treeview
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::TreeViewInit()
{
    HTREEITEM hGeneral     = PropertyPageAdd( E_PROPERTY_PAGE_GENERAL,                   L"General" );
    HTREEITEM hSurfaceScan = PropertyPageAdd( E_PROPERTY_PAGE_SURFACE_SCAN,              L"Surface Scan" );
    HTREEITEM hRTM         = PropertyPageAdd( E_PROPERTY_PAGE_REAL_TIME_QUALITY_MESHING, L"Real-Time Quality Meshing", hSurfaceScan );
    PropertyPageAdd( E_PROPERTY_PAGE_POLYGONAL_MODELS,   L"Polygonal Models", hRTM );
    PropertyPageAdd( E_PROPERTY_PAGE_QUALITY_METRICS,    L"Quality Metrics",  hRTM );
    PropertyPageAdd( E_PROPERTY_PAGE_FILTERING,          L"Filtering",        hSurfaceScan );
    PropertyPageAdd( E_PROPERTY_PAGE_HOLE_BOUNDARY_SCAN, L"Surface and Boundary Scan" );
    PropertyPageAdd( E_PROPERTY_PAGE_SHARP_EDGE_SCAN,    L"Sharp Edge Scan" );

    m_pPropertyTree->Expand( hSurfaceScan, TVE_EXPAND );
    m_pPropertyTree->Expand( hRTM,         TVE_EXPAND );

    // Select the first item
    m_pPropertyTree->SelectItem( hGeneral );
}

// =================================================================================================
//   Initialize the property grid
//
// Parameter : selectedItem_ : Selected item of the treeview
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridInit( HTREEITEM selectedItem_ )
{
    m_pPropertyGridCtrl->RemoveAll();

    // Set the witdh of the first column
    HDITEM hdItem;
    hdItem.mask = HDI_WIDTH;
    hdItem.cxy  = 300;
    m_pPropertyGridCtrl->GetHeaderCtrl().SetItem( 0, &hdItem );

    auto propertyPageItr = m_propertyPageMap.find( selectedItem_ );
    if ( propertyPageItr != m_propertyPageMap.end() )
    {
        switch ( propertyPageItr->second )
        {
            case E_PROPERTY_PAGE_GENERAL:
                PropertyGridGeneralInit();
                break;
            case E_PROPERTY_PAGE_SURFACE_SCAN:
                PropertyGridSurfaceScanInit();
                break;
            case E_PROPERTY_PAGE_REAL_TIME_QUALITY_MESHING:
                PropertyGridRealTimeQualityMeshingInit();
                break;
            case E_PROPERTY_PAGE_POLYGONAL_MODELS:
                PropertyGridRTMPolygonalModelsInit();
                break;
            case E_PROPERTY_PAGE_QUALITY_METRICS:
                PropertyGridRTMQualityMetricsInit();
                break;
            case E_PROPERTY_PAGE_FILTERING:
                PropertyGridFilteringInit();
                break;
            case E_PROPERTY_PAGE_HOLE_BOUNDARY_SCAN:
                PropertyGridHoleBoundaryScanInit();
                break;
            case E_PROPERTY_PAGE_SHARP_EDGE_SCAN:
                PropertyGridSharpEdgeScanInit();
                break;
            default: // Unsupported
                ASSERT( FALSE );
                m_pPropertyGridCtrl->Invalidate();
                break;
        }
    }
}

// =================================================================================================
//   Initialize the General property grid
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridGeneralInit()
{
    // Utilities
    // ---------
    CIMPropertyGridProperty* pUtilitiesGroup = MakePropertyGroup( L"Utilities" );
    m_pPropertyGridCtrl->AddProperty( pUtilitiesGroup );
    pUtilitiesGroup->AddSubItem( MakePropertyValue< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_USE_AUDIO_FEEDBACK ) );

    // Automatic viewpoint
    // -------------------
    auto* pUseAutomaticViewpointGroup =
        MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_USE_AUTOMATIC_VIEWPOINT );
    m_pPropertyGridCtrl->AddProperty( pUseAutomaticViewpointGroup );

    TWStrings verticalAxis;
    verticalAxis.emplace_back( L"+X" );
    verticalAxis.emplace_back( L"-X" );
    verticalAxis.emplace_back( L"+Y" );
    verticalAxis.emplace_back( L"-Y" );
    verticalAxis.emplace_back( L"+Z" );
    verticalAxis.emplace_back( L"-Z" );
    pUseAutomaticViewpointGroup->AddSubItem( MakePropertyComboValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_DEVICE_VERTICAL_AXIS, verticalAxis, FALSE ) );

    // Scan line close-up
    // ------------------
    CIMPropertyGridProperty* pScanLineCloseUp = MakePropertyGroup( L"Scan line close-up" );
    pUseAutomaticViewpointGroup->AddSubItem( pScanLineCloseUp );
    pScanLineCloseUp->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_STANDARD_ZOOM ) );
    pScanLineCloseUp->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_FEATURE_SCANNING_GUIDANCE_ZOOM ) );

    // Data processing
    // ---------------
    CIMPropertyGridProperty* pDataProcessingGroup = MakePropertyGroup( L"Data processing" );
    m_pPropertyGridCtrl->AddProperty( pDataProcessingGroup );

    pDataProcessingGroup->AddSubItem( MakePropertyValue< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_USE_PARALLEL_PROCESSING ) );
    auto* pPrioritizeAcquisitionSpeedGroup = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_USE_PRIORITIZE_ACQUISITION_SPEED );
    pDataProcessingGroup->AddSubItem( pPrioritizeAcquisitionSpeedGroup );
    TWStrings meshingSpeed;
    meshingSpeed.emplace_back( L"Low" );
    meshingSpeed.emplace_back( L"Medium" );
    pPrioritizeAcquisitionSpeedGroup->AddSubItem( MakePropertyComboValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_MESHING_SPEED, meshingSpeed, FALSE ) );

    // Feature scanning guidance
    // -------------------------
    auto* pFeatureScanGuidanceGroup =
        MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_USE_FEATURE_SCANNING_GUIDANCE );
    m_pPropertyGridCtrl->AddProperty( pFeatureScanGuidanceGroup );

    pFeatureScanGuidanceGroup->AddSubItem( MakePropertyColorValue( E_PROPERTY_VALUE_SURFACE_HIGHLIGHT_COLOR ) );
    pFeatureScanGuidanceGroup->AddSubItem( MakePropertyColorValue( E_PROPERTY_VALUE_BOUNDARY_HIGHLIGHT_COLOR ) );

    m_pPropertyGridCtrl->ExpandAll();

    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_USE_AUTOMATIC_VIEWPOINT );
    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_USE_FEATURE_SCANNING_GUIDANCE );
    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_USE_PRIORITIZE_ACQUISITION_SPEED );
}

// =================================================================================================
//   Initialize the Surface Scan property grid
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridSurfaceScanInit()
{
    m_pPropertyGridCtrl->AddProperty( MakePropertyValue< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_SPLIT_ZIGZAG_SCAN_PASSES ) );

    // Point clouds
    // ------------
    CIMPropertyGridProperty* pPointCloudGroup = MakePropertyGroup( L"Point clouds" );
    m_pPropertyGridCtrl->AddProperty( pPointCloudGroup );

    // Extract normal vectors
    // ----------------------
    auto* pExtractNormalVectors =
        MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_USE_EXTRACT_NORMAL_VECTORS );
    pPointCloudGroup->AddSubItem( pExtractNormalVectors );

    pExtractNormalVectors->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_MIN_SEARCH_DISTANCE ) );
    pExtractNormalVectors->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_MAX_SEARCH_DISTANCE ) );

    m_pPropertyGridCtrl->ExpandAll();

    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_USE_EXTRACT_NORMAL_VECTORS );
}

// =================================================================================================
//   Initialize the Real-Time Quality Meshing property grid
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridRealTimeQualityMeshingInit()
{
    // Default mesh creation parameters
    // --------------------------------
    CIMPropertyGridProperty* pDefaultMeshCreationParametersGroup = MakePropertyGroup( L"Default mesh creation parameters" );
    m_pPropertyGridCtrl->AddProperty( pDefaultMeshCreationParametersGroup );

    pDefaultMeshCreationParametersGroup->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_SAMPLING_STEP ) );
    pDefaultMeshCreationParametersGroup->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_MAX_EDGE_LENGTH ) );
    pDefaultMeshCreationParametersGroup->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_MAX_ANGLE ) );

    // Scan pass merging
    // -----------------
    CIMPropertyGridProperty* pScanPassMerging = MakePropertyGroup( L"Scan pass merging" );
    pDefaultMeshCreationParametersGroup->AddSubItem( pScanPassMerging );

    pScanPassMerging->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_MAX_DISTANCE ) );
    pScanPassMerging->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_NUMBER_OF_BLENDING_STEPS ) );

    m_pPropertyGridCtrl->ExpandAll();
}

// =================================================================================================
//   Initialize the Real-Time Quality Meshing Polygonal Models property grid
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridRTMPolygonalModelsInit()
{
    // Default mesh optimization parameters
    // ------------------------------------
    CIMPropertyGridProperty* pDefaultMeshOptimizationParametersGroup = MakePropertyGroup( L"Default mesh optimization parameters" );
    m_pPropertyGridCtrl->AddProperty( pDefaultMeshOptimizationParametersGroup );

    // Smooth
    // ------
    auto* pRTMSmooth = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_SMOOTH );
    pDefaultMeshOptimizationParametersGroup->AddSubItem( pRTMSmooth );

    TWStrings level;
    level.emplace_back( L"Minimum" );
    level.emplace_back( L"Low" );
    level.emplace_back( L"Medium" );
    level.emplace_back( L"High" );
    level.emplace_back( L"Custom" );
    pRTMSmooth->AddSubItem( MakePropertyComboValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_SMOOTH_LEVEL, level, FALSE ) );

    pRTMSmooth->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_SMOOTH_CUSTOM_LEVEL_RADIUS ) );

    CIMPropertyGridProperty* pSmoothConstrainDisplacement = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_SMOOTH_CONSTRAIN_DISPLACEMENT );
    pRTMSmooth->AddSubItem( pSmoothConstrainDisplacement );

    pSmoothConstrainDisplacement->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_SMOOTH_MAX_DISPLACEMENT ) );
    pRTMSmooth->AddSubItem( MakePropertyValue< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_SMOOTH_PRESERVE_FEATURES ) );

    // Reduce
    // ------
    auto* pRTMReduce = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_REDUCE );
    pDefaultMeshOptimizationParametersGroup->AddSubItem( pRTMReduce );

    level.erase( level.begin() ); // Remove the Minimum level
    pRTMReduce->AddSubItem( MakePropertyComboValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_REDUCE_LEVEL, level, FALSE ) );

    CIMPropertyGridProperty* pRTMReduceCustomLevel = MakePropertyGroup( L"Custom level" );
    pRTMReduce->AddSubItem( pRTMReduceCustomLevel );

    TWStrings reduceMethod;
    reduceMethod.emplace_back( L"Tolerance" );
    reduceMethod.emplace_back( L"Percentage of Triangles" );
    reduceMethod.emplace_back( L"Number of Triangles" );
    pRTMReduceCustomLevel->AddSubItem( MakePropertyComboValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_REDUCE_CUSTOM_METHOD, reduceMethod, FALSE ) );
    pRTMReduceCustomLevel->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_REDUCE_CUSTOM_TOLERANCE ) );
    pRTMReduceCustomLevel->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_REDUCE_CUSTOM_REMAINING_PERCENT ) );
    pRTMReduceCustomLevel->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_REDUCE_CUSTOM_REMAINING_TRIANGLES ) );

    auto* pConstrain = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_REDUCE_CONSTRAIN_EDGE_LENGTH );
    pRTMReduce->AddSubItem( pConstrain );

    pConstrain->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_REDUCE_CONSTRAIN_MAX_EDGE_LENGTH ) );

    pRTMReduce->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_REDUCE_PREREDUCTION_TOLERANCE ) );

    m_pPropertyGridCtrl->ExpandAll();

    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_RTM_REDUCE_CONSTRAIN_EDGE_LENGTH );
}

// =================================================================================================
//   Initialize the Real-Time Quality Meshing Quality Metrics property grid
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridRTMQualityMetricsInit()
{
    // Detect misaligned scan passes
    // -----------------------------
    auto* pDetectMisalignedScanPasses = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_DETECT_MISALIGNED_SCAN_PASSES );
    m_pPropertyGridCtrl->AddProperty( pDetectMisalignedScanPasses );

    pDetectMisalignedScanPasses->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_MAX_AVERAGE_DEVIATION ) );

    TWStrings misalignedBehavior;
    misalignedBehavior.emplace_back( L"Confirm Pass Deletion" );
    misalignedBehavior.emplace_back( L"Delete Pass" );
    pDetectMisalignedScanPasses->AddSubItem( MakePropertyComboValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_BEHAVIOR_WHEN_MISALIGNED, misalignedBehavior, FALSE ) );

    // Highlight low-quality triangles
    // -------------------------------
    CIMPropertyGridProperty* pHighlightLowQuality = MakePropertyGroup( L"Highlight low-quality triangles" );
    m_pPropertyGridCtrl->AddProperty( pHighlightLowQuality );

    // High scanner-to-surface-normal angle
    // ------------------------------------
    auto* pHighScannerToSurfaceNormal = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_HIGH_SCANNER_TO_SURFACE_NORMAL_ANGLE );
    pHighlightLowQuality->AddSubItem( pHighScannerToSurfaceNormal );

    pHighScannerToSurfaceNormal->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_HIGHLIGHT_MAX_ANGLE ) );
    pHighScannerToSurfaceNormal->AddSubItem( MakePropertyColorValue( E_PROPERTY_VALUE_RTM_HIGHLIGHT_MAX_ANGLE_COLOR ) );

    // Low scan density for mesh curvature
    // -----------------------------------
    auto* pLowScanDensityForCurvature = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_LOW_SCAN_DENSITY_FOR_CURVATURE );
    pHighlightLowQuality->AddSubItem( pLowScanDensityForCurvature );

    pLowScanDensityForCurvature->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_MAX_DEVIATION_SURFACE ) );
    pLowScanDensityForCurvature->AddSubItem( MakePropertyColorValue( E_PROPERTY_VALUE_RTM_MAX_DEVIATION_SURFACE_COLOR ) );

    // High noise level
    // ----------------
    auto* pHighNoiseLevel = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_RTM_HIGH_NOISE_LEVEL );
    pHighlightLowQuality->AddSubItem( pHighNoiseLevel );

    pHighNoiseLevel->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_RTM_STANDARD_DEVIATION_THRESHOLD ) );
    pHighNoiseLevel->AddSubItem( MakePropertyColorValue( E_PROPERTY_VALUE_RTM_STANDARD_DEVIATION_THRESHOLD_COLOR ) );

    m_pPropertyGridCtrl->ExpandAll();

    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_RTM_DETECT_MISALIGNED_SCAN_PASSES );
    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_RTM_HIGH_SCANNER_TO_SURFACE_NORMAL_ANGLE );
    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_RTM_LOW_SCAN_DENSITY_FOR_CURVATURE );
    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_RTM_HIGH_NOISE_LEVEL );
}

// =================================================================================================
//   Initialize the Filtering property grid
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridFilteringInit()
{
    // Filter scan lines
    // -----------------
    auto* pFilterScanLines = MakePropertyValueGroup< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES );
    m_pPropertyGridCtrl->AddProperty( pFilterScanLines );

    pFilterScanLines->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES_STANDARD_DEVIATION ) );

    CIMPropertyGridProperty* pFilterCloudPoints = MakePropertyGroup( L"Points cloud" );
    pFilterScanLines->AddSubItem( pFilterCloudPoints );

    pFilterCloudPoints->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES_MAX_POINT_TO_POINT_DISTANCE ) );

    // Clipping plane
    // --------------
    CIMPropertyGridProperty* pClippingPlane = MakePropertyGroup( L"Clipping plane" );
    m_pPropertyGridCtrl->AddProperty( pClippingPlane );

    pClippingPlane->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_FILTERING_CLIPPING_PLANE_REJECTION_DIST ) );

    m_pPropertyGridCtrl->ExpandAll();

    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES );
    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES_STANDARD_DEVIATION );
    PropertyEnableUpdateAuto( E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES_MAX_POINT_TO_POINT_DISTANCE );
}

// =================================================================================================
//   Initialize the Hole Boundary Scan property grid
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridHoleBoundaryScanInit()
{
    // Internal boundary detection (holes)
    // -----------------------------------
    CIMPropertyGridProperty* pHoleDetectionGroup = MakePropertyGroup( L"Internal boundary detection (holes)" );
    m_pPropertyGridCtrl->AddProperty( pHoleDetectionGroup );

    pHoleDetectionGroup->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_MIN_HOLE_WIDTH ) );

    // Real-time quality meshing
    // -------------------------
    CIMPropertyGridProperty* pRTMGroup = MakePropertyGroup( L"Real-time quality meshing" );
    m_pPropertyGridCtrl->AddProperty( pRTMGroup );

    pRTMGroup->AddSubItem( MakePropertyValue< CIMPropertyGridCheckBoxProperty >( E_PROPERTY_VALUE_EXTERNAL_BOUNDARY_DETECTION ) );

    m_pPropertyGridCtrl->ExpandAll();
}

// =================================================================================================
//   Initialize the Sharp Edge Scan property grid
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyGridSharpEdgeScanInit()
{
    // Scan line
    // ---------
    CIMPropertyGridProperty* pScanLineGroup = MakePropertyGroup( L"Scan line" );
    m_pPropertyGridCtrl->AddProperty( pScanLineGroup );

    pScanLineGroup->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_EDGE_MAX_POINT_TO_POINT_DISTANCE ) );
    pScanLineGroup->AddSubItem( MakePropertyValue< CIMPropertyGridProperty >( E_PROPERTY_VALUE_EDGE_MIN_ANGLE ) );

    m_pPropertyGridCtrl->ExpandAll();
}

// =================================================================================================
//   Update the enable state of a property.
//
// Parameter : propertyData_ : Property data ID
// Parameter : enable_       : TRUE to enable, FALSE otherwise
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::PropertyEnableUpdate( DWORD propertyData_, BOOL enable_ )
{
    __super::PropertyEnableUpdate( propertyData_, enable_ );

    switch ( propertyData_ )
    {
        case E_PROPERTY_VALUE_USE_AUTOMATIC_VIEWPOINT:
            PropertyEnable( E_PROPERTY_VALUE_DEVICE_VERTICAL_AXIS,           enable_ );
            PropertyEnable( E_PROPERTY_VALUE_STANDARD_ZOOM,                  enable_ );
            PropertyEnable( E_PROPERTY_VALUE_FEATURE_SCANNING_GUIDANCE_ZOOM, enable_ );
            break;
        case E_PROPERTY_VALUE_USE_EXTRACT_NORMAL_VECTORS:
            PropertyEnable( E_PROPERTY_VALUE_MIN_SEARCH_DISTANCE, enable_ );
            PropertyEnable( E_PROPERTY_VALUE_MAX_SEARCH_DISTANCE, enable_ );
            break;
        case E_PROPERTY_VALUE_RTM_DETECT_MISALIGNED_SCAN_PASSES:
            PropertyEnable( E_PROPERTY_VALUE_RTM_MAX_AVERAGE_DEVIATION,    enable_ );
            PropertyEnable( E_PROPERTY_VALUE_RTM_BEHAVIOR_WHEN_MISALIGNED, enable_ );
            break;
        case E_PROPERTY_VALUE_USE_PRIORITIZE_ACQUISITION_SPEED:
            PropertyEnable( E_PROPERTY_VALUE_MESHING_SPEED, enable_ );
            break;
        case E_PROPERTY_VALUE_USE_FEATURE_SCANNING_GUIDANCE:
            PropertyEnable( E_PROPERTY_VALUE_SURFACE_HIGHLIGHT_COLOR,  enable_ );
            PropertyEnable( E_PROPERTY_VALUE_BOUNDARY_HIGHLIGHT_COLOR, enable_ );
            break;
        case E_PROPERTY_VALUE_RTM_HIGH_SCANNER_TO_SURFACE_NORMAL_ANGLE:
            PropertyEnable( E_PROPERTY_VALUE_RTM_HIGHLIGHT_MAX_ANGLE,       enable_ );
            PropertyEnable( E_PROPERTY_VALUE_RTM_HIGHLIGHT_MAX_ANGLE_COLOR, enable_ );
            break;
        case E_PROPERTY_VALUE_RTM_LOW_SCAN_DENSITY_FOR_CURVATURE:
            PropertyEnable( E_PROPERTY_VALUE_RTM_MAX_DEVIATION_SURFACE,       enable_ );
            PropertyEnable( E_PROPERTY_VALUE_RTM_MAX_DEVIATION_SURFACE_COLOR, enable_ );
            break;
        case E_PROPERTY_VALUE_RTM_HIGH_NOISE_LEVEL:
            PropertyEnable( E_PROPERTY_VALUE_RTM_STANDARD_DEVIATION_THRESHOLD,       enable_ );
            PropertyEnable( E_PROPERTY_VALUE_RTM_STANDARD_DEVIATION_THRESHOLD_COLOR, enable_ );
            break;
        case E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES:
            PropertyEnable( E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES_STANDARD_DEVIATION,          enable_ );
            PropertyEnable( E_PROPERTY_VALUE_FILTERING_FILTER_SCAN_LINES_MAX_POINT_TO_POINT_DISTANCE, enable_ );
            break;
        case E_PROPERTY_VALUE_RTM_REDUCE_CONSTRAIN_EDGE_LENGTH:
            PropertyEnable( E_PROPERTY_VALUE_RTM_REDUCE_CONSTRAIN_MAX_EDGE_LENGTH, enable_ );
            break;
        default: // Unsupported
            ASSERT( FALSE );
            break;
    }
}

// =================================================================================================
//   Obtain the X position of the window.
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgIMInspectOptions::WindowPositionXGet()
{
    return theCompanyNameScannerSettings().IMIOptionsWindowPositionXGet();
}


// =================================================================================================
//   Set the X position of the window.
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::WindowPositionXSet( long position_ )
{
    theCompanyNameScannerSettings().IMIOptionsWindowPositionXSet( position_ );
}


// =================================================================================================
//   Obtain the Y position of the window.
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgIMInspectOptions::WindowPositionYGet()
{
    return theCompanyNameScannerSettings().IMIOptionsWindowPositionYGet();
}


// =================================================================================================
//   Sets the Y position of the window.
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgIMInspectOptions::WindowPositionYSet( long position_ )
{
    theCompanyNameScannerSettings().IMIOptionsWindowPositionYSet( position_ );
}
