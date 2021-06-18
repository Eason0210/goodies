#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPWOPredicate.h
///    \brief    IPWOPredicate interface class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CPWOPredicates.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class IPWObject;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_ENUMERATIONS
///
///    \brief    Types of a PolyWorks Object predicate complexity. These types define the order in
///              which the predicates will be evaluated. They are presented in order of speed of
///              calculation (from the quickest to the slowest). You must use those types in conjunction
///              with your IPWOPredicate derived class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
enum EPWOPredicateComplexity
{
    E_PWO_PREDICATE_COMPLEXITY_INSTANTANEOUS = 0u,  /*!< Complexity of a predicate who's evaluation is completed instantly.  For example,
                                                         the following predicates have this complexity:
                                                         - CPWOPredicatePWOType */
    E_PWO_PREDICATE_COMPLEXITY_LOW           = 25u, /*!< Complexity of a predicate who's evaluation requires some simple calculations.
                                                         For example, the following predicates have this complexity:
                                                         - CPWOPredicatePWOPropertyType
                                                         - CPWOPredicatePWOPropertyValue
                                                     */
    E_PWO_PREDICATE_COMPLEXITY_MEDIUM        = 50u, /*!< Complexity of a predicate who's evaluation requires some calculations. */
    E_PWO_PREDICATE_COMPLEXITY_HIGH          = 75u, /*!< Complexity of a predicate who's evaluation requires complex calculations. */
    E_PWO_PREDICATE_COMPLEXITY_CPU_INTENSIVE = 99u  /*!< Complexity of a predicate who's evaluation requires intensive CPU usage. */
};

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///    \brief    Class used to define a predicate used to obtain PolyWorks objects.
////////////////////////////////////////////////////////////////////////////////////////////////////
class IPWOPredicate
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPWOPredicate() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPWOPredicate() {}

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the complexity level of the current predicate. The complexity level of a
    ///              predicate defines the speed at which it evaluates the input object. This complexity
    ///              level will be used by CPWOPredicates to sort the predicates collection. Lower complexity
    ///              predicates will be evaluated first and higher complexity predicates at the end.
    ///
    ///              Note that a given predicate must always return the exact same level of complexity.
    ///
    ///    \return    Complexity level of the current predicate.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual EPWOPredicateComplexity ComplexityLevelGet() const = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a duplicated PolyWorks Object predicate.
    ///
    ///    \return    Pointer to the duplicated predicate.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual IPWOPredicate* Duplicate() const = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Tells whether the input PolyWorks Object satisfies the predicate.
    ///
    ///    \param[ in ] pPWObject_    Pointer to the PolyWorks Object to test.
    ///
    ///    \return    true if the PolyWorks Object satisfies the predicate, false if not satisfy it
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual bool Evaluate( const IPWObject* pPWObject_ ) = 0;

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
