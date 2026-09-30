#!/usr/bin/env python3
"""Build the rename table for top-200 unnamed data globals (leva 8 census).

Categories:
  K_*   : .rdata/.rodata numeric constants (decode init bytes)
  XF_*  : C8F7B0..C8F98F 'transform frame' BSS work area
  GD_*  : Phyre PClassDescriptorConcrete<T> static-init guard dwords
  SP_*  : special singletons/state (manual names from accessor evidence)
"""
import json, re, struct, sys

cr = json.load(open('code_refs.json'))
defs = json.load(open('data_defs.json'))['defs']
ev = {t['name']: t for t in json.load(open('evidence.json'))['targets']}

TYPE_PAT = re.compile(
    r'(?:DEAD_)?(?:Phyre_)?(?:PClassDescriptorConcrete_|PClassDesc_)?'
    r'([A-Za-z0-9_]+?)_(?:ctorClassDesc|GetSingleton|GetGlobalSingleton|'
    r'GetTotalSize|Traverse|Register|Init|ctor|dtor|GetClass|'
    r'GetSingletonCopy|TraverseGetSize|TraverseNoFlag|TraverseWithFlag|'
    r'SetFlag|GetClassPtr|static_Init|vec_|ClassDescriptor|RegClass|'
    r'CalcMemberSize|CalcMemberSize_Sub|Copy|ClassDescGetSize|'
    r'ClassDescriptorSingleton|Singleton|GetSize|d)')
REG_PAT = re.compile(r'Register(?:Class)?Descriptors?|_Register(P[A-Za-z0-9_]+?)(?:Class)?Descriptor')

renames = []   # (old, new, confidence, comment)
skips = []     # (name, reason)

# ---- hand-curated special globals ----
SPECIAL = {
    'unk_112A034': ('g_AtelMovieObjTable', 'CONFIRMED',
                    'ptr to array of 0x1D8-stride ATEL Movie objects; 173 movie-op fns index 472*i + base + 0x9A (name str ref via FFX_Menu_ResolveNameWithFallback)'),
    'unk_187168C': ('g_MenuPersistWorkPtr', 'SUSPECTED',
                    'written by FFX_Save_ReadPersistData (=a1); read by FFX_TextLayout_RenderFormattedString/RenderStringWithColor + Menu2D draw; persistent menu/save work struct ptr'),
    'unk_1A858B4': ('g_IggyGDrawState', 'CONFIRMED',
                    'Iggy GDraw subsystem state array (dword vec); AllocBuffers/CreatePixelShader/ReleaseResources index [614]/[618]/[624]'),
    'unk_C901A8': ('g_PhyreEngineObjList', 'SUSPECTED',
                   'list head of registered Phyre engine objects: node.vtbl call [eax+4] then esi=[esi+4]; Phyre_Engine_Init/GetVersion/Timer_Shutdown/Stream_Seek'),
    'unk_C9628C': ('g_PhyreResSysInitFlag', 'SUSPECTED',
                   'bit0 set-once init guard shared by 86 Phyre resource/Shader/PostProcessing/Cluster singleton inits'),
    'dword_C907F4': ('g_PhyreCDMAnnotTypeId', 'SUSPECTED',
                     'annotation type id passed to PAnnotation_Init + PAnnotationList_FindByID by ~75 ClassDescriptorInit fns'),
    'unk_2322790': ('g_FileIoReadyFlag', 'SUSPECTED',
                    'set =1 in FFX_Pmcom_InitProtocolDriver; read by FFX_File_GetFileSize/ReadToAllocatedBuffer'),
    'unk_12F4108': ('g_SpuCmdQueueInitFlag', 'VALID',
                    'bit0-tested in SoundSpuCmd_PushNoop/PushOpcode21AndFlush; init guard for SPU cmd queue'),
    'unk_12F4DC0': ('g_SpuCmdQueueEnd', 'VALID',
                    'address used as end bound: g_FFX_SoundSpuCmdQueueCursor+32 > &unk_12F4DC0 in SoundSpuDma_InitChannel'),
    'unk_1865AFC': ('g_MenuListDrawCtx', 'VALID',
                    'menu list draw context ptr array; MenuListDraw zeroes **(WORD**)(ctx[0]+16/20/24) text buffers'),
    'unk_18676B0': ('g_MenuListItemTbl', 'SUSPECTED',
                    'indexed table *(&unk_18676B0+i) read by Menu_ListItemInitHeight + Save_TableIterate/SlotValidate'),
    'unk_113E258': ('g_Menu2DStartData', 'VALID',
                    'Menu2D start-data model struct ptr; [7]=count [12]=font table offset (SelectFontSize)'),
    'unk_113E25C': ('g_Menu2DParseCursor', 'VALID',
                    'Menu2D_ParseMenuDefData stores v17 then parses float triples/int fields into it; init by InitStartDataSystem'),
    'unk_1328A30': ('g_FieldDbgPcSlot', 'SUSPECTED',
                    'selector fed to FFX_Field_GetScriptStateMachineArray by FieldService_DbgPrintPc* debug fns'),
    'unk_25D5F90': ('g_SplineEdCurNode', 'VALID',
                    'current spline node index: indexes unk_25D5F44/25D5F54/flt_25D5F4C arrays in FFX_Debug_SplineEditor'),
    'unk_22FB534': ('g_PPostProcResetFlag0', 'VALID',
                    'cleared by PhyreCleanup + PPostProcessing_ResetFlag534_* family'),
    'unk_22FB538': ('g_PPostProcResetFlag1', 'VALID',
                    'cleared by PhyreCleanup + PPostProcessing_ResetFlag538_* family'),
    'unk_FF0000': ('kMask_FF0000', 'CONFIRMED',
                   'address used AS the constant 0xFF0000 byte mask in Engine_ByteSwap64/Endian_SwapFloat (not data)'),
    'byte_25D09C2': ('g_MenuSaveStateArr', 'SUSPECTED',
                     'byte array [ecx] + word fields +0x10/+0x12/+0x14 written by FFX_Save_BufferWrite4; Menu_StateMachineDriverFull reads'),
    'byte_25D60B6': ('g_VpxCoeffProbBuf', 'SUSPECTED',
                     'buffer filled by FFX_VpxDecoder_InitCoeffProbs; also passed offset in Debug_SplineEditor'),
    'unk_C8F540': ('g_ModelBrowserParamA', 'VALID',
                   'Debug_ModelBrowser_Store*Param fns write; copied into dword_C8F968 transform slot'),
    'unk_C8F544': ('g_ModelBrowserParamB', 'VALID',
                   'paired with g_ModelBrowserParamA; copied into FFX_Field_Global_C0A010_9 slot'),
    'unk_C8F788': ('g_VecLenWork', 'SUSPECTED',
                   'float work slot shared by Vec4_NormalizeMagnitude/Vec4LengthWithGlobal/FieldMap_ApplySpringForce'),
    'unk_C8F900': ('g_XfFrm_TrailW', 'VALID',
                   'KeShpTail3/KeShpTail3X_RenderTrail write; inside transform-frame block (adjacent g_XfFrm_TrailXY/TrailScaleY)'),
    'dword_C92418': ('g_CDGuard_PCamera', 'VALID',
                     'static-init guard for PCamera class registration (PCamera_RegClass: test al,1 / or eax,1 / |=2)'),
    'unk_186A1F8': ('g_Menu2DObjAllocState', 'SUSPECTED',
                    'state touched by FFX_Menu2D_ObjectAlloc_16B + menu row/text pool fns'),
    'unk_18714F0': ('g_MenuTextPoolCursor', 'SUSPECTED',
                    'cursor/idx used by FFX_Menu_AdvancePoolAndDrawRow/DrawText1/DrawText2 family'),
    'dword_CA2A50': ('g_CDGuard_PSamplerState', 'VALID',
                     'static-init guard in PSamplerState_RegClass (test al,1 / or eax,1)'),
    'dword_C9B078': ('g_CDGuard_PLight', 'VALID',
                     'static-init guard in PLight_RegClass'),
    'dword_C90F2C': ('g_DbgErrStaticGuard', 'VALID',
                     'MSVC static-local init guard inside Phyre_Debug_Error (guards static obj at C90E2C)'),
    'qword_25D76A0': ('kByteBias80_x8', 'CONFIRMED',
                      '8x 0x80 byte lanes = +128 per-lane rounding bias; PhyreVideo_InterpolateHalfPel/Quantize SIMD'),
    'dbl_B0DBA0': ('kDbl_Zero', 'VALID',
                   '.rdata double constant 0.0 used by Phyre_spline_eval/Skinning_ComputeLightIntensitySum/Audio_UpdateVolumeFade'),
}

# ---- C8Fxxx transform-frame block map ----
XF = {
    'qword_C8F7B0': 'g_XfFrm_ScaleVec_xy', 'unk_C8F7B8': 'g_XfFrm_ScaleVec_z',
    'unk_C8F7BC': 'g_XfFrm_ScaleVec_w',
    'flt_C8F794': 'FFX_Render_TransformConstants_1', 'flt_C8F798': 'FFX_Render_TransformConstants_2',
    'flt_C8F79C': 'FFX_Render_TransformConstants_3',
    'unk_C8F7A0': 'g_XfFrm_PosScaled_x', 'unk_C8F7A4': 'g_XfFrm_PosScaled_y',
    'unk_C8F7A8': 'g_XfFrm_PosScaled_z', 'unk_C8F7AC': 'g_XfFrm_PosScaled_w',
    'flt_C8F7C0': 'g_XfFrm_f070', 'unk_C8F7C4': 'g_XfFrm_f074',
    'unk_C8F7C8': 'g_XfFrm_f078', 'unk_C8F7CC': 'g_XfFrm_f07C',
    'unk_C8F7D0': 'g_XfFrm_TranspVec_x', 'unk_C8F7D4': 'g_XfFrm_TranspVec_y',
    'unk_C8F7D8': 'g_XfFrm_TranspVec_z',
    'unk_C8F7E0': 'g_XfFrm_AuxVec_0', 'unk_C8F7E4': 'g_XfFrm_AuxVec_1',
    'unk_C8F7E8': 'g_XfFrm_AuxVec_2', 'unk_C8F7EC': 'g_XfFrm_AuxVec_3',
    'flt_C8F7F0': 'g_XfFrm_AuxVec2_0', 'unk_C8F7F4': 'g_XfFrm_AuxVec2_1',
    'unk_C8F7F8': 'g_XfFrm_AuxVec2_2', 'unk_C8F7FC': 'g_XfFrm_AuxVec2_3',
    'unk_C8F800': 'g_XfFrm_AuxVec3_0', 'unk_C8F804': 'g_XfFrm_AuxVec3_1',
    'unk_C8F808': 'g_XfFrm_AuxVec3_2',
    'unk_C8F810': 'g_XfFrm_Wk810', 'unk_C8F814': 'g_XfFrm_Wk814',
    'unk_C8F818': 'g_XfFrm_Wk818',
    'dword_C8F820': 'g_XfFrm_f060', 'dword_C8F824': 'g_XfFrm_f064',
    'dword_C8F828': 'g_XfFrm_f068', 'dword_C8F82C': 'g_XfFrm_f06C',
    'dword_C8F834': 'g_XfFrm_ScaleTmpA', 'dword_C8F838': 'g_XfFrm_ScaleTmpB',
    'dword_C8F840': 'g_XfFrm_f080', 'dword_C8F844': 'g_XfFrm_f084',
    'dword_C8F848': 'g_XfFrm_f088', 'dword_C8F84C': 'g_XfFrm_f08C',
    'dword_C8F858': 'g_XfFrm_EulerTmp',
    'unk_C8F870': 'g_XfFrm_f040', 'unk_C8F874': 'g_XfFrm_f044',
    'unk_C8F878': 'g_XfFrm_f048', 'unk_C8F87C': 'g_XfFrm_f04C',
    'unk_C8F884': 'g_XfFrm_Wk884', 'unk_C8F890': 'g_XfFrm_Scale45_x',
    'unk_C8F894': 'g_XfFrm_Scale45_y', 'qword_C8F898': 'g_XfFrm_Const16',
    'unk_C8F8A0': 'g_XfFrm_Wk8A0', 'unk_C8F8A4': 'g_XfFrm_Wk8A4',
    'unk_C8F8B4': 'g_XfFrm_Wk8B4',
    'unk_C8F8D0': 'g_XfFrm_f050', 'unk_C8F8D4': 'g_XfFrm_f054',
    'unk_C8F8D8': 'g_XfFrm_f058', 'unk_C8F8DC': 'g_XfFrm_f05C',
    'unk_C8F8E0': 'g_XfFrm_f030', 'unk_C8F8E4': 'g_XfFrm_f034',
    'unk_C8F8E8': 'g_XfFrm_f038', 'unk_C8F8EC': 'g_XfFrm_f03C',
    'qword_C8F8F0': 'g_XfFrm_TrailXY',
    'unk_C8F904': 'g_XfFrm_TrailScaleY', 'unk_C8F908': 'g_XfFrm_TrailScaleZ',
    'unk_C8F910': 'g_XfFrm_Inv1024', 'unk_C8F914': 'g_XfFrm_InvKVec_1',
    'unk_C8F918': 'g_XfFrm_InvKVec_2', 'unk_C8F91C': 'g_XfFrm_InvKVec_3',
    'flt_C8F920': 'g_XfFrm_f000', 'unk_C8F924': 'g_XfFrm_f004',
    'unk_C8F928': 'g_XfFrm_f008', 'unk_C8F92C': 'g_XfFrm_f00C',
    'qword_C8F938': 'g_XfFrm_f010', 'dword_C8F948': 'g_XfFrm_f018',
    'qword_C8F960': 'g_XfFrm_f020', 'dword_C8F968': 'g_XfFrm_f028',
    'dword_C8F958': 'g_XfFrm_W958', 'dword_C8F95C': 'g_XfFrm_W95C',
    'dword_C8F970': 'g_XfScratchVecB_x', 'dword_C8F974': 'g_XfScratchVecB_y',
    'dword_C8F978': 'g_XfScratchVecB_z', 'dword_C8F97C': 'g_XfScratchVecB_w',
    'qword_C8F988': 'g_XfScratchVecA_zw',
}
XF_COMMENT = ('member of global transform-frame work area C8F7B0-C8F98F; '
              'staged by FFX_MagicHost_LoadTransformFrameToGlobals (src+%s) '
              'and consumed by MagicHost_ApplyWeightedTransform / Pmcom / BattleModel fns')

# ---- constant value decoding ----
def const_name(name, hexbytes):
    try:
        b = bytes(int(x, 16) for x in hexbytes.split())
    except Exception:
        return None, None
    if name.startswith('flt_') and len(b) >= 4:
        v = struct.unpack('<f', b[:4])[0]
        if v != v or v == 0:
            return None, None
        return 'kFlt', v
    if name.startswith(('dbl_', 'qword_')) and len(b) >= 8:
        v = struct.unpack('<d', b[:8])[0]
        if v != v or v == 0:
            return None, None
        return 'kDbl', v
    if name.startswith('xmmword_') and len(b) >= 16:
        if b == b'\x00\x00\x00\x80' * 4:
            return 'kXm', 'sign-mask x4 (0x80000000 f32 lanes)'
        return None, None
    return None, None


skx = json.load(open('skips_xrefs.json')) if __import__('os').path.exists('skips_xrefs.json') else {}


def guard_type(t):
    fns = [x['fn'] or '' for x in t.get('xrefs', [])]
    fns += [f or '' for f in skx.get(t['addr'].lower(), [])]
    for f in fns:
        m2 = re.search(r'Register(P[A-Za-z0-9_]+?)(?:Class)?Descriptors?$', f)
        if m2:
            return m2.group(1)
        m3 = re.search(r'RegisterClassDescriptors?$', f)
        if m3:
            mm = re.search(r'(?:Phyre_|FFX_)?([A-Za-z0-9_]+?)_RegisterClassDescriptors?$', f)
            if mm:
                return mm.group(1)
        m = TYPE_PAT.search(f)
        if m:
            tp = m.group(1)
            tp = tp.replace('Phyre_PArray_', 'PArray_')
            tp = re.sub(r'_(dup|v\d+|\d|[A-F0-9]{6,}|copy|GetSingleton.*|d)$', '', tp)
            tp = re.sub(r'^Phyre_?', '', tp)
            BAD = {'Phyre', 'Engine', 'Class', 'Descriptor', 'Array', 'Ptr', 'P', ''}
            if len(tp) > 2 and tp not in BAD and not tp.startswith(('DEAD', 'Register')):
                return tp
    return None


for t in json.load(open('evidence.json'))['targets']:
    nm, addr = t['name'], t['addr']
    if nm in SPECIAL:
        new, conf, com = SPECIAL[nm]
        renames.append((nm, new, conf, com))
        continue
    if nm in XF:
        off = int(addr, 16) - 0xC8F7B0
        renames.append((nm, XF[nm], 'VALID', XF_COMMENT % hex(off)))
        continue
    # constants
    kind, val = const_name(nm, t.get('bytes', ''))
    if kind:
        if kind == 'kXm':
            renames.append((nm, 'kXmFltSignMask', 'CONFIRMED',
                            f'xmmword constant = {val}; SIMD abs/negate ops'))
            continue
        NICE = {3.141592653589793: 'Pi', 3.1415926: 'Pi', 3.1416: 'Pi',
                6.283185307179586: 'TwoPi', 6.2831852: 'TwoPi', 6.28319: 'TwoPi',
                0.0078125: 'Inv128', 0.00390625: 'Inv256',
                0.000244140625: 'Inv4096', 0.25: 'Quarter', 0.5: 'Half',
                1.0: 'One', 2.0: 'Two', 3.0: 'Three', 4.0: 'Four',
                5.0: 'Five', 6.0: 'Six', 10.0: 'Ten', 16.0: '16',
                50.0: '50', 140.0: '140', 180.0: '180', 210.0: '210',
                250.0: '250', 255.0: '255', 340.0: '340', 416.0: '416',
                740.0: '740', 1000.0: '1000', 4294967296.0: '2Pow32',
                0.0009765625: 'Inv1024'}
        nice = None
        for k2, v2 in NICE.items():
            if abs(val - k2) < 1e-6 * max(1.0, abs(k2)):
                nice = v2
                break
        if nice is None:
            nice = (f'{val:g}').replace('.', 'p').replace('-', 'm')
        renames.append((nm, f'{kind}_{nice}', 'CONFIRMED',
                        f'{kind[1:]} constant = {val!r}'))
        continue
    # guard flags
    if all(int(x, 16) == 0 for x in t.get('bytes', '0x0').split()):
        tp = guard_type(t)
        if tp:
            renames.append((nm, f'g_CDGuard_{tp}'[:60], 'VALID',
                            'static-init guard dword (bit0) for PClassDescriptorConcrete singleton; '
                            'ctors run once via test al,1 / or eax,1'))
            continue
    skips.append((nm, f'no confident evidence (refs={t["code_refs"]})'))

# dedup: same new-name collisions get a short address suffix
import collections
cnt = collections.Counter(n for _, n, _, _ in renames)
final = []
for o, n, c, cm in renames:
    if cnt[n] > 1:
        n = f'{n}_{o.split("_",1)[1][-4:]}'
    final.append((o, n, c, cm))
renames = final

with open('rename_plan.json', 'w') as f:
    json.dump({'renames': [{'old': o, 'new': n, 'conf': c, 'comment': cm}
                           for o, n, c, cm in renames],
               'skips': [{'name': s, 'reason': r} for s, r in skips]}, f, indent=1)
print(f'renames: {len(renames)}  skips: {len(skips)}')
import collections
print(collections.Counter(c for _, _, c, _ in renames))
for s in skips[:20]:
    print('SKIP', s[0], s[1])
