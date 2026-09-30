#!/usr/bin/env python3
"""build_plan.py — classify top-150 residual dummies into renames+comments."""
import json, struct
W = '/home/wanderson/Documents/ffx-editor-main/work/_data_r2/'
top = json.load(open(W + 'top150_vals.json'))
ctx = json.load(open(W + 'ctx_decompile.json'))

# ---------- helpers ----------
def fname(v):
    """short value token for kFlt_/kDbl_ names."""
    if isinstance(v, float):
        if v != v: return 'NaN'
        if v == int(v) and abs(v) < 1e15:
            s = str(int(v))
        else:
            s = ('%g' % v).replace('-', 'm').replace('+', '').replace('.', 'p').replace('e-0', 'e').replace('e-', 'e')
        return s
    return str(v)

SPECIAL = {
    3.4028234663852886e+38: 'Max', -3.4028234663852886e+38: 'NegMax',
    1.1920928955078125e-07: 'Epsilon', 0.01745329238474369: 'DegToRad',
    6.283184051513672: 'TwoPi', 4294967296.0: '2Pow32',
    0.001953125: 'Inv512', 0.0009765625: 'Inv1024', 0.125: '0p125',
}
def fp_name(name, v):
    pref = 'kFlt' if name.startswith('flt') else 'kDbl' if name.startswith('dbl') else 'kQword'
    tok = SPECIAL.get(v, fname(v))
    return f'{pref}_{tok}'

# ---------- curated semantic names (evidence from ctx_decompile + ctx2) ----------
CUR = {
 'word_CA7400':  ('g_InitFlags_PMeshInstanceRegFields','VALID',
   'multi-bit static-init guard bitmask for ~32 function-local statics in Phyre_PMeshInstance_registerFields (test/or bits 1..0x80000000)'),
 'word_CC0784':  ('g_InitFlags_RigidBodyRegCD','VALID','static-init guard bitmask for Phyre_RigidBody_RegisterClassDescriptors locals'),
 'word_CAA8A4':  ('g_InitFlags_PAnimationClip','VALID','static-init guard bitmask for PhyrePAnimationClip_Initialize locals'),
 'word_C913F0':  ('g_InitFlags_CDMForMemoryBlock','VALID','static-init guard for Phyre_PClassDataMember_InitForMemoryBlock'),
 'word_CA67A8':  ('g_InitFlags_PEffectReg','VALID','static-init guard for PhyrePEffect_RegisterDescriptor'),
 'word_CBCA48':  ('g_InitFlags_PDynamicGeometryCD','VALID','static-init guard for Phyre_PDynamicGeometry_ExpandedClassDescriptor'),
 'dword_C973F8': ('g_InitFlags_SerializationHeaderCD','VALID','static-init guard for Phyre_SerializationHeader_RegisterClassDescriptor'),
 'dword_C9944C': ('g_InitFlags_MeshCD','VALID','static-init guard for Phyre_Mesh_RegisterClassDescriptor'),
 'dword_C94108': ('g_InitFlags_CDMForAsset','VALID','static-init guard for Phyre_PClassDataMember_InitForAsset'),
 'dword_C94A1C': ('g_InitFlags_QuatCD','VALID','static-init guard bitmask (bits 1,2,..) in Phyre_Quat_RegisterClassDescriptor'),
 'dword_C948A4': ('g_InitFlags_Vector4CD','VALID','static-init guard for Phyre_Vector4_RegisterClassDescriptor'),
 'dword_C9BB58': ('g_InitFlags_ShaderParameterCD','VALID','static-init guard for Phyre_ShaderParameter_RegisterClassDescriptor'),
 'dword_C9CFFC': ('g_InitFlags_VertexElementCD','VALID','static-init guard for Phyre_VertexElement_RegisterClassDescriptor'),
 'dword_CA35F0': ('g_InitFlags_CDMForTexture','VALID','static-init guard for Phyre_PClassDataMember_InitForTexture'),
 'dword_C91CD4': ('g_InitFlags_CDMForComponent','VALID','static-init guard for Phyre_PClassDataMember_InitForComponent'),
 'dword_C9214C': ('g_InitFlags_TransformCD','VALID','static-init guard for Phyre_Transform_RegisterClassDescriptor'),
 'dword_C94754': ('g_InitFlags_Point3CD','VALID','static-init guard for Phyre_Point3_RegisterClassDescriptor'),
 'dword_C94604': ('g_InitFlags_Vector3CD','VALID','static-init guard for Phyre_Vector3_RegisterClassDescriptor'),
 'dword_C99020': ('g_InitFlags_PIndexBufferCD','VALID','static-init guard for Phyre_PIndexBuffer_ClassDescriptor'),
 'dword_CA17D4': ('g_InitFlags_ShaderProgramBindingsCD','VALID','static-init guard for Phyre_ShaderProgramBindings_RegisterClassDescriptor'),
 'dword_CA2610': ('g_InitFlags_ShaderPassArrayCD','VALID','static-init guard for Phyre_ShaderPassArray_RegisterClassDescriptor'),
 'dword_C987F0': ('g_InitFlags_PVertexStreamCD','VALID','static-init guard for Phyre_PGeometry_PVertexStream_ClassDescriptor'),
 'dword_C98A08': ('g_InitFlags_PVertexStreamArrayCD','VALID','static-init guard for Phyre_PGeometry_PVertexStreamArray_ClassDescriptor'),
 'dword_C98DD8': ('g_InitFlags_CDMForGeometryVertexBuffer','VALID','static-init guard for Phyre_PClassDataMember_InitForGeometryVertexBuffer'),
 'dword_C999B0': ('g_InitFlags_MaterialArrayCD','VALID','static-init guard for Phyre_MaterialArray_RegisterClassDescriptor'),
 'dword_C99D4C': ('g_InitFlags_PSkinBoneCD','VALID','static-init guard for Phyre_PSkinBone_ClassDescriptor'),
 'dword_C9A890': ('g_InitFlags_PMeshElementGroupCD','VALID','static-init guard for Phyre_PGeometry_PMeshElementGroup_ClassDescriptor'),
 'dword_C9CED4': ('g_InitFlags_PShaderProgramCD','VALID','static-init guard for Phyre_Rendering_PShaderProgram_ClassDescriptor'),
 # singleton storage / static slots
 'dword_CA80E8': ('g_CDGuard_PModNetInstArray_A80E8','VALID','guard+static store: ctor Phyre_PArray_PModifierNetworkInstance CD at +8; returned by *_GetSingleton_*'),
 'byte_C9AD1C':  ('g_CDGuard_PUByteArray','VALID','guard byte + static store: PUByteArray_ClassDescriptor_ctor at +44; returned by PShape_ClassDescriptor_GetSingleton*'),
 'dword_C91C10': ('g_CDSlot_PCluster','VALID','static CD store: DEAD_PCluster_GetStaticSlot_C91C18 returns &dword[2]'),
 'dword_C93F90': ('g_CDSlot_PAssetRef','VALID','static CD store: DEAD_PAssetRef_GetStaticSlot_C93F98 returns &dword[2]'),
 'dword_C9434C': ('g_CDSlot_PRandomGenerator','VALID','static store: DEAD_PRandomGenerator_GetStaticSlot_C94350 returns &dword[1]'),
 'dword_C90E2C': ('g_CDSlot_C90E30','VALID','static store: DEAD_GetStaticSlot_C90E30 returns &dword[1] (class unidentified)'),
 'dword_CAED50': ('g_CDSlot_Size16','VALID','static store: DEAD_Phyre_GetSize16Ptr* returns &dword[2]'),
 'dword_CAE7B0': ('g_CDSlot_PCaller21','VALID','static store: DEAD_Phyre_PCaller_GetSize21Ptr* returns &dword[2]'),
 'dword_CB0AB8': ('g_CDSlot_PAttachableComponent41','VALID','static store: DEAD_Phyre_PAttachableComponent_GetSize41Ptr* returns &dword[2]'),
 'dword_CAFB68': ('g_CDSlot_PTimerComponent60','VALID','static store: DEAD_Phyre_PTimerComponent_GetSize60Ptr* returns &dword[2]'),
 'dword_CA9770': ('g_CDSlot_PAnimationDescriptor','VALID','static store: DEAD_Phyre_AnimationDescriptor_GetSizePtr* returns &dword[2]'),
 'dword_1A855B0':('g_CDSlot_PGameSettings','VALID','static store: DEAD_Phyre_PGameSettings_GetSize* returns &dword[2]'),
 'dword_C9B048': ('g_CDGuard_PLightType','VALID','static-init guard (test&1/or 1) for PLightType descriptor singleton'),
 'dword_C9B014': ('g_CDGuard_PLightType_b','VALID','second guard for PLightType singleton cluster (PLightType_GetSingleton_B/_C/SemanticDescriptorInit)'),
 'dword_CA4590': ('g_CDGuard_PShadowCasterType','VALID','static-init guard (test&1/or 1) for PShadowCasterType descriptor singleton'),
 'dword_CA455C': ('g_CDGuard_PShadowCasterType_b','VALID','second guard for PShadowCasterType singleton cluster'),
 'dword_C91658': ('g_CDGuard_PArrayU8_b','VALID','guard bit1 (&=~2 clear) adjacent to g_CDGuard_PArrayU8 @C9165C; PClassDescriptorConcrete_PArrayU8_GetClassPtr'),
 'dword_C94EFC': ('g_InitFlag_PTimerFreq','VALID','static-init guard (test&1/or 1) for Phyre_Timer_InitFrequencySingleton'),
 'dword_C94EE0': ('g_InitFlag_PTimerFreq_b','VALID','paired init flag for timer-frequency singleton (also touched by PMatrix4x3 CD GetSingleton/Cluster_ReadFieldsFromStream)'),
 'dword_CCC868': ('g_EscMenuCtxPtr','SUSPECTED','context ptr returned by DEAD_FFX_AsyncQ_GetContextEx; also used by FFEscMenu_* (DestroySingleton/DispatchTriggeredAction/OnConfirmKeyCallback)'),
 'dword_CBD9B0': ('g_AnimSchedCurCtx','VALID','AnimationScheduler current ctx: [2]=this scheduler, [3]=cur index; set/cleared by Phyre_AnimationScheduler_Execute/Process'),
 'dword_C940C4': ('g_PhyreEventObj','SUSPECTED','event object: LOBYTE flag tested then Phyre_Event_Reset(dword_C940C4); also Event_Register/Atomic_DecrementAndExchange'),
 'dword_CA2F04': ('g_FileDirListHead','VALID','Phyre file-directory list head: *(a1+4)=head; head=a1 insert pattern in Phyre_File_AddEntry; GetDirectoryListHead returns it'),
 'dword_CA2F08': ('g_FileDirEntryTbl','VALID','dword array indexed by entry->id in Phyre_File_RemoveDirectoryEntry (entry_tbl[id]=0)'),
 'dword_CA310C': ('g_PixelFmtDesc_RGBA8','VALID','static PPixelFormatDesc: Phyre_PixelFormatDesc_Init(this,"RGBA8",11,504,0,28,28,28,28) in PhyreInit_TextureFormat_RGBA8'),
 'dword_CA34CC': ('g_ResStreamHandlerPtr','SUSPECTED','handler ptr compared against *a1 in DEAD_Phyre_resource_streamHandler; also ref by PCD_NullThunk/TextureFormat inits'),
 'dword_C59564': ('g_MenuItemListMax','VALID','item-count limit: ItemListInit sets = a1!=1?18:4; passed to FFX_Menu_EditBoxCharDelete as bound'),
 'byte_C0A09C':  ('g_PostFxRegistered','VALID','one-shot flag: Phyre_PostProcessing_RegisterAllEffects and PApplication_Constructor test !byte before registering'),
 'byte_B6E681':  ('kLuaLexCtype','VALID','Lua lexer ctype table base: byte_B6E681[*p_Val]&2 digit-class test in LuaLex_readDecimalEscape/readHexEscape'),
 'word_18DED08': ('g_BtlHudFieldFlags','VALID','flags dword: bit3 toggled by FFX_BtlUI_HudTextureOverride; copied by FFX_Battle_SnapshotFieldLightingState'),
 'word_C53414':  ('g_FieldDbgWordTbl','SUSPECTED','word array indexed [4*idx] by FFX_FieldDebug_ActorFieldList/StatusList/AiScriptOpcode* debug lists'),
 'dword_13009D0':('g_MgrpMseqRecordPool','VALID','496-dword pool: FFX_Mgrp_AddMseqRecord bounds-checks <&dword[496], stores a2 at [v4]; used by BindMseqToActiveInstance/Clear*'),
 'qword_113FCF0':('g_XfRuntimeMtxBuf','VALID','dst buffer of FFX_Magic_CopyRuntimeTransformMatricesToGlobals; consumed by MagicVm_SetupCoordTransform/DrawGeometrySetup'),
 'off_C34194':   ('g_PTreeSentinel_C34194','CONFIRMED','PTree sentinel node (PTree_Node_InitSelfRef self-ptrs x4); removed by PhyreInit_C34194_destructor; also ClusterHandle_TreeCleanup'),
 'off_C24F0C':   ('g_PTreeSentinel_C24F0C','CONFIRMED','PTree sentinel node (PTree_Node_InitSelfRef) for PClusterGlobalList; removed by PhyreInit_C24F0C_destructor'),
 'dword_C9424C': ('g_PhyreTimerTreeRoot','VALID','self-referential tree/list root init in Phyre_Timer_TreeInit (4x self ptrs); shared by Event_SystemSingleton/TreeNodeRemove'),
 # SIMD/video constants
 'xmmword_25D7450':('kSimd_4000x8','CONFIRMED','16B = 8x u16 0x4000 (16384) bias/scale for PhyreVideo filters + MaddubsFilter MMX/SSE'),
 'xmmword_25D73F0':('kSimd_4000x8_b','CONFIRMED','16B = 8x u16 0x4000; used by PhyreImage_BilinearH_*_SSE/BilinearScale'),
 'xmmword_25D7010':('kSimd_80x16','CONFIRMED','16B = 16x 0x80 (128) unsigned bias for FFX_Video chroma upsample/deblock filters'),
 'xmmword_25D70B0':('kSimd_Zero','CONFIRMED','16B zero constant for FFX_Video_* filter kernels'),
 'qword_25D70A0': ('kQword_0040x4','VALID','8B = 4x u16 0x0040 (64) coeff for FFX_Video_SubPixel_8tap filters'),
}

plan = []
for r in top:
    nm = r['name']
    if nm in CUR:
        new, conf, cmt = CUR[nm]
        plan.append({'old': nm, 'addr': r['addr'], 'new': new, 'conf': conf,
                     'refs': r['code_refs'], 'comment': cmt + ' [data-r2]'})
        continue
    if nm in ('flt_C8F7C0','dword_13009D0'):
        plan.append({'old': nm, 'addr': r['addr'], 'new': None, 'conf': 'SKIP-RENAMED',
                     'refs': r['code_refs'], 'comment': 'already named (prior lane)'})
        continue
    pref = nm.split('_')[0]
    if pref in ('flt','dbl'):
        v = r.get('val')
        new = fp_name(nm, v)
        fns = '; '.join(f for f in r['funcs'] if f != '?')[:150]
        plan.append({'old': nm, 'addr': r['addr'], 'new': new, 'conf': 'CONFIRMED',
                     'refs': r['code_refs'],
                     'comment': f"{pref}32/64 pooled const = {v}; {r['code_refs']} code refs incl {fns} [data-r2]"})
        continue
    if pref == 'qword':
        v = r.get('val')
        plan.append({'old': nm, 'addr': r['addr'], 'new': f'kQword_{nm.split("_")[1]}', 'conf':'SUSPECTED',
                     'refs': r['code_refs'],
                     'comment': f'qword const = {v} (0x{v:016x}); refs: {"; ".join(r["funcs"][:4])} [data-r2]'})
        continue
    plan.append({'old': nm, 'addr': r['addr'], 'new': None, 'conf': 'UNRESOLVED',
                 'refs': r['code_refs'], 'comment': 'needs manual decode', 'funcs': r['funcs']})

# fix name collisions among generated names
seen = {}
for p in plan:
    if not p['new']: continue
    n = p['new']
    if n in seen:
        p['new'] = n + '_b'
        if p['new'] in seen:
            p['new'] = n + '_' + p['addr'].split('x')[1].upper()
    seen[p['new']] = p['addr']

json.dump(plan, open(W + 'rename_plan.json','w'), indent=1)
import collections
print(collections.Counter(p['conf'] for p in plan))
print('unresolved:', [p['old'] for p in plan if p['conf']=='UNRESOLVED'])
