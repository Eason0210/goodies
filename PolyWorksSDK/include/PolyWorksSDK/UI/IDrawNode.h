#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IDrawNode.h
///    \brief    IDrawNode class
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CWString.h>

namespace IM { class IBBox; }
namespace IM { class IRenderer; }

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
///    \brief    Class used to render geometries into the 3D Scene. To do so, you must derive a class
///              from IDrawNode and override NameGet and Draw. You must add your draw node to IDrawNodes
///              in order to make sure that your rendering routine is called. There may exist as
///              many draw nodes as you want. Please, see IDrawNodes documentation for more information.
///
////////////////////////////////////////////////////////////////////////////////////////////////////
class IDrawNode
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    IDrawNode() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~IDrawNode() {}


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the bounding box of all three-dimensional geometries present in the drawing
    ///              node.
    ///
    ///    \return    The three-dimensional bounding box.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual const IBBox& BBoxGet() const = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Method called for IDrawNode objects added to the draw nodes collection via IDrawNodes::Add.
    ///              This method will be called as soon as the 3D Scene needs a refresh. The IRenderer
    ///              engine will be passed to this function so that you can do basic rendering of geometries.
    ///
    ///
    ///    \param[ in ] renderer_    Reference to the IRenderer engine
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void Draw( IRenderer& renderer_ ) = 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Returns the name of the draw node. Make sure your name is unique because there cannot
    ///              be two draw nodes with the same name in the draw nodes tree. To make sure the string
    ///              you return is unique, we suggest you prefix your draw node name by your company
    ///              name. For example: L"InnovMetricSoftwareBoundaryComparison"
    ///
    ///    \return    Unique draw nodes name.
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CWString NameGet() const = 0;


protected:
    // ---------------- Protected methods ----------------------------------------------------------

    // ---------------- Protected Member Variables -------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------

};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
