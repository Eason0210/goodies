// =================================================================================================
// CComPlugin class. 
// This class implements the COM Interfaces needed for your plug-in to be used by PolyWorks
// appplications.
//
// Copyright © InnovMetric Logiciels Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System.Collections.Generic;
using IM;
namespace CompanyNameCsLineScanner
{

// =============================================================================================
//   Plug-in's COM object interface used to connect to a PolyWorks module.
// ---------------------------------------------------------------------------------------------
[ System.Runtime.InteropServices.ComVisible( true ) ]
[ System.Runtime.InteropServices.ClassInterface( System.Runtime.InteropServices.ClassInterfaceType.None ) ]
[ System.Runtime.InteropServices.Guid( "7A8D5334-75E7-4819-9EC4-C385BAD64759" ) ]
public class CComPlugin : IMPluginLib.IIMPlugin,
                          IMPluginLib.IIMLanguage,
                          IMPluginLib.IIMUnitsUser,
                          IMPluginLib.IIMCommandEnum,
                          IMPluginLib.IIMSettings3,
                          IMPluginLib.IIMScanner5,
                          IMPluginLib.IIMLineScanner2,
                          IMPluginLib.IIMScanningProfilesUser,
                          IMPluginLib.IIMScanningObjectsUser
{
    private List< IMPluginLib.IIMCommand2 > m_commands = new List< IMPluginLib.IIMCommand2 >();

    private CSettings m_settings;
    private CReceiver m_receiver;
    private CIMHost   m_host;

    // =========================================================================================
    // Adds MSCL commands to the commands vector member variable.
    // -----------------------------------------------------------------------------------------
    private void CommandsAdd()
    {
        {
            // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command a good name and a good description.
            var cmdInfo = new CComCommandInfo( Consts.CMD_SCAN_BOUNDARY_MIN_EDGE_ANGLE, 
                                                  "Sets the sharp edge min angle." );

            var param01 = new CComCommandParameterInfo( "Min angle", 
                                                           IMPluginLib.EParameterDirection.E_PARAM_DIR_IN, 
                                                           IMPluginLib.EParameterType.E_PARAM_TYPE_DOUBLE );
            param01.ValuesSet( "Greater than 0 and smaller than 180" );

            cmdInfo.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

            // Add the command to the command vector
            m_commands.Add( new CCmdSharpEdgeMinAngle( cmdInfo, false, m_settings, m_host ) );
        }

        {
            // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
            var cmdInfo = new CComCommandInfo( Consts.CMD_SCAN_BOUNDARY_MIN_EDGE_ANGLE + Consts.CMD_GET_SUFFIX, 
                                                  "Gets the sharp edge min angle." );

            var param01 = new CComCommandParameterInfo( "Min angle", 
                                                           IMPluginLib.EParameterDirection.E_PARAM_DIR_OUT, 
                                                           IMPluginLib.EParameterType.E_PARAM_TYPE_DOUBLE );
            param01.ValuesSet( "Greater than 0 and smaller than 180" );

            cmdInfo.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

            // Add the command to the command vector
            m_commands.Add( new CCmdSharpEdgeMinAngle( cmdInfo, true, m_settings, m_host ) );
        }

        {
            // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
            var cmdInfo = new CComCommandInfo( Consts.CMD_SCAN_BOUNDARY_MAX_POINT_TO_POINT_DIST, 
                                               "Sets the sharp edge max point to point distance." );

            var param01 = new CComCommandParameterInfo( "Max distance", 
                                                         IMPluginLib.EParameterDirection.E_PARAM_DIR_IN, 
                                                         IMPluginLib.EParameterType.E_PARAM_TYPE_DOUBLE );
            param01.ValuesSet( "Greater than 0" );

            cmdInfo.ParameterEnumGet().CommandParameterAdd( new IM.CComCommandParameter( param01 ) );

            // Add the command to the command vector
            m_commands.Add( new CCmdSharpEdgeMaxPointToPointDist( cmdInfo, false, m_settings, m_host ) );
        }

        {
            // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
            var cmdInfo = new IM.CComCommandInfo( Consts.CMD_SCAN_BOUNDARY_MAX_POINT_TO_POINT_DIST + Consts.CMD_GET_SUFFIX, 
                                                  "Gets the sharp edge max point to point distance." );

            var param01 = new IM.CComCommandParameterInfo( "Max distance", 
                                                           IMPluginLib.EParameterDirection.E_PARAM_DIR_OUT, 
                                                           IMPluginLib.EParameterType.E_PARAM_TYPE_DOUBLE );
            param01.ValuesSet( "Greater than 0" );

            cmdInfo.ParameterEnumGet().CommandParameterAdd( new IM.CComCommandParameter( param01 ) );

            // Add the command to the command vector
            m_commands.Add( new CCmdSharpEdgeMaxPointToPointDist( cmdInfo, true, m_settings, m_host ) );
        }
    }

    // =========================================================================================
    // Releases any commands added in CommandsAdd.
    // -----------------------------------------------------------------------------------------
    private void CommandsRemove()
    {
        m_commands.Clear();
    }

    // =========================================================================================
    // ========================================= IIMPlugin =====================================
    #region IIMPlugin

    // =========================================================================================
    // Returns the plug-in's name.
    //
    // Return: Plug-in's name.
    // -----------------------------------------------------------------------------------------
    public string PlgNameGet()
    {
        return Consts.PLUGIN_NAME;
    }

    // =========================================================================================
    // Returns the plug-in's version in the form of major.minor.dot.
    //
    // Parameter: major_ : Major component of the plug-in's version
    // Parameter: minor_ : Minor component of the plug-in's version
    // Parameter: dot_   : Dot component of the plug-in's version
    // -----------------------------------------------------------------------------------------
    public void PlgVersionGet( ref int major_, ref int minor_, ref int dot_ )
    {
        // TODO Adjust the numbers each time you provide a new version to users.
        major_ = 1;
        minor_ = 0;
        dot_   = 0;
    }

    // =========================================================================================
    // Called when the plug-in is loaded.
    //
    // Parameter: iIMHost_ : Host's application.
    //
    // Return: 1 if everything went well.
    //         0 if something went wrong.
    // -----------------------------------------------------------------------------------------
    public int Load( IMPluginLib.IIMHost iIMHost_ )
    {
        if ( iIMHost_ == null )
        {
            return 0;
        }

        Diagnostics.DiagnosticConfigurationUpdate();

        m_host = CIMHost.Create( iIMHost_ );
            
        var repository = iIMHost_ as IMInspectLib.IIMSettingsRepository2;

        if ( repository == null )
        {
            System.Diagnostics.Debug.Assert( false );
            return 0;
        }

        m_settings = new CSettings( m_host, repository );

        m_receiver = new CReceiver( m_host, m_settings );

        return 1;
    }

    // =========================================================================================
    // Called when the plug-in is unloaded.
    //
    // Return: 1 if everything went well.
    //         0 if something went wrong.
    // -----------------------------------------------------------------------------------------
    public int Unload()
    {
        m_receiver.InterfacePopdown();
        m_receiver.Disconnect();

        CommandsRemove();

        m_host.Dispose();
        m_host = null;
        m_settings.Dispose();
        m_settings = null;
        m_receiver.Dispose();
        m_receiver = null;

        return 1;
    }

    #endregion

    // =========================================================================================
    // ======================================= IIMLanguage =====================================
    #region IIMLanguage

    public void LanguageSet( string language_, string fontName_, IMPluginLib.ECharacterSets charSet_ )
    {
        // TODO: Translate the dialogs in the appropriate language
        //       If this is not required, then remove this method
        //       and all references to IIMLanguage
    }

    #endregion

    // =========================================================================================
    // ====================================== IIMUnitsUser =====================================
    #region IIMUnitsUser

    // =========================================================================================
    // Called by the application when the units used are changed.
    //
    // Parameter: scalingFactor_ : The new scaling factor. This the factor that must be applied
    //                             to go from mm to the currently selected units.
    //                             So (assuming internally you use mm) when sending values to
    //                             the application you must multiply by this factor and when
    //                             receiving values you must divide by this factor.
    //                             For example if the current units are cm, the factor is 0.1.
    // -----------------------------------------------------------------------------------------
    public void UnitsScalingFactorSet( double scalingFactor_ )
    {
        // A PolyWorks plug-in implementing the UnitsScalingFactorSet method should:
        //
        // - use the specified units scaling factor to convert data to be sent
        //   to the application from plug-in units to host application units
        // - use the specified units scaling factor to convert data sent by
        //   the application from host application units to plug-in units

        if ( m_settings.HostUnitsScalingFactorSet( scalingFactor_ ) )
        {
            // TODO: Make appropriate calls to ensure appropriate propagation of new units for data conversion
        }
    }

    #endregion

    // =========================================================================================
    // ====================================== IIMCommandEnum ===================================
    #region IIMCommandEnum

    // =========================================================================================
    // Returns the number of MSCL command's registered by this plug-in.  
    //
    // Return: Number of MSCL command's registered by this plug-in.
    // -----------------------------------------------------------------------------------------
    public int CmdsGetNb()
    {
        if ( m_commands.Count == 0 )
        {
            CommandsAdd();
        }

        return m_commands.Count;
    }

    // =========================================================================================
    // Returns a COM interface pointer to a MSCL command.
    //
    // Parameter: number_     : Index of the command to be returned
    // Parameter: iIMCommand_ : COM interface object.
    //
    // -----------------------------------------------------------------------------------------
    public void CmdGet( int number_, out IMPluginLib.IIMCommand iIMCommand_ )
    {
        iIMCommand_ = null;

        if ( ( number_ >= 0 ) && ( number_ < m_commands.Count ) )
        {
            iIMCommand_ = m_commands[ number_ ];
        }
    }

    #endregion

    // =========================================================================================
    // ======================================= IIMSettings =====================================
    #region IIMSettings

    // =================================================================================================
    //   Called on startup to know the number of settings of type "double" (i.e. floating point).
    //
    // Return : The number of double settings, can be 0 if there are none.
    // -------------------------------------------------------------------------------------------------
    public int DoubleSettingsNbGet()
    {
        return m_settings.DoubleSettingsNbGet();
    }

    // =================================================================================================
    //   Called on startup once for each setting of type "double".
    //
    // Parameter : index_        : Index of the setting whose information are needed. 
    // Parameter : name_         : On output must be set to the setting's name (max 31 characters).
    // Parameter : defaultValue_ : On output must be set to a default value for the setting.
    // Parameter : user_         : On output must always be true.
    // Parameter : host_         : On output must be set to true if the setting can have a different
    //                             value in each application, false if the value is the same for all
    //                             applications.
    // Parameter : project_      : On output must always be false as this is deprecated.
    // -------------------------------------------------------------------------------------------------
    public void DoubleSettingGet( int index_, ref string name_, ref double defaultValue_, ref bool user_, ref bool host_, ref bool project_ )
    {
        m_settings.DoubleSettingGet( index_, ref name_, ref defaultValue_, ref user_, ref host_, ref project_ );
    }

    // =================================================================================================
    //   Called on startup to know the number of settings of type "long" (i.e. integer).
    //
    // Return : The number of long settings, can be 0 if there are none.
    // -------------------------------------------------------------------------------------------------
    public int LongSettingsNbGet()
    {
        return m_settings.LongSettingsNbGet();
    }

    // =================================================================================================
    //   Called on startup once for each setting of type "long".
    //
    // See "double" version for parameter descriptions.
    // -------------------------------------------------------------------------------------------------
    public void LongSettingGet( int index_, ref string name_, ref int defaultValue_, ref bool user_, ref bool host_, ref bool project_ )
    {
        m_settings.LongSettingGet( index_, ref name_, ref defaultValue_, ref user_, ref host_, ref project_ );
    }

    // =================================================================================================
    //   Called on startup to know the number of settings of type "string".
    //
    // Return : The number of string settings, can be 0 if there are none.
    // -------------------------------------------------------------------------------------------------
    public int StringSettingsNbGet()
    {
        return m_settings.StringSettingsNbGet();
    }

    // =================================================================================================
    //   Called on startup once for each setting of type "string".
    //
    // See "double" version for parameter descriptions.
    // -------------------------------------------------------------------------------------------------
    public void StringSettingGet( int index_, ref string name_, ref string defaultValue_, ref bool user_, ref bool host_, ref bool project_ )
    {
        m_settings.StringSettingGet( index_, ref name_, ref defaultValue_, ref user_, ref host_, ref project_ );
    }

    // =================================================================================================
    //   Called on startup to know the number of settings of type "matrix".
    //
    // Return : The number of matrix settings, can be 0 if there are none.
    // -------------------------------------------------------------------------------------------------
    public int MatrixSettingsNbGet()
    {
        return m_settings.MatrixSettingsNbGet();
    }

    // =================================================================================================
    //   Called on startup once for each setting of type "matrix".
    //
    // See "double" version for parameter descriptions.
    // -------------------------------------------------------------------------------------------------
    public void MatrixSettingGet( int index_, ref string name_, ref System.Array defaultValue_, ref bool user_, ref bool host_, ref bool project_ )
    {
        m_settings.MatrixSettingGet( index_, ref name_, ref defaultValue_, ref user_, ref host_, ref project_ );
    }

    // =================================================================================================
    //   This function is called when the application has changed one or more of the plug-in's settings.
    // This can happen for example during the execution of the CONFIG POP command.
    //
    // Parameter : settingsName_ : array containing the name of all parameters that were modified.
    // -------------------------------------------------------------------------------------------------
    public void OnSettingsChange( System.Array settingsName_ )
    {
        // TODO : You should perform whatever action is needed by your plug-in to
        //        adapt to the changed settings.
        //        Note that if your plug-in uses simple settings that are always read
        //        from the CSettings object, you may not have anything to do in this function.
    }

    #endregion

    // =========================================================================================
    // ======================================== IIMScanner =====================================
    #region IIMScanner

    // =================================================================================================
    //   Returns the name of the scanning device. This name is used in the scanning device menu and is
    // also used for the DIGITIZE DEVICE() command.
    //
    // Return : The name
    // -------------------------------------------------------------------------------------------------
    public string ScanningDeviceNameGet()
    {
        // TODO Change this to an appropriate name for your scanning device.
        //      This name will be visible in the user interface.
        return "CompanyName C# Line Scanner";
    }

    // =================================================================================================
    //   The application is asking the plug-in to connect to the device.
    //
    // Parameter : feedback_ : Reference to a COM object to provide feedback to the application.
    //                         This object is valid until ScanningConnectionEnd is called.
    //
    // Return : 1 for success, 0 for failure.
    // -------------------------------------------------------------------------------------------------
    public int ScanningConnectionInit( IMPluginLib.IIMScannerFeedback feedback_ )
    {
        if ( !m_receiver.Connect( feedback_ ) )
        {
            return 0;
        }

        // Synchronize the host application with our own settings
        string command = Utils.CommandBuild( Consts.CMD_AUTO_VIEWPOINT_SET,
                                             m_settings.UseAutoViewpoint );
        m_host.ExecuteCommand( command, false, false, true );

        command = Utils.CommandBuild( Consts.CMD_AUTO_VIEWPOINT_VERTICAL_AXIS_SET,
                                      m_settings.DeviceVerticalAxis );
        m_host.ExecuteCommand( command, false, false, true );

        command = Utils.CommandBuild( Consts.CMD_AUTO_VIEWPOINT_CLOSEUP_ZOOM_SET,
                                      m_settings.AutoViewpointZoomCloseUp );
        m_host.ExecuteCommand( command, false, false, true );

        m_receiver.EnableRealTimeMeshing( m_settings.IMIRealTimeMeshing );

        return 1;
    }

    // =================================================================================================
    //   The application is asking the plug-in to disconnect from the device.
    //
    // Return : 1 for success, 0 for failure.
    // -------------------------------------------------------------------------------------------------
    public int ScanningConnectionEnd()
    {
        return m_receiver.Disconnect() ? 1 : 0;
    }

    // =================================================================================================
    //   The application is asking the plug-in to show its main dialog.
    // -------------------------------------------------------------------------------------------------
    public void ScanningDlgShow()
    {
        m_receiver.InterfacePopup();
    }

    // =================================================================================================
    //   The application is asking the plug-in to close its main dialog.
    // -------------------------------------------------------------------------------------------------
    public void ScanningDlgClose()
    {
        if ( m_receiver != null )
        {
            m_receiver.InterfacePopdown();
        }
    }

    public string ScanNameDefaultGet()
    {
        // This function is obsolete and will not be called by the application.
        return "";
    }

    public void ScanNameSet( string name_ )
    {
        // This function is obsolete and will not be called by the application.
    }

    // =================================================================================================
    //   The next few functions are used by the application to retrieve/set the value of standard
    // settings stored in the plug-in.
    // -------------------------------------------------------------------------------------------------
    public double MeshMaxEdgeLengthGet()
    {
        return m_settings.IMAMaxEdgeLength;
    }

    public void MeshMaxEdgeLengthSet( double value_ )
    {
        m_settings.IMAMaxEdgeLength = value_;
    }

    public double MeshInterpolationStepGet()
    {
        return m_settings.IMAInterpolationStep;
    }

    public void MeshInterpolationStepSet( double value_ )
    {
        m_settings.IMAInterpolationStep = value_;
    }

    public double MeshMaxAngleGet()
    {
        return m_settings.IMAMaxAngle;
    }

    public void MeshMaxAngleSet( double value_ )
    {
        m_settings.IMAMaxAngle = value_;
    }

    // =================================================================================================
    //   Returns a string that describes the location a the menu item for this plug-in in the
    // Tools/Plug-in menu.
    //
    // Return : The location. To have more than one level of sub-menu use a \ for separation.
    // -------------------------------------------------------------------------------------------------
    public string ScanningDeviceMenuLocationGet()
    {
        // TODO Change this to proper values for your device. If you do not want your plug-in to have
        //      an entry in the menu, do not return an empty string (this would create an empty menu
        //      item);
        return "CompanyName\\C# Line Scanner...";
    }

    // =================================================================================================
    //   The application is signaling that a scanning event has occured. The plug-in should react as
    // needed.
    //
    // Parameter : event_ : The event that occured.
    // -------------------------------------------------------------------------------------------------
    public void OnScanningEvent( IMPluginLib.EScanningEvents event_ )
    {
        switch( event_ )
        {
        case IMPluginLib.EScanningEvents.E_SCANNING_EVENT_DEVICE_SELECTED:
        case IMPluginLib.EScanningEvents.E_SCANNING_EVENT_UPDATE_APP_SETTINGS:
            m_receiver.UpdateFromSettings();
            break;
        case IMPluginLib.EScanningEvents.E_SCANNING_EVENT_APP_SETTING_MODIFIED:
            m_receiver.UpdateSettingsFromApp( true );
            break;
        case IMPluginLib.EScanningEvents.E_SCANNING_EVENT_POST_PROFILE_CHANGED:
            m_receiver.UpdateSettingsFromApp( false );
            m_receiver.UpdateFromSettings();
            break;
        // TODO: Add reaction to other events as needed by your plug-in.
        }
    }

    // =================================================================================================
    //   The application is asking the plug-in if it has deprecated names that should still be accepted
    // by the DIGITIZE DEVICE command.
    //
    // Parameter : oldNames_ : On output contains a list of 0 or more names.
    // -------------------------------------------------------------------------------------------------
    public void DeviceDeprecatedNamesGet( ref System.Array oldNames_ )
    {
        // TODO: Implement this method only if your plug-in changes name and there
        //       are existing scripts using the deprecated name(s).
    }

    // =================================================================================================
    //   The application is asking the plug-in if it has an Options dialog.
    //
    // Return : true if the plug-in has an Options dialog, false otherwise.
    // -------------------------------------------------------------------------------------------------
    public bool HasScanningOptionsDlg()
    {
        return true;
    }

    // =================================================================================================
    //   The application is requesting the plug-in to open its Options dialog.
    // -------------------------------------------------------------------------------------------------
    public void ScanningOptionsDlgShow()
    {
        var dialog = new CDlgOptions( m_host );

        dialog.ShowDialog();
    }

    #endregion

    // =========================================================================================
    // ====================================== IIMLineScanner ===================================
    #region IIMLineScanner

    // =================================================================================================
    //   The application is asking the plug-in to activate scanning.
    //
    // Parameter : lineScan_   : Reference to a COM object used to provide scan lines to the application.
    // Parameter : pointCloud_ : Reference to a COM object used to provide individual points to the
    //                           application.
    //
    // Return : 1 for success, 0 for failure.
    // -------------------------------------------------------------------------------------------------
    public int ScanningStart( IMPluginLib.IIMLineScan lineScan_, IMPluginLib.IIMPointCloud pointCloud_ )
    {
        if ( m_receiver.ScanStart( lineScan_, pointCloud_ ) )
        { 
            return 1;
        }

        return 0;
    }

    // =================================================================================================
    //   The application is asking the plug-in to end scanning mode.
    //
    // Return : 1 for success, 0 for failure.
    // -------------------------------------------------------------------------------------------------
    public int ScanningEnd()
    {
        m_receiver.ScanEnd();
        return 1;
    }

    // =================================================================================================
    //   Return the current configured scan type.
    //
    // Return : The type
    // -------------------------------------------------------------------------------------------------
    public IMPluginLib.EScanTypes ScanTypeGet()
    {
        return m_settings.ScanType;
    }

    // =================================================================================================
    //   Sets a new scan type to use.
    //
    // Parameter : scanType_   : The new type.
    //
    // Return : 1 for success, 0 for failure.
    // -------------------------------------------------------------------------------------------------
    public int ScanTypeSet( IMPluginLib.EScanTypes scanType_ )
    {
        // TODO: Optional: if you want your plug-in to support sharp edge scanning (E_SCAN_TYPE_SHARP_EDGE)
        //       or object scanning (E_SCAN_TYPE_OBJECT), add them to the list of supported types below.
        //       You will then have to perform additionnal scan data processing to either extract
        //       and send only boundary points (for boundary scanning) or to create objects
        //       (using MSCL scripts, for example) and send only points related to those objects.
        if ( ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE ) ||
             ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE_AND_BOUNDARY ) ||
             ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SHARP_EDGE ) )
        {
            m_receiver.ScanTypeSet( scanType_ );
            return 1;
        }

        return 0;
    }

    // =================================================================================================
    //   The next few functions are used by the application to retrieve/set the value of standard
    // settings stored in the plug-in.
    // -------------------------------------------------------------------------------------------------
    public bool ExtractNormalsGet()
    {
        return m_settings.IMIExtractNormals;
    }

    public void ExtractNormalsSet( bool extractNormals_ )
    {
        m_settings.IMIExtractNormals = extractNormals_;
    }

    public double ExtractNormalsMinSearchDistGet()
    {
        return m_settings.IMIMinSearchDist;
    }

    public void ExtractNormalsMinSearchDistSet( double minSearchDist_ )
    {
        m_settings.IMIMinSearchDist = minSearchDist_;
    }

    public double ExtractNormalsMaxSearchDistGet()
    {
        return m_settings.IMIMaxSearchDist;
    }

    public void ExtractNormalsMaxSearchDistSet( double maxSearchDist_ )
    {
        m_settings.IMIMaxSearchDist = maxSearchDist_;
    }

    public bool ExtractHoleBoundariesGet()
    {
        // TODO: If you need to extract boundaries when scanning objects (scan type E_SCAN_TYPE_OBJECT),
        //       return "true" instead of the "false" below.
        return false;
    }

    public void ExtractHoleBoundariesSet( bool extractHoleBoundaries_ )
    {
        // Reserved for future use.
    }

    public double ExtractHoleBoundariesMinWidthGet()
    {
        return m_settings.IMIMinHoleWidth;
    }

    public void ExtractHoleBoundariesMinWidthSet( double minWidth_ )
    {
        m_settings.IMIMinHoleWidth = minWidth_;
    }

    public bool TestModeGet()
    {
        return m_settings.TestMode;
    }

    public void TestModeSet( bool testMode_ )
    {
        m_settings.TestMode = testMode_;
    }

    public bool RealTimeComparisonGet()
    {
        return m_settings.IMIRealTimeInspection;
    }

    public void RealTimeComparisonSet( bool realTimeComp_ )
    {
        m_settings.IMIRealTimeInspection = realTimeComp_;
        m_receiver.EnableRealTimeInspection( realTimeComp_ );
    }

    #endregion

    // =========================================================================================
    // ================================== IIMScanningProfilesUser ==============================
    #region IIMScanningProfilesUser

    // =================================================================================================
    //   Returns the list of settings that are part of a scanning profile.
    //
    // Parameter : names_ : On output contains the name of all settings that are part of scanning
    //                      profiles. All names must be valid setting names registered through the
    //                      IIMSettings interface.
    // -------------------------------------------------------------------------------------------------
    public void ScanningProfileSettingsGet( ref System.Array names_ )
    {
        m_settings.ScanningProfileSettingsGet( ref names_ );
    }

    // =================================================================================================
    //   Returns the value of a double profile setting for a given standard profile.
    //
    // Parameter : profile_ : The requested standard profile
    // Parameter : name_    : The requested setting's name
    // Parameter : value_   : On output must be set to the value of the requested setting in the
    //                        requested profile.
    // -------------------------------------------------------------------------------------------------
    public void StandardScanningProfileDoubleSettingValueGet( IMPluginLib.EStandardScanningProfiles profile_, string name_, out double value_ )
    {
        m_settings.StandardScanningProfileDoubleSettingValueGet( profile_, name_, out value_ );
    }

    // =================================================================================================
    //   Returns the value of a long profile setting for a given standard profile.
    //
    // Parameter : profile_ : The requested standard profile
    // Parameter : name_    : The requested setting's name
    // Parameter : value_   : On output must be set to the value of the requested setting in the
    //                        requested profile.
    // -------------------------------------------------------------------------------------------------
    public void StandardScanningProfileLongSettingValueGet( IMPluginLib.EStandardScanningProfiles profile_, string name_, out int value_ )
    {
        m_settings.StandardScanningProfileLongSettingValueGet( profile_, name_, out value_ );
    }

    // =================================================================================================
    //   Returns the value of a string profile setting for a given standard profile.
    //
    // Parameter : profile_ : The requested standard profile
    // Parameter : name_    : The requested setting's name
    // Parameter : value_   : On output must be set to the value of the requested setting in the
    //                        requested profile.
    // -------------------------------------------------------------------------------------------------
    public void StandardScanningProfileStringSettingValueGet( IMPluginLib.EStandardScanningProfiles profile_, string name_, out string value_ )
    {
        m_settings.StandardScanningProfileStringSettingValueGet( profile_, name_, out value_ );
    }

    // =================================================================================================
    //   Sets the list of available scanning profiles for scanning, and specifies the current profile.
    //
    // Parameter : profileCmdArgNames_     : Profile names to use to designate a profile through a
    //                                       MSCL command argument.
    // Parameter : profileDisplayNames_    : Profile names to use in a graphical user interface.
    // Parameter : profileAdditionalInfos_ : Extended profile information.
    // Parameter : currentProfile_         : Current profile among the list in profileCmdArgNames_.
    // -------------------------------------------------------------------------------------------------
    public void ScanningProfilesSet( ref System.Array profileCmdArgNames_,
                                     ref System.Array profileDisplayNames_,
                                     ref System.Array profileAdditionalInfos_,
                                     string           currentProfile_ )
    {
        m_receiver.ScanningProfilesSet( profileCmdArgNames_, profileDisplayNames_, profileAdditionalInfos_, currentProfile_ );
    }

    #endregion

    // =========================================================================================
    // ================================== IIMScanningObjectsUser ===============================
    #region IIMScanningObjectsUser

    // =================================================================================================
    //   Sets the list of available scanning objects for a given scan type, and specifies the current
    // choice identifying which scanning object will receive future scanned points of the given type.
    //
    // Parameter : scanType_      : Scan type to which the objects are related (E_SCAN_TYPE_SURFACE,
    //                              E_SCAN_TYPE_SHARP_EDGE or E_SCAN_TYPE_OBJECT)
    // Parameter : objectNames_   : Available object names
    // Parameter : currentChoice_ : Current choice. If the current choice is a name that does not
    //                              appear in objectNames_, this means that a new object with
    //                              this name will be created upon receiving new scanned points.
    // -------------------------------------------------------------------------------------------------
    public void ScanningObjectsSet( IMPluginLib.EScanTypes scanType_, ref System.Array objectNames_, string currentChoice_ )
    {
        if ( m_receiver != null )
        {
            m_receiver.ScanningObjectsSet( scanType_, ref objectNames_, currentChoice_ );
        }
    }

    #endregion
}

}
