// =================================================================================================
//   CDrawNodePolyline2D class.
//
// Copyright © InnovMetric Logiciels Inc. 2010 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharp3DSceneRendering
{
    // =================================================================================================
    //   Draw node drawing a 2D border around the 3D Scene. The draw node's name and border distance
    //   from the 3D Scene's limits are configurable.
    // -------------------------------------------------------------------------------------------------
    public class CDrawNodePolyline2D : IMM.IDrawNode
    {
        // =================================================================================================
        // Constructor configuring the draw node.
        //
        // Parameter: name_           : Draw node's name
        // Parameter: borderDistance_ : Distance from the 3D Scene limit from which to draw a 2D polyline.
        // -------------------------------------------------------------------------------------------------
        public CDrawNodePolyline2D(string name_, double borderDistance_)
        {
            m_name = name_;
            m_borderDistance = borderDistance_;

            IMM.FnIGeometry.Create(out m_pPolyline2D);
            m_pPolyline2D.ClosedSet(true);
            IMM.FnIGeometry.Create(out m_pBBox);
        }
        // =================================================================================================
        // Deallocate memory associated to the drawn geometry.
        // -------------------------------------------------------------------------------------------------
        public virtual void Dispose()
        {

            IMM.FnIGeometry.Destroy(m_pBBox);
            IMM.FnIGeometry.Destroy(m_pPolyline2D);
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
        // Draws a 2D polyline inside the outer border of the 3D Scene.
        //
        // Parameter: renderer_ : Reference to the rendering engine.
        // -------------------------------------------------------------------------------------------------
        public virtual void Draw(IMM.IRenderer renderer_)
        {
            uint currentWidth = 0;
            uint currentHeight = 0;
            IMM.FnIScene.SceneGet().SizeGet(ref currentWidth, ref currentHeight);

            // Recalculates where to draw a border using 2D polyline only if the 3D Scene size has changed
            if (currentWidth != m_sceneWidth || currentHeight != m_sceneHeight)
            {
                m_sceneWidth = currentWidth;
                m_sceneHeight = currentHeight;

                double x1 = m_borderDistance;
                double x2 = (double)m_sceneWidth - m_borderDistance;
                double y1 = m_borderDistance;
                double y2 = (double)m_sceneHeight - m_borderDistance;

                m_pPolyline2D.Clear();
                m_pPolyline2D.InsertBack(new IMM.CPoint2D(x1, y1));
                m_pPolyline2D.InsertBack(new IMM.CPoint2D(x2, y1));
                m_pPolyline2D.InsertBack(new IMM.CPoint2D(x2, y2));
                m_pPolyline2D.InsertBack(new IMM.CPoint2D(x1, y2));
            }

            // Change the line width and color before drawing a 2D polyline
            using (IMM.CRenderLineWidth renderLineWidth = new IMM.CRenderLineWidth(1))
            {
                using (IMM.CRenderColor renderColor = new IMM.CRenderColor(new IMM.CColorRGBA(90, 187, 49)))
                {
                    renderer_.Polyline2DDraw(m_pPolyline2D);
                }
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
        private IMM.IPolyline2D m_pPolyline2D;
        private uint m_sceneWidth;
        private uint m_sceneHeight;
        private double m_borderDistance;
        private string m_name;
    }
}
