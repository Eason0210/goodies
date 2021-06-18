#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCPoint.h
///    \brief    This file contains the declaration of the utility functions that can be applied to
///              CPoint three-dimensional point objects.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

namespace IM { class CMatrix4; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CPoint;

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
///    \brief    Apply a transformation matrix to a point object.
///
///    \param[ in ] mat_      Transformation matrix to be applied to the point coordinates.
///    \param[ in, out ] point_    Point object to be transformed.
///
///    \return    true if the transformation went successfuly, false otherwise
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool Transform( const CMatrix4& mat_, CPoint& point_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Opposite position operator (unary minus operator).  Returns a new point object located
///              opposite position of the input point with respect to the origin.
///
///    \param[ in ] lhs_    The point object from which the opposite position will be computed.
///
///    \return    A point object located at the opposite position of the input point.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint operator- ( const CPoint& lhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Addition operator for point objects.  Returns a new point object which coordinates
///              correspond to the sum of the two points' coordinates.
///
///    \param[ in ] lhs_    The first point to be added.
///    \param[ in ] rhs_    The second point to be added.
///
///    \return    A point object computed from the sum of the two points' coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint operator+ ( const CPoint& lhs_, const CPoint&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Subtraction operator for point objects.  Returns a new point object which coordinates
///              correspond to the subtraction of the second points' coordinates to the ones of the
///              first point.
///
///    \param[ in ] lhs_    The point to be used as a basis.
///    \param[ in ] rhs_    The point to be subtracted.
///
///    \return    A point object computed from the subtraction of the two points' coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint operator- ( const CPoint& lhs_, const CPoint&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Multiplication operator for a point object.  Returns a new point object which coordinates
///              were multiplied by a factor.
///
///    \param[ in ] lhs_    The point object from which the new position will be computed.
///    \param[ in ] rhs_    The scaling factor to be applied.
///
///    \return    A point object computed from the scaling of the point's coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint operator* ( const CPoint& lhs_, double rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Multiplication operator for a point object.  Returns a new point object which coordinates
///              were multiplied by a factor.
///
///    \param[ in ] lhs_    The scaling factor to be applied.
///    \param[ in ] rhs_    The point object from which the new position will be computed.
///
///    \return    A point object computed from the scaling of the point's coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint operator* ( double lhs_, const CPoint&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Equality operator for point objects.  Indicate if the two point objects have the
///              same coordinates.
///
///    \param[ in ] lhs_    The first point to be compared.
///    \param[ in ] rhs_    The second point to be compared.
///
///    \return    Indicate if the point objects have the same coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator== ( const CPoint& lhs_, const CPoint&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Inequality operator for point objects.  Indicate if the two point objects have different
///              coordinates.
///
///    \param[ in ] lhs_    The first point to be compared.
///    \param[ in ] rhs_    The second point to be compared.
///
///    \return    Indicate if the point objects have different coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator!= ( const CPoint& lhs_, const CPoint&  rhs_ );

} // namespace IM
