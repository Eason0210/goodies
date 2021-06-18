' =================================================================================================
' Class for COM command parameters enumeration
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    <System.Runtime.InteropServices.ComVisible(True)> _
    <System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)> _
    Public Class CComCommandParameterEnum
        Implements IMPluginLib.IIMCommandParameterEnum

        ' =============================================================================
        '                            IIMCommandParameterEnum Interface
        ' =============================================================================

        Public Function ParamsGetNb() As Integer _
        Implements IMPluginLib.IIMCommandParameterEnum.ParamsGetNb

            If Not m_impl Is Nothing Then

                Return m_impl.ParamsGetNb()

            End If

            Return 0

        End Function

        Public Sub ParamGet(ByVal number_ As Integer, ByRef iIMCommandParameter_ As IMPluginLib.IIMCommandParameter) _
        Implements IMPluginLib.IIMCommandParameterEnum.ParamGet

            iIMCommandParameter_ = Nothing

            If Not m_impl Is Nothing Then

                m_impl.ParamGet(number_, iIMCommandParameter_)

            End If

        End Sub

        ' =============================================================================
        '              CComCommandParameterEnum specific methods
        ' =============================================================================

        ' =============================================================================
        ' Constructor
        ' -----------------------------------------------------------------------------
        Public Sub New()

            m_impl = New CComCommandParameterEnumImpl()

        End Sub

        ' =============================================================================
        ' Add an argument to the enumeration
        '
        ' Parameter: pCommandParameter_ : Argument to add
        ' -----------------------------------------------------------------------------
        Public Sub CommandParameterAdd(ByVal commandParameter_ As IMPluginLib.IIMCommandParameter)

            If Not m_impl Is Nothing Then

                m_impl.CommandParameterAdd(commandParameter_)

            End If

        End Sub

        Private m_impl As CComCommandParameterEnumImpl = Nothing

    End Class

End Namespace



