#ifndef _CDRAWNODEPOLYLINE2D_TUESDAY_AUGUST07_134554_H_
#define _CDRAWNODEPOLYLINE2D_TUESDAY_AUGUST07_134554_H_
// =================================================================================================
//   CDrawNodePolyline2D class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/UI/IDrawNode.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

namespace IM { class IPolyline2D; }

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Draw node drawing a 2D border around the 3D Scene. The draw node's name and border distance
//   from the 3D Scene's limits are configurable.
// -------------------------------------------------------------------------------------------------
class CDrawNodePolyline2D : public IM::IDrawNode
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    CDrawNodePolyline2D( const IM::CWString& name_,
                         double              borderDistance_ );
    virtual ~CDrawNodePolyline2D();

    virtual const IM::IBBox& BBoxGet() const;
    virtual void             Draw( IM::IRenderer& renderer_ );
    virtual IM::CWString     NameGet() const;

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    IM::IBBox*       m_pBBox;
    IM::IPolyline2D* m_pPolyline2D;
    unsigned int     m_sceneWidth;
    unsigned int     m_sceneHeight;
    double           m_borderDistance;
    IM::CWString     m_name;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

#endif // _CDRAWNODEPOLYLINE2D_TUESDAY_AUGUST07_134554_H_
