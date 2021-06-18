// =================================================================================================
//   CDrawNodeTriangles class.
//
// Copyright © InnovMetric Logiciels Inc. 2010 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharp3DSceneRendering
{
    // =================================================================================================
    //   Draw node drawing triangles in the 3D Scene. The draw node's name and triangle array XY center
    //   are configurable.
    // -------------------------------------------------------------------------------------------------
    public class CDrawNodeTriangles : IMM.IDrawNode
    {
        // =================================================================================================
        // Constructor configuring the draw node.
        //
        // Parameter: name_   : Draw node's name
        // Parameter: center_ : X and Y coordinate for the center of the 3D points.
        // -------------------------------------------------------------------------------------------------
        public CDrawNodeTriangles(string name_, IMM.CPoint2D center_)
        {
            m_name = name_;

            IMM.FnIGeometry.Create(out m_pPointArray);

            // Sets the points for the triangles
            // Top
            m_pPointArray.Add(new IMM.CPoint(-0.5 + center_[0], -0.5 + center_[1], -1.0));
            m_pPointArray.Add(new IMM.CPoint(0.5 + center_[0], -0.5 + center_[1], -1.0));
            m_pPointArray.Add(new IMM.CPoint(0.5 + center_[0], 0.5 + center_[1], -1.0));
            m_pPointArray.Add(new IMM.CPoint(-0.5 + center_[0], 0.5 + center_[1], -1.0));

            // Centre point
            m_pPointArray.Add(new IMM.CPoint(0.0 + center_[0], 0.0 + center_[1], 0.0));

            // Top
            m_pPointArray.Add(new IMM.CPoint(-0.5 + center_[0], -0.5 + center_[1], 1.0));
            m_pPointArray.Add(new IMM.CPoint(0.5 + center_[0], -0.5 + center_[1], 1.0));
            m_pPointArray.Add(new IMM.CPoint(0.5 + center_[0], 0.5 + center_[1], 1.0));
            m_pPointArray.Add(new IMM.CPoint(-0.5 + center_[0], 0.5 + center_[1], 1.0));

            // Links together points using their ID in m_pPointArray to define triangles
            IMM.FnIGeometry.Create( out m_pTriangleArray, m_pPointArray);
            m_pTriangleArray.Add(new IMM.CTriangle(0, 1, 2));
            m_pTriangleArray.Add(new IMM.CTriangle(2, 3, 0));
            m_pTriangleArray.Add(new IMM.CTriangle(1, 4, 2));
            m_pTriangleArray.Add(new IMM.CTriangle(2, 4, 3));
            m_pTriangleArray.Add(new IMM.CTriangle(3, 4, 0));
            m_pTriangleArray.Add(new IMM.CTriangle(0, 4, 1));
            m_pTriangleArray.Add(new IMM.CTriangle(6, 5, 8));
            m_pTriangleArray.Add(new IMM.CTriangle(8, 7, 6));
            m_pTriangleArray.Add(new IMM.CTriangle(6, 4, 5));
            m_pTriangleArray.Add(new IMM.CTriangle(7, 4, 6));
            m_pTriangleArray.Add(new IMM.CTriangle(8, 4, 7));
            m_pTriangleArray.Add(new IMM.CTriangle(5, 4, 8));

            IMM.FnIGeometry.Create(out m_pBBox);
            IMM.FnIBBox.Insert(m_pBBox, m_pPointArray);
        }

        // =================================================================================================
        // Deallocate memory associated to the drawn geometry.
        // -------------------------------------------------------------------------------------------------
        public virtual void Dispose()
        {
            IMM.FnIGeometry.Destroy(m_pBBox);
            IMM.FnIGeometry.Destroy(m_pPointArray);
            IMM.FnIGeometry.Destroy(m_pTriangleArray);
        }

        // =================================================================================================
        // Returns the bounding box for this draw node.
        //
        // Return: Bounding box (not used because we draw in 2D)
        // -------------------------------------------------------------------------------------------------
        public virtual IMM.IBBox BBoxGet()
        {
            return m_pBBox;
        }

        // =================================================================================================
        // Draws 3D points in the 3D Scene.
        //
        // Parameter: renderer_ : Reference to the rendering engine.
        // -------------------------------------------------------------------------------------------------
        public virtual void Draw(IMM.IRenderer renderer_)
        {
            // Change the color and draw the triangle array
            using (IMM.CRenderColor renderColor = new IMM.CRenderColor(new IMM.CColorRGBA(64, 203, 255)))
            {
                renderer_.TriangleArrayDraw(m_pTriangleArray);
            }
        }

        // =================================================================================================
        // Return the draw node's name
        //
        // Return: Draw node's name
        // -------------------------------------------------------------------------------------------------
        public virtual string NameGet()
        {
            return m_name;
        }

        IMM.IBBox m_pBBox;
        IMM.ITriangleArray m_pTriangleArray;
        IMM.IPointArray m_pPointArray;
        string m_name;
    }
}
