' =================================================================================================
' Class representing a COM command
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    ' =============================================================================
    ' Base class for a COM command
    ' Method Execute2 must at least be redefined
    ' If command parameters can be validated, ArgsTest should also be redefined
    ' All other stuff is managed automatically based on CComCommandInfo content
    ' This does not prevent any other method redefinition for particular needs
    '
    ' Derive from IIMCommand2 
    ' -----------------------------------------------------------------------------
    <System.Runtime.InteropServices.ComVisible(True)> _
    <System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)> _
    Public Class CComCommand
        Implements IMPluginLib.IIMCommand2

        ' =============================================================================
        '                            IIMCommand Interface
        ' =============================================================================

        ' =============================================================================
        ' See IIMCommand.CmdNameGet
        ' -----------------------------------------------------------------------------
        Public Function Base_CmdNameGet() As String _
        Implements IMPluginLib.IIMCommand.CmdNameGet

            If Not m_commandInfo Is Nothing Then

                Return m_commandInfo.NameGet()

            End If

            Return String.Empty

        End Function

        ' =============================================================================
        ' See IIMCommand.CmdDescGet
        ' -----------------------------------------------------------------------------
        Public Function Base_CmdDescGet() As String _
        Implements IMPluginLib.IIMCommand.CmdDescGet

            If Not m_commandInfo Is Nothing Then

                Return m_commandInfo.DescGet()

            End If

            Return String.Empty

        End Function

        ' =============================================================================
        ' See IIMCommand.Execute
        ' -----------------------------------------------------------------------------
        Public Function Base_Execute() As Integer _
        Implements IMPluginLib.IIMCommand.Execute

            If Execute2(Nothing) = IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED Then

                Return 1

            End If

            Return 0

        End Function

        ' =============================================================================
        ' See IIMCommand.MenuLocationGet
        ' -----------------------------------------------------------------------------
        Public Function Base_MenuLocationGet() As String _
        Implements IMPluginLib.IIMCommand.MenuLocationGet

            If Not m_commandInfo Is Nothing Then

                Return m_commandInfo.MenuLocationGet()

            End If

            Return String.Empty

        End Function

        ' =============================================================================
        ' See IIMCommand.MenuDescGet
        ' -----------------------------------------------------------------------------
        Public Function Base_MenuDescGet() As String _
        Implements IMPluginLib.IIMCommand.MenuDescGet

            If Not m_commandInfo Is Nothing Then

                ' If a menu description exist, we take it, otherwise, command description is used
                Dim menuDesc As String = StrUtil.StrNonNull(m_commandInfo.MenuDescGet())

                If Not String.IsNullOrEmpty(menuDesc) Then

                    Return menuDesc

                End If

                Return m_commandInfo.DescGet()

            End If

            Return String.Empty

        End Function

        ' =============================================================================
        '                            IIMCommand2 Interface
        ' =============================================================================

        ' =============================================================================
        ' See IIMCommand.CmdNameGet
        ' -----------------------------------------------------------------------------
        Public Function CmdNameGet() As String _
        Implements IMPluginLib.IIMCommand2.CmdNameGet

            Return Base_CmdNameGet()

        End Function

        ' =============================================================================
        ' See IIMCommand.CmdDescGet
        ' -----------------------------------------------------------------------------
        Public Function CmdDescGet() As String _
        Implements IMPluginLib.IIMCommand2.CmdDescGet

            Return Base_CmdDescGet()

        End Function

        ' =============================================================================
        ' See IIMCommand.Execute
        ' -----------------------------------------------------------------------------
        Public Function Execute() As Integer _
        Implements IMPluginLib.IIMCommand2.Execute

            Return Execute()

        End Function

        ' =============================================================================
        ' See IIMCommand.MenuLocationGet
        ' -----------------------------------------------------------------------------
        Public Function MenuLocationGet() As String _
        Implements IMPluginLib.IIMCommand2.MenuLocationGet

            Return Base_MenuLocationGet()

        End Function

        ' =============================================================================
        ' See IIMCommand.MenuDescGet
        ' -----------------------------------------------------------------------------
        Public Function MenuDescGet() As String _
        Implements IMPluginLib.IIMCommand2.MenuDescGet

            Return Base_MenuDescGet()

        End Function

        ' =============================================================================
        ' See IIMCommand2.ArgsTest
        '
        ' A simple check for argument count corresponding to parameter count is performed here
        ' -----------------------------------------------------------------------------
        Public Function ArgsTest(ByVal pIIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes _
        Implements IMPluginLib.IIMCommand2.ArgsTest

            If Not pIIMCommandArgumentEnum_ Is Nothing Then

                Dim nbArgs As Integer = pIIMCommandArgumentEnum_.ArgsGetNb()
                Dim nbParams As Integer = m_commandInfo.ParameterEnumGet().ParamsGetNb()

                If nbArgs = nbParams Then

                    System.Runtime.InteropServices.Marshal.ReleaseComObject(pIIMCommandArgumentEnum_)

                    Return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

                End If

                System.Runtime.InteropServices.Marshal.ReleaseComObject(pIIMCommandArgumentEnum_)

                Return IMPluginLib.ECommandReturnCodes.E_CMD_FAILED

            End If

        End Function


        ' =============================================================================
        ' See IIMCommand2.CmdDeprecatedNamesGet
        ' -----------------------------------------------------------------------------
        Public Sub CmdDeprecatedNamesGet(ByRef names_ As System.Array) _
        Implements IMPluginLib.IIMCommand2.CmdDeprecatedNamesGet

            Dim nbNames As UInteger = m_commandInfo.DeprecatedNamesGetNb()
            If nbNames > 0 Then
                Dim arrayVector As System.Collections.ArrayList = New System.Collections.ArrayList()

                Dim iName As UInteger = 0
                While iName < nbNames

                    Dim name As String
                    name = StrUtil.StrNonNull(m_commandInfo.DeprecatedNameGet(iName))
                    If Not String.IsNullOrEmpty(name) Then
                        arrayVector.Add(name)
                    End If

                    iName += 1

                End While

                If arrayVector.Count > 0 Then
                    arrayVector.CopyTo(names_)
                End If
            End If
        End Sub

        ' =============================================================================
        ' See IIMCommand.CmdIsObsolete
        ' -----------------------------------------------------------------------------
        Public Sub CmdIsObsolete(ByRef pIsObsolete_ As Boolean, ByRef pSupersedingCmd_ As String) _
        Implements IMPluginLib.IIMCommand2.CmdIsObsolete

            pIsObsolete_ = False
            pSupersedingCmd_ = Nothing

            If Not m_commandInfo Is Nothing Then

                pIsObsolete_ = m_commandInfo.IsObsoleteGet()

                If pIsObsolete_ = True Then

                    pSupersedingCmd_ = m_commandInfo.SupersedingCommandGet()

                End If

            End If

        End Sub

        ' =============================================================================
        ' See IIMCommand2.CmdNoteGet
        ' -----------------------------------------------------------------------------
        Public Function CmdNoteGet() As String _
        Implements IMPluginLib.IIMCommand2.CmdNoteGet

            If Not m_commandInfo Is Nothing Then

                Return m_commandInfo.NoteGet()

            End If

            Return String.Empty

        End Function

        ' =============================================================================
        ' See IIMCommand2.Execute2
        ' -----------------------------------------------------------------------------
        Public Overridable Function Execute2(ByVal pIIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes _
        Implements IMPluginLib.IIMCommand2.Execute2

        End Function

        ' =============================================================================
        ' See IIMCommand2.ParamsGet
        ' -----------------------------------------------------------------------------
        Public Sub ParamsGet(ByRef iIMCommandParameterEnum_ As IMPluginLib.IIMCommandParameterEnum) _
        Implements IMPluginLib.IIMCommand2.ParamsGet

            iIMCommandParameterEnum_ = Nothing

            If Not m_commandInfo Is Nothing Then

                iIMCommandParameterEnum_ = m_commandInfo.ParameterEnumGet()

            End If

        End Sub

        ' =============================================================================
        '              CComCommand specific methods
        ' =============================================================================

        ' =============================================================================
        ' Constructor
        '
        ' Parameter: info_ : Information used to construct command
        ' -----------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            m_commandInfo = New CComCommandInfo(info_)

        End Sub

        Protected m_commandInfo As CComCommandInfo = Nothing

    End Class

End Namespace



