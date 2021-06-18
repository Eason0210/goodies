#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CGeometryStatus.h
///    \brief    This file contains the declaration of the status object for geometric operations.
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
///    \ingroup  IM_ENUMERATIONS
///
///    \brief    Defines a unique type used to identify the geometry status codes.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
enum EGeometryStatusCodeUnique {};


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_TYPEDEFS
///
///    \brief    Unique status dedicated to geometry objects.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef CStatus< EGeometryStatusCodeUnique > CGeometryStatus;


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_TYPEDEFS
///
///    \brief    Status code type returned by operations made on geometry objects.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef CGeometryStatus::TCode TGeometryStatusCode;


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the status code telling that the operation on a geometry went well.  This
///              code will not change throughout the execution of a PolyWorks' module. To increase
///              the performance of the plugins, this function should not be called at each you need
///              to return a CGeometryStatus object. It should instead be cached in a local variable.
///
///
///    \return    Status code telling that the operation on a geometry went well.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TGeometryStatusCode GeometryStatusOKGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the status code telling that the operation was cancelled.
///
///    \return    Status code telling that the operation was cancelled.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TGeometryStatusCode GeometryStatusCancelledGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the status code telling that the operation failed.
///
///    \return    Status code telling that the operation failed.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TGeometryStatusCode GeometryStatusErrorGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the status code telling that the operation is not supported in this context.
///
///
///    \return    Status code telling that the operation is not supported in this context.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TGeometryStatusCode GeometryStatusNotSupportedGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the status code telling that the operations parameters are out of range.
///
///
///    \return    Status code telling that the operations parameters are out of range.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API TGeometryStatusCode GeometryStatusOutOfRangeGet();

} // namespace IM
