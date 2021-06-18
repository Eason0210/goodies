#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     CColorRGBA.h
///    \brief    This file contains the declaration of the CColorRGBA color object.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/PolyWorksSDKApi.h>

#include "PolyWorksSDK/Base/FnCColorRGBA.h" // IWYU pragma: keep

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_CLASSES
///
///    \brief    The CColorRGBA color object. Represents a color with four components: red, green,
///              blue and alpha.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class POLYWORKS_SDK_API CColorRGBA
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Creates a new CColorRGBA object. The color is white ( 255, 255, 255, 255 ).
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CColorRGBA();

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Creates a new CColorRGBA object.
    ///
    ///    \param[ in ] red_      The red component.
    ///    \param[ in ] green_    The green component.
    ///    \param[ in ] blue_     The blue component.
    ///    \param[ in ] alpha_    The alpha component (default is 255 ).
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    CColorRGBA( unsigned char red_,
                unsigned char green_,
                unsigned char blue_,
                unsigned char alpha_ = 255 );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ~CColorRGBA();


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Color component access operator.
    ///
    ///    \param[ in ] idx_    The index of the desired component:
    ///                         - 0 for the red component
    ///                         - 1 for the green component
    ///                         - 2 for the blue component
    ///                         - 3 for the alpha component
    ///
    ///    \return    A reference to the desired component.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const unsigned char& operator[] ( unsigned int idx_ ) const;
    unsigned char&       operator[] ( unsigned int idx_ );


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Read-only access operator.
    ///
    ///    \return    A constant pointer to the array of the color's components.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    const unsigned char* const Get() const;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Affectation function. Sets the components of the RGBA color.
    ///
    ///    \param[ in ] red_      The red component.
    ///    \param[ in ] green_    The green component.
    ///    \param[ in ] blue_     The blue component.
    ///    \param[ in ] alpha_    The alpha component (default is 255 ).
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    void Set( unsigned char red_,
              unsigned char green_,
              unsigned char blue_,
              unsigned char alpha_ = 255 );

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

    unsigned char m_colors[ 4 ];

};


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================


} // namespace IM
