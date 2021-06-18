' =================================================================================================
' CCompanyNameComPlugin class.
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    ' =============================================================================================
    '   Plug-in's COM object interface used to connect to a PolyWorks module.
    ' ---------------------------------------------------------------------------------------------
    <System.Runtime.InteropServices.ComVisible(True)> _
    <System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)> _
    <System.Runtime.InteropServices.Guid("B52A0137-5CF8-4BCF-ABC4-49630DC707DC")> _
    Public Class CCompanyNameComPlugin
        Implements IMPluginLib.IIMPlugin
        Implements IMPluginLib.IIMCommandEnum

        ' Make sure your plug-in name does not exceed 31 character
        Private m_pluginName As String = "CompanyName VBNetCommands"

        ' Command center from the current PolyWorks|Inspector project
        Private m_inspectCommandCenter As IMInspectLib.IIMCommandCenter

        Private m_commands As System.Collections.Generic.List(Of IMPluginLib.IIMCommand2) = New System.Collections.Generic.List(Of IMPluginLib.IIMCommand2)()

        ' =========================================================================================
        ' Adds MSCL commands to the commands vector member variable.
        ' -----------------------------------------------------------------------------------------
        Public Sub CommandsAdd()

            ' =========================================================================================
            ' MENU command
            ' -----------------------------------------------------------------------------------------

            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command good name and a good description.
            Dim cmdInfo As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET COMMAND_ACTION", _
                "Command action description.")

            ' TODO: Replace "CompanyName VisualBasic.Net" by your company name
            cmdInfo.MenuLocationSet("CompanyName VBNetCommands\Menu Item Action Name")

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyNameAction(cmdInfo))

            ' =========================================================================================
            ' Command that executes a macro script
            ' -----------------------------------------------------------------------------------------
            If m_inspectCommandCenter IsNot Nothing Then

                ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command good name and a good description.
                cmdInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET COMMAND_FROM_MACRO", _
                "Command from macro description.")

                ' Add the command to the command vector
                m_commands.Add(New CCmdCompanyNameCmdFromMacro(cmdInfo, m_inspectCommandCenter))

            End If

            ' =========================================================================================
            ' DOUBLE setting value SET command
            ' -----------------------------------------------------------------------------------------

            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command good name and a good description.
            Dim cmdInfoDoubleValueSet As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET DOUBLE_SETTING", _
                "Sets a double value setting.")

            Dim param01 As CComCommandParameterInfo = New CComCommandParameterInfo( _
                "Double setting", _
                IMPluginLib.EParameterDirection.E_PARAM_DIR_IN, _
                IMPluginLib.EParameterType.E_PARAM_TYPE_DOUBLE)

            cmdInfoDoubleValueSet.ParameterEnumGet().CommandParameterAdd(New CComCommandParameter(param01))

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyNameDoubleSet(cmdInfoDoubleValueSet))

            ' =========================================================================================
            ' DOUBLE setting value GET command
            ' =========================================================================================

            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command good name and a good description.
            Dim cmdInfoDoubleValueGet As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET DOUBLE_SETTING GET", _
                "Gets a double value setting.")

            param01 = New CComCommandParameterInfo( _
                "Double setting", _
                IMPluginLib.EParameterDirection.E_PARAM_DIR_OUT, _
                IMPluginLib.EParameterType.E_PARAM_TYPE_DOUBLE)

            cmdInfoDoubleValueGet.ParameterEnumGet().CommandParameterAdd(New CComCommandParameter(param01))

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyNameDoubleGet(cmdInfoDoubleValueGet))

            ' =========================================================================================
            ' INTEGER setting value SET command
            ' =========================================================================================

            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command good name and a good description.
            Dim cmdInfoIntegerValueSet As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET INTEGER_SETTING", _
                "Sets an integer value setting.")

            param01 = New CComCommandParameterInfo( _
                "Integer setting", _
                IMPluginLib.EParameterDirection.E_PARAM_DIR_IN, _
                IMPluginLib.EParameterType.E_PARAM_TYPE_INTEGER)

            cmdInfoIntegerValueSet.ParameterEnumGet().CommandParameterAdd(New CComCommandParameter(param01))

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyNameIntegerSet(cmdInfoIntegerValueSet))

            ' =========================================================================================
            ' INTEGER setting value GET command
            ' =========================================================================================

            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command good name and a good description.
            Dim cmdInfoIntegerValueGet As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET INTEGER_SETTING GET", _
                "Gets an integer value setting.")

            param01 = New CComCommandParameterInfo( _
                "Double setting", _
                IMPluginLib.EParameterDirection.E_PARAM_DIR_OUT, _
                IMPluginLib.EParameterType.E_PARAM_TYPE_INTEGER)

            cmdInfoIntegerValueGet.ParameterEnumGet().CommandParameterAdd(New CComCommandParameter(param01))

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyNameIntegerGet(cmdInfoIntegerValueGet))

            ' =========================================================================================
            ' STRING setting value SET command
            ' =========================================================================================

            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command good name and a good description.
            Dim cmdInfoStringValueSet As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET STRING_SETTING", _
                "Sets an string value setting.")

            param01 = New CComCommandParameterInfo( _
                "String setting", _
                IMPluginLib.EParameterDirection.E_PARAM_DIR_IN, _
                IMPluginLib.EParameterType.E_PARAM_TYPE_STRING)

            cmdInfoStringValueSet.ParameterEnumGet().CommandParameterAdd(New CComCommandParameter(param01))

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyNameStringSet(cmdInfoStringValueSet))

            ' =========================================================================================
            ' STRING setting value GET command
            ' =========================================================================================


            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command good name and a good description.
            Dim cmdInfoStringValueGet As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET STRING_SETTING GET", _
                "Gets an string value setting.")

            param01 = New CComCommandParameterInfo( _
                "Double setting", _
                IMPluginLib.EParameterDirection.E_PARAM_DIR_OUT, _
                IMPluginLib.EParameterType.E_PARAM_TYPE_STRING)

            cmdInfoStringValueGet.ParameterEnumGet().CommandParameterAdd(New CComCommandParameter(param01))

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyNameStringGet(cmdInfoStringValueGet))

        End Sub

        ' =========================================================================================
        ' Releases any commands added in CommandsAdd.
        ' -----------------------------------------------------------------------------------------
        Public Sub CommandsRemove()

            m_commands.Clear()

        End Sub

        ' =========================================================================================
        ' ========================================= IIMPlugin =====================================

        ' =========================================================================================
        ' Returns the plug-in's name.
        '
        ' Return: Plug-in's name.
        ' -----------------------------------------------------------------------------------------
        Public Function PlgNameGet() As String _
        Implements IMPluginLib.IIMPlugin.PlgNameGet

            Return m_pluginName

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

            ' -----------------------------------------------------------------------------------------
            ' Obtain a Command center from the current PolyWorks|Inspector project

            Dim imInspectObject As IMInspectLib.IMInspect = Nothing

            Try
                imInspectObject = pIIMHost_
            Catch e As System.InvalidCastException
                ' The host application is not PolyWorks|Inspector
            End Try

            ' The host application is PolyWorks|Inspector
            If imInspectObject IsNot Nothing Then

                ' Obtain PolyWorks|Inspector's current project
                Dim projectObject As IMInspectLib.IIMInspectProject = Nothing

                imInspectObject.ProjectGetCurrent(projectObject)

                If projectObject IsNot Nothing Then

                    ' Obtain the command center
                    projectObject.CommandCenterCreate(m_inspectCommandCenter)

                    System.Runtime.InteropServices.Marshal.ReleaseComObject(projectObject)

                End If

                System.Runtime.InteropServices.Marshal.ReleaseComObject(imInspectObject)

            End If

            System.Runtime.InteropServices.Marshal.ReleaseComObject(pIIMHost_)

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

            CommandsRemove()

            If m_inspectCommandCenter IsNot Nothing Then

                System.Runtime.InteropServices.Marshal.ReleaseComObject(m_inspectCommandCenter)

            End If

            Return 1

        End Function

        ' =========================================================================================
        ' ====================================== IIMCommandEnum ===================================

        ' =========================================================================================
        ' Returns the number of MSCL command's registered by this plug-in.  
        '
        ' Return: Number of MSCL command's registered by this plug-in.
        ' -----------------------------------------------------------------------------------------
        Public Function CmdsGetNb() As Integer _
        Implements IMPluginLib.IIMCommandEnum.CmdsGetNb

            If m_commands.Count = 0 Then

                CommandsAdd()

            End If

            Return m_commands.Count

        End Function

        ' =========================================================================================
        ' Returns a COM interface pointer to a MSCL command.
        '
        ' Parameter: number_     : Index of the command to be returned
        ' Parameter: iIMCommand_ : COM interface object.
        ' -----------------------------------------------------------------------------------------
        Public Sub CmdGet(ByVal number_ As Integer, ByRef pIIMCommand_ As IMPluginLib.IIMCommand) _
        Implements IMPluginLib.IIMCommandEnum.CmdGet

            pIIMCommand_ = Nothing

            If number_ >= 0 And number_ < m_commands.Count Then

                pIIMCommand_ = m_commands(number_)

            End If

        End Sub

    End Class

End Namespace



