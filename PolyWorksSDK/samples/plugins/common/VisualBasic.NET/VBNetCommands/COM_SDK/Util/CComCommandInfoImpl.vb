' =================================================================================================
' Class describing a COM command
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    ' =============================================================================
    ' COM command class description implementation
    ' A description and a name must at least be specified
    ' Otherwise, only needed members require initialisation
    ' -----------------------------------------------------------------------------
    Public Class CComCommandInfoImpl

        ' =============================================================================
        ' Constructor
        '
        ' Parameter: name_    : Name 
        ' Parameter: desc_    : Description 
        ' -----------------------------------------------------------------------------
        Public Sub New(ByVal name_ As String, ByVal desc_ As String)

            m_name = name_
            m_desc = desc_

        End Sub


        Public m_name As String                                     ' Name
        Public m_desc As String                                     ' Description
        Public m_note As String = String.Empty                      ' Note to be added to description
        Public m_menuLocation As String = String.Empty              ' Menu item location
        Public m_menuDesc As String = String.Empty                  ' Menu item description (if empty, command description is used)
        Public m_isObsolete As Boolean                              ' True if the command is obsolete
        Public m_supersedingCommand As String = String.Empty        ' Indicate which command have replaced this obsolete command (empty if no command replace this obsolete command)

        Public m_deprecatedNames As System.Collections.Generic.List(Of String) = New System.Collections.Generic.List(Of String)() ' Deprecated names of the command

        Public m_parameterEnum As CComCommandParameterEnum = New CComCommandParameterEnum() ' Enumeration of command parameters  

    End Class

End Namespace

