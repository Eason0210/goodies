Public Class MainForm

    ' Main action of this application
    Private Sub ButtonStart_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ButtonStart.Click

        Dim imAlignObject As New IMAlignLib.IMAlign

        TextLog.Text = ""

        ' If the server does not exists, return
        If imAlignObject Is Nothing Then

            Exit Sub

        End If

        ' Obtain IMAlign's current project
        Dim projectObject As IMAlignLib.IIMAlignProject = Nothing
        imAlignObject.ProjectGetCurrent(projectObject)

        If projectObject Is Nothing Then

            System.Runtime.InteropServices.Marshal.ReleaseComObject(imAlignObject)
            imAlignObject = Nothing
            Exit Sub

        End If

        ' Obtain a Command Center from the current IMAlign project
        Dim commandCenterObject As IMAlignLib.IIMCommandCenter
        projectObject.CommandCenterCreate(commandCenterObject)

        ' Send commands
        Dim buffer As String

        If Not commandCenterObject Is Nothing Then

            buffer = "FILE NEW_PROJECT"
            TextLog.Text = TextLog.Text & buffer & vbCrLf
            commandCenterObject.CommandExecute(buffer)

            buffer = "CONFIG DIGITIZERS NAME ( ""Generic Close Range (in mm)"" )"
            TextLog.Text = TextLog.Text & buffer & vbCrLf
            commandCenterObject.CommandExecute(buffer)

            buffer = "FILE IMPORT_IMAGE 3D_DIGITIZED_DATASET PLANAR_GRID DIRECTORY ( """ & TextSource.Text & """, , ""PIF"" )"
            TextLog.Text = TextLog.Text & buffer & vbCrLf
            commandCenterObject.CommandExecute(buffer)

            buffer = "ALIGN START(0.000001, 10)"
            TextLog.Text = TextLog.Text & buffer & vbCrLf
            commandCenterObject.CommandExecute(buffer)

            buffer = "FILE SAVE_PROJECT_AS( """ & TextDestination.Text & "\workspace.pwk"", ""IMAlign Project"" )"
            TextLog.Text = TextLog.Text & buffer & vbCrLf
            commandCenterObject.CommandExecute(buffer)

        End If

        ' Cleanup
        System.Runtime.InteropServices.Marshal.ReleaseComObject(commandCenterObject)
        System.Runtime.InteropServices.Marshal.ReleaseComObject(projectObject)
        System.Runtime.InteropServices.Marshal.ReleaseComObject(imAlignObject)

        commandCenterObject = Nothing
        projectObject = Nothing
        imAlignObject = Nothing

    End Sub

End Class
