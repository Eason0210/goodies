' =================================================================================================
' Class describing a COM command parameter
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    ' =================================================================================
    ' COM command parameter class description implementation
    ' A description, a direction and a type must at least be specified
    ' Otherwise, only needed members require initialisation
    ' ---------------------------------------------------------------------------------
    Public Class CComCommandParameterInfo

        ' =============================================================================
        ' Constructor
        '
        ' Parameter: desc_ : Description
        ' Parameter: dir_  : Direction
        ' Parameter: type_ : Type
        ' -----------------------------------------------------------------------------
        Public Sub New(ByVal desc_ As String, _
                       ByVal dir_ As IMPluginLib.EParameterDirection, _
                       ByVal type_ As IMPluginLib.EParameterType)

            m_impl = New CComCommandParameterInfoImpl(desc_, dir_, type_)

        End Sub

        ' =============================================================================
        ' Copy constructor
        '
        ' Parameter: info_ : Object to be copied
        ' -----------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandParameterInfo)

            If Not info_ Is Nothing Then

                m_impl = New CComCommandParameterInfoImpl(info_.DescGet(), info_.DirGet(), info_.TypeGet())

                ValuesSet(info_.ValuesGet())
                HasDoubleDefaultValueSet(info_.HasDoubleDefaultValueGet())
                DoubleDefaultValueSet(info_.DoubleDefaultValueGet())
                HasIntDefaultValueSet(info_.HasIntDefaultValueGet())
                IntDefaultValueSet(info_.IntDefaultValueGet())
                HasStringDefaultValueSet(info_.HasStringDefaultValueGet())
                StringDefaultValueSet(info_.StringDefaultValueGet())

            End If

        End Sub

        ' ==============================================================================
        ' Members access methods
        ' ------------------------------------------------------------------------------

        ' Description 
        Public Function DescGet() As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_desc

            End If

            Return String.Empty

        End Function

        Public Sub DescSet(ByVal desc_ As String)

            If Not m_impl Is Nothing Then

                m_impl.m_desc = StrUtil.StrNonNull(desc_)

            End If

        End Sub

        ' Possible values (in a string, separated by comas)
        Public Function ValuesGet() As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_values

            End If

            Return String.Empty

        End Function

        Public Sub ValuesSet(ByVal values_ As String)

            If Not m_impl Is Nothing Then

                m_impl.m_values = StrUtil.StrNonNull(values_)

            End If

        End Sub

        ' Direction
        Public Function DirGet() As IMPluginLib.EParameterDirection

            If Not m_impl Is Nothing Then

                Return m_impl.m_dir

            End If

            Return 0

        End Function

        Public Sub DirSet(ByVal dir_ As IMPluginLib.EParameterDirection)

            If Not m_impl Is Nothing Then

                m_impl.m_dir = dir_

            End If

        End Sub

        ' Type
        Public Function TypeGet() As IMPluginLib.EParameterType

            If Not m_impl Is Nothing Then

                Return m_impl.m_type

            End If

            Return 0

        End Function

        Public Sub TypeSet(ByVal type_ As IMPluginLib.EParameterType)

            If Not m_impl Is Nothing Then

                m_impl.m_type = type_

            End If

        End Sub

        ' True if parameter have a default double value
        Public Function HasDoubleDefaultValueGet() As Boolean

            If Not m_impl Is Nothing Then

                Return m_impl.m_hasDoubleDefaultValue

            End If

            Return False

        End Function

        Public Sub HasDoubleDefaultValueSet(ByVal hasValue_ As Boolean)

            If Not m_impl Is Nothing Then

                m_impl.m_hasDoubleDefaultValue = hasValue_

            End If

        End Sub

        ' Default value for double parameter
        Public Function DoubleDefaultValueGet() As Double

            If Not m_impl Is Nothing Then

                Return m_impl.m_doubleDefaultValue

            End If

            Return 0.0

        End Function

        Public Sub DoubleDefaultValueSet(ByVal value_ As Double)

            If Not m_impl Is Nothing Then

                m_impl.m_doubleDefaultValue = value_

            End If

        End Sub

        ' True if parameter have a default integer value
        Public Function HasIntDefaultValueGet() As Boolean

            If Not m_impl Is Nothing Then

                Return m_impl.m_hasIntDefaultValue

            End If

            Return False

        End Function

        Public Sub HasIntDefaultValueSet(ByVal hasValue_ As Boolean)

            If Not m_impl Is Nothing Then

                m_impl.m_hasIntDefaultValue = hasValue_

            End If

        End Sub

        ' Default value for integer parameter
        Public Function IntDefaultValueGet() As Integer

            If Not m_impl Is Nothing Then

                Return m_impl.m_intDefaultValue

            End If

            Return 0

        End Function

        Public Sub IntDefaultValueSet(ByVal value_ As Integer)

            If Not m_impl Is Nothing Then

                m_impl.m_intDefaultValue = value_

            End If

        End Sub

        ' True if parameter have a default string value
        Public Function HasStringDefaultValueGet() As Boolean

            If Not m_impl Is Nothing Then

                Return m_impl.m_hasStringDefaultValue

            End If

            Return False

        End Function

        Public Sub HasStringDefaultValueSet(ByVal hasValue_ As Boolean)

            If Not m_impl Is Nothing Then

                m_impl.m_hasStringDefaultValue = hasValue_

            End If

        End Sub

        ' Default value for string parameter
        Public Function StringDefaultValueGet() As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_stringDefaultValue

            End If

            Return String.Empty

        End Function

        Public Sub StringDefaultValueSet(ByVal value_ As String)

            If Not m_impl Is Nothing Then

                m_impl.m_stringDefaultValue = StrUtil.StrNonNull(value_)

            End If

        End Sub

        Private m_impl As CComCommandParameterInfoImpl = Nothing

    End Class

End Namespace


