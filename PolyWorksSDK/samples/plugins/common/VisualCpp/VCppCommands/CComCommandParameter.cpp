// =================================================================================================
// Class representing a COM command parameter
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CComCommandParameter.h"

#include <PolyWorksSDK/COM/IIMCommand_i.c>

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

/* *****************************************************************************
 *                           IUnknown Interface
 * -------------------------------------------------------------------------- */

// =============================================================================
// QueryInterface is used to obtain a pointer to a specific COM interface
//
// Parameter: riid_  : IID of wanted COM interface
// Parameter: ppObj_ : [out] found pointer (or nullptr if not found)
//
// Return: STDMETHODIMP : return code
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameter::QueryInterface( REFIID riid_, void** ppObj_ )
{
    if ( ( riid_ == IID_IUnknown ) ||
         ( riid_ == IID_IIMCommandParameter ) )
    {
        *ppObj_ = static_cast< IIMCommandParameter* >( this );
    }
    else
    {
        // Wanted COM interface is not supported
        *ppObj_ = nullptr;
        return E_NOINTERFACE;
    }

    ( ( IUnknown* ) *ppObj_ )->AddRef();

    return S_OK;
}

// =============================================================================
// Increment reference count on object
//
// Return: STDMETHODIMP_(ULONG) : reference count value
// -----------------------------------------------------------------------------
STDMETHODIMP_( ULONG )
CComCommandParameter::AddRef()
{
    int res = InterlockedIncrement( &m_nRefCount );
    return res;
}

// =============================================================================
// Decrement reference count of object and free object if no more reference exist
//
// Return: STDMETHODIMP_(ULONG) : reference count value
// -----------------------------------------------------------------------------
STDMETHODIMP_( ULONG )
CComCommandParameter::Release()
{
    long nRefCount = 0;
    nRefCount = InterlockedDecrement( &m_nRefCount );
    if ( nRefCount == 0 )
    {
        delete this;
    }
    return nRefCount;
}

/* *****************************************************************************
 *                           IIMCommandParameter Interface
 * -------------------------------------------------------------------------- */

// =============================================================================
// See IIMCommandParameter::ParamDescGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameter::ParamDescGet(
    /* [retval][out] */ BSTR* pParamDesc_ )
{
    if ( pParamDesc_ != nullptr )
    {
        *pParamDesc_ = ::SysAllocString( m_paramInfo.DescGet() );
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommandParameter::ParamPossibleValuesGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameter::ParamPossibleValuesGet(
    /* [retval][out] */ BSTR* pPossibleValuesList_ )
{
    if ( pPossibleValuesList_ != nullptr )
    {
        *pPossibleValuesList_ = ::SysAllocString( m_paramInfo.ValuesGet() );
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommandParameter::ParamDirGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameter::ParamDirGet(
    /* [retval][out] */ EParameterDirection* pParamDir_ )
{
    if ( pParamDir_ != nullptr )
    {
        *pParamDir_ = m_paramInfo.DirGet();
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommandParameter::ParamTypeGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameter::ParamTypeGet(
    /* [retval][out] */ EParameterType* pParamType_ )
{
    if ( pParamType_ != nullptr )
    {
        *pParamType_ = m_paramInfo.TypeGet();
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommandParameter::ParamDefaultDoubleValueGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameter::ParamDefaultDoubleValueGet(
    /* [out] */ double*       pDefaultValue_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ != nullptr )
    {
        *pReturnVal_ = m_paramInfo.HasDoubleDefaultValueGet() ? 1 : 0;
    }
    if ( ( *pReturnVal_ == 1 ) && ( pDefaultValue_ != nullptr ) )
    {
        *pDefaultValue_ = m_paramInfo.DoubleDefaultValueGet();
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommandParameter::ParamDefaultIntValueGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameter::ParamDefaultIntValueGet(
    /* [out] */ int*          pDefaultValue_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ != nullptr )
    {
        *pReturnVal_ = m_paramInfo.HasIntDefaultValueGet() ? 1 : 0;
    }
    if ( ( *pReturnVal_ == 1 ) && ( pDefaultValue_ != nullptr ) )
    {
        *pDefaultValue_ = m_paramInfo.IntDefaultValueGet();
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommandParameter::ParamDefaultStringValueGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameter::ParamDefaultStringValueGet(
    /* [out] */ BSTR*         pDefaultValue_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( pReturnVal_ != nullptr )
    {
        *pReturnVal_ = m_paramInfo.HasStringDefaultValueGet() ? 1 : 0;
    }
    if ( ( *pReturnVal_ == 1 ) && ( pDefaultValue_ != nullptr ) )
    {
        *pDefaultValue_ = ::SysAllocString( m_paramInfo.StringDefaultValueGet() );
        return S_OK;
    }
    return S_FALSE;
}

/* *****************************************************************************
 *              CComCommandParameter specific methods
 * -------------------------------------------------------------------------- */

// =============================================================================
// Constructor
//
// Parameter: info_ : Information used to construct parameter
// -----------------------------------------------------------------------------
CComCommandParameter::CComCommandParameter( CComCommandParameterInfo& info_ )
: m_nRefCount( 0 )
, m_paramInfo( info_ )
{
}

// =============================================================================
// Destructor
// -----------------------------------------------------------------------------
CComCommandParameter::~CComCommandParameter() = default;
