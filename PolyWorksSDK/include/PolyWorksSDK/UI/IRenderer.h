#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IRenderer.h
///    \brief    IRenderer class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CWString.h>

namespace IM { class CPoint2D; }
namespace IM { class IPointArray; }
namespace IM { class IPolyline2D; }
namespace IM { class IPolyline; }
namespace IM { class ITriangleArray; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_INTERFACES
///
///    \brief    Class used by a plug-in to render geometries defined by the PolyWorks SDK. This interface
///              provides an abstraction over our internal rendering technology. To make your rendering
///              routine effective, you will need to create a derived class from IDrawNode and then
///              this class into the draw nodes manager IDrawNodes. When the application
///              asks for a refresh, it will pass a pointer to the renderer to the IDrawNode::Draw
///              method.
///
///              To customize your rendering, you can use our rendering tools; CRenderColor
///              for example. These tools are implemented in the form of RAII (resource acquisition
///              is initialisation). This means that when you instanciate a tool, for instance CRenderColor,
///              it will push it's color state on a stack making all subsequent drawn objects having
///              this color. This color will pop the minute the CRenderColor object is destroyed.
///
///              Example:
///              \code{.cpp}
///              void CMyDrawNode::Draw( IM::IRenderer& renderer_ )
///              {
///                  // Draws a first point array in red
///                  CRenderColor renderInRed( renderer_, CColorRGBA( 255, 0, 0 ) );
///                  pRenderer_->PointArrayDraw( m_pMyFirstPointArray );
///
///                  // Draws a second point array in blue
///                  CRenderColor renderInBlue( renderer_, CColorRGBA( 0, 0, 255 ) );
///                  pRenderer_->PointArrayDraw( m_pMySecondPointArray );
///              }
///              \endcode
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IRenderer
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IRenderer() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IRenderer() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Draws the input 3D point array into the 3D Scene associated to this renderer. As
    ///              this method does not take any normal to points, there will be no shading when drawing
    ///              them.
    ///
    ///    \param[ in ] pPointArray_    Point array to be drawn
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void PointArrayDraw( const IPointArray* pPointArray_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Draws the input 3D polyline into the 3D Scene associated to this renderer.
    ///
    ///    \param[ in ] pPolyline_    Polyline to be drawn
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void PolylineDraw( const IPolyline* pPolyline_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Draws the input 2D polyline into the 2D Scene associated to this renderer.  The given
    ///              polyline's coordinates are directly mapped into pixel values so that the ( 0, 0
    ///              ) coordinate correspond to the center of the pixel located in the lower-left corner.
    ///
    ///
    ///    \param[ in ] pPolyline2D_    Polyline to be drawn
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void Polyline2DDraw( const IPolyline2D* pPolyline2D_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Draws the input text at the specified location into the 2D Scene associated to this renderer.
    ///
    ///              If a font color was specified using the CRenderColor rendering tool, the text will be drawn
    ///              using this color. If no color was specified, the text will have a contrasting color with
    ///              respect to the scene's background.
    ///
    ///              Even if CPoint2D accepts floating-point values, the values of the coordinates should be
    ///              exact integers in order to obtain a crisp rendering of the text.
    ///
    ///    \param[ in ] point2D_    The lower-left corner for the text. Units are in pixels and
    ///                             the origin is located to the lower left corner of the 3D Scene.
    ///    \param[ in ] text_       The text to be drawn at the given location.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void Text2DDraw( const CPoint2D& point2D_, const CWString& text_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Draws the input 3D triangle array into the 3D Scene associated to this renderer.
    ///              Lighting in the scene will be done according to the triangle's normal.
    ///
    ///    \param[ in ] pTriangleArray_    Array of triangles to be drawn.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void TriangleArrayDraw( const ITriangleArray* pTriangleArray_ ) = 0;

protected:
    // ---------------- Protected methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
