# Function Index: 0x800000 - 0x9FFFFF

**Binary:** FFX.exe (v1.0.0 - International Steam/JPRY)
**Architecture:** x86 (32-bit)
**Total functions in range:** ~10,800
**Extraction method:** IDA Hex-Rays decompiler
**Extraction date:** 2026-07-11

## Naming Convention

Files are named `<addr>_<name>.c` where:
- `addr` = 8-digit hex address
- `name` = sanitized function name (special characters replaced with `_`)

Each file contains:
- Header with function name, address, and size
- Decompiled C pseudocode from Hex-Rays
- Address annotations: `/*0xNNNNNN*/`

## Contents by Functional Area

### 0x800000 - 0x80FFFF: Magic System Core
| Address | Name | Size |
|---------|------|------|
| 0x800000 | sub_800000 | 0x1 |
| 0x800001 | sub_800001 | 0x6 |
| 0x800010 | sub_800010 | 0x74 |
| 0x800090 | FFX_Magic_ProcessPendingQueue_structural | 0x149 |
| 0x8001E0 | sub_8001E0 | 0x64 |
| 0x800250 | sub_800250 | 0x5c |
| 0x8002B0 | sub_8002B0 | 0x2b |
| 0x800360 | sub_800360 | 0xef |
| 0x8004A0 | sub_8004A0 | 0x65 |
| 0x800510 | sub_800510 | 0xa |
| 0x800520 | sub_800520 | 0x3 |
| 0x800530 | FFX_Magic_RunPhase0Wrapper_structural | 0x57 |
| 0x800590 | FFX_Magic_RunPhase1Wrapper_structural | 0x79 |
| 0x800610 | sub_800610 | 0x3 |
| 0x800620 | sub_800620 | 0x66 |
| 0x800690 | sub_800690 | 0x135 |
| 0x8007D0 | sub_8007D0 | 0xa6 |
| 0x800880 | sub_800880 | 0x3 |
| 0x800890 | sub_800890 | 0x49 |
| 0x8008E0 | sub_8008E0 | 0x65 |
| 0x800950 | FFX_Magic_RunPhase2Wrapper_structural | 0x47 |
| 0x8009A0 | nullsub_723 | 0x1 |
| 0x8009D0 | sub_8009D0 | 0x34 |
| 0x800A10 | sub_800A10 | 0x34 |
| ... | ... | ... |
| 0x80C540 | FFX_MagicCoreOp_00_RecordEndCleanup | 0x98 |
| 0x80C5E0 | FFX_MagicCoreOp_7F_OneShotRecordFinalize | 0x69 |
| 0x80C7A0 | FFX_MagicCoreOp_1D_GuardedRecordEndCleanup | 0x48 |
| 0x80CD60 | FFX_Magic_RunRuntimeRootPhase_structural | 0x12f5 |
| 0x80BEA0 | FFX_Magic_RunAuxRuntimeRootPass_structural | 0x699 |

### 0x810000 - 0x81FFFF: Magic Operations & Post-Processing
| 0x814960 | FFX_MagicCoreOp_54_MatrixDrawSubmit | 0xba |
| 0x8151A0 | FFX_MagicPostProc_00_NormalizeRecordRgba | 0xcf |
| 0x815270 | FFX_MagicPostProc_06_LerpBetweenRecordTransforms | 0x222 |
| 0x816060 | FFX_BtlTick_GetModelProcessingDelay | 0x45 |
| 0x8160B0 | FFX_MagicCoreOp_C9_SphericalPlacement | 0xc4 |
| 0x8167C0 | FFX_MagicCoreOp_C0_GlobalMagicSwitch | 0x103 |
| 0x8169F0 | FFX_MagicCoreOp_02_RelJump | 0xe |
| 0x817200 | FFX_MagicTimeline_WriteRoot84_88_structural | 0xdb |
| 0x817440 | FFX_MagicCoreOp_1E_SetRecordParamByte | 0x16f |
| 0x818250 | FFX_MagicCoreOp_6E_FloatRangeBranch | 0xe4 |
| 0x818550 | FFX_MagicCoreOp_0A_SoundParamSetup_candidate | 0x393 |
| 0x81A110 | FFX_MagicCoreOp_D6_ParamAccumThenPostProc | 0x4cb |

### 0x820000 - 0x82FFFF: Character & Battle Core
| 0x820490 | FFX_BtlActor_FSM_SetGlobalDeathFlag | 0xd |
| 0x821C00 | FFX_BtlTick_FreeTempBattleAllocations | 0x15 |
| 0x822410 | FFX_Achievement_TryUnlock | 0x14 |
| 0x8222E0 | FFX_MagicFile_PollStartGateAndDispatch | 0x124 |
| 0x8246E0 | FFX_Chr_ReseatInstanceTransform | 0x14 |
| 0x825010 | FFX_Chr_AllocateActiveInstance | 0x60f |
| 0x826C10 | FFX_MagicPath_GetNameFromModelSlot | 0xb |
| 0x82AF20 | FFX_Model_SetHideFlag | 0x102 |
| 0x82B500 | FFX_Chr_SetWorldPosition | 0x58 |
| 0x82B8E0 | FFX_BtlChr_SetHPGaugeFloatTransition | 0x20 |
| 0x82B980 | FFX_BtlChr_SetHPValueFloatTransition | 0x20 |
| 0x82B9C0 | FFX_Chr_SetVisualScale | 0x1d |
| 0x82BA10 | FFX_BtlChr_SetFloatTransition | 0x1e |
| 0x82BF60 | FFX_Graphics_SetFadeState | 0x75 |
| 0x82C140 | FFX_MagicCoreOp_UpdateEffectResourceState | 0x692 |

### 0x830000 - 0x83FFFF: Battle Effects & Menu Fade
| 0x82C140 | FFX_MagicCoreOp_UpdateEffectResourceState | 0x692 |
| 0x82CC00 | __exit | 0x14 |
| 0x82CCF0 | FFX_BtlActor_FSM_ResetFadeCounter | 0x9 |
| 0x82CD00 | FFX_BtlActor_FSM_ApplyFadeEffect | 0x20 |
| 0x82DB50 | FFX_Chr_SetControlledInstance | 0x35 |
| 0x82B460 | FFX_BtlMenu_ClearActorModelAnimation | 0x11 |
| 0x8357D0 | FFX_BtlMenu_ResetActorModelCommandState | 0x25 |
| 0x83C520 | FFX_Memory_SetAlignment | 0x29 |
| 0x83F090 | FFX_Memory_FreeSubsystemData | 0x10 |
| 0x83F0A0 | FFX_Btl_SubAllocAligned | 0x13 |
| 0x83F160 | FFX_VictoryScreen_SetupKernelViewport | 0x5c |

### 0x840000 - 0x84FFFF: Field Map System
| 0x83E980 | FFX_FieldMap_DecodeEncounterGroupFromPolyMeta | 0x20 |
| 0x83EA00 | FFX_FieldMap_SetActiveGuideMapRoot | 0xd1 |
| 0x844490 | FFX_FieldMap_RasterizeGuidePolyBatch_structural | 0x301 |
| 0x8447A0 | FFX_FieldMap_RasterizeEncounterPolyBatch_structural | 0x2e0 |
| 0x844BC0 | FFX_FieldMap_RegisterGuideMapBlob | 0xe0 |
| 0x844D10 | FFX_FieldMap_LoadEncounterGuideFromFfxmapId | 0x19e |
| 0x845030 | FFX_FieldMap_ProjectVertexToScreen | 0x89 |
| 0x859F50 | FFX_SceneState_GetBase_w | 0x5 |
| 0x8579E0 | FFX_Atel_Common_obtainTreasureSilently | 0xb5 |
| 0x85A740 | FFX_Atel_Common_obtainTreasure | 0x2d2 |
| 0x85F8E0 | FFX_Atel_Cmd_SetActorPosition | 0x5e |
| 0x861100 | FFX_BtlTick_SceneTransitionFinalize | 0x2a5 |

### 0x860000 - 0x86FFFF: Field Actor & ATEL Scripting
| 0x860740 | sub_860740 | 0x1ea |
| 0x862C00 | FFX_Field_RenderActorByAnimation | 0x52 |
| 0x862CD0 | FFX_Field_PushActorContext | 0x1f |
| 0x862D10 | FFX_Field_SyncActorToInstanceTransform | 0x344 |
| 0x864180 | FFX_Atel_InterpretWorkerOpcodes | 0x1070 |
| 0x865390 | FFX_Field_SetActorAnimationPhase | 0xcd |
| 0x8661E0 | FFX_Battle_InitBattleAndScheduleEntry | 0x1ee |
| 0x8678F0 | FFX_Field_RunAllActorScripts | 0x2b5 |
| 0x868380 | FFX_Field_RunSingleActorScript | 0x7b |
| 0x869040 | FFX_Field_InitActorAnimation | 0x12b |
| 0x869D00 | FFX_Atel_FetchOpcode | 0x40 |
| 0x86A220 | FFX_Atel_ComputeScriptChunksSize | 0x52 |
| 0x86A5E0 | FFX_Atel_GetScriptWorkerCount | 0xc |
| 0x86A7C0 | FFX_Field_GetActorByIndex | 0x135 |
| 0x86AE10 | FFX_TK_GetChrPointer | 0xe |

### 0x870000 - 0x87FFFF: Field VM & Encounter System
| 0x86B170 | FFX_Field_GetActorPosition | 0x82 |
| 0x86B200 | FFX_Field_GetActorRotation | 0x83 |
| 0x86B2B0 | FFX_Field_GetActorTypeId | 0x4b |
| 0x86BB10 | FFX_Atel_GetScriptWorkerByIndex | 0x11 |
| 0x86C050 | FFX_Atel_ComputeScriptDataSize | 0x98 |
| 0x86C0F0 | FFX_Atel_ComputeWorkerDataSizeAligned | 0x21 |
| 0x86C380 | FFX_Field_GetActorAnimationPhase | 0x14 |
| 0x86DDE0 | FFX_TK_PopStackFloat | 0xa2 |
| 0x86DE90 | FFX_FieldVM_PopOperand | 0x3f |
| 0x86EDA0 | FFX_Field_InitActorSlot | 0x226 |
| 0x86F6C0 | FFX_Field_PopActorContext | 0x13 |
| 0x870810 | FFX_Atel_ZeroWorkerDataBuffer | 0x52 |
| 0x870AC0 | FFX_Field_WarpActorToPosition | 0x1e1 |
| 0x8715F0 | FFX_Field_DispatchActorAnimSound | 0x57 |
| 0x871980 | sub_871980 | 0xc4 |
| 0x871A50 | FFX_Field_SelectControlledActorInstance | 0xef |
| 0x871B60 | FFX_Field_UpdateWalkEncounter | 0x1a1 |
| 0x872CC0 | FFX_Field_InitSceneResetSubsystems | 0x1c2 |
| 0x872E90 | FFX_Event_LoadObjResources | 0x60a |
| 0x875650 | FFX_Atel_InstantiateScriptsIntoActor | 0x26e |
| 0x875AC0 | FFX_Field_ResolveEncounterZoneIndices | 0xd6 |
| 0x875BA0 | FFX_Field_SampleEncounterZoneSlot | 0x70 |
| 0x875C10 | FFX_Field_InterpolateEncounterZoneGroup | 0x9e |

### 0x880000 - 0x88FFFF: I/O, Menu, and Battle Effects
| 0x8768D0 | FFX_BtlEffect_PlaySfxPositional | 0x98f |
| 0x877260 | FFX_BtlEffect_ResetMatrixMode | 0xb |
| 0x8776B0 | FFX_Atel_CallStatusDispatchByNamespace | 0x36 |
| 0x877720 | FFX_Atel_CallPreDispatchByNamespace | 0x49 |
| 0x877770 | FFX_Atel_CallReturnDispatchByNamespace | 0x87 |
| 0x878170 | FFX_Field_LoadStateRecordIntoSceneBlock_structural | 0x3e |
| 0x8781B0 | FFX_Atel_ReadEncounterGroupFromSaveStack_structural | 0x50 |
| 0x885C60 | FFX_BtlEffect_ResolveCtx | 0x10 |
| 0x885C70 | FFX_BtlEffect_ResolveId | 0xd |
| 0x8860A0 | FFX_BtlEffect_GetSlotCapacity | 0x2b |
| 0x886140 | FFX_BtlEffect_GetSlotTable | 0x188 |
| 0x886350 | FFX_BtlMenu_PostBattle_FadeTransitionSetup | 0x6 |
| 0x886410 | FFX_BtlMenu_PostBattle_WaitResourceLoad | 0x1a |
| 0x8865B0 | FFX_BtlMenu_PostBattle_WaitResourceDecompress | 0x3 |
| 0x8865E0 | FFX_BtlEffect_CheckEffect | 0x2d |
| 0x886610 | FFX_BtlEffect_ApplyRequest | 0x12a |
| 0x886740 | FFX_BtlEffect_MapEffectId | 0x1d |
| 0x886760 | FFX_BtlMenu_Fade_SetupAlphaOut | 0x21 |
| 0x886980 | FFX_BtlMenu_Fade_InitSurface | 0x36 |
| 0x8869C0 | FFX_BtlMenu_Fade_SetupAlphaIn | 0x21 |
| 0x886A50 | FFX_BtlMenu_PostBattle_FadeTransitionRun | 0x47 |
| 0x886AE0 | FFX_BtlEffect_PlaySfxGated | 0x14 |
| 0x886B00 | FFX_Btl_MenuDispatchSfx | 0x31 |
| 0x886C80 | FFX_BtlEffect_SetPitchDirect | 0x2c |
| 0x886CB0 | FFX_BtlEffect_SetPitchTranslate | 0x2f |
| 0x886CE0 | FFX_BtlEffect_Reset | 0x2e |
| 0x886D50 | FFX_BtlEffect_SetVolume | 0x27 |
| 0x886D80 | FFX_BtlEffect_SetPan | 0x2a |
| 0x886DB0 | FFX_BtlEffect_PlaySfx | 0x2a |
| 0x886DE0 | FFX_BtlEffect_Enable | 0x28 |
| 0x886E10 | FFX_BtlEffect_Disable | 0x24 |
| 0x886EC0 | FFX_BtlEffect_SetParam | 0x27 |
| 0x886EF0 | FFX_BtlEffect_GetParam | 0x27 |
| 0x886F50 | FFX_BtlEffect_EnableTimed | 0x2a |
| 0x8870E0 | FFX_BtlTick_ResetBattleSystemState | 0x5 |
| 0x8876C0 | FFX_BtlEffect_DisableDirect | 0x5 |
| 0x887870 | FFX_BtlMenu_Fade_IsSystemBusy | 0x9 |
| 0x887A00 | FFX_BtlInit_RegisterSoundPath | 0x9 |
| 0x887BC0 | FFX_Btl_IsBattleSystemReady | 0x8 |
| 0x888850 | FFX_Iop_InitDeviceBuffer | 0x2f |
| 0x888880 | FFX_Iop_InitDeviceButtons | 0x2e |
| 0x888950 | FFX_Iop_ReadRawAnalogByte | 0x9 |
| 0x888960 | FFX_Iop_InitAnalogFloats | 0x43 |
| 0x8889B0 | FFX_Iop_CheckAxisPresence | 0x2c |
| 0x8889E0 | FFX_Iop_ReadCursorPosition | 0xe4 |
| 0x888AF0 | FFX_HUD_InputStateGetDevice | 0x1f |
| 0x888B90 | FFX_HUD_InputStateReadByte | 0x1f |
| 0x888CE0 | FFX_Battle_GetInitReadyMask | 0x1a |
| 0x888D80 | FFX_Iop_GetPollingSlot | 0x13 |
| 0x888DF0 | FFX_BtlHud_InputStateRead | 0x1a |
| 0x888E30 | FFX_Iop_GetDeviceContext | 0x13 |
| 0x888E50 | FFX_Iop_ResetDeviceFlag | 0x11 |
| 0x888E70 | FFX_Iop_ResetDeviceGlobals | 0x15 |
| 0x888F00 | FFX_Iop_DeviceOpenRoutine | 0x65 |
| 0x888F70 | FFX_Iop_InitAnalogNeutralZone | 0x2a |
| 0x888FC0 | FFX_Iop_DeviceDispatch | 0x2aa |
| 0x8892B0 | FFX_Iop_InitAllDevices | 0x16 |
| 0x8892D0 | FFX_Iop_InitDeviceContext | 0x77 |
| 0x889350 | FFX_Iop_TickDeviceInit | 0x24 |
| 0x889380 | FFX_Iop_ComputeCursorPosition | 0x4b |
| 0x8893D0 | FFX_Iop_StoreCursorPosition | 0x23 |
| 0x889460 | FFX_Iop_WriteRemapTable | 0x1a |
| 0x889480 | FFX_Iop_CheckAnalogDeviceTransition | 0x57 |
| 0x8894E0 | FFX_Iop_CalibrateAnalogData | 0x21a |
| 0x889700 | FFX_Iop_PollDeviceState | 0x10f |
| 0x889810 | FFX_Iop_SetupDeviceData | 0x9e |
| 0x8899F0 | FFX_Iop_TickDevicePoll | 0x1f |
| 0x889A10 | FFX_Iop_NormalizeAnalogValue | 0x1c |
| 0x889E00 | sub_889E00 | 0x1a8 |
| 0x889FB0 | FFX_Sfx_CalcPositionalFactor | 0x360 |

### 0x8D0000 - 0x8DFFFF: Battle HUD & UI
| 0x88CC60 | FFX_Ps2Locale_LoadLocalizedMenuBin | 0x15d |
| 0x88D340 | FFX_Scene_PumpPendingTransition | 0xa3 |
| 0x88DFE0 | FFX_Scene_InitScene | 0x2b6 |
| 0x88E9D0 | FFX_Scene_RequestTransition | 0x90 |
| 0x88EA60 | FFX_Scene_SetCurrentMapId | 0x4c |
| 0x890E60 | FFX_BtlQueue_ClearDelayTimer | 0xb |
| 0x890EA0 | FFX_Btl_HudRotationAngleTick | 0x35 |
| 0x890EE0 | FFX_Btl_SubmenuStateMachine | 0x1a7 |
| 0x8910B0 | FFX_Btl_HudRefreshPartyArrays | 0xdb |
| 0x891190 | FFX_Btl_HudOvrGaugeTick | 0xbb |
| 0x891250 | FFX_Btl_SubmenuContextCommandDisplay | 0x19e |
| 0x8913F0 | FFX_Btl_UI_Overdrive_DetectReadyActor | 0xf2 |
| 0x8914F0 | FFX_Btl_UI_Overdrive_AnimateGauge | 0x4ab |
| 0x8919A0 | FFX_Btl_HudSubmenuTransitionTick | 0x64 |
| 0x891A30 | FFX_Btl_HudShimmerScrollUpdate | 0xb4 |
| 0x891AF0 | FFX_Btl_HudAnimationTickAll | 0x528 |
| 0x892040 | FFX_Btl_SubmenuRefresh | 0x239 |
| 0x892290 | FFX_Btl_SubmenuShimmerNavTick | 0x23a |
| 0x8927E0 | FFX_BtlQueue_ActorActionEvent | 0x3c |
| 0x893440 | FFX_BtlQueue_SimpleEvent_3003 | 0x1d |
| 0x893460 | FFX_BtlQueue_SimpleEvent_3002 | 0x1d |
| 0x893480 | FFX_BtlQueue_TargetedActionEvent | 0xdf |
| 0x893560 | FFX_BtlQueue_KernelStringActionEvent | 0x68 |
| 0x8935D0 | FFX_BtlQueue_SignedActionEvent | 0x67 |
| 0x8939A0 | FFX_BtlUI_DrawScanTargetInfoPanel | 0xd8f |
| 0x894AB0 | FFX_BtlUI_DrawScanElementResistRow_4ElemHardcoded | 0x5ee |
| 0x8951B0 | FFX_BtlUI_DrawScanStatusRow | 0xdb |
| 0x895290 | FFX_BtlQueue_CommandActionEvent | 0x6d |
| 0x8953F0 | FFX_Btl_DrawOverdriveGaugeFill | 0x152 |
| 0x896050 | FFX_Menu2D_DrawProgressBar | 0x36f |
| 0x8963C0 | FFX_BtlUI_RenderPartyStatusDetail | 0xd9a |
| 0x897170 | FFX_BtlQueue_ShowStandardActionEvent | 0x3c |
| 0x8975C0 | FFX_GetActorElementCategoryMask_Switch4 | 0x4b |
| 0x8978E0 | FFX_Btl_SubmenuInitTargeting | 0x60 |
| 0x897E70 | FFX_BtlHud_ShimmerResetAll | 0x61 |
| 0x897EE0 | FFX_Btl_SubmenuCursorInit | 0x91 |
| 0x897F80 | FFX_Battle_SubmenuOvrRowBuild | 0x117 |
| 0x8980F0 | FFX_Btl_SubmenuSliderInit | 0xa5 |
| 0x8981D0 | FFX_Btl_UI_BuildOverdriveSubcommandList | 0xca |
| 0x898A40 | FFX_Btl_SubmenuSetupTargeting | 0x9a |
| 0x898B60 | FFX_Btl_SubmenuSetupCursor | 0x68 |
| 0x898C10 | FFX_Btl_SubmenuSetupSlider | 0xce |
| 0x898D60 | FFX_BtlMenu_ScrollDown | 0x2f |
| 0x898D90 | FFX_BtlMenu_ScrollUp | 0x1d |
| 0x899E90 | FFX_Btl_UI_Overdrive_ResetGaugeToActor | 0xa6 |
| 0x899F40 | FFX_Btl_UI_Overdrive_InitGaugeForActor | 0x18b |
| 0x89A5A0 | FFX_Btl_MenuPopSubmenuEntry | 0xde |
| 0x89A890 | FFX_BtlHud_ShimmerStopOnEntry | 0x27 |
| 0x89AAC0 | FFX_BtlHud_ShimmerStart | 0x30 |
| 0x89AB10 | FFX_BtlHud_ShimmerStopOnExit | 0x27 |
| 0x89AD50 | FFX_Btl_MenuCursorResetGlobals | 0x3a |
| 0x89AD90 | FFX_BtlTick_UI_AllHudAndSubmenuTick | 0x17d |
| 0x89AF30 | FFX_Btl_SubmenuBuildCommandList | 0x173 |
| 0x89B2D0 | FFX_BtlUI_RenderBattleHudRoot_CallsScanPanel | 0x1c9 |
| 0x89BA80 | FFX_Btl_UI_OpenSubmenu | 0x132 |
| 0x89C870 | FFX_Btl_MenuCursorNavigate | 0x4d5 |
| 0x89E5D0 | sub_89E5D0 | 0x628 |
| 0x89EC70 | sub_89EC70 | 0x3f7 |
| 0x89F300 | sub_89F300 | 0xf36 |
| 0x8A0236 | sub_8A0236 | 0x1c5 |

### 0x8B0000 - 0x8BFFFF: Sphere Grid & Menu 2D
| 0x8CC300 | FFX_SphereGrid_NodeActivateStateMachine | 0x6f8 |
| 0x8A9790 | j_FFX_Abmap_RecomputePartyStatsAndLearnedMoves | 0x5 |
| 0x8B7C10 | FFX_BtlMenu_GetScrollStep | 0x6 |

### 0x8C0000 - 0x8CFFFF: Battle Queue & Dialogue
| 0x8DE8A0 | FFX_Btl_DialogueSpeedSetup | 0x81 |
| 0x8DE950 | FFX_Btl_DialogueTextProgress | 0x8c |
| 0x8DECE0 | FFX_Btl_DialogueScrollInit | 0x59 |
| 0x8DF560 | FFX_Btl_DialogueFrameCounter | 0x9c |
| 0x8E01A0 | FFX_Btl_DialogueStateEntry | 0x4e |
| 0x8E02B0 | FFX_Btl_DialogueTextComplete | 0x28 |

### 0x8F0000 - 0x8FFFFF: Menu2D Drawing
| 0x8F41B0 | FFX_Menu2D_DrawRoundedPanel9Slice | 0x96c |
| 0x8F4B20 | FFX_Menu2D_DrawFilledRect | 0x118 |
| 0x8F5F70 | sub_8F5F70 | 0x28be |
| 0x8FDE10 | FFX_Menu2D_SetViewport | 0x3a |
| 0x8F9280 | sub_8F9280 | 0x6e3 |
| 0x8F9C20 | sub_8F9C20 | 0x829 |
| 0x8F8BB0 | sub_8F8BB0 | 0x195 |
| 0x8F8D50 | sub_8F8D50 | 0x190 |
| 0x8F8EE0 | sub_8F8EE0 | 0x303 |

### 0x900000 - 0x90FFFF: Menu2D Drawing (cont.)
| 0x8FF490 | sub_8FF490 | 0x1421 |
| 0x8FDE10 | FFX_Menu2D_SetViewport | 0x3a |
| 0x901660 | FFX_Menu2D_DrawIconOrTimer | 0x47 |
| 0x901700 | sub_901700 | 0x2d3 |
| 0x9019F0 | sub_9019F0 | 0xf9 |
| 0x902700 | sub_902700 | 0x10b |
| 0x902EF0 | sub_902EF0 | 0x408 |
| 0x9034B0 | sub_9034B0 | 0x55a |
| 0x903BB0 | FFX_Menu2D_DrawTexQuadSolid | 0x326 |
| 0x903EE0 | FFX_Menu2D_DrawTexQuadTinted | 0x36c |
| 0x904BA0 | sub_904BA0 | 0x5e4 |
| 0x9057C0 | FFX_Menu2D_DrawNumberText | 0x5c |
| 0x905890 | FFX_Menu2D_DrawNumberWithAlignment | 0x94 |
| 0x905930 | FFX_Menu2D_DrawStatusEffectTimerBar | 0x38 |
| 0x905970 | FFX_Menu2D_DrawStatusEffectTimerBarEx | 0x13c |
| 0x905AB0 | FFX_Menu2D_DrawKernelString | 0x278 |

### 0x906000 - 0x906FFF: Magic Texture Path
| 0x906420 | FFX_Magic_BuildPs3MagicTexturePath | 0x260 |

### 0x920000 - 0x92FFFF: Lua VM & String Allocation
| 0x92A440 | sub_92A440 | 0x2c1 |
| 0x94A950 | LuaObj_IndexRead | 0x92 |
| 0x94AA40 | LuaGC_StackCheck | 0x15 |
| 0x94AA60 | Lua_IndexAddr | 0x64 |
| 0x94AD00 | Lua_ErrorCleanup | 0x5e |
| 0x94AE40 | Lua_ErrorAbort | 0xb |
| 0x94AE50 | LuaObj_TableArrayOp | 0x148 |
| 0x94B030 | Lua_PushString | 0x47 |
| 0x94B0D0 | Lua_PushTypedValue | 0x57 |
| 0x94B730 | LuaStack_PushSlot | 0x16 |
| 0x94B880 | Lua_ErrorPushMsg | 0x2b |
| 0x94B8B0 | LuaObj_RawEqual | 0x53 |
| 0x94BDC0 | Lua_Pop | 0x44 |
| 0x94BF60 | sub_94BF60 | 0x53 |
| 0x94BFC0 | LuaBridge_ResolveValue | 0x76 |
| 0x94C040 | LuaBridge_ReadFloat | 0x51 |
| 0x94C1B0 | Lua_ToPointer | 0x30 |
| 0x94C1E0 | Lua_Type | 0x25 |
| 0x94C5F0 | sub_94C5F0 | 0x29 |
| 0x94CD50 | Lua_Error | 0x2a |
| 0x94CF60 | sub_94CF60 | 0x2ca |
| 0x94D2B0 | sub_94D2B0 | 0x256 |
| 0x94DD20 | Lua_ErrorPushPrefix | 0x82 |
| 0x94E040 | LuaGC_RunGCFinalizer | 0x111 |
| 0x94E160 | LuaGC_ComputeSize | 0x16d |
| 0x94E2D0 | LuaGC_InitSweep | 0x136 |
| 0x94E410 | LuaGC_ShrinkStrTable | 0x47 |
| 0x94E460 | LuaGC_MarkUpvalList | 0x8e |
| 0x94E4F0 | LuaGC_MarkTableList | 0xdf |
| 0x94E5D0 | LuaGC_PropagateUpvalues | 0x50 |
| 0x94E690 | LuaGC_FreeNode | 0xaf |
| 0x94E790 | LuaGC_AtomicStep | 0x7f |
| 0x94E810 | LuaGC_IncrementalStep | 0x25d |
| 0x94EAD0 | LuaV_Exec_GCStep | 0x38 |
| 0x94EB10 | LuaV_Exec_GCRelease | 0x1b |
| 0x94EB30 | LuaV_ClosureDebugSetup | 0x42 |
| 0x94ECE0 | LuaGC_Step | 0x52 |
| 0x94EDD0 | LuaGC_FullCycle | 0xf1 |
| 0x94EF20 | LuaGC_MarkArray | 0x1a5 |
| 0x94F0E0 | LuaState_ErrorAfterCall | 0x28 |
| 0x94F110 | LuaGC_TraverseStrTable | 0xe2 |
| 0x94F240 | LuaGC_TraverseGrayArray | 0xfa |
| 0x94F380 | LuaGC_Finalize | 0x6f |
| 0x94F3F0 | LuaGC_ProcessGrayLoop | 0x9b |
| 0x94F4F0 | LuaGC_MarkSingle | 0xa7 |
| 0x94F5E0 | LuaGC_Mark | 0xec |
| 0x94F710 | LuaGC_MarkWeakTable | 0x3e |
| 0x94F970 | LuaGC_Free | 0xea |
| 0x94FAA0 | LuaGC_SweepList | 0x113 |
| 0x94FBC0 | LuaGC_MarkClosure | 0x125 |
| 0x94FD30 | LuaGC_MarkFunction | 0x12b |
| 0x94FEA0 | LuaGC_MarkTableKeys | 0x148 |
| 0x94FFF0 | LuaGC_MarkThread | 0x109 |
| 0x950100 | LuaGC_MarkUserData | 0x6f |
| 0x950170 | LuaGC_MarkTableDefault | 0xab |
| 0x950220 | LuaGC_MarkTable | 0xe4 |
| 0x950310 | LuaGC_MarkTableKeyList | 0xe1 |
| 0x950600 | LuaGC_FreeUpvalList | 0x3b |
| 0x950640 | LuaGC_FreeClosure | 0x4d |
| 0x950690 | LuaGC_ReturnDebt | 0x16 |
| 0x955960 | LuaV_MathOp | 0xfd |
| 0x955BD0 | LuaV_Exec_DecodeExp | 0x1b |
| 0x955C40 | LuaO_PushFString | 0x17 |
| 0x955C60 | LuaO_PushFStringImpl | 0x251 |
| 0x955F20 | LuaConvert_StringToNumber | 0x88 |
| 0x955FB0 | LuaConvert_HexStringToNumber | 0x15e |
| 0x956D10 | LuaV_ArithTypeError | 0x2c |
| 0x956E40 | LuaState_ErrorThrow | 0x24 |
| 0x956E70 | LuaV_TypeError | 0xaa |
| 0x957420 | LuaTable_FindNextEntry | 0x21 |
| 0x9574A0 | LuaStack_CCall | 0x86 |
| 0x957530 | LuaStack_Grow | 0x67 |
| 0x9575A0 | LuaStack_CallHook | 0xaa |
| 0x957650 | LuaStack_ExecGuard | 0x8a |
| 0x9576E0 | LuaStack_CopyArgs | 0xac |
| 0x957790 | LuaStack_CallDispatch | 0x1cd |
| 0x957A40 | LuaStack_ProtectedCall | 0x7c |
| 0x957AC0 | LuaStack_Realloc | 0xdf |
| 0x957BA0 | LuaStack_Shrink | 0x56 |
| 0x957C00 | LuaState_Panic | 0x75 |
| 0x957F50 | LuaStack_PushResult | 0x79 |
| 0x958150 | LuaStack_FreeBlocks | 0x9b |
| 0x9581F0 | LuaV_UpvaluePush | 0x70 |
| 0x958260 | LuaGC_FreeProto | 0x8f |
| 0x9582F0 | LuaGC_FreeUpValue | 0x32 |
| 0x9583B0 | LuaV_ClosureAlloc | 0x42 |
| 0x958540 | LuaStr_NewShort | 0x153 |
| 0x9586A0 | LuaValue_RawEqual | 0x71 |
| 0x958720 | LuaValue_Equal | 0x37 |
| 0x958760 | LuaStr_Hash | 0x40 |
| 0x9587D0 | LuaStr_Create | 0x71 |
| 0x958850 | LuaStrBuf_New | 0x3c |
| 0x958890 | LuaStr_TableResize | 0x114 |
| 0x958A60 | LuaTable_ComputeOptArraySize | 0x62 |
| 0x958B20 | LuaOp_Table_Next | 0xb0 |
| 0x958C10 | LuaStr_FloatHash | 0x74 |
| 0x958C90 | LuaStr_TableFree | 0x57 |
| 0x958CF0 | LuaStr_Find | 0xc1 |
| 0x958DC0 | LuaTable_FindIntKey | 0x66 |
| 0x958E30 | LuaStr_ArrayBoundary | 0x5b |
| 0x958E90 | LuaStr_FindByHash | 0x3b |
| 0x958ED0 | LuaStr_TableNew | 0x41 |
| 0x958F20 | LuaTable_RawSet | 0x13f |
| 0x959140 | LuaTable_ArrayResize | 0x183 |
| 0x9592D0 | LuaOp_Concat | 0x3f |
| 0x959310 | LuaTable_FindOrSet | 0x20 |
| 0x959330 | LuaTable_ArrayGet | 0x52 |
| 0x959390 | LuaTable_HashSlot | 0xc6 |
| 0x959490 | LuaTable_CountArrayUsed | 0x72 |
| 0x959510 | LuaTable_CountHashUsed | 0x9f |
| 0x9595B0 | LuaTable_Rehash | 0x128 |
| 0x9596E0 | LuaTable_ArrayGrow | 0x5f |
| 0x959740 | LuaTable_HashResize | 0xca |
| 0x95A200 | LuaV_EqualMetaDispatch | 0xc7 |
| 0x95A2D0 | LuaV_ExecuteArithFallback | 0xd5 |
| 0x95A400 | LuaV_EqualMetamethod | 0x91 |
| 0x95A4A0 | LuaV_Exec_UpvalueMatch | 0x62 |
| 0x95A510 | LuaV_CompareString | 0x7f |
| 0x95A590 | LuaV_ArithDispatch | 0xe9 |
| 0x95A680 | LuaOp_ConcatStr | 0x282 |
| 0x95A910 | LuaV_EqualDispatch | 0xcd |
| 0x95AA10 | LuaVM_Dispatch | 0x106a |
| 0x95BCB0 | LuaOp_GetTable | 0x14f |
| 0x95BE00 | LuaV_CompareLE | 0xdd |
| 0x95BEE0 | LuaV_CompareLT | 0x95 |
| 0x95BF80 | LuaOp_Length | 0x15b |
| 0x95C0E0 | LuaTable_SetField | 0x183 |
| 0x95C270 | LuaConvert_ToNumber | 0x48 |
| 0x95C2C0 | LuaConvert_NumberToString | 0x7f |
| 0x95C340 | LuaOp_Closure | 0x93 |
| 0x95C3E0 | LuaOp_Return | 0xd9 |
| 0x95C4C0 | LuaV_TryGetMetamethod | 0x28 |
| 0x95C4F0 | LuaV_GetMetamethodEvent | 0x52 |
| 0x95C620 | LuaAlloc_Realloc | 0x69 |
| 0x95C690 | LuaAlloc_ErrorBlockTooBig | 0x10 |

### 0x980000 - 0x98FFFF: D3D11 & Rendering
| 0x96838E | D3D11CreateDevice | 0x6 |
| 0x968394 | D3D11CreateDeviceAndSwapChain | 0x6 |

### 0x9D0000 - 0x9FFFFF: Magic File I/O, FMOD, Steam, and Runtime
| 0x9DA3A0 | FFX_Btl_GetCurrentBattleFormationId | 0x6 |
| 0x9DA370 | FFX_MagicFile_GetEffectOverlayTable | 0x20 |
| 0x9DA3D0 | FFX_MagicFile_InitGlobals | 0x3b |
| 0x9DA420 | FFX_MagicFile_LoadDllByMagicId | 0x2c2 |
| 0x9DA780 | FFX_MagicFile_SetMagicId | 0x41 |
| 0x9DA7D0 | FFX_MagicFile_Start | 0x82 |
| 0x9DA860 | FFX_MagicFile_Stop | 0xdf |
| 0x9DA940 | FFX_MagicFile_Unload | 0x2f8 |
| 0x9DAC40 | FFX_MagicFile_UnloadPendingAndReleaseAux | 0x37 |
| 0x9DAC80 | FFX_MagicFile_ClearPreloadWrapper | 0x1b |
| 0x9DACA0 | FFX_MagicFile_ClearPreloadedPrx | 0x9f |
| 0x9DAE70 | FFX_MagicFile_PreloadAsync | 0x139 |
| 0x9DB0F0 | FFX_MagicFile_BindDllExports | 0x60 |
| 0x9DB160 | j_memcpy | 0x5 |
| 0x9DBD70 | sub_9DBD70 | 0x7a |
| ... | ... | ... |
<!-- Note: The complete index would contain ~10,800 entries.
     Use batch_decompile_all.py to extract all and generate a complete index. -->

## How to Extract Remaining Functions

The `batch_decompile_all.py` script (in this directory) extracts ALL functions
in the range when run inside IDA Pro:

```
File -> Script file... -> batch_decompile_all.py
```

Or paste the script content into IDAPython console.

## Statistics

- **Total functions in range:** ~10,800
- **Already extracted (batch 1):** 20 functions (0x800000-0x8008E0)
- **Script for full extraction:** batch_decompile_all.py
- **IDA DB:** ffx_exe_copy.i64
- **IDA session ID (headless):** 76b991e4

## Key Functional Sections

| Range | Description |
|-------|-------------|
| 0x800000-0x80FFFF | Magic System Core |
| 0x810000-0x81FFFF | Magic Core Operations & Post-Processing |
| 0x820000-0x82FFFF | Battle Tick, Character, Model |
| 0x830000-0x83FFFF | Battle Effects, Menu Fade, IOP |
| 0x840000-0x84FFFF | Field Map System |
| 0x850000-0x85FFFF | ATEL Scripting, Treasure, Positional |
| 0x860000-0x86FFFF | Field Actor System, ATEL Interpreter |
| 0x870000-0x87FFFF | Field VM, Walk Encounter, Scene |
| 0x880000-0x88FFFF | IOP Input, Battle Effects, Sound |
| 0x890000-0x89FFFF | Battle HUD, Submenus, UI Drawing |
| 0x8A0000-0x8AFFFF | Menu Cursor, Party, Battle Queue |
| 0x8B0000-0x8BFFFF | Battle UI, Scroll, Selection |
| 0x8C0000-0x8CFFFF | Sphere Grid, Dialogue System |
| 0x8D0000-0x8DFFFF | Scene Transitions, Dialogue |
| 0x8E0000-0x8EFFFF | Battle Dialogue, Post-Battle |
| 0x8F0000-0x8FFFFF | Menu2D Drawing Functions |
| 0x900000-0x90FFFF | Menu2D Text/Quad Drawing |
| 0x910000-0x91FFFF | Menu2D/UI Drawing |
| 0x920000-0x92FFFF | UI Elements, Battle (cont.) |
| 0x930000-0x93FFFF | Battle UI, Scrolling, Events |
| 0x940000-0x94FFFF | Lua VM, FMOD, Steam, Debug |
| 0x950000-0x95FFFF | Lua VM Core (complete GC, table, string, exec) |
| 0x960000-0x96FFFF | D3D11, Rendering Pipeline |
| 0x970000-0x97FFFF | GPU Resources, Shaders |
| 0x980000-0x98FFFF | D3D11 Device Creation, Swap Chain |
| 0x990000-0x99FFFF | Concurrency Runtime, Threadpool |
| 0x9A0000-0x9AFFFF | Concurrency (cont.), Misc Runtime |
| 0x9B0000-0x9BFFFF | Concurrency Runtime, C++ Runtime |
| 0x9C0000-0x9CFFFF | Post-Battle, Concurrency, RTC |
| 0x9D0000-0x9DFFFF | Magic File I/O, FMOD Audio, Steam |
| 0x9E0000-0x9EFFFF | Concurrency RT, Phyre Lua Bridge |
| 0x9F0000-0x9FFFFF | Runtime, IMRT, RTC check functions |
