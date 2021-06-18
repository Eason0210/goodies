' =================================================================================================
' Plug-in's commands.
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    ' =============================================================================================
    ' Settings
    ' =============================================================================================
    Public Class Settings

        Public Shared g_doubleSettingValue As Double = 110.25
        Public Shared g_integerSettingValue As Integer = 237
        Public Shared g_stringSettingValue As String = "String Value"

    End Class

    Public Class CCmdCompanyNameCmdFromMacro
        Inherits CComCommand

        Private m_inspectCmdCenter As IMInspectLib.IIMCommandCenter

        ' =========================================================================================
        ' Command constructor. 
        ' This constructor is only called one time when the command is registered to the 
        ' application.
        '
        ' Parameter: info_                 : Parameters necessary to build the command.
        ' Parameter: inspectCommandCenter_ : Command center to execute the macro script.
        ' -----------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo, ByRef inspectCommandCenter_ As IMInspectLib.IIMCommandCenter)

            MyBase.New(info_)
            m_inspectCmdCenter = inspectCommandCenter_

        End Sub

        ' =========================================================================================
        ' Command action, which executes a macro script on the host application. 
        '
        ' TODO: Comment the action here
        '
        ' Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' -----------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            Dim returnValue As Integer
            Dim script As String

            ' Build the macro script
            ' TODO: Replace macro script here.

            script = "version ""5.0""" & vbCrLf

            ' Turn Off the echoing of the commands
            script += "MACRO COMMAND ECHO ( ""Off"" )" & vbCrLf

            ' We want to keep all measurement objects visible while probing to be able to move the probe on the plane (see below)
            script += "PROBE DISPLAY SHOW_ONLY_RELEVANT_MEASUREMENT_OBJECTS ( ""Off"" )" & vbCrLf

            ' Initialisation
            ' Create a plane, and a circle to be probed
            script += "FILE NEW_PROJECT" & vbCrLf &
                "FEATURE PRIMITIVE PLANE CREATE FROM_POINT_AND_NORMAL ( 43.882238437618, 6.96668688420377, 1.2, 0.0, 0.0, 1.0, ""Nominal"", ""plane 1"", , 100, 4 )" & vbCrLf &
                "TREEVIEW FEATURE Select ( 1, ""On"" )" & vbCrLf &
                "TREEVIEW VIEW STATIC SMOOTH" & vbCrLf &
                "FEATURE PRIMITIVE CIRCLE CREATE ( 25.3999999904043, 50.7999999963512, 0.0, 0.0, 0.0, 1.0, 12.6999997329769, ""Nominal"", ""circle 1"" )" & vbCrLf

            ' Probe circle using the Virtual Probe.
            ' The user can move the probe on the previously created plane and use the Insert key to acquire points.
            ' The execution of the script will wait until the probing Is completed before continuing.
            script += "" & vbCrLf &
                "PROBE DEVICE ( ""PolyWorks Virtual Probe"" )" & vbCrLf &
                "FEATURE PRIMITIVE CIRCLE PROBE ( ""Measured"", ""circle 1"" )" & vbCrLf

            ' Create and open a formatted report
            script += "TREEVIEW FEATURE Select ( 1, ""On"" )" & vbCrLf &
                "REPORT_ITEM TABLE FROM_SELECTED_OBJECTS ( )" & vbCrLf &
                "TREEVIEW OBJECT SELECT NONE" & vbCrLf &
                "TREEVIEW FORMATTED_REPORT Select ( 1, ""On"" )" & vbCrLf &
                "FORMATTED_REPORT OPEN" & vbCrLf

            ' Reset the option we changed previously to the default value
            script += "PROBE DISPLAY SHOW_ONLY_RELEVANT_MEASUREMENT_OBJECTS ( ""On"" )" & vbCrLf

            ' Turn back On the echoing of the commands
            script += "MACRO COMMAND ECHO ( ""On"" )" & vbCrLf

            ' Execute the macro script
            returnValue = m_inspectCmdCenter.ScriptExecuteFromBuffer(script, "")

            ' Check if the execution is a success
            If m_inspectCmdCenter.ReturnValueIsSuccess(returnValue) = 1 Then

                Return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

            End If

            Return IMPluginLib.ECommandReturnCodes.E_CMD_FAILED

        End Function

    End Class

    ' =============================================================================================
    ' TODO: Rename CompanyNameAction with your company name and your action
    '
    ' TODO: Add command description here.
    ' ---------------------------------------------------------------------------------------------
    Public Class CCmdCompanyNameAction
        Inherits CComCommand

        ' =========================================================================================
        ' Command constructor. 
        ' This constructor is only called one time when the command is registered to the 
        ' application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' -----------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =========================================================================================
        ' Command action. 
        '
        ' TODO: Comment the action here
        '
        ' Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' -----------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            ' TODO: Add command execution code here.

            Return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

        End Function

    End Class

    ' =============================================================================================
    ' TODO: Rename CompanyNameDouble with your company name and double setting name.
    '
    ' Sets a double value setting within the plug-in
    ' ---------------------------------------------------------------------------------------------
    Public Class CCmdCompanyNameDoubleSet
        Inherits CComCommand

        ' =========================================================================================
        ' Command constructor. 
        ' This constructor is only called one time when the command is registered to the 
        ' application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' -----------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =========================================================================================
        ' Sets a double value setting within the plug-in.
        '
        ' Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' -----------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            Dim retCode As IMPluginLib.ECommandReturnCodes = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED

            ' Getting argument value
            Dim success As Boolean = False
            Dim argValue As Double = 0.0

            ' Setting argument value
            If Not pIMCommandArgumentEnum_ Is Nothing Then

                ' Checking argument count validity
                If pIMCommandArgumentEnum_.ArgsGetNb() > 0 Then

                    ' Checking availability of first argument
                    Dim argument As IMPluginLib.IIMCommandArgument = Nothing
                    pIMCommandArgumentEnum_.ArgGet(0, argument)

                    If Not argument Is Nothing Then

                        ' Checking and retrieving argument value if of valid type
                        If argument.ArgValueGetAsDouble(1, argValue) = 1 Then

                            success = True

                        End If

                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument)

                    End If

                End If

            End If

            ' Argument value validation
            If success = True Then

                ' TODO: Replace validation code by your own depending on wanted argument value valid range
                If argValue < 0 Then

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_ARG_OUT_OF_RANGE

                Else

                    ' TODO: Register setting value into the plug-in for future use or execute action using argument value
                    ' TODO: Replace g_doubleSettingValue use by your own code
                    Settings.g_doubleSettingValue = argValue

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

                End If

            End If

            System.Runtime.InteropServices.Marshal.ReleaseComObject(pIMCommandArgumentEnum_)

            Return retCode

        End Function

    End Class

    ' =============================================================================================
    ' TODO: Rename CompanyNameDouble with your company name and double setting name.
    '
    ' Gets a double value setting from the plug-in
    ' ---------------------------------------------------------------------------------------------
    Public Class CCmdCompanyNameDoubleGet
        Inherits CComCommand

        ' =========================================================================================
        ' Command constructor. 
        ' This constructor is only called one time when the command is registered to the 
        ' application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' -----------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =========================================================================================
        ' Gets a double value setting from the plug-in
        '
        ' Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' -----------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            Dim retCode As IMPluginLib.ECommandReturnCodes = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED

            ' Getting argument value
            If Not pIMCommandArgumentEnum_ Is Nothing Then

                ' Checking argument count validity
                If pIMCommandArgumentEnum_.ArgsGetNb() > 0 Then

                    ' Checking availability of first argument
                    Dim argument As IMPluginLib.IIMCommandArgument = Nothing
                    pIMCommandArgumentEnum_.ArgGet(0, argument)

                    If Not argument Is Nothing Then

                        ' TODO: Get setting value from the plug-in
                        ' TODO: Replace g_doubleSettingValue use by your own code
                        If argument.ArgValueSetFromDouble(1, Settings.g_doubleSettingValue) = 1 Then

                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

                        End If

                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument)

                    End If

                End If

            End If

            System.Runtime.InteropServices.Marshal.ReleaseComObject(pIMCommandArgumentEnum_)

            Return retCode

        End Function

    End Class

    ' =============================================================================================
    ' TODO: Rename CompanyNameInteger with your company name and integer setting name.
    '
    ' Sets a integer value setting within the plug-in
    ' ---------------------------------------------------------------------------------------------
    Public Class CCmdCompanyNameIntegerSet
        Inherits CComCommand

        ' =========================================================================================
        ' Command constructor. 
        ' This constructor is only called one time when the command is registered to the 
        ' application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' -----------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =========================================================================================
        ' Sets a integer value setting within the plug-in.
        '
        ' Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' -----------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            Dim retCode As IMPluginLib.ECommandReturnCodes = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED

            ' Getting argument value
            Dim success As Boolean = False
            Dim argValue As Integer = 0

            ' Setting argument value
            If Not pIMCommandArgumentEnum_ Is Nothing Then

                ' Checking argument count validity
                If pIMCommandArgumentEnum_.ArgsGetNb() > 0 Then

                    ' Checking availability of first argument
                    Dim argument As IMPluginLib.IIMCommandArgument = Nothing
                    pIMCommandArgumentEnum_.ArgGet(0, argument)

                    If Not argument Is Nothing Then

                        ' Checking and retrieving argument value if of valid type
                        If argument.ArgValueGetAsInt(1, argValue) = 1 Then

                            success = True

                        End If

                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument)

                    End If

                End If

            End If

            ' Argument value validation
            If success = True Then

                ' TODO: Replace validation code by your own depending on wanted argument value valid range
                If argValue < 0 Then

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_ARG_OUT_OF_RANGE

                Else

                    ' TODO: Register setting value into the plug-in for future use or execute action using argument value
                    ' TODO: Replace g_integerSettingValue use by your own code
                    Settings.g_integerSettingValue = argValue

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

                End If

            End If

            System.Runtime.InteropServices.Marshal.ReleaseComObject(pIMCommandArgumentEnum_)

            Return retCode

        End Function

    End Class

    ' =============================================================================================
    ' TODO: Rename CompanyNameInteger with your company name and integer setting name.
    '
    ' Gets a integer value setting from the plug-in
    ' ---------------------------------------------------------------------------------------------
    Public Class CCmdCompanyNameIntegerGet
        Inherits CComCommand

        ' =========================================================================================
        ' Command constructor. 
        ' This constructor is only called one time when the command is registered to the 
        ' application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' -----------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =========================================================================================
        ' Gets a integer value setting from the plug-in
        '
        ' Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' -----------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            Dim retCode As IMPluginLib.ECommandReturnCodes = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED

            ' Getting argument value
            If Not pIMCommandArgumentEnum_ Is Nothing Then

                ' Checking argument count validity
                If pIMCommandArgumentEnum_.ArgsGetNb() > 0 Then

                    ' Checking availability of first argument
                    Dim argument As IMPluginLib.IIMCommandArgument = Nothing
                    pIMCommandArgumentEnum_.ArgGet(0, argument)

                    If Not argument Is Nothing Then

                        ' TODO: Get setting value from the plug-in
                        ' TODO: Replace g_integerSettingValue use by your own code
                        If argument.ArgValueSetFromInt(1, Settings.g_integerSettingValue) = 1 Then

                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

                        End If

                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument)

                    End If

                End If

            End If

            System.Runtime.InteropServices.Marshal.ReleaseComObject(pIMCommandArgumentEnum_)

            Return retCode

        End Function

    End Class

    ' =============================================================================================
    ' TODO: Rename CompanyNameString with your company name and string setting name.
    '
    ' Sets a string value setting within the plug-in
    ' ---------------------------------------------------------------------------------------------
    Public Class CCmdCompanyNameStringSet
        Inherits CComCommand

        ' =========================================================================================
        ' Command constructor. 
        ' This constructor is only called one time when the command is registered to the 
        ' application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' -----------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =========================================================================================
        ' Sets a string value setting within the plug-in.
        '
        ' Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' -----------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            Dim retCode As IMPluginLib.ECommandReturnCodes = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED

            ' Getting argument value
            Dim success As Boolean = False
            Dim argValue As String = String.Empty

            ' Setting argument value
            If Not pIMCommandArgumentEnum_ Is Nothing Then

                ' Checking argument count validity
                If pIMCommandArgumentEnum_.ArgsGetNb() > 0 Then

                    ' Checking availability of first argument
                    Dim argument As IMPluginLib.IIMCommandArgument = Nothing
                    pIMCommandArgumentEnum_.ArgGet(0, argument)

                    If Not argument Is Nothing Then

                        ' Checking and retrieving argument value if of valid type
                        If argument.ArgValueGetAsString(1, argValue) = 1 Then

                            success = True

                        End If

                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument)

                    End If

                End If

            End If

            ' Argument value validation
            If success = True Then

                ' TODO: Replace validation code by your own depending on wanted argument value valid range
                If argValue = "Invalid" Then

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_ARG_INVALID_STRING

                Else

                    ' TODO: Register setting value into the plug-in for future use or execute action using argument value
                    ' TODO: Replace g_stringSettingValue use by your own code
                    Settings.g_stringSettingValue = argValue

                    retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

                End If

            End If

            System.Runtime.InteropServices.Marshal.ReleaseComObject(pIMCommandArgumentEnum_)

            Return retCode

        End Function

    End Class

    ' =============================================================================================
    ' TODO: Rename CompanyNameString with your company name and string setting name.
    '
    ' Gets a string value setting from the plug-in
    ' ---------------------------------------------------------------------------------------------
    Public Class CCmdCompanyNameStringGet
        Inherits CComCommand

        ' =========================================================================================
        ' Command constructor. 
        ' This constructor is only called one time when the command is registered to the 
        ' application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' -----------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =========================================================================================
        ' Gets a string value setting from the plug-in
        '
        ' Parameter: iIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' -----------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            Dim retCode As IMPluginLib.ECommandReturnCodes = IMPluginLib.ECommandReturnCodes.E_CMD_FAILED

            ' Getting argument value
            If Not pIMCommandArgumentEnum_ Is Nothing Then

                ' Checking argument count validity
                If pIMCommandArgumentEnum_.ArgsGetNb() > 0 Then

                    ' Checking availability of first argument
                    Dim argument As IMPluginLib.IIMCommandArgument = Nothing
                    pIMCommandArgumentEnum_.ArgGet(0, argument)

                    If Not argument Is Nothing Then

                        ' TODO: Get setting value from the plug-in
                        ' TODO: Replace g_stringSettingValue use by your own code
                        If argument.ArgValueSetFromString(1, Settings.g_stringSettingValue) = 1 Then

                            retCode = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

                        End If

                        System.Runtime.InteropServices.Marshal.ReleaseComObject(argument)

                    End If

                End If

            End If

            System.Runtime.InteropServices.Marshal.ReleaseComObject(pIMCommandArgumentEnum_)

            Return retCode

        End Function

    End Class

End Namespace

