// =================================================================================================
//   CSettingsBase class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;

namespace IM
{

// =================================================================================================
//   Simple utility structure to manage information on a setting.
// -------------------------------------------------------------------------------------------------
class CSetting< T >
{
    public string    m_name;
    public T         m_defaultValue;
    public List< T > m_profileValues;
    public bool      m_isUserSpecific;
    public bool      m_isHostSpecific;
    public bool      m_isDistance;

    // =================================================================================================
    //   Constructor for a setting that is not part of scanning profiles.
    //
    // Parameter : list_         : List to add the setting to.
    // Parameter : name_         : Setting's name
    // Parameter : defaultValue_ : Initial value of setting
    // Parameter : user_         : Should always be true
    // Parameter : host_         : true to have different values in Inspector and IMAlign, false to
    //                             have the same value in all applications.
    // Parameter : isDistance_   : This parameter applies only to "double" settings. If it is true
    //                             the values will automatically be scaled by the current scaling
    //                             factor.
    // -------------------------------------------------------------------------------------------------
    public CSetting( List< CSetting< T > > list_, string name_, T defaultValue_, bool user_, bool host_, bool isDistance_ )
    {
        m_name           = name_;
        m_defaultValue   = defaultValue_;
        m_isUserSpecific = user_;
        m_isHostSpecific = host_;
        m_isDistance     = isDistance_;

        list_.Add( this );
    }

    // =================================================================================================
    //   Constructor for a scanning profile setting.
    //
    // Parameter : list_          : List to add the setting to.
    // Parameter : name_          : Setting's name
    // Parameter : profileValues_ : Values for each profile. The list size must be the same as the
    //                              number of profiles. The default value for the setting will be the
    //                              value for the "standard resolution" profile.
    // Parameter : user_          : Should always be true
    // Parameter : host_          : true to have different values in Inspector and IMAlign, false to
    //                              have the same value in all applications.
    // Parameter : isDistance_    : This parameter applies only to "double" settings. If it is true
    //                              the values will automatically be scaled by the current scaling
    //                              factor.
    // -------------------------------------------------------------------------------------------------
    public CSetting( List< CSetting< T > > list_, string name_, List< T > profileValues_,
                     bool user_, bool host_, bool isDistance_ )
    {
        System.Diagnostics.Debug.Assert( profileValues_.Count == (int) IMPluginLib.EStandardScanningProfiles.E_LAST_STD_SCAN_PROFILE + 1 );

        int standardIndex = (int) IMPluginLib.EStandardScanningProfiles.E_STD_SCAN_PROFILE_STANDARD_RES;

        m_name           = name_;
        m_defaultValue   = profileValues_[ standardIndex ];
        m_profileValues  = profileValues_;
        m_isUserSpecific = user_;
        m_isHostSpecific = host_;
        m_isDistance     = isDistance_;

        list_.Add( this );
    }

    // =================================================================================================
    //   Indicates if a setting is part of scanning profiles.
    //
    // Return : true if a profile setting, false if not.
    // -------------------------------------------------------------------------------------------------
    public bool IsProfileSetting()
    {
        return ( m_profileValues != null ) && ( m_profileValues.Count != 0 );
    }
};

// =================================================================================================
//   Base class form settings management. This class defines the basic behavior that you can
// reuse in multiple plugins. A derived class then defines behavior specific to a given plug-in.
// -------------------------------------------------------------------------------------------------
class CSettingsBase : IDisposable
{
    private   CIMHost                             m_host;
    private   IMInspectLib.IIMSettingsRepository2 m_repository;
    private   double                              m_hostUnitsScalingFactor = 1;
    private readonly string                       m_pluginName;

    protected List< CSetting< double > >    m_doubleSettings = new List< CSetting< double > >();
    protected List< CSetting< int > >       m_longSettings   = new List< CSetting< int > >();
    protected List< CSetting< string > >    m_stringSettings = new List< CSetting< string > >();
    protected List< CSetting< double[,] > > m_matrixSettings = new List< CSetting< double[,] > >();

    // =================================================================================================
    //   Constructor
    //
    // Parameter : host_            : Access to host application functionalities.
    // Parameter : repository_      : COM setting access object. Must not be null.
    // -------------------------------------------------------------------------------------------------
    public CSettingsBase( string                              pluginName_,
                          CIMHost                             host_,
                          IMInspectLib.IIMSettingsRepository2 repository_ )
    {
        System.Diagnostics.Debug.Assert( repository_ != null );
        m_pluginName = pluginName_;
        m_host       = host_; 
        m_repository = repository_;
    }

    // =================================================================================================
    //   Destructor
    //
    // Frees unmanaged resources.
    // -------------------------------------------------------------------------------------------------
    ~CSettingsBase()
    {
        Dispose( false );
    }

    // =================================================================================================
    //   Internal code for freeing unmanaged resources common to destructor and Dispose.
    //
    // Parameter : disposing_ : true if calling from Dispose, false if calling from destructor.
    // -------------------------------------------------------------------------------------------------
    private void Dispose( bool disposing_ )
    {
        Utils.COMObjectRelease( ref m_repository );

        if ( disposing_ )
        {
            // We have freed the resources, tell the GC it does not need to Finalize this object.
            GC.SuppressFinalize( this );
        }
    }

    // =================================================================================================
    //   Implementation of IDisposable interface.
    // -------------------------------------------------------------------------------------------------
    public void Dispose()
    {
        Dispose( true );
    }

    // =================================================================================================
    //   Property access.
    // -------------------------------------------------------------------------------------------------
    protected EHostApplication HostApplication
    {
        get { return m_host.HostApplication; }
    }

    public double HostUnitsScalingFactor
    {
        get { return m_hostUnitsScalingFactor; }
    }

    // =================================================================================================
    //   Assigns scaling factor for application units usage.
    //
    // Parameter : newValue_ : The new scaling factor to use.
    //
    // Return : true if the new value is deemed valid, false otherwise.
    // -------------------------------------------------------------------------------------------------
    public bool HostUnitsScalingFactorSet( double newValue_ )
    {
        if ( newValue_ <= 0.0 )
        {
            return false;
        }

        // Recording new scaling factor
        m_hostUnitsScalingFactor = newValue_;

        return true;
    }

    // =================================================================================================
    //   Utility function to generate the scanning profile values with the same value for all
    // profiles.
    //
    // Parameter : value_ : The value to duplicate in all profiles.
    // -------------------------------------------------------------------------------------------------
    protected List< T > ProfileValuesGet< T >( T value_ )
    {
        List< T > result = new List< T >();

        int start = (int) IMPluginLib.EStandardScanningProfiles.E_FIRST_STD_SCAN_PROFILE;
        int end   = (int) IMPluginLib.EStandardScanningProfiles.E_LAST_STD_SCAN_PROFILE;

        for( int i = start; i <= end; ++i )
        {
            result.Add( value_ );
        }

        return result;
    }

    // =================================================================================================
    //   Returns a double setting's value (scaled if needed).
    //
    // Parameter : setting_ : Setting whose value we want.
    // 
    // Return : The value
    // -------------------------------------------------------------------------------------------------
    protected double ValueGet( CSetting< double > setting_ )
    {
        System.Diagnostics.Debug.Assert( m_repository != null );

        double result = m_repository.DoubleValueGet( m_pluginName, setting_.m_name );

        if ( setting_.m_isDistance )
        {
            result *= m_hostUnitsScalingFactor;
        }

        return result;
    }

    // =================================================================================================
    //   Set the value of a double setting (scaled if needed).
    //
    // Parameter : setting_ : The setting to change.
    // Parameter : value_   : The new value to write.
    // -------------------------------------------------------------------------------------------------
    protected void ValueSet( CSetting< double > setting_, double value_ )
    {
        System.Diagnostics.Debug.Assert( m_repository != null );

        if ( setting_.m_isDistance )
        {
            value_ /= m_hostUnitsScalingFactor;
        }

        m_repository.DoubleValueSet( m_pluginName, setting_.m_name, value_ );
    }

    // =================================================================================================
    //   Returns a long setting's value.
    //
    // Parameter : setting_ : Setting whose value we want.
    // 
    // Return : The value
    // -------------------------------------------------------------------------------------------------
    protected int ValueGet( CSetting< int > setting_ )
    {
        System.Diagnostics.Debug.Assert( m_repository != null );

        return m_repository.LongValueGet( m_pluginName, setting_.m_name );
    }

    // =================================================================================================
    //   Set the value of a long setting.
    //
    // Parameter : setting_ : The setting to change.
    // Parameter : value_   : The new value to write.
    // -------------------------------------------------------------------------------------------------
    protected void ValueSet( CSetting< int > setting_, int value_ )
    {
        System.Diagnostics.Debug.Assert( m_repository != null );

        m_repository.LongValueSet( m_pluginName, setting_.m_name, value_ );
    }

    // =================================================================================================
    //   Returns a long setting's value as a boolean.
    //
    // Parameter : setting_ : Setting whose value we want.
    // 
    // Return : The value
    // -------------------------------------------------------------------------------------------------
    protected bool BoolValueGet( CSetting< int > setting_ )
    {
        System.Diagnostics.Debug.Assert( m_repository != null );

        return m_repository.LongValueGet( m_pluginName, setting_.m_name ) != 0;
    }

    // =================================================================================================
    //   Set the value of a long setting as a bool.
    //
    // Parameter : setting_ : The setting to change.
    // Parameter : value_   : The new value to write.
    // -------------------------------------------------------------------------------------------------
    protected void ValueSet( CSetting< int > setting_, bool value_ )
    {
        System.Diagnostics.Debug.Assert( m_repository != null );

        m_repository.LongValueSet( m_pluginName, setting_.m_name, value_ ? 1 : 0 );
    }

    // =================================================================================================
    //   Returns a string setting's value.
    //
    // Parameter : setting_ : Setting whose value we want.
    // 
    // Return : The value
    // -------------------------------------------------------------------------------------------------
    protected string ValueGet( CSetting< string > setting_ )
    {
        System.Diagnostics.Debug.Assert( m_repository != null );

        return m_repository.StringValueGet( m_pluginName, setting_.m_name );
    }

    // =================================================================================================
    //   Set the value of a string setting.
    //
    // Parameter : setting_ : The setting to change.
    // Parameter : value_   : The new value to write.
    // -------------------------------------------------------------------------------------------------
    protected void ValueSet( CSetting< string > setting_, string value_ )
    {
        System.Diagnostics.Debug.Assert( m_repository != null );

        m_repository.StringValueSet( m_pluginName, setting_.m_name, value_ );
    }

    // =================================================================================================
    //   Helper function for the IIMSetting interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public int DoubleSettingsNbGet()
    {
        return m_doubleSettings.Count;
    }

    // =================================================================================================
    //   Helper function for the IIMSettings interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public void DoubleSettingGet( int        index_,
                                  ref string name_,
                                  ref double defaultValue_,
                                  ref bool   user_,
                                  ref bool   host_,
                                  ref bool   project_ )
    {
        System.Diagnostics.Debug.Assert( index_ < m_doubleSettings.Count );

        name_         = m_doubleSettings[ index_ ].m_name;
        defaultValue_ = m_doubleSettings[ index_ ].m_defaultValue;
        user_         = m_doubleSettings[ index_ ].m_isUserSpecific;
        host_         = m_doubleSettings[ index_ ].m_isHostSpecific;
        project_      = false;
    }

    // =================================================================================================
    //   Helper function for the IIMSettings interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public int LongSettingsNbGet()
    {
        return m_longSettings.Count;
    }

    // =================================================================================================
    //   Helper function for the IIMSettings interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public void LongSettingGet( int        index_,
                                ref string name_,
                                ref int    defaultValue_,
                                ref bool   user_,
                                ref bool   host_,
                                ref bool   project_ )
    {
        System.Diagnostics.Debug.Assert( index_ < m_longSettings.Count );

        name_         = m_longSettings[ index_ ].m_name;
        defaultValue_ = m_longSettings[ index_ ].m_defaultValue;
        user_         = m_longSettings[ index_ ].m_isUserSpecific;
        host_         = m_longSettings[ index_ ].m_isHostSpecific;
        project_      = false;
    }

    // =================================================================================================
    //   Helper function for the IIMSettings interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public int StringSettingsNbGet()
    {
        return m_stringSettings.Count;
    }

    // =================================================================================================
    //   Helper function for the IIMSettings interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public void StringSettingGet( int        index_,
                                  ref string name_,
                                  ref string defaultValue_,
                                  ref bool   user_,
                                  ref bool   host_,
                                  ref bool   project_ )
    {
        System.Diagnostics.Debug.Assert( index_ < m_stringSettings.Count );

        name_         = m_stringSettings[ index_ ].m_name;
        defaultValue_ = m_stringSettings[ index_ ].m_defaultValue;
        user_         = m_stringSettings[ index_ ].m_isUserSpecific;
        host_         = m_stringSettings[ index_ ].m_isHostSpecific;
        project_      = false;
    }

    // =================================================================================================
    //   Helper function for the IIMSettings2 interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public int MatrixSettingsNbGet()
    {
        return m_matrixSettings.Count;
    }

    // =================================================================================================
    //   Helper function for the IIMSettings2 interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public void MatrixSettingGet( int        index_,
                                  ref string name_,
                                  ref Array  defaultValue_,
                                  ref bool   user_,
                                  ref bool   host_,
                                  ref bool   project_ )
    {
        System.Diagnostics.Debug.Assert( index_ < m_matrixSettings.Count );

        name_         = m_matrixSettings[ index_ ].m_name;
        defaultValue_ = m_matrixSettings[ index_ ].m_defaultValue;
        user_         = m_matrixSettings[ index_ ].m_isUserSpecific;
        host_         = m_matrixSettings[ index_ ].m_isHostSpecific;
        project_      = false;
    }

    // =================================================================================================
    //   Count the number of scanning profile settings.
    //
    // Parameter : list_ : The list to analyze.
    //
    // Return : The number of scanning profile settings in the list.
    // -------------------------------------------------------------------------------------------------
    private int ProfileSettingsCount< T >( List< CSetting< T > > list_ )
    {
        int count = 0;

        foreach( CSetting< T > setting in list_ )
        {
            if ( setting.IsProfileSetting() )
            {
                ++count;
            }
        }

        return count;
    }

    // =================================================================================================
    //   Utility function to export scanning profiles setting names.
    //
    // Parameter : list_          : List of settings to export from.
    // Parameter : names_         : Array to export to.
    // Parameter : startingIndex_ : Index to start exporting to.
    // -------------------------------------------------------------------------------------------------
    private void ProfileSettingsExport< T >( List< CSetting< T > > list_,
                                             System.Array          names_,
                                             ref int               startingIndex_ )
    {
        foreach( CSetting< T > setting in list_ )
        {
            if ( setting.IsProfileSetting() )
            {
                names_.SetValue( setting.m_name, startingIndex_ );
                ++startingIndex_;
            }
        }
    }

    // =================================================================================================
    //   Utility function to export the value of a scanning profiles setting.
    //
    // Parameter : list_          : List where the required setting can be found.
    // Parameter : profile_       : Which profile we want the value from.
    // Parameter : name_          : Name of the desired setting.
    //
    // Return : The value
    // -------------------------------------------------------------------------------------------------
    private T StandardScanningProfileSettingValueGet< T >( List< CSetting< T > >                 list_,
                                                           IMPluginLib.EStandardScanningProfiles profile_,
                                                           string                                name_ )
    {
        int profile = (int) profile_;

        foreach( CSetting< T > setting in list_ )
        {
            if ( ( setting.m_name == name_ ) && 
                   setting.IsProfileSetting() &&
                 ( profile >= 0 ) &&
                 ( profile < setting.m_profileValues.Count ) )
            {
                return setting.m_profileValues[ profile ];
            }
        }

        return default(T);
    }

    // =================================================================================================
    //   Helper function for the IIMScanningProfilesUser interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public void ScanningProfileSettingsGet( ref System.Array names_ )
    {
        int count = ProfileSettingsCount( m_doubleSettings );

        count += ProfileSettingsCount( m_longSettings );
        count += ProfileSettingsCount( m_stringSettings );

        names_ = System.Array.CreateInstance( typeof( string ), count );

        count = 0;
        ProfileSettingsExport( m_doubleSettings, names_, ref count );
        ProfileSettingsExport( m_longSettings, names_, ref count );
        ProfileSettingsExport( m_stringSettings, names_, ref count );
    }

    // =================================================================================================
    //   Helper function for the IIMScanningProfilesUser interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public void StandardScanningProfileDoubleSettingValueGet( IMPluginLib.EStandardScanningProfiles profile_,
                                                              string     name_,
                                                              out double value_ )
    {
        value_ = StandardScanningProfileSettingValueGet( m_doubleSettings, profile_, name_ );
    }     

    // =================================================================================================
    //   Helper function for the IIMScanningProfilesUser interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public void StandardScanningProfileLongSettingValueGet( IMPluginLib.EStandardScanningProfiles profile_,
                                                            string  name_,
                                                            out int value_ )
    {
        value_ = StandardScanningProfileSettingValueGet( m_longSettings, profile_, name_ );
    }     

    // =================================================================================================
    //   Helper function for the IIMScanningProfilesUser interface in the CComPlugin class.
    // -------------------------------------------------------------------------------------------------
    public void StandardScanningProfileStringSettingValueGet( IMPluginLib.EStandardScanningProfiles profile_,
                                                              string     name_,
                                                              out string value_ )
    {
        value_ = StandardScanningProfileSettingValueGet( m_stringSettings, profile_, name_ );
    }     
}

}
