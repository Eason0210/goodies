#pragma once

// =================================================================================================
// Class describing a COM command parameter
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/COM/IMTypes.h>
#include <string>

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ===================================== CONSTANTES, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =============================================================================
// COM command parameter class description implementation
// A description, a direction and a type must at least be specified
// Otherwise, only needed members require initialisation
// -----------------------------------------------------------------------------
class CComCommandParameterInfoImpl
{
public:
    CComCommandParameterInfoImpl( const std::wstring& desc_, EParameterDirection dir_, EParameterType type_ );
    CComCommandParameterInfoImpl( CComCommandParameterInfoImpl& info_ );
    ~CComCommandParameterInfoImpl();

    std::wstring        m_desc;                     // Description
    std::wstring        m_values;                   // Possible values (in a string, separated by comas)
    EParameterDirection m_dir;                      // Direction
    EParameterType      m_type;                     // Type
    bool                m_hasDoubleDefaultValue;    // True if parameter have a default double value
    double              m_doubleDefaultValue;       // Default value for double parameter
    bool                m_hasIntDefaultValue;       // True if parameter have a default integer value
    int                 m_intDefaultValue;          // Default value for integer parameter
    bool                m_hasStringDefaultValue;    // True if parameter have a default string value
    std::wstring        m_stringDefaultValue;       // Default value for string parameter
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
