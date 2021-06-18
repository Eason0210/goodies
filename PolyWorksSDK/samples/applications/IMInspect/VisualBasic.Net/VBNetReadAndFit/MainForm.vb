Public Class MainForm

    ' Global access to a PolyWorks|Inspector
    Private imInspectObject As IMInspectLib.IMInspect = Nothing

    ' Upon loading the Form
    Private Sub MainForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        imInspectObject = New IMInspectLib.IMInspect

    End Sub

    ' Cleanup upon destruction of the form
    Private Sub MainForm_FormClosed(ByVal sender As System.Object, ByVal e As System.Windows.Forms.FormClosedEventArgs) Handles MyBase.FormClosed

        System.Runtime.InteropServices.Marshal.ReleaseComObject(imInspectObject)
        imInspectObject = Nothing

    End Sub

    ' Main action of this application
    Private Sub ButtonSend_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ButtonSend.Click

        LabelResult.Text = ""

        ' If the server does not exists, return
        If imInspectObject Is Nothing Then

            Exit Sub

        End If

        ' Obtain PolyWorks|Inspector's current project
        Dim projectObject As IMInspectLib.IIMInspectProject = Nothing
        imInspectObject.ProjectGetCurrent(projectObject)

        If projectObject Is Nothing Then

            Exit Sub

        End If

        ' Read the file and fill the coordinates and normals lists
        Dim coordinates As System.Collections.Generic.List(Of Single) = New System.Collections.Generic.List(Of Single)()
        Dim normals As System.Collections.Generic.List(Of Single) = New System.Collections.Generic.List(Of Single)()
        Dim colors As System.Collections.Generic.List(Of Byte) = New System.Collections.Generic.List(Of Byte)()

        If FillArraysFromFile((TextFileName.Text), coordinates, normals) = False Then

            Exit Sub

        End If


        ' Set all points to a blue color
        Dim index As Integer
        index = 0

        While index < coordinates.Count

            colors.Add(32)
            colors.Add(32)
            colors.Add(224)
            index += 3

        End While

        ' Obtain the name of the file, without the path
        Dim tokens As String() = TextFileName.Text.Split(New [Char]() {"\"c})
        Dim objectName As String = tokens(tokens.Length - 1)

        ' Create a point cloud in the current PolyWorks|Inspector project
        Dim pointCloudObject As IMInspectLib.IIMPointCloud
        projectObject.PointCloudCreateData(pointCloudObject, objectName, 0)

        ' Send the points to the point cloud
        If Not pointCloudObject Is Nothing Then

            pointCloudObject.PointsAdd(coordinates.ToArray(), normals.ToArray(), colors.ToArray())

        End If

        ' Obtain a Command Center from the current PolyWorks|Inspector project
        Dim commandCenterObject As IMInspectLib.IIMCommandCenter
        projectObject.CommandCenterCreate(commandCenterObject)

        ' Send commands to fit a sphere on all the elements of this new object
        Dim returnValue As Integer
        Dim script As String
        Dim sphereName As String

        If Not commandCenterObject Is Nothing Then

            commandCenterObject.CommandExecute("TREEVIEW OBJECT SELECT NONE")
            commandCenterObject.CommandExecute("TREEVIEW OBJECT_ELEMENTS SELECT ALL ( """ & objectName & """ )")

            ' Perform the fit and obtain the fitted sphere's name
            script = "version ""5.0""" & vbCrLf &
                         "DECLARE nbSpheres" & vbCrLf &
                         "DECLARE lastSphereName" & vbCrLf &
                         "MACRO END_ON_ERROR ( ""On"" )" & vbCrLf &
                         "FEATURE PRIMITIVE SPHERE FIT_SELECTED_ELEMENTS" & vbCrLf &
                         "TREEVIEW PRIMITIVE SPHERE COUNT GET( nbSpheres )" & vbCrLf &
                         "TREEVIEW PRIMITIVE SPHERE NAME GET( $nbSpheres, lastSphereName )" & vbCrLf

            returnValue = commandCenterObject.ScriptExecuteFromBuffer(script, "")

            If commandCenterObject.ReturnValueIsSuccess(returnValue) = 1 Then

                returnValue = commandCenterObject.ScriptVariableGetValueAsString("lastSphereName", 1, sphereName)

                If commandCenterObject.ReturnValueIsSuccess(returnValue) = 1 Then

                    LabelResult.Text = "Sphere """ & sphereName & """ was successfully fitted"

                End If

            End If

            If commandCenterObject.ReturnValueIsSuccess(returnValue) = 0 Then

                LabelResult.Text = "The fitting was unsuccessful"

            End If

        End If

        ' Cleanup
        System.Runtime.InteropServices.Marshal.ReleaseComObject(pointCloudObject)
        System.Runtime.InteropServices.Marshal.ReleaseComObject(commandCenterObject)
        System.Runtime.InteropServices.Marshal.ReleaseComObject(projectObject)

        pointCloudObject = Nothing
        commandCenterObject = Nothing
        projectObject = Nothing

    End Sub

    ' Reads an ASCII file containing lines made of 6 values (X,Y,Z,I,J,K)
    ' and fills a coordinates and a normals arrays with those values
    Private Function FillArraysFromFile( _
        ByRef filename_ As String, _
        ByRef coordinates_ As System.Collections.Generic.List(Of Single), _
        ByRef normals_ As System.Collections.Generic.List(Of Single)) As Boolean

        ' Validate file name
        If Not System.IO.File.Exists(filename_) Then

            Return False

        End If

        ' Open the file for reading
        Dim reader As New System.IO.StreamReader(filename_)
        Dim line As String
        Dim success As Boolean

        ' Read the first six tokens (X,Y,Z,I,J,K) on each line of the file
        ' and convert them to double-precision floating point values
        success = True
        line = reader.ReadLine()

        While Not line Is Nothing

            Dim tokens As String() = line.Split(New [Char]() {" "c})

            If tokens.Length < 6 Then

                success = False
                Exit While

            End If

            ' Recording coordinates
            coordinates_.Add(Convert.ToSingle(tokens(0)))
            coordinates_.Add(Convert.ToSingle(tokens(1)))
            coordinates_.Add(Convert.ToSingle(tokens(2)))

            ' Recording normals
            normals_.Add(Convert.ToSingle(tokens(3)))
            normals_.Add(Convert.ToSingle(tokens(4)))
            normals_.Add(Convert.ToSingle(tokens(5)))

            line = reader.ReadLine()

        End While

        reader.Close()

        Return success

    End Function

End Class
