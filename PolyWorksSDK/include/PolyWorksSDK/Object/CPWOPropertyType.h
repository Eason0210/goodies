#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWOPropertyType.h
///    \brief    Type of a PolyWorks Object property.
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
///    \brief    Enumeration making CPWOPropertyType unique.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
enum EIPWOPropertyTypeUnique {};

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_TYPEDEFS
///
///    \brief    Unique type of a PolyWorks Object property type.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef CTrueTypedef< unsigned int, EIPWOPropertyTypeUnique > CPWOPropertyType;

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Tells whether the input PolyWorks Object property type is valid or not.
///
///    \param[ in ] PWOPropertyType_    PolyWorks Object property type to be tested
///
///    \return    true if the PolyWorks Object property type is valid, false otherwise
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API bool IsPWOPropertyTypeValid( const CPWOPropertyType& PWOPropertyType_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the type of PolyWorks Object property associated to the input strings. Note
///              that the PolyWorks Object property must have been registered through the IPWObjects::PWOPropertyTypeRegister
///              method prior to calling this method.
///
///    \param[ in ] companyName_     Your company name
///    \param[ in ] moduleName_      Your module name (plug-in name)
///    \param[ in ] propertyName_    The object's name
///
///    \return    Constant representing the already registered PolyWorks Object property type.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyTypeGet( const CWString& companyName_,
                                                       const CWString& moduleName_,
                                                       const CWString& propertyName_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Registers a new PolyWorks Object property into the PolyWorks SDK. The same object
///              cannot be registered more than one time.
///
///    \param[ in ] companyName_     Your company name
///    \param[ in ] moduleName_      Your module name (plug-in name)
///    \param[ in ] propertyName_    The PolyWorks Object property name
///
///    \return    Constant representing the newly registered PolyWorks Object property Type. If there
///               is  already an property registered using the three input string, it's type will
///               be returned. It is your responsability to verify whether there exists a property
///               having the same identifier using PWOPropertyTypeGet prior to registering it.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyTypeRegister( const CWString& companyName_,
                                                            const CWString& moduleName_,
                                                            const CWString& propertyName_ );


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object color property type. The property is of IM::CColorRGBA
///              type.
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyColorTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object data property type. The property is of bool type.
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyDataTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object elements type.
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyElementPropertiesTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object focus property type. The property is of bool type.
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyFocusedTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object name property type.The property is of IM::CWString type.
///
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyNameTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object reference property type. The property is of bool type.
///
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyReferenceTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object selection property type. The property is of bool type.
///
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertySelectedTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object transformation property type. The property is of IM::CMatrix4
///              type.
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyTransformationTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object usage property type. The property is of bool type.
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyUsedTypeGet();


////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Returns the PolyWorks Object visibility property type. The property is of bool type.
///
///
///    \return    The type of the property. Might be invalid (determined by IsPWOPropertyTypeValid)
///               in the case that the property is not available in the current module.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API CPWOPropertyType PWOPropertyVisibleTypeGet();


} // namespace IM
