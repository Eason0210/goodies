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

#include "CCompanyNameSDKStub.h"
#include "CompanyNameConst.h"
#include "CScanningProfilesUser.h"
#include "CThreadHelper.h"
#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class CDlgCompanyName;
class CDlgIMAlignOptions;
class CDlgIMInspectOptions;

struct IIMLineScan;
struct IIMPointCloud;
struct IIMSceneCamera;
struct IIMVisualFeedback;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const int SIZE_OF_POINT = sizeof( float ) * 3;

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Scan line data structure.
// -------------------------------------------------------------------------------------------------
struct SScanLineData
{
    std::vector< PointF > m_pointsBuffer;
    long                  m_nbBytesRead; // Divide this number of bytes by ( sizeof(float) * 3 ) to have the number of points
    float                 m_Roll;
    float                 m_Pitch;
    float                 m_Yaw;
    float                 m_Tag[ 3 ];
    long                  m_TagNbBytesRead;

    SScanLineData()
    : m_nbBytesRead( 0 )
    , m_Roll( 0 )
    , m_Pitch( 0 )
    , m_Yaw( 0 )
    , m_TagNbBytesRead( 0 )
    {
        m_pointsBuffer.reserve( 2000 );
        m_Tag[ 0 ] = m_Tag[ 1 ] = m_Tag[ 2 ] = 0.0;
    }
};

// =================================================================================================
//   Data receiver class.
// -------------------------------------------------------------------------------------------------
class CCompanyNameScannerReceiver : public CScanningProfilesUser
{

public:

    // Public member functions
    ////////////////////////////

    virtual ~CCompanyNameScannerReceiver();

    void ConflictingPluginsDisconnect();

    void Reset();

    void NbLinesToAccumulateSet( int nbLines_ ) { m_nbLinesToAccumulate = nbLines_; }
    long NbPointsRecordedGet()                  { return m_nbPointsRecorded; }
    void RefreshDelaySet( int refreshDelay_ )   { m_refreshDelay = refreshDelay_; }

    void EnableAutoViewpoint( bool use_ );
    void EnableRealTimeInspection( bool use_ );
    void EnableRealTimeMeshing( bool use_ );

    void PrepareData(
        float                  Roll_,
        float                  Pitch_,
        float                  Yaw_,
        std::vector< PointF >& pointsBuffer_,
        SAFEARRAY**            ppVector_,
        SAFEARRAY*&            pCoordsRef_ );

    void DlgIMAlignOptionsShow( CWnd* pParent_ );
    void DlgIMInspectOptionsShow( CWnd* pParent_ );
    bool DlgOptionsLog( const std::wstring& logFilePath_ );
    bool InterfacePopdown();
    bool InterfacePopup();

    void CursorSegmentsMaxDistSet( double cursorSegmentsMaxDist_ ) { m_cursorSegmentsMaxDist = cursorSegmentsMaxDist_; }
    void CursorSend( PointF* points_, int nbPoints_, float roll_, float pitch_, float yaw_ );

    bool Connect();
    void ConnectionStateUpdate( const bool connected_ );
    bool Disconnect();
    bool ReceiveScanData( IIMLineScan* pLineScan_, IIMPointCloud* pPointCloud_ );
    void ReceiveScanDataCancel();
    bool SendNewData( bool all_ );

    void InitLineScanPtr( IIMLineScan* pLineScan_, IIMPointCloud* pPointCloud_ );
    void ResetLineScanPtr();

    bool ScanStart();
    bool ScanEnd();

    bool DoAcquisitionStart();
    bool DoAcquisitionEnd();
    bool IsAcquisitionStarted() { return m_acquisitionIsStarted; }

    bool DoPassStart();
    bool DoPassEnd();
    bool IsPassStarted() { return m_passIsStarted; }

    bool ScanningObjectsGet(
        EScanTypes    scanType_,
        TWStrings&    objectNames_,
        std::wstring& currentChoice_ ) const;
    bool ScanningObjectsSet(
        EScanTypes          scanType_,
        const TWStrings&    objectNames_,
        const std::wstring& currentChoice_ );

    void UpdateFromSettings();
    void UpdateSettingsFromApp( bool updateProfileSettings_ );

    void UpdateProfiles() override;

    // Public member variables
    ////////////////////////////

    bool m_newRecordData;

    CThreadHelper m_dataThread;

    CCompanyNameSDKStub m_companyNameSDKStub;

    std::list< SScanLineData > m_Data;
    size_t                     m_DataIterIdx;
    bool                       m_iterFromBeginning;

    CRITICAL_SECTION m_DataRead;
    CRITICAL_SECTION m_DataWrite;

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

    // Private member variables
    /////////////////////////////

    DWORD m_cookieLineScan;
    DWORD m_cookiePointCloud;

    int m_nbLinesToAccumulate;
    int m_refreshDelay;

    SAFEARRAY* m_pVector;
    SAFEARRAY* m_pCoords;
    SAFEARRAY* m_pSizes;
    EScanTypes m_scanType;
    bool       m_useSMIFilter;

    bool m_useAutomaticViewpoint;

    long m_nbPointsRecorded;

    double m_cursorSegmentsMaxDist;

    bool m_acquisitionIsStarted;
    bool m_passIsStarted;
    bool m_scanPassChanging;

    bool m_isUpdatingFromSettings;

    TWStrings    m_surfaceScanName;
    std::wstring m_surfaceScanNameCurrentChoice;
    TWStrings    m_boundaryScanName;
    std::wstring m_boundaryScanNameCurrentChoice;

    std::unique_ptr< CDlgIMInspectOptions > m_pDlgIMInspectOptions;
    std::unique_ptr< CDlgIMAlignOptions >   m_pDlgIMAlignOptions;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
