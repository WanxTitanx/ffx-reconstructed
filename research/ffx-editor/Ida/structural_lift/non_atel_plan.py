#!/usr/bin/env python3
"""Non-ATEL rename manifest — all entries verified by decompile/xref/string evidence."""
import json

OUT = '/home/wanderson/Documents/ffx-editor-main/work/_structural_lift'
census = {f['addr']: f['name'] for f in json.load(open(f'{OUT}/structural_funcs.json'))}

# (addr, new_name, evidence, kind)
LIFT = [
 ("0x575410","Phyre_PClassDataMember_ctorAttach","262 callers; body calls StringNode_Ctor, sets vtable/meta, links class member, invokes descriptor callback","CONFIRMED"),
 ("0x86a920","FFX_Field_GetScriptSelfActorIndexPtr","198 callers; returns a1+192 (self-actor-index field of worker ctx)","CONFIRMED"),
 ("0x86a7c0","FFX_Field_AiScriptStateMachine","164 callers; segmented-table actor-index->worker/state-machine resolver","CONFIRMED"),
 ("0x6ed4a0","FFX_Matrix4x4_Copy16Dwords_Thunk","72 callers; 16-dword copy thunk","CONFIRMED"),
 ("0x6ecd80","FFX_Matrix4x4_Copy16Dwords","literal 16-dword (64B) copy body","CONFIRMED"),
 ("0x630670","FFX_GameAllocWrapper","54 callers; tail-calls Heap_AllocGameArenaDebugFill_wrapper","CONFIRMED"),
 ("0x86e380","FFX_FieldVM_PushIntOperand","45 callers; pushes int operand into VM operand stack (flag byte,slot array)","CONFIRMED"),
 ("0x86e350","FFX_FieldVM_PushFloatOperand","pushes float operand (type flag 2 at +84, slot array)","CONFIRMED"),
 ("0x7e82c0","FFX_Magic_CopyRuntimeTransformMatricesToGlobals","44 callers; copies runtime matrices/vectors into global transform state","CONFIRMED"),
 ("0x79a4c0","FFX_Kernel_ResolveTypedEntryByPackedId","29 callers; high-nibble dispatch to actor/cmd/monmagic/ability/save/model tables","CONFIRMED"),
 ("0x8725f0","FFX_FieldActor_GetScriptWorkerContext","28 callers; selects worker-ctx slot by actor type+index","CONFIRMED"),
 ("0x711260","FFX_MagicHost_BuildVfxTextureAndCommitDrawable","26 callers; texture binding dispatch + geometry validate + particle alloc/commit or release","CONFIRMED"),
 ("0x7110b0","FFX_MagicHost_BuildVfxTextureAndFinalize","same pipeline ending with LoadCharacterModelWithFlag8000","CONFIRMED"),
 ("0x7e78b0","FFX_Math_ComposeTransformExtended","24 callers; matrix compose/extend math","CONFIRMED"),
 ("0x640f60","FFX_Menu2D_GetNativeViewportSize1920x1080","22 callers; writes *a=1920,*b=1080","CONFIRMED"),
 ("0x785440","FFX_PartySlot_IsFlagBit0","20 callers; returns (unk_1132088+148*n)&1","CONFIRMED"),
 ("0x7e6610","FFX_Math_RandomJitterScale","17 callers; LCG-ish jitter (v*2-3)*a1","CONFIRMED"),
 ("0x7e7f20","FFX_Mem_Copy64Bytes","17 callers; 64B copy","CONFIRMED"),
 ("0x820640","FFX_Magic_GetRuntimeScratchBase","16 callers; returns scratch base + opt count write","CONFIRMED"),
 ("0x7e9760","FFX_Math_ComposeMatrixTranslateZYX","16 callers; matrix compose T*Rz*Ry*Rx order","CONFIRMED"),
 ("0x7e9940","FFX_Math_ComposeMatrixTranslateYZX","10 callers; matrix compose YZX order","CONFIRMED"),
 ("0x7e9670","FFX_Math_RotateMatrixX","13 callers; X-axis matrix rotation","CONFIRMED"),
 ("0x6fa3a0","FFX_Sound_QueueCommandAsync2Params","16 callers; forwards to QueueCommandAsync with 2 trailing zeros","CONFIRMED"),
 ("0x79f010","FFX_Btl_BuildActorStatusEffectDescriptorRows","13 callers; builds status/effect desc rows from actor +1542/+1544/+1558","CONFIRMED"),
 ("0x888e30","FFX_Input_GetPadContextBase","13 callers; returns &unk_1330248+256*(a2+a1)","CONFIRMED"),
 ("0x865390","FFX_FieldActor_AdvancePriorityNode","12 callers; advances priority node in field-actor state","CONFIRMED"),
 ("0x86e990","FFX_FieldActor_RequeuePriorityNode","10 callers; requeues priority node (dedupe/type3)","CONFIRMED"),
 ("0x7e7de0","FFX_Math_ComputeFixedAngle","10 callers; atan2-based fixed angle, scaled + 12-bit mask","CONFIRMED"),
 ("0x780d80","FFX_Battle_HasPlayerListBase","9 callers; bool over player/formation base availability","CONFIRMED"),
 ("0x7e2050","FFX_Field_ReadParenthesizedToken","reads '('/')' tokens, nested-paren tracking + trailing trim","CONFIRMED"),
 ("0x640590","FFX_Graphics_FinalizeSubsystems_SKS","'SKS: graphicFinalize begin/end/skip' strings; JobSchedule dtor path","CONFIRMED"),
 ("0x6f77e0","FFX_Flash_LoadGameplayOverlaySwf","loads freecamera/time_stop/enemy_0/chocobo .swf overlay paths","CONFIRMED"),
 ("0x869de0","FFX_FieldActor_SyncPositionBuffer","syncs pos buffer from Chr instance XYZ; move-type branches","CONFIRMED"),
 ("0x836d10","FFX_Mgrp_RegisterMseqRecords","'nb mgrp err','SG:Add MGRP' strings; mseq record registration","CONFIRMED"),
 ("0x783730","FFX_Battle_LoadMonsterFilesIntoMemoryChr","loads mon_data files for 8 slots into MemoryChr + registers ATEL scripts","CONFIRMED"),
 ("0x783e30","FFX_Battle_RequestFormationResourceById","requests res via walker vtable slot41/5, allocs unk_112CA60, async read cb 0x783E80","CONFIRMED"),
 ("0x79cd10","FFX_Mgrp_LoadBattleRegmotAsync","async loads battle regmot.mgrp","CONFIRMED"),
 ("0x837730","FFX_Mgrp_AttachBattleRegmotBufferToResourceSlot","attaches regmot buffer to resource slot; '[PC Battle Idling]', key 590823","CONFIRMED"),
 ("0x837790","FFX_Mgrp_IsBattleRegmotRegistered","FindRegistryEntry(2,0,0)!=0","CONFIRMED"),
 ("0x8377b0","FFX_Mgrp_IsBattleRegmotCachePresent","ResourceCache_GetSlotField3(2,590823)!=0","CONFIRMED"),
 ("0x7e3d80","FFX_Magic_Oef2ClutResetStub","empty stub guarded by arg; dbgPrintf only","CONFIRMED"),
 ("0x7dabf0","FFX_Field_DebugDisplayCameraPosXYZ","dbg-overlay prints X/Y/Z %.4f rows","CONFIRMED"),
 ("0x7d9870","FFX_Field_DebugDisplaySeparatorLines","dbg-overlay '------' rows","CONFIRMED"),
 ("0x7d3630","FFX_Camera_DebugDisplayCountAndAdd","dbg-overlay 'count'/'add' %.4f rows","CONFIRMED"),
 ("0xa182f0","FFX_Phyre_BindDeferredShadowParams","binds NormalDepthBuffer/ShadowTexture/DeferredShadowMatrix params","CONFIRMED"),
 ("0x6a3ca0","FFX_Phyre_BindMapMaterialMultiParamTextureLane","binds map material multi-lane texture params","CONFIRMED"),
 ("0x6a4ba0","FFX_Phyre_BindScreenVideoSamplerParams","binds TextureSampler/zCrct/zMatrix/ScreenShift/cameraFadeoutFactor","CONFIRMED"),
 ("0x6e84d0","FFX_Phyre_BindTextureSamplerColorScale","binds TextureSampler + default ColorScale vec4","CONFIRMED"),
 ("0x6b45f0","FFX_Phyre_BindTextureSamplerFromMaterialSlot","iterates material slots, binds TextureSampler via shader-param lookup","CONFIRMED"),
 ("0xaa3640","FFX_Mkv_ProcessTrackEntries","MKV track-entry walker (mislabel-fixed r2); body iterates track types","CONFIRMED"),
 ("0xa6cfb0","FFX_Phyre_TransformVertexBlock","vertex-block normalize/transform (mislabel-fixed r2)","CONFIRMED"),
 ("0x6429a0","FFX_Phyre_FlushLoadingCallbackList","locks/walks/invokes/clears loading-callback list (mislabel-fixed r2)","CONFIRMED"),
 ("0x643130","FFX_Distortion_SetFlag125","writes byte +125 of distortion singleton (mislabel-fixed r2)","CONFIRMED"),
 ("0x864180","FFX_Field_EventParser","ATEL VM interpreter main loop, 123-case switch, fetches via 0x869D00","CONFIRMED"),
 ("0x7e1e90","FFX_Field_ClassifyAndCopyCharStream","char-class state machine (unk_113FB38) copying classified chars","CONFIRMED"),
 ("0x7e2160","FFX_String_Length","strlen body","CONFIRMED"),
 ("0x840560","FFX_ResourceCache_RegisterDataPtr","finds free cache entry, stores type/id/data ptr, evict-on-overflow","CONFIRMED"),
 ("0x840dd0","FFX_ResourceCache_MarkEntryActive","finds entry by id+type, sets active byte +5=1","CONFIRMED"),
 ("0x8715f0","FFX_FieldActor_RequeueType1NodeAsTail","converts type1 node to type3 tail via RequeuePriorityNode","CONFIRMED"),
 ("0x86e920","FFX_FieldActor_QueuePriorityNode","builds priority-node descriptor, calls RequeuePriorityNode","CONFIRMED"),
 ("0x86eb70","FFX_FieldActor_QueuePriorityNodeIfAbsent","dedupe check on worker node list then requeue","CONFIRMED"),
 ("0x863510","FFX_Atel_CanSetActorCtxPair","ctx node-list membership guard; called twice by EventParser cases 119/120","CONFIRMED"),
 ("0x7c0de0","FFX_Atel_SetMovieGlobalFrameFloat","writes unk_1136FFC[0]; caller FFX_Atel_RenderMovieFrame","CONFIRMED"),
 ("0x870cd0","FFX_AtelOp_79_StoreActorWordSlot","op-0x79 handler: materializes 8-word actor slot vector, stores clamped word","CONFIRMED"),
 ("0x85b120","FFX_AtelOp_CheckCommandLearned","pops 3 ops, IsCommandLearnedPersistent gate, sets word@+14","CONFIRMED"),
 ("0x860aa0","FFX_AtelOp_EventStringDispatch","7-operand event/dialogue string dispatcher","CONFIRMED"),
 ("0x860740","FFX_AtelOp_FieldChoiceDispatch","field-choice operand dispatcher; pushes results via PushIntOperand","CONFIRMED"),
 ("0x8573c0","FFX_AtelOp_ProcessActorTurn","pops ops, resolves worker ctx, rotates actor (turn op)","CONFIRMED"),
 ("0x8671d0","FFX_AtelOp_QueueActorNodeType0","pops target/payload/priority, queues type0 actor node","CONFIRMED"),
 ("0x867510","FFX_AtelOp_QueueActorNodeType1","queues type1 actor node","CONFIRMED"),
 ("0x867370","FFX_AtelOp_QueueActorNodeType2","queues type2 actor node","CONFIRMED"),
 ("0x9dda40","DEAD_Phyre_GetPInputSourceMotionQuatWTypeName","6-byte getter returning 'PInputSourceMotionQuatW'","CONFIRMED"),
 ("0x9dda50","DEAD_Phyre_GetPInputSourceMotionQuatXTypeName","6-byte getter returning 'PInputSourceMotionQuatX'","CONFIRMED"),
 ("0x9dda60","DEAD_Phyre_GetPInputSourceMotionQuatYTypeName","6-byte getter returning 'PInputSourceMotionQuatY'","CONFIRMED"),
 ("0x9dda70","DEAD_Phyre_GetPInputSourceMotionQuatZTypeName","6-byte getter returning 'PInputSourceMotionQuatZ'","CONFIRMED"),
 ("0x6b8960","DEAD_FFX_FieldDebug_ModelCycleInputHandlerA","grid00-gated model-cycle input handler, pad flags + input mapper","CONFIRMED"),
 ("0x6b8b60","DEAD_FFX_FieldDebug_ModelCycleInputHandlerB","grid00 substring gate + pad/input reads","CONFIRMED"),
]

FIX = [
 ("0x71b980","FFX_AudioSdStream_ConvertPcmToIeeeFloat_structural","FFX_MagicHost_BuildPppDrawableRecord","body+callers = PPP drawable/color record applicator under MagicHost; no audio/PCM","MISLABEL"),
 ("0x7b4b80","FFX_Battle_BuildAbilityUsedLog_structural","FFX_Battle_ActorPropertyWriteDispatch","large write-side actor-property dispatcher (100+ cases), not a log builder","MISLABEL"),
 ("0x820970","FFX_Field_DrawBgAnimAfterSemiTransparent_structural","FFX_Field_FullSceneReset","full field-scene reinit: VU/VIF/GS resets + subsystem setup; not a bg-anim draw","MISLABEL"),
 ("0x890ee0","FFX_Btl_AnimatedBgTextureStamp_structural","FFX_Battle_FormationSubmenuBgSequence","multi-stage animated bg/menu state machine (bauro/bauro2); not a texture stamp","MISLABEL"),
 ("0x9055c0","FFX_Debug_DisplaySettingsProgrammableKeyHandler_structural","FFX_Menu2D_RenderNumberRightAligned","digit-count + measure + RenderNumberText; no key handling; callers BtlUI/SphereGrid/EscMenu","MISLABEL"),
 ("0x654fd0","FFX_BtlUI_DrawHudCursorRing_structural","FFX_BtlUI_CursorRingVector_Init","24-byte-element vector init (alloc begin/end); sole caller FFX_BtlUI_SetupCursorRing","MISLABEL"),
 ("0x7cf8a0","FFX_Menu2D_MenuDefDataFieldValue_14b_structural","FFX_Menu2D_MenuDefDebugAlloc","'malloc %10d' debug trace + alloc body; called by Menu2D select paths","MISLABEL"),
 ("0x7cf820","FFX_Menu2D_MenuDefDataFieldValue_13w_structural","FFX_Menu2D_MenuDefDebugFree","'free   %10d' debug trace + free body","MISLABEL"),
 ("0x83c610","FFX_Debug_FieldActionListDisplay_structural","FFX_Debug_FieldActionListDisplay_Stub","empty body (single ';'); shared debug-hook stub called from Chr/Mgrp alloc paths","MISLABEL"),
 ("0x7c04c0","FFX_Field_DummyNop_structural","FFX_Field_SetVfxParticleSlotCounts","writes g_vfxParticleSlotCount_512_3/_416_1; not a nop","MISLABEL"),
 ("0x8bf020","FFX_Atel_Movie_FuncB087_FLOATRET_structural","FFX_Menu_StateReset","not in ATEL funcspace table; lives in menu-state cb table @0xC5A090 slot2 (siblings StateValidate/Rollback/Snapshot); clears globals + Global accessor","MISLABEL"),
 ("0x486820","DEAD_Phyre_RegisterPMeshSegmentDescriptor_structural","DEAD_Phyre_GetPMeshSegmentTypeName","6-byte getter returning 'PMeshSegment' string; not a registrar","MISLABEL"),
 ("0x488a10","DEAD_Phyre_RegisterPMeshSegmentDataMembers_structural","DEAD_Phyre_GetPMeshSegmentTypeName_2","6-byte getter returning 'PMeshSegment' string; not a registrar","MISLABEL"),
 ("0x6359a0","DEAD_FFX_Menu2D_PrepassTransformAndTexture_structural","DEAD_FFX_LazyInitResourcePool_CCCA90","lazy-init singleton: allocs 0x208 ResourcePool into unk_CCCA90; no prepass/texture work","MISLABEL"),
 ("0x7b8dc0","FFX_Atel_Camera_PopActorScopedOperand_A_structural","FFX_Atel_Camera_CamScrWait_CALL","Camera funcspace [0x7B].CALL; fahrenheit cam[123]='camScrWait'","VALID"),
 ("0x7b8d80","FFX_Atel_Camera_PopActorScopedOperand_B_structural","FFX_Atel_Camera_CamDrawWait_CALL","Camera funcspace [0x7C].CALL; fahrenheit cam[124]='camDrawWait'","VALID"),
]

plan = json.load(open(f'{OUT}/rename_plan_atel.json'))
full = [list(r) for r in plan]
missing = []
for a, new, ev, conf in LIFT:
    old = census.get(a)
    if not old:
        missing.append((a, new)); continue
    assert old == new + '_structural', (a, old, new)
    full.append([a, old, new, ev, 'LIFT_' + conf])
for a, old, new, ev, conf in FIX:
    assert census.get(a) == old, (a, census.get(a), old)
    full.append([a, old, new, ev, 'FIX_' + conf])

print('missing:', missing)
print('total renames:', len(full))
json.dump(full, open(f'{OUT}/rename_plan.json', 'w'), indent=1)
import collections
print(collections.Counter(k for *_, k in full))
