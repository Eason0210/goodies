#pragma once

// =================================================================================================
// Class describing a COM command
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CWString.h>

class CComCommandInfoImpl;

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CComCommandParameterEnum;

// =================================================================================================
// ===================================== CONSTANTES, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =============================================================================
// COM command class description implementation
// A description and a name must at least be specified
// Otherwise, only needed members require initialisation
// -----------------------------------------------------------------------------

class CComCommandInfo
{
public:

    CComCommandInfo( const IM::CWString& name_, const IM::CWString& desc_ );
    CComCommandInfo( CComCommandInfo& info_ );
    ~CComCommandInfo();

    // Name
    IM::CWString NameGet() const;
    void         NameSet( const IM::CWString& name_ );

    // Description
    IM::CWString DescGet() const;
    void         DescSet( const IM::CWString& desc_ );

    // Note to be added to description
    IM::CWString NoteGet() const;
    void         NoteSet( const IM::CWString& note_ );

    // Menu item location
    IM::CWString MenuLocationGet() const;
    void         MenuLocationSet( const IM::CWString& menuLocation_ );

    // Menu item description
    // (if empty, command description is used)
    IM::CWString MenuDescGet() const;
    void         MenuDescSet( const IM::CWString& menuDesc_ );

    // Deprecated names of the command
    // (as long as parameter list have not changed)
    unsigned int DeprecatedNamesGetNb() const;
    IM::CWString DeprecatedNameGet( unsigned int index_ ) const;
    void         DeprecatedNameAdd( const IM::CWString& deprecatedName_ );

    // True if the command is obsolete
    bool IsObsoleteGet() const;
    void IsObsoleteSet( bool isObsolete_ );

    // Indicate which command have replaced this obsolete command
    // (empty if no command replace this obsolete command)
    IM::CWString SupersedingCommandGet() const;
    void         SupersedingCommandSet( const IM::CWString& cmdName_ );

    // Enumeration of command parameters
    CComCommandParameterEnum& ParameterEnumGet();

private:

    const CComCommandInfo& operator=( const CComCommandInfo& );

    CComCommandInfoImpl* m_pImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
