#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWOPredicatePWOType.h
///    \brief    CPWOPredicatePWOType class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "PolyWorksSDK/Base/PolyWorksSDKApi.h"

#include "PolyWorksSDK/Object/CPWObjectType.h"
#include "PolyWorksSDK/Object/IPWOPredicate.h"


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
///    \brief    Predicate checking if a given IPWObject is of a certain CPWObjectType.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CPWOPredicatePWOType : public IPWOPredicate
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor taking a type as an argument.
    ///
    ///    \param[ in ] objectType_    Type of PolyWorks Object
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOPredicatePWOType( const CPWObjectType& objectType_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~CPWOPredicatePWOType();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the complexity level of this predicate. This predicate has a complexity of
    ///              E_PWO_PREDICATE_COMPLEXITY_INSTANTANEOUS.
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
    ///    \brief    Checks whether the input PolyWorks Object is of the type specified at the predicate
    ///              construction.
    ///
    ///    \param[ in ] pPWObject_    Pointer to the object to evaluate.
    ///
    ///    \return    true if the input object is of the same type as the predicate, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool Evaluate( const IPWObject* pPWObject_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    CPWObjectType m_type;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
