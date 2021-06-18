#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     DrawNodeTypes.h
///    \brief    Constants defining types of draw nodes.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

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
///    \ingroup  IM_ENUMERATIONS
///
///    \brief    Depending on the type of a draw node, it will be added at a different place in the
///              drawing tree. This will affect the order in which the nodes are drawn:
/// ************************************************************************** */
enum EDrawNodeType
{
    E_DRAW_NODE_TYPE_BEGIN,
    E_DRAW_NODE_TYPE_3D = E_DRAW_NODE_TYPE_BEGIN,  /*!< This type should be assigned to the nodes drawing elements that are positioned in
                                                        three-dimensional space, such as points, polylines and triangles. The coordinates
                                                        units are usually in millimeters or inches. */
    E_DRAW_NODE_TYPE_2D,                           /*!< This type should be assigned to the nodes drawing elements that are positioned
                                                        in the two-dimensional screen viewport, such as points and polylines and text.
                                                        The elements will be drawn over all three-dimensional objects in the viewport.
                                                        The coordinates units are in pixels. */
    E_DRAW_NODE_TYPE_XOR,                          /*!< This type should be assigned to the nodes drawing
                                                        elements that are to be drawn in XOR, such as points and polylines. The elements
                                                        will be drawn over all elements in the viewport and can be used to give an highlighting
                                                        effect to some curves or points. */
    E_DRAW_NODE_TYPE_END
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

} // namespace IM
