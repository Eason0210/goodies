#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     ILineScan.h
///    \brief    ILineScan class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "PolyWorksSDK/Object/IPWObject.h"

#include "CLineScanPassConstIterator.h"
#include "CLineScanPassIterator.h"
#include "CPWObjectStatus.h"
#include "IPointCloud.h"
#include "../Geom/CUnitVector.h"

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
///
///    \brief    Interface giving access to line scan objects. Note that ILineScan class derives from
///              IPointCloud so every line scan object can act as a point cloud.
///
///              ILineScan objects contain ILineScanPass objects. ILineScanPass objects regroup ILineScanLine
///              objects. With a ILineScanLine object, you can retrieve the lines points in the original order
///              from which they were scanned.
///
///              Note that you will be able to access and modify points and normals coordinates. You will not
///              be able to add points and/or normals directly from these classes. If you want to do so, you
///              will need to add your points via ILineScan::LineAdd.
///
///              The following geometries are available for this object:
///              <table border>
///                <tr>
///                  <td><b> Geometry </b></td>
///                  <td><b> Description </b></td>
///                </tr>
///                <tr>
///                  <td> IBBox </td>
///                  <td> Represents the bounding box containing all of the ILineScan points. <br/> The bounding box is aligned to the coordinate system axis. </td>
///                </tr>
///                <tr>
///                  <td> IPointArray </td>
///                  <td> Gives an access to all points in the ILineScan object. </td>
///                </tr>
///                <tr>
///                  <td> IPointWithNormalArray </td>
///                  <td> Same as the IPointArray except that you have access to the normals. </td>
///                </tr>
///              </table>
///
///              The following properties are available for this object:
///              <table border>
///                <tr>
///                  <td><b> Property Type Function  </b></td>
///                  <td><b> Description </b></td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyColorTypeGet </td>
///                  <td> Returns the objects color. </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyDataTypeGet </td>
///                  <td> Returns whether the object is a data object (PolyWorks|Inspector only). </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyElementsTypeGet </td>
///                  <td> Returns the elements properties (element visibility, selection etc.). </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyFocusedTypeGet </td>
///                  <td> Returns whether the object is focused in the Tree View. </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyNameTypeGet </td>
///                  <td> Returns the objects name. </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyReferenceTypeGet </td>
///                  <td> Returns whether the object is a reference object (PolyWorks|Inspector only). </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertySelectedTypeGet </td>
///                  <td> Returns whether the object is selected in the Tree View. </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyTransformationTypeGet </td>
///                  <td> Returns the objects transformation matrix. </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyUsedTypeGet </td>
///                  <td> Returns whether the object is used. </td>
///                </tr>
///                <tr>
///                  <td> PWOPropertyVisibleTypeGet </td>
///                  <td> Returns whether the object is visible. </td>
///                </tr>
///              </table>
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class ILineScan : public IPointCloud
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Creates a new ILineScan object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ILineScan() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~ILineScan() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns an iterator to the first pass of the current line scan object.
    ///
    ///    \return    Iterator to the first pass of the current line scan object.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CLineScanPassIterator      LineScanPassBegin()       = 0;
    virtual CLineScanPassConstIterator LineScanPassBegin() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns an iterator to the end of the passes collection.
    ///
    ///    \return    Iterator to the end of the passes collection.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CLineScanPassIterator      LineScanPassEnd()       = 0;
    virtual CLineScanPassConstIterator LineScanPassEnd() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the array of points contained in the point cloud. This array
    ///              of points will contains all points, whether or not they have normals. Note that
    ///              the points within the returned IPointArray do not have any particular order; if
    ///              you want the points original order, you must use ILineScan::LineScanPassBegin and
    ///              ILineScan::LineScanPassEnd and finally get the points from the ILineScanLine class.
    ///
    ///    \return   The array of points without normal of the point cloud object. Here are the restrictions
    ///              and specific notes for the returned object:
    ///              <table border>
    ///                <tr>
    ///                  <td><b> Method </b></td>
    ///                  <td><b> Restriction/Specific Note </b></td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Add </td>
    ///                  <td> Operation not supported. <br/> You cannot freely add points to a line scan; you can only add points within new lines using ILineScan::LineAdd method.</td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Clear </td>
    ///                  <td> Operation not supported. <br/> It is impossible to remove a point from a ILineScan object. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> EraseAt </td>
    ///                  <td> Operation not supported. <br/> It is impossible to remove a point from a ILineScan object. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///              </table>
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IPointArray* PointArrayGet() const = 0;
    virtual IPointArray*       PointArrayGet()       = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the array of points with normal contained in the line scan. This array
    ///              of points will contains all points, whether or not they have normals. You will determine if
    ///              a point has a normal by calling IPointWithNormalArray::HasNormal. Note that the points within
    ///              the returned IPointWithNormalArray do not have any particular order; if you want the points
    ///              original order, you must use ILineScan::LineScanPassBegin and ILineScan::LineScanPassEnd and
    ///              finally get the points from the ILineScanLine class.
    ///
    ///              This array will still contain all points even if the point cloud has no normals at all. In
    ///              this case, IPointWithNormalArray::HasNormal will always return false.
    ///
    ///    \return   The array of points (without normal) of the point cloud object. Here are the restrictions
    ///              and specific notes for the returned object:
    ///              <table border>
    ///                <tr>
    ///                  <td><b> Method </b></td>
    ///                  <td><b> Restriction/Specific Note </b></td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Add </td>
    ///                  <td> Operation not supported. <br/> You cannot freely add points to a line scan; you can only add points within new lines using ILineScan::LineAdd method.</td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Clear </td>
    ///                  <td> Operation not supported. <br/> It is impossible to remove a point from a ILineScan object. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> EraseAt </td>
    ///                  <td> Operation not supported. <br/> It is impossible to remove a point from a ILineScan object. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///              </table>
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IPointWithNormalArray* PointWithNormalArrayGet() const = 0;
    virtual IPointWithNormalArray*       PointWithNormalArrayGet()       = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Insert a new line of points in the line scan object.
    ///
    ///              If this object is attached to a CPWODelayer tool, all the lines added when the tool is attached
    ///              will be stored. When the tool is destroyed, the stored lines will be added as a single pass. If
    ///              the PolyWorks line scan has some normals, the normal extraction algorithm will be
    ///              used to generate normals for these new points prior to adding them to the line scan.
    ///              Note that each pass is completely independent in the normal extraction process.
    ///
    ///              In the PolyWorks|Inspector module, the normal extraction algorithm's distance parameters
    ///              can be configured using the following two commands. They specify the minimum and
    ///              maximum distance to search for the points that will be used to compute a point's
    ///              normal.
    ///
    ///                 - FILE IMPORT_DATA 3D_DIGITIZED_DATASET LINE_SCAN OPTIONS EXTRACT_NORMAL MIN_DIST
    ///                 - FILE IMPORT_DATA 3D_DIGITIZED_DATASET LINE_SCAN OPTIONS EXTRACT_NORMAL MAX_DIST
    ///
    ///              If this object is not attached to a CPWODelayer, each line will be added
    ///              in a different pass. In this case, it is impossible to extract any normals for these
    ///              new points.
    ///
    ///    \param[ in ] pLine                The array of points for the new line.
    ///    \param[ in ] digitizingVector_    The direction from the object to the scanner for the
    ///                                      new line.
    ///
    ///    \return    Indicate if the operation was successful.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CPWObjectStatus LineAdd( const IPointArray* pLine, const CUnitVector& digitizingVector_ ) = 0;

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
