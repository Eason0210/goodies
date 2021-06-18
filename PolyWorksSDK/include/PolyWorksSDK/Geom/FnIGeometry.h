#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnIGeometry.h
///    \brief    This file contains the declaration of the functions used to create and destroy various
///              geometries.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class IBBox;
class IGeometry;
class IPointArray;
class IPointWithNormalArray;
class IPolyline;
class IPolyline2D;
class ITriangleArray;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Factory for bounding box objects.  Creates a bounding box geometry objects. The pointer
///              MUST be destroy using the Destroy method in order to free its allocated memory.
///
///
///    \param[ out ] pBBox_    The pointer that will receive the created bounding box. There are no
///                            restrictions or specific notes for the returned object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Create( IBBox*& pBBox_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Factory for point arrays.  Creates an array of point objects. The pointer MUST be
///              destroy using the Destroy method in order to free its allocated memory.
///
///    \param[ out ] pPointArray_    The pointer that will receive the created array. Here are the
///                                  restrictions and specific notes for the returned object:
///                                  * Add - Each time you add a new point, it is garantied to be added
///                                  at the end of the array.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Create( IPointArray*& pPointArray_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Factory for point with normal arrays.  Creates an array of point with normal objects.
///              The pointer MUST be destroy using the Destroy method in order to free its allocated
///              memory.
///
///    \param[ out ] pPointWithNormalArray_    The pointer that will receive the created array. Here
///                                            are the restrictions and specific notes for the
///                                            returned object:
///                                            * Add - Each time you add a new point (whether it has
///                                            a normal or not), it is garantied to be added
///                                            at the end of the array.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Create( IPointWithNormalArray*& pPointWithNormalArray_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Factory for polyline objects.  Creates a polyline object. The pointer MUST be destroy
///              using the Destroy method in order to free its allocated memory.
///
///    \param[ out ] pPolyline_    The pointer that will receive the created polyline. There are no
///                                restrictions or specific notes for the returned object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Create( IPolyline*& pPolyline_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Factory for two-dimensional polyline objects.  Creates a two-dimensional polyline
///              object. The pointer MUST be destroy using the Destroy method in order to free its
///              allocated memory.
///
///    \param[ out ] pPolyline2D_    The pointer that will receive the created 2D polyline. There are
///                                  no restrictions or specific notes for the returned object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Create( IPolyline2D*& pPolyline2D_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Factory for triangle objects arrays.  Creates an array of triangle objects associated
///              with the input point array. The pointer MUST be destroy using the Destroy method
///              in order to free its allocated memory.
///
///    \param[ out ] pTriangleArray_    The pointer that will receive the created array.
///    \param[ in ] pPointArray_       The pointer to the array of points used by the triangles. Note
///                                    that this array must already be valid.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Create( ITriangleArray*& pTriangleArray_, IPointArray* pPointArray_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    The destruction method for all geometry objects created with the Create factory.
///              Destroys the geometry and free up its allocated memory.
///
///    \param[ in ] pGeometry_    Pointer to the geometry to be destoyed.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Destroy( IGeometry* pGeometry_ );


} // namespace IM
