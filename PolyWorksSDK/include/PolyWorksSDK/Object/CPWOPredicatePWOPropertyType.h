#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWOPredicatePWOPropertyType.h
///    \brief    CPWOPredicatePWOPropertyType class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "PolyWorksSDK/Base/PolyWorksSDKApi.h"
#include "PolyWorksSDK/Object/IPWOPredicate.h"
#include "PolyWorksSDK/Object/IPWOProperty.h"


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
///    \ingroup  IM_CLASSES
///
///    \brief    Predicate checking if a given IPWObject has a property of a certain CPWOPropertyType
///              type.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CPWOPredicatePWOPropertyType : public IPWOPredicate
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor taking a property type as an argument.
    ///
    ///    \param[ in ] type_    Type of PolyWorks Object's property
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOPredicatePWOPropertyType( CPWOPropertyType type_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~CPWOPredicatePWOPropertyType();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the complexity level of this predicate. This predicate has a complexity of
    ///              E_PWO_PREDICATE_COMPLEXITY_LOW.
    ///
    ///    \return    Complexity level of this predicate.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual EPWOPredicateComplexity ComplexityLevelGet() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a duplicate of the current object.
    ///
    ///    \return    Pointer to the newly duplicated predicate
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual IPWOPredicate* Duplicate() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Checks whether the input PolyWorks Object has a property of the type specified at
    ///              the predicate construction.
    ///
    ///    \param[ in ] pPWObject_    Pointer to the object to evaluate.
    ///
    ///    \return    true if the input object has a property of the same type as the predicate,  false
    ///               otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool Evaluate( const IPWObject* pPWObject_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    CPWOPropertyType m_type;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
