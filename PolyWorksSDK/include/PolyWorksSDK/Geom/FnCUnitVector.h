#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCUnitVector.h
///    \brief    This file contains the declaration of the utility functions that can be applied to
///              CUnitVector objects.
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

class CUnitVector;

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
///    \brief    Apply a transformation matrix to a unit vector.
///
///    \param[ in ] mat_           Transformation matrix to be applied to the unit vector components.
///    \param[ in, out ] unitVector_    Unit vector to be transformed.
///
///    \return    true if the transformation went successfuly, false otherwise
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool Transform( const CMatrix4& mat_, CUnitVector& unitVector_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Inversion operator (unary minus operator).  Returns a new unit vector that points
///              in the opposite direction.
///
///    \param[ in ] lhs_    The unit vector from which the inverse direction will be computed.
///
///    \return    A unit vector pointing in the opposite direction as the input vector.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CUnitVector operator- ( const CUnitVector& lhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Equality operator for unit vectors.  Indicate if the two unit vectors are pointing
///              in the same direction.
///
///    \param[ in ] lhs_    The first unit vector to be compared.
///    \param[ in ] rhs_    The second unit vector to be compared.
///
///    \return    Indicate if the unit vectors are pointing in the same direction.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator== ( const CUnitVector& lhs_, const CUnitVector&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Inequality operator for unit vectors.  Indicate if the two unit vectors are pointing
///              in different directions.
///
///    \param[ in ] lhs_    The first unit vector to be compared.
///    \param[ in ] rhs_    The second unit vector to be compared.
///
///    \return    Indicate if the unit vectors are pointing in different directions.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator!= ( const CUnitVector& lhs_, const CUnitVector&  rhs_ );

} // namespace IM
