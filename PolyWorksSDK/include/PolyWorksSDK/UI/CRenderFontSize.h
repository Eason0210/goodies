#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CRenderFontSize.h
///    \brief    This file contains the declaration of the class used to specify the size of the text
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
///    \brief    Class that specifies a font size for text. At the destruction of the  object, the
///              previous font size used by the renderer will be placed back.
///
///              To customize the size of the font of the rendered text, you can use this CRenderFontSize rendering tool.
///              It is implemented in the form of RAII (resource acquisition is initialization).
///              This means that when you instantiate this tool, it will change the current font
///              size making all subsequent drawn text having this font size. This size will reverted
///              back to its original value once the object is destroyed.
///
///              Example:
///              \code{.cpp}
///              void CMyDrawNode::Draw( IRenderer& renderer_ )
///              {
///                  // Draws a first text with default font size
///                  renderer_.TextDraw( m_pMyFirstText );
///
///                  // Draws a second text with a font size of 12 pixels
///                  CRenderFontSize renderSize12( 12 );
///                  renderer_.TextDraw( m_pMySecondText );
///              }
///              \endcode
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CRenderFontSize
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.  Once this object is constructed, the default renderer's font size will
    ///              be changed to the specified size. It will be reverted back to its original state
    ///              at its destruction.
    ///
    ///    \param[ in ] fontSize_    The point size that will be used to draw.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    explicit CRenderFontSize( unsigned int fontSize_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CRenderFontSize();


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
    CRenderFontSize( const CRenderFontSize& );
    CRenderFontSize& operator=( const CRenderFontSize& );

    // ---------------- Private Member Variables ---------------------------------------------------

    unsigned int m_fontSizePrevious;

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
