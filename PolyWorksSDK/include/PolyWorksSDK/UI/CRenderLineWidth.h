#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CRenderLineWidth.h
///    \brief    This file contains the declaration of the class used to specify the with of the lines
///              to be drawn.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

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
///    \brief    Class that specifies a width for lines. At the destruction of the object, the previous
///              width used by the renderer will be placed back.
///
///              To customize the width of the lines
///              of the rendered geometry, you can use this CRenderLineWidth rendering tool. It is
///              implemented in the form of RAII (resource acquisition is initialization). This means
///              that when you instantiate this tool, it will change the current line width making
///              all subsequent drawn objects having this line width. This width will reverted back
///              to its original value once the object is destroyed.
///
///              Example:
///              \code{.cpp}
///              void CMyDrawNode::Draw( IRenderer& renderer_ )
///              {
///                  // Draws a first polyline with default line width
///                  renderer_.PolylineDraw( m_pMyFirstPolyline );
///
///                  // Draws a second polyline with a line width of 3.0
///                  CRenderLineWidth renderWidth3( 3.0f );
///                  renderer_.PolylineDraw( m_pMySecondPolyline );
///              }
///              \endcode
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CRenderLineWidth
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.  Once this object is constructed, the default renderer's line width
    ///              will be changed to the specified width. It will be reverted back to its original
    ///              state at its destruction.
    ///
    ///    \param[ in ] lineWidth_    The line width that will be used to draw.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    explicit CRenderLineWidth( float lineWidth_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CRenderLineWidth();


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // =================================================================================================
    // The copy constructor and copy operator are defined private to render the class non-copyable.
    CRenderLineWidth( const CRenderLineWidth& );
    CRenderLineWidth& operator=( const CRenderLineWidth& );

    // ---------------- Private Member Variables ---------------------------------------------------
    float m_lineWidthPrevious;
};


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================


} // namespace IM
