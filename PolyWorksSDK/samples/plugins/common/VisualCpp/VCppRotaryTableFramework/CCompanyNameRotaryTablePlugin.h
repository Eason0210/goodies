#pragma once

// =================================================================================================
//   Polyworks SDK interface implementation
//
// Copyright © InnovMetric Logiciels Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include <PolyWorksSDK/COM/IIMPlugin.h>
#include <PolyWorksSDK/COM/IIMRotaryTable.h>
#include <string>

#include "CompanyNameRotaryTable.h"
#include "CThreadHelper.h"
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
//   CCompanyNameRotaryTablePlugin
// -------------------------------------------------------------------------------------------------
class ATL_NO_VTABLE CCompanyNameRotaryTablePlugin :
    public CComObjectRootEx< CComSingleThreadModel >,
    public CComCoClass< CCompanyNameRotaryTablePlugin, &CLSID_CompanyNameRotaryTablePlugin >,
    public IDispatchImpl< ICompanyNameRotaryTablePlugin, &IID_ICompanyNameRotaryTablePlugin, &LIBID_COMPANYNAMEROTARYTABLELib >,
    public IIMPlugin,
    public IIMRotaryTable
{
public:
    CCompanyNameRotaryTablePlugin() {}

    DECLARE_REGISTRY_RESOURCEID( IDR_COMPANYNAMEROTARYTABLEPLUGIN )

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP( CCompanyNameRotaryTablePlugin )
    COM_INTERFACE_ENTRY( ICompanyNameRotaryTablePlugin )
    COM_INTERFACE_ENTRY( IDispatch )
    COM_INTERFACE_ENTRY( IIMPlugin )
    COM_INTERFACE_ENTRY( IIMRotaryTable )
    END_COM_MAP()

    // ICompanyNameRotaryTablePlugin
public:

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

    // IIMRotaryTable
public:
    STDMETHODIMP RotaryTableNameGet(
        /* [retval][out] */ BSTR* pName_ ) override;

    STDMETHODIMP RotaryTableConnectionInit(
        /* [in] */ IIMRotaryTableFeedback* pIIMRotaryTableFeedback_ ) override;

    STDMETHODIMP RotaryTableConnectionEnd() override;

    STDMETHODIMP RotaryTableDefaultStepGet(
        /* [retval][out] */ double* pStep_ ) override;

    STDMETHODIMP RotaryTableCanChangeSpeed(
        /* [retval][out] */ VARIANT_BOOL* pCanChangeSpeed_ ) override;

    STDMETHODIMP RotaryTableDefaultSpeedGet(
        /* [retval][out] */ double* pSpeed_ ) override;

    STDMETHODIMP RotaryTableMaximumSpeedGet(
        /* [retval][out] */ double* pSpeed_ ) override;

    STDMETHODIMP RotaryTableMinimumSpeedGet(
        /* [retval][out] */ double* pSpeed_ ) override;

    STDMETHODIMP RotaryTableSpeedSet(
        /* [in] */ double speed_ ) override;

    STDMETHODIMP RotaryTableCanChangeAcceleration(
        /* [retval][out] */ VARIANT_BOOL* pCanChangeAcceleration_ ) override;

    STDMETHODIMP RotaryTableDefaultAccelerationGet(
        /* [retval][out] */ double* pAcceleration_ ) override;

    STDMETHODIMP RotaryTableMaximumAccelerationGet(
        /* [retval][out] */ double* pAcceleration_ ) override;

    STDMETHODIMP RotaryTableMinimumAccelerationGet(
        /* [retval][out] */ double* pAcceleration_ ) override;

    STDMETHODIMP RotaryTableAccelerationSet(
        /* [in] */ double acceleration_ ) override;

    STDMETHODIMP RotaryTableAngleGet(
        /* [retval][out] */ double* pAngle_ ) override;

    STDMETHODIMP RotaryTableStatusGet(
        /* [out] */ EDeviceStatus* pStatus_,
        /* [out] */ BSTR*          pDetails_ ) override;

    STDMETHODIMP RotaryTableHomingIsRequired(
        /* [retval][out] */ VARIANT_BOOL* pIsHomingRequired_ ) override;

    STDMETHODIMP RotaryTableRotateHome() override;

    STDMETHODIMP RotaryTableRotate(
        /* [in] */ double             angle_,
        /* [in] */ ERotationDirection direction_ ) override;

    STDMETHODIMP RotaryTableCanStop(
        /* [retval][out] */ VARIANT_BOOL* pCanStop_ ) override;

    STDMETHODIMP RotaryTableStop() override;

private:

    // Rotary table feedback to the application
    void OnRotaryTableAngleChanged( double angle_ );
    void OnRotaryTableStatusChanged( EDeviceStatus status_, const std::wstring& details_ );
    void OnRotaryTableRotationCompleted( ERotaryTableCommandStatus commandStatus_, const std::wstring& details_ );
    void OnRotaryTableHomingCompleted( ERotaryTableCommandStatus commandStatus_, const std::wstring& details_ );
    void OnRotaryTableConnectionLost();

    // Device communication thread
    friend unsigned __stdcall DeviceCommunicationThread( void* pPlugin_ );
    CThreadHelper m_deviceCommunicationThread;

    // Pointer to the host application
    CComPtr< IIMHost > m_host;

    DWORD m_cookieFeedback = 0;

    // Cache for the rotary table position
    double m_currentAngle = 0.0;

    // TODO : Remove these lines that are only here to simplify the sample
    bool m_isRotationInProgess = false;
    bool m_isHomingInProgress  = false;

    // Cache for the rotary table status
    //
    // EDeviceStatus::E_DEVICE_STATUS_READY     : The rotary table is ready to move and the current position is stable.
    // EDeviceStatus::E_DEVICE_STATUS_NOT_READY : The rotary table cannot be ordered to move for any reason (e.g. the machine is in Emergency Stop)
    // EDeviceStatus::E_DEVICE_STATUS_BUSY      : The rotary table is moving and thus the current position is not stable.
    EDeviceStatus m_currentStatus = EDeviceStatus::E_DEVICE_STATUS_READY;
    std::wstring  m_currentStatusDetails;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
