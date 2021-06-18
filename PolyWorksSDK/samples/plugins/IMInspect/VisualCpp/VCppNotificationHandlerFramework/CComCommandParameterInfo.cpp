// =================================================================================================
// Class describing a COM command parameter
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CComCommandParameterInfo.h"

#include "CComCommandParameterInfoImpl.h"
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
// Parameter: desc_ : Description
// Parameter: dir_  : Direction
// Parameter: type_ : Type
// -----------------------------------------------------------------------------
CComCommandParameterInfo::CComCommandParameterInfo(
    const IM::CWString& desc_,
    EParameterDirection dir_,
    EParameterType      type_ )
{
    m_pImpl = new CComCommandParameterInfoImpl( StrNonNull( desc_ ), dir_, type_ );
}

// =============================================================================
// Copy constructor
//
// Parameter: info_ : Object to be copied
// -----------------------------------------------------------------------------
CComCommandParameterInfo::CComCommandParameterInfo( CComCommandParameterInfo& info_ )
{
    m_pImpl = new CComCommandParameterInfoImpl( StrNonNull( info_.DescGet() ), info_.DirGet(), info_.TypeGet() );
    ValuesSet( info_.ValuesGet() );
    HasDoubleDefaultValueSet( info_.HasDoubleDefaultValueGet() );
    DoubleDefaultValueSet( info_.DoubleDefaultValueGet() );
    HasIntDefaultValueSet( info_.HasIntDefaultValueGet() );
    IntDefaultValueSet( info_.IntDefaultValueGet() );
    HasStringDefaultValueSet( info_.HasStringDefaultValueGet() );
    StringDefaultValueSet( info_.StringDefaultValueGet() );
}

// =================================================================================================
// Destructor
// -------------------------------------------------------------------------------------------------
CComCommandParameterInfo::~CComCommandParameterInfo()
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
IM::CWString CComCommandParameterInfo::DescGet() const
{
    return m_pImpl->m_desc.c_str();
}

void CComCommandParameterInfo::DescSet( const IM::CWString& desc_ )
{
    m_pImpl->m_desc = StrNonNull( desc_ );
}

IM::CWString CComCommandParameterInfo::ValuesGet() const
{
    return m_pImpl->m_values.c_str();
}

void CComCommandParameterInfo::ValuesSet( const IM::CWString& values_ )
{
    m_pImpl->m_values = StrNonNull( values_ );
}

EParameterDirection CComCommandParameterInfo::DirGet() const
{
    return m_pImpl->m_dir;
}

void CComCommandParameterInfo::DirSet( EParameterDirection dir_ )
{
    m_pImpl->m_dir = dir_;
}

EParameterType CComCommandParameterInfo::TypeGet() const
{
    return m_pImpl->m_type;
}

void CComCommandParameterInfo::TypeSet( EParameterType type_ )
{
    m_pImpl->m_type = type_;
}

bool CComCommandParameterInfo::HasDoubleDefaultValueGet() const
{
    return m_pImpl->m_hasDoubleDefaultValue;
}

void CComCommandParameterInfo::HasDoubleDefaultValueSet( bool hasValue_ )
{
    m_pImpl->m_hasDoubleDefaultValue = hasValue_;
}

double CComCommandParameterInfo::DoubleDefaultValueGet() const
{
    return m_pImpl->m_doubleDefaultValue;
}

void CComCommandParameterInfo::DoubleDefaultValueSet( double value_ )
{
    m_pImpl->m_doubleDefaultValue = value_;
}

bool CComCommandParameterInfo::HasIntDefaultValueGet() const
{
    return m_pImpl->m_hasIntDefaultValue;
}

void CComCommandParameterInfo::HasIntDefaultValueSet( bool hasValue_ )
{
    m_pImpl->m_hasIntDefaultValue = hasValue_;
}

int CComCommandParameterInfo::IntDefaultValueGet() const
{
    return m_pImpl->m_intDefaultValue;
}

void CComCommandParameterInfo::IntDefaultValueSet( int value_ )
{
    m_pImpl->m_intDefaultValue = value_;
}

bool CComCommandParameterInfo::HasStringDefaultValueGet() const
{
    return m_pImpl->m_hasStringDefaultValue;
}

void CComCommandParameterInfo::HasStringDefaultValueSet( bool hasValue_ )
{
    m_pImpl->m_hasStringDefaultValue = hasValue_;
}

IM::CWString CComCommandParameterInfo::StringDefaultValueGet() const
{
    return m_pImpl->m_stringDefaultValue.c_str();
}

void CComCommandParameterInfo::StringDefaultValueSet( const IM::CWString& value_ )
{
    m_pImpl->m_stringDefaultValue = StrNonNull( value_ );
}
