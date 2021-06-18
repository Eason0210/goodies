// =================================================================================================
//   Constants used by the plug-in implementation.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CompanyNameConst.h"

#include <algorithm>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

const wchar_t* const PLUGIN_NAME = L"CompanyName Notification Handler";  // The name should not be longer than 31 characters

const std::wstring g_OnOffChoiceStrings[ E_OO_NB_VALUES ] =
{
    L"On",
    L"Off",
    L"Toggle"
};

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

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

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

DWORD g_cookieCommandCenter = 0;

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   OnOffConvertStringToEnum
//
// Parameter: argValue : On/Off string to convert
//
// Return : On/Off Choice
// -------------------------------------------------------------------------------------------------
EOnOffChoice OnOffConvertStringToEnum( const std::wstring& argValue )
{
    EOnOffChoice choiceToReturn = E_OO_INVALID;
    CTCaseInsensitiveComparator< std::wstring > caseInsensitiveComparator( argValue );
    for ( int iValue = 0; iValue < E_OO_NB_VALUES; iValue++ )
    {
        if ( caseInsensitiveComparator( g_OnOffChoiceStrings[ iValue ] ) )
        {
            choiceToReturn = static_cast< EOnOffChoice >( iValue );
            break;
        }
    }

    return choiceToReturn;
}


// =================================================================================================
//   OnOffGetPossibleValuesString
//
// Return : On/Off string
// -------------------------------------------------------------------------------------------------
std::wstring OnOffGetPossibleValuesString()
{
    std::wstring values = L"\"";
    for ( int iValue = 0; iValue < E_OO_NB_VALUES; iValue++ )
    {
        values += g_OnOffChoiceStrings[ iValue ];
        values += L"\"";
        if ( iValue != E_OO_NB_VALUES - 1 )
        {
            values += L", \"";
        }
    }

    return values;
}
