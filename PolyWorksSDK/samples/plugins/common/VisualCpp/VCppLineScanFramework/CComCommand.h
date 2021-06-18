#pragma once

// =================================================================================================
// Class representing a COM command
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/COM/IIMCommand.h>
#include <PolyWorksSDK/COM/IMTypes.h>

#include "CComCommandInfo.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ===================================== CONSTANTES, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =============================================================================
// Base class for a COM command
// Method Execute2 must at least be redefined
// If command parameters can be validated, ArgsTest should also be redefined
// All other stuff is managed automatically based on CComCommandInfo content
// This does not prevent any other method redefinition for particular needs
//
// Derive from IIMCommand2
// -----------------------------------------------------------------------------
class CComCommand : public IIMCommand2
{

public:

    CComCommand( CComCommandInfo& info_ );
    virtual ~CComCommand();

    // IUnknown
    STDMETHODIMP QueryInterface( REFIID riid_, void** ppObj_ ) override;

    STDMETHODIMP_( ULONG ) AddRef() override;

    STDMETHODIMP_( ULONG ) Release() override;

    // IIMCommand
    STDMETHODIMP CmdNameGet(
        /* [retval][out] */ BSTR* pCmdName_ ) override;

    STDMETHODIMP CmdDescGet(
        /* [retval][out] */ BSTR* pCmdDesc_ ) override;

    STDMETHODIMP Execute(
        /* [retval][out] */ long* pReturnVal_ ) override;

    STDMETHODIMP MenuLocationGet(
        /* [retval][out] */ BSTR* pMenuPath_ ) override;

    STDMETHODIMP MenuDescGet(
        /* [retval][out] */ BSTR* pMenuDesc_ ) override;

    // IIMCommand2
    STDMETHODIMP ArgsTest(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ ) override;

    STDMETHODIMP CmdDeprecatedNamesGet(
        /* [out][in] */ SAFEARRAY** pNames_ ) override;

    STDMETHODIMP CmdIsObsolete(
        /* [out] */ VARIANT_BOOL* pIsObsolete_,
        /* [out] */ BSTR*         pSupersedingCmd_ ) override;

    STDMETHODIMP CmdNoteGet(
        /* [retval][out] */ BSTR* pCmdNote_ ) override;

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ ) override = 0;

    STDMETHODIMP ParamsGet(
        /* [out] */ IIMCommandParameterEnum** pIIMCommandParameterEnum_ ) override;

protected:

    CComCommandInfo m_commandInfo;

private:

    CComCommand( const CComCommand& );
    const CComCommand& operator=( const CComCommand& );

    long m_nRefCount;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
