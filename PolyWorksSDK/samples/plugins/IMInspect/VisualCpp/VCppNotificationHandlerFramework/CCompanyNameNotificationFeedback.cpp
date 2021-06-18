// =================================================================================================
//   Polyworks SDK interface implementation
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include <atlbase.h>
#include <atlcom.h>

#include "CComMessageFilter.h"
#include "CCompanyNameNotificationHandlerConnectionPoint.h"
#include "CCompanyNameNotificationHandlerPlugin.h"
#include "SafeArrayConversion.h"
#include "Types.h"

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
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// Performs conversion from SAFEARRAY(BSTR) to std::vector<std::wstring>
// -------------------------------------------------------------------------------------------------
static TWStrings FromSafeArrayToWStringConvert( SAFEARRAY* uniqueIDs_ )
{
    if ( uniqueIDs_ != nullptr )
    {
        TWStrings uniqueIDs;
        SafeArrayConversion::SafeArrayStringsGet( &uniqueIDs_, uniqueIDs );

        return uniqueIDs;
    }
    return {};
}

// =================================================================================================
// Performs conversion from BSTR to std::wstring
// -------------------------------------------------------------------------------------------------
static std::wstring FromBSTRToWStringConvert( BSTR uniqueID_ )
{
    if ( uniqueID_ != nullptr )
    {
        return std::wstring{ uniqueID_, SysStringLen( uniqueID_ ) };
    }
    return {};
}

// =================================================================================================
// Notifies feedback that a new object notification was received
// -------------------------------------------------------------------------------------------------
HRESULT CCompanyNameNotificationFeedback::OnSafeArrayNotification( SAFEARRAY* uniqueIDs_, std::wstring&& msg_ )
{
    if ( m_pFeedback != nullptr )
    {
        m_pFeedback->OnObjectUniqueIDsReceived( FromSafeArrayToWStringConvert( uniqueIDs_ ), std::move( msg_ ) );
        return S_OK;
    }
    return E_FAIL;
}

// =================================================================================================
// Notifies feedback that a new piece notification was received
// -------------------------------------------------------------------------------------------------
HRESULT CCompanyNameNotificationFeedback::OnBSTRNotification( BSTR uniqueID_, std::wstring&& msg_ )
{
    if ( m_pFeedback != nullptr )
    {
        m_pFeedback->OnPieceUniqueIDReceived( FromBSTRToWStringConvert( uniqueID_ ), std::move( msg_ ) );
        return S_OK;
    }
    return E_FAIL;
}
