#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IAnnotation.h
///    \brief    This file contains the interface for the annotation object.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 Tous droits réservés All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CWString.h>
#include "PolyWorksSDK/UI/FnIAnnotation.h"

namespace IM { class CColorRGBA; }
namespace IM { class CPoint2D; }
namespace IM { class CPoint; }

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
///    \brief    The interface for the annotation object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IAnnotation
{
public:
    // --------------  Types publics   -------------------------------------------------------------

    // --------------  Méthodes publiques  ---------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IAnnotation() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IAnnotation() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Changes the anchoring position.  When an anchor point is set to an annotation, an
    ///              attachment line will link the annotation to the 3D anchor point. The anchor point
    ///              will be taken in account when the application adjusts the 3D Scene bounding box.
    ///              This state will be effective at the next scene refresh.
    ///
    ///    \param[ in ] pt_    The three-dimensional position of the annotation.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void AnchorPointSet( const CPoint& pt_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Changes the background color of the annotation.  This state will be effective at
    ///              the next scene refresh.
    ///
    ///    \param[ in ] color_    The annotation's background color.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void ColorSet( const CColorRGBA& color_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Changes the position of the annotation.  The input coordinates must be between 0
    ///              and 1 and are relative to the display. The origin (0,0) correspond to the lower-left
    ///              corner of the display.  This state will be effective at the next scene refresh.
    ///
    ///
    ///    \param[ in ] pt_    The two-dimensional position of the annotation in the display.
    ///                        The values of the position will be clamped between 0 and 1.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void PositionSet( const CPoint2D& pt_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Changes the text displayed in the annotation.  This state will be effective at the
    ///              next scene refresh.
    ///
    ///    \param[ in ] text_    The annotation's text.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void TextSet( const CWString& text_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Changes the visibility state of the annotation.  This state will be effective at
    ///              the next scene refresh.
    ///
    ///    \param[ in ] visible_    The annotation's visibility state.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void VisibleSet( bool visible_ ) = 0;


protected:
    // --------------- Méthodes protégées ----------------------------------------------------------

    // --------------- Variables membres protégées -------------------------------------------------

private:
    // --------------- Méthodes privées ------------------------------------------------------------

    // --------------- Variables membres privées ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
