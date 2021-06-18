#pragma once

// =================================================================================================
//   Data receiver from the device.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IMTypes.h>
#include <list>
#include <memory>
#include <vector>

#include "CCompanyNameSDKStub.h"
#include "CMessageOnlyWindow.h"
#include "CompanyNameConst.h"
#include "CThreadHelper.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CDlgCompanyName;
class CDlgIMAlignOptions;

struct IIMPlanarGrid;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================


// =================================================================================================
//   Data receiver class.
// -------------------------------------------------------------------------------------------------
class CCompanyNameScannerReceiver
{

public:

    // Public member functions
    ////////////////////////////

    virtual ~CCompanyNameScannerReceiver();

    void ConflictingPluginsDisconnect();
    void CreateNewDevicePositionIfNeeded( bool isVisibleInCommandHistory_ );
    void Reset();

    void DlgIMAlignOptionsShow( CWnd* pParent_ );
    bool InterfacePopdown();
    bool InterfacePopup();

    bool Connect();
    void ConnectionStateUpdate( const bool connected_ );
    bool Disconnect();

    void OnDataAcquired( SScanData& data_ );
    void OnScanEnd();

    bool ScanningStart( IIMPlanarGrid* pPlanarGrid_ );
    bool ScanningEnd();

    bool ScanningObjectsGet( EScanTypes                   scanType_,
                             std::vector< std::wstring >& objectNames_,
                             std::wstring&                currentChoice_ ) const;
    bool ScanningObjectsSet( EScanTypes                         scanType_,
                             const std::vector< std::wstring >& objectNames_,
                             const std::wstring&                currentChoice_ );

    void UpdateFromSettings();
    void UpdateSettingsFromApp();

    long NbPointsRecordedGet() { return m_nbPointsRecorded; }

    // Public member variables
    ////////////////////////////

    CCompanyNameSDKStub m_companyNameSDKStub;

    std::unique_ptr< CDlgCompanyName > m_pDlgCompanyName;

protected:

    // Protected member Functions
    ///////////////////////////////

    // Protected member variables
    ///////////////////////////////

private:

    // Private member functions
    /////////////////////////////

    friend class CCompanyNameScanner;
    CCompanyNameScannerReceiver();

    void DataTransfer( IIMPlanarGrid* pPlanarGrid_, std::vector< float >& points_ );
    void ViewPointSet( IIMPlanarGrid* pPlanarGrid_, std::vector< float >& viewPointVector_ );

    // Private member variables
    /////////////////////////////

    DWORD                m_cookiePlanarGrid;
    CMessageOnlyWindow   m_messageOnlyWindow;
    std::vector< float > m_digitizingVector;
    bool                 m_isUpdatingFromSettings = false;
    long                 m_nbPointsRecorded       = 0;

    std::vector< std::wstring > m_surfaceScanName;
    std::wstring                m_surfaceScanNameCurrentChoice;

    std::unique_ptr< CDlgIMAlignOptions > m_pDlgIMAlignOptions;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
