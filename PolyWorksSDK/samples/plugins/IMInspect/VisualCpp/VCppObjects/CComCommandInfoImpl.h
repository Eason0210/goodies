#pragma once

// =================================================================================================
// Class describing a COM command
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <string>
#include <vector>

#include "CComCommandParameterEnum.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ===================================== CONSTANTES, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =============================================================================
// COM command class description implementation
// A description and a name must at least be specified
// Otherwise, only needed members require initialisation
// -----------------------------------------------------------------------------

class CComCommandInfoImpl
{
public:

    CComCommandInfoImpl( const std::wstring& name_, const std::wstring& desc_ );
    ~CComCommandInfoImpl();

    std::wstring m_name;                                        // Name
    std::wstring m_desc;                                        // Description
    std::wstring m_note;                                        // Note to be added to description
    std::wstring m_menuLocation;                                // Menu item location
    std::wstring m_menuDesc;                                    // Menu item description
                                                                // (if empty, command description is used)
    std::vector< std::wstring > m_deprecatedNames;              // Deprecated names of the command
                                                                // (as long as parameter list have not changed)
    bool         m_isObsolete;                                  // True if the command is obsolete
    std::wstring m_supersedingCommand;                          // Indicate which command have replaced this obsolete command
                                                                // (empty if no command replace this obsolete command)
    CComCommandParameterEnum m_parameterEnum;                   // Enumeration of command parameters

private:

    CComCommandInfoImpl( CComCommandInfoImpl& info_ );
    const CComCommandInfoImpl& operator=( const CComCommandInfoImpl& );
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
