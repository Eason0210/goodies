#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPointCloud.h
///    \brief    This file contains the interface declaration for a point cloud that can be found
///              in a project.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Object/IPWObject.h>

namespace IM { class IPointArray; }
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
///     \brief    The interface for a point cloud object.
///
///               Note that in PolyWorks|Inspector, point cloud are unorganized (unless you use ILineScan object).
///
///               Note that in PolyWorks|Inspector, adding points to a point cloud objet will clear the undo stack of the
///               module.
///
///               The following geometries are available for this object:
///              <table border>
///                <tr>
///                  <td><b> Geometry </b></td>
///                  <td><b> Description </b></td>
///                </tr>
///                <tr>
///                  <td> IBBox </td>
///                  <td> Represents the bounding box containing all of the IPointCloud points. <br/> The bounding box is aligned to the coordinate system axis. </td>
///                </tr>
///                <tr>
///                  <td> IPointArray </td>
///                  <td> Gives an access to all points in the IPointCloud object. </td>
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
class IPointCloud : public IPWObject
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPointCloud() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPointCloud() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the array of points contained in the point cloud. This array
    ///              of points will contains all points, whether or not they have normals. Note that
    ///              the points within the returned IPointArray do not have any particular order.
    ///
    ///    \return   The array of points without normal of the point cloud object. Here are the restrictions
    ///               and specific notes for the returned object:
    ///              <table border>
    ///                <tr>
    ///                  <td><b> Method </b></td>
    ///                  <td><b> Restriction/Specific Note </b></td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Add </td>
    ///                  <td> The order in which points are added is not garantied since the point cloud is unorganized.</td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Clear </td>
    ///                  <td> Operation not supported. <br/> It is impossible to remove a point from a IPointCloud object. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> EraseAt </td>
    ///                  <td> Operation not supported. <br/> It is impossible to remove a point from a IPointCloud object. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///              </table>
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IPointArray* PointArrayGet() const = 0;
    virtual IPointArray*       PointArrayGet()       = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the array of points with normal contained in the point cloud.
    ///              This array of points will contains all points, whether or not they have normals.
    ///              You will determine if a point has a normal by calling IPointWithNormalArray::HasNormal.
    ///              Note that the points within the returned IPointWithNormalArray do not have any particular
    ///              order.
    ///
    ///              This array will still contain all points even if the point cloud has no
    ///              normals at all. In this case, IPointWithNormalArray::HasNormal will always return
    ///              false.
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
    ///                  <td> The order in which points are added is not garantied since the point cloud is unorganized.</td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Clear </td>
    ///                  <td> Operation not supported. <br/> It is impossible to remove a point from a IPointCloud object. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> EraseAt </td>
    ///                  <td> Operation not supported. <br/> It is impossible to remove a point from a IPointCloud object. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
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
