#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCColorRGBA.h
///    \brief    This file contains the declaration of the operators that can be applied to CColorRGBA
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

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

namespace IM
{

class CColorRGBA;

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
///    \brief    Equality operator for color objects.  Indicate if the two color objects are identical.
///
///
///    \param[ in ] lhs_    The first color to be compared.
///    \param[ in ] rhs_    The second color to be compared.
///
///    \return    Indicate if the color objects are identical.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator== ( const CColorRGBA& lhs_, const CColorRGBA&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Inequality operator for color objects.  Indicate if the two color objects are different.
///
///
///    \param[ in ] lhs_    The first color to be compared.
///    \param[ in ] rhs_    The second color to be compared.
///
///    \return    Indicate if the color objects are different.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator!= ( const CColorRGBA& lhs_, const CColorRGBA&  rhs_ );

} // namespace IM
