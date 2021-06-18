#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnIBBox.h
///    \brief    This file contains the declaration of the utility functions that can be applied to
///              the bounding box geometry.
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
///    \brief    Increases the size of the bounding box to include the specified point array.
///
///    \param[ out ] pBBox_          The bounding box to modify.
///    \param[ in ] pPointArray_    The point array to be included in the bounding box.
///
///    \return    true if all points were inserted without error, false otherwise.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool Insert( IBBox* const pBBox_, const IPointArray* const pPointArray_ );


} // namespace IM
