#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWObjectType.h
///    \brief    Type of a PolyWorks Object.
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
///    \brief    enum used to make CPWObjectType unique.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
enum ECPWObjectTypeUnique {};


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_TYPEDEFS
///
///    \brief    Unique type of a PolyWorks Object type.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef CTrueTypedef< unsigned int, ECPWObjectTypeUnique > CPWObjectType;


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the ILineScan PolyWorks Object Type.
///
///    \return    The type identifying the ILineScan PolyWorks Object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWObjectType ILineScanTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the IPointCloud PolyWorks Object Type.
///
///    \return    The type identifying the IPointCloud PolyWorks Object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWObjectType IPointCloudTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the IPolygonalModel PolyWorks Object Type.
///
///    \return    The type identifying the IPolygonalModel PolyWorks Object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWObjectType IPolygonalModelTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Tells whether the input PolyWorks Object type is valid or not.
///
///    \param[ in ] PWObjectType_    PolyWorks Object type to be tested
///
///    \return    true if the PolyWorks Object type is valid, false otherwise
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool IsPWObjectTypeValid( const CPWObjectType& PWObjectType_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the type of PolyWorks Object associated to the input strings. Note that the
///              PolyWorks Object must have been registered through the IPWObjects::PWObjectTypeRegister
///              method prior to calling this method.
///
///    \param[ in ] companyName_    Your company name
///    \param[ in ] moduleName_     Your module name (plug-in name)
///    \param[ in ] objectName_     The object's name
///
///    \return    Constant representing the already registered PolyWorks Object type.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWObjectType PWObjectTypeGet( const CWString& companyName_,
                                                 const CWString& moduleName_,
                                                 const CWString& objectName_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Registers a new PolyWorks Object into the PolyWorks SDK. The same object cannot be
///              registered more than one time.
///
///    \param[ in ] companyName_    Your company name
///    \param[ in ] moduleName_     Your module name (plug-in name)
///    \param[ in ] objectName_     The object's name
///
///    \return    Constant representing the newly registered PolyWorks Object Type. If there is already
///               an object registered using the three input string, it's type will be returned. It
///               is your responsability to verify whether there exists an object having the same
///               identifier using PWObjectTypeGet prior to registering it.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWObjectType PWObjectTypeRegister( const CWString& companyName_,
                                                      const CWString& moduleName_,
                                                      const CWString& objectName_ );


} // namespace IM
