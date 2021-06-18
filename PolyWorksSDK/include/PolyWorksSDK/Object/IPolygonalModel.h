#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IPolygonalModel.h
///    \brief    This file contains the interface declaration for a polygonal model that can be found
///              in a polyworks project.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
////////////////////////////////////////////////////////////////////////////////////////////////////

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Object/IPWObject.h>

namespace IM { class IPointArray; }
namespace IM { class IPointWithNormalArray; }
namespace IM { class ITriangleArray; }

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ========================================= NAMESPACES ============================================

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
///    \brief    The interface for a polygonal model object.
///
///              Note that in PolyWorks|Inspector, polygonal models are all represented by the IPolygonalModel class. You
///              may differentiate data objects from reference objects properties of type returned by
///              PWOPropertyDataTypeGet and PWOPropertyReferenceTypeGet.
///
///              The following geometries are available for this object:
///              <table border>
///                <tr>
///                  <td><b> Geometry </b></td>
///                  <td><b> Description </b></td>
///                </tr>
///                <tr>
///                  <td> IBBox </td>
///                  <td> Represents the bounding box containing all points. <br/> The bounding box is aligned to the coordinate system axis. </td>
///                </tr>
///                <tr>
///                  <td> IPointArray </td>
///                  <td> Gives an access to all points. </td>
///                </tr>
///                <tr>
///                  <td> IPointWithNormalArray </td>
///                  <td> Same as the IPointArray except that you have access to the normals. </td>
///                </tr>
///                <tr>
///                  <td> ITriangleArray </td>
///                  <td> Triangle array linked to IPointArray. Note that IPointArray and IPointWithNormalArray are the exact same geometry except that you have access to normals using the IPointWithNormalArray geometry.</td>
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
class IPolygonalModel : public IPWObject
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IPolygonalModel() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IPolygonalModel() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the array of points contained in the polygonal model.
    ///
    ///    \return   The array of points without normal of the polygonal model. Here are the restrictions
    ///              and specific notes for the returned object:
    ///              <table border>
    ///                <tr>
    ///                  <td><b> Method </b></td>
    ///                  <td><b> Restriction/Specific Note </b></td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Add </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Clear </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> EraseAt </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> PointSetAt </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. </td>
    ///                </tr>
    ///              </table>
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IPointArray* PointArrayGet() const = 0;
    virtual IPointArray*       PointArrayGet()       = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the array of points with normal contained in the polygonal model.
    ///
    ///    \return   The array of points with normal of the polygonal model. Here are the restrictions
    ///              and specific notes for the returned object:
    ///              <table border>
    ///                <tr>
    ///                  <td><b> Method </b></td>
    ///                  <td><b> Restriction/Specific Note </b></td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Add </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Clear </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> EraseAt </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> NormalSetAt </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> PointSetAt </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. </td>
    ///                </tr>
    ///              </table>
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IPointWithNormalArray* PointWithNormalArrayGet() const = 0;
    virtual IPointWithNormalArray*       PointWithNormalArrayGet()       = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns a pointer to the array of triangles contained in the polygonal model.
    ///
    ///    \return   The array of triangles of the polygonal model. Here are the restrictions and specific notes
    ///              for the returned object:
    ///              <table border>
    ///                <tr>
    ///                  <td><b> Method </b></td>
    ///                  <td><b> Restriction/Specific Note </b></td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Add </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> Clear </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> EraseAt </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. <br/> To virtually erase points, use the pointer (IPWOElementsProperties) returned by the PWOPropertyElementsTypeGet property. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> PointSetAt </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. </td>
    ///                </tr>
    ///                <tr>
    ///                  <td> TriangleSetAt </td>
    ///                  <td> Operation not supported. <br/> IPolygonalModel object geometries are read-only. </td>
    ///                </tr>
    ///              </table>
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const ITriangleArray* TriangleArrayGet() const = 0;
    virtual ITriangleArray*       TriangleArrayGet()       = 0;


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
