#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPWOProperty.h
///    \brief    IPWOProperty interface.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Object/CPWOPropertyType.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CColorRGBA;
class CMatrix4;
class CWString;
class IPWOElementsProperties;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_INTERFACES
///
///    \brief    Interface of a PolyWorks Object property. A property is defined as any attribute
///              that is not representable geometrically. For example, a property could be: visibility,
///              selection status, transformation matrix or the object's color.
///
///              The value of a property can be retreived using the right version of ValueGet.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPWOProperty
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPWOProperty() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPWOProperty() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the unique type of a PolyWorks Object's property.
    ///
    ///    \return    Unique type of a PolyWorks Object's property
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CPWOPropertyType TypeGet() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the value of the property as a bool variable.
    ///
    ///    \param[ out ] value_    Value of the property
    ///
    ///    \return    true if the property is a bool, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool ValueGet( bool& value_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the value of the property as a CColorRGBA variable.
    ///
    ///    \param[ out ] value_    Value of the property
    ///
    ///    \return    true if the property is a CColorRGBA, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool ValueGet( CColorRGBA& value_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the value of the property as a CMatrix4 variable.
    ///
    ///    \param[ out ] value_    Value of the property
    ///
    ///    \return    true if the property is a CMatrix4, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool ValueGet( CMatrix4& value_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the value of the property as a CWString variable.
    ///
    ///    \param[ out ] value_    Value of the property
    ///
    ///    \return    true if the property is a CWString, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool ValueGet( CWString& value_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the value of the property as a IPWOElementsProperties pointer.
    ///
    ///    \param[ out ] value_    Value of the property
    ///
    ///    \return    true if the property is a IPWOElementsProperties pointer, false otherwise.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool ValueGet( IPWOElementsProperties*& value_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the value of the property as a double variable.
    ///
    ///    \param[ out ] value_    Value of the property
    ///
    ///    \return    true if the property is a double, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool ValueGet( double& value_ ) const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the value of the property as a int variable.
    ///
    ///    \param[ out ] value_    Value of the property
    ///
    ///    \return    true if the property is a int, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool ValueGet( int& value_ ) const = 0;


protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
