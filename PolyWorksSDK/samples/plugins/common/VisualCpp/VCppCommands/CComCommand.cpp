// =================================================================================================
// Class representing a COM command
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CComCommand.h"

#include <PolyWorksSDK/COM/IIMCommand_i.c>

#include "CComCommandParameterEnum.h"
#include "SafeArrayConversion.h"
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

STDMETHODIMP CComCommand::QueryInterface( REFIID riid_, void** ppObj_ )
{
    if ( ( riid_ == IID_IUnknown ) ||
         ( riid_ == IID_IIMCommand ) )
    {
        *ppObj_ = static_cast< IIMCommand* >( this );
    }
    else if ( riid_ == IID_IIMCommand2 )
    {
        *ppObj_ = static_cast< IIMCommand2* >( this );
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
CComCommand::AddRef()
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
CComCommand::Release()
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
 *                            IIMCommand Interface
 * -------------------------------------------------------------------------- */

// =============================================================================
// See IIMCommand::CmdNameGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::CmdNameGet(
    /* [retval][out] */ BSTR __RPC_FAR* pCmdName_ )
{
    if ( pCmdName_ != nullptr )
    {
        ::SysFreeString( *pCmdName_ );

        *pCmdName_ = ::SysAllocString( m_commandInfo.NameGet() );

        return ( *pCmdName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommand::CmdDescGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::CmdDescGet(
    /* [retval][out] */ BSTR* pCmdDesc_ )
{
    if ( pCmdDesc_ != nullptr )
    {
        ::SysFreeString( *pCmdDesc_ );

        *pCmdDesc_ = ::SysAllocString( m_commandInfo.DescGet() );

        return ( *pCmdDesc_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommand::Execute
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::Execute(
    /* [retval][out] */ long* pReturnVal_ )
{
    ECommandReturnCodes retCode = E_CMD_FAILED;
    HRESULT hr                  = Execute2( nullptr, &retCode );

    if ( pReturnVal_ != nullptr )
    {
        *pReturnVal_ = ( retCode == E_CMD_SUCCEEDED ) ? 1 : 0;
    }

    return hr;
}

// =============================================================================
// See IIMCommand::MenuLocationGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::MenuLocationGet(
    /* [retval][out] */ BSTR* pMenuPath_ )
{
    if ( pMenuPath_ != nullptr )
    {
        ::SysFreeString( *pMenuPath_ );

        *pMenuPath_ = ::SysAllocString( m_commandInfo.MenuLocationGet() );

        return ( *pMenuPath_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommand::MenuDescGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::MenuDescGet(
    /* [retval][out] */ BSTR* pMenuDesc_ )
{
    if ( pMenuDesc_ != nullptr )
    {
        ::SysFreeString( *pMenuDesc_ );

        // If a menu description exist, we take it, otherwise, command description is used
        std::wstring menuDesc = StrNonNull( m_commandInfo.MenuDescGet() );
        if ( !menuDesc.empty() )
        {
            *pMenuDesc_ = ::SysAllocString( menuDesc.c_str() );
        }
        else
        {
            *pMenuDesc_ = ::SysAllocString( m_commandInfo.DescGet() );
        }

        return ( *pMenuDesc_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
    }
    return S_FALSE;
}

/* *****************************************************************************
 *                            IIMCommand2 Interface
 * -------------------------------------------------------------------------- */

// =============================================================================
// See IIMCommand2::ArgsTest
//
// A simple check for argument count corresponding to parameter count is performed here
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::ArgsTest(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    if ( pReturnCode_ != nullptr )
    {
        *pReturnCode_ = E_CMD_FAILED;

        if ( pIIMCommandArgumentEnum_ != nullptr )
        {
            long nbArgs = 0;
            if ( pIIMCommandArgumentEnum_->ArgsGetNb( &nbArgs ) == S_OK )
            {
                long nbParams = 0;
                if ( m_commandInfo.ParameterEnumGet().ParamsGetNb( &nbParams ) == S_OK )
                {
                    if ( nbArgs == nbParams )
                    {
                        *pReturnCode_ = E_CMD_SUCCEEDED;
                        return S_OK;
                    }
                }
            }
        }
    }
    return S_FALSE;
}

// =============================================================================
// See IIMCommand2::CmdDeprecatedNamesGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::CmdDeprecatedNamesGet(
    /* [out][in] */ SAFEARRAY** pNames_ )
{
    std::vector< std::wstring > deprecatedNames;

    unsigned int nbNames = m_commandInfo.DeprecatedNamesGetNb();
    std::wstring name;
    for ( unsigned int iName = 0; iName < nbNames; iName++ )
    {
        name = StrNonNull( m_commandInfo.DeprecatedNameGet( iName ) );
        if ( !name.empty() )
        {
            deprecatedNames.push_back( name );
        }
    }

    return SafeArrayConversion::Insert_WStrings( deprecatedNames, pNames_ ) ? S_OK : S_FALSE;
}

// =============================================================================
// See IIMCommand2::CmdIsObsolete
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::CmdIsObsolete(
    /* [out] */ VARIANT_BOOL* pIsObsolete_,
    /* [out] */ BSTR*         pSupersedingCmd_ )
{
    HRESULT retVal = S_OK;

    if ( pIsObsolete_ != nullptr )
    {
        *pIsObsolete_ = m_commandInfo.IsObsoleteGet() ? VARIANT_TRUE : VARIANT_FALSE;
    }
    else
    {
        retVal = S_FALSE;
    }

    if ( pSupersedingCmd_ != nullptr )
    {
        *pSupersedingCmd_ = m_commandInfo.IsObsoleteGet() ? ::SysAllocString( m_commandInfo.SupersedingCommandGet() ) : nullptr;
    }
    else
    {
        retVal = S_FALSE;
    }

    return retVal;
}

// =============================================================================
// See IIMCommand2::CmdNoteGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::CmdNoteGet(
    /* [retval][out] */ BSTR* pCmdNote_ )
{
    if ( pCmdNote_ != nullptr )
    {
        ::SysFreeString( *pCmdNote_ );

        *pCmdNote_ = ::SysAllocString( m_commandInfo.NoteGet() );

        return ( *pCmdNote_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
    }
    return S_FALSE;
}


// =============================================================================
// See IIMCommand2::ParamsGet
// -----------------------------------------------------------------------------
STDMETHODIMP CComCommand::ParamsGet(
    /* [out] */ IIMCommandParameterEnum** pIIMCommandParameterEnum_ )
{
    if ( pIIMCommandParameterEnum_ != nullptr )
    {
        *pIIMCommandParameterEnum_ = &( m_commandInfo.ParameterEnumGet() );
        ( *pIIMCommandParameterEnum_ )->AddRef();
        return S_OK;
    }
    return S_FALSE;
}

/* *****************************************************************************
 *              CComCommand specific methods
 * -------------------------------------------------------------------------- */

// =============================================================================
// Constructor
//
// Parameter: info_ : Information used to construct command
// -----------------------------------------------------------------------------
CComCommand::CComCommand( CComCommandInfo& info_ )
: m_commandInfo( info_ )
, m_nRefCount( 0 )
{
}

// =============================================================================
// Destructor
// -----------------------------------------------------------------------------
CComCommand::~CComCommand()
{
}
