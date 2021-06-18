// =================================================================================================
//   CDrawNodePoints class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CDrawNodePoints.h"

#include <PolyWorksSDK/Geom/CPoint2D.h>
#include <PolyWorksSDK/Geom/FnIBBox.h>
#include <PolyWorksSDK/Geom/FnIGeometry.h>
#include <PolyWorksSDK/Geom/IBBox.h>
#include <PolyWorksSDK/Geom/IPointArray.h>
#include <PolyWorksSDK/UI/CRenderColor.h>
#include <PolyWorksSDK/UI/FnIAnnotation.h>
#include <PolyWorksSDK/UI/IRenderer.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// Constructor configuring the draw node.
//
// Parameter: name_   : Draw node's name
// Parameter: center_ : X and Y coordinate for the center of the 3D points.
// -------------------------------------------------------------------------------------------------
CDrawNodePoints::CDrawNodePoints( const IM::CWString& name_,
                                  const IM::CPoint2D& center_ )
: m_name( name_ )
{
    IM::Create( m_pPointArray );

    // Fills the point array to draw a simple box using 3D points.
    for ( float iX = -1; iX <= 1; iX += 0.5f )
    {
        for ( float iY = -1; iY <= 1; iY += 0.5f )
        {
            for ( float iZ = -1; iZ <= 1; iZ += 0.5f )
            {
                m_pPointArray->Add( IM::CPoint( iX + center_[ 0 ], iY + center_[ 1 ], iZ ) );
            }
        }
    }

    IM::Create( m_pBBox );
    IM::Insert( m_pBBox, m_pPointArray );
}


// =================================================================================================
// Deallocate memory associated to the drawn geometry.
// -------------------------------------------------------------------------------------------------
CDrawNodePoints::~CDrawNodePoints()
{
    IM::Destroy( m_pBBox );
    IM::Destroy( m_pPointArray );
}


// =================================================================================================
// Returns the bounding box for this draw node.
//
// Return: Bounding box (not used because we draw in 2D)
// -------------------------------------------------------------------------------------------------
const IM::IBBox& CDrawNodePoints::BBoxGet() const
{
    return *m_pBBox;
}


// =================================================================================================
// Draws 3D points in the 3D Scene.
//
// Parameter: renderer_ : Reference to the rendering engine.
// -------------------------------------------------------------------------------------------------
void CDrawNodePoints::Draw( IM::IRenderer& renderer_ )
{
    // Sets the color to draw the points
    IM::CRenderColor renderColor( IM::CColorRGBA( 244, 255, 170 ) );
    renderer_.PointArrayDraw( m_pPointArray );
}


// =================================================================================================
// Return the draw node's name
//
// Return: Draw node's name
// -------------------------------------------------------------------------------------------------
IM::CWString CDrawNodePoints::NameGet() const
{
    return m_name;
}
