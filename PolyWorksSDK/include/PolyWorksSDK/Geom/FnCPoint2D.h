#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCPoint2D.h
///    \brief    This file contains the declaration of the utility functions that can be applied to
///              CPoint2D two-dimensional point objects.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

namespace IM
{

class CPoint2D;

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
///    \brief    Opposite position operator (unary minus operator).  Returns a new point object located
///              opposite position of the input point with respect to the origin.
///
///    \param[ in ] lhs_    The point object from which the opposite position will be computed.
///
///    \return    A point object located at the opposite position of the input point.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint2D operator- ( const CPoint2D& lhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Addition operator for two-dimensional point objects.  Returns a new point object
///              which coordinates correspond to the sum of the two points' coordinates.
///
///    \param[ in ] lhs_    The first point to be added.
///    \param[ in ] rhs_    The second point to be added.
///
///    \return    A point object computed from the sum of the two points' coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint2D operator+ ( const CPoint2D& lhs_, const CPoint2D&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Subtraction operator for two-dimensional point objects.  Returns a new point object
///              which coordinates correspond to the subtraction of the second points' coordinates
///              to the ones of the first point.
///
///    \param[ in ] lhs_    The point to be used as a basis.
///    \param[ in ] rhs_    The point to be subtracted.
///
///    \return    A point object computed from the subtraction of the two points' coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint2D operator- ( const CPoint2D& lhs_, const CPoint2D&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Multiplication operator for a two-dimensional point object.  Returns a new point
///              object which coordinates were multiplied by a factor.
///
///    \param[ in ] lhs_    The point object from which the new position will be computed.
///    \param[ in ] rhs_    The scaling factor to be applied.
///
///    \return    A point object computed from the scaling of the point's coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint2D operator* ( const CPoint2D& lhs_, double rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Multiplication operator for a two-dimensional point object.  Returns a new point
///              object which coordinates were multiplied by a factor.
///
///    \param[ in ] lhs_    The scaling factor to be applied.
///    \param[ in ] rhs_    The point object from which the new position will be computed.
///
///    \return    A point object computed from the scaling of the point's coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPoint2D operator* ( double lhs_, const CPoint2D&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Equality operator for two-dimensional point objects.  Indicate if the two point objects
///              have the same coordinates.
///
///    \param[ in ] lhs_    The first point to be compared.
///    \param[ in ] rhs_    The second point to be compared.
///
///    \return    Indicate if the point objects have the same coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator== ( const CPoint2D& lhs_, const CPoint2D&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Inequality operator for two-dimensional point objects.  Indicate if the two point
///              objects have different coordinates.
///
///    \param[ in ] lhs_    The first point to be compared.
///    \param[ in ] rhs_    The second point to be compared.
///
///    \return    Indicate if the point objects have different coordinates.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator!= ( const CPoint2D& lhs_, const CPoint2D&  rhs_ );

} // namespace IM
