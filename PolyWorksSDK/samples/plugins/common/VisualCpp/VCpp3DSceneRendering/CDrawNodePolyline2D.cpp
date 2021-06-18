// =================================================================================================
//   CDrawNodePolyline2D class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CDrawNodePolyline2D.h"

#include <PolyWorksSDK/Geom/FnIGeometry.h>
#include <PolyWorksSDK/Geom/IBBox.h>
#include <PolyWorksSDK/Geom/IPolyline2D.h>
#include <PolyWorksSDK/UI/CRenderColor.h>
#include <PolyWorksSDK/UI/CRenderLineWidth.h>
#include <PolyWorksSDK/UI/IRenderer.h>
#include <PolyWorksSDK/UI/IScene.h>

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
// Parameter: name_           : Draw node's name
// Parameter: borderDistance_ : Distance from the 3D Scene limit from which to draw a 2D polyline.
// -------------------------------------------------------------------------------------------------
CDrawNodePolyline2D::CDrawNodePolyline2D( const IM::CWString& name_,
                                          double              borderDistance_ )
: m_borderDistance( borderDistance_ )
, m_sceneWidth( 0 )
, m_sceneHeight( 0 )
, m_name( name_ )
{
    IM::Create( m_pPolyline2D );
    m_pPolyline2D->ClosedSet( true );
    IM::Create( m_pBBox );
}


// =================================================================================================
// Deallocate memory associated to the drawn geometry.
// -------------------------------------------------------------------------------------------------
CDrawNodePolyline2D::~CDrawNodePolyline2D()
{
    IM::Destroy( m_pBBox );
    IM::Destroy( m_pPolyline2D );
}


// =================================================================================================
// Returns the bounding box for this draw node.
//
// Return: Bounding box (not used because we draw in 2D)
// -------------------------------------------------------------------------------------------------
const IM::IBBox& CDrawNodePolyline2D::BBoxGet() const
{
    return *m_pBBox;
}


// =================================================================================================
// Draws a 2D polyline inside the outer border of the 3D Scene.
//
// Parameter: renderer_ : Reference to the rendering engine.
// -------------------------------------------------------------------------------------------------
void CDrawNodePolyline2D::Draw( IM::IRenderer& renderer_ )
{
    unsigned int currentWidth  = 0;
    unsigned int currentHeight = 0;
    IM::SceneGet()->SizeGet( currentWidth, currentHeight );

    // Recalculates where to draw a border using 2D polyline only if the 3D Scene size has changed
    if ( currentWidth != m_sceneWidth || currentHeight != m_sceneHeight )
    {
        m_sceneWidth  = currentWidth;
        m_sceneHeight = currentHeight;

        double x1 = m_borderDistance;
        double x2 = double( m_sceneWidth ) - m_borderDistance;
        double y1 = m_borderDistance;
        double y2 = double( m_sceneHeight ) - m_borderDistance;

        m_pPolyline2D->Clear();
        m_pPolyline2D->InsertBack( IM::CPoint2D( x1, y1 ) );
        m_pPolyline2D->InsertBack( IM::CPoint2D( x2, y1 ) );
        m_pPolyline2D->InsertBack( IM::CPoint2D( x2, y2 ) );
        m_pPolyline2D->InsertBack( IM::CPoint2D( x1, y2 ) );
    }

    // Change the line width and color before drawing a 2D polyline
    IM::CRenderLineWidth renderLineWidth( 1 );
    IM::CRenderColor     renderColor( IM::CColorRGBA( 90, 187, 49 ) );
    renderer_.Polyline2DDraw( m_pPolyline2D );
}


// =================================================================================================
// Return the draw node's name
//
// Return: Draw node's name
// -------------------------------------------------------------------------------------------------
IM::CWString CDrawNodePolyline2D::NameGet() const
{
    return m_name;
}
