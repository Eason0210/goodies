// =================================================================================================
//   CDrawNodePoints class.
//
// Copyright © InnovMetric Logiciels Inc. 2010 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharp3DSceneRendering
{
    // =================================================================================================
    //   Draw node drawing 3D points in the 3D Scene. 
    //   The draw node's name and point array XY center are configurable.
    // -------------------------------------------------------------------------------------------------
    public class CDrawNodePoints : IMM.IDrawNode
    {
        // =================================================================================================
        // Constructor configuring the draw node.
        //
        // Parameter: name_   : Draw node's name
        // Parameter: center_ : X and Y coordinate for the center of the 3D points.
        // -------------------------------------------------------------------------------------------------
        public CDrawNodePoints(string name_, IMM.CPoint2D center_)
        {
            m_name = name_;

            IMM.FnIGeometry.Create(out m_pPointArray);

            // Fills the point array to draw a simple box using 3D points.
            for (float iX = -1; iX <= 1; iX += 0.5f)
            {
                for (float iY = -1; iY <= 1; iY += 0.5f)
                {
                    for (float iZ = -1; iZ <= 1; iZ += 0.5f)
                    {
                        m_pPointArray.Add(new IMM.CPoint(iX + center_[0], iY + center_[1], iZ));
                    }
                }
            }

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
            // Sets the color to draw the points
            using (IMM.CRenderColor renderColor = new IMM.CRenderColor(new IMM.CColorRGBA(244, 255, 170)))
            {
                renderer_.PointArrayDraw(m_pPointArray);
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

        private IMM.IBBox m_pBBox;
        private IMM.IPointArray m_pPointArray;
        private string m_name;
    }
}
