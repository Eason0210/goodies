// =================================================================================================
//   CDrawNodeTriangles class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CDrawNodeTriangles.h"

#include <PolyWorksSDK/Geom/FnIGeometry.h>
#include <PolyWorksSDK/Geom/IBBox.h>
#include <PolyWorksSDK/Geom/IPointArray.h>
#include <PolyWorksSDK/Geom/ITriangleArray.h>
#include <PolyWorksSDK/UI/CRenderColor.h>
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
CDrawNodeTriangles::CDrawNodeTriangles( const IM::CWString& name_,
                                        const IM::CPoint2D& center_ )
: m_name( name_ )
{
    IM::Create( m_pPointArray );

    // Sets the points for the triangles
    // Top
    m_pPointArray->Add( IM::CPoint( -0.5 + center_[ 0 ], -0.5 + center_[ 1 ], -1.0 ) );
    m_pPointArray->Add( IM::CPoint(  0.5 + center_[ 0 ], -0.5 + center_[ 1 ], -1.0 ) );
    m_pPointArray->Add( IM::CPoint(  0.5 + center_[ 0 ],  0.5 + center_[ 1 ], -1.0 ) );
    m_pPointArray->Add( IM::CPoint( -0.5 + center_[ 0 ],  0.5 + center_[ 1 ], -1.0 ) );

    // Centre point
    m_pPointArray->Add( IM::CPoint( 0.0 + center_[ 0 ], 0.0 + center_[ 1 ], 0.0 ) );

    // Top
    m_pPointArray->Add( IM::CPoint( -0.5 + center_[ 0 ], -0.5 + center_[ 1 ], 1.0 ) );
    m_pPointArray->Add( IM::CPoint(  0.5 + center_[ 0 ], -0.5 + center_[ 1 ], 1.0 ) );
    m_pPointArray->Add( IM::CPoint(  0.5 + center_[ 0 ],  0.5 + center_[ 1 ], 1.0 ) );
    m_pPointArray->Add( IM::CPoint( -0.5 + center_[ 0 ],  0.5 + center_[ 1 ], 1.0 ) );

    // Links together points using their ID in m_pPointArray to define triangles
    IM::Create( m_pTriangleArray, m_pPointArray );
    m_pTriangleArray->Add( IM::CTriangle( 0, 1, 2 ) );
    m_pTriangleArray->Add( IM::CTriangle( 2, 3, 0 ) );
    m_pTriangleArray->Add( IM::CTriangle( 1, 4, 2 ) );
    m_pTriangleArray->Add( IM::CTriangle( 2, 4, 3 ) );
    m_pTriangleArray->Add( IM::CTriangle( 3, 4, 0 ) );
    m_pTriangleArray->Add( IM::CTriangle( 0, 4, 1 ) );
    m_pTriangleArray->Add( IM::CTriangle( 6, 5, 8 ) );
    m_pTriangleArray->Add( IM::CTriangle( 8, 7, 6 ) );
    m_pTriangleArray->Add( IM::CTriangle( 6, 4, 5 ) );
    m_pTriangleArray->Add( IM::CTriangle( 7, 4, 6 ) );
    m_pTriangleArray->Add( IM::CTriangle( 8, 4, 7 ) );
    m_pTriangleArray->Add( IM::CTriangle( 5, 4, 8 ) );

    IM::Create( m_pBBox );
    IM::Insert( m_pBBox, m_pPointArray );
}


// =================================================================================================
// Deallocate memory associated to the drawn geometry.
// -------------------------------------------------------------------------------------------------
CDrawNodeTriangles::~CDrawNodeTriangles()
{
    IM::Destroy( m_pBBox );
    IM::Destroy( m_pPointArray      );
    IM::Destroy( m_pTriangleArray   );
}


// =================================================================================================
// Returns the bounding box for this draw node.
//
// Return: Bounding box (not used because we draw in 2D)
// -------------------------------------------------------------------------------------------------
const IM::IBBox& CDrawNodeTriangles::BBoxGet() const
{
    return *m_pBBox;
}


// =================================================================================================
// Draws 3D points in the 3D Scene.
//
// Parameter: renderer_ : Reference to the rendering engine.
// -------------------------------------------------------------------------------------------------
void CDrawNodeTriangles::Draw( IM::IRenderer& renderer_ )
{
    // Change the color and draw the triangle array
    IM::CRenderColor renderColor( IM::CColorRGBA( 64, 203, 255 ) );
    renderer_.TriangleArrayDraw( m_pTriangleArray );
}


// =================================================================================================
// Return the draw node's name
//
// Return: Draw node's name
// -------------------------------------------------------------------------------------------------
IM::CWString CDrawNodeTriangles::NameGet() const
{
    return m_name;
}
