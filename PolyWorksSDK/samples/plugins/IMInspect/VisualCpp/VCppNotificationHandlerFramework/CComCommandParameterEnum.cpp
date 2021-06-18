// =================================================================================================
// Implementation of the class for COM command parameters enumeration
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CComCommandParameterEnum.h"

#include <PolyWorksSDK/COM/IIMCommandParameter_i.c>

#include "CComCommandParameterEnumImpl.h"

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
 *                            IUnknown Interface
 * -------------------------------------------------------------------------- */

// =============================================================================
// QueryInterface is used to obtain a pointer to a specific COM interface
//
// Parameter: riid_  : IID of wanted COM interface
// Parameter: ppObj_ : [out] found pointer (or nullptr if not found)
//
// Return: STDMETHODIMP : return code
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameterEnum::QueryInterface( REFIID riid_, void** ppObj_ )
{
    if ( ( riid_ == IID_IUnknown ) ||
         ( riid_ == IID_IIMCommandParameterEnum ) )
    {
        *ppObj_ = static_cast< IIMCommandParameterEnum* >( this );
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
CComCommandParameterEnum::AddRef()
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
CComCommandParameterEnum::Release()
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
 *                            IIMCommandParameterEnum Interface
 * -------------------------------------------------------------------------- */

// =============================================================================
// See CComCommandParameterEnum::ParamsGetNb
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameterEnum::ParamsGetNb(
    /* [retval][out] */ long* pParamNb_ )
{
    return m_pImpl->ParamsGetNb( pParamNb_ );
}

// =============================================================================
// See CComCommandParameterEnum::ParamGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommandParameterEnum::ParamGet(
    /* [in] */ long                   number_,
    /* [out] */ IIMCommandParameter** pIIMCommandParameter_ )
{
    return m_pImpl->ParamGet( number_, pIIMCommandParameter_ );
}


/* *****************************************************************************
 *              CComCommandParameterEnum specific methods
 * -------------------------------------------------------------------------- */

// =============================================================================
// Constructor
// -----------------------------------------------------------------------------
CComCommandParameterEnum::CComCommandParameterEnum()
: m_nRefCount( 0 )
{
    m_pImpl = new CComCommandParameterEnumImpl;
}

// =============================================================================
// Destructor
// -----------------------------------------------------------------------------
CComCommandParameterEnum::~CComCommandParameterEnum()
{
    if ( m_pImpl != nullptr )
    {
        delete m_pImpl;
        m_pImpl = nullptr;
    }
}

// =============================================================================
// Add an argument to the enumeration
//
// Parameter: pCommandParameter_ : Argument to add
// -----------------------------------------------------------------------------
void CComCommandParameterEnum::CommandParameterAdd( const CComPtr< IIMCommandParameter >& pCommandParameter_ )
{
    m_pImpl->CommandParameterAdd( pCommandParameter_ );
}
