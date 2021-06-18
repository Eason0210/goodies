// =================================================================================================
// Data utility to generate and mesh polygonal models
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "DataGenerator.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================

// Use count to move each of the data set from an offset
static unsigned int g_useCount = 0;

namespace DataGenerator
{

// =================================================================================================
// Generates a plan on axis yz each time it is called.
// The data will be have some noise to ensure a proper contrast of the polygonal model when
// view on the application
//
// Parameter: dir_             : Direction of the digitizing vector
// Parameter: dirVector_       : Digitizing vector
// Parameter: coordinatesInMM_ : Point coordinates in millimeters
// -------------------------------------------------------------------------------------------------
void CoordinatesGet(
    EDigitizingVectorDirections& dir_,
    PointF&                      dirVector_,
    std::vector< PointF >&       squareCoordinates_ )
{
    srand( static_cast< unsigned >( time( NULL ) ) );

    // Point to point average distance ( before noise )
    const float avgDistanceBetweenPoint = 10.0f;

    // Number of points by side of the square
    const size_t sideSize = 25 + ( rand() % 10 );

    // Each time we use the generator, we move the cube on the X axis to ensure different set of data
    const float offsetX   = static_cast< float >( g_useCount ) * ( sideSize * avgDistanceBetweenPoint );
    const float offsetY   = 0;
    const float offsetZ   = 0;
    const int   randomMin = -4;
    const int   randomMax = +4;

    // Make a square plane on axis yz
    squareCoordinates_.clear();
    squareCoordinates_.reserve( sideSize * sideSize );
    for ( int j = 0; j < sideSize; ++j )
    {
        for ( int i = 0; i < sideSize; ++i )
        {
            const float x = static_cast< float >( ( rand() % ( randomMax - randomMin + 1 ) + randomMin ) ) + offsetX;
            const float y = static_cast< float >( ( rand() % ( randomMax - randomMin + 1 ) + randomMin ) ) + offsetY + ( static_cast< float >( i ) * avgDistanceBetweenPoint );
            const float z = static_cast< float >( ( rand() % ( randomMax - randomMin + 1 ) + randomMin ) ) + offsetZ + ( static_cast< float >( j ) * avgDistanceBetweenPoint );

            squareCoordinates_.emplace_back( x, y, z );
        }
    }

    dir_       = E_DIGITIZING_VECTOR_DIRECTION_OBJECT_TO_SCANNER;
    dirVector_ = { 1.0f, 0.0f, 0.0f };

    ++g_useCount;
}

// =================================================================================================
// Ok folk, this is a sample.
// There is a lot assumed here but the importance is only to show that an array of triangles must
// be generate to make the polygonal model based on the coordinates.
//
// This function assume that the point cloud is provided by CoordinatesGet and represent a pseudo-flat square surface
//
// Parameter: squareCoordinates_ : Coordinate of the points
// Parameter: triangleIndexes_   : Triangle indexes
// -------------------------------------------------------------------------------------------------
void MeshingGet(
    const std::vector< PointF >&    squareCoordinates_,
    std::vector< TriangleIndexes >& triangleIndexes_ )
{
    const size_t sideSize = sqrt( squareCoordinates_.size() );

    triangleIndexes_.clear();
    triangleIndexes_.reserve( ( sideSize - 1 ) * ( sideSize - 1 ) * 2 );
    for ( size_t j = 0; j < ( sideSize - 1 ); ++j )
    {
        const size_t indexRow     = j * sideSize;
        const size_t nextIndexRow = ( j + 1 ) * sideSize;

        for ( size_t i = 0; i < ( sideSize - 1 ); ++i )
        {
            // For each square of 4 points, we form 2 triangles
            triangleIndexes_.emplace_back( indexRow + i,     indexRow + i + 1, nextIndexRow + i );
            triangleIndexes_.emplace_back( nextIndexRow + i, indexRow + i + 1, nextIndexRow + i + 1 );
        }
    }
}

} // namespace DataGenerator
