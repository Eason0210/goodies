#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWObjectStatus.h
///    \brief    This file contains the declaration of the status object for Polyworks Object operations.
///
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CStatus.h>
#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup   IM_ENUMERATIONS
///
///    \brief     Defines a unique type used to identify the PolyWorks Object status codes.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
enum EPWObjectStatusCodeUnique {};


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup   IM_TYPEDEFS
///
///    \brief     Unique status dedicated to PolyWorks Objects.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef CStatus< EPWObjectStatusCodeUnique > CPWObjectStatus;


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup   IM_TYPEDEFS
///
///    \brief     Status code type returned by operations made on PolyWorks Objects.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef CPWObjectStatus::TCode TPWObjectStatusCode;


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup   IM_FUNCTIONS
///
///    \brief     Returns the status code telling that the operation on a PolyWorks Object went well.
///
///
///    \return    Status code telling that the operation on a PolyWorks Object went well.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TPWObjectStatusCode PWObjectStatusOKGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup   IM_FUNCTIONS
///
///    \brief     Returns the status code telling that the operation was canceled.
///
///    \return    Status code telling that the operation was canceled.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TPWObjectStatusCode PWObjectStatusCancelledGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup   IM_FUNCTIONS
///
///    \brief     Returns the status code telling that the operation failed.
///
///    \return    Status code telling that the operation failed.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TPWObjectStatusCode PWObjectStatusErrorGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup   IM_FUNCTIONS
///
///    \brief     Returns the status code telling that the operation is not supported in this context.
///
///
///    \return    Status code telling that the operation is not supported in this context.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TPWObjectStatusCode PWObjectStatusNotSupportedGet();


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================


} // namespace IM
