' =================================================================================================
' CCompanyNameComPlugin class.
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =============================================================================================
    '   Plug-in's COM object interface used to connect to a PolyWorks module.
    ' ---------------------------------------------------------------------------------------------
    <System.Runtime.InteropServices.ComVisible(True)> _
    <System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)> _
    <System.Runtime.InteropServices.Guid("EF961101-BBC0-4265-A188-9B2DAEA27A8D")> _
    Public Class CCompanyNameComPlugin
        Implements IMPluginLib.IIMPlugin
        Implements IMPluginLib.IIMCommandEnum

        ' Make sure your plug-in name does not exceed 31 character
        Private m_pluginName As String = "CompanyName VBNet Rendering"

        Private m_commands As System.Collections.Generic.List(Of IMPluginLib.IIMCommand2) = New System.Collections.Generic.List(Of IMPluginLib.IIMCommand2)()

        ' =========================================================================================
        ' Adds MSCL commands to the commands vector member variable.
        ' -----------------------------------------------------------------------------------------
        Public Sub CommandsAdd()

            ' =========================================================================================
            ' MENU commands
            ' -----------------------------------------------------------------------------------------

            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command a good name and a good description.
            Dim cmdInfoStart As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET DRAW START", _
                "Start drawing.")

            ' TODO: Replace "CompanyName" by your company name
            cmdInfoStart.MenuLocationSet("CompanyName VBNet3DSceneRendering\Start drawing")

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyName3DSceneRenderingStart(cmdInfoStart))

            ' TODO: Replace COMPANY_NAME_VBNET by your company name, give the command a good name and a good description.
            Dim cmdInfoStop As CComCommandInfo = New CComCommandInfo( _
                "COMPANY_NAME_VBNET DRAW STOP", _
                "Stop drawing.")

            ' TODO: Replace "CompanyName" by your company name
            cmdInfoStop.MenuLocationSet("CompanyName VBNet3DSceneRendering\Stop drawing")

            ' Add the command to the command vector
            m_commands.Add(New CCmdCompanyName3DSceneRenderingStop(cmdInfoStop))

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

            ' 3D scene rendering functionalities are only supported in PolyWorks|Inspector
            If Not TypeOf pIIMHost_ Is IMInspectLib.IMInspect Then

                System.Runtime.InteropServices.Marshal.ReleaseComObject(pIIMHost_)
                Return 0

            End If

            Dim canLoad As Boolean
            canLoad = IMM.FnDotNetPlugin.DotNetPluginConnect(PlgNameGet(), _
                                                             New IMM.DSDKVersionGet(AddressOf Connection.SDKVersionGet), _
                                                             New IMM.DInterfaceGet(AddressOf Connection.PluginInterfaceGet))

            System.Runtime.InteropServices.Marshal.ReleaseComObject(pIIMHost_)

            If (canLoad) Then
                Return 1
            Else
                Return 0
            End If

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



