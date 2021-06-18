// =================================================================================================
//   CScanningProfilesUser class implementation.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CScanningProfilesUser.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   Ctor
// -------------------------------------------------------------------------------------------------
CScanningProfilesUser::CScanningProfilesUser()
{
}

// =================================================================================================
//   Dtor
// -------------------------------------------------------------------------------------------------
CScanningProfilesUser::~CScanningProfilesUser()
{
}

// =================================================================================================
//   Gets available scanning profiles.
//
// Parameter : profileCmdArgNames_    : Profile names used for command arguments
// Parameter : profileDisplayNames_   : Profile display names
// Parameter : profileAddtionalInfos_ : Profile additional information
// Parameter : currentProfile_        : Current profile
// -------------------------------------------------------------------------------------------------
void CScanningProfilesUser::ScanningProfilesGet( TWStrings&    profileCmdArgNames_,
                                                 TWStrings&    profileDisplayNames_,
                                                 TWStrings&    profileAddtionalInfos_,
                                                 std::wstring& currentProfile_ ) const
{
    profileCmdArgNames_    = m_profileCmdArgNames;
    profileDisplayNames_   = m_profileDisplayNames;
    profileAddtionalInfos_ = m_profileAddtionalInfos;
    currentProfile_        = m_currentProfile;
}

// =================================================================================================
//   Sets available scanning profiles.
//
// Parameter : profileCmdArgNames_    : Profile names used for command arguments
// Parameter : profileDisplayNames_   : Profile display names
// Parameter : profileAddtionalInfos_ : Profile additional information
// Parameter : currentProfile_        : Current profile
// -------------------------------------------------------------------------------------------------
void CScanningProfilesUser::ScanningProfilesSet( const TWStrings&    profileCmdArgNames_,
                                                 const TWStrings&    profileDisplayNames_,
                                                 const TWStrings&    profileAddtionalInfos_,
                                                 const std::wstring& currentProfile_ )
{
    m_profileCmdArgNames    = profileCmdArgNames_;
    m_profileDisplayNames   = profileDisplayNames_;
    m_profileAddtionalInfos = profileAddtionalInfos_;
    m_currentProfile        = currentProfile_;

    UpdateProfiles();
}

// =================================================================================================
//   Resets (clear) available scanning profiles.
// -------------------------------------------------------------------------------------------------
void CScanningProfilesUser::ScanningProfilesReset()
{
    ScanningProfilesSet( TWStrings(), TWStrings(), TWStrings(), L"" );
}
