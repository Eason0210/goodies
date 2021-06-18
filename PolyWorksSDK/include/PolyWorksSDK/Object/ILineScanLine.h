#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     ILineScanLine.h
///    \brief    ILineScanLine class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Geom/CUnitVector.h>

namespace IM { class IPointWithNormalArray; }

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
///    \ingroup  IM_INTERFACES
///
///    \brief    Interface giving access to a line scan line information. You can get access to ILineScanLine
///              objects by calling the iterators from ILineScanPass.
///
///              From a ILineScanLine, you can get the digitizing vector as well as the points of the line
///              in the original order from which they were scanned. To get access to the points, you will need to
///              call one of the two overloads ILineScanLine::PointWithNormalArrayGet; please refer
///              to this functions documentation for more details.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class ILineScanLine
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Creates a ILineScanLine object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ILineScanLine() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~ILineScanLine() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns scanning direction for this scan line.
    ///
    ///    \return    Scanning direction for this line.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CUnitVector DigitizingVectorGet() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a constant pointer to the array of points with normal contained in the scan
    ///              line. You must not try to free up any memory associated to the returned pointer.
    ///              It is the host applications responsibility to do so.
    ///
    ///    \return   The array of points with normal of the scan line. Here are the restrictions and specific
    ///              notes for the returned object:
    ///              <table border>
    ///                <tr>
    ///                  <td><b> Method </b></td>
    ///                  <td><b> Restriction/Specific Note </b></td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Add </td>
    ///                  <td> Operation not supported. <br/> You cannot add points to existing lines; <br/> you can only add new lines using ILineScan::LineAdd method. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Clear </td>
    ///                  <td> Operation not supported. <br/> It is not possible to remove points from existing lines. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> EraseAt </td>
    ///                  <td> Operation not supported. <br/> It is not possible to remove points from existing lines. </td>
    ///                </tr>
    ///              </table>
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IPointWithNormalArray* PointWithNormalArrayGet() const = 0;
    virtual IPointWithNormalArray*       PointWithNormalArrayGet()       = 0;

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
