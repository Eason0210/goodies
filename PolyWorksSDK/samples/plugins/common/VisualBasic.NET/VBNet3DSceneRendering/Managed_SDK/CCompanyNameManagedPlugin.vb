' =================================================================================================
' CCompanyNameManagedPlugin class.
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =================================================================================================
    ' Plug-in C# interface used to connect to a PolyWorks module.
    ' -------------------------------------------------------------------------------------------------
    Public Class CCompanyNameManagedPlugin
        Implements IMM.IPlugin

        Public Function Load() As Boolean Implements IMM.IPlugin.Load

            If IMM.FnIDrawNodes.DrawNodesGet() Is Nothing Then

                Return False

            Else

                Return True

            End If

        End Function

        Public Function Unload() As Boolean Implements IMM.IPlugin.Unload

            Return True

        End Function

        Public Sub Dispose() Implements IMM.IPlugin.Dispose

        End Sub

    End Class

    ' =================================================================================================
    ' Plug-in C# methods used to connect to a PolyWorks module.
    ' -------------------------------------------------------------------------------------------------
    Public Class Connection

        Public Shared Sub SDKVersionGet(ByRef major_ As UShort, ByRef minor_ As UShort, ByRef dot_ As UShort)

            major_ = IMM.Version.SDK_VERSION_MAJOR
            minor_ = IMM.Version.SDK_VERSION_MINOR
            dot_ = IMM.Version.SDK_VERSION_DOT

        End Sub

        Public Shared Function PluginInterfaceGet() As IMM.IPlugin

            If PluginContainer.g_thePlugin Is Nothing Then

                PluginContainer.g_thePlugin = New CCompanyNameManagedPlugin()

            End If

            Return PluginContainer.g_thePlugin

        End Function

    End Class

    ' =================================================================================================
    '   Contains an instance of the C# plug-in.
    ' -------------------------------------------------------------------------------------------------
    Public Class PluginContainer

        Public Shared g_thePlugin As CCompanyNameManagedPlugin = Nothing

    End Class

End Namespace

