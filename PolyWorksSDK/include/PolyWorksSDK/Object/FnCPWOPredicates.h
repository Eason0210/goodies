#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     FnCPWOPredicates.h
///    \brief    This file contains the declaration of the operators that can be applied to IPWOPredicate
///              and CPWOPredicates objects
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CPWOPredicates;

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
///    \brief    Joins together two collections of predicates in a OR operation. The function returns
///              a list of ORed predicate collections.
///
///              Note that a IM::CPWOPredicates object can be created implicitly from a IPWOPredicate derived class.
///
///              Example:
///              \code{.cpp}
///              // Iterator request where all input parameters are IPWOPredicate derived objects
///              // The result is that you will be iterating on objects satisfying your logical predicates
///              // expression.
///              pPWObjects->Begin( myPred0 || myPred1 && ( myPred0 || myPred2 ) );
///              \endcode
///
///    \param[ in ] lhs_    The first collection of predicates of the OR operation
///    \param[ in ] rhs_    The second collection of predicates of the OR operation
///
///    \return    List of ORed predicate collections.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPWOPredicates operator||( const CPWOPredicates& lhs_, const CPWOPredicates& rhs_ );

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_FUNCTIONS
///
///    \brief    Joins together two collections of predicates in a AND operation. The function returns
///              a list of ANDed predicate collections.
///
///              Note that a IM::CPWOPredicates object can be created implicitly from a IPWOPredicate derived class.
///
///              Example:
///              \code{.cpp}
///              // Iterator request where all input parameters are IPWOPredicate derived objects
///              // The result is that you will be iterating on objects satisfying your logical predicates
///              // expression.
///              pPWObjects->Begin( myPred0 || myPred1 && ( myPred0 || myPred2 ) );
///              \endcode
///
///    \param[ in ] lhs_    The first collection of predicates of the AND operation
///    \param[ in ] rhs_    The second collection of predicates of the AND operation
///
///    \return    List of ANDed predicate collections.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
POLYWORKS_SDK_API const CPWOPredicates operator&&( const CPWOPredicates& lhs_, const CPWOPredicates& rhs_ );

} // namespace IM
