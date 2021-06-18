// =================================================================================================
//   CDlgOptions class and support classes for property grid.
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   Class implementing the options dialog in Inspector mode.
// -------------------------------------------------------------------------------------------------
partial class CDlgOptions : Form
{
    private List< CPropertyGroup > m_groups = new List< CPropertyGroup >();

    // =================================================================================================
    //   Constructor used only by the designer.
    // -------------------------------------------------------------------------------------------------
    public CDlgOptions()
    {
        InitializeComponent();
    }

    // =================================================================================================
    //   Real constructor used when we create the dialog at runtime.
    //
    // Parameter : host_ : Access to host application functionalities.
    // -------------------------------------------------------------------------------------------------
    public CDlgOptions( IM.CIMHost host_ )
    {
        InitializeComponent();

        // Treeview nodes are created here instead of in the designer
        // to associate each with an object that will be passed to the
        // property grid.
        TreeNode treeNode1 = new TreeNode( "General" );
        TreeNode treeNode2 = new TreeNode( "Polygonal Models" );
        TreeNode treeNode3 = new TreeNode( "Quality Metrics" );
        TreeNode treeNode4 = new TreeNode( "Real-Time Quality Meshing",
                                            new TreeNode[] { treeNode2,
                                                             treeNode3 } );
        TreeNode treeNode5 = new TreeNode( "Filtering" );
        TreeNode treeNode6 = new TreeNode( "Surface Scan",
                                            new TreeNode[] { treeNode4,
                                                             treeNode5 } );
        TreeNode treeNode7 = new TreeNode( "Surface and Boundary Scan" );
        TreeNode treeNode8 = new TreeNode( "Sharp Edge Scan" );

        m_treeView.Nodes.AddRange( new TreeNode[] { treeNode1, treeNode6, treeNode7, treeNode8 } );
        m_treeView.ExpandAll();

        AddGroup( new CGeneral( host_ ), treeNode1 );
        AddGroup( new CSurfaceScan( host_ ), treeNode6 );
        AddGroup( new CRTQM( host_ ), treeNode4 );
        AddGroup( new CPolygonalModels( host_ ), treeNode2 );
        AddGroup( new CQualityMetrics( host_ ), treeNode3 );
        AddGroup( new CFiltering( host_ ), treeNode5 );
        AddGroup( new CSurfaceBoundary( host_ ), treeNode7 );
        AddGroup( new CSharpEdgeScan( host_ ), treeNode8 );
    }

    // =================================================================================================
    //   Simple utility functions to add a group of properties and associate it with a tree view node.
    //
    // Parameter : group_ : The group to add
    // Parameter : node_  : The group will be set in the Tag property of this node so that it is
    //                      displayed in the property grid when that node is selected.
    // -------------------------------------------------------------------------------------------------
    private void AddGroup( CPropertyGroup group_, TreeNode node_ )
    {
        m_groups.Add( group_ );
        node_.Tag = group_;
    }

    // =================================================================================================
    //   Event-handler called when a new node is selected in the tree view. The property group object
    // associated with this group is set in the property grid.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Event parameter used to know the selected node.
    // -------------------------------------------------------------------------------------------------
    private void treeViewAfterSelect( object sender, TreeViewEventArgs e )
    {
        m_propertyGrid.SelectedObject = e.Node.Tag;
        m_propertyGrid.ExpandAllGridItems();
    }

    // =================================================================================================
    //   Event-handler called when the Cancel button is clicked. The dialog is simply closed, losing
    // any changes to the properties.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbCancelClick( object sender, EventArgs e )
    {
        Close();
    }

    // =================================================================================================
    //   Event-handler called when the OK button is clicked. Properties changes are confirmed and then
    // the dialog is closed.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbOKClick( object sender, EventArgs e )
    {
        foreach( CPropertyGroup group in m_groups )
        {
            if ( !group.WriteProperties() )
            {
                return;
            }
        }

        Close();
    }
}

#region Property grid support classes and enums

// =================================================================================================
//   The rest of this files are support classes and enums to fill the property grid.
// Properties are grouped in CPropertyGroup objects, each group corresponding to one node in the
// treeview.
// -------------------------------------------------------------------------------------------------

/******************************************
* General
* ****************************************/
class CScanLineCloseup
{
    private CProperty< int > m_standardZoom;
    private CProperty< int > m_guidanceZoom;

    public CScanLineCloseup( List< CPropertyBase > group_ )
    {
        m_standardZoom = new CProperty< int >( Consts.CMD_AUTO_VIEWPOINT_CLOSEUP_ZOOM_SET, group_ );
        m_guidanceZoom = new CProperty< int >( "DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM FEATURE_SCANNING_GUIDANCE", group_ );
    }

    [ DisplayName( "Standard zoom (%)" ),
      NotifyParentProperty( true ) ]
    public int StandardZoom
    {
        get { return m_standardZoom.m_value; }
        set { m_standardZoom.m_value = value; }
    }

    [ DisplayName( "Feature scanning guidance zoom (%)" ),
      NotifyParentProperty( true ) ]
    public int GuidanceZoom
    {
        get { return m_guidanceZoom.m_value; }
        set { m_guidanceZoom.m_value = value; }
    }
}

enum EMeshingSpeed
{
    [ Description( "Low" ) ]
    LOW,
    [ Description( "Medium" ) ]
    MEDIUM
}

class CMeshingSpeed
{
    private CPropertyBool                  m_prioritize;
    private CPropertyEnum< EMeshingSpeed > m_speed;

    public CMeshingSpeed( List< CPropertyBase > group_ )
    {
        m_prioritize = new CPropertyBool( "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING PRIORITIZE_ACQUISITION_SPEED", group_ );
        m_speed      = new CPropertyEnum< EMeshingSpeed >( "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING PRIORITIZE_ACQUISITION_SPEED MESHING_SPEED", group_ );
    }

    [ DisplayName( "Enable" ) ]
    public bool Prioritize
    {
        get { return m_prioritize.m_value; }
        set { m_prioritize.m_value = value; }
    }

    [ DisplayName( "Meshing speed" ),
      TypeConverter( typeof( CCustomEnumConverter ) ) ]
    public EMeshingSpeed MeshingSpeed
    {
        get { return m_speed.m_value; }
        set { m_speed.m_value = value; }
    }
}

class CGeneral : CPropertyGroup
{
    private const string VIEWPOINT_CATEGORY  = "2. Automatic viewpoint";
    private const string PROCESSING_CATEGORY = "3. Data processing";
    private const string GUIDANCE_CATEGORY   = "4. Feature scanning guidance";

    private CPropertyBool             m_audioFeedback;
    private CPropertyBool             m_automaticViewpoint;
    private CPropertyEnum< EStdAxis > m_verticalAxis;
    private CScanLineCloseup          m_scanLineCloseup;
    private CPropertyBool             m_parallelProcessing;
    private CMeshingSpeed             m_meshingSpeed;
    private CPropertyBool             m_guidance;
    private CPropertyColor            m_surfaceHiliteColor;
    private CPropertyColor            m_boundaryHiliteColor;

    public CGeneral( IM.CIMHost host_ ) :
        base( host_ )
    {
        m_audioFeedback       = new CPropertyBool( "DIGITIZE LINE_SCAN AUDIO_FEEDBACK", m_properties );
        m_automaticViewpoint  = new CPropertyBool( Consts.CMD_AUTO_VIEWPOINT_SET, m_properties );
        m_verticalAxis        = new CPropertyEnum< EStdAxis >( Consts.CMD_AUTO_VIEWPOINT_VERTICAL_AXIS_SET, m_properties );
        m_scanLineCloseup     = new CScanLineCloseup( m_properties );
        m_parallelProcessing  = new CPropertyBool( "DIGITIZE LINE_SCAN PARALLEL_PROCESSING", m_properties );
        m_meshingSpeed        = new CMeshingSpeed( m_properties );
        m_guidance            = new CPropertyBool( "DIGITIZE LINE_SCAN FEATURE_SCANNING_GUIDANCE", m_properties );
        m_surfaceHiliteColor  = new CPropertyColor( "DIGITIZE LINE_SCAN FEATURE_SCANNING_GUIDANCE HIGHLIGHT_COLOR SURFACE", m_properties );
        m_boundaryHiliteColor = new CPropertyColor( "DIGITIZE LINE_SCAN FEATURE_SCANNING_GUIDANCE HIGHLIGHT_COLOR BOUNDARY", m_properties );

        ReadProperties();
    }

    [ Category( "1. Utilities" ),
      DisplayName( "Audio feedback" ) ]
    public bool AudioFeedback
    {
        get { return m_audioFeedback.m_value; }
        set { m_audioFeedback.m_value = value; }
    }

    [ Category( VIEWPOINT_CATEGORY ),
      DisplayName( "Enable" ) ]
    public bool AutomaticViewpoint
    {
        get { return m_automaticViewpoint.m_value; }
        set { m_automaticViewpoint.m_value = value; }
    }

    [ Category( VIEWPOINT_CATEGORY ),
      DisplayName( "Device vertical axis" ),
      TypeConverter( typeof( CCustomEnumConverter ) ) ]
    public EStdAxis VerticalAxis
    {
        get { return m_verticalAxis.m_value; }
        set { m_verticalAxis.m_value = value; }
    }

    [ Category( VIEWPOINT_CATEGORY ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ),
      DisplayName( "Scan line close-up" )
    ]
    public CScanLineCloseup SLC
    {
        get { return m_scanLineCloseup; }
        set { m_scanLineCloseup = value; }
    }

    [ Category( PROCESSING_CATEGORY ),
      DisplayName( "Parallel processing" ) ]
    public bool ParallelProcessing
    {
        get { return m_parallelProcessing.m_value; }
        set { m_parallelProcessing.m_value = value; }
    }

    [ Category( PROCESSING_CATEGORY ),
      DisplayName( "Prioritize acquisition speed over meshing speed" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CMeshingSpeed MS
    {
        get { return m_meshingSpeed; }
        set { m_meshingSpeed = value; }
    }

    [ Category( GUIDANCE_CATEGORY ) ]
    public bool Enable
    {
        get { return m_guidance.m_value; }
        set { m_guidance.m_value = value; }
    }

    [ Category( GUIDANCE_CATEGORY ),
      DisplayName( "Surface highlight color" ) ]
    public Color SurfaceHighlightColor
    {
        get { return m_surfaceHiliteColor.m_value; }
        set { m_surfaceHiliteColor.m_value = value; }
    }

    [ Category( GUIDANCE_CATEGORY ),
      DisplayName( "Boundary highlight color" ) ]
    public Color BoundaryHighlightColor
    {
        get { return m_boundaryHiliteColor.m_value; }
        set { m_boundaryHiliteColor.m_value = value; }
    }
}

/******************************************
* Surface Scan
* ****************************************/
class CExtractNormals
{
    private CPropertyBool       m_enable;
    private CProperty< double > m_minSearchDistance;
    private CProperty< double > m_maxSearchDistance;
    
    public CExtractNormals( List< CPropertyBase > group_ )
    {
        m_enable            = new CPropertyBool( Consts.CMD_EXTRACT_NORMAL_VECTORS, group_ );
        m_minSearchDistance = new CProperty< double >( Consts.CMD_EXTRACT_NORMALS_MIN_DISTANCE, group_ );
        m_maxSearchDistance = new CProperty< double >( Consts.CMD_EXTRACT_NORMALS_MAX_DISTANCE, group_ );
    }

    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ DisplayName( "Min search distance" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MinSearchDistance
    {
        get { return m_minSearchDistance.m_value; }
        set { m_minSearchDistance.m_value = value; }
    }

    [ DisplayName( "Max search distance" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MaxSearchDistance
    {
        get { return m_maxSearchDistance.m_value; }
        set { m_maxSearchDistance.m_value = value; }
    }
}

class CSurfaceScan : CPropertyGroup
{
    private CPropertyBool    m_zigzag;
    private CExtractNormals  m_extractNormals;

    public CSurfaceScan( IM.CIMHost host_ ) :
        base( host_ )
    {
        m_zigzag         = new CPropertyBool( "DIGITIZE DEVICE SCAN SURFACE SPLIT_ZIGZAG_SCAN_PASSES", m_properties );
        m_extractNormals = new CExtractNormals( m_properties );

        ReadProperties();
    }

    [ Category( "1. Scan passes" ),
      DisplayName( "Split zigzag passes" ) ]
    public bool ZigZag
    {
        get { return m_zigzag.m_value; }
        set { m_zigzag.m_value = value; }
    }

    [ Category( "2. Point clouds" ),
      DisplayName( "Extract normal vectors" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CExtractNormals ExtractNormals
    {
        get { return m_extractNormals; }
        set { m_extractNormals = value; }
    }
}

/******************************************
* Real-Time Quality Meshing
* ****************************************/
class CScanPassMerging
{
    private CProperty< double > m_maxDistance;
    private CProperty< int >    m_blendingSteps;

    public CScanPassMerging( List< CPropertyBase > group_ )
    {
        m_maxDistance   = new CProperty< double >( "DATA OPTIONS SCAN MESHING SCAN_PASS_MERGING MAX_DISTANCE", group_ );
        m_blendingSteps = new CProperty< int >( "DATA OPTIONS SCAN MESHING SCAN_PASS_MERGING NB_BLENDING_STEPS", group_ );
    }

    [ DisplayName( "Max distance" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MaxDistance
    {
        get { return m_maxDistance.m_value; }
        set { m_maxDistance.m_value = value; }
    }

    [ DisplayName( "Number of blending steps" ) ]
    public int BlendingSteps
    {
        get { return m_blendingSteps.m_value; }
        set { m_blendingSteps.m_value = value; }
    }
}

class CRTQM : CPropertyGroup
{
    private const string CATEGORY = "Default mesh creation parameters";

    private CProperty< double > m_samplingStep;
    private CProperty< double > m_maxEdgeLength;
    private CProperty< double > m_maxAngle;
    private CScanPassMerging    m_scanPassMerging;

    public CRTQM( IM.CIMHost host_ ) :
        base( host_ )
    {
        m_samplingStep    = new CProperty< double >( "DATA SURFACE OPTIONS SCAN MESHING SAMPLING_STEP", m_properties );
        m_maxEdgeLength   = new CProperty< double >( "DATA SURFACE OPTIONS SCAN MESHING MAX_EDGE_LENGTH", m_properties );
        m_maxAngle        = new CProperty< double >( "DATA OPTIONS SCAN MESHING MAX_ANGLE", m_properties );
        m_scanPassMerging = new CScanPassMerging( m_properties );

        ReadProperties();
    }

    [ Category( CATEGORY ),
      DisplayName( "Sampling step" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double SamplingStep
    {
        get { return m_samplingStep.m_value; }
        set { m_samplingStep.m_value = value; }
    }

    [ Category( CATEGORY ),
      DisplayName( "Max edge length" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MaxEdgeLength
    {
        get { return m_maxEdgeLength.m_value; }
        set { m_maxEdgeLength.m_value = value; }
    }

    [ Category( CATEGORY ),
      DisplayName( "Max angle" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MaxAngle
    {
        get { return m_maxAngle.m_value; }
        set { m_maxAngle.m_value = value; }
    }

    [ Category( CATEGORY ),
      DisplayName( "Scan pass merging" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CScanPassMerging MaxDistance
    {
        get { return m_scanPassMerging; }
        set { m_scanPassMerging = value; }
    }
}

/******************************************
* Polygonal Models
* ****************************************/
enum ESmoothLevel
{
    [ Description( "Minimum" ) ]
    MINIMUM,
    [ Description( "Low" ) ]
    LOW,
    [ Description( "Medium" ) ]
    MEDIUM,
    [ Description( "High" ) ]
    HIGH,
    [ Description( "Custom" ) ]
    CUSTOM
}

class CConstrain
{
    private CPropertyBool       m_enable;
    private CProperty< double > m_maxDisplacement;

    public CConstrain( List< CPropertyBase > group_ )
    {
        m_enable          = new CPropertyBool( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH USE_MAX_DISPLACEMENT", group_ );
        m_maxDisplacement = new CProperty< double >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH MAX_DISPLACEMENT", group_ );
    }

    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ DisplayName( "Max displacement" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MaxDisplacement
    {
        get { return m_maxDisplacement.m_value; }
        set { m_maxDisplacement.m_value = value; }
    }
}

class CSmooth
{
    private CPropertyBool                 m_enable;
    private CPropertyEnum< ESmoothLevel > m_level;
    private CProperty< double >           m_customRadius;
    private CConstrain                    m_constrain;
    private CPropertyBool                 m_preserveFeatures;

    public CSmooth( List< CPropertyBase > group_ )
    {
        m_enable           = new CPropertyBool( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH", group_ );
        m_level            = new CPropertyEnum< ESmoothLevel >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH LEVEL", group_ );
        m_customRadius     = new CProperty< double >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH LEVEL CUSTOM RADIUS", group_ );
        m_constrain        = new CConstrain( group_ );
        m_preserveFeatures = new CPropertyBool( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING SMOOTH PRESERVE_FEATURES", group_ );
    }

    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ TypeConverter( typeof( CCustomEnumConverter ) ) ]
    public ESmoothLevel Level
    {
        get { return m_level.m_value; }
        set { m_level.m_value = value; }
    }

    [ DisplayName( "Custom level radius" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double CustomRadius
    {
        get { return m_customRadius.m_value; }
        set { m_customRadius.m_value = value; }
    }

    [ DisplayName( "Constrain displacement" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CConstrain Constrain
    {
        get { return m_constrain; }
        set { m_constrain = value; }
    }

    [ DisplayName( "Preserve features" ) ]
    public bool PreserveFeatures
    {
        get { return m_preserveFeatures.m_value; }
        set { m_preserveFeatures.m_value = value; }
    }
}

enum EReduceMethod
{
    [ Description( "Tolerance" ) ]
    TOLERANCE,
    [ Description( "Percentage of Triangles" ) ]
    PERCENTAGE,
    [ Description( "Number of Triangles" ) ]
    NUMBER
}

class CCustomLevel
{
    private CPropertyEnum< EReduceMethod > m_method;
    private CProperty< double >            m_tolerance;
    private CProperty< double >            m_trianglePercentage;
    private CProperty< int >               m_triangleNumber;

    public CCustomLevel( List< CPropertyBase > group_ )
    {
        m_method             = new CPropertyEnum< EReduceMethod >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL CUSTOM METHOD", group_ );
        m_tolerance          = new CProperty< double >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL CUSTOM TOLERANCE", group_ );
        m_trianglePercentage = new CProperty< double >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL CUSTOM REMAINING_PERCENTAGE", group_ );
        m_triangleNumber     = new CProperty< int >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL CUSTOM REMAINING_TRIANGLES", group_ );
    }

    [ TypeConverter( typeof( CCustomEnumConverter ) ) ]
    public EReduceMethod Method
    {
        get { return m_method.m_value; }
        set { m_method.m_value = value; }
    }

    [ TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double Tolerance
    {
        get { return m_tolerance.m_value; }
        set { m_tolerance.m_value = value; }
    }

    [ DisplayName( "Remaining percentage of triangles" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double Percentage
    {
        get { return m_trianglePercentage.m_value; }
        set { m_trianglePercentage.m_value = value; }
    }

    [ DisplayName( "Remaining number of triangles" ) ]
    public int Number
    {
        get { return m_triangleNumber.m_value; }
        set { m_triangleNumber.m_value = value; }
    }
}

class CConstrainEdgeLength
{
    private CPropertyBool       m_enable;
    private CProperty< double > m_maxEdgeLength;

    public CConstrainEdgeLength( List< CPropertyBase > group_ )
    {
        m_enable        = new CPropertyBool( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE USE_MAX_EDGE_LENGTH", group_ );
        m_maxEdgeLength = new CProperty< double >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE MAX_EDGE_LENGTH", group_ );
    }

    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ DisplayName( "Max edge length" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MaxEdgeLength
    {
        get { return m_maxEdgeLength.m_value; }
        set { m_maxEdgeLength.m_value = value; }
    }
}

enum EReduceLevel
{
    [ Description( "Low" ) ]
    LOW,
    [ Description( "Medium" ) ]
    MEDIUM,
    [ Description( "High" ) ]
    HIGH,
    [ Description( "Custom" ) ]
    CUSTOM
}

class CReduce
{
    private CPropertyBool                 m_enable;
    private CPropertyEnum< EReduceLevel > m_level;
    private CCustomLevel                  m_customLevel;
    private CConstrainEdgeLength          m_constrainEdgeLength;
    private CProperty< double >           m_preReductionTolerance;

    public CReduce( List< CPropertyBase > group_ )
    {
        m_enable                = new CPropertyBool( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE", group_ );
        m_level                 = new CPropertyEnum< EReduceLevel >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE LEVEL", group_ );
        m_customLevel           = new CCustomLevel( group_ );
        m_constrainEdgeLength   = new CConstrainEdgeLength( group_ );
        m_preReductionTolerance = new CProperty< double >( "DATA POLYGONAL_MODEL OPTIONS SCAN MESHING REDUCE PREREDUCTION TOLERANCE", group_ );
    }

    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ TypeConverter( typeof( CCustomEnumConverter ) ) ]
    public EReduceLevel Level
    {
        get { return m_level.m_value; }
        set { m_level.m_value = value; }
    }

    [ DisplayName( "Custom level" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CCustomLevel CustomLevel
    {
        get { return m_customLevel; }
        set { m_customLevel = value; }
    }

    [ DisplayName( "Constrain edge length" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CConstrainEdgeLength ConstrainEdgeLength
    {
        get { return m_constrainEdgeLength; }
        set { m_constrainEdgeLength = value; }
    }

    [ DisplayName( "Prereduction tolerance" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double PreReductionTolerance
    {
        get { return m_preReductionTolerance.m_value; }
        set { m_preReductionTolerance.m_value = value; }
    }
}

class CPolygonalModels : CPropertyGroup
{
    private const string CATEGORY = "Default mesh optimization parameters";

    private CSmooth m_smooth;
    private CReduce m_reduce;

    public CPolygonalModels( IM.CIMHost host_ ):
        base( host_ )
    {
        m_smooth = new CSmooth( m_properties );
        m_reduce = new CReduce( m_properties );

        ReadProperties();
    }
    
    [ Category( CATEGORY ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CSmooth Smooth
    {
        get { return m_smooth; }
        set { m_smooth = value; }
    }

    [ Category( CATEGORY ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CReduce Reduce
    {
        get { return m_reduce; }
        set { m_reduce = value; }
    }
}

/******************************************
* Quality Metrics
* ****************************************/
class CDoubleAndColor
{
    private const string COMMAND_BASE = "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS HIGHLIGHT_LOW_QUALITY_TRIANGLES ";

    protected CPropertyBool       m_enable;
    protected CProperty< double > m_criteria;
    protected CPropertyColor      m_color;

    public CDoubleAndColor( List< CPropertyBase > group_, string suffix_, string criteria_ )
    {
        m_enable   = new CPropertyBool( COMMAND_BASE + suffix_, group_ );
        m_criteria = new CProperty< double >( COMMAND_BASE + suffix_ + " " + criteria_, group_ );
        m_color    = new CPropertyColor( COMMAND_BASE + suffix_ + " COLOR", group_ );
    }
}

class CHighAngle : CDoubleAndColor
{
    public CHighAngle( List< CPropertyBase > group_ ) :
        base( group_, "HIGH_SCANNER_TO_SURFACE_NORMAL_ANGLE", "MAX_ANGLE" )
    {
    }

    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ DisplayName( "High scanner-to-surface-normal angle" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double Criteria
    {
        get { return m_criteria.m_value; }
        set { m_criteria.m_value = value; }
    }

    public Color Color
    {
        get { return m_color.m_value; }
        set { m_color.m_value = value; }
    }
}

class CLowDensity : CDoubleAndColor
{
    public CLowDensity( List< CPropertyBase > group_ ) :
        base( group_, "LOW_SCAN_DENSITY_FOR_MESH_CURVATURE", "MAX_DEVIATION_TO_SURFACE" )
    {
    }

    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ DisplayName( "Max deviation to surface" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double Criteria
    {
        get { return m_criteria.m_value; }
        set { m_criteria.m_value = value; }
    }

    public Color Color
    {
        get { return m_color.m_value; }
        set { m_color.m_value = value; }
    }
}

class CHighNoise : CDoubleAndColor
{
    public CHighNoise( List< CPropertyBase > group_ ) :
        base( group_, "HIGH_NOISE_LEVEL", "THRESHOLD" )
    {
    }

    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ DisplayName( "Standard deviation threshold" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double Criteria
    {
        get { return m_criteria.m_value; }
        set { m_criteria.m_value = value; }
    }

    public Color Color
    {
        get { return m_color.m_value; }
        set { m_color.m_value = value; }
    }
}

enum EConfirm
{
    [ Description( "Confirm Pass Deletion" ) ]
    CONFIRM,
    [ Description( "Delete Pass" ) ]
    DELETE
}

class CQualityMetrics : CPropertyGroup
{
    private const string DETECT_CATEGORY = "Detect misaligned scan passes";
    private const string HILITE_CATEGORY = "Highlight low-quality triangles";

    private CPropertyBool             m_enable;
    private CProperty< double >       m_maxDeviation;
    private CPropertyEnum< EConfirm > m_behavior;
    private CHighAngle                m_highAngle;
    private CLowDensity               m_lowDensity;
    private CHighNoise                m_highNoise;

    public CQualityMetrics( IM.CIMHost host_ ):
        base( host_ )
    {
        m_enable       = new CPropertyBool( "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS DETECT_MISALIGNED_SCAN_PASSES", m_properties );
        m_maxDeviation = new CProperty< double >( "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS DETECT_MISALIGNED_SCAN_PASSES MAX_AVERAGE_DEVIATION", m_properties );
        m_behavior     = new CPropertyEnum< EConfirm >( "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING QUALITY_METRICS DETECT_MISALIGNED_SCAN_PASSES BEHAVIOR", m_properties );
        m_highAngle    = new CHighAngle( m_properties );
        m_lowDensity   = new CLowDensity( m_properties );
        m_highNoise    = new CHighNoise( m_properties );

        ReadProperties();
    }

    [ Category( DETECT_CATEGORY ) ]
    public bool Enable
    {
        get { return m_enable.m_value; }
        set { m_enable.m_value = value; }
    }

    [ Category( DETECT_CATEGORY ),
      DisplayName( "Max average deviation" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MaxDeviation
    {
        get { return m_maxDeviation.m_value; }
        set { m_maxDeviation.m_value = value; }
    }

    [ Category( DETECT_CATEGORY ),
      DisplayName( "Behavior when misaligned" ),
      TypeConverter( typeof(CCustomEnumConverter) ) ]
    public EConfirm Behavior
    {
        get { return m_behavior.m_value; }
        set { m_behavior.m_value = value; }
    }

    [ Category( HILITE_CATEGORY ),
      DisplayName( "High scanner-to-surface-normal angle" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CHighAngle HighAngle
    {
        get { return m_highAngle; }
        set { m_highAngle = value; }
    }
        
    [ Category( HILITE_CATEGORY ),
      DisplayName( "Low scan density for mesh curvature" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CLowDensity LowDensityColor
    {
        get { return m_lowDensity; }
        set { m_lowDensity = value; }
    }

    [ Category( HILITE_CATEGORY ),
      DisplayName( "High noise level" ),
      TypeConverter( typeof( IMExpandableObjectConverter ) ) ]
    public CHighNoise HighNoiseColor
    {
        get { return m_highNoise; }
        set { m_highNoise = value; }
    }
}

/******************************************
 * Filtering
 * ***************************************/
class CFilterScanLinePointsCloud
{
    private CProperty< double > m_filterScanLineMaxPointToPointDistance;

    public CFilterScanLinePointsCloud( List< CPropertyBase > group_ )
    {
        m_filterScanLineMaxPointToPointDistance = new CProperty<double>( "DIGITIZE LINE_SCAN SCAN_LINE_FILTER MAX_POINT_TO_POINT_DIST", group_ );
    }

    [ DisplayName( "Max point-to-point distance" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double FilterScanLineMaxPointToPointDistance
    {
        get { return m_filterScanLineMaxPointToPointDistance.m_value; }
        set { m_filterScanLineMaxPointToPointDistance.m_value = value; }
    }
}

class CFiltering : CPropertyGroup
{
    private const string FILTER_SCAN_LINE_CATEGORY = "1. Filter scan line";

    private CPropertyBool              m_filterScanLineEnable;
    private CProperty< double >        m_filterScanLineStandardDeviation;
    private CFilterScanLinePointsCloud m_filterScanLinePointsCloud;

    private CProperty< double >       m_rejectionDistance;
    
    public CFiltering( IM.CIMHost host_ ) :
        base( host_ )
    {
        m_filterScanLineEnable            = new CPropertyBool( "DIGITIZE LINE_SCAN SCAN_LINE_FILTER", m_properties );
        m_filterScanLineStandardDeviation = new CProperty< double >( "DIGITIZE LINE_SCAN SCAN_LINE_FILTER STANDARD_DEVIATION", m_properties );
        m_filterScanLinePointsCloud       = new CFilterScanLinePointsCloud( m_properties );

        m_rejectionDistance = new CProperty< double >( "DIGITIZE LINE_SCAN SURFACE CLIPPING_PLANE POINT_REJECTION_DISTANCE", m_properties );

        ReadProperties();
    }

    [ Category( FILTER_SCAN_LINE_CATEGORY ),
      DisplayName( "Enable" ) ]
    public bool FilterScanLineEnable
    {
        get { return m_filterScanLineEnable.m_value; }
        set { m_filterScanLineEnable.m_value = value; }
    }

    [ Category( FILTER_SCAN_LINE_CATEGORY ),
      DisplayName( "Standard deviation" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double FilterScanLineStandardDeviation
    {
        get { return m_filterScanLineStandardDeviation.m_value; }
        set { m_filterScanLineStandardDeviation.m_value = value; }
    }

    [ Category( FILTER_SCAN_LINE_CATEGORY ),
      DisplayName("Points cloud"),
      TypeConverter(typeof(IMExpandableObjectConverter))]
    public CFilterScanLinePointsCloud FilterScanLinePointsCloud
    {
        get { return m_filterScanLinePointsCloud; }
        set { m_filterScanLinePointsCloud = value; }
    }

    [ Category( "2. Clipping plane" ),
      DisplayName( "Point rejection distance above plane" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double RejectionDistance
    {
        get { return m_rejectionDistance.m_value; }
        set { m_rejectionDistance.m_value = value; }
    }
}

/******************************************
 * Surface and Boundary Scan
 * ***************************************/
class CSurfaceBoundary : CPropertyGroup
{
    private CProperty< double > m_minHoleWidth;
    private CPropertyBool       m_boundaryDetect;

    public CSurfaceBoundary( IM.CIMHost host_ ) :
        base( host_)
    {
        m_minHoleWidth   = new CProperty< double >( "DIGITIZE DEVICE SCAN SURFACE_AND_BOUNDARY INTERNAL_BOUNDARIES MIN_HOLE_WIDTH", m_properties );
        m_boundaryDetect = new CPropertyBool( "DIGITIZE DEVICE SCAN SURFACE_AND_BOUNDARY EXTERNAL_BOUNDARIES", m_properties );

        ReadProperties();
    }

    [ Category( "Internal boundary detection (holes)" ),
      DisplayName( "Min hole width" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MinHoleWidth
    {
        get { return m_minHoleWidth.m_value; }
        set { m_minHoleWidth.m_value = value; }
    }

    [ Category( "Real-time quality meshing" ),
      DisplayName( "External boundary detection" ) ]
    public bool BoundaryDetect
    {
        get { return m_boundaryDetect.m_value; }
        set { m_boundaryDetect.m_value = value; }
    }
}

/******************************************
* Sharp Edge Scan
* ****************************************/
class CSharpEdgeScan : CPropertyGroup
{
    private const string CATEGORY = "Scan line";

    private CProperty< double > m_maxDistance;
    private CProperty< double > m_minAngle;

    public CSharpEdgeScan( IM.CIMHost host_ ) :
        base( host_ )
    {
        m_maxDistance = new CProperty< double >( Consts.CMD_SCAN_BOUNDARY_MAX_POINT_TO_POINT_DIST, m_properties );
        m_minAngle    = new CProperty< double >( Consts.CMD_SCAN_BOUNDARY_MIN_EDGE_ANGLE, m_properties );

        ReadProperties();
    }

    [ Category( CATEGORY ),
      DisplayName( "Max point-to-point distance" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MaxDistance
    {
        get { return m_maxDistance.m_value; }
        set { m_maxDistance.m_value = value; }
    }

    [ Category( CATEGORY ),
      DisplayName( "Min angle" ),
      TypeConverter( typeof( FloatNumberTypeConverter ) ) ]
    public double MinAngle
    {
        get { return m_minAngle.m_value; }
        set { m_minAngle.m_value = value; }
    }
}

#endregion

}
