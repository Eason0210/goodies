' =================================================================================================
' String utilities.
'
' Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNetCommands

    Public Class StrUtil

        Public Shared Function StrNonNull(ByVal str_ As String) As String

            If str_ Is Nothing Then

                Return str_ = String.Empty

            End If

            Return str_

        End Function

    End Class

End Namespace




