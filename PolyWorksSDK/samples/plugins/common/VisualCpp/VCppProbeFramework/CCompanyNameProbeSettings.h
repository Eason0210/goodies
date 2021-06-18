#ifndef _CCOMPANYNAMEPROBESETTINGS_FRIDAY_OCTOBER252013_094236_H_
#define _CCOMPANYNAMEPROBESETTINGS_FRIDAY_OCTOBER252013_094236_H_
// =================================================================================================
//   User configuration setting management
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include <string>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================
enum ECompMethods;
enum ERecordModes;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   User configuration setting management
// -------------------------------------------------------------------------------------------------
class CCompanyNameProbeSettings
{
public:
    virtual ~CCompanyNameProbeSettings() { }

    // IIMSettings
    STDMETHODIMP DoubleSettingsNbGet(
        /* [out] */ long __RPC_FAR* nbSettings_ );

    STDMETHODIMP DoubleSettingGet(
        /* [in] */ long                     settingIndex_,
        /* [out] */ BSTR __RPC_FAR*         pSettingName_,
        /* [out] */ double __RPC_FAR*       pDefaultValue_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ );

    STDMETHODIMP LongSettingsNbGet(
        /* [out] */ long __RPC_FAR* nbSettings_ );

    STDMETHODIMP LongSettingGet(
        /* [in] */ long                     settingIndex_,
        /* [out] */ BSTR __RPC_FAR*         pSettingName_,
        /* [out] */ long __RPC_FAR*         pDefaultValue_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ );

    STDMETHODIMP StringSettingsNbGet(
        /* [out] */ long __RPC_FAR* nbSettings_ );

    STDMETHODIMP StringSettingGet(
        /* [in] */ long                     settingIndex_,
        /* [out] */ BSTR __RPC_FAR*         pSettingName_,
        /* [out] */ BSTR __RPC_FAR*         pDefaultValue_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ );

    // IIMSettings2
    STDMETHODIMP MatrixSettingsNbGet(
        /* [retval][out] */ long* pNbSettings_ );

    STDMETHODIMP MatrixSettingGet(
        /* [in] */ long               settingIndex_,
        /* [out][in] */ BSTR*         pSettingName_,
        /* [out][in] */ SAFEARRAY**   pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsProjectSetting_ );

    // Get
    double       AutomaticTriggerDistanceGet();
    ECompMethods CompensationMethodGet();
    long         ContinuousTimeDelayGet();
    double       ContinuousDistanceDistGet();
    double       HostUnitsScalingFactorGet() const;
    ERecordModes ModeGet();
    long         MeasurementAutomaticTriggerStabilityDelayGet();
    double       MeasurementAutomaticTriggerStabilityToleranceGet();
    bool         UseAutomaticTriggerGet();
    bool         UseMeasurementAutomaticTriggerGet();
    bool         UseProbeAsMouseGet();


    // Set
    void AutomaticTriggerDistanceSet( double automaticTriggerDistance_ );
    void CompensationMethodSet( ECompMethods compensationMethod_ );
    void ContinuousTimeDelaySet( long delay_ );
    void ContinuousDistanceDistSet( double dist_ );
    bool HostUnitsScalingFactorSet( double scalingFactor_ );
    void ModeSet( ERecordModes mode_ );
    void MeasurementAutomaticTriggerStabilityDelaySet( long delay_ );
    void MeasurementAutomaticTriggerStabilityToleranceSet( double tolerance_ );
    void UseAutomaticTriggerSet( bool use_ );
    void UseMeasurementAutomaticTriggerSet( bool use_ );
    void UseProbeAsMouseSet( bool use_ );

protected:

private:
    friend CCompanyNameProbeSettings& theCompanyNameProbeSettings();
    CCompanyNameProbeSettings();

    double m_hostUnitsScalingFactor; // Conversion factor from mm to application units
};

template< int N_ELE >
class MatrixD
{
public:
    MatrixD() { Identity(); }
    void Identity()
    {
        for ( int i = 0; i < N_ELE; ++i )
        {
            for ( int j = 0; j < N_ELE; ++j )
            {
                m_mat[ i ][ j ] = ( ( i == j ) ? 1.0 : 0.0 );
            }
        }
    }
    double& operator()( int row_, int col_ )
    {
        if ( ( row_ >= 0 && row_ < N_ELE ) &&
             ( col_ >= 0 && col_ < N_ELE ) )
        {
            return m_mat[ row_ ][ col_ ];
        }
        else
        {
            static double zero = 0.0;
            return zero;
        }
    }
    const double& operator()( int row_, int col_ ) const
    {
        if ( ( row_ >= 0 && row_ < N_ELE ) &&
             ( col_ >= 0 && col_ < N_ELE ) )
        {
            return m_mat[ row_ ][ col_ ];
        }
        else
        {
            static double zero = 0.0;
            return zero;
        }
    }

private:
    double m_mat[ N_ELE ][ N_ELE ];
};

typedef class MatrixD< 4 > Matrix4D;

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

CCompanyNameProbeSettings& theCompanyNameProbeSettings();

#endif // _CCOMPANYNAMEPROBESETTINGS_FRIDAY_OCTOBER252013_094236_H_
