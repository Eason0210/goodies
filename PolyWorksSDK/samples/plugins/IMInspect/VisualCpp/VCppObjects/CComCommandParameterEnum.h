#pragma once

// =================================================================================================
// Class for COM command parameters enumeration
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/COM/IIMCommandParameter.h>
#include <atlcomcli.h>

class CComCommandParameterEnumImpl;

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ===================================== CONSTANTES, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CComCommandParameterEnum : public IIMCommandParameterEnum
{

public:

    CComCommandParameterEnum();
    virtual ~CComCommandParameterEnum();

    void CommandParameterAdd( const CComPtr< IIMCommandParameter >& pCommandParameter_ );

    // IUnknown
    STDMETHODIMP QueryInterface( REFIID riid_, void** ppObj_ ) override;

    STDMETHODIMP_( ULONG ) AddRef() override;

    STDMETHODIMP_( ULONG ) Release() override;

    // IIMCommandParameterEnum
    STDMETHODIMP ParamsGetNb(
        /* [retval][out] */ long* pParamNb_ ) override;

    STDMETHODIMP ParamGet(
        /* [in] */ long                   number_,
        /* [out] */ IIMCommandParameter** pIIMCommandParameter_ ) override;

private:

    CComCommandParameterEnum( const CComCommandParameterEnum& );
    const CComCommandParameterEnum& operator=( const CComCommandParameterEnum& );

    long                          m_nRefCount;
    CComCommandParameterEnumImpl* m_pImpl;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
