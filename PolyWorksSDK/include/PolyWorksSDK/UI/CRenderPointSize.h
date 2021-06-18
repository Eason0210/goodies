#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CRenderPointSize.h
///    \brief    This file contains the declaration of the class used to specify the size of the points
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
///    \brief    Class that specifies a size for points. At the destruction of the object, the previous
///              point size used by the renderer will be placed back.
///
///              To customize the size of the
///              points of the rendered geometry , you can use this CRenderPointSize rendering tool.
///              It is implemented in the form of RAII (resource acquisition is initialization).
///              This means that when you instantiate this tool, it will change the current point
///              size making all subsequent drawn objects having this point size. This size will
///              reverted back to its original value once the object is destroyed.
///
///              Example:
///              \code{.cpp}
///              void CMyDrawNode::Draw( IRenderer& renderer_ )
///              {
///                  // Draws a first point array with default size
///                  renderer_.PointArrayDraw( m_pMyFirstPointArray );
///
///                  // Draws a second point array with a size of 3.0 pixels
///                  CRenderPointSize renderSize3( 3.0f );
///                  renderer_.PointArrayDraw( m_pMySecondPointArray );
///              }
///              \endcode
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CRenderPointSize
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.  Once this object is constructed, the default renderer's point size
    ///              will be changed to the specified size. It will be reverted back to its original
    ///              state at its destruction.
    ///
    ///    \param[ in ] pointSize_    The point size that will be used to draw.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    explicit CRenderPointSize( float pointSize_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CRenderPointSize();


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // =================================================================================================
    // The copy constructor and copy operator are defined private to render the class non-copyable.
    CRenderPointSize( const CRenderPointSize& );
    CRenderPointSize& operator=( const CRenderPointSize& );

    // ---------------- Private Member Variables ---------------------------------------------------

    float m_pointSizePrevious;

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
