#pragma once

// =================================================================================================
//   Polyworks SDK interface implementation
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IIMCommand.h>
#include <PolyWorksSDK/COM/IIMPlugin.h>
#include <array>
#include <atlcom.h>
#include <CompanyNameNotificationHandler.h>
#include <string>
#include <variant>
#include <vector>

#include "CCompanyNameCommands.h"
#include "CCompanyNameConnectionPointImpl.h"
#include "CCompanyNameNotificationHandlerConnectionPoint.h"
#include "CDlgCompanyNameNotificationViewer.h"
#include "INotificationFeedback.h"
#include "Resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class ClgCompanyNameNotificationViewer;
class CompanyNameNotificationHandlerPlugin;
class IIMInspect;
class INotificationFeedback;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

enum class ENotificationType
{
    E_DATA_OBJECT = 0,
    E_INSPECTOR_PROJECT,
    E_REFERENCE_OBJECT,
    E_DATA_OBJECT_GROUP,
    E_COUNT
};

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

using TDataObjectSink       = CCompanyNameConnectionPointImpl< CDataObjectNotificationSink >;
using TReferenceObjectSink  = CCompanyNameConnectionPointImpl< CReferenceObjectNotificationSink >;
using TInspectorProjectSink = CCompanyNameConnectionPointImpl< CInspectProjectNotificationSink >;
using TDataObjectGroupSink  = CCompanyNameConnectionPointImpl< CDataObjectGroupNotificationSink >;

// =================================================================================================
//   INotificationActivationManager
// -------------------------------------------------------------------------------------------------
class INotificationActivationManager
{
public:
    virtual ~INotificationActivationManager() = default;
    virtual void NotificationActivationStateSet( ENotificationType notificationID_, bool activate_ ) = 0;
    virtual bool NotificationActivationStateGet( ENotificationType notificationID_ )                 = 0;
};

// =================================================================================================
//   CCompanyNameRotaryTablePlugin
// -------------------------------------------------------------------------------------------------
class ATL_NO_VTABLE CCompanyNameNotificationHandlerPlugin :
    public CComObjectRootEx< CComSingleThreadModel >,
    public CComCoClass< CCompanyNameNotificationHandlerPlugin, &CLSID_CompanyNameNotificationHandlerPlugin >,
    public IDispatchImpl< ICompanyNameNotificationHandlerPlugin, &IID_ICompanyNameNotificationHandlerPlugin, &LIBID_COMPANYNAMENOTIFICATIONHANDLERLib, /*wMajor =*/ 1, /*wMinor =*/ 0 >,
    public IIMPlugin,
    public IIMCommandEnum,
    public INotificationActivationManager,
    public INotificationFeedback
{
public:
    // ---------------- Public Methods  ------------------------------------------------------------
    CCompanyNameNotificationHandlerPlugin();
    virtual ~CCompanyNameNotificationHandlerPlugin();

    DECLARE_REGISTRY_RESOURCEID( IDR_COMPANYNAMENOTIFICATIONHANDLERPLUGIN )

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP( CCompanyNameNotificationHandlerPlugin )
    COM_INTERFACE_ENTRY( ICompanyNameNotificationHandlerPlugin )
    COM_INTERFACE_ENTRY( IDispatch )
    COM_INTERFACE_ENTRY( IIMPlugin )
    COM_INTERFACE_ENTRY( IIMCommandEnum )
    END_COM_MAP()

    // IIMPlugin
public:
    STDMETHODIMP PlgNameGet(
        /* [out] */ BSTR* pName_ ) override;

    STDMETHODIMP PlgVersionGet(
        /* [out] */ long* pMajor_,
        /* [out] */ long* pMinor_,
        /* [out] */ long* pDot_ ) override;

    STDMETHODIMP Load(
        /* [in] */ IIMHost*       pIIMHost_,
        /* [retval][out] */ long* pReturnVal_ ) override;

    STDMETHODIMP Unload(
        /* [retval][out] */ long* pReturnVal_ ) override;

    // IIMCommandEnum
public:
    STDMETHODIMP CmdsGetNb( /* [retval][out] */ long* pArgNb_ ) override;

    STDMETHODIMP CmdGet(
        /* [in]  */ long         number_,
        /* [out] */ IIMCommand** pIIMCommand_ ) override;

    // INotificationActivationManager
public:
    void NotificationActivationStateSet( ENotificationType notificationID_, bool toogle_ ) override;
    bool NotificationActivationStateGet( ENotificationType notificationID_ ) override;

    // INotificationFeedback
public:
    void OnObjectUniqueIDsReceived( std::vector< std::wstring >&& uniqueIDs_, std::wstring&& operationType_ ) override;
    void OnPieceUniqueIDReceived( std::wstring&& uniqueID_,  std::wstring&& operationType_ ) override;

private:
    // ---------------- Private Methods ------------------------------------------------------------
    void CommandsAdd();
    void CommandsRemove();

    // ---------------- Private Member Variables ---------------------------------------------------
    // Pointer to the host application
    CComPtr< IIMInspect > m_host;

    // Supported command list
    typedef std::vector< CComPtr< IIMCommand2 > > CommandsVector;
    CommandsVector m_commands;

    // Dialog object
    std::unique_ptr< CDlgCompanyNameNotificationViewer > m_pDlg = nullptr;

    // notification
    TDataObjectSink       m_dataObjectSink;
    TReferenceObjectSink  m_referenceObjectSink;
    TInspectorProjectSink m_inspectorSink;
    TDataObjectGroupSink  m_dataObjectGroupSink;
};

OBJECT_ENTRY_AUTO( __uuidof( CompanyNameNotificationHandlerPlugin ), CCompanyNameNotificationHandlerPlugin )

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
