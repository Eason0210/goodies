// =================================================================================================
//   CSettings class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using IM;
using System.ComponentModel;

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   Enumeration used to identify the vertical axis
// -------------------------------------------------------------------------------------------------
enum EStdAxis
{
    [ Browsable( false ) ]
    INVALID = -1,

    [ Description( "+X" ) ]
    X_POS = 0, 
    [ Description( "-X" ) ]
    X_NEG, 
    [ Description( "+Y" ) ]
    Y_POS, 
    [ Description( "-Y" ) ]
    Y_NEG, 
    [ Description( "+Z" ) ]
    Z_POS, 
    [ Description( "-Z" ) ]
    Z_NEG, 

    [ Browsable( false ) ]
    NB_STD_AXES
}

// =================================================================================================
//   Derived class implementing access functions for the plug-in's settings.
// -------------------------------------------------------------------------------------------------
class CSettings : CSettingsBase
{
    private CSetting< double > m_IMAMaxEdgeLength;
    private CSetting< double > m_IMAInterpolationStep;
    private CSetting< double > m_IMAMaxAngle;
    private CSetting< double > m_IMIMinSearchDist;
    private CSetting< double > m_IMIMaxSearchDist;
    private CSetting< double > m_IMIMinHoleWidth;
    private CSetting< double > m_IMISharpEdgeMaxPtToPtDist;
    private CSetting< double > m_IMISharpEdgeMinAngle;
    // TODO : Add any double settings your plug-in requires.

    private CSetting< int >    m_testMode;
    private CSetting< int >    m_refreshDelay;
    private CSetting< int >    m_autoViewpointEnable;
    private CSetting< int >    m_autoViewpointZoomClsup;
    private CSetting< int >    m_invertDigitizingVector;
    private CSetting< int >    m_deviceVerticalAxis;
    private CSetting< int >    m_IMAWindowPositionX;
    private CSetting< int >    m_IMAWindowPositionY;
    private CSetting< int >    m_IMAOptionsWindowPositionX;
    private CSetting< int >    m_IMAOptionsWindowPositionY;
    private CSetting< int >    m_IMIExtractNormals;
    private CSetting< int >    m_IMIRealTimeInspection;
    private CSetting< int >    m_IMIScanType;
    private CSetting< int >    m_IMIWindowPositionX;
    private CSetting< int >    m_IMIWindowPositionY;
    private CSetting< int >    m_IMIOptionsWindowPositionX;
    private CSetting< int >    m_IMIOptionsWindowPositionY;
    private CSetting< int >    m_IMIRealTimeMeshing;
    // TODO : Add any integer settings your plug-in requires

    // TODO : Add any string settings your plug-in requires

    // =================================================================================================
    //   Constructor
    //
    // Parameter : host_            : Access to host application functionalities.
    // Parameter : repository_      : COM setting access object. Must not be null.
    // -------------------------------------------------------------------------------------------------
    public CSettings( CIMHost                             host_,
                      IMInspectLib.IIMSettingsRepository2 repository_ ) :
        base( Consts.PLUGIN_NAME, host_, repository_ )
    {
        // TODO : Create all your plug-in settings (as added in the member variables above).

        m_testMode               = new CSetting< int >( m_longSettings, "TEST_MODE",                 0,                       true, false, false );
        m_refreshDelay           = new CSetting< int >( m_longSettings, "REFRESH_DELAY",             ProfileValuesGet( 500 ), true, false, false );
        m_autoViewpointEnable    = new CSetting< int >( m_longSettings, "AUTO_VIEWPOINT_ENABLE",      1,                      true, false, false );
        m_autoViewpointZoomClsup = new CSetting< int >( m_longSettings, "AUTO_VIEWPOINT_ZOOM_CLSUP", 40,                      true, false, false );
        m_invertDigitizingVector = new CSetting< int >( m_longSettings, "INVERT_DIGITIZING_VECTORS", ProfileValuesGet( 0 ),   true, false, false );
        m_deviceVerticalAxis     = new CSetting< int >( m_longSettings, "DEVICE_VERTICAL_AXIS",      ProfileValuesGet( (int)( EStdAxis.Z_POS ) ), true, false, false );

        if ( host_.HostApplication == EHostApplication.IMALIGN )
        { 
            m_IMAMaxEdgeLength     = new CSetting< double >( m_doubleSettings, "IMA_MAX_EDGE_LENGTH",     4.0, true, true, true );
            m_IMAInterpolationStep = new CSetting< double >( m_doubleSettings, "IMA_INTERPOLATION_STEP",  0.4, true, true, true );
            m_IMAMaxAngle          = new CSetting< double >( m_doubleSettings, "IMA_MAX_ANGLE",          75.0, true, true, false );

            m_IMAWindowPositionX        = new CSetting< int >( m_longSettings, "IMA_WINDOW_POS_X",      50,    true, true, false );
            m_IMAWindowPositionY        = new CSetting< int >( m_longSettings, "IMA_WINDOW_POS_Y",      50,    true, true, false );
            m_IMAOptionsWindowPositionX = new CSetting< int >( m_longSettings, "IMA_OPT_WINDOW_POS_X", 100,    true, true, false );
            m_IMAOptionsWindowPositionY = new CSetting< int >( m_longSettings, "IMA_OPT_WINDOW_POS_Y", 100,    true, true, false );
        }
        else if ( host_.HostApplication == EHostApplication.IMINSPECT )
        {
            m_IMIMinSearchDist          = new CSetting< double >( m_doubleSettings, "IMI_MIN_SEARCH_DISTANCE",    0.4,                     true, true, true );
            m_IMIMaxSearchDist          = new CSetting< double >( m_doubleSettings, "IMI_MAX_SEARCH_DISTANCE",    4.0,                     true, true, true );
            m_IMIMinHoleWidth           = new CSetting< double >( m_doubleSettings, "IMI_MIN_HOLE_WIDTH",         ProfileValuesGet( 4.0 ), true, true, true );
            m_IMISharpEdgeMaxPtToPtDist = new CSetting< double >( m_doubleSettings, "IMI_EDGE_MAX_PT_TO_PT_DIST", 4.0,                     true, true, true );
            m_IMISharpEdgeMinAngle      = new CSetting< double >( m_doubleSettings, "IMI_EDGE_MIN_ANGLE",         45.0,                    true, true, false );

            m_IMIExtractNormals         = new CSetting< int >( m_longSettings, "IMI_EXTRACT_NORMALS",       1,                              true, true, false );
            m_IMIRealTimeInspection     = new CSetting< int >( m_longSettings, "IMI_REAL_TIME_INSPECTION",  0,                              true, true, false );
            m_IMIScanType               = new CSetting< int >( m_longSettings, "IMI_SCAN_TYPE",             (int)IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE, true, true, false );
            m_IMIWindowPositionX        = new CSetting< int >( m_longSettings, "IMI_WINDOW_POS_X",          50,                             true, true, false );
            m_IMIWindowPositionY        = new CSetting< int >( m_longSettings, "IMI_WINDOW_POS_Y",          50,                             true, true, false );
            m_IMIOptionsWindowPositionX = new CSetting< int >( m_longSettings, "IMI_OPT_WINDOW_POS_X",      100,                            true, true, false );
            m_IMIOptionsWindowPositionY = new CSetting< int >( m_longSettings, "IMI_OPT_WINDOW_POS_Y",      100,                            true, true, false );
            m_IMIRealTimeMeshing        = new CSetting< int >( m_longSettings, "IMI_RTM",                   1,                              true, true, false );
        }
        else
        {
            System.Diagnostics.Debug.Assert( false );   // Unknown host application!
        }
    }

    // =================================================================================================
    //   The rest of this file is made of getter/setter functions for all settings.
    // -------------------------------------------------------------------------------------------------

    public double IMAMaxEdgeLength
    {
        get { return ValueGet( m_IMAMaxEdgeLength ); }
        set { ValueSet( m_IMAMaxEdgeLength, value ); }
    }

    public double IMAInterpolationStep
    {
        get { return ValueGet( m_IMAInterpolationStep ); }
        set { ValueSet( m_IMAInterpolationStep, value ); }
    }

    public double IMAMaxAngle
    {
        get { return ValueGet( m_IMAMaxAngle ); }
        set { ValueSet( m_IMAMaxAngle, value ); }
    }

    public bool IMIExtractNormals
    {
        get { return BoolValueGet( m_IMIExtractNormals ); }
        set { ValueSet( m_IMIExtractNormals, value ); }
    }

    public double IMIMinHoleWidth
    {
        get { return ValueGet( m_IMIMinHoleWidth ); }
        set { ValueSet( m_IMIMinHoleWidth, value ); }
    }

    public double IMIMaxSearchDist
    {
        get { return ValueGet( m_IMIMaxSearchDist ); }
        set { ValueSet( m_IMIMaxSearchDist, value ); }
    }

    public double IMIMinSearchDist
    {
        get { return ValueGet( m_IMIMinSearchDist ); }
        set { ValueSet( m_IMIMinSearchDist, value ); }
    }

    public bool IMIRealTimeInspection
    {
        get { return ( m_IMIRealTimeInspection != null ) ? BoolValueGet( m_IMIRealTimeInspection ) : false; }
        set { ValueSet( m_IMIRealTimeInspection, value ); }
    }

    public bool IMIRealTimeMeshing
    {
        get { return ( m_IMIRealTimeMeshing != null ) ? BoolValueGet( m_IMIRealTimeMeshing ) : false; }
        set { ValueSet( m_IMIRealTimeMeshing, value ); }
    }

    public double IMISharpEdgeMaxPointToPointDistance
    {
        get { return ValueGet( m_IMISharpEdgeMaxPtToPtDist ); }
        set { ValueSet( m_IMISharpEdgeMaxPtToPtDist, value ); }
    }

    public double IMISharpEdgeMinAngle
    {
        get { return ValueGet( m_IMISharpEdgeMinAngle ); }
        set { ValueSet( m_IMISharpEdgeMinAngle, value ); }
    }

    public int IMIWindowPositionX
    {
        get { return ValueGet( m_IMIWindowPositionX ); }
        set { ValueSet( m_IMIWindowPositionX, value ); }
    }

    public int IMIWindowPositionY
    {
        get { return ValueGet( m_IMIWindowPositionY ); }
        set { ValueSet( m_IMIWindowPositionY, value ); }
    }

    public int AutoViewpointZoomCloseUp
    {
        get { return ValueGet( m_autoViewpointZoomClsup ); }
        set { ValueSet( m_autoViewpointZoomClsup, value ); }
    }

    public EStdAxis DeviceVerticalAxis
    {
        get { return (EStdAxis) ValueGet( m_deviceVerticalAxis ); }
        set { ValueSet( m_deviceVerticalAxis, (int) value ); }
    }

    public int RefreshDelay
    {
        get { return ValueGet( m_refreshDelay ); }
        set { ValueSet( m_refreshDelay, value ); }
    }

    public IMPluginLib.EScanTypes ScanType
    {
        get
        {
            // The scan type can only be configured in PolyWorks|Inspector, while in IMAlign it is always Surface
            if ( HostApplication == EHostApplication.IMINSPECT )
            {
                return (IMPluginLib.EScanTypes) ValueGet( m_IMIScanType );
            }

            System.Diagnostics.Debug.Assert( false );
            return IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE;
        }
        set
        {
            // The scan type can only be configured in PolyWorks|Inspector, while in IMAlign it is always Surface
            if ( HostApplication == EHostApplication.IMINSPECT )
            {
                ValueSet( m_IMIScanType, (int) value );
            }
            else
            {
                System.Diagnostics.Debug.Assert( false );
            }
        }
    }

    public bool TestMode
    {
        get { return BoolValueGet( m_testMode ); }
        set { ValueSet( m_testMode, value ); }
    }

    public bool UseAutoViewpoint
    {
        get { return BoolValueGet( m_autoViewpointEnable ); }
        set { ValueSet( m_autoViewpointEnable, value ); }
    }

    // TODO Add your accessors here.
}

}
