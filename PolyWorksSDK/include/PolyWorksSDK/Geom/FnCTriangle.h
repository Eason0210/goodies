#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCTriangle.h
///    \brief    This file contains the declaration of the operators that can be applied to CTriangle
///              triangle objects.
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

class CTriangle;

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
///    \brief    Equality operator for triangle objects.  Indicate if the two triangle objects have
///              the same point indexes.
///
///    \param[ in ] lhs_    The first triangle to be compared.
///    \param[ in ] rhs_    The second triangle to be compared.
///
///    \return    Indicate if the triangle objects have the same point indexes.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator== ( const CTriangle& lhs_, const CTriangle&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Inequality operator for triangle objects.  Indicate if the two triangle objects have
///              different point indexes.
///
///    \param[ in ] lhs_    The first triangle to be compared.
///    \param[ in ] rhs_    The second triangle to be compared.
///
///    \return    Indicate if the triangle objects have different point indexes.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator!= ( const CTriangle& lhs_, const CTriangle&  rhs_ );

} // namespace IM
