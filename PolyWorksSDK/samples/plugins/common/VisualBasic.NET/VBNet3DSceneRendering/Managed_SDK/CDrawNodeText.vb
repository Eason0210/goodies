' =================================================================================================
' CDrawNodeText class.
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =================================================================================================
    ' Draw node drawing 3D points in the 3D Scene. 
    ' The draw node's name and point array XY center are configurable.
    ' -------------------------------------------------------------------------------------------------
    Public Class CDrawNodeText
        Implements IMM.IDrawNode

        ' =================================================================================================
        ' Constructor configuring the draw node.
        '
        ' Parameter: name_ : Draw node's name
        ' Parameter: text_ : Text to be displayed.
        ' -------------------------------------------------------------------------------------------------
        Public Sub New(ByVal name_ As String, ByVal text_ As String)

            m_name = name_
            m_text = text_

            IMM.FnIGeometry.Create(m_pBBox)

        End Sub

        ' =================================================================================================
        ' Deallocate memory associated to the drawn geometry.
        ' -------------------------------------------------------------------------------------------------
        Public Sub Dispose() Implements IMM.IDrawNode.Dispose

            IMM.FnIGeometry.Destroy(m_pBBox)

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

            Using renderColor As New IMM.CRenderColor(New IMM.CColorRGBA(255, 255, 0))

                renderer_.Text2DDraw(New IMM.CPoint2D(30, 30), m_text)

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
        Private m_name As String
        Private m_text As String

    End Class

End Namespace
