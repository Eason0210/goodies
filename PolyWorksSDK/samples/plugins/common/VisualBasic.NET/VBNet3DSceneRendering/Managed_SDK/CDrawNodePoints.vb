' =================================================================================================
' CDrawNodePoints class.
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =================================================================================================
    ' Draw node drawing 3D points in the 3D Scene
    ' The draw node's name and point array XY center are configurable
    ' -------------------------------------------------------------------------------------------------
    Public Class CDrawNodePoints
        Implements IMM.IDrawNode

        ' =================================================================================================
        ' Constructor configuring the draw node
        '
        ' Parameter: name_   : Draw node's name
        ' Parameter: center_ : X and Y coordinate for the center of the 3D points
        ' -------------------------------------------------------------------------------------------------
        Public Sub New(ByVal name_ As String, ByVal center_ As IMM.CPoint2D)

            m_name = name_

            IMM.FnIGeometry.Create(m_pPointArray)

            ' Fills the point array to draw a simple box using 3D points.
            For iX As Single = -1 To 1 Step 0.5F
                For iY As Single = -1 To 1 Step 0.5F
                    For iZ As Single = -1 To 1 Step 0.5F
                        m_pPointArray.Add(New IMM.CPoint(iX + center_(0), iY + center_(1), iZ))
                    Next iZ
                Next iY
            Next iX

            IMM.FnIGeometry.Create(m_pBBox)
            IMM.FnIBBox.Insert(m_pBBox, m_pPointArray)

        End Sub

        ' =================================================================================================
        ' Deallocate memory associated to the drawn geometry.
        ' -------------------------------------------------------------------------------------------------
        Public Sub Dispose() Implements IMM.IDrawNode.Dispose

            IMM.FnIGeometry.Destroy(m_pBBox)
            IMM.FnIGeometry.Destroy(m_pPointArray)

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

            ' Sets the color to draw the points
            Using renderColor As New IMM.CRenderColor(New IMM.CColorRGBA(244, 255, 170))

                renderer_.PointArrayDraw(m_pPointArray)

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
        Private m_pPointArray As IMM.IPointArray = Nothing
        Private m_name As String

    End Class

End Namespace
