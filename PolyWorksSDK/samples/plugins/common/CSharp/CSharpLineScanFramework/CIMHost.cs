// =================================================================================================
//   CIMHost class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;

namespace IM
{

// =================================================================================================
//   Enumeration used to indicate which application is currently hosting the plug-in.
// -------------------------------------------------------------------------------------------------
enum EHostApplication
{
    UNKNOWN,
    IMALIGN,
    IMEDIT,
    IMINSPECT
}

// =================================================================================================
//   Class encapsulating functionalities provided by the host application.
// -------------------------------------------------------------------------------------------------
class CIMHost : IDisposable
{
    private const string SCRIPT_VERSION_DECLARATION = "version \"5.0\"\n";
    private const string BASE_VAR_NAME = "variable";

    private IMPluginLib.IIMHost           m_host;
    private IMInspectLib.IIMCommandCenter m_commandCenter;
    private EHostApplication              m_hostApplication = EHostApplication.UNKNOWN;

    // =================================================================================================
    //   Private constructor
    //
    // Parameter : iIMHost_         : COM object for access to host application functionality.
    //                                 Must not be null.
    // Parameter : commandCenter_   : Command center object for calling command with host application.
    //                                 Must not be null.
    // Parameter : hostApplication_ : Application (Inspector, IMAlign are supported)
    // -------------------------------------------------------------------------------------------------
    private CIMHost( IMPluginLib.IIMHost iIMHost_, IMInspectLib.IIMCommandCenter commandCenter_, IM.EHostApplication hostApplication_ )
    {
        System.Diagnostics.Debug.Assert( iIMHost_ != null );
        m_host = iIMHost_;
        m_commandCenter = commandCenter_;
        m_hostApplication = hostApplication_;
    }
    
    // =================================================================================================
    //   Creates a CIMHost and returns null if creation failed.
    //
    // Parameter : iIMHost_ : COM object for access to host application functionality.
    //                        Must not be null.
    // -------------------------------------------------------------------------------------------------
    public static CIMHost Create(IMPluginLib.IIMHost iIMHost_)
    {
        System.Diagnostics.Debug.Assert(iIMHost_ != null);

        IMInspectLib.IIMInspect inspect = iIMHost_ as IMInspectLib.IIMInspect;
        IMAlignLib.IIMAlign align = iIMHost_ as IMAlignLib.IIMAlign;

        if (inspect != null)
        {
            IMInspectLib.IIMInspectProject project;
            inspect.ProjectGetCurrent(out project);

            // The project object is necessary
            if (project == null)
            {
                return null;
            }
            IMInspectLib.IIMCommandCenter commandCenter;
            project.CommandCenterCreate(out commandCenter);

            // The command center object is necessary
            if ( commandCenter == null )
            {
                return null;
            }
            Utils.COMObjectRelease(ref project);
            return new CIMHost(iIMHost_, commandCenter, EHostApplication.IMINSPECT);
        }
        else if (align != null)
        {
            IMAlignLib.IIMAlignProject project;

            align.ProjectGetCurrent(out project);

            // The project object is necessary
            if (project == null)
            {
                return null;
            }

            IMAlignLib.IIMCommandCenter commandCenter;

            project.CommandCenterCreate(out commandCenter);

            // The command center object is necessary
            if ( commandCenter == null )
            {
                return null;
            }

            Utils.COMObjectRelease(ref project);
            return new CIMHost( iIMHost_, commandCenter as IMInspectLib.IIMCommandCenter, EHostApplication.IMALIGN );
        }
        return null;
    }

    // =================================================================================================
    //   Destructor
    //
    // Frees unmanaged resources.
    // -------------------------------------------------------------------------------------------------
    ~CIMHost()
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
        Utils.COMObjectRelease( ref m_commandCenter );
        Utils.COMObjectRelease( ref m_host );

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
    //   Do the necessary preparations before calling a command or script to set the proper echo and
    // interactive modes.
    //
    // Parameter : withEcho_    : indicates whether the command should be visible in the 
    //                            application's Command History
    // Parameter : interactive_ : true for interactive behavior, false for script behavior
    // -------------------------------------------------------------------------------------------------
    private void EchoAndInteractivePrepare( bool withEcho_, bool interactive_ )
    {
        if ( withEcho_ )
        {
            m_commandCenter.CommandExecute( "EchoOn" );
            m_commandCenter.CommandExecute( "RecordableOn" );
        }
        else
        {
            m_commandCenter.CommandExecute( "EchoOff" );
            m_commandCenter.CommandExecute( "RecordableOff" );
        }

        // Interactivity activation
        m_commandCenter.CommandExecute( interactive_ ? "InteractivityOn" : "InteractivityOff" );
    }

    // =================================================================================================
    //   Property access
    // -------------------------------------------------------------------------------------------------
    public EHostApplication HostApplication
    {
        get { return m_hostApplication; }
    }

    // =================================================================================================
    //   Displays a message box.
    //
    // Parameter : messageType_ : the type of message.
    // Parameter : message_     : the main message body.
    // Parameter : details_     : (optional) additional details for the message.
    // Parameter : title_       : (optional) The window's title.
    //
    // Return : An id indicating which button was clicked to close the message window.
    // -------------------------------------------------------------------------------------------------
    public int MessageBox( IMInspectLib.EMessageTypes messageType_, 
                           string                     message_,
                           string                     details_ = "",
                           string                     title_ = "" )
    {
        IMInspectLib.IIMMessageCenter messageCenter = m_host as IMInspectLib.IIMMessageCenter;

        return messageCenter.MessageBox( messageType_, message_, details_, title_ );
    }

    // =================================================================================================
    //   Executes a command on the host application.
    //
    // Parameter : command_                : the command to execute
    // Parameter : withEcho_               : indicates whether the command should be visible in the 
    //                                       application's Command History
    // Parameter : interactive_            : true for interactive behavior, false for script behavior
    // Parameter : waitForInteractiveMode_ : enable waiting for Interactive Mode
    //
    // Return : true if successful, false otherwise
    // -------------------------------------------------------------------------------------------------
    public bool ExecuteCommand( string command_, bool withEcho_, bool interactive_, bool waitForInteractiveMode_ )
    {
        EchoAndInteractivePrepare( withEcho_, interactive_ );

        // Don't wait for the Interactive Mode
        if ( !waitForInteractiveMode_ )
        {
            m_commandCenter.CommandExecute( "WaitOnInteractiveModeOff" );
        }

        int retVal = m_commandCenter.CommandExecute( command_ );
            retVal = m_commandCenter.ReturnValueIsSuccess( retVal );

        // Restore the Interactive Mode waiting
        if ( !waitForInteractiveMode_ )
        {
            m_commandCenter.CommandExecute( "WaitOnInteractiveModeOn" );
        }

        return retVal == 1;
    }

    // =================================================================================================
    //   Builds and executes a script to call a command returning an array of values.
    // Parameter : command_  : The command to execute
    // Parameter : preArgs_  : A string with properly formatted arguments to pass to
    //                         the command before the out arguments. This can be empty.
    // Parameter : count_    : The number of values to retrieve.
    // Parameter : withEcho_ : indicates whether the command should be visible in the 
    //                         application's Command History
    //
    // Return : An array containing the retrieved values.
    // -------------------------------------------------------------------------------------------------
    private string[] ValuesGetStart( string command_, string preArgs_, int count_, bool withEcho_ )
    {
        // Construct the variable names that will be used to retrieve the values.
        string[] names = new string[ count_ ];

        for( int i=0; i < count_; ++i )
        {
            names[ i ] = BASE_VAR_NAME + i.ToString();
        }

        EchoAndInteractivePrepare( withEcho_, false );

        string script = SCRIPT_VERSION_DECLARATION;
        script += "\n";
        for( int i=0; i < count_; ++i )
        {
            script += "DECLARE ";
            script += names[ i ];
            script += "\n";
        }

        script += Utils.CommandBuild( command_, preArgs_, names );

        int retVal = m_commandCenter.ScriptExecuteFromBuffer( script, null );

        if ( m_commandCenter.ReturnValueIsSuccess( retVal ) != 1 )
        { 
            return null;
        }

        return names;
    }

    // =================================================================================================
    //   Builds and execute a script to call a command that returns string values.
    //
    // Parameter : command_  : The command to execute
    // Parameter : preArgs_  : A string with properly formatted arguments to pass to
    //                         the command before the out arguments. This can be empty.
    // Parameter : count_    : The number of values to retrieve.
    // Parameter : withEcho_ : indicates whether the command should be visible in the 
    //                         application's Command History
    //
    // Return : An array containing the retrieved values.
    // -------------------------------------------------------------------------------------------------
    public string[] ValuesStrGet( string command_, string preArgs_, int count_, bool withEcho_ )
    {
        string[] varNames = ValuesGetStart( command_, preArgs_, count_, withEcho_ );
        if (varNames == null )
        {
            return null;
        }
        string[] result = new string[ count_ ];

        for( int i=0; i < count_; ++i )
        {
            int retVal = m_commandCenter.ScriptVariableGetValueAsString( varNames[ i ], 1, out result[ i ] );

            if ( m_commandCenter.ReturnValueIsSuccess( retVal ) != 1 )
            {
                return null;
            }
        }

        return result;
    }

    // =================================================================================================
    //   Builds and execute a script to call a command that returns int values.
    //
    // Parameter : command_  : The command to execute
    // Parameter : preArgs_  : A string with properly formatted arguments to pass to
    //                         the command before the out arguments. This can be empty.
    // Parameter : count_    : The number of values to retrieve.
    // Parameter : withEcho_ : indicates whether the command should be visible in the 
    //                         application's Command History
    //
    // Return : An array containing the retrieved values.
    // -------------------------------------------------------------------------------------------------
    public int[] ValuesIntGet( string command_, int count_, bool withEcho_ )
    {
        string[] varNames = ValuesGetStart( command_, "", count_, withEcho_ );
        if ( varNames == null )
        {
            return null;
        }
        int[] result = new int[ count_ ];

        for( int i=0; i < count_; ++i )
        {
            int retVal = m_commandCenter.ScriptVariableGetValueAsInt( varNames[ i ], 1, out result[ i ] );

            if ( m_commandCenter.ReturnValueIsSuccess( retVal ) != 1 )
            {
                return null;
            }
        }

        return result;
    }

    // =================================================================================================
    //   Retrieves a string value from the application, using a command.
    //
    // Parameter : command_  : command name
    // Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
    //
    // Return : The string value
    // -------------------------------------------------------------------------------------------------
    public string ValueStrGet( string command_, string preArgs_, bool withEcho_ )
    {
        var values = ValuesStrGet(command_, preArgs_, 1, withEcho_);
        return values != null? values[0] : string.Empty;
    }

    // =================================================================================================
    //   Wrapper around ValuesStrGet for boolean "On"/"Off" cases.
    //
    // Parameter : command_  : command name
    // Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
    //
    // Return : The boolean value as converted from "On"->true "Off"->false.
    // -------------------------------------------------------------------------------------------------
    public Nullable<bool> ValueBoolGet( string command_, bool withEcho_ )
    {
        string[] str = ValuesStrGet( command_, "", 1, withEcho_ );
   
        return str == null ? null : Utils.MSCLToBool( str[ 0 ] );
    }

    // =================================================================================================
    //   Changes a value in the application, using a command.
    //
    // Parameter : cmdName_     : command name
    // Parameter : value_       : new value
    // Parameter : withEcho_    : indicates whether the command should be visible in the application's Command History
    // Parameter : interactive_ : true for interactive behavior, false for script behavior
    //
    // Return : true if the value was set with success, false otherwise.
    // -------------------------------------------------------------------------------------------------
    public bool ValueSet< T >( string cmdName_, T value_, bool withEcho_, bool interactive_ )
    {
        return ExecuteCommand( Utils.CommandBuild( cmdName_, value_ ), withEcho_, interactive_, true );
    }

    // =================================================================================================
    //   Retrieves a date time value from the application, using a command.
    //
    // Parameter : cmdName_  : command name
    // Parameter : withEcho_ : indicates whether the command should be visible in the application's Command History
    //
    // Return : The date/time as a string.
    // -------------------------------------------------------------------------------------------------
    public string ValueDateTimeGet( string cmdName_, bool withEcho_ )
    {
        int[] values = ValuesIntGet( cmdName_, 6, withEcho_ );
        if ( values == null )
        {
            return string.Empty; 
        }
        DateTime dateTime = new DateTime( values[ 0 ], values[ 1 ], values[ 2 ],
                                          values[ 3 ], values[ 4 ], values[ 5 ] );

        return dateTime.ToString();
    }

    // =================================================================================================
    //   Synchronizes, if necessary, a double from the application.
    //
    // Parameter : getCmdName_ : Get command name
    // Parameter : value_      : Current value
    // Parameter : newValue_   : [OUT] New value
    //
    // Return : true if value_ and newValue_ are different, false if they are the same.
    // -------------------------------------------------------------------------------------------------
    public bool ValueDoubleSynchFromApp( string getCmdName_, double value_, out double newValue_ )
    {
        string strValue = ValueStrGet( getCmdName_, "", false );

        double doubleValue = 0;

        if ( double.TryParse( strValue, out doubleValue ) && ( value_ != doubleValue ) )
        {
            newValue_ = doubleValue;
            return true;
        }

        newValue_ = value_;
        return false;
    }

    // =================================================================================================
    //   Synchronizes, if necessary, a integer from the application.
    //
    // Parameter : getCmdName_ : Get command name
    // Parameter : value_      : Current value
    // Parameter : newValue_   : [OUT] New value
    //
    // Return : true if value_ and newValue_ are different, false if they are the same.
    // -------------------------------------------------------------------------------------------------
    public bool ValueIntSynchFromApp( string getCmdName_, int value_, out int newValue_ )
    {
        string strValue = ValueStrGet( getCmdName_, "", false );

        int intValue = 0;
        
        if ( int.TryParse( strValue, out intValue ) && ( value_ != intValue ) )
        {
            newValue_ = intValue;
            return true;
        }

        newValue_ = value_;
        return false;
    }

    // =================================================================================================
    //   Synchronizes, if necessary, a boolean from the application.
    //
    // Parameter : getCmdName_ : Get command name
    // Parameter : value_      : Current value
    // Parameter : newValue_   : [OUT] New value
    //
    // Return : true if value_ and newValue_ are different, false if they are the same.
    // -------------------------------------------------------------------------------------------------
    public bool ValueOnOffSynchFromApp( string getCmdName_, bool value_, out bool newValue_ )
    {
        string strValue = ValueStrGet( getCmdName_, "", false );

        bool? boolValue = Utils.MSCLToBool( strValue );

        if ( boolValue.HasValue && value_ != boolValue.Value )
        {
            newValue_ = boolValue.Value;
            return true;
        }

        newValue_ = value_;
        return false;
    }

    // =================================================================================================
    //   Synchronizes, if necessary, a string from the application.
    //
    // Parameter : getCmdName_ : Get command name
    // Parameter : value_      : Current value
    // Parameter : newValue_   : [OUT] New value
    //
    // Return : true if value_ and newValue_ are different, false if they are the same.
    // -------------------------------------------------------------------------------------------------
    public bool ValueStrSynchFromApp( string getCmdName_, string value_, out string newValue_ )
    {
        string strValue = ValueStrGet( getCmdName_, "", false );

        if ( value_ != strValue )
        {
            newValue_ = strValue;
            return true;
        }

        newValue_ = value_;
        return false;
    }

    // =================================================================================================
    //   Synchronizes, if necessary, a string value with the application.
    //
    // Parameter : getCmdName_ : Get command name
    // Parameter : setCmdName_ : Set command name
    // Parameter : value_      : new value
    // Parameter : withEcho_   : indicates whether the Set command should be visible in the application's Command History
    // -------------------------------------------------------------------------------------------------
    public void ValueOnOffSynchWithApp( string getCmdName_,
                                        string setCmdName_,
                                        bool   value_,
                                        bool   withEcho_ )
    {
        string value = Utils.BoolToMSCL( value_ );

        string valueFromApp = ValueStrGet( getCmdName_, "", false );

        if ( valueFromApp != value )
        {
            ValueSet( setCmdName_, value_, withEcho_, false );
        }
    }

    // =================================================================================================
    //   Synchronizes, if necessary, a string value with the application.
    //
    // Parameter : getCmdName_ : Get command name
    // Parameter : setCmdName_ : Set command name
    // Parameter : value_      : new value
    // Parameter : withEcho_   : indicates whether the Set command should be visible in the application's Command History
    // -------------------------------------------------------------------------------------------------
    public void ValueStrSynchWithApp( string getCmdName_,
                                      string setCmdName_,
                                      string value_,
                                      bool   withEcho_ )
    {
        string valueFromApp = ValueStrGet( getCmdName_, "", false );

        if ( valueFromApp != value_ )
        {
            ValueSet( setCmdName_, Utils.Quote( value_ ), withEcho_, false );
        }
    }

    // =================================================================================================
    //   Synchronizes, if necessary, a string value with the application.
    //
    // Parameter : getCmdName_ : Get command name
    // Parameter : setCmdName_ : Set command name
    // Parameter : value_      : new value
    // Parameter : withEcho_   : indicates whether the Set command should be visible in the application's Command History
    // -------------------------------------------------------------------------------------------------
    public void ValueIntSynchWithApp( string getCmdName_,
                                      string setCmdName_,
                                      int    value_,
                                      bool   withEcho_ )
    {
        string valueFromApp = ValueStrGet( getCmdName_, "", false );

        int intValueFromApp = 0;

        if ( int.TryParse( valueFromApp, out intValueFromApp ) && ( intValueFromApp != value_ ) )
        {
            ValueSet( setCmdName_, value_, withEcho_, false );
        }
    }

    // =================================================================================================
    //   Synchronizes, if necessary, a string value with the application.
    //
    // Parameter : getCmdName_ : Get command name
    // Parameter : setCmdName_ : Set command name
    // Parameter : value_      : new value
    // Parameter : withEcho_   : indicates whether the Set command should be visible in the application's Command History
    // -------------------------------------------------------------------------------------------------
    public void ValueDoubleSynchWithApp( string getCmdName_,
                                         string setCmdName_,
                                         double value_,
                                         bool   withEcho_ )
    {
        string valueFromApp = ValueStrGet( getCmdName_, "", false );

        double doubleValueFromApp = 0;

        if ( double.TryParse( valueFromApp, out doubleValueFromApp ) && ( doubleValueFromApp != value_ ) )
        {
            ValueSet( setCmdName_, value_, withEcho_, false );
        }
    }

    // =================================================================================================
    //   Generate a unique object name from a base name if necessary.
    //
    // Parameter : baseName_ : base name
    //
    // Return : Unique name generated from base name
    // -------------------------------------------------------------------------------------------------
    public string ObtainUniqueName( string baseName_ )
    {
        string result = baseName_;

        if ( result.Length != 0 )
        {
            var values =  ValuesStrGet("TREEVIEW NAME GENERATE_UNIQUE", Utils.Quote(baseName_), 1, false);
            return values != null ? values[ 0 ] : string.Empty;
        }

        return string.Empty;
    }
}

}