' =================================================================================================
' Implementation of the class for COM command parameters enumeration
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    Public Class CComCommandParameterEnumImpl

        ' =============================================================================
        '                           IIMCommandParameterEnum Interface
        ' =============================================================================

        ' =============================================================================
        ' See CComCommandParameterEnum.ParamsGetNb
        ' -----------------------------------------------------------------------------
        Public Function ParamsGetNb() As Integer

            If Not m_parameters Is Nothing Then

                Return m_parameters.Count

            End If

            Return 0

        End Function


        ' =============================================================================
        ' See CComCommandParameterEnum.ParamGet
        ' -----------------------------------------------------------------------------
        Public Sub ParamGet(ByVal number_ As Integer, ByRef pIIMCommandParameter_ As IMPluginLib.IIMCommandParameter)

            pIIMCommandParameter_ = Nothing

            If m_parameters Is Nothing Then

                Return

            End If

            If number_ >= 0 And number_ < m_parameters.Count Then

                pIIMCommandParameter_ = m_parameters(number_)

            End If

        End Sub


        ' =============================================================================
        '               CComCommandParameterEnumImpl specific methods
        ' =============================================================================

        ' =============================================================================
        ' Add an argument to the enumeration
        '
        ' Parameter: pCommandParameter_ : Argument to add
        ' -----------------------------------------------------------------------------
        Public Sub CommandParameterAdd(ByVal commandParameter_ As IMPluginLib.IIMCommandParameter)

            If Not m_parameters Is Nothing Then

                m_parameters.Add(commandParameter_)

            End If

        End Sub

        Private m_parameters As System.Collections.Generic.List(Of IMPluginLib.IIMCommandParameter) = New System.Collections.Generic.List(Of IMPluginLib.IIMCommandParameter)()

    End Class

End Namespace



