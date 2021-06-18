Public Class MainForm

    ' Main action of this application
    Private Sub ButtonStart_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ButtonStart.Click

        Dim imEditObject As New IMEditLib.IMEdit

        TextLog.Text = ""

        ' If the server does not exists, return
        If imEditObject Is Nothing Then

            Exit Sub

        End If

        ' Obtain PolyWorks|Modeler's current project
        Dim projectObject As IMEditLib.IIMEditProject = Nothing
        imEditObject.ProjectGetCurrent(projectObject)

        If projectObject Is Nothing Then

            System.Runtime.InteropServices.Marshal.ReleaseComObject(imEditObject)
            imEditObject = Nothing
            Exit Sub

        End If

        ' Obtain a Command Center from the current PolyWorks|Modeler project
        Dim commandCenterObject As IMEditLib.IIMCommandCenter
        projectObject.CommandCenterCreate(commandCenterObject)

        ' Send commands
        Dim buffer As String
        Dim result As Short

        If Not commandCenterObject Is Nothing Then

            buffer = "FILE NEW_PROJECT"
            TextLog.Text = TextLog.Text & buffer & vbCrLf
            commandCenterObject.CommandExecute(buffer)

            buffer = "TREEVIEW MODEL VIEW DEFAULT_STATIC FLAT"
            TextLog.Text = TextLog.Text & buffer & vbCrLf
            commandCenterObject.CommandExecute(buffer)

            buffer = "FILE IMPORT_MODEL POLYGONAL_FILE ( """ & TextSource.Text & """ )"
            TextLog.Text = TextLog.Text & buffer & vbCrLf
            result = commandCenterObject.CommandExecute(buffer)

            ' If the previous operation was not a success, we're finished
            If commandCenterObject.ReturnValueIsSuccess(result) <> 0 Then

                buffer = "EDIT PLANE CREATE XY_PLANE"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "EDIT OBJECT INVERT_ORIENTATION"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "SELECT TRIANGLES ALL"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "EDIT TRIANGLES OFFSET NORMAL ( -1.0, ""On"", ""Off"", 180.0 )"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "SELECT TRIANGLES ALL"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "EDIT TRIANGLES SLICE_WITH_A_PLANE INSERT_INTERSECTION"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "SELECT TRIANGLES USING_PLANES BELOW"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "EDIT DELETE LAST"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "TREEVIEW OBJECT VIEW HIDE"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "VIEW POSE CENTER"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

                buffer = "EDIT TRIANGLES CREATE_WALLS ( 3.0 )"
                TextLog.Text = TextLog.Text & buffer & vbCrLf
                commandCenterObject.CommandExecute(buffer)

            End If

        End If

        ' Cleanup
        System.Runtime.InteropServices.Marshal.ReleaseComObject(commandCenterObject)
        System.Runtime.InteropServices.Marshal.ReleaseComObject(projectObject)
        System.Runtime.InteropServices.Marshal.ReleaseComObject(imEditObject)

        commandCenterObject = Nothing
        projectObject = Nothing
        imEditObject = Nothing

    End Sub

End Class
