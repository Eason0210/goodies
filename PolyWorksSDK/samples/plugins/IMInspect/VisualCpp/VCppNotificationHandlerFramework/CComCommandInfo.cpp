// =================================================================================================
// Implementation of the class describing a COM command
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CComCommandInfo.h"

#include <PolyWorksSDK/COM/IIMCommandParameter.h>
#include <atlcomcli.h>

#include "CComCommandInfoImpl.h"
#include "StrUtil.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =============================================================================
// Constructor
//
// Parameter: name_    : Name
// Parameter: desc_    : Description
// -----------------------------------------------------------------------------
CComCommandInfo::CComCommandInfo(
    const IM::CWString& name_,
    const IM::CWString& desc_ )
{
    m_pImpl = new CComCommandInfoImpl( StrNonNull( name_ ), StrNonNull( desc_ ) );
}

// =============================================================================
// Copy constructor
//
// Parameter: info_ : Object to be copied
// -----------------------------------------------------------------------------
CComCommandInfo::CComCommandInfo( CComCommandInfo& info_ )
{
    m_pImpl = new CComCommandInfoImpl( StrNonNull( info_.NameGet() ), StrNonNull( info_.DescGet() ) );

    m_pImpl->m_note               = StrNonNull( info_.NoteGet() );
    m_pImpl->m_menuLocation       = StrNonNull( info_.MenuLocationGet() );
    m_pImpl->m_menuDesc           = StrNonNull( info_.MenuDescGet() );
    m_pImpl->m_isObsolete         = info_.IsObsoleteGet();
    m_pImpl->m_supersedingCommand = StrNonNull( info_.SupersedingCommandGet() );

    // Copying old names
    unsigned int nbNames = info_.DeprecatedNamesGetNb();
    for ( unsigned int iName = 0; iName < nbNames; iName++ )
    {
        DeprecatedNameAdd( StrNonNull( info_.DeprecatedNameGet( iName ) ) );
    }

    // Copying parameters
    long nbParams = 0;

    CComPtr< IIMCommandParameter > pParam;

    CComCommandParameterEnum& paramEnum = info_.ParameterEnumGet();
    paramEnum.ParamsGetNb( &nbParams );
    for ( long iParam = 0; iParam < nbParams; iParam++ )
    {
        paramEnum.ParamGet( iParam, &pParam );
        if ( pParam != nullptr )
        {
            m_pImpl->m_parameterEnum.CommandParameterAdd( pParam );
        }
    }
}

// =============================================================================
// Destructor
// -----------------------------------------------------------------------------
CComCommandInfo::~CComCommandInfo()
{
    if ( m_pImpl != nullptr )
    {
        delete m_pImpl;
        m_pImpl = nullptr;
    }
}

// =================================================================================================
// Members access methods
// -------------------------------------------------------------------------------------------------
IM::CWString CComCommandInfo::NameGet() const
{
    return m_pImpl->m_name.c_str();
}

void CComCommandInfo::NameSet( const IM::CWString& name_ )
{
    m_pImpl->m_name = StrNonNull( name_ );
}

IM::CWString CComCommandInfo::DescGet() const
{
    return m_pImpl->m_desc.c_str();
}

void CComCommandInfo::DescSet( const IM::CWString& desc_ )
{
    m_pImpl->m_desc = StrNonNull( desc_ );
}

IM::CWString CComCommandInfo::NoteGet() const
{
    return m_pImpl->m_note.c_str();
}

void CComCommandInfo::NoteSet( const IM::CWString& note_ )
{
    m_pImpl->m_note = StrNonNull( note_ );
}

IM::CWString CComCommandInfo::MenuLocationGet() const
{
    return m_pImpl->m_menuLocation.c_str();
}

void CComCommandInfo::MenuLocationSet( const IM::CWString& menuLocation_ )
{
    m_pImpl->m_menuLocation = StrNonNull( menuLocation_ );
}

IM::CWString CComCommandInfo::MenuDescGet() const
{
    return m_pImpl->m_menuDesc.c_str();
}

void CComCommandInfo::MenuDescSet( const IM::CWString& menuDesc_ )
{
    m_pImpl->m_menuDesc = StrNonNull( menuDesc_ );
}

unsigned int CComCommandInfo::DeprecatedNamesGetNb() const
{
    return static_cast< unsigned int >( m_pImpl->m_deprecatedNames.size() );
}

IM::CWString CComCommandInfo::DeprecatedNameGet( unsigned int index_ ) const
{
    return ( m_pImpl->m_deprecatedNames[ index_ ] ).c_str();
}

void CComCommandInfo::DeprecatedNameAdd( const IM::CWString& deprecatedName_ )
{
    // Making sure we have a valid string
    if ( ( deprecatedName_ != ( wchar_t* ) nullptr ) &&
         ( wcslen( deprecatedName_ ) > 0 ) )
    {
        m_pImpl->m_deprecatedNames.emplace_back( static_cast< const wchar_t* >( deprecatedName_ ) );
    }
}

bool CComCommandInfo::IsObsoleteGet() const
{
    return m_pImpl->m_isObsolete;
}

void CComCommandInfo::IsObsoleteSet( bool isObsolete_ )
{
    m_pImpl->m_isObsolete = isObsolete_;
}

IM::CWString CComCommandInfo::SupersedingCommandGet() const
{
    return m_pImpl->m_supersedingCommand.c_str();
}

void CComCommandInfo::SupersedingCommandSet( const IM::CWString& cmdName_ )
{
    m_pImpl->m_supersedingCommand = StrNonNull( cmdName_ );
}

CComCommandParameterEnum& CComCommandInfo::ParameterEnumGet()
{
    return m_pImpl->m_parameterEnum;
}
