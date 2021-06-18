#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWOElementsTypes.h
///    \brief    CPWOElementsTypes class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "PolyWorksSDK/Object/FnCPWOElementsTypes.h"
#include "PolyWorksSDK/Base/PolyWorksSDKApi.h"
#include "PolyWorksSDK/Object/internal/../CPWOElementsType.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CPWOElementsTypesImpl;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_CLASSES
///
///    \brief    Class used to contain a collection of CPWOElementsType linked together by logical
///              AND and NOT operations. Note that you do not need to explicitly use this class to
///              create a CPWOElementsTypes collection; we strongly recommend that you use the operators
///              available in FnCPWOElementsTypes.h which will create implicitly the resulting CPWOPredicates
///              object. This will result in a much more readable code.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CPWOElementsTypes
{
    friend class CPWOElements;
    friend const CPWOElementsTypes IM::operator&&( const CPWOElementsTypes& lhs_, const CPWOElementsTypes& rhs_ );
    friend const CPWOElementsTypes IM::operator!( const CPWOElementsTypes& rhs_ );

public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOElementsTypes();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constructor taking a given type as a starting point for the type of elements collection.
    ///
    ///
    ///    \param[ in ] type_    First type of elements to be added to the collection.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOElementsTypes( const CPWOElementsType& type_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor.
    ///
    ///    \param[ in ] rhs_    The type of elements collection to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOElementsTypes( const CPWOElementsTypes& rhs_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CPWOElementsTypes();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator.
    ///
    ///    \param[ in ] rhs_    The type of elements collection to be copied.
    ///
    ///    \return    Reference to the current object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWOElementsTypes& operator=( CPWOElementsTypes& rhs_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------
    CPWOElementsTypes( CPWOElementsTypesImpl* pPWOElementsTypesImpl_ );

    // ---------------- Private Member Variables ---------------------------------------------------
    CPWOElementsTypesImpl* m_pImpl;

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
