#ifndef _CCCOMPANYNAMECOMPLUGIN_MONDAY_AUGUST06_151020_H_
#define _CCCOMPANYNAMECOMPLUGIN_MONDAY_AUGUST06_151020_H_
// =================================================================================================
// CCompanyNameComPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/COM/IIMCommand.h>
#include <PolyWorksSDK/COM/IIMPlugin.h>
#include <atlcomcli.h>
#include <VCppCommands.h>
#include <vector>

#include "resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Plug-in's COM object interface used to connect to a PolyWorks module.
// -------------------------------------------------------------------------------------------------

class ATL_NO_VTABLE CCompanyNameComPlugin :
    public CComObjectRootEx< CComSingleThreadModel >,
    public CComCoClass< CCompanyNameComPlugin, &CLSID_CompanyNameComPlugin >,
    public IDispatchImpl< ICompanyNameComPlugin, &IID_ICompanyNameComPlugin, &LIBID_CompanyNameLib, /* wMajor = */ 1, /* wMinor = */ 0 >,
    public IIMPlugin,
    public IIMCommandEnum
{
public:

    // ---------------- Public Types  --------------------------------------------------------------
    // ---------------- Public Methods  ------------------------------------------------------------

    CCompanyNameComPlugin();
    virtual ~CCompanyNameComPlugin();

    DECLARE_REGISTRY_RESOURCEID( IDR_COMPANYNAMEPLUGIN )

    BEGIN_COM_MAP( CCompanyNameComPlugin )
    COM_INTERFACE_ENTRY( ICompanyNameComPlugin )
    COM_INTERFACE_ENTRY( IDispatch )
    COM_INTERFACE_ENTRY( IIMPlugin )
    COM_INTERFACE_ENTRY( IIMCommandEnum )
    END_COM_MAP()

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    void CommandsAdd();
    void CommandsRemove();

    HRESULT FinalConstruct();
    void    FinalRelease();

public:

    // --- IIMPlugin -------------------------------------------------------------------------------

    STDMETHODIMP PlgNameGet( /* [retval][out] */ BSTR* pName_ );

    STDMETHODIMP PlgVersionGet(
        /* [out][in] */ long* pMajor_,
        /* [out][in] */ long* pMinor_,
        /* [out][in] */ long* pDot_ );

    STDMETHODIMP Load(
        /* [unique][in]  */ IIMHost* pIIMHost_,
        /* [retval][out] */ long*    pReturnVal_ );

    STDMETHODIMP Unload( /* [retval][out] */ long* pReturnVal_ );

public:

    // --- IIMCommandEnum --------------------------------------------------------------------------

    STDMETHODIMP CmdsGetNb( /* [retval][out] */ long* pArgNb_ );

    STDMETHODIMP CmdGet(
        /* [in]  */ long         number_,
        /* [out] */ IIMCommand** pIIMCommand_ );

protected:

    // ---------------- Protected Methods ----------------------------------------------------------
    // ---------------- Protected Member Variables -------------------------------------------------

private:

    typedef std::vector< CComPtr< IIMCommand2 > > CommandsVector;

    // ---------------- Private Methods ------------------------------------------------------------
    // ---------------- Private Member Variables ---------------------------------------------------

    CommandsVector m_commands;
};

OBJECT_ENTRY_AUTO( __uuidof( CompanyNameComPlugin ), CCompanyNameComPlugin )

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

#endif // _CCCOMPANYNAMECOMPLUGIN_MONDAY_AUGUST06_151020_H_
