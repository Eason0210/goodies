﻿#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnIScene.h
///    \brief    Free functions for managing IScene object.
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

class IScene;

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

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
///    \brief    Gives a direct access to the module's current IScene interface.
///
///    \return    Pointer to the module's current IScene interface. NULL if there is an error or if
///               the PolyWorks SDK is not initialized.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API IScene* SceneGet();

} // namespace IM
