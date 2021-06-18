#ifndef _IRECEIVER_THURSDAY_OCTOBER242013_103359_H_
#define _IRECEIVER_THURSDAY_OCTOBER242013_103359_H_
// =================================================================================================
//   Interface used by the proprietary SDK to communicate with the plug-in main implementation
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================
#include <PolyWorksSDK/COM/IMTypes.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================
struct SProbePosition;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Interface used by the proprietary SDK to communicate with the plug-in main implementation
// -------------------------------------------------------------------------------------------------
class IReceiver
{
public:

    IReceiver() {}
    virtual ~IReceiver() {}

    virtual void OnButtonPressed( const unsigned int buttonIdentifier_ )  = 0;
    virtual void OnButtonReleased( const unsigned int buttonIdentifier_ ) = 0;

    virtual void OnPointAcquired( const SProbePosition& update_ )   = 0;
    virtual void OnPositionChanged( const SProbePosition& update_ ) = 0;

    virtual void UpdateConnectionState( const bool connected_ )    = 0;
    virtual void UpdateDeviceStatus( const EDeviceStatus status_ ) = 0;
    virtual void UpdateProbeDiameter( const double diameter_ )     = 0;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

#endif // _IRECEIVER_THURSDAY_OCTOBER242013_103359_H_
