// =================================================================================================
// Implementation of the class describing a COM command parameter
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CComCommandParameterInfoImpl.h"

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
CComCommandParameterInfoImpl::CComCommandParameterInfoImpl( const std::wstring& desc_,
                                                            EParameterDirection dir_,
                                                            EParameterType      type_ )
: m_desc( desc_ )
, m_dir( dir_ )
, m_type( type_ )
, m_hasDoubleDefaultValue( false )
, m_doubleDefaultValue( 0.0 )
, m_hasIntDefaultValue( false )
, m_intDefaultValue( 0 )
, m_hasStringDefaultValue( false )
{
}

// =============================================================================
// Copy constructor
//
// Parameter: info_ : Object to be copied
// -----------------------------------------------------------------------------
CComCommandParameterInfoImpl::CComCommandParameterInfoImpl( CComCommandParameterInfoImpl& info_ )
: m_desc( info_.m_desc )
, m_values( info_.m_values )
, m_dir( info_.m_dir )
, m_type( info_.m_type )
, m_hasDoubleDefaultValue( info_.m_hasDoubleDefaultValue )
, m_doubleDefaultValue( info_.m_doubleDefaultValue )
, m_hasIntDefaultValue( info_.m_hasIntDefaultValue )
, m_intDefaultValue( info_.m_intDefaultValue )
, m_hasStringDefaultValue( info_.m_hasStringDefaultValue )
, m_stringDefaultValue( info_.m_stringDefaultValue )
{
}


// =================================================================================================
// Destructor
// -------------------------------------------------------------------------------------------------
CComCommandParameterInfoImpl::~CComCommandParameterInfoImpl()
{
}
