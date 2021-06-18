#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCPWOPredicatePWOPropertyValue.h
///    \brief    Functions simplifying the creation of CPWOPredicatePWOPropertyValue.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CPWOPredicatePWOPropertyValue.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

template< class TType >
class CPWOPredicatePWOPropertyValue;

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
///    \brief    Small template function simplifying the creation of CPWOPredicatePWOPropertyValue
///              objects. This free function has the advantage of not having to speficy the template
///              arguments has it is automatically deduced.  Parameter: type_  : Type of the PolyWorks
///              Object's property Parameter: value_ : Value of the property
///
///    \return    Newly created CPWOPredicatePWOPropertyValue object.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
template< class TType >
CPWOPredicatePWOPropertyValue< TType > MakePWOPredicatePWOPropertyValue( CPWOPropertyType type_,
                                                                         TType            value_ )
{
    return CPWOPredicatePWOPropertyValue< TType >( type_, value_ );
}

} // namespace IM
