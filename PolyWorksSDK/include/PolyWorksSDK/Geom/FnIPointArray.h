#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnIPointArray.h
///    \brief    This file contains the declaration of the transformation functions that can be applied
///              to an array of CPoint objects.
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

class IPointArray;

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
///    \brief    Apply a transformation matrix to an array of points.
///
///    \param[ in ] mat_            Transformation matrix to be applied to the point coordinates
///                                 in the array.
///    \param[ in, out ] pPointArray_    Array of points to be transformed.
///
///    \return    true if the transformation went successfuly, false otherwise
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool Transform( const CMatrix4& mat_, IPointArray* const pPointArray_ );


} // namespace IM
