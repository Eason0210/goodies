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
#include <vector>

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ===================================== CONSTANTES, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CComCommandParameterEnumImpl
{

public:

    CComCommandParameterEnumImpl();
    virtual ~CComCommandParameterEnumImpl();

    void CommandParameterAdd( const CComPtr< IIMCommandParameter >& pCommandParameter_ );

    // IIMCommandParameterEnum
    STDMETHODIMP ParamsGetNb(
        /* [retval][out] */ long* pParamNb_ );

    STDMETHODIMP ParamGet(
        /* [in] */ long                   number_,
        /* [out] */ IIMCommandParameter** pIIMCommandParameter_ );

private:

    CComCommandParameterEnumImpl( const CComCommandParameterEnumImpl& );
    const CComCommandParameterEnumImpl& operator=( const CComCommandParameterEnumImpl& );

    std::vector< CComPtr< IIMCommandParameter > > m_parameters;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
