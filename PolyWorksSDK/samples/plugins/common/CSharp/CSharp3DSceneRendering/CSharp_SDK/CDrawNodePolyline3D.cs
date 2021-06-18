// =================================================================================================
//   CDrawNodePolyline3D class.
//
// Copyright © InnovMetric Logiciels Inc. 2010 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharp3DSceneRendering
{
    // =================================================================================================
    //   Draw node drawing a 3D polyline in the 3D Scene. The draw node's name and polyline XY center
    //   are configurable.
    // -------------------------------------------------------------------------------------------------
    public class CDrawNodePolyline3D : IMM.IDrawNode
    {
        // =================================================================================================
        // Constructor configuring the draw node.
        //
        // Parameter: name_   : Draw node's name
        // Parameter: center_ : X and Y coordinate for the center of the 3D polyline.
        // -------------------------------------------------------------------------------------------------
        public CDrawNodePolyline3D(string name_, IMM.CPoint2D center_)
        {
            m_name = name_;

            IMM.FnIGeometry.Create(out m_pPolyline3D);

            // Defines a 3D polyline using a spring shape
            double angle = 0.0;
            for (double r = 0.0; r <= 1.0; r += 0.005)
            {
                double x = (double)(System.Math.Cos(angle) * r) + center_[0];
                double y = (double)(System.Math.Sin(angle) * r) + center_[1];
                m_pPolyline3D.InsertBack(new IMM.CPoint(x, y, r));
                angle += 0.1;
            }

            angle = 0.0;
            for (double r = 0.0; r > -1.0; r -= 0.005)
            {
                double x = (double)(System.Math.Cos(angle) * r) + center_[0];
                double y = (double)(System.Math.Sin(angle) * r) + center_[1];
                m_pPolyline3D.InsertAt(0, new IMM.CPoint(x, y, r));
                angle += 0.1;
            }

            IMM.FnIGeometry.Create(out m_pBBox);
            IMM.FnIBBox.Insert(m_pBBox, m_pPolyline3D);
        }

        // =================================================================================================
        // Deallocate memory associated to the drawn geometry.
        // -------------------------------------------------------------------------------------------------
        public virtual void Dispose()
        {
            IMM.FnIGeometry.Destroy(m_pBBox);
            IMM.FnIGeometry.Destroy(m_pPolyline3D);
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
        // Draws a 3D polyline in the 3D Scene.
        //
        // Parameter: renderer_ : Reference to the rendering engine.
        // -------------------------------------------------------------------------------------------------
        public virtual void Draw(IMM.IRenderer renderer_)
        {
            // Change the color and draw a 3D polyline
            using (IMM.CRenderColor renderColor = new IMM.CRenderColor(new IMM.CColorRGBA(90, 187, 49)))
            {
                renderer_.PolylineDraw(m_pPolyline3D);
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
        IMM.IPolyline m_pPolyline3D;
        string m_name;
    }
}
