#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnIAnnotation.h
///    \brief    This file contains the declaration of the functions used to create and destroy various
///              annotations.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class IAnnotation;

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
///    \brief    Factory for annotation objects.  Creates an annotation object. This operation is
///              not supported in all of PolyWorks' modules and will return NULL if this operation
///              is not supported.  This annotation MUST be destroy using the Destroy method in order
///              to free its allocated memory and to remove it from the display list.
///
///    \param[ out ] pAnnotation_    The pointer that will receive the created annotation.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Create( IAnnotation*& pAnnotation_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    The destruction method for all annotation objects.  Destroys the annotation, remove
///              it from the display list and free up its allocated memory.
///
///    \param[ in ] pAnnotation_    Pointer to the annotation to be destroyed.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API void Destroy( IAnnotation* pAnnotation_ );


} // namespace IM
