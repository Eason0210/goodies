// =================================================================================================
//   CSettings class
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------
using IM;
using System.ComponentModel;

namespace CompanyNameCsPlanarScanner
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
    // TODO : Add any double settings your plug-in requires.

    private CSetting< int >    m_refreshDelay;
    private CSetting< int >    m_autoViewpointEnable;
    private CSetting< int >    m_autoViewpointZoomClsup;
    private CSetting< int >    m_invertDigitizingVector;
    private CSetting< int >    m_deviceVerticalAxis;
    private CSetting< int >    m_IMAWindowPositionX;
    private CSetting< int >    m_IMAWindowPositionY;
    private CSetting< int >    m_IMAOptionsWindowPositionX;
    private CSetting< int >    m_IMAOptionsWindowPositionY;
    private CSetting< int >    m_IMIConvertToPolygonal;
    private CSetting< int >    m_IMICreateNewDevicePositionOnScan;
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
            
        m_refreshDelay                  = new CSetting< int >( m_longSettings, "REFRESH_DELAY",                         ProfileValuesGet( 500 ), true, false, false );
        m_autoViewpointEnable           = new CSetting< int >( m_longSettings, "AUTO_VIEWPOINT_ENABLE",                 1,                       true, false, false );
        m_autoViewpointZoomClsup        = new CSetting< int >( m_longSettings, "AUTO_VIEWPOINT_ZOOM_CLSUP",             40,                      true, false, false );
        m_invertDigitizingVector        = new CSetting< int >( m_longSettings, "INVERT_DIGITIZING_VECTORS",             ProfileValuesGet( 0 ),   true, false, false );
        m_deviceVerticalAxis            = new CSetting< int >( m_longSettings, "DEVICE_VERTICAL_AXIS",                  ProfileValuesGet( (int)( EStdAxis.Z_POS ) ), true, false, false );
        
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
            m_IMIConvertToPolygonal            = new CSetting< int >( m_longSettings, "IMI_CONVERT_TO_POLYGONAL",              0,                              true, true, false );
            m_IMICreateNewDevicePositionOnScan = new CSetting< int >( m_longSettings, "IMI_CREATE_NEW_DEVIE_POSITION_ON_SCAN", 0,                              true, false, false );       
            m_IMIWindowPositionX               = new CSetting< int >( m_longSettings, "IMI_WINDOW_POS_X",                      50,                             true, true, false );
            m_IMIWindowPositionY               = new CSetting< int >( m_longSettings, "IMI_WINDOW_POS_Y",                      50,                             true, true, false );
            m_IMIOptionsWindowPositionX        = new CSetting< int >( m_longSettings, "IMI_OPT_WINDOW_POS_X",                  100,                            true, true, false );
            m_IMIOptionsWindowPositionY        = new CSetting< int >( m_longSettings, "IMI_OPT_WINDOW_POS_Y",                  100,                            true, true, false );
            m_IMIRealTimeMeshing               = new CSetting< int >( m_longSettings, "IMI_RTM",                               1,                              true, true, false );
        }
        else
        {
            System.Diagnostics.Debug.Assert( false );   // Unknown host application!
        }
    }

    // =================================================================================================
    //   The rest of this file is made of getter/setter functions for all settings.
    // -------------------------------------------------------------------------------------------------
    
    public bool IMIConvertToPolygonal
    {
        get { return BoolValueGet( m_IMIConvertToPolygonal ); }
        set { ValueSet( m_IMIConvertToPolygonal, value );  }
    }

    public bool IMIRealTimeMeshing
    {
        get { return ( m_IMIRealTimeMeshing != null ) ? BoolValueGet( m_IMIRealTimeMeshing ) : false; }
        set { ValueSet( m_IMIRealTimeMeshing, value ); }
    }

    public double IMAMaxEdgeLength
    {
        get { return ValueGet(m_IMAMaxEdgeLength); }
        set { ValueSet(m_IMAMaxEdgeLength, value); }
    }

    public double IMAInterpolationStep
    {
        get { return ValueGet(m_IMAInterpolationStep); }
        set { ValueSet(m_IMAInterpolationStep, value); }
    }

    public double IMAMaxAngle
    {
        get { return ValueGet(m_IMAMaxAngle); }
        set { ValueSet(m_IMAMaxAngle, value); }
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

    public bool UseAutoViewpoint
    {
        get { return BoolValueGet( m_autoViewpointEnable ); }
        set { ValueSet( m_autoViewpointEnable, value ); }
    }

    public int IMAWindowPositionX
    {
        get { return ValueGet( m_IMAOptionsWindowPositionX ); }
        set { ValueSet( m_IMAOptionsWindowPositionX, value ); }
    }
    public int IMAWindowPositionY
    {
        get { return ValueGet( m_IMAOptionsWindowPositionY ); }
        set { ValueSet( m_IMAOptionsWindowPositionY, value ); }
    }

    public bool CreateNewDevicePositionOnScan
    { 
        get { return BoolValueGet( m_IMICreateNewDevicePositionOnScan ); }
        set { ValueSet( m_IMICreateNewDevicePositionOnScan, value ); }
    }
    // TODO Add your accessors here.
}

}
