' =================================================================================================
' Plug-in's commands.
'
' Copyright © InnovMetric Logiciels Inc. 2012 All Rights Reserved
' -------------------------------------------------------------------------------------------------
Namespace VBNet3DSceneRendering

    ' =============================================================================================
    ' Constants
    ' =============================================================================================
    Public Class Constants

        ' TODO: Change CompanyName for your company name because draw node names must be unique
        Public Shared _drawNodeNamePolyline2D As String = "CompanyNameDrawNodePolyline2D"
        Public Shared _drawNodeNamePolyline2DXOR As String = "CompanyNameDrawNodePolyline2DXOR"
        Public Shared _drawNodeNamePolyline3D As String = "CompanyNameDrawNodePolyline3D"
        Public Shared _drawNodeNamePolyline3DXOR As String = "CompanyNameDrawNodePolyline3DXOR"
        Public Shared _drawNodeNamePoints As String = "CompanyNameDrawNodePoints"
        Public Shared _drawNodeNamePointsXOR As String = "CompanyNameDrawNodePointsXOR"
        Public Shared _drawNodeNameTriangles As String = "CompanyNameDrawNodeTriangles"
        Public Shared _drawNodeNameText As String = "CompanyNameDrawNodeText"
        Public Shared _drawText = "PolyWorks SDK 3D Scene Rendering Sample"
        Public Shared _pAnchoredAnnotation As IMM.IAnnotation = Nothing
        Public Shared _pFloatingAnnotation As IMM.IAnnotation = Nothing

    End Class

    ' =================================================================================================
    ' MSCL command drawing in the 3D Scene.
    '
    ' TODO: Rename CompanyNameAction with your company name.
    ' -------------------------------------------------------------------------------------------------
    Public Class CCmdCompanyName3DSceneRenderingStart
        Inherits CComCommand

        ' =============================================================================================
        ' Commands constructor. 
        ' This constructor is only called one time when the command is registered to the application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' ---------------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =============================================================================================
        ' Starts drawing into the 3D Scene.
        '
        ' Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' ---------------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            ' Add some draw nodes to the host application's draw nodes. 
            ' Note the last parameters. 
            ' It is very important that you specify the right draw node type.
            Functions.DrawNodeAddOne(New CDrawNodePoints(Constants._drawNodeNamePoints, New IMM.CPoint2D(0, 4)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_3D)
            Functions.DrawNodeAddOne(New CDrawNodePoints(Constants._drawNodeNamePointsXOR, New IMM.CPoint2D(4, 4)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_XOR)
            Functions.DrawNodeAddOne(New CDrawNodePolyline2D(Constants._drawNodeNamePolyline2D, 10), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_2D)
            Functions.DrawNodeAddOne(New CDrawNodePolyline2D(Constants._drawNodeNamePolyline2DXOR, 5), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_XOR)
            Functions.DrawNodeAddOne(New CDrawNodePolyline3D(Constants._drawNodeNamePolyline3D, New IMM.CPoint2D(0, 0)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_3D)
            Functions.DrawNodeAddOne(New CDrawNodePolyline3D(Constants._drawNodeNamePolyline3DXOR, New IMM.CPoint2D(4, 0)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_XOR)
            Functions.DrawNodeAddOne(New CDrawNodeText(Constants._drawNodeNameText, Constants._drawText), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_2D)
            Functions.DrawNodeAddOne(New CDrawNodeTriangles(Constants._drawNodeNameTriangles, New IMM.CPoint2D(2, 2)), IMM.DrawNodeTypes.EDrawNodeType.E_DRAW_NODE_TYPE_3D)

            ' Creation of a floating annotation
            If Constants._pFloatingAnnotation Is Nothing Then

                IMM.FnIAnnotation.Create(Constants._pFloatingAnnotation)

                If Not Constants._pFloatingAnnotation Is Nothing Then

                    Constants._pFloatingAnnotation.ColorSet(New IMM.CColorRGBA(0, 128, 255, 255))
                    Constants._pFloatingAnnotation.PositionSet(New IMM.CPoint2D(0.1, 0.1))
                    Constants._pFloatingAnnotation.TextSet("PolyWorks SDK - Floating Annotation")
                    Constants._pFloatingAnnotation.VisibleSet(True)

                End If

            End If

            ' Creation of anchored annotation
            If Constants._pAnchoredAnnotation Is Nothing Then

                IMM.FnIAnnotation.Create(Constants._pAnchoredAnnotation)

                If Not Constants._pAnchoredAnnotation Is Nothing Then

                    Constants._pAnchoredAnnotation.AnchorPointSet(New IMM.CPoint(0.0, 0.0, 0.0))
                    Constants._pAnchoredAnnotation.ColorSet(New IMM.CColorRGBA(0, 128, 0, 255))
                    Constants._pAnchoredAnnotation.TextSet("PolyWorks SDK - Anchored Annotation")
                    Constants._pAnchoredAnnotation.VisibleSet(True)

                End If

            End If

            Return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

        End Function

    End Class

    ' =================================================================================================
    ' MSCL command removing any drawing in the 3D Scene created by 
    ' CCmdCompanyName3DSceneRenderingStart.
    '
    ' TODO: Rename CompanyNameAction with your company name.
    ' -------------------------------------------------------------------------------------------------
    Public Class CCmdCompanyName3DSceneRenderingStop
        Inherits CComCommand

        ' =============================================================================================
        ' Commands constructor. 
        ' This constructor is only called one time when the command is registered to the application.
        '
        ' Parameter: info_ : Parameters necessary to build the command.
        ' ---------------------------------------------------------------------------------------------
        Public Sub New(ByVal info_ As CComCommandInfo)

            MyBase.New(info_)

        End Sub

        ' =============================================================================================
        ' Stops drawing in the 3D Scene
        '
        ' Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
        '
        ' Return: COM error code.
        ' ---------------------------------------------------------------------------------------------
        Public Overrides Function Execute2(ByVal pIMCommandArgumentEnum_ As IMPluginLib.IIMCommandArgumentEnum) As IMPluginLib.ECommandReturnCodes

            ' Remove all annotations
            Functions.AnnotationsRemoveAll()

            ' Remove all draw nodes
            Functions.DrawNodesRemoveAll()

            Return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED

        End Function

    End Class

    Public Class Functions

        ' =================================================================================================
        ' Remove one given annotation from the 3D Scene and free up any memory associated to it.
        '
        ' Parameter: pAnnotation_ : Reference to a pointer to an annotation.
        ' -------------------------------------------------------------------------------------------------
        Public Shared Sub AnnotationsRemoveOne(ByRef pAnnotation_ As IMM.IAnnotation)

            If Not pAnnotation_ Is Nothing Then

                IMM.FnIAnnotation.Destroy(pAnnotation_)
                pAnnotation_ = Nothing

            End If

        End Sub

        ' =================================================================================================
        ' Removes all annotations from the 3D Scene.
        ' -------------------------------------------------------------------------------------------------
        Public Shared Sub AnnotationsRemoveAll()

            AnnotationsRemoveOne(Constants._pAnchoredAnnotation)
            AnnotationsRemoveOne(Constants._pFloatingAnnotation)

        End Sub

        ' =================================================================================================
        ' Adds (if possible) a draw node to the applications draw node collection. 
        ' If the operation fails, the draw nodes memory is freed.
        '
        ' Parameter: pDrawNode_    : Pointer to a draw node
        ' Parameter: drawNodeType_ : Draw node type
        ' -------------------------------------------------------------------------------------------------
        Public Shared Sub DrawNodeAddOne(ByVal pDrawNode_ As IMM.IDrawNode, _
                                         ByVal drawNodeType_ As IMM.DrawNodeTypes.EDrawNodeType)

            If IMM.FnIDrawNodes.DrawNodesGet() Is Nothing Then

                Return

            End If

            If IMM.FnIDrawNodes.DrawNodesGet().Add(pDrawNode_, drawNodeType_) = False Then

                pDrawNode_.Dispose()

            End If

        End Sub

        ' =================================================================================================
        ' Removes all draw nodes and make sure any memory associated to it is freed.
        '
        ' Parameter: drawNodeName_ : Draw node's name
        ' -------------------------------------------------------------------------------------------------
        Public Shared Sub DrawNodesRemoveOne(ByVal drawNodeName_ As String)

            If IMM.FnIDrawNodes.DrawNodesGet() Is Nothing Then

                Return

            End If

            Dim pDrawNode As IMM.IDrawNode = IMM.FnIDrawNodes.DrawNodesGet().Remove(drawNodeName_)

            If Not pDrawNode Is Nothing Then

                pDrawNode.Dispose()

            End If

        End Sub

        ' =================================================================================================
        ' Remove all draw nodes potentially added previously from the host application draw nodes 
        ' collection.
        ' -------------------------------------------------------------------------------------------------
        Public Shared Sub DrawNodesRemoveAll()

            DrawNodesRemoveOne(Constants._drawNodeNamePolyline2D)
            DrawNodesRemoveOne(Constants._drawNodeNamePolyline2DXOR)
            DrawNodesRemoveOne(Constants._drawNodeNamePolyline3D)
            DrawNodesRemoveOne(Constants._drawNodeNamePolyline3DXOR)
            DrawNodesRemoveOne(Constants._drawNodeNamePoints)
            DrawNodesRemoveOne(Constants._drawNodeNamePointsXOR)
            DrawNodesRemoveOne(Constants._drawNodeNameTriangles)
            DrawNodesRemoveOne(Constants._drawNodeNameText)

        End Sub

    End Class

End Namespace

