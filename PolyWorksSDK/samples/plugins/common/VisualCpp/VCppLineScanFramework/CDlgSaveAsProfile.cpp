// =================================================================================================
//   Save As profile dialog.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CDlgSaveAsProfile.h"

#include <assert.h>

#include "ApplicationUtils.h"
#include "CCompanyNameScannerReceiver.h"
#include "CCompanyNameScannerSettings.h"

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
CDlgSaveAsProfile::CDlgSaveAsProfile( CWnd* pParent_ /*= nullptr*/ )
: CDialog( IDD, pParent_ )
, m_pReceiver( nullptr )
{

}


// =================================================================================================
//   Dtor
// -----------------------------------------------------------------------------
CDlgSaveAsProfile::~CDlgSaveAsProfile()
{
}


// =================================================================================================
// Message map.
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CDlgSaveAsProfile, CDialog )
END_MESSAGE_MAP()

// =================================================================================================
//   MFC function to transfer data between GUI and variables.
// -------------------------------------------------------------------------------------------------
void CDlgSaveAsProfile::DoDataExchange( CDataExchange* pDX_ )
{
    __super::DoDataExchange( pDX_ );

    DDX_Control( pDX_, IDC_COMBO_USER_PROFILE, m_comboUserProfile );
}


// =================================================================================================
//   Handling the WM_INITDIALOG message
// -------------------------------------------------------------------------------------------------
BOOL CDlgSaveAsProfile::OnInitDialog()
{
    // Ask the base class to do the rest
    BOOL result = __super::OnInitDialog();

    auto* pScanningProfilesUser = dynamic_cast< CScanningProfilesUser* >( m_pReceiver );
    if ( pScanningProfilesUser != nullptr )
    {
        TWStrings    profileCmdArgNames;
        TWStrings    profileDisplayNames;
        TWStrings    profileAdditionalInfos;
        std::wstring currentProfile;

        pScanningProfilesUser->ScanningProfilesGet( profileCmdArgNames, profileDisplayNames, profileAdditionalInfos, currentProfile );

        if ( profileCmdArgNames.size() == profileDisplayNames.size() )
        {
            for ( int iProfile = 0; static_cast< size_t >( iProfile ) < profileDisplayNames.size(); ++iProfile )
            {
                // Display name is empty for user profile
                if ( profileDisplayNames[ iProfile ].empty() )
                {
                    m_comboUserProfile.AddString( profileCmdArgNames[ iProfile ].c_str() );
                }
            }
        }
    }

    return result;
}


// =================================================================================================
//   Handling the OK button (Enter)
// -------------------------------------------------------------------------------------------------
void CDlgSaveAsProfile::OnOK()
{
    CString profileName;
    m_comboUserProfile.GetWindowText( profileName );

    std::wstring cmd;
    cmd  = L"DIGITIZE DEVICE SCAN PROFILE SAVE_AS ( \"";
    cmd += profileName;
    cmd += L"\" )";
    if ( ExecuteCommandOnApp( cmd.c_str(), true, true ) )
    {
        __super::OnOK();
    }
}


// =================================================================================================
//   Obtain the X position of the window
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgSaveAsProfile::WindowPositionXGet()
{
    return theCompanyNameScannerSettings().IMISaveAsWindowPositionXGet();
}


// =================================================================================================
//   Set the X position of the window
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgSaveAsProfile::WindowPositionXSet( long position_ )
{
    theCompanyNameScannerSettings().IMISaveAsWindowPositionXSet( position_ );
}


// =================================================================================================
//   Obtain the Y position of the window
//
// Return : Position
// -------------------------------------------------------------------------------------------------
long CDlgSaveAsProfile::WindowPositionYGet()
{
    return theCompanyNameScannerSettings().IMISaveAsWindowPositionYGet();
}


// =================================================================================================
//   Sets the Y position of the window
//
// Parameter : position_ : Position
// -------------------------------------------------------------------------------------------------
void CDlgSaveAsProfile::WindowPositionYSet( long position_ )
{
    theCompanyNameScannerSettings().IMISaveAsWindowPositionYSet( position_ );
}
