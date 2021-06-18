#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CRenderColor.h
///    \brief    This file contains the declaration of the class used to specify the rendering color
///              for points, lines and triangles.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CColorRGBA.h>
#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

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
///    \ingroup  IM_CLASSES
///
///    \brief    Class that specifies a rendering color for points, lines and triangles. At the destruction
///              of the object, the previous color used by the IRenderer will be placed back.
///
///              To customize the color in which the geometry will be rendered, you can use this CRenderColor
///              rendering tool. It is implemented in the form of RAII (resource acquisition is initialization).
///              This means that when you instantiate this tool, it will change the renderer's color
///              making all subsequent drawn objects having this color. This color will reverted
///              back to its original value once the object is destroyed.
///
///              Example:
///              \code{.cpp}
///              void CMyDrawNode::Draw( IRenderer& renderer_ )
///              {
///                  // Draws a first point array in red
///                  CRenderColor renderInRed( CColorRGBA( 255, 0, 0 ) );
///                  renderer_.PointArrayDraw( m_pMyFirstPointArray );
///
///                  // Draws a second point array in blue
///                  CRenderColor renderInBlue( CColorRGBA( 0, 0, 255 ) );
///                  renderer_.PointArrayDraw( m_pMySecondPointArray );
///              }
///              \endcode
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CRenderColor
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.  Once this object is constructed, the drawing color of the default IRenderer
    ///              will be changed to the specified color. It will be reverted back to its original
    ///              state at its destruction.
    ///
    ///    \param[ in ] color_    The color that will be used to draw.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    explicit CRenderColor( const CColorRGBA& color_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CRenderColor();


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    The copy constructor and copy operator are defined private to render the class non-copyable.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CRenderColor( const CRenderColor& );
    CRenderColor& operator=( const CRenderColor& );

    // ---------------- Private Member Variables ---------------------------------------------------

    CColorRGBA m_colorPrevious;
    bool       m_defaultPrevious;

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
