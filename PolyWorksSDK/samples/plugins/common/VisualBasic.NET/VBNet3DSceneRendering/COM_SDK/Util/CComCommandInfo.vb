' =================================================================================================
' Class describing a COM command
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =============================================================================
    ' COM command class description implementation
    ' A description and a name must at least be specified
    ' Otherwise, only needed members require initialisation
    ' -----------------------------------------------------------------------------
    Public Class CComCommandInfo

        ' =============================================================================
        ' Constructor
        '
        ' Parameter: name_    : Name 
        ' Parameter: desc_    : Description 
        ' -----------------------------------------------------------------------------
        Public Sub New(ByVal name_ As String, ByVal desc_ As String)

            m_impl = New CComCommandInfoImpl(name_, desc_)

        End Sub

        ' =============================================================================
        ' Copy constructor
        '
        ' Parameter: info_ : Object to be copied
        ' -----------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            If Not info_ Is Nothing Then

                m_impl = New CComCommandInfoImpl(info_.NameGet(), info_.DescGet())

                m_impl.m_note = StrUtil.StrNonNull(info_.NoteGet())
                m_impl.m_menuLocation = StrUtil.StrNonNull(info_.MenuLocationGet())
                m_impl.m_menuDesc = StrUtil.StrNonNull(info_.MenuDescGet())
                m_impl.m_isObsolete = info_.IsObsoleteGet()
                m_impl.m_supersedingCommand = StrUtil.StrNonNull(info_.SupersedingCommandGet())

                ' Copying old names
                Dim nbNames As UInteger = info_.DeprecatedNamesGetNb()
                Dim iName As UInteger = 0

                While iName < nbNames

                    DeprecatedNameAdd(StrUtil.StrNonNull(info_.DeprecatedNameGet(iName)))
                    iName += 1

                End While

                ' Copying parameters   
                Dim paramEnum As CComCommandParameterEnum = info_.ParameterEnumGet()

                If Not paramEnum Is Nothing Then

                    Dim param As IMPluginLib.IIMCommandParameter = Nothing
                    Dim nbParams As Integer = paramEnum.ParamsGetNb()
                    Dim iParam As Integer = 0

                    While iParam < nbParams

                        paramEnum.ParamGet(iParam, param)

                        If Not param Is Nothing Then

                            m_impl.m_parameterEnum.CommandParameterAdd(param)

                        End If

                        iParam += 1

                    End While

                End If

            End If

        End Sub

        ' =============================================================================
        ' Members access methods
        ' -----------------------------------------------------------------------------

        ' Name
        Public Function NameGet() As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_name

            End If

            Return String.Empty

        End Function


        Public Sub NameSet(ByVal name_ As String)

            If Not m_impl Is Nothing Then

                m_impl.m_name = StrUtil.StrNonNull(name_)

            End If

        End Sub

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

        ' Note to be added to description
        Public Function NoteGet() As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_note

            End If

            Return String.Empty

        End Function

        Public Sub NoteSet(ByVal note_ As String)

            If Not m_impl Is Nothing Then

                m_impl.m_note = StrUtil.StrNonNull(note_)

            End If

        End Sub

        ' Menu item location
        Public Function MenuLocationGet() As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_menuLocation

            End If

            Return String.Empty

        End Function

        Public Sub MenuLocationSet(ByVal menuLocation_ As String)

            If Not m_impl Is Nothing Then

                m_impl.m_menuLocation = StrUtil.StrNonNull(menuLocation_)

            End If

        End Sub

        ' Menu item description
        ' (if empty, command description is used)
        Public Function MenuDescGet() As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_menuDesc

            End If

            Return String.Empty

        End Function

        Public Sub MenuDescSet(ByVal menuDesc_ As String)

            If Not m_impl Is Nothing Then

                m_impl.m_menuDesc = StrUtil.StrNonNull(menuDesc_)

            End If

        End Sub

        ' Deprecated names of the command
        ' (as long as parameter list have not changed)
        Public Function DeprecatedNamesGetNb() As UInteger

            If Not m_impl Is Nothing Then

                Return m_impl.m_deprecatedNames.Count

            End If

            Return 0

        End Function

        Public Function DeprecatedNameGet(ByVal index_ As UInteger) As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_deprecatedNames(index_)

            End If


            Return String.Empty

        End Function

        Public Sub DeprecatedNameAdd(ByVal deprecatedName_ As String)

            ' Making sure we have a valid string
            If Not String.IsNullOrEmpty(deprecatedName_) Then

                m_impl.m_deprecatedNames.Add(deprecatedName_)

            End If

        End Sub

        ' True if the command is obsolete
        Public Function IsObsoleteGet() As Boolean

            If Not m_impl Is Nothing Then

                Return m_impl.m_isObsolete

            End If

            Return False

        End Function

        Public Sub IsObsoleteSet(ByVal isObsolete_ As Boolean)

            If Not m_impl Is Nothing Then

                m_impl.m_isObsolete = isObsolete_

            End If

        End Sub

        ' Indicate which command have replaced this obsolete command
        ' (empty if no command replace this obsolete command)
        Public Function SupersedingCommandGet() As String

            If Not m_impl Is Nothing Then

                Return m_impl.m_supersedingCommand

            End If

            Return String.Empty

        End Function

        Public Sub SupersedingCommandSet(ByVal cmdName_ As String)

            If Not m_impl Is Nothing Then

                m_impl.m_supersedingCommand = StrUtil.StrNonNull(cmdName_)

            End If

        End Sub

        ' Enumeration of command parameters
        Public Function ParameterEnumGet() As CComCommandParameterEnum

            If Not m_impl Is Nothing Then

                Return m_impl.m_parameterEnum

            End If

            Return Nothing

        End Function

        Private m_impl As CComCommandInfoImpl = Nothing

    End Class

End Namespace
