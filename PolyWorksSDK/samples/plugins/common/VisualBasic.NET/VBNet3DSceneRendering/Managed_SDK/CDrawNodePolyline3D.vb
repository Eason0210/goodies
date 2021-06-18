' =================================================================================================
' CDrawNodePolyline3D class.
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =================================================================================================
    ' Draw node drawing a 3D polyline in the 3D Scene. 
    ' The draw node's name and polyline XY center are configurable.
    ' -------------------------------------------------------------------------------------------------
    Public Class CDrawNodePolyline3D
        Implements IMM.IDrawNode

        ' =================================================================================================
        ' Constructor configuring the draw node.
        '
        ' Parameter: name_   : Draw node's name
        ' Parameter: center_ : X and Y coordinate for the center of the 3D polyline.
        ' -------------------------------------------------------------------------------------------------
        Public Sub New(ByVal name_ As String, ByVal center_ As IMM.CPoint2D)

            m_name = name_

            IMM.FnIGeometry.Create(m_pPolyline3D)

            ' Defines a 3D polyline using a spring shape
            Dim angle As Double = 0.0
            For r As Double = 0.0 To 1.0 Step 0.005

                Dim x As Double = (System.Math.Cos(angle) * r) + center_(0)
                Dim y As Double = (System.Math.Sin(angle) * r) + center_(1)
                m_pPolyline3D.InsertBack(New IMM.CPoint(x, y, r))
                angle += 0.1

            Next r

            angle = 0.0
            For r As Double = 0.0 To -1.0 Step -0.005

                Dim x As Double = (System.Math.Cos(angle) * r) + center_(0)
                Dim y As Double = (System.Math.Sin(angle) * r) + center_(1)
                m_pPolyline3D.InsertBack(New IMM.CPoint(x, y, r))
                angle += 0.1

            Next r

            IMM.FnIGeometry.Create(m_pBBox)
            IMM.FnIBBox.Insert(m_pBBox, m_pPolyline3D)

        End Sub

        ' =================================================================================================
        ' Deallocate memory associated to the drawn geometry.
        ' -------------------------------------------------------------------------------------------------
        Public Sub Dispose() Implements IMM.IDrawNode.Dispose

            IMM.FnIGeometry.Destroy(m_pBBox)
            IMM.FnIGeometry.Destroy(m_pPolyline3D)

        End Sub

        ' =================================================================================================
        ' Returns the bounding box for this draw node.
        '
        ' Return: Bounding box (not used because we draw in 2D)
        ' -------------------------------------------------------------------------------------------------
        Public Function BBoxGet() As IMM.IBBox Implements IMM.IDrawNode.BBoxGet

            Return m_pBBox

        End Function

        ' =================================================================================================
        ' Draws a 3D polyline in the 3D Scene.
        '
        ' Parameter: renderer_ : Reference to the rendering engine.
        ' -------------------------------------------------------------------------------------------------
        Public Sub Draw(ByVal renderer_ As IMM.IRenderer) Implements IMM.IDrawNode.Draw

            ' Sets the color to draw the points
            Using renderColor As New IMM.CRenderColor(New IMM.CColorRGBA(90, 187, 49))

                renderer_.PolylineDraw(m_pPolyline3D)

            End Using

        End Sub

        ' =================================================================================================
        ' Return the draw node's name
        '
        ' Return: Draw node's name
        ' -------------------------------------------------------------------------------------------------
        Public Function NameGet() As String Implements IMM.IDrawNode.NameGet

            Return m_name

        End Function

        Private m_pBBox As IMM.IBBox = Nothing
        Private m_pPolyline3D As IMM.IPolyline = Nothing
        Private m_name As String

    End Class

End Namespace