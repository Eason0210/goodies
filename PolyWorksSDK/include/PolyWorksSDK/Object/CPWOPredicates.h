#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWOPredicates.h
///    \brief    CPWOPredicates class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>
#include <PolyWorksSDK/Base/Size.h>

#include "FnCPWOPredicates.h" // IWYU pragma: keep

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CPWOPredicatesImpl;
class IPWOPredicate;
class IPWObject;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_CLASSES
///
///    \brief    Class used to contain a collection of IPWOPredicates linked together by logical AND
///              and OR operations. Note that you do not need to explicitly use this class to create
///              a IPWOPredicates collection; we strongly recommend that you use the operators available
///              in FnCPWOPredicates.h which will create implicitly the resulting CPWOPredicates
///              object.
///              This will result in a much more readable code.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CPWOPredicates
{
    friend const IM::CPWOPredicates IM::operator||( const IM::CPWOPredicates& lhs_, const IM::CPWOPredicates& rhs_ );
    friend const IM::CPWOPredicates IM::operator&&( const IM::CPWOPredicates& lhs_, const IM::CPWOPredicates& rhs_ );

public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOPredicates();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor taking a given predicate as a starting point for the predicates collection.
    ///
    ///
    ///    \param[ in ] predicate_    First predicate to be added to the collection.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOPredicates( const IPWOPredicate& predicate_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor
    ///
    ///    \param[ in ] rhs_    Right hand side predicates to be equaled
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOPredicates( const CPWOPredicates& rhs_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CPWOPredicates();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Equals the current object with the right hand side predicates.
    ///
    ///    \param[ in ] rhs_    Right hand side predicates to be equaled
    ///
    ///    \return    Reference to the current object
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOPredicates& operator=( const CPWOPredicates& rhs_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Evaluates all the predicates listed under the current object. The predicates are
    ///              also sorted in order of their complexity when it is possible, depending on the AND
    ///              and OR operations, (see IPWOPredicate::Evaluate for more information on predicates
    ///              complexity) from the quickest to the slowest.
    ///
    ///    \param[ in ] pPWObject_    Pointer to the PolyWorks object to be tested.
    ///
    ///    \return    true if the input PolyWorks Object satisfies this predicate collection or if there
    ///               are no predicates in the collection.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool Evaluate( const IPWObject* pPWObject_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the number of predicates in the current predicates collection.
    ///
    ///    \return    Number of predicates in the current predicates collection.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    TSize Size() const;

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    CPWOPredicates( CPWOPredicatesImpl* pPWOPredicatesImpl_ );

    // ---------------- Private Member Variables ---------------------------------------------------

    CPWOPredicatesImpl* m_pPWOPredicatesImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
