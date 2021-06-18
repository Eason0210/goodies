' =================================================================================================
' Class representing a COM command parameter
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    ' =============================================================================
    ' Classe used to implement a COM parameter
    '
    ' Derive from IIMCommandParameter 
    ' -----------------------------------------------------------------------------
    <System.Runtime.InteropServices.ComVisible(True)> _
    <System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)> _
    Public Class CComCommandParameter
        Implements IMPluginLib.IIMCommandParameter

        ' =============================================================================
        '                           IIMCommandParameter Interface 
        ' =============================================================================

        ' =============================================================================
        ' See IIMCommandParameter.ParamDescGet
        ' -----------------------------------------------------------------------------
        Public Function ParamDescGet() As String _
        Implements IMPluginLib.IIMCommandParameter.ParamDescGet

            If Not m_paramInfo Is Nothing Then

                Return m_paramInfo.DescGet()

            End If

            Return String.Empty

        End Function

        ' =============================================================================
        ' See IIMCommandParameter.ParamPossibleValuesGet
        ' -----------------------------------------------------------------------------
        Public Function ParamPossibleValuesGet() As String _
        Implements IMPluginLib.IIMCommandParameter.ParamPossibleValuesGet

            If Not m_paramInfo Is Nothing Then

                Return m_paramInfo.ValuesGet()

            End If

            Return String.Empty

        End Function

        ' =============================================================================
        ' See IIMCommandParameter.ParamDirGet
        ' -----------------------------------------------------------------------------
        Public Function ParamDirGet() As IMPluginLib.EParameterDirection _
        Implements IMPluginLib.IIMCommandParameter.ParamDirGet

            If Not m_paramInfo Is Nothing Then

                Return m_paramInfo.DirGet()

            End If

            Return 0

        End Function

        ' =============================================================================
        ' See IIMCommandParameter.ParamTypeGet
        ' -----------------------------------------------------------------------------
        Public Function ParamTypeGet() As IMPluginLib.EParameterType _
        Implements IMPluginLib.IIMCommandParameter.ParamTypeGet

            If Not m_paramInfo Is Nothing Then

                Return m_paramInfo.TypeGet()

            End If

            Return 0

        End Function

        ' =============================================================================
        ' See IIMCommandParameter.ParamDefaultDoubleValueGet
        ' -----------------------------------------------------------------------------
        Public Function ParamDefaultDoubleValueGet(ByRef defaultValue_ As Double) As Integer _
        Implements IMPluginLib.IIMCommandParameter.ParamDefaultDoubleValueGet

            defaultValue_ = 0.0

            If Not m_paramInfo Is Nothing Then

                If m_paramInfo.HasDoubleDefaultValueGet() = True Then

                    defaultValue_ = m_paramInfo.DoubleDefaultValueGet()

                    Return 1

                End If

            End If

            Return 0

        End Function

        ' =============================================================================
        ' See IIMCommandParameter.ParamDefaultIntValueGet
        ' -----------------------------------------------------------------------------
        Public Function ParamDefaultIntValueGet(ByRef defaultValue_ As Integer) As Integer _
        Implements IMPluginLib.IIMCommandParameter.ParamDefaultIntValueGet

            defaultValue_ = 0

            If Not m_paramInfo Is Nothing Then

                If m_paramInfo.HasIntDefaultValueGet() = True Then

                    defaultValue_ = m_paramInfo.IntDefaultValueGet()

                    Return 1

                End If

            End If

            Return 0

        End Function

        ' =============================================================================
        ' See IIMCommandParameter.ParamDefaultStringValueGet
        ' -----------------------------------------------------------------------------
        Public Function ParamDefaultStringValueGet(ByRef defaultValue_ As String) As Integer _
        Implements IMPluginLib.IIMCommandParameter.ParamDefaultStringValueGet

            defaultValue_ = String.Empty

            If Not m_paramInfo Is Nothing Then

                If m_paramInfo.HasStringDefaultValueGet() = True Then

                    defaultValue_ = m_paramInfo.StringDefaultValueGet()

                    Return 1

                End If

            End If

            Return 0

        End Function

        ' =============================================================================
        '              CComCommandParameter specific methods
        ' =============================================================================

        ' =============================================================================
        ' Constructor
        '
        ' Parameter: info_ : Information used to construct parameter
        ' -----------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandParameterInfo)

            m_paramInfo = New CComCommandParameterInfo(info_)

        End Sub

        Private m_paramInfo As CComCommandParameterInfo = Nothing

    End Class

End Namespace



