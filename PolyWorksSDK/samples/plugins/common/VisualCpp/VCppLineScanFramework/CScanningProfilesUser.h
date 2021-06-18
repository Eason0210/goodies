#pragma once

// =================================================================================================
//   CScanningProfilesUser class.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Class used to manage scanning profiles.
// -------------------------------------------------------------------------------------------------
class CScanningProfilesUser
{
public:
    // --------------  Publics types  -------------------------------------------------------------

    // --------------  Publics methods ------------------------------------------------------------
    CScanningProfilesUser();
    virtual ~CScanningProfilesUser();

    void ScanningProfilesGet(
        TWStrings&    profileCmdArgNames_,
        TWStrings&    profileDisplayNames_,
        TWStrings&    profileAddtionnalInfos_,
        std::wstring& currentProfile_ ) const;
    void ScanningProfilesSet(
        const TWStrings&    profileCmdArgNames_,
        const TWStrings&    profileDisplayNames_,
        const TWStrings&    profileAddtionnalInfos_,
        const std::wstring& currentProfile_ );
    void ScanningProfilesReset();

    // Purely virtual methods
    virtual void UpdateProfiles() = 0;

protected:
    // --------------- Protected methods  ----------------------------------------------------------

    // --------------- Protected member variables  -------------------------------------------------
    TWStrings    m_profileCmdArgNames;             // Profile names used for command arguments
    TWStrings    m_profileDisplayNames;            // Profile display names
    TWStrings    m_profileAddtionalInfos;          // Profile additional information
    std::wstring m_currentProfile;                 // Current profile (one of the m_profileCmdArgNames profiles)
};



// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
