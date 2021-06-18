// =================================================================================================
//   Commands implementation
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   Class implementing the DIGITIZE DEVICE COMPANY_NAME_CSHARP SCAN BOUNDARY MIN_EDGE_ANGLE [GET]
// commands (both commands are handled through the same class using the "isGet" flag).
// -------------------------------------------------------------------------------------------------
class CCmdSharpEdgeMinAngle : IM.CComCommand
{
    private bool       m_isGet;
    private CSettings  m_settings;
    private IM.CIMHost m_host;

    // =================================================================================================
    //   Constructor
    //
    // Parameter : info_     : Information used to register the command with the application.
    // Parameter : isGet_    : true for the "get" command, false for the "set" command.
    // Parameter : settings_ : Access to settings.
    // Parameter : host_     : Access to host (for displaying error message).
    // -------------------------------------------------------------------------------------------------
    public CCmdSharpEdgeMinAngle( IM.CComCommandInfo info_, bool isGet_, CSettings settings_, IM.CIMHost host_ ) :
        base( info_ )
    {
        m_isGet    = isGet_;
        m_settings = settings_;
        m_host     = host_;
    }

    // =================================================================================================
    //   Execute the command, changing the setting value for the "set" command and returning the
    // current setting value for the "get" command.
    //
    // Parameter : iIMCommandArgumentEnum_ : Arguments passed to the command
    //
    // Return : A standard command return code indicating success or failure.
    // -------------------------------------------------------------------------------------------------
    public override IMPluginLib.ECommandReturnCodes Execute2( IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_ )
    {
        IMPluginLib.ECommandReturnCodes retCode = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;

        double argValue = 0;

        // Getting argument value
        if ( iIMCommandArgumentEnum_ != null )
        {
            // Checking argument count validity
            if ( iIMCommandArgumentEnum_.ArgsGetNb() > 0 )
            {
                // Checking availability of first argument
                IMPluginLib.IIMCommandArgument argument = null;
                iIMCommandArgumentEnum_.ArgGet( 0, out argument );
                if ( argument != null )
                {
                    if ( m_isGet )
                    { 
                        argValue = m_settings.IMISharpEdgeMinAngle;
                        if ( argument.ArgValueSetFromDouble( 1, argValue ) == 1 )
                        {
                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                        }
                    }
                    else
                    {
                        if ( argument.ArgValueGetAsDouble( 1, out argValue ) == 1 )
                        {
                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                        }
                    }

                    IM.Utils.COMObjectRelease( ref argument );
                }
            }
        }

        if ( !m_isGet && ( retCode == IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED ) )
        {
            if ( ( argValue > 0 ) && ( argValue < 180 ) )
            {
                m_settings.IMISharpEdgeMinAngle = argValue;
            }
            else
            {
                m_host.MessageBox( IMInspectLib.EMessageTypes.E_MESSAGE_TYPE_INFORMATION,
                                    "The sharp edge min angle is out of range" );

                retCode = IMPluginLib.ECommandReturnCodes.E_CMD_ARG_OUT_OF_RANGE;
            }
        }

        IM.Utils.COMObjectRelease( ref iIMCommandArgumentEnum_ );

        return retCode;
    }
}

// =================================================================================================
//   Class implementing the DIGITIZE DEVICE COMPANY_NAME_CSHARP SCAN BOUNDARY MAX_POINT_TO_POINT_DIST (GET)
// commands (both commands are handled through the same class with the "isGet" flag).
// -------------------------------------------------------------------------------------------------
class CCmdSharpEdgeMaxPointToPointDist : IM.CComCommand
{
    private bool      m_isGet;
    private CSettings m_settings;
    private IM.CIMHost   m_host;

    // =================================================================================================
    //   Constructor
    //
    // Parameter : info_     : Information used to register the command with the application.
    // Parameter : isGet_    : true for the "get" command, false for the "set" command.
    // Parameter : settings_ : Access to settings.
    // Parameter : host_     : Acesss to host (for displaying error message).
    // -------------------------------------------------------------------------------------------------
    public CCmdSharpEdgeMaxPointToPointDist( IM.CComCommandInfo info_, bool isGet_, CSettings settings_, IM.CIMHost host_ ) :
        base( info_ )
    {
        m_isGet    = isGet_;
        m_settings = settings_;
        m_host     = host_;
    }

    // =================================================================================================
    //   Execute the command, changing the setting value for the "set" command and returning the
    // current setting value for the "get" command.
    //
    // Parameter : iIMCommandArgumentEnum_ : Arguments passed to the command
    //
    // Return : A standard command return code indicating success or failure.
    // -------------------------------------------------------------------------------------------------
    public override IMPluginLib.ECommandReturnCodes Execute2( IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_ )
    {
        IMPluginLib.ECommandReturnCodes retCode = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;

        double argValue = 0;

        // Getting argument value
        if ( iIMCommandArgumentEnum_ != null )
        {
            // Checking argument count validity
            if ( iIMCommandArgumentEnum_.ArgsGetNb() > 0 )
            {
                // Checking availability of first argument
                IMPluginLib.IIMCommandArgument argument = null;
                iIMCommandArgumentEnum_.ArgGet( 0, out argument );
                if ( argument != null )
                {
                    if ( m_isGet )
                    { 
                        argValue = m_settings.IMISharpEdgeMaxPointToPointDistance;
                        if ( argument.ArgValueSetFromDouble( 1, argValue ) == 1 )
                        {
                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                        }
                    }
                    else
                    {
                        if ( argument.ArgValueGetAsDouble( 1, out argValue ) == 1 )
                        {
                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                        }
                    }

                    IM.Utils.COMObjectRelease( ref argument );
                }
            }
        }

        if ( !m_isGet && ( retCode == IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED ) )
        {
            if ( argValue > 0 )
            {
                m_settings.IMISharpEdgeMaxPointToPointDistance = argValue;
            }
            else
            {
                m_host.MessageBox( IMInspectLib.EMessageTypes.E_MESSAGE_TYPE_INFORMATION,
                                    "The sharp edge max point to point is out of range" );

                retCode = IMPluginLib.ECommandReturnCodes.E_CMD_ARG_OUT_OF_RANGE;
            }
        }

        IM.Utils.COMObjectRelease( ref iIMCommandArgumentEnum_ );

        return retCode;
    }
}

}
