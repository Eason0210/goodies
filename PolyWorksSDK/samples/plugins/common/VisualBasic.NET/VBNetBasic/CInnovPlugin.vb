' =================================================================================================
' CInnovPlugin class.
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetBasic

    ' =============================================================================================
    '   Plug-in's COM object interface used to connect to a PolyWorks module.
    ' ---------------------------------------------------------------------------------------------
    <System.Runtime.InteropServices.ComVisible(True)> _
    <System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)> _
    <System.Runtime.InteropServices.Guid("20256276-EC1B-4D30-B432-9AAFED314598")> _
    Public Class CInnovPlugin
        Implements IMPluginLib.IIMPlugin
        Implements IMPluginLib.IIMCommand
        Implements IMPluginLib.IIMSettings

        ' =========================================================================================
        ' ========================================= IIMPlugin =====================================

        ' =========================================================================================
        ' Returns the plug-in's name.
        '
        ' Return: Plug-in's name.
        ' -----------------------------------------------------------------------------------------
        Public Function PlgNameGet() As String _
        Implements IMPluginLib.IIMPlugin.PlgNameGet

            Return "VBNetBasic"

        End Function

        ' =========================================================================================
        ' Returns the plug-in's version in the form of major.minor.dot.
        '
        ' Parameter: major_ : Major component of the plug-in's version
        ' Parameter: minor_ : Minor component of the plug-in's version
        ' Parameter: dot_   : Dot component of the plug-in's version
        ' -----------------------------------------------------------------------------------------
        Public Sub PlgVersionGet(ByRef major_ As Integer, ByRef minor_ As Integer, ByRef dot_ As Integer) _
        Implements IMPluginLib.IIMPlugin.PlgVersionGet

            major_ = 1
            minor_ = 0
            dot_ = 0

        End Sub

        ' =========================================================================================
        ' Called when the plug-in is loaded.
        '
        ' Parameter: iIMHost_ : Host's application.
        '
        ' Return: 1 if everything went well.
        '         0 if something went wrong.
        ' -----------------------------------------------------------------------------------------
        Public Function Load(ByVal pIIMHost_ As IMPluginLib.IIMHost) As Integer _
        Implements IMPluginLib.IIMPlugin.Load

            If pIIMHost_ Is Nothing Then

                Return 0

            End If

            ' Do nothing to accept all hosts (IMAlign, PolyWorks|Inspector, PolyWorks|Modeler, etc...)
            ' or do the following to accept only specific hosts (PolyWorks|Inspector in this case)

            Dim imInspect As IMInspectLib.IMInspect = TryCast(pIIMHost_, IMInspectLib.IMInspect)

            If imInspect Is Nothing Then

                ' Release the host
                System.Runtime.InteropServices.Marshal.ReleaseComObject(pIIMHost_)
                Return 0

            End If

            ' Obtain the command center interface
            Dim imInspectProject As IMInspectLib.IIMInspectProject = Nothing
            imInspect.ProjectGetCurrent(imInspectProject)

            If Not imInspectProject Is Nothing Then

                imInspectProject.CommandCenterCreate(m_imCommandCenter)
                System.Runtime.InteropServices.Marshal.ReleaseComObject(imInspectProject)
                imInspectProject = Nothing

            End If


            If m_imCommandCenter Is Nothing Then

                ' Release the host
                System.Runtime.InteropServices.Marshal.ReleaseComObject(pIIMHost_)
                Return 0

            End If

            ' Keep a reference to the host's application
            m_imHost = pIIMHost_

            Return 1

        End Function

        ' =========================================================================================
        ' Called when the plug-in is unloaded.
        '
        ' Return: 1 if everything went well.
        '         0 if something went wrong.
        ' -----------------------------------------------------------------------------------------
        Public Function Unload() As Integer _
        Implements IMPluginLib.IIMPlugin.Unload

            ' Release the host
            System.Runtime.InteropServices.Marshal.ReleaseComObject(m_imHost)
            m_imHost = Nothing

            ' Release the command center
            System.Runtime.InteropServices.Marshal.ReleaseComObject(m_imCommandCenter)
            m_imCommandCenter = Nothing

            Return 1

        End Function

        ' =========================================================================================
        ' ======================================== IIMCommand =====================================

        ' =========================================================================================
        ' See IIMCommand.CmdNameGet
        ' -----------------------------------------------------------------------------------------
        Public Function CmdNameGet() As String _
        Implements IMPluginLib.IIMCommand.CmdNameGet

            Return "VBNET_PLUGIN SHOW_MESSAGE"

        End Function

        ' =========================================================================================
        ' See IIMCommand.CmdDescGet
        ' -----------------------------------------------------------------------------------------
        Public Function CmdDescGet() As String _
        Implements IMPluginLib.IIMCommand.CmdDescGet

            Return "Shows a message from the VBNet sample plug-in"

        End Function

        ' =========================================================================================
        ' See IIMCommand.Execute
        ' -----------------------------------------------------------------------------------------
        Public Function Execute() As Integer _
        Implements IMPluginLib.IIMCommand.Execute

            ' Obtain the message center interface
            Dim imMessageCenter As IMInspectLib.IIMMessageCenter = TryCast(m_imHost, IMInspectLib.IIMMessageCenter)

            ' Obtain the sound center interface
            Dim imSoundCenter As IMInspectLib.IIMSoundCenter = TryCast(m_imHost, IMInspectLib.IIMSoundCenter)

            If imMessageCenter Is Nothing Or imSoundCenter Is Nothing Then

                Return 0

            End If

            ' Display a message using IMInspectLib.IIMMessageCenter COM interface
            imMessageCenter.MessageBox(IMInspectLib.EMessageTypes.E_MESSAGE_TYPE_INFORMATION, _
                                         "VBNet sample plug-in command invoked", _
                                         "", "VBNetBasic", 0, True, Nothing, 0)

            ' Play a sound using IMInspectLib.IIMSoundCenter COM interface
            imSoundCenter.Play("Error", False)

            ' Call MSCL commands using IMInspectLib.IIMCommandCenter COM interface
            ExecuteCommandOnApp("MACRO PAUSE( ""Message"", ""Check Command History"" )")
            ExecuteCommandOnApp("MACRO ECHO( ""Calling a command from the plug-in"" )")

            Return 1

        End Function

        ' =========================================================================================
        ' See IIMCommand.MenuLocationGet
        ' -----------------------------------------------------------------------------------------
        Public Function MenuLocationGet() As String _
        Implements IMPluginLib.IIMCommand.MenuLocationGet

            Return "VBNet sample\Show Message"

        End Function

        ' =========================================================================================
        ' See IIMCommand.MenuDescGet
        ' -----------------------------------------------------------------------------------------
        Public Function Base_MenuDescGet() As String _
        Implements IMPluginLib.IIMCommand.MenuDescGet

            Return CmdDescGet()

        End Function

        ' =========================================================================================
        ' ======================================= IIMSettings =====================================

        ' =========================================================================================
        ' See IIMSettings.DoubleSettingsNbGet
        ' -----------------------------------------------------------------------------------------
        Public Function DoubleSettingsNbGet() As Integer _
        Implements IMPluginLib.IIMSettings.DoubleSettingsNbGet

            Return 1

        End Function

        ' =========================================================================================
        ' See IIMSettings.DoubleSettingGet
        ' -----------------------------------------------------------------------------------------
        Public Sub DoubleSettingGet(ByVal settingIndex_ As Integer, ByRef settingName_ As String, ByRef defaultValue_ As Double, ByRef isUserSpecific_ As Boolean, ByRef isHostSpecific_ As Boolean, ByRef isProjectSetting_ As Boolean) _
        Implements IMPluginLib.IIMSettings.DoubleSettingGet

            ' settingIndex_ should be validated, and if more than one setting is available,
            ' settingIndex_ should be used to give the info about the right setting

            settingName_ = "VBNET_SAMPLE_DOUBLE_SETTING"

            defaultValue_ = 5264.463

            ' These are the recommended values for those parameters:

            isUserSpecific_ = True
            ' True means the setting be saved in the user's config
            ' False would save it globally for everyone that uses the same Polyworks installation

            isHostSpecific_ = False
            ' False means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
            ' True would reserve a different value for each software

            ' PolyWorks|Inspector only
            isProjectSetting_ = False

            ' False means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
            ' True would include it in PolyWorks|Inspector application settings when saving the project
            ' NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be True for such a saving to work

        End Sub

        ' =========================================================================================
        ' See IIMSettings.LongSettingsNbGet
        ' -----------------------------------------------------------------------------------------
        Public Function LongSettingsNbGet() As Integer _
        Implements IMPluginLib.IIMSettings.LongSettingsNbGet

            Return 1

        End Function

        ' =========================================================================================
        ' See IIMSettings.LongSettingGet
        ' -----------------------------------------------------------------------------------------
        Public Sub LongSettingGet(ByVal settingIndex_ As Integer, ByRef settingName_ As String, ByRef defaultValue_ As Integer, ByRef isUserSpecific_ As Boolean, ByRef isHostSpecific_ As Boolean, ByRef isProjectSetting_ As Boolean) _
        Implements IMPluginLib.IIMSettings.LongSettingGet

            ' settingIndex_ should be validated, and if more than one setting is available,
            ' settingIndex_ should be used to give the info about the right setting

            settingName_ = "VBNET_SAMPLE_LONG_SETTING"

            defaultValue_ = 867

            ' These are the recommended values for those parameters:

            isUserSpecific_ = True
            ' True means the setting be saved in the user's config
            ' False would save it globally for everyone that uses the same Polyworks installation

            isHostSpecific_ = False
            ' False means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
            ' True would reserve a different value for each software

            ' PolyWorks|Inspector only
            isProjectSetting_ = False

            ' False means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
            ' True would include it in PolyWorks|Inspector application settings when saving the project
            ' NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be True for such a saving to work

        End Sub

        ' =========================================================================================
        ' See IIMSettings.StringSettingsNbGet
        ' -----------------------------------------------------------------------------------------
        Public Function StringSettingsNbGet() As Integer _
        Implements IMPluginLib.IIMSettings.StringSettingsNbGet

            Return 1

        End Function

        ' =========================================================================================
        ' See IIMSettings.StringSettingGet
        ' -----------------------------------------------------------------------------------------
        Public Sub StringSettingGet(ByVal settingIndex_ As Integer, ByRef settingName_ As String, ByRef defaultValue_ As String, ByRef isUserSpecific_ As Boolean, ByRef isHostSpecific_ As Boolean, ByRef isProjectSetting_ As Boolean) _
        Implements IMPluginLib.IIMSettings.StringSettingGet

            ' settingIndex_ should be validated, and if more than one setting is available,
            ' settingIndex_ should be used to give the info about the right setting

            settingName_ = "VBNET_SAMPLE_STRING_SETTING"

            defaultValue_ = "Sample string setting"

            ' These are the recommended values for those parameters:

            isUserSpecific_ = True
            ' True means the setting be saved in the user's config
            ' False would save it globally for everyone that uses the same Polyworks installation

            isHostSpecific_ = False
            ' False means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
            ' True would reserve a different value for each software

            ' PolyWorks|Inspector only
            isProjectSetting_ = False

            ' False means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
            ' True would include it in PolyWorks|Inspector application settings when saving the project
            ' NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be True for such a saving to work

        End Sub

        ' =========================================================================================
        ' ======================================== Utilities ======================================
        Public Function ExecuteCommandOnApp(ByVal command_ As String) As Boolean

            ' Execute the command
            Dim returnValue As Integer = m_imCommandCenter.CommandExecute(command_)

            If m_imCommandCenter.ReturnValueIsSuccess(returnValue) = 1 Then

                Return True

            End If

            Return False

        End Function

        Private m_imCommandCenter As IMInspectLib.IIMCommandCenter = Nothing
        Private m_imHost As IMPluginLib.IIMHost = Nothing

    End Class

End Namespace

