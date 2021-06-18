#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCPWOElementsTypes.h
///    \brief    This file contains the declaration of the operators that can be applied to CPWOElementsTypes
///              objects.
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

class CPWOElementsTypes;

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
///    \brief    Joins together two collections of element types with a AND operation.  Note that
///              a CPWOElementsTypes object can be created implicitly from a CPWOElementType.
///
///    \param[ in ] lhs_    The first collection of types of the AND operation
///    \param[ in ] rhs_    The second collection of types of the AND operation
///
///    \return    A new collection corresponding to the joined input collections.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPWOElementsTypes operator&&( const CPWOElementsTypes& lhs_, const CPWOElementsTypes& rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Inverts a collection of element types.  Note that a CPWOElementsTypes object can
///              be created implicitly from a CPWOElementType.
///
///    \param[ in ] rhs_    The collection of types.
///
///    \return    A new collection corresponding to the inverted input collection.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPWOElementsTypes operator!( const CPWOElementsTypes& rhs_ );

} // namespace IM
