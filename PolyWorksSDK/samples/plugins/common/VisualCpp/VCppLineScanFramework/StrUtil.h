#pragma once

// =================================================================================================
// String utilities.
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

inline
const char* StrNonNull( const char* pStr_ )
{
    return pStr_ != nullptr ? pStr_ : "";
}

inline
const wchar_t* StrNonNull( const wchar_t* pStr_ )
{
    return pStr_ != nullptr ? pStr_ : L"";
}

template< class TString >
class CTCaseInsensitiveComparator
{
public:
    CTCaseInsensitiveComparator( const TString& firstStr_ )
    {
        // Transform first string to upper case
        m_firstStr.resize( firstStr_.size() );
        // Some people reported compiler issues with toupper, so we use static_cast to remove any type ambiguity
        std::transform( firstStr_.begin(), firstStr_.end(), m_firstStr.begin(), static_cast< int ( * )( int ) >( toupper ) );
    }

    bool operator()( const TString& secondStr_ ) const
    {
        // Transform second string to upper case
        TString secondStr;
        secondStr.resize( secondStr_.size() );
        // Some people reported compiler issues with toupper, so we use static_cast to remove any type ambiguity
        std::transform( secondStr_.begin(), secondStr_.end(), secondStr.begin(), static_cast< int ( * )( int ) >( toupper ) );

        // Compare strings
        return m_firstStr == secondStr;
    }

private:
    TString m_firstStr;
};
