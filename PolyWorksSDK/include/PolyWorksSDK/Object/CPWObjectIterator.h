#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CPWObjectIterator.h
///    \brief    CPWObjectIterator class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

namespace IM { class IPWObject; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CPWObjectIteratorImpl;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_ClASSES
///
///    \brief    Iterator on PolyWorks Objects. This type of iterator can only be created from the
///              IPWObjects class.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CPWObjectIterator
{
    friend class CIPWObjects;

public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor. Create an iterator from an existing one.
    ///
    ///    \param[ in ] rhs_    The iterator to be copied.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWObjectIterator( const CPWObjectIterator& rhs_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CPWObjectIterator();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy operator.
    ///
    ///    \param[ in ] rhs_    The iterator to be copied.
    ///
    ///    \return    A reference to the current iterator to allow chaining of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWObjectIterator& operator=( const CPWObjectIterator& rhs_ );

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Equality operator for iterators. Indicate if the two iterators are positioned at
    ///              the same PolyWorks Object.
    ///
    ///    \param[ in ] rhs_    The iterator to be compared.
    ///
    ///    \return    Indicate if the iterators are positioned at the same PolyWorks Object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator==( const CPWObjectIterator& rhs_ ) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Inequality operator for iterators. Indicate if the two iterators are positioned at
    ///              different PolyWorks Object.
    ///
    ///    \param[ in ] rhs_    The iterator to be compared.
    ///
    ///    \return    Indicate if the iterators are positioned at different PolyWorks Object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator!=( const CPWObjectIterator& rhs_ ) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Prefix increment operator. Moves the iterator the next PolyWorks Object.
    ///
    ///    \return    A reference to the current iterator which has been incremented to allow chaining
    ///               of operations.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CPWObjectIterator& operator++();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Dereference operator. Gives access to the PolyWorks Object found at the iterator's
    ///              position.
    ///
    ///    \return    A reference to the PolyWorks Object found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPWObject& operator*() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Member access operator. Simplify the access of the PolyWorks Object's member functions
    ///              when using iterators.
    ///
    ///    \return    A pointer to the PolyWorks Object found at the iterator's position.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPWObject* operator->() const;

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------
    CPWObjectIterator( CPWObjectIteratorImpl* pImpl_ );

    // ---------------- Private Member Variables ---------------------------------------------------
    CPWObjectIteratorImpl* m_pImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
