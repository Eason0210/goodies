#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \file     IDrawNodes.h
///    \brief    IDrawNodes class.
///
///    \copyright InnovMetric Logiciels Inc. Copyright ( C ) 2007 All Rights Reserved All rights reserved
///
/// ************************************************************************** */

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <PolyWorksSDK/Base/CWString.h>
#include <PolyWorksSDK/UI/DrawNodeTypes.h>
#include "FnIDrawNodes.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

namespace IM
{

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

class IDrawNode;

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

////////////////////////////////////////////////////////////////////////////////////////////////////
///
///    \ingroup  IM_INTERFACES
///
///    \brief    Class managing the addition and removal of draw nodes into our rendering tree. Using
///              draw nodes is the only way for a plugin to render geometries into the 3D Scene.
///              You can retrieve a pointer to this class by calling DrawNodesGet from IScene.
///
/// ************************************************************************** */
class IDrawNodes
{
public:
    // ---------------- Public Types  --------------------------------------------------------------

    // ---------------- Public Methods  ------------------------------------------------------------

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Default constructor.
    ///
    /// ************************************************************************** */
    IDrawNodes() {}

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Destructor.
    ///
    /// ************************************************************************** */
    virtual ~IDrawNodes() {}

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Adds a draw node into the host applications rendering tree. You must derive your
    ///              own class from IDrawNode and pass a pointer to it to this function. It is the plug-ins
    ///              responsability not to delete the pointer until IDrawNodes::Remove is called. It
    ///              is also the plug-in responsability to delete the pointer returned by IDrawNodes::Remove.
    ///              In order to make the rendering as effective and nice as possible, you will have
    ///              to clasify the kind of rendering nodes you add. This is done by passing the drawNodeType_
    ///              argument. For example, a draw node rendering in XOR will need to draw it's geometry
    ///              after another draw node rendering flat triangles. See the documentation EDrawNodeType
    ///              to find out about each of the draw node types.  Note that you cannot add the same
    ///              draw node twice, it has to have a unique name (defined by IDrawNode::NameGet).
    ///
    ///    \param[ in ] pDrawNode_       Pointer to the draw node to add.
    ///    \param[ in ] drawNodeType_    Type of draw node defining the kind of rendering done
    ///
    ///    \return    true if the draw node has been succesfully added, false otherwise
    ///
    /// ************************************************************************** */
    virtual bool Add( IDrawNode* pDrawNode_, EDrawNodeType drawNodeType_ ) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    ///    \brief    Removes a draw node (previously added) from the draw node's tree. Each time you add
    ///              a draw node, make sure you remove it when it is not needed anymore. After calling
    ///              Remove, make sure you free any memory associated to your draw node.
    ///
    ///    \param[ in ] pDrawNodeName_    Unique name identifying the draw node you previously added
    ///                                   This is the same name returned by IDrawNode::NameGet.
    ///
    ///    \return    Pointer to the removed draw node. NULL if the draw node was not found.
    ///
    /// ************************************************************************** */
    virtual IDrawNode* Remove( const CWString& pDrawNodeName_ ) = 0;

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
