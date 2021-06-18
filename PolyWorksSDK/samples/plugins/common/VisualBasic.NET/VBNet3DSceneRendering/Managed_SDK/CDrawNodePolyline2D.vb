' =================================================================================================
' CDrawNodePolyline2D class.
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =================================================================================================
    ' Draw node drawing a 2D border around the 3D Scene.
    ' The draw node's name and border distance from the 3D Scene's limits are configurable.
    ' -------------------------------------------------------------------------------------------------
    Public Class CDrawNodePolyline2D
        Implements IMM.IDrawNode

        ' =================================================================================================
        ' Constructor configuring the draw node.
        '
        ' Parameter: name_           : Draw node's name
        ' Parameter: borderDistance_ : Distance from the 3D Scene limit from which to draw a 2D polyline.
        ' -------------------------------------------------------------------------------------------------
        Public Sub New(ByVal name_ As String, ByVal borderDistance_ As Double)

            m_name = name_
            m_borderDistance = borderDistance_

            IMM.FnIGeometry.Create(m_pPolyline2D)
            m_pPolyline2D.ClosedSet(True)
            IMM.FnIGeometry.Create(m_pBBox)

        End Sub

        ' =================================================================================================
        ' Deallocate memory associated to the drawn geometry.
        ' -------------------------------------------------------------------------------------------------
        Public Sub Dispose() Implements IMM.IDrawNode.Dispose

            IMM.FnIGeometry.Destroy(m_pBBox)
            IMM.FnIGeometry.Destroy(m_pPolyline2D)

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
        ' Draws a 2D polyline inside the outer border of the 3D Scene.
        '
        ' Parameter: renderer_ : Reference to the rendering engine.
        ' -------------------------------------------------------------------------------------------------
        Public Sub Draw(ByVal renderer_ As IMM.IRenderer) Implements IMM.IDrawNode.Draw

            Dim currentWidth As UInteger = 0
            Dim currentHeight As UInteger = 0
            IMM.FnIScene.SceneGet().SizeGet(currentWidth, currentHeight)

            ' Recalculates where to draw a border using 2D polyline only if the 3D Scene size has changed
            If currentWidth <> m_sceneWidth Or currentHeight <> m_sceneHeight Then

                m_sceneWidth = currentWidth
                m_sceneHeight = currentHeight

                Dim x1 As Double = m_borderDistance
                Dim x2 As Double = m_sceneWidth - m_borderDistance
                Dim y1 As Double = m_borderDistance
                Dim y2 As Double = m_sceneHeight - m_borderDistance

                m_pPolyline2D.Clear()
                m_pPolyline2D.InsertBack(New IMM.CPoint2D(x1, y1))
                m_pPolyline2D.InsertBack(New IMM.CPoint2D(x2, y1))
                m_pPolyline2D.InsertBack(New IMM.CPoint2D(x2, y2))
                m_pPolyline2D.InsertBack(New IMM.CPoint2D(x1, y2))

            End If

            ' Change the line width and color before drawing a 2D polyline
            Using renderLineWidth As New IMM.CRenderLineWidth(1)

                Using renderColor As New IMM.CRenderColor(New IMM.CColorRGBA(90, 187, 49))

                    renderer_.Polyline2DDraw(m_pPolyline2D)

                End Using

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
        Private m_pPolyline2D As IMM.IPolyline2D = Nothing
        Private m_sceneWidth As UInteger
        Private m_sceneHeight As UInteger
        Private m_borderDistance As Double
        Private m_name As String

    End Class

End Namespace
