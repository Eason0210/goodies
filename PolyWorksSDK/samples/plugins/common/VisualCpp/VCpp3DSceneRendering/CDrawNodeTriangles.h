#ifndef _CDRAWNODETRIANGLES_TUESDAY_AUGUST07_134554_H_
#define _CDRAWNODETRIANGLES_TUESDAY_AUGUST07_134554_H_
// =================================================================================================
//   CDrawNodeTriangles class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Geom/CPoint2D.h>
#include <PolyWorksSDK/UI/IDrawNode.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

namespace IM { class ITriangleArray; }
namespace IM { class IPointArray; }

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Draw node drawing triangles in the 3D Scene. The draw node's name and triangle array XY center
//   are configurable.
// -------------------------------------------------------------------------------------------------
class CDrawNodeTriangles : public IM::IDrawNode
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    CDrawNodeTriangles( const IM::CWString& name_,
                        const IM::CPoint2D& center_ );
    virtual ~CDrawNodeTriangles();

    virtual const IM::IBBox& BBoxGet() const;
    virtual void             Draw( IM::IRenderer& renderer_ );
    virtual IM::CWString     NameGet() const;

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    IM::IBBox*          m_pBBox;
    IM::ITriangleArray* m_pTriangleArray;
    IM::IPointArray*    m_pPointArray;
    IM::CWString        m_name;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================


#endif // _CDRAWNODETRIANGLES_TUESDAY_AUGUST07_134554_H_
