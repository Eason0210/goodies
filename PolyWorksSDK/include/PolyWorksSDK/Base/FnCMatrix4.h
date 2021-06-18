#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCMatrix4.h
///    \brief    This file contains the identity matrix creation function declaration.
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

class CMatrix4;

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
///    \brief    Assign the identity matrix to the specified matrix.
///
///    \param[ out ] mat_    The matrix to revert back to identity.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Identity( CMatrix4& mat_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Equality operator for transformation matrix objects.  Indicate if the two transformation
///              matrix objects are identical.
///
///    \param[ in ] lhs_    The first matrix to be compared.
///    \param[ in ] rhs_    The second matrix to be compared.
///
///    \return    Indicate if the transformation matrix objects are identical.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator== ( const CMatrix4& lhs_, const CMatrix4&  rhs_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Inequality operator for transformation matrix objects.  Indicate if the two transformation
///              matrix objects are different.
///
///    \param[ in ] lhs_    The first matrix to be compared.
///    \param[ in ] rhs_    The second matrix to be compared.
///
///    \return    Indicate if the transformation matrix objects are different.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool operator!= ( const CMatrix4& lhs_, const CMatrix4&  rhs_ );

} // namespace IM
