// =================================================================================================
//   CDrawNodePolyline3D class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CDrawNodePolyline3D.h"

#include <PolyWorksSDK/Geom/CPoint.h>
#include <PolyWorksSDK/Geom/CPoint2D.h>
#include <PolyWorksSDK/Geom/FnIGeometry.h>
#include <PolyWorksSDK/Geom/IBBox.h>
#include <PolyWorksSDK/Geom/IPolyline.h>
#include <PolyWorksSDK/UI/CRenderColor.h>
#include <PolyWorksSDK/UI/IRenderer.h>
#include <math.h>

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
// Parameter: center_ : X and Y coordinate for the center of the 3D polyline.
// -------------------------------------------------------------------------------------------------
CDrawNodePolyline3D::CDrawNodePolyline3D( const IM::CWString& name_,
                                          const IM::CPoint2D& center_ )
: m_name( name_ )
{
    IM::Create( m_pPolyline3D );

    // Defines a 3D polyline using a spring shape
    double angle = 0.0;
    for ( double r = 0.0; r <= 1.0; r += 0.005 )
    {
        double x = static_cast< double >( cos( angle ) * r ) + center_[ 0 ];
        double y = static_cast< double >( sin( angle ) * r ) + center_[ 1 ];
        m_pPolyline3D->InsertBack( IM::CPoint( x, y, r ) );
        angle += 0.1;
    }

    angle = 0.0;
    for ( double r = 0.0; r > -1.0; r -= 0.005 )
    {
        double x = static_cast< double >( cos( angle ) * r ) + center_[ 0 ];
        double y = static_cast< double >( sin( angle ) * r ) + center_[ 1 ];
        m_pPolyline3D->InsertAt( 0, IM::CPoint( x, y, r ) );
        angle += 0.1;
    }

    IM::Create( m_pBBox );
    IM::Insert( m_pBBox, m_pPolyline3D );
}


// =================================================================================================
// Deallocate memory associated to the drawn geometry.
// -------------------------------------------------------------------------------------------------
CDrawNodePolyline3D::~CDrawNodePolyline3D()
{
    IM::Destroy( m_pBBox );
    IM::Destroy( m_pPolyline3D );
}


// =================================================================================================
// Returns the bounding box for this draw node.
//
// Return: Bounding box (not used because we draw in 2D)
// -------------------------------------------------------------------------------------------------
const IM::IBBox& CDrawNodePolyline3D::BBoxGet() const
{
    return *m_pBBox;
}


// =================================================================================================
// Draws a 3D polyline in the 3D Scene.
//
// Parameter: renderer_ : Reference to the rendering engine.
// -------------------------------------------------------------------------------------------------
void CDrawNodePolyline3D::Draw( IM::IRenderer& renderer_ )
{
    // Change the color and draw a 3D polyline
    IM::CRenderColor renderColor( IM::CColorRGBA( 90, 187, 49 ) );
    renderer_.PolylineDraw( m_pPolyline3D );
}


// =================================================================================================
// Return the draw node's name
//
// Return: Draw node's name
// -------------------------------------------------------------------------------------------------
IM::CWString CDrawNodePolyline3D::NameGet() const
{
    return m_name;
}
