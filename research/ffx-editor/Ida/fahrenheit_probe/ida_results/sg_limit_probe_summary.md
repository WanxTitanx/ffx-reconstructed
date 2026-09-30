# SG Limit Probe (fahrenheit cross-check)

- DB: `F:\ffx-reconstructed\extras\ffxoficial.exe.i64` root=`FFX.exe` min_ea=0x401000
- Funcoes alvo: 10
- Faixa ABMAP: 90 funcoes com constantes de limite

## Funcoes com constantes de limite
| EA | Nome | Consts |
|---|---|---|
| 0xa43e60 | FFX_Camera_ComputeProjectionFrustum | 1024 |
| 0xa44d30 | FFX_Abmap_ScanOwnedInventoryForNodeRequirements | 861, 860, 0x35D, 0x35C |
| 0xa45010 | FFX_Abmap_MainInputDispatcher | 861, 0x35D |
| 0xa452d0 | FFX_Abmap_ItemUseConfirmMenuTick | 861, 0x35D |
| 0xa45440 | FFX_Abmap_DispatchSfxByTableEntry | 860, 0x35C |
| 0xa454a0 | FFX_Abmap_DispatchSfxByTableEntry_B | 860, 0x35C |
| 0xa45500 | FFX_Abmap_DispatchSfxByTableEntry_C | 860, 0x35C |
| 0xa45930 | FFX_Abmap_RunPlacementFx | 860, 0x35C |
| 0xa459e0 | FFX_Abmap_BuildPanelPrimsFromMenuEntries | 861, 0x35D |
| 0xa45fd0 | FFX_Abmap_PopulateOwnedItemMenuPrims | 861, 0x35D |
| 0xa474d0 | FFX_Abmap_InitSlotDisplay_ResetEntries | 861, 860, 0x35D, 0x35C |
| 0xa47560 | FFX_Abmap_PositionSlotDisplayEntry | 861, 860, 0x35D, 0x35C |
| 0xa47d50 | FFX_Abmap_NodePlacementAnim_structural | 860, 0x35C |
| 0xa47f00 | FFX_Abmap_ProcessPlacementFrame | 860, 0x35C |
| 0xa48230 | FFX_Abmap_SetupMenuModeState | 861, 0x35D |
| 0xa48280 | FFX_Abmap_SwapAnimCallbackChain | 860, 0x35C |
| 0xa48740 | FFX_Abmap_PlacementAnim_SetupMarker | 860, 0x35C |
| 0xa48910 | FFX_Abmap_ActivateNode | 860, 0x35C |
| 0xa48a80 | FFX_Abmap_SetupNodeActivationCamera | 860, 0x35C |
| 0xa48c20 | FFX_Abmap_SetSlotAnimForward | 861, 0x35D |
| 0xa48e40 | FFX_Abmap_InputDispatchCursorOrReset | 861, 860, 0x35D, 0x35C |
| 0xa48f20 | FFX_Abmap_SetSlotAnimReverse | 861, 0x35D |
| 0xa48f50 | FFX_Abmap_AnimateScrollOffset | 861, 0x35D |
| 0xa490c0 | FFX_Abmap_AnimateZoomTransition | 861, 0x35D |
| 0xa49310 | FFX_Abmap_TestInventoryItemAgainstNodeRequirement | 860, 0x35C |
| 0xa493b0 | FFX_Abmap_TestAndMarkInventoryItemForNode | 860, 0x35C |
| 0xa49440 | FFX_Abmap_EvaluateNodeItemRequirementRule | 860, 0x35C |
| 0xa497b0 | FFX_Abmap_SphereGridRenderFlush | 860, 0x35C |
| 0xa49f10 | FFX_Abmap_FlushCapturedFullUiQuads | 860, 0x35C |
| 0xa4ac20 | FFX_Abmap_ResolveAndDrawCaptureQuads | 860, 0x35C |
| 0xa4c430 | FFX_Abmap_DispatchPlacementFxIfSlotReady | 860, 0x35C |
| 0xa4c460 | FFX_Abmap_TextureQuadDrawPath_B | 860, 0x35C |
| 0xa4ce20 | FFX_Abmap_RenderScene | 860, 0x35C |
| 0xa50290 | FFX_Abmap_RenderPathNodes | 1024, 0x5000 |
| 0xa51340 | FFX_Abmap_DrawRuntimePanelNodes | 860, 0x35C |
| 0xa51560 | FFX_Abmap_DrawNodeByIndex | 861, 0x35D |
| 0xa51700 | FFX_Abmap_PlacementFxCallback | 860, 0x35C |
| 0xa51720 | FFX_Abmap_CaptureAndRenderQuads | 860, 0x35C |
| 0xa521a0 | FFX_Menu2D_Quad_Submit | 860, 0x35C |
| 0xa53570 | FFX_Abmap_UpdateCameraScroll_structural | 1024, 861, 0x35D |
| 0xa53de0 | FFX_SphereGrid_InitRuntimeStateFromAbmapResources | 860, 0x1320, 0x35C |
| 0xa545a0 | FFX_Abmap_ExitRenderTeardownLoop | 861, 0x35D |
| 0xa54660 | FFX_Abmap_ExitFullUiFlush_structural | 861, 0x35D |
| 0xa54720 | FFX_Abmap_ReleaseGpuOnExit_structural | 860, 0x35C |
| 0xa54810 | FFX_SphereGrid_AllocSpherePanelBuffers | 860, 0x35C |
| 0xa54860 | FFX_Abmap_RecomputePartyStatsAndLearnedMoves | 1024, 860, 0x35C |
| 0xa54ab0 | FFX_SphereGrid_LoadSpherePanelBuffers | 860, 0x35C |
| 0xa54b40 | FFX_Abmap_InitAndEnterMenu | 861, 860, 0x35D, 0x35C |
| 0xa56060 | FFX_Abmap_ExitConfirmHandler | 861, 0x35D |
| 0xa560d0 | FFX_Abmap_OpenItemUseNodeSelection | 861, 0x35D |
| 0xa56160 | FFX_Abmap_MenuModeDispatch | 861, 0x35D |
| 0xa56330 | FFX_Abmap_ModeChangeCallback | 861, 0x35D |
| 0xa563b0 | FFX_Abmap_ComputeLabelAnglePosition | 1024 |
| 0xa56bd0 | FFX_Abmap_ReadCursorInput | 1024 |
| 0xa57040 | FFX_Abmap_DispatchPlacementSfxByCmdTable | 860, 0x35C |
| 0xa57120 | FFX_Abmap_ClearNodeTransforms | 1024 |
| 0xa572e0 | FFX_Abmap_InitStaticMenuStateBuffers | 861, 860, 0x12FC0, 0x35D, 0x35C |
| 0xa57520 | FFX_Abmap_ReadAndProcessInputState | 1024 |
| 0xa57620 | FFX_Abmap_InitRenderContextForMagicHost | 860, 0x35C |
| 0xa57710 | FFX_Abmap_BuildLinkBatchSegment_structural | 1024 |
| 0xa58080 | FFX_Abmap_UpdatePlacementSlotTransform | 1024 |
| 0xa583e0 | FFX_Abmap_DialogDispatch | 1024, 861, 0x35D |
| 0xa58660 | FFX_Abmap_ExitPanelTransitionDispatch | 861, 0x35D |
| 0xa58900 | FFX_Abmap_PanelDraw | 861, 0x35D |
| 0xa58df0 | FFX_Abmap_WalkNodesAndFlagByType | 860, 0x35C |
| 0xa59680 | FFX_Abmap_ItemUseMenu_CopyEntryCoords | 861, 0x35D |
| 0xa596d0 | FFX_Abmap_ItemUseMenu_InitEntryCoords | 861, 0x35D |
| 0xa59860 | FFX_Abmap_SetupButtonStateAndHandler | 861, 0x35D |
| 0xa598a0 | FFX_Abmap_RefreshOwnedItemRequirementFlags | 861, 0x35D |
| 0xa59950 | FFX_Abmap_ResetAndSetModeCallback | 861, 860, 0x35D, 0x35C |
| 0xa5a020 | FFX_Abmap_UpdateCursorAndTransitionMode | 861, 860, 0x35D, 0x35C |
| 0xa5a2e0 | FFX_Abmap_CheckStatRequirementsForSlots | 861, 0x35D |
| 0xa5a640 | FFX_Abmap_SetupPlacementAnimOverlayText | 860, 0x35C |
| 0xa5aa30 | FFX_Abmap_DispatchActivationAnim | 860, 0x35C |
| 0xa5aca0 | FFX_Abmap_ResetSlotAvailability | 861, 0x35D |
| 0xa5adf0 | FFX_Abmap_FillNodeIndexFromRuntimeTable | 860, 0x35C |
| 0xa5b030 | FFX_Abmap_InitCharacterView | 860, 0x35C |
| 0xa5b230 | FFX_Abmap_InitPlacementGrid | 1024, 861, 860, 0x35D, 0x35C |
| 0xa5b400 | FFX_Abmap_ApplyInventoryItemRequirementToLinkedNodes | 860, 0x35C |
| 0xa5bca0 | FFX_Abmap_ConsumeItemAndActivateNode | 860, 0x35C |
| 0xa5d3c0 | FFX_Abmap_SphereGrid_ProcessData | 861, 0x35D |
| 0xa5dd90 | FFX_Settings_SetGlobalWord | 861, 0x35D |
| 0xa5dda0 | FFX_Settings_InitPaletteState | 861, 0x35D |
| 0xa5de50 | FFX_Settings_ClearFlag | 861, 0x35D |
| 0xa5de60 | FFX_Settings_SetFlagByte | 861, 0x35D |
| 0xa5dfb0 | FFX_Settings_AdvanceState | 861, 0x35D |
| 0xa5e2b0 | FFX_Settings_SetDisplayPalette | 861, 0x35D |
| 0xa5e7b0 | FFX_SphereGrid_BuildRenderCmd | 861, 0x35D |
| 0xa5ea30 | FFX_Abmap_ValueToFloat | 861, 0x35D |
| 0xa5f040 | FFX_Abmap_SphereGrid_DecodeCoord | 861, 0x35D |
| 0xA572E0 | FFX_Abmap_InitStaticMenuStateBuffers | 861, 860, 128, 0x12FC0, 0x800, 0x28, 0x14, 0x10 |
| 0xA45570 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells | 128, 0x28, 0x14, 0x10 |
| 0xA49590 | FFX_Abmap_ApplyRuntimeNodeStates | 0x28, 0x14, 0x10 |
| 0xA51340 | FFX_Abmap_DrawRuntimePanelNodes | 860, 128, 0x28, 0x14, 0x10 |
| 0xA54860 | FFX_Abmap_RecomputePartyStatsAndLearnedMoves | 1024, 860, 128, 0x28, 0x14, 0x10 |
| 0xA5BB70 | FFX_Abmap_ExitPersistSave | 0x28, 0x14, 0x10 |
| 0xA56060 | FFX_Abmap_ExitConfirmPersistAndLeave | 861 |
| 0x681DB0 | FFX_Menu2D_InitBatchBuffers_NoTextureFallback | 128, 0x28, 0x14, 0x10 |
| 0x7F4900 | FFX_Menu2D_DrawQuadIndexedBatch | 861, 128, 0x800, 0x28, 0x14, 0x10 |
| 0x8E27E0 | FFX_Abmap_DeactivateAndReturnToFieldUI | - |

## Xrefs ao ponteiro global (menu blob)
| De | Tipo | Funcao |
|---|---|---|
| 0xa44cd3 | 3 |  |
| 0xa44cee | 3 |  |
| 0xa44d03 | 3 |  |
| 0xa44d1e | 3 |  |
| 0xa44d36 | 3 | FFX_Abmap_ScanOwnedInventoryForNodeRequirements |
| 0xa44e2b | 3 | FFX_Abmap_ScanOwnedInventoryForNodeRequirements |
| 0xa44e40 | 3 | FFX_Abmap_SwapSlotBufferA |
| 0xa44e52 | 3 | FFX_Abmap_SwapSlotBufferA |
| 0xa44e70 | 3 | FFX_Abmap_SwapSlotBufferB |
| 0xa44e82 | 3 | FFX_Abmap_SwapSlotBufferB |
| 0xa44ed0 | 3 |  |
| 0xa44efa | 3 | FFX_Abmap_ProcessTickAndModeSwitch |
| 0xa44f3b | 3 | FFX_Abmap_ProcessTickAndModeSwitch |
| 0xa44f69 | 3 | FFX_Abmap_ProcessTickAndModeSwitch |
| 0xa44f78 | 3 | FFX_Abmap_ProcessTickAndModeSwitch |
| 0xa44f87 | 3 | FFX_Abmap_ProcessTickAndModeSwitch |
| 0xa44f93 | 3 | FFX_Abmap_ProcessTickAndModeSwitch |
| 0xa44fcb | 3 | FFX_Abmap_ProcessTickAndModeSwitch |
| 0xa44fd7 | 3 | FFX_Abmap_ProcessTickAndModeSwitch |
| 0xa45017 | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa4503e | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa45067 | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa45085 | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa450c3 | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa450d5 | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa45132 | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa451ca | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa451d8 | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa451ed | 3 | FFX_Abmap_MainInputDispatcher |
| 0xa452da | 3 | FFX_Abmap_ItemUseConfirmMenuTick |
| 0xa45347 | 3 | FFX_Abmap_ItemUseConfirmMenuTick |
| 0xa45420 | 3 |  |
| 0xa45444 | 3 | FFX_Abmap_DispatchSfxByTableEntry |
| 0xa454a4 | 3 | FFX_Abmap_DispatchSfxByTableEntry_B |
| 0xa45504 | 3 | FFX_Abmap_DispatchSfxByTableEntry_C |
| 0xa45608 | 3 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells |
| 0xa45619 | 3 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells |
| 0xa45623 | 3 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells |
| 0xa45634 | 3 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells |
| 0xa45660 | 3 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells |
| 0xa4573b | 3 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells |
| 0xa45770 | 3 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells |
| 0xa4579a | 3 | FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells |
| 0xa457de | 3 | FFX_Abmap_TestNodeActivationBit |
| 0xa4580a | 3 | FFX_Abmap_FindMatchingChrSlot |
| 0xa4588a | 3 | FFX_Abmap_GetSlotNodeIdIfActive |
| 0xa458c9 | 3 | FFX_Abmap_ClearNodeActivationBit |
| 0xa458fe | 3 | FFX_Abmap_MarkActivationPosted |
| 0xa45942 | 3 | FFX_Abmap_RunPlacementFx |
| 0xa45957 | 3 | FFX_Abmap_RunPlacementFx |
| 0xa45ef7 | 3 | FFX_Abmap_TextureQuadDrawPath_A |
| 0xa461b4 | 3 | FFX_Abmap_ButtonAnim_CalcDrawParams |
| 0xa4620f | 3 | FFX_Abmap_ButtonAnim_CalcDrawParams |
| 0xa4621b | 3 | FFX_Abmap_ButtonAnim_CalcDrawParams |
| 0xa46263 | 3 | FFX_Abmap_ButtonAnim_CalcDrawParams |
| 0xa462a2 | 3 | FFX_Abmap_ButtonAnim_CalcDrawParams |
| 0xa473d3 | 3 | FFX_Abmap_ClearSlotFlagsByMask |
| 0xa47403 | 3 | FFX_Abmap_ClearSlotEntryFlagsByMask |
| 0xa47446 | 3 | FFX_Abmap_AnimIndexTick_structural |
| 0xa4748b | 3 | FFX_Abmap_AnimIndexTick_structural |
| 0xa474a2 | 3 | FFX_Abmap_AnimIndexTick_structural |
| 0xa474d3 | 3 | FFX_Abmap_InitSlotDisplay_ResetEntries |
| 0xa47501 | 3 | FFX_Abmap_InitSlotDisplay_ResetEntries |
| 0xa47586 | 3 | FFX_Abmap_PositionSlotDisplayEntry |
| 0xa475a6 | 3 | FFX_Abmap_PositionSlotDisplayEntry |
| 0xa47645 | 3 | FFX_Abmap_ProcessScreenCoordinateQuads |
| 0xa47ba6 | 3 | FFX_Abmap_ProcessScreenCoordinateQuads |
| 0xa47c75 | 3 | FFX_Abmap_ComputeGlowPlacementParams |
| 0xa47d56 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47d73 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47dca | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47dff | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47e1e | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47e31 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47e40 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47e54 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47e6e | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47ea4 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47ec6 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47ed5 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47ee7 | 3 | FFX_Abmap_NodePlacementAnim_structural |
| 0xa47f10 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa47f3b | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa47f62 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa47f77 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa47f91 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa47fa4 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa47fb3 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa47fc5 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa48048 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa4805e | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa480dc | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa480fd | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa4810f | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa48121 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa48144 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa48163 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa48171 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa48194 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa481bf | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa481d5 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa481fa | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa48206 | 3 | FFX_Abmap_ProcessPlacementFrame |
| 0xa4828a | 3 | FFX_Abmap_SwapAnimCallbackChain |
| 0xa4829c | 3 | FFX_Abmap_SwapAnimCallbackChain |
| 0xa482ab | 3 | FFX_Abmap_SwapAnimCallbackChain |
| 0xa482bd | 3 | FFX_Abmap_SwapAnimCallbackChain |
| 0xa482f2 | 3 | FFX_Abmap_GlowSetup |
| 0xa48746 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa48813 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa4884b | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa48860 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa4887d | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa48888 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa48894 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa488a0 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa488b1 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa488d2 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa488e1 | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa488fc | 3 | FFX_Abmap_PlacementAnim_SetupMarker |
| 0xa48914 | 3 | FFX_Abmap_ActivateNode |
| 0xa489f7 | 3 | FFX_Abmap_ActivateNode |
| 0xa48a18 | 3 | FFX_Abmap_ActivateNode |
| 0xa48a39 | 3 | FFX_Abmap_ActivateNode |
| 0xa48a48 | 3 | FFX_Abmap_ActivateNode |
| 0xa48a63 | 3 | FFX_Abmap_ActivateNode |
| 0xa48a89 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48aa9 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48aba | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48ae4 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48af5 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48b14 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48b25 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48b30 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48b3d | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48b4e | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48bc0 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48be1 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48bf0 | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48c0b | 3 | FFX_Abmap_SetupNodeActivationCamera |
| 0xa48c83 | 3 | FFX_Abmap_InitNodeSelectionLayout |
| 0xa48ca2 | 3 | FFX_Abmap_InitNodeSelectionLayout |
| 0xa48cb6 | 3 | FFX_Abmap_InitNodeSelectionLayout |
| 0xa48cc7 | 3 | FFX_Abmap_InitNodeSelectionLayout |
| 0xa48cd2 | 3 | FFX_Abmap_InitNodeSelectionLayout |
| 0xa48cdf | 3 | FFX_Abmap_InitNodeSelectionLayout |
| 0xa48cea | 3 | FFX_Abmap_InitNodeSelectionLayout |
| 0xa48d05 | 3 | FFX_Abmap_InitNodeSelectionLayout |
| 0xa48d32 | 3 | FFX_Abmap_UpdateAndChainCursorAnim |
| 0xa48d50 | 3 | FFX_Abmap_UpdateAndChainCursorAnim |
| 0xa48d76 | 3 | FFX_Abmap_CopyCameraStateToTemp |
| 0xa48db1 | 3 | FFX_Abmap_CopyCameraStateToTemp |
| 0xa48dbc | 3 | FFX_Abmap_CopyCameraStateToTemp |
| 0xa48dca | 3 | FFX_Abmap_CopyCameraStateToTemp |
| 0xa48ddb | 3 | FFX_Abmap_CopyCameraStateToTemp |
| 0xa48e09 | 3 | FFX_Abmap_CopyCameraStateToTemp |
| 0xa48e1a | 3 | FFX_Abmap_CopyCameraStateToTemp |
| 0xa48e26 | 3 | FFX_Abmap_CopyCameraStateToTemp |
| 0xa48e43 | 3 | FFX_Abmap_InputDispatchCursorOrReset |
| 0xa48e9c | 3 | FFX_Abmap_InputDispatchCursorOrReset |
| 0xa48eba | 3 | FFX_Abmap_InputDispatchCursorOrReset |
| 0xa48f59 | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa48f8d | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa48fae | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa48fba | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa48fc6 | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa48fd7 | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa4900d | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa4902c | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa49048 | 3 | FFX_Abmap_AnimateScrollOffset |
| 0xa490c9 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa490f3 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49108 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49114 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa4912a | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49135 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49158 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49170 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa4917b | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49186 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49196 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa491ea | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa491f5 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa4920f | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49230 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa49248 | 3 | FFX_Abmap_AnimateZoomTransition |
| 0xa4941d | 3 | FFX_Abmap_TestAndMarkInventoryItemForNode |
| 0xa49471 | 3 | FFX_Abmap_EvaluateNodeItemRequirementRule |
| 0xa4959b | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa495e6 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa4961e | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa49645 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa49658 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa4966b | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa4967e | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa49691 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa496a4 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa496b7 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa496c9 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa496d4 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa4970f | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa49750 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa4975b | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa49771 | 3 | FFX_Abmap_ApplyMenuSnapshot |
| 0xa497c4 | 3 | FFX_Abmap_SphereGridRenderFlush |
| 0xa497ed | 3 | FFX_Abmap_SphereGridRenderFlush |
| 0xa49f38 | 3 | FFX_Abmap_FlushCapturedFullUiQuads |
| 0xa4a0d8 | 3 | FFX_Abmap_FlushCapturedFullUiQuads |
| 0xa4ac3d | 3 | FFX_Abmap_ResolveAndDrawCaptureQuads |
| 0xa4ac6f | 3 | FFX_Abmap_ResolveAndDrawCaptureQuads |
| 0xa4ad5b | 3 | FFX_Abmap_ResolveAndDrawCaptureQuads |
| 0xa4b4c1 | 3 | FFX_Abmap_ButtonLayout_InitRender |
| 0xa4b4ff | 3 | FFX_Abmap_ButtonLayout_InitRender |
| 0xa4b7b2 | 3 | FFX_Abmap_RenderFullUiFlushQuads |
| 0xa4bbeb | 3 | FFX_Abmap_RenderFullUiFlushQuads |
| 0xa4bbf6 | 3 | FFX_Abmap_RenderFullUiFlushQuads |
| 0xa4bd0f | 3 | FFX_Abmap_RenderFullUiFlushQuads |
| 0xa4c343 | 3 | FFX_Abmap_RenderFullUiFlushQuads |
| 0xa4c430 | 3 | FFX_Abmap_DispatchPlacementFxIfSlotReady |
| 0xa4c579 | 3 | FFX_Abmap_TextureQuadDrawPath_B |
| 0xa4c6c0 | 3 |  |
| 0xa4c837 | 3 | FFX_Abmap_RenderCrosshair |
| 0xa4c86b | 3 | FFX_Abmap_RenderCrosshair |
| 0xa4c893 | 3 | FFX_Abmap_RenderCrosshair |
| 0xa4c8f8 | 3 | FFX_Abmap_SphereGridRenderNodes |
| 0xa4cad7 | 3 | FFX_Abmap_SphereGridRenderNodes |
| 0xa4caf7 | 3 | FFX_Abmap_SphereGridRenderNodes |
| 0xa4cca7 | 3 | FFX_Abmap_SphereGridRenderNodes |
| 0xa4cd60 | 3 | FFX_Abmap_SphereGridRenderNodes |
| 0xa4cdb2 | 3 | FFX_Abmap_SphereGridRenderNodes |
| 0xa4ce47 | 3 | FFX_Abmap_RenderScene |
| 0xa4f22e | 3 | FFX_Abmap_RenderScene |
| 0xa4f2a7 | 3 | FFX_Abmap_MarkerTextureDrawPath |
| 0xa4f2d3 | 3 | FFX_Abmap_MarkerTextureDrawPath |
| 0xa4f34e | 3 | FFX_Abmap_MarkerTextureDrawPath |
| 0xa4f3b7 | 3 | FFX_Abmap_MarkerTextureDrawPath |
| 0xa4f3db | 3 | FFX_Abmap_MarkerTextureDrawPath |
| 0xa4f942 | 3 | FFX_Abmap_DrawItemReqQuad |
| 0xa4f9e3 | 3 | FFX_SphereGrid_DrawStatNumber_WithType7 |
| 0xa4fa33 | 3 | FFX_SphereGrid_DrawStatNumber |
| 0xa4fb7c | 3 | FFX_Abmap_ButtonAnim_DrawQuad |
| 0xa4fbe8 | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fc43 | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fc4f | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fca8 | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fce6 | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fcf8 | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fd89 | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fdca | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fddc | 3 | FFX_Abmap_ButtonAnim_Step |
| 0xa4fe66 | 3 | FFX_Abmap_DrawPanelNodesPrep_structural |
| 0xa4ff4d | 3 | FFX_Abmap_DrawPanelNodesPrep_structural |
| 0xa4ff75 | 3 | FFX_Abmap_DrawPanelNodesPrep_structural |
| 0xa4fff7 | 3 | FFX_Abmap_DrawPanelNodeColorOverlay |
| 0xa501e5 | 3 | FFX_Abmap_DrawPanelNodeColorOverlay |
| 0xa50226 | 3 | FFX_Abmap_DrawPanelNodeColorOverlay |
| 0xa502b6 | 3 | FFX_Abmap_RenderPathNodes |
| 0xa5031f | 3 | FFX_Abmap_RenderPathNodes |
| 0xa5044f | 3 | FFX_Abmap_RenderPathNodes |
| 0xa5054d | 3 | FFX_Abmap_RenderPathNodes |
| 0xa50573 | 3 | FFX_Abmap_RenderPathNodes |
| 0xa50595 | 3 | FFX_Abmap_RenderPathNodes |
| 0xa5060a | 3 | FFX_Abmap_SphereGridBuildVertices |
| 0xa5096e | 3 | FFX_Abmap_SphereGridBuildVertices |
| 0xa509bc | 3 | FFX_Abmap_SphereGridBuildVertices |
| 0xa50a23 | 3 | FFX_Abmap_SphereGridBuildVertices |
| 0xa50a61 | 3 | FFX_Abmap_SphereGridBuildVertices |
| 0xa50ab1 | 3 | FFX_Abmap_SphereGridBuildVertices |
| 0xa50aeb | 3 | FFX_Abmap_SphereGridBuildVertices |
| 0xa50b16 | 3 | FFX_Abmap_SphereGridBuildVertices |
| 0xa50b76 | 3 | FFX_Abmap_DrawNodeColorOverlay |
| 0xa50d72 | 3 | FFX_Abmap_DrawNodeColorOverlay |
| 0xa50e2c | 3 | FFX_Abmap_DrawNodeColorOverlay |
| 0xa50e43 | 3 | FFX_Abmap_DrawNodeColorOverlay |
| 0xa50f1e | 3 | FFX_Abmap_NodeDraw |
| 0xa5128e | 3 | FFX_Abmap_NodeDraw |
| 0xa51312 | 3 | FFX_Abmap_NodeDraw |
| 0xa51366 | 3 | FFX_Abmap_DrawRuntimePanelNodes |
| 0xa51465 | 3 | FFX_Abmap_DrawRuntimePanelNodes |
| 0xa514b5 | 3 | FFX_Abmap_DrawRuntimePanelNodes |
| 0xa514dd | 3 | FFX_Abmap_DrawRuntimePanelNodes |
| 0xa5150b | 3 | FFX_Abmap_DrawRuntimePanelNodes |
| 0xa515a1 | 3 | FFX_Abmap_DrawNodeByIndex |
| 0xa51639 | 3 | FFX_Abmap_DrawNodeByIndex |
| 0xa516ac | 3 | FFX_Abmap_DrawNodeByIndex |
| 0xa51733 | 3 | FFX_Abmap_CaptureAndRenderQuads |
| 0xa51772 | 3 | FFX_Abmap_CaptureAndRenderQuads |
| 0xa517c7 | 3 | FFX_Abmap_CaptureAndRenderQuads |
| 0xa51809 | 3 | FFX_Abmap_CaptureAndRenderQuads |
| 0xa51b7e | 3 | FFX_Abmap_CaptureAndRenderQuads |
| 0xa51bc0 | 3 | FFX_Abmap_CaptureAndRenderQuads |
| 0xa51bf5 | 3 | FFX_Abmap_CaptureAndRenderQuads |
| 0xa521b3 | 3 | FFX_Menu2D_Quad_Submit |
| 0xa5220b | 3 | FFX_Menu2D_Quad_Submit |
| 0xa52259 | 3 | FFX_Menu2D_Quad_Submit |
| 0xa5229b | 3 | FFX_Menu2D_Quad_Submit |
| 0xa527a3 | 3 | FFX_Menu2D_Quad_Submit |
| 0xa527ce | 3 | FFX_Menu2D_Quad_Submit |
| 0xa52813 | 3 | FFX_Menu2D_Quad_Submit |
| 0xa52848 | 3 | FFX_Menu2D_Quad_Submit |
| 0xa53450 | 3 | FFX_Abmap_ButtonLayout_StateMachine |
| 0xa53479 | 3 | FFX_Abmap_ButtonLayout_StateMachine |
| 0xa534c0 | 3 | FFX_Abmap_DrawNodeColorOverlay |
| 0xa534d8 | 3 | FFX_Abmap_DrawNodeColorOverlay |
| 0xa534fb | 3 | FFX_Abmap_DrawNodeColorOverlay |
| 0xa53510 | 3 | FFX_Abmap_DrawPanelNodeColorOverlay |
| 0xa5353e | 3 | FFX_Abmap_DrawPanelNodeColorOverlay |
| 0xa5355a | 3 | FFX_Abmap_DrawPanelNodeColorOverlay |
| 0xa53580 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa535a5 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53605 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53616 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53632 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53641 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa5364d | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa5366f | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa5368d | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53699 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa536a9 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa536b6 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa536c2 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa536e6 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53702 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa5372b | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53749 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53778 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa537c5 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa537d0 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa537db | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa537e6 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa537ff | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa5381e | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53859 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa538cb | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa538e1 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa5392b | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa5396b | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa5398a | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa539a9 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa539db | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa539fc | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53a1b | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53a31 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53a4a | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53a63 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53a83 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53bf5 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53c27 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53c59 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53c64 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53c84 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53ca4 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53cb7 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53cca | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53ce7 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53cfa | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53d0d | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53d1e | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53d3e | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53d9e | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53db4 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa53dc0 | 3 | FFX_Abmap_UpdateCameraScroll_structural |
| 0xa54560 | 3 | FFX_Abmap_ExitRenderTeardown_structural |
| 0xa5457c | 3 | FFX_Abmap_ExitRenderTeardown_structural |
| 0xa5458e | 3 | FFX_Abmap_ExitRenderTeardown_structural |
| 0xa545d5 | 3 | FFX_Abmap_ExitRenderTeardownLoop |
| 0xa54632 | 3 | FFX_Abmap_ExitRenderTeardownLoop |
| 0xa54643 | 3 | FFX_Abmap_ExitRenderTeardownLoop |
| 0xa546ad | 3 | FFX_Abmap_ExitFullUiFlush_structural |
| 0xa54700 | 3 | FFX_Abmap_ExitFullUiFlush_structural |
| 0xa54b90 | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa54bb4 | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa54bf3 | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa54c67 | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa54ca3 | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa54ccd | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa54d25 | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa54d87 | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa54dbd | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa55feb | 3 | FFX_Abmap_InitAndEnterMenu |
| 0xa5611f | 3 | FFX_Abmap_OpenItemUseNodeSelection |
| 0xa56179 | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa561a3 | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa561cc | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa561df | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa561f5 | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa56216 | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa56228 | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa5623a | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa56266 | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa56286 | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa56295 | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa5631a | 3 | FFX_Abmap_MenuModeDispatch |
| 0xa56693 | 3 |  |
| 0xa56753 | 3 |  |
| 0xa567f0 | 3 |  |
| 0xa56820 | 3 | FFX_Abmap_GetZoomFactor |
| 0xa56870 | 3 | FFX_Abmap_FindNearestSpherePoint |
| 0xa56a46 | 3 | FFX_Abmap_FindNearestNode |
| 0xa56c19 | 3 | FFX_Abmap_ReadCursorInput |
| 0xa56c7c | 3 | FFX_Abmap_ReadCursorInput |
| 0xa56c9b | 3 | FFX_Abmap_ReadCursorInput |
| 0xa56cc4 | 3 | FFX_Abmap_ReadCursorInput |
| 0xa56ceb | 3 | FFX_Abmap_ReadCursorInput |
| 0xa56e15 | 3 | FFX_Abmap_FindNearestNodeConnection |
| 0xa56eaf | 3 | FFX_Abmap_FindNearestNodeConnection |
| 0xa56f39 | 3 | FFX_Abmap_GetNodeRadiusOffset |
| 0xa56f8c | 3 |  |
| 0xa57120 | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa57154 | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa57186 | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa571b8 | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa571ea | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa5721c | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa5724e | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa57280 | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa572b2 | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa572bd | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa572c8 | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa572d3 | 3 | FFX_Abmap_ClearNodeTransforms |
| 0xa57325 | 2 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57356 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57370 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa573bc | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa573cc | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa573de | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa573ec | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57422 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa5742d | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57438 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57443 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa5744e | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa5745a | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57469 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57478 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57487 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57493 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa574a6 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa574b3 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa574c4 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa574d0 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa574dc | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa574eb | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa574fa | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57505 | 3 | FFX_Abmap_InitStaticMenuStateBuffers |
| 0xa57632 | 3 | FFX_Abmap_InitRenderContextForMagicHost |
| 0xa57f86 | 3 | FFX_Abmap_InitNodePlacementSlot |
| 0xa57fd5 | 3 | FFX_Abmap_InitNodePlacementSlot |
| 0xa58088 | 3 | FFX_Abmap_UpdatePlacementSlotTransform |
| 0xa5840c | 3 | FFX_Abmap_DialogDispatch |
| 0xa5857a | 3 | FFX_Abmap_DialogDispatch |
| 0xa58660 | 3 | FFX_Abmap_ExitPanelTransitionDispatch |
| 0xa586e1 | 3 | FFX_Abmap_ExitPanelTransitionDispatch |
| 0xa58776 | 3 | FFX_Abmap_ExitPanelTransitionDispatch |
| 0xa58810 | 3 | FFX_Abmap_ExitPanelTransitionDispatch |
| 0xa588aa | 3 | FFX_Abmap_ExitPanelTransitionDispatch |
| 0xa58db3 | 3 |  |
| 0xa58dfa | 3 | FFX_Abmap_WalkNodesAndFlagByType |
| 0xa58e50 | 3 | FFX_Abmap_WalkNodesAndFlagByType |
| 0xa58e95 | 3 | FFX_Abmap_WalkNodesAndFlagByType |
| 0xa58ec0 | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58ee3 | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58f06 | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58f12 | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58f2a | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58f36 | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58f5e | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58f81 | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58fa4 | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa58fc2 | 3 | FFX_Abmap_TabSwitchHandler |
| 0xa59000 | 3 | FFX_Abmap_TickUpdate |
| 0xa59043 | 3 | FFX_Abmap_TickUpdate |
| 0xa59086 | 3 | FFX_Abmap_TickUpdate |
| 0xa5910b | 3 | FFX_Abmap_TickUpdate |
| 0xa5915b | 3 | FFX_Abmap_TickUpdate |
| 0xa59193 | 3 | FFX_Abmap_TickUpdate |
| 0xa591ce | 3 | FFX_Abmap_TickUpdate |
| 0xa59227 | 3 | FFX_Abmap_TickUpdate |
| 0xa59353 | 3 | FFX_Abmap_DispatchPlacementSfx |
| 0xa59371 | 3 | FFX_Abmap_DispatchPlacementSfx |
| 0xa59397 | 3 | FFX_Abmap_DispatchPlacementSfx |
| 0xa593b6 | 3 | FFX_Abmap_DispatchPlacementSfx |
| 0xa593da | 3 | FFX_Abmap_DispatchPlacementSfx |
| 0xa593f9 | 3 | FFX_Abmap_DispatchPlacementSfx |
| 0xa59418 | 3 | FFX_Abmap_DispatchPlacementSfx |
| 0xa5942f | 3 | FFX_Abmap_DispatchPlacementSfx |
| 0xa594c3 | 3 | FFX_Abmap_DrawQuadWithDefaultColor |
| 0xa59543 | 3 |  |
| 0xa595d4 | 3 |  |
| 0xa59713 | 3 | FFX_Abmap_WalkNodeRecordsUntilRequirementMet_structural |
| 0xa59773 | 3 | FFX_Abmap_WalkLinkedNodeRequirementChain_structural |
| 0xa59790 | 3 | FFX_Abmap_WalkLinkedNodeRequirementChain_structural |
| 0xa598a4 | 3 | FFX_Abmap_RefreshOwnedItemRequirementFlags |
| 0xa5990e | 3 | FFX_Abmap_RefreshOwnedItemRequirementFlags |
| 0xa599a0 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa599c5 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa599e9 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59a47 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59a78 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59a9c | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59ac4 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59acf | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59ae2 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59b09 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59c74 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59c95 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59cb0 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59cc2 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59cf0 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59d01 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59da8 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59db5 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59dc8 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59e35 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59e55 | 3 | FFX_Abmap_ProcessLayoutCalculation |
| 0xa59e91 | 3 | FFX_Abmap_UpdateCursorAnimation |
| 0xa59f08 | 3 | FFX_Abmap_UpdateCursorAnimation |
| 0xa59f3e | 3 | FFX_Abmap_UpdateCursorAnimation |
| 0xa59f4f | 3 | FFX_Abmap_UpdateCursorAnimation |
| 0xa59f62 | 3 | FFX_Abmap_UpdateCursorAnimation |
| 0xa59f7f | 3 | FFX_Abmap_UpdateCursorAnimation |
| 0xa59fb0 | 3 | FFX_Abmap_UpdateCursorAnimation |
| 0xa59fd3 | 3 | FFX_Abmap_UpdateCursorAnimation |
| 0xa5a027 | 3 | FFX_Abmap_UpdateCursorAndTransitionMode |
| 0xa5a2e3 | 3 | FFX_Abmap_CheckStatRequirementsForSlots |
| 0xa5a453 | 3 |  |
| 0xa5a490 | 3 | FFX_Abmap_SetLinkPointerAndUpdateGeom |
| 0xa5a4d0 | 3 | FFX_Abmap_SetupGlowPlacements |
| 0xa5a4f2 | 3 | FFX_Abmap_SetupGlowPlacements |
| 0xa5a58d | 3 | FFX_Abmap_SetupGlowPlacements |
| 0xa5a598 | 3 | FFX_Abmap_SetupGlowPlacements |
| 0xa5a624 | 3 | FFX_Abmap_SetupGlowPlacements |
| 0xa5a64b | 3 | FFX_Abmap_SetupPlacementAnimOverlayText |
| 0xa5a67e | 3 | FFX_Abmap_SetupPlacementAnimOverlayText |
| 0xa5a692 | 3 | FFX_Abmap_SetupPlacementAnimOverlayText |
| 0xa5a6b4 | 3 | FFX_Abmap_SetupPlacementAnimOverlayText |
| 0xa5a6d2 | 3 | FFX_Abmap_SetupPlacementAnimOverlayText |
| 0xa5a6ef | 3 | FFX_Abmap_SetupPlacementAnimOverlayText |
| 0xa5a6fc | 3 | FFX_Abmap_SetupPlacementAnimOverlayText |
| 0xa5a720 | 3 | FFX_Abmap_CopyCameraScrollData |
| 0xa5a76e | 3 | FFX_Abmap_RecomputeLinkEndpointBuckets |
| 0xa5a7b7 | 3 | FFX_Abmap_RecomputeLinkEndpointBuckets |
| 0xa5a803 | 3 | FFX_Abmap_UpdateRuntimeLinkGeometry |
| 0xa5a8c8 | 3 | FFX_Abmap_UpdateRuntimeLinkGeometry |
| 0xa5a996 | 3 | FFX_Abmap_UpdateNodePlacementPosition |
| 0xa5a9e4 | 3 | FFX_Abmap_UpdateNodePlacementPosition |
| 0xa5aa3b | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5aa59 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5aa71 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5aa81 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5aa95 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5aab2 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5aac6 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5aad5 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ab30 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ab51 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ab72 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ab93 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5abb3 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5abd7 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5abe6 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ac10 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ac1f | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ac57 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ac75 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5ac82 | 3 | FFX_Abmap_DispatchActivationAnim |
| 0xa5acde | 3 | FFX_Abmap_ResetSlotAvailability |
| 0xa5ae07 | 3 | FFX_Abmap_FillNodeIndexFromRuntimeTable |
| 0xa5ae50 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5ae63 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5ae76 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5ae88 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5ae96 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5aec8 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5afe4 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5aff1 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5b002 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5b014 | 3 | FFX_Abmap_WriteMenuBboxFloats_structural |
| 0xa5b037 | 3 | FFX_Abmap_InitCharacterView |
| 0xa5b04a | 3 | FFX_Abmap_InitCharacterView |
| 0xa5b090 | 3 | FFX_Abmap_InitCharacterView |
| 0xa5b0a2 | 3 | FFX_Abmap_InitCharacterView |
| 0xa5b0db | 3 | FFX_Abmap_InitCharacterView |
| 0xa5b148 | 3 | FFX_Abmap_BuildNodeAdjacencyFromLinks |
| 0xa5b1d5 | 3 | FFX_Abmap_BuildNodeAdjacencyFromLinks |
| 0xa5b21c | 3 | FFX_Abmap_BuildNodeAdjacencyFromLinks |
| 0xa5b243 | 3 | FFX_Abmap_InitPlacementGrid |
| 0xa5b4e5 | 3 | FFX_Abmap_LookupNodeLinkCoords |
| 0xa5b52c | 3 | FFX_Abmap_LookupNodeLinkCoords |
| 0xa5b7b0 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b7d6 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b7e5 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b802 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b831 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b846 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b877 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b88c | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b89c | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b8b4 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b8d4 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b8e3 | 3 | FFX_Abmap_InitSlotDisplay |
| 0xa5b900 | 3 | FFX_Abmap_ResetNavCallbacks |
| 0xa5b90f | 3 | FFX_Abmap_ResetNavCallbacks |
| 0xa5b91e | 3 | FFX_Abmap_ResetNavCallbacks |
| 0xa5b930 | 3 | FFX_Abmap_InstallItemUseMenuCallbacks_structural |
| 0xa5b93c | 3 | FFX_Abmap_InstallItemUseMenuCallbacks_structural |
| 0xa5b94b | 3 | FFX_Abmap_InstallItemUseMenuCallbacks_structural |
| 0xa5b95a | 3 | FFX_Abmap_InstallItemUseMenuCallbacks_structural |
| 0xa5b969 | 3 | FFX_Abmap_InstallItemUseMenuCallbacks_structural |
| 0xa5b984 | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5b9c3 | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5b9d7 | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5b9e6 | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5b9f5 | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5ba04 | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5ba29 | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5ba6e | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5ba8c | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5ba9c | 3 | FFX_Abmap_OpenItemUseNodeSelection_Worker |
| 0xa5bb77 | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bba7 | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bbde | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bbfe | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bc11 | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bc24 | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bc37 | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bc4a | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bc5d | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bc70 | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bc82 | 3 | FFX_Abmap_PackMenuSnapshot |
| 0xa5bca3 | 3 | FFX_Abmap_ConsumeItemAndActivateNode |

## Buffer estatico (de A572E0)
- 0x16ab160 (.data)
- 0x16ad870 (.data)
- 0x16ad870 (.data)
- 0x1a86108 (.data)
- 0x16ab160 (.data)

### Pseudocodigo A572E0
```c
// FFX Abmap: Init static menu state buffers
unsigned int FFX_Abmap_InitStaticMenuStateBuffers()
{
  void *hudContext; // edx
  FFX_CharacterId charId; // ecx
  void *hudContext_1; // edx
  FFX_CharacterId charId_1; // ecx
  _DWORD *v4; // ecx
  unsigned int result; // eax

  memset(&MEMORY[0x16AB160], 0, 0x2710u);
  unk_16AD860 = -1;
  n20_3 = (unsigned int)&MEMORY[0x16AD870];
  memset(&MEMORY[0x16AD870], 0, 0x12FC0u);
  MEMORY[0x1A86108] = (int)&MEMORY[0x16AB160];
  FFX_Math_BuildProjectionMatrix(flt_16BEC10, 512.0, 1.0, 1.0833334, 2048.0, 2048.0, 1.0, 16777215.0, 1.0, 65536.0);
  FFX_Math_BuildProjectionMatrix((float *)(n20_3 + 70816), 512.0, 1.0, 1.0, 0.0, 0.0, 1.0, 16777215.0, 1.0, 65536.0);
  FFX_BtlUI_HudParty_GetElement(charId, hudContext);
  FFX_BtlUI_HudParty_GetElement(charId_1, hudContext_1);
  *(float *)(n20_3 + 70420) = 1.0;
  v4 = (_DWORD *)n20_3;
  *(_DWORD *)(n20_3 + 70440) = *(_DWORD *)(n20_3 + 70408);
  v4[17611] = v4[17603];
  v4[17612] = v4[17604];
  v4[17613] = v4[17605];
  *(float *)(n20_3 + 70492) = 1.0;
  *(float *)(n20_3 + 70488) = 1.0;
  *(float *)(n20_3 + 70484) = 1.0;
  *(float *)(n20_3 + 70480) = 1.0;
  *(_BYTE *)(n20_3 + 71108) = 0;
  *(_DWORD *)(n20_3 + 71080) = FFX_Abmap_MainInputDispatcher;
  *(_DWORD *)(n20_3 + 71084) = FFX_Abmap_DispatchSfxByTableEntry_B;
  *(_DWORD *)(n20_3 + 71084) = FFX_Abmap_DispatchSfxByTableEntry_B;
  *(_BYTE *)(n20_3 + 71107) = 0;
  *(_BYTE *)(n20_3 + 71110) = 0x80;
  *(_BYTE *)(n20_3 + 71100) = FFX_MenuState_GetBufferHandle();
  *(_WORD *)(n20_3 + 71280) = -1;
  *(_BYTE *)(n20_3 + 71099) = 1;
  *(_BYTE *)(n20_3 + 71098) = 1;
  *(_DWORD *)(n20_3 + 71336) = -2;
  *(_DWORD *)(n20_3 + 71340) = 0;
  *(float *)(n20_3 + 71348) = 0.0;
  result = n20_3;
  *(_DWORD *)(n20_3 + 71352) = 1;
  return result;
}

```