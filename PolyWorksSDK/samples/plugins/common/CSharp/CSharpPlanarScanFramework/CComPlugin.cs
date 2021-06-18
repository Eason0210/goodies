// =================================================================================================
// CComPlugin class. 
// This class implements the COM Interfaces needed for your plug-in to be used by PolyWorks
// appplications.
//
// Copyright © InnovMetric Logiciels Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System.Collections.Generic;

namespace CompanyNameCsPlanarScanner
{

// =============================================================================================
//   Plug-in's COM object interface used to connect to a PolyWorks module.
// ---------------------------------------------------------------------------------------------
[ System.Runtime.InteropServices.ComVisible( true ) ]
[ System.Runtime.InteropServices.ClassInterface( System.Runtime.InteropServices.ClassInterfaceType.None ) ]
[ System.Runtime.InteropServices.Guid("da3ff608-e186-4d67-b172-bfbd0ce4bd23") ]
public class CComPlugin : IMPluginLib.IIMPlugin,
                          IMPluginLib.IIMLanguage,
                          IMPluginLib.IIMUnitsUser,
                          IMPluginLib.IIMCommandEnum,
                          IMPluginLib.IIMSettings3,
                          IMPluginLib.IIMScanner5,
                          IMPluginLib.IIMPlanarScanner,
                          IMPluginLib.IIMScanningObjectsUser
{
    private List< IMPluginLib.IIMCommand2 > m_commands = new List< IMPluginLib.IIMCommand2 >();

    private CSettings m_settings;
    private CReceiver m_receiver;
    private IM.CIMHost   m_host;

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

        IM.Diagnostics.DiagnosticConfigurationUpdate();

        m_host = IM.CIMHost.Create( iIMHost_ );

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
        return "CompanyName C# Planar Scanner";
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
        string command = IM.Utils.CommandBuild( Consts.CMD_AUTO_VIEWPOINT_SET,
                                                m_settings.UseAutoViewpoint );
        m_host.ExecuteCommand( command, false, false, true );

        command = IM.Utils.CommandBuild( Consts.CMD_AUTO_VIEWPOINT_VERTICAL_AXIS_SET,
                                         m_settings.DeviceVerticalAxis );
        m_host.ExecuteCommand( command, false, false, true );

        command = IM.Utils.CommandBuild( Consts.CMD_AUTO_VIEWPOINT_CLOSEUP_ZOOM_SET,
                                         m_settings.AutoViewpointZoomCloseUp );
        m_host.ExecuteCommand( command, false, false, true );

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

    public void MeshMaxEdgeLengthSet(double value_)
    {
        m_settings.IMAMaxEdgeLength = value_;
    }

    public double MeshInterpolationStepGet()
    {
        return m_settings.IMAInterpolationStep;
    }

    public void MeshInterpolationStepSet(double value_)
    {
        m_settings.IMAInterpolationStep = value_;
    }

    public double MeshMaxAngleGet()
    {
        return m_settings.IMAMaxAngle;
    }

    public void MeshMaxAngleSet(double value_)
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
        // TODO Change this to proper values for your device. 
        return "CompanyName\\C# Planar Scanner...";
    }

    // =================================================================================================
    //   The application is signaling that a scanning event has occured. The plug-in should react as
    // needed.
    //
    // Parameter : event_ : The event that occured.
    // -------------------------------------------------------------------------------------------------
    public void OnScanningEvent( IMPluginLib.EScanningEvents event_ )
    {
    // TODO: React to the scanning events that might happen in the host application
    //
    // if( event_ == E_SCANNING_EVENT_LEAVING_SCAN_MODE )
    // {
    //     // Any reaction to this event...
    // }
    //
    // For more information see the sample: CSharpLineScanFramework
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
        // Dialog option is only supported for PolyWorks|Align 
        return m_host.HostApplication == IM.EHostApplication.IMALIGN;
    }

    // =================================================================================================
    //   The application is requesting the plug-in to open its Options dialog.
    // -------------------------------------------------------------------------------------------------
    public void ScanningOptionsDlgShow()
    {
        // Dialog option is only supported for PolyWorks|Align 
        if ( m_host.HostApplication == IM.EHostApplication.IMALIGN )
        {
                var dialog = new CDlgOptions( m_host, m_settings );

                dialog.ShowDialog();
            }
        }

    #endregion

    // =========================================================================================
    // ====================================== IIMPlanarScanner ===================================
    #region IIMPlanarScanner

    // =================================================================================================
    //   The application is asking the plug-in to activate scanning.
    //
    // Parameter : lineScan_   : Reference to a COM object used to provide scan lines to the application.
    // Parameter : pointCloud_ : Reference to a COM object used to provide individual points to the
    //                           application.
    //
    // Return : 1 for success, 0 for failure.
    // -------------------------------------------------------------------------------------------------
    public int ScanningStart( IMPluginLib.IIMPlanarGrid planarGrid_ )
    {
        if ( m_receiver.ScanStart( planarGrid_ ) )
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
    //   The next few functions are used by the application to retrieve/set the value of standard
    // settings stored in the plug-in.
    // -------------------------------------------------------------------------------------------------
    public bool ConvertToPolygonalModelGet()
    {
        return m_settings.IMIConvertToPolygonal;
    }
    public void ConvertToPolygonalModelSet( bool convertToPolygonalModel_ )
    {
        m_settings.IMIConvertToPolygonal = convertToPolygonalModel_;
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
