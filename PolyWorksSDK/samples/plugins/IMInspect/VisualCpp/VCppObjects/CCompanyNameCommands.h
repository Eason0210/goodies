#ifndef _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
#define _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
// =================================================================================================
//   Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "CComCommand.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// Pops up message boxes giving information about the selected objects.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNamePolyWorksObjectRead : public CComCommand
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyNamePolyWorksObjectRead( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNamePolyWorksObjectRead();

    STDMETHODIMP ArgsTest( /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
                           /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );
    STDMETHODIMP Execute2( /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
                           /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// Add new passes to selected ILineScan objects.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNamePolyWorksObjectILineScanAddLine : public CComCommand
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyNamePolyWorksObjectILineScanAddLine( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNamePolyWorksObjectILineScanAddLine();

    STDMETHODIMP Execute2( /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
                           /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};


// =================================================================================================
// Add noise to each points in the selected IPointCloud objects.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise : public CComCommand
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise();

    STDMETHODIMP Execute2( /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
                           /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};


// =================================================================================================
// Apply a 1:10 subsampling to the selected IPointCloud objects.
// -------------------------------------------------------------------------------------------------
class CCmdCompanyNamePolyWorksObjectIPointCloudSubsample : public CComCommand
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------
    CCmdCompanyNamePolyWorksObjectIPointCloudSubsample( CComCommandInfo& info_ );
    virtual ~CCmdCompanyNamePolyWorksObjectIPointCloudSubsample();

    STDMETHODIMP Execute2( /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
                           /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================


#endif // _CCOMPANYNAMECOMMANDS_TUESDAY_AUGUST07_085131_H_
