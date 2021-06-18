// =================================================================================================
// C++ Wrapper around the IIMPolygonalModel COM Interface
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CPolygonalModel.h"

#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspectProject7.h>
#include <PolyWorksSDK/COM/IIMPolygonalModel.h>
#include <atlsafe.h>

#include "CompanyNameConst.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================

// =================================================================================================
// Return true if the 2 unique IDs are the same
// -------------------------------------------------------------------------------------------------
bool Compare( const TUniqueID& uniqueID1_, const TUniqueID& uniqueID2_  )
{
    return wcsicmp( uniqueID1_.c_str(), uniqueID2_.c_str() ) == 0;
}

// =================================================================================================
// Factory function to create a Polygonal Model from a unique ID.
//
// The unique ID can be obtains from a MSCL Command or from the storage of a polygonal model passed
// while scanning.
//
// Parameter: uniqueID_ : Unique ID used to retrieve the Polygonal Model
//
// Return: The polygonal model or empty on failure
// -------------------------------------------------------------------------------------------------
std::unique_ptr< CPolygonalModel > PolygonalModelCreate( const TUniqueID& uniqueID_ )
{
    CComPtr< IIMInspect > pIIMInspect;
    HRESULT hResult = GITGetInterfaceFromGlobal( g_cookieHost, IID_IIMInspect, ( void** ) &pIIMInspect );
    if ( !SUCCEEDED( hResult ) || ( pIIMInspect == nullptr ) )
    {
        return {};
    }

    CComPtr< IIMInspectProject > pIIMInspectProjectBase;
    hResult = pIIMInspect->ProjectGetCurrent( &pIIMInspectProjectBase );
    if ( !SUCCEEDED( hResult ) || ( pIIMInspectProjectBase == nullptr ) )
    {
        return {};
    }
    CComQIPtr< IIMInspectProject7 > pIIMInspectProject( pIIMInspectProjectBase );
    if ( pIIMInspectProject == nullptr )
    {
        return {};
    }

    CComPtr< IIMPolygonalModel > pIIMPolygonalModel;
    hResult = pIIMInspectProject->DataObtainAsPolygonalModel( uniqueID_.c_str(), &pIIMPolygonalModel );
    if ( !SUCCEEDED( hResult ) || ( pIIMPolygonalModel == nullptr ) )
    {
        return {};
    }

    auto pPolygonalModel = std::make_unique< CPolygonalModel >();
    if ( !pPolygonalModel->Initialize( *pIIMPolygonalModel ) )
    {
        return {};
    }

    return pPolygonalModel;
}

// =================================================================================================
// Destructor
// -------------------------------------------------------------------------------------------------
CPolygonalModel::~CPolygonalModel()
{
    Uninitialize();
}

// =================================================================================================
// Initialize the class with the COM Interface
//
// After the success of this call, the IIMPolygonalModel ref count will be increment to own
// the reference to it for futur use
//
// Parameter: polygonalModel_ : Polygonal Model
//
// Return: true for success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CPolygonalModel::Initialize( IIMPolygonalModel& polygonalModel_ )
{
    if ( IsInitialized() )
    {
        return false;
    }

    return GITRegisterInterfaceInGlobal( &polygonalModel_, IID_IIMPolygonalModel, &m_cookie ) == S_OK;
}

// =================================================================================================
// Return if the polygonal model is initialized
// -------------------------------------------------------------------------------------------------
bool CPolygonalModel::IsInitialized() const
{
    return m_cookie != 0;
}

// =================================================================================================
// Uninitialize and release the COM Interface
// -------------------------------------------------------------------------------------------------
void CPolygonalModel::Uninitialize()
{
    GITRevokeInterfaceFromGlobal( m_cookie );
}

// =================================================================================================
// Retrieves the coordinates and triangles of a polygonal model
//
// This function can be used directly on a polygonal model passed by the application during a scan or
// by one retrieve from the project
//
// Parameter: unitConversionFactor_ : Scaling factor to have the coordinates returned in the current application units
// Parameter: coordinates_          : Coordinates of the points
// Parameter: triangleIndexes_      : Triangle indexes
//
// Return: true for success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CPolygonalModel::PointsAndTrianglesGet( float                           unitConversionFactor_,
                                             std::vector< PointF >&          coordinates_,
                                             std::vector< TriangleIndexes >& triangleIndexes_ )
{
    coordinates_.clear();
    triangleIndexes_.clear();

    if ( !IsInitialized() )
    {
        return false;
    }

    // Get the COM Interface
    CComPtr< IIMPolygonalModel > pPolygonalModel;
    HRESULT hResult = GITGetInterfaceFromGlobal( m_cookie, IID_IIMPolygonalModel, ( void** ) &pPolygonalModel );
    if ( !SUCCEEDED( hResult ) || ( pPolygonalModel == nullptr ) )
    {
        return false;
    }

    // Get the information using the COM Interface
    LPSAFEARRAY pCoordinates = nullptr;
    LPSAFEARRAY pTriangles   = nullptr;
    hResult = pPolygonalModel->PointsAndTrianglesGet( &pCoordinates, &pTriangles );
    if ( !SUCCEEDED( hResult ) )
    {
        return false;
    }

    // Convert the coordinate safearray into a std::vector and apply the units scaling factor in same time
    CComSafeArray< float > coordinates;
    coordinates.Attach( pCoordinates );
    LONG lb = coordinates.GetLowerBound();
    LONG ub = coordinates.GetUpperBound();
    coordinates_.reserve( ( ub - lb + 1 ) / 3 );
    for ( LONG i = lb; i <= ub; i += 3 )
    {
        coordinates_.emplace_back( coordinates[ i ] / unitConversionFactor_,
                                   coordinates[ i + 1 ] / unitConversionFactor_,
                                   coordinates[ i + 2 ] / unitConversionFactor_ );
    }

    // Convert the triangle indexes safearray into a std::vector
    CComSafeArray< unsigned long > triangles;
    triangles.Attach( pTriangles );
    lb = triangles.GetLowerBound();
    ub = triangles.GetUpperBound();
    triangleIndexes_.reserve( ( ub - lb + 1 ) / 3 );
    for ( LONG i = lb; i <= ub; i += 3 )
    {
        triangleIndexes_.emplace_back( triangles[ i ],
                                       triangles[ i + 1 ],
                                       triangles[ i + 2 ] );
    }

    return true;
}

// =================================================================================================
// Replace the coordinates and triangles of a polygonal model
//
// This function can be used directly on a polygonal model passed by the application during a scan or
// by one retrieve from the project
//
// Each call to this function will erase the previously contains data and replace them by the new ones.
//
// Parameter: unitConversionFactor_ : Scaling factor to have the coordinates sent in the current application units
// Parameter: dir_                  : Description of the direction of the digitizing vector
// Parameter: dirVector_            : Digitizing vector
// Parameter: coordinates_          : Coordinates of the points
// Parameter: triangleIndexes_      : Triangle indexes
//
// Return: true for success, otherwise false
// -------------------------------------------------------------------------------------------------
bool CPolygonalModel::PointsAndTrianglesTransfer( float                                 unitConversionFactor_,
                                                  EDigitizingVectorDirections           dir_,
                                                  const PointF&                         dirVector_,
                                                  const std::vector< PointF >&          coordinates_,
                                                  const std::vector< TriangleIndexes >& triangleIndexes_ )
{
    if ( !IsInitialized() )
    {
        return false;
    }

    // Get the COM Interface
    CComPtr< IIMPolygonalModel > pPolygonalModel;
    HRESULT hResult = GITGetInterfaceFromGlobal( m_cookie, IID_IIMPolygonalModel, ( void** ) &pPolygonalModel );
    if ( !SUCCEEDED( hResult ) || ( pPolygonalModel == nullptr ) )
    {
        return false;
    }

    // Convert the direction vector into a flat safe array of float
    CComSafeArray< float > dirVector( 3 );
    dirVector[ 0 ] = dirVector_[ 0 ];
    dirVector[ 1 ] = dirVector_[ 1 ];
    dirVector[ 2 ] = dirVector_[ 2 ];

    // Convert the coordinates into a flat safe array of float
    // Each point will be 3 consecutive values in the safearray
    CComSafeArray< float > coordinates( coordinates_.size() * 3 );
    for ( LONG i = 0; i < static_cast< LONG >( coordinates_.size() ); ++i )
    {
        const auto& coordinate = coordinates_[ i ];
        coordinates[ ( i * 3 )     ] = coordinate[ 0 ] * unitConversionFactor_;
        coordinates[ ( i * 3 ) + 1 ] = coordinate[ 1 ] * unitConversionFactor_;
        coordinates[ ( i * 3 ) + 2 ] = coordinate[ 2 ] * unitConversionFactor_;
    }

    // Convert the triangleIndexes into a flat safe array of float
    // Each triangle will be convert into 3 consecutive index values in the safearray
    CComSafeArray< unsigned long > triangleIndexes( triangleIndexes_.size() * 3 );
    for ( LONG i = 0; i < static_cast< LONG >( triangleIndexes_.size() ); ++i )
    {
        const auto& indexes = triangleIndexes_[ i ];
        triangleIndexes[ ( i * 3 )     ] = static_cast< unsigned long >( indexes[ 0 ] );
        triangleIndexes[ ( i * 3 ) + 1 ] = static_cast< unsigned long >( indexes[ 1 ] );
        triangleIndexes[ ( i * 3 ) + 2 ] = static_cast< unsigned long >( indexes[ 2 ] );
    }

    // Transfer the model to the application
    hResult = pPolygonalModel->PointsAndTrianglesTransfer( dir_,
                                                           dirVector.GetSafeArrayPtr(),
                                                           coordinates.GetSafeArrayPtr(),
                                                           triangleIndexes.GetSafeArrayPtr() );

    return SUCCEEDED( hResult );
}

// =================================================================================================
// Return the unique ID of a polygonal model
//
// The unique ID is the link between the model and can be preserve from a polygonal mode from a scan
// to later use it to retrieve the polygonal model post-scan from the project.
// -------------------------------------------------------------------------------------------------
TUniqueID CPolygonalModel::UniqueIDGet()
{
    if ( !IsInitialized() )
    {
        return {};
    }

    // Get the COM Interface
    CComPtr< IIMPolygonalModel > pPolygonalModel;
    HRESULT hResult = GITGetInterfaceFromGlobal( m_cookie, IID_IIMPolygonalModel, ( void** ) &pPolygonalModel );
    if ( ( hResult != S_OK ) || ( pPolygonalModel == nullptr ) )
    {
        return {};
    }

    // Retrieve the unique ID from the application
    CComBSTR id;
    hResult = pPolygonalModel->UniqueIDGet( &id );
    if ( !SUCCEEDED( hResult ) )
    {
        return {};
    }

    return TUniqueID{ id, id.Length() };
}
