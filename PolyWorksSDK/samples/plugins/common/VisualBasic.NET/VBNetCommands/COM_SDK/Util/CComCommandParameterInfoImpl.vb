' =================================================================================================
' Implementation of the class describing a COM command parameter
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    ' =================================================================================
    ' COM command parameter class description implementation
    ' A description, a direction and a type must at least be specified
    ' Otherwise, only needed members require initialisation
    ' ---------------------------------------------------------------------------------
    Public Class CComCommandParameterInfoImpl

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

            m_desc = desc_
            m_dir = dir_
            m_type = type_

        End Sub

        ' =============================================================================
        ' Copy constructor
        '
        ' Parameter: info_ : Object to be copied
        ' -----------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandParameterInfoImpl)

            If Not info_ Is Nothing Then

                m_desc = info_.m_desc
                m_values = info_.m_values
                m_dir = info_.m_dir
                m_type = info_.m_type
                m_hasDoubleDefaultValue = info_.m_hasDoubleDefaultValue
                m_doubleDefaultValue = info_.m_doubleDefaultValue
                m_hasIntDefaultValue = info_.m_hasIntDefaultValue
                m_intDefaultValue = info_.m_intDefaultValue
                m_hasStringDefaultValue = info_.m_hasStringDefaultValue
                m_stringDefaultValue = info_.m_stringDefaultValue

            End If

        End Sub

        Public m_desc As String                               ' Description 
        Public m_values As String = String.Empty              ' Possible values (in a string, separated by comas)
        Public m_dir As IMPluginLib.EParameterDirection       ' Direction
        Public m_type As IMPluginLib.EParameterType           ' Type
        Public m_hasDoubleDefaultValue As Boolean             ' True if parameter have a default double value
        Public m_doubleDefaultValue As Double                 ' Default value for double parameter
        Public m_hasIntDefaultValue As Boolean                ' True if parameter have a default integer value
        Public m_intDefaultValue As Integer                   ' Default value for integer parameter
        Public m_hasStringDefaultValue As Boolean             ' True if parameter have a default string value
        Public m_stringDefaultValue As String = String.Empty  ' Default value for string parameter

    End Class

End Namespace



