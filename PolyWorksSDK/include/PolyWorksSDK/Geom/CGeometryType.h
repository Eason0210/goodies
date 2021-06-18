#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CGeometryType.h
///    \brief    This file contains the declaration of the geometry type.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CTrueTypedef.h>
#include <PolyWorksSDK/Base/CWString.h>
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
///    \brief    Defines a unique type used to identify the geometry types.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
enum EIGeometryTypeUnique {};


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_TYPEDEFS
///
///    \brief    The type used to identify geometries.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef CTrueTypedef< unsigned int, EIGeometryTypeUnique > CGeometryType;


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Tells whether the input geometry type is valid or not.
///
///    \param[ in ] geometryType_    The geometry type to be tested.
///
///    \return    Indicate if the geometry type is valid.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool IsGeometryTypeValid( const CGeometryType& geometryType_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the type of geometry associated to the input strings. Note that the geometry
///              must have been registered through the GeometryTypeRegister method prior to calling
///              this method.
///
///    \param[ in ] companyName_     Your company name
///    \param[ in ] moduleName_      Your module name (plug-in name)
///    \param[ in ] geometryName_    The geometry's name
///
///    \return    Constant representing the already registered geometry type.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CGeometryType GeometryTypeGet( const CWString& companyName_,
                                                 const CWString& moduleName_,
                                                 const CWString& geometryName_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Registers a new geometry into the PolyWorks SDK. The same object cannot be registered
///              more than one time.
///
///    \param[ in ] companyName_     Your company name
///    \param[ in ] moduleName_      Your module name (plug-in name)
///    \param[ in ] geometryName_    The geometry's name
///
///    \return    Constant representing the newly registered geometry type. If there is already an
///               geometry registered using the three input string, it's type will be returned. It
///               is your responsability to verify whether there exists a geometry having the same
///               identifier using GeometryTypeGet prior to registering it.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CGeometryType GeometryTypeRegister( const CWString& companyName_,
                                                      const CWString& moduleName_,
                                                      const CWString& geometryName_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the geometry type associated with IBBox class.
///
///    \return    The type of the geometry. Might be invalid (determined by IsGeometryTypeValid) in
///               the case that the geometry is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CGeometryType IBBoxTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the geometry type associated with IPointArray class.
///
///    \return    The type of the geometry. Might be invalid (determined by IsGeometryTypeValid) in
///               the case that the geometry is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CGeometryType IPointArrayTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the geometry type associated with IPointWithNormalArray class.
///
///    \return    The type of the geometry. Might be invalid (determined by IsGeometryTypeValid) in
///               the case that the geometry is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CGeometryType IPointWithNormalArrayTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the geometry type associated with a IPolyline class.
///
///    \return    The type of the geometry. Might be invalid (determined by IsGeometryTypeValid) in
///               the case that the geometry is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CGeometryType IPolylineTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the geometry type associated with a IPolyline2D class.
///
///    \return    The type of the geometry. Might be invalid (determined by IsGeometryTypeValid) in
///               the case that the geometry is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CGeometryType IPolyline2DTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the geometry type associated with a ITriangleArray class.
///
///    \return    The type of the geometry. Might be invalid (determined by IsGeometryTypeValid) in
///               the case that the geometry is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CGeometryType ITriangleArrayTypeGet();


} // namespace IM
