#pragma once

// =================================================================================================
//   Settings data structure.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <assert.h>
#include <string>
#include <vector>

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

template< class TType >
class CTSetting
{
public:
    using TStdProfileValues = std::vector< TType >;

    CTSetting(
        std::wstring name_,
        TType        defaultValue_,
        bool         isUserSpecific_,
        bool         isHostSpecific_ )
    : m_name( name_ )
    , m_defaultValue( defaultValue_ )
    , m_isUserSpecific( isUserSpecific_ )
    , m_isHostSpecific( isHostSpecific_ )
    {}

    CTSetting(
        std::wstring      name_,
        TStdProfileValues stdProfileValues,
        bool              isUserSpecific_,
        bool              isHostSpecific_ )
    : m_name( name_ )
    , m_defaultValue( ( stdProfileValues.size() == E_LAST_STD_SCAN_PROFILE + 1 ) ? stdProfileValues[ E_STD_SCAN_PROFILE_STANDARD_RES ] : TType() )
    , m_isUserSpecific( isUserSpecific_ )
    , m_isHostSpecific( isHostSpecific_ )
    {
        if ( stdProfileValues.size() != E_LAST_STD_SCAN_PROFILE + 1 )
        {
            assert( 0 );   // Unknown profile!
            return;
        }

        for ( int iProfile = E_FIRST_STD_SCAN_PROFILE; iProfile <= E_LAST_STD_SCAN_PROFILE; ++iProfile )
        {
            if ( ( iProfile >= 0 ) && ( static_cast< size_t >( iProfile ) < stdProfileValues.size() ) )
            {
                m_stdProfileValues.emplace_back( stdProfileValues[ iProfile ] );
            }
        }
    }

    bool IsProfileSetting() const
    {
        return !m_stdProfileValues.empty();
    }

    std::wstring      m_name;
    TType             m_defaultValue;
    TStdProfileValues m_stdProfileValues; // Values for standard scanning profiles
    bool              m_isUserSpecific;
    bool              m_isHostSpecific;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
