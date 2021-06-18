#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CTrueTypedef.h
///    \brief    CTrueTypedef class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

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
///     \brief Class implementing "True Typedefs", C++ typedef acts more as an alias than a new type
///            definition. This class intends to solve this problem. CTrueTypedef is parametrized with T which
///            is the base type you want to give to your typedef ans U which is the unique type that ensures
///            the uniqueness of the type definition.
///
///            A compilation error is generated if you try to equal variables of TObjectType type and
///            TGeometryType type.
///
///            Example:
///            \code{.cpp}
///            enum ETObjectTypeUnique{};
///            typedef IM::CTrueTypedef< int, ETObjectTypeUnique > TObjectType;
///            enum ETGeometryTypeUnique{};
///            typedef IM::CTrueTypedef< int, ETGeometryTypeUnique > TGeometryType;
///            \endcode
///
///            Parameter: T : Type of your true typedef. You may use int or short for example.
///            Parameter: U : Parameter making your CTrueTypedef unique. Use an empty enum.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
template< typename T, typename U >
class CTrueTypedef
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Reference class type T.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef T& TValueReference;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Constant reference class type T.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef const T& TValueConstReference;

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor initializing the value to it's default value.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CTrueTypedef()
    : m_value( T() )
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Explicit copy constructor preventing the implicit creation CTrueTypedef from it's
    ///              templatized paremeter T which would have break the uniqueness of those typedefs.
    ///
    ///    \param[ in ] value_    Value to assing to m_value
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    explicit CTrueTypedef( T const& value_ )
    : m_value( value_ )
    {
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Copy constructor on CTrueTypedef.
    ///
    ///    \param[ in ] rhs_    Right-hand side object to assigne to the current one.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CTrueTypedef( const CTrueTypedef& rhs_ )
    : m_value( rhs_.m_value )
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Operator equals on CTrueTypedef.
    ///
    ///    \param[ in ] rhs_    Right-hand side object to assigne to the current one.
    ///
    ///    \return    Const reference to this.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const CTrueTypedef< T, U >& operator=( const CTrueTypedef& rhs_ )
    {
        m_value = rhs_.m_value;
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Tests whether two CTrueTypedef objects are equal.
    ///
    ///    \param[ in ] rhs_    Right-hand side of the equality test
    ///
    ///    \return    true if the two objects are equal, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator==( const CTrueTypedef& rhs_ ) const
    {
        return m_value == rhs_.m_value;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Tests whether two CTrueTypedef objects are not equal.
    ///
    ///    \param[ in ] rhs_    Right-hand side of the inequality test
    ///
    ///    \return    true if the two objects are not equal, false otherwise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator!=( const CTrueTypedef& rhs_ ) const
    {
        return m_value != rhs_.m_value;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Tests whether this CTrueTypedef is smaller than it's right-hand side.
    ///
    ///    \param[ in ] rhs_    Right-hand side of the test
    ///
    ///    \return    true this object is smaller, false otherwhise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator<( const CTrueTypedef& rhs_ ) const
    {
        return m_value < rhs_.m_value;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Tests whether this CTrueTypedef is greater than it's right-hand side.
    ///
    ///    \param[ in ] rhs_    Right-hand side of the test
    ///
    ///    \return    true this object is greater, false otherwhise
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    bool operator>( const CTrueTypedef& rhs_ ) const
    {
        return m_value > rhs_.m_value;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Accessor giving a const reference on the internal value of the class.
    ///
    ///    \return    Const reference on the internal value of the class.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    typename TValueConstReference ValueGet() const
    {
        return m_value;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Accessor giving a reference on the internal value of the class.
    ///
    ///    \return    Reference on the internal value of the class.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    typename TValueReference ValueGet()
    {
        return m_value;
    }

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    const CTrueTypedef& operator=( const T& );

    // ---------------- Private Member Variables ---------------------------------------------------

    T m_value;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
