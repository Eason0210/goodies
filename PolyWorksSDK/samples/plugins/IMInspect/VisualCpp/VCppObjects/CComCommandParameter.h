#pragma once

// =================================================================================================
// Class representing a COM command parameter
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/COM/IIMCommandParameter.h>

#include "CComCommandParameterInfo.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ===================================== CONSTANTES, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =============================================================================
// Classe used to implement a COM parameter
//
// Derive from IIMCommandParameter
// -----------------------------------------------------------------------------
class CComCommandParameter : public IIMCommandParameter
{

public:

    CComCommandParameter( CComCommandParameterInfo& info_ );
    virtual ~CComCommandParameter();

    // IUnknown
    STDMETHODIMP QueryInterface( REFIID riid_, void** ppObj_ ) override;

    STDMETHODIMP_( ULONG ) AddRef() override;

    STDMETHODIMP_( ULONG ) Release() override;

    // IIMCommandParameter
    STDMETHODIMP ParamDescGet(
        /* [retval][out] */ BSTR* pParamDesc_ ) override;

    STDMETHODIMP ParamPossibleValuesGet(
        /* [retval][out] */ BSTR* pPossibleValuesList_ ) override;

    STDMETHODIMP ParamDirGet(
        /* [retval][out] */ EParameterDirection* pParamDir_ ) override;

    STDMETHODIMP ParamTypeGet(
        /* [retval][out] */ EParameterType* pParamType_ ) override;

    STDMETHODIMP ParamDefaultDoubleValueGet(
        /* [out] */ double*       pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ ) override;

    STDMETHODIMP ParamDefaultIntValueGet(
        /* [out] */ int*          pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ ) override;

    STDMETHODIMP ParamDefaultStringValueGet(
        /* [out] */ BSTR*         pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ ) override;

private:

    CComCommandParameter( const CComCommandParameter& );
    const CComCommandParameter& operator=( const CComCommandParameter& );

    long                     m_nRefCount;
    CComCommandParameterInfo m_paramInfo;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
