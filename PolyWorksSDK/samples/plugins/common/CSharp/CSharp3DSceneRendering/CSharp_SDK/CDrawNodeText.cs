// =================================================================================================
//   CDrawNodeText class.
//
// Copyright © InnovMetric Logiciels Inc. 2010 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharp3DSceneRendering
{
    // =================================================================================================
    //   Draw node drawing 3D points in the 3D Scene. The draw node's name and point array XY center
    //   are configurable.
    // -------------------------------------------------------------------------------------------------
    public class CDrawNodeText : IMM.IDrawNode
    {
        // =================================================================================================
        // Constructor configuring the draw node.
        //
        // Parameter: name_ : Draw node's name
        // Parameter: text_ : Text to be displayed.
        // -------------------------------------------------------------------------------------------------
        public CDrawNodeText(string name_, string text_)
        {
            m_name = name_;
            m_text = text_;

            IMM.FnIGeometry.Create(out m_pBBox);
        }

        // =================================================================================================
        // Deallocate memory associated to the drawn geometry.
        // -------------------------------------------------------------------------------------------------
        public virtual void Dispose()
        {
            IMM.FnIGeometry.Destroy(m_pBBox);
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
            using (IMM.CRenderColor renderColor = new IMM.CRenderColor(new IMM.CColorRGBA(255, 255, 0)))
            {
                renderer_.Text2DDraw(new IMM.CPoint2D(30, 30), m_text);
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
        private string m_name;
        private string m_text;
    }
}
