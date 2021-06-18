' =================================================================================================
' CDrawNodeTriangles class.
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =================================================================================================
    ' Draw node drawing triangles in the 3D Scene. 
    ' The draw node's name and triangle array XY center are configurable.
    ' -------------------------------------------------------------------------------------------------
    Public Class CDrawNodeTriangles
        Implements IMM.IDrawNode

        ' =================================================================================================
        ' Constructor configuring the draw node.
        '
        ' Parameter: name_   : Draw node's name
        ' Parameter: center_ : X and Y coordinate for the center of the 3D points.
        ' -------------------------------------------------------------------------------------------------
        Public Sub New(ByVal name_ As String, ByVal center_ As IMM.CPoint2D)

            m_name = name_

            IMM.FnIGeometry.Create(m_pPointArray)

            ' Sets the points for the triangles
            ' Top
            m_pPointArray.Add(New IMM.CPoint(-0.5 + center_(0), -0.5 + center_(1), -1.0))
            m_pPointArray.Add(New IMM.CPoint(0.5 + center_(0), -0.5 + center_(1), -1.0))
            m_pPointArray.Add(New IMM.CPoint(0.5 + center_(0), 0.5 + center_(1), -1.0))
            m_pPointArray.Add(New IMM.CPoint(-0.5 + center_(0), 0.5 + center_(1), -1.0))

            ' Centre point
            m_pPointArray.Add(New IMM.CPoint(0.0 + center_(0), 0.0 + center_(1), 0.0))

            ' Top
            m_pPointArray.Add(New IMM.CPoint(-0.5 + center_(0), -0.5 + center_(1), 1.0))
            m_pPointArray.Add(New IMM.CPoint(0.5 + center_(0), -0.5 + center_(1), 1.0))
            m_pPointArray.Add(New IMM.CPoint(0.5 + center_(0), 0.5 + center_(1), 1.0))
            m_pPointArray.Add(New IMM.CPoint(-0.5 + center_(0), 0.5 + center_(1), 1.0))

            ' Links together points using their ID in m_pPointArray to define triangles
            IMM.FnIGeometry.Create(m_pTriangleArray, m_pPointArray)
            m_pTriangleArray.Add(New IMM.CTriangle(0, 1, 2))
            m_pTriangleArray.Add(New IMM.CTriangle(2, 3, 0))
            m_pTriangleArray.Add(New IMM.CTriangle(1, 4, 2))
            m_pTriangleArray.Add(New IMM.CTriangle(2, 4, 3))
            m_pTriangleArray.Add(New IMM.CTriangle(3, 4, 0))
            m_pTriangleArray.Add(New IMM.CTriangle(0, 4, 1))
            m_pTriangleArray.Add(New IMM.CTriangle(6, 5, 8))
            m_pTriangleArray.Add(New IMM.CTriangle(8, 7, 6))
            m_pTriangleArray.Add(New IMM.CTriangle(6, 4, 5))
            m_pTriangleArray.Add(New IMM.CTriangle(7, 4, 6))
            m_pTriangleArray.Add(New IMM.CTriangle(8, 4, 7))
            m_pTriangleArray.Add(New IMM.CTriangle(5, 4, 8))

            IMM.FnIGeometry.Create(m_pBBox)
            IMM.FnIBBox.Insert(m_pBBox, m_pPointArray)

        End Sub

        ' =================================================================================================
        ' Deallocate memory associated to the drawn geometry.
        ' -------------------------------------------------------------------------------------------------
        Public Sub Dispose() Implements IMM.IDrawNode.Dispose

            IMM.FnIGeometry.Destroy(m_pBBox)
            IMM.FnIGeometry.Destroy(m_pPointArray)
            IMM.FnIGeometry.Destroy(m_pTriangleArray)

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
        ' Draws 3D points in the 3D Scene.
        '
        ' Parameter: renderer_ : Reference to the rendering engine.
        ' -------------------------------------------------------------------------------------------------
        Public Sub Draw(ByVal renderer_ As IMM.IRenderer) Implements IMM.IDrawNode.Draw

            ' Change the color and draw the triangle array
            Using renderColor As New IMM.CRenderColor(New IMM.CColorRGBA(64, 203, 255))

                renderer_.TriangleArrayDraw(m_pTriangleArray)

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
        Private m_pTriangleArray As IMM.ITriangleArray = Nothing
        Private m_pPointArray As IMM.IPointArray = Nothing
        Private m_name As String

    End Class

End Namespace
