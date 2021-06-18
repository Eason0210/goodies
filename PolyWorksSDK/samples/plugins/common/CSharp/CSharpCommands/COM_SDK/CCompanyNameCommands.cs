// =================================================================================================
// Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharpCommands
{
    // =============================================================================================
    // Settings
    // =============================================================================================
    public static class Settings
    {
        public static double g_doubleSettingValue  = 110.25;
        public static int    g_integerSettingValue = 237;
        public static string g_stringSettingValue  = "String Value";
    }

    // =============================================================================================
    // TODO: Rename CompanyNameAction with your company name and your action
    //
    // TODO: Add command description here.
    // ---------------------------------------------------------------------------------------------
    public class CCmdCompanyNameAction : IM.CComCommand
    {
        // =========================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the 
        // application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -----------------------------------------------------------------------------------------
        public CCmdCompanyNameAction(IM.CComCommandInfo info_)
            : base(info_)
        {}

        // =========================================================================================
        // Commands action. 
        //
        // TODO: Comment the action here
        //
        // Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -----------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            // TODO: Add command execution code here.

            return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
        }
    };

    // =============================================================================================
    // TODO: Rename CompanyNameDouble with your company name and double setting name.
    //
    // Sets a double value setting within the plug-in
    // ---------------------------------------------------------------------------------------------
    public class CCmdCompanyNameDoubleSet : IM.CComCommand
    {
        // =========================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the 
        // application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -----------------------------------------------------------------------------------------
        public CCmdCompanyNameDoubleSet(IM.CComCommandInfo info_)
            : base(info_)
        {}

        // =========================================================================================
        // Sets a double value setting within the plug-in.
        //
        // Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -----------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            IMPluginLib.ECommandReturnCodes retCode = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;

            // Getting argument value
            bool success = false;
            double argValue = 0.0;

            // Setting argument value
            if (iIMCommandArgumentEnum_ != null)
            {
                // Checking argument count validity
                if (iIMCommandArgumentEnum_.ArgsGetNb() > 0)
                {
                    // Checking availability of first argument
                    IMPluginLib.IIMCommandArgument argument = null;
                    iIMCommandArgumentEnum_.ArgGet(0, out argument);
                    if (argument != null)
                    {
                         // Checking and retrieving argument value if of valid type
                        if (argument.ArgValueGetAsDouble(1, out argValue) == 1)
                        {
                            success = true;
                        }
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument);
                    }
                }
            }

            // Argument value validation
            if (success)
            {
                // TODO: Replace validation code by your own depending on wanted argument value valid range
                if (argValue < 0)
                {
                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_ARG_OUT_OF_RANGE;
                }
                else
                {
                    // TODO: Register setting value into the plug-in for future use or execute action using argument value
                    // TODO: Replace g_doubleSettingValue use by your own code
                    Settings.g_doubleSettingValue = argValue;

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                }
            }

            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMCommandArgumentEnum_);

            return retCode;
        }
    };

    // =============================================================================================
    // TODO: Rename CompanyNameDouble with your company name and double setting name.
    //
    // Gets a double value setting from the plug-in
    // ---------------------------------------------------------------------------------------------
    public class CCmdCompanyNameDoubleGet : IM.CComCommand
    {
        // =========================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the 
        // application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -----------------------------------------------------------------------------------------
        public CCmdCompanyNameDoubleGet(IM.CComCommandInfo info_)
            : base(info_)
        {}

        // =========================================================================================
        // Gets a double value setting from the plug-in
        //
        // Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -----------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            IMPluginLib.ECommandReturnCodes retCode = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;

            // Getting argument value
            if (iIMCommandArgumentEnum_ != null)
            {
                // Checking argument count validity
                if (iIMCommandArgumentEnum_.ArgsGetNb() > 0)
                {
                    // Checking availability of first argument
                    IMPluginLib.IIMCommandArgument argument = null;
                    iIMCommandArgumentEnum_.ArgGet(0, out argument);
                    if (argument != null)
                    {
                        // TODO: Get setting value from the plug-in
                        // TODO: Replace g_doubleSettingValue use by your own code
                        if (argument.ArgValueSetFromDouble(1, Settings.g_doubleSettingValue) == 1)
                        {
                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                        }
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument);
                    }
                }
            }

            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMCommandArgumentEnum_);

            return retCode;
        }
    };

    // =============================================================================================
    // TODO: Rename CompanyNameInteger with your company name and integer setting name.
    //
    // Sets a integer value setting within the plug-in
    // ---------------------------------------------------------------------------------------------
    public class CCmdCompanyNameIntegerSet : IM.CComCommand
    {
        // =========================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the 
        // application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -----------------------------------------------------------------------------------------
        public CCmdCompanyNameIntegerSet(IM.CComCommandInfo info_)
            : base(info_)
        {}

        // =========================================================================================
        // Sets an integer value setting within the plug-in.
        //
        // Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -----------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            IMPluginLib.ECommandReturnCodes retCode = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;

            // Getting argument value
            bool success = false;
            int argValue = 0;

            // Setting argument value
            if (iIMCommandArgumentEnum_ != null)
            {
                // Checking argument count validity
                if (iIMCommandArgumentEnum_.ArgsGetNb() > 0)
                {
                    // Checking availability of first argument
                    IMPluginLib.IIMCommandArgument argument = null;
                    iIMCommandArgumentEnum_.ArgGet(0, out argument);
                    if (argument != null)
                    {
                        // Checking and retrieving argument value if of valid type
                        if (argument.ArgValueGetAsInt(1, out argValue) == 1)
                        {
                            success = true;
                        }
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument);
                    }
                }
            }

            // Argument value validation
            if (success)
            {
                // TODO: Replace validation code by your own depending on wanted argument value valid range
                if (argValue < 0)
                {
                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_ARG_OUT_OF_RANGE;
                }
                else
                {
                    // TODO: Register setting value into the plug-in for future use or execute action using argument value
                    // TODO: Replace g_integerSettingValue use by your own code
                    Settings.g_integerSettingValue = argValue;

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                }
            }

            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMCommandArgumentEnum_);

            return retCode;
        }
    };

    // =============================================================================================
    // TODO: Rename CompanyNameInteger with your company name and integer setting name.
    //
    // Gets a integer value setting from the plug-in
    // ---------------------------------------------------------------------------------------------
    public class CCmdCompanyNameIntegerGet : IM.CComCommand
    {
        // =========================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the 
        // application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -----------------------------------------------------------------------------------------
        public CCmdCompanyNameIntegerGet(IM.CComCommandInfo info_)
            : base(info_)
        {}

        // =========================================================================================
        // Gets a integer value setting within the plug-in.
        //
        // Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -----------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            IMPluginLib.ECommandReturnCodes retCode = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;

            // Setting argument value
            if (iIMCommandArgumentEnum_ != null)
            {
                // Checking argument count validity
                if (iIMCommandArgumentEnum_.ArgsGetNb() > 0)
                {
                    // Checking availability of first argument
                    IMPluginLib.IIMCommandArgument argument = null;
                    iIMCommandArgumentEnum_.ArgGet(0, out argument);
                    if (argument != null)
                    {
                        // TODO: Get setting value from the plug-in
                        // TODO: Replace g_integerSettingValue use by your own code
                        if (argument.ArgValueSetFromInt(1, Settings.g_integerSettingValue) == 1)
                        {
                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                        }
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument);
                    }
                }
            }

            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMCommandArgumentEnum_);

            return retCode;
        }
    };

    // =============================================================================================
    // TODO: Rename CompanyNameString with your company name and string setting name.
    //
    // Sets a string value setting within the plug-in
    // ---------------------------------------------------------------------------------------------
    public class CCmdCompanyNameStringSet : IM.CComCommand
    {
        // =========================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the 
        // application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -----------------------------------------------------------------------------------------
        public CCmdCompanyNameStringSet(IM.CComCommandInfo info_)
            : base(info_)
        {}

        // =========================================================================================
        // Sets a string value setting within the plug-in.
        //
        // Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -----------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            IMPluginLib.ECommandReturnCodes retCode = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;

            // Getting argument value
            bool success = false;
            string argValue = string.Empty;

            // Setting argument value
            if (iIMCommandArgumentEnum_ != null)
            {
                // Checking argument count validity
                if (iIMCommandArgumentEnum_.ArgsGetNb() > 0)
                {
                    // Checking availability of first argument
                    IMPluginLib.IIMCommandArgument argument = null;
                    iIMCommandArgumentEnum_.ArgGet(0, out argument);
                    if (argument != null)
                    {
                        // Checking and retrieving argument value if of valid type
                        if (argument.ArgValueGetAsString(1, out argValue) == 1)
                        {
                            success = true;
                        }
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument);
                    }
                }
            }

            // Argument value validation
            if (success)
            {
                // TODO: Replace validation code by your own depending on wanted argument value valid range
                if (argValue.CompareTo("Invalid") == 0)
                {
                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_ARG_INVALID_STRING;
                }
                else
                {
                    // TODO: Register setting value into the plug-in for future use or execute action using argument value
                    // TODO: Replace g_stringSettingValue use by your own code
                    Settings.g_stringSettingValue = argValue;

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                }
            }

            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMCommandArgumentEnum_);

            return retCode;
        }
    };

    // =============================================================================================
    // TODO: Rename CompanyNameString with your company name and string setting name.
    //
    // Gets a string value setting from the plug-in
    // ---------------------------------------------------------------------------------------------
    public class CCmdCompanyNameStringGet : IM.CComCommand
    {
        // =========================================================================================
        // Commands constructor. 
        // This constructor is only called one time when the command is registered to the 
        // application.
        //
        // Parameter: info_ : Parameters necessary to build the command.
        // -----------------------------------------------------------------------------------------
        public CCmdCompanyNameStringGet(IM.CComCommandInfo info_)
            : base(info_)
        {}

        // =========================================================================================
        // Gets a string value setting within the plug-in.
        //
        // Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
        //
        // Return: COM error code.
        // -----------------------------------------------------------------------------------------
        public override IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            IMPluginLib.ECommandReturnCodes retCode = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;

            // Setting argument value
            if (iIMCommandArgumentEnum_ != null)
            {
                // Checking argument count validity
                if (iIMCommandArgumentEnum_.ArgsGetNb() > 0)
                {
                    // Checking availability of first argument
                    IMPluginLib.IIMCommandArgument argument = null;
                    iIMCommandArgumentEnum_.ArgGet(0, out argument);
                    if (argument != null)
                    {
                        // TODO: Get setting value from the plug-in
                        // TODO: Replace g_stringSettingValue use by your own code
                        if (argument.ArgValueSetFromString(1, Settings.g_stringSettingValue) == 1)
                        {
                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                        }
                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument);
                    }
                }
            }

            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMCommandArgumentEnum_);

            return retCode;
        }
    }
}
