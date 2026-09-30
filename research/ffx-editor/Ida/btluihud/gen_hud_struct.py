#!/usr/bin/env python3
"""gen_hud_struct.py — emit FFX_BtlUIHud.h (pack(1), size 0x4068).

Layout proven by:
  - allocator: Phyre_Sort_RunScratchPass 0x6c9640 -> AllocGameArenaDebugFill(0x4068)
    + ctor FFX_ShaderParameter_ProcessGroup 0x6c7ec0 (PInstanceList_Init this+4,
    self-linked node +0x4C, locks +0x290/+0x2A0, PSharedPtr +0x3FC4/+0x3FA8,
    +0x4060=3, +0x4064=0), stored in global 0xCDEC18, getter 0x6d24c0.
  - member harvest: disasm this-alias tracking over the 27-fn FFX_BtlUI_HudActor*
    family (work/_btluihud/this_fields.json + offsets.json).
Only fields with behavioral evidence are named; rest is pad_NNNN.
"""
import re
TSZ = 0x4068
F = []
def add(off, name, ty, sz, note=""):
    F.append((off, name, ty, sz, note))

# ---- Phyre/PInstanceList-derived header (ctor + list-init evidence) ----
add(0x0000, 'entryTab',            'int', 4,     'VALID: dword at +0 read as list/entry head; cmp==1 gate (DrawSortedActorList 6d378e, CullHud 6c90ee [esi+eax*4]); deref as ptr (EnemyPartyProtoData 6d1bf9)')
add(0x0004, 'readyFlag',           'unsigned __int8', 1, 'VALID: byte flag gates body (RenderPostProcessEffect 6d4f7a)')
add(0x0005, 'flag_0005',           'unsigned __int8', 1, 'VALID: byte flag gates body (RenderWithPostProcess 6d57da)')
add(0x0006, 'pad_0006',            'char[2]', 2)
add(0x0008, 'hdrFloat_0008',       'float', 4, 'VALID: fld [esi+8] (RenderWithPostProcess 6d57f3)')
add(0x000C, 'pad_000C',            'char[20]', 20)
add(0x0020, 'listNext_0020',       'int', 4, 'VALID: PInstanceList_Init self-link [this+0x20]=&this+0x20 (ctor chain via +4)')
add(0x0024, 'listPrev_0024',       'int', 4, 'VALID: self-link (ctor)')
add(0x0028, 'listCount_0028',      'int', 4, 'VALID: zeroed by PInstanceList_Init (+4 obj +9*4)')
add(0x002C, 'instanceBlockHead',   'int', 4, 'VALID: AlignedLinkedListBlock_Init(this+0x2C,76,20,4,"PInstanceList"); head dword read as sub-this (RenderPostProcessEffect 6d4fa3)')
add(0x0030, 'pad_0030',            'char[4]', 4)
add(0x0034, 'listIterEnd_0034',    'int', 4, 'SUSPECTED: compared vs walking node (RenderWithPostProcess 6d5810)')
add(0x0038, 'field_0038',          'int', 4, 'VALID: dword r/w in RenderWithPostProcess (6d5858)')
add(0x003C, 'pad_003C',            'char[4]', 4)
add(0x0040, 'listCount_0040',      'int', 4, 'VALID: dword read in DrawSortedActorList (6d38bf)')
add(0x0044, 'listField_0044',      'int', 4, 'VALID: =0 in PInstanceList_Init (+4 obj +16*4)')
add(0x0048, 'listField_0048',      'int', 4, 'VALID: =3 in PInstanceList_Init (+4 obj +17*4)')
add(0x004C, 'nodeNext_004C',       'int', 4, 'CONFIRMED: ctor self-links [4C]=&[4C] (FFX_ShaderParameter_ProcessGroup 6c7ef5)')
add(0x0050, 'nodePrev_0050',       'int', 4, 'CONFIRMED: ctor self-links [50]=&[4C] (6c7ef7)')
add(0x0054, 'pad_0054',            'char[4]', 4)
add(0x0058, 'shaderContainerPtr',  'int', 4, 'VALID: *([+0x58]+16) deref chain (RenderPostProcessEffect 6d4fc5)')
add(0x005C, 'field_005C',          'int', 4, 'VALID: dword r/w (RenderPostProcessEffect/RenderHudActor)')
add(0x0060, 'slotKeyTab',          'float[5]', 20, 'VALID: float reads fld [edi+60h..] + dword-indexed [esi+ebx*4+60h] (DrawSortedActorList, RenderHudActor)')
add(0x0074, 'streamFlags_0074',    'unsigned int', 4, 'VALID: bytes +74/+75 written 0/1 as stream busy flags (RenderPostProcessEffect 6d4f7e); dword cmp==0 (StPtrProto 6d2f25); ctor-zeroed')
add(0x0078, 'field_0078',          'int', 4, 'VALID: dword cmp (StPtrProto 6d2f2d); ctor-zeroed')
add(0x007C, 'field_007C',          'int', 4, 'VALID: ctor-zeroed dword (ctor 6c7f16-2b)')
add(0x0080, 'textureDescPtr',      'int', 4, 'VALID: ptr used as this for PTextureDescription_ValidateAndSetConfig (StPtrProto 6d2fc8); ctor-zeroed')
add(0x0084, 'pad_0084',            'char[0x8C]', 0x8C)
# ---- 0x110..0x290 proto/copy pool (16-dword writes per ~0x80 block, AtbHpPtrProto) ----
add(0x0110, 'protoPool_0110',      'char[0x180]', 0x180, 'SUSPECTED: AtbHpPtrProto writes 16-dword tables at +0x110/+0x190/+0x210 (0x80 stride)')
add(0x0290, 'lockA_0290',          'char[16]', 16, 'CONFIRMED: eh-vector ctor builds 2x _ReaderWriterLock (8B) here (ctor 6c7f35)')
add(0x02A0, 'lockB_02A0',          'char[16]', 16, 'CONFIRMED: 2nd pair of _ReaderWriterLock (ctor 6c7f53)')
add(0x02B0, 'protoPool_02B0',      'char[0x208]', 0x208, 'SUSPECTED: continues proto pool; 16-dword writes at +0x2B0/+0x330/+0x3B0/+0x430')
# ---- four per-slot 64-dword work arrays ----
add(0x04B8, 'slotCountA',          'int[64]', 256, 'VALID: [edi+ebx*4+4B8h] = clamped bucket count >=1 (PartyPtrProto 6d34f4)')
add(0x05B8, 'slotCountB',          'int[64]', 256, 'VALID: [+ebx*4] second clamped count (PartyPtrProto 6d34fb)')
add(0x06B8, 'slotFloatC',          'float[64]', 256, 'VALID: float store per slot (PartyPtrProto 6d3428)')
add(0x07B8, 'slotFloatD',          'float[64]', 256, 'VALID: float store per slot (PartyPtrProto 6d3432)')
add(0x08B8, 'postFxChain',         'int', 4, 'CONFIRMED: stores Phyre_PostProcessing_EffectChain(this+4) result; read/compared in RenderHudActor (6c9f80), Enemy/OvrProtoData')
add(0x08BC, 'postFxTab',           'int[256]', 1024, 'SUSPECTED: dword array indexed ecx*4 (RenderHudActor 6cadfe); bound=gap to 0xCBC')
add(0x0CBC, 'fontCachePtr',        'int', 4, 'CONFIRMED: stores FFX_Scaleform_FontCache(&instanceList,...) (AtbHpPtrProto 6d1d12)')
add(0x0CC0, 'pad_0CC0',            'char[4]', 4)
# ---- sort tables (16 entries each; Phyre_Sort_RadixPass in/out) ----
add(0x0CC4, 'sortOutA',            'int[16]', 64, 'CONFIRMED: RadixPass results, [edi]=eax loop (AtbHpPtrProto 6d1cbe)')
add(0x0D04, 'sortOutB',            'int[16]', 64, 'CONFIRMED: p_m_float3C[16]=v6 (6d1cd1)')
add(0x0D44, 'sortInA',             'int[16]', 64, 'CONFIRMED: RadixPass arg2 = this+0xD44 (6d1cb0)')
add(0x0D84, 'sortInB',             'int[16]', 64, 'CONFIRMED: RadixPass arg2 = this+0xD84 (6d1cc0)')
add(0x0DC4, 'protoFlagA',          'unsigned __int8[16]', 16, 'VALID: byte[i]=0 loop (6d1cd4)')
add(0x0DD4, 'protoFlagB',          'unsigned __int8[16]', 16, 'VALID: byte[i]=0 loop (6d1cd8)')
add(0x0DE4, 'protoListPtr',        'int', 4, 'VALID: dword obj ptr, deref as _DWORD** (AtbHpPtrProto 6d1d91..)')
add(0x0DE8, 'actorNode',           'int[8]', 32, 'CONFIRMED: 8 node ptrs iterated (v8=this+0xDE8,+4 step x8; ComputeHudActorScreenPositions 6c8607); memset region start')
add(0x0E08, 'pad_0E08',            'char[0x1E0]', 0x1E0)
# ---- four 64-dword slot flag grids ----
add(0x0FE8, 'slotEnableGridA',     'int[64]', 256, 'CONFIRMED: memset 0x100 (ClearHudActorBuffer 6d18b1 + AtbHpPtrProto 6d1ef9); cmp==1 checks (ComputeHud 6c8622)')
add(0x10E8, 'slotEnableGridB',     'int[64]', 256, 'CONFIRMED: parallel grid, cmp==1 (ComputeHud 6c8633)')
add(0x11E8, 'slotGridC',           'int[64]', 256, 'SUSPECTED: dword write 1 (AtbHpPtrProto 6d1fb0 via [eax-100h])')
add(0x12E8, 'slotGridD',           'int[64]', 256, 'VALID: [ebx+edi*4+12E8h]=1 (ActorAp 6ce6d4); lea base (HpPtrProto 6d1f84)')
add(0x13E8, 'uvPairTab',           'float[256]', 1024, 'VALID: 8-byte-stride float2 UV pairs for gauge tiles (PartyPtrProto 6d3538 +8*idx; reads at 13EC/13F0/13F4)')
add(0x17E8, 'slotMatrix',          'float[64][16]', 4096, 'VALID: PMatrix4_copy16f into +0x17E8+64*i (PartyPtrProto 6d33fa) - X-rotated transforms per slot; bound=gap')
add(0x27E8, 'slotScaleA',          'float[64]', 256, 'VALID: float store per slot (PartyPtrProto 6d35fc)')
add(0x28E8, 'slotScaleB',          'float[64]', 256, 'VALID: 0.5*v70 per slot (PartyPtrProto 6d3606)')
add(0x29E8, 'slotFlagE',           'int[64]', 256, 'VALID: [+idx*4]==1 selects 10x/20x gauge mult (PartyPtrProto 6d344b)')
add(0x2AE8, 'slotByteTabF',        'unsigned __int8[256]', 256, 'VALID: byte reads at +0x2AE9 (ActorAp 6ce632); block at +0x2B68 used by CullHud; char buf at +0x2BA8 cmp 0x63 (ActorActor 6ce89f)')
add(0x2BE8, 'pad_2BE8',            'char[0x2C0]', 0x2C0)
add(0x2EA8, 'slotTabG',            'int[64]', 256, 'VALID: [ebx+edi*4+2EA8h]=eax store (ActorAp 6ce6f0)')
add(0x2FA8, 'pad_2FA8',            'char[4]', 4)
add(0x2FAC, 'protoBlocks',         'char[0x7FC]', 0x7FC, 'VALID: block bases 0x2FAC/0x2FB4 (RenderHudActor 6ca98d, Enemy/OvrProtoData lea); PartyProtoData strides slot<<0xA into it (6d1949)')
add(0x37A8, 'slotHandleTab',       'int[64]', 256, 'VALID: [esi+eax*4+37A8h] compared to node ptrs / ==0 (RenderHudActor 6ca96f); bound 64 assumed')
add(0x38A8, 'pad_38A8',            'char[0x700]', 0x700)
add(0x3FA8, 'phSharedB',           'char[8]', 8, 'CONFIRMED: ctor calls Phyre_PSharedPtr_GetRefCount(this+0x3FA8) (6c7f71)')
add(0x3FB0, 'slotHandleTab2',      'int[5]', 20, 'VALID: [esi+eax*4+3FB0h] compared to node ptrs (RenderHudActor 6ca4ed); lea base (HpPtrProto 6d1fcd)')
add(0x3FC4, 'textureDescA',        'char[0x1C]', 0x1C, 'CONFIRMED: 5-byte init {1,1,2,2,2} then Phyre_Texture_DeferredCreateFromFormat(this+0x3FC4) (HpPtrProto 6d1e4b-93); ctor shared-ptr init here')
add(0x3FE0, 'flags_3FE0',          'unsigned int', 4, 'VALID: dword &0x80 create-gate (HpPtrProto 6d1e56)')
add(0x3FE4, 'pad_3FE4',            'char[4]', 4)
add(0x3FE8, 'textureDescB',        'char[0x14]', 0x14, 'CONFIRMED: init {0,0,2,2,2} then DeferredCreateFromFormat(this+0x3FE8) (HpPtrProto 6d1e9e-e6)')
add(0x3FFC, 'field_3FFC',          'int', 4, 'VALID: base of tail-state accesses (StringFormatSkip)')
add(0x4000, 'pad_4000',            'char[4]', 4)
add(0x4004, 'flags_4004',          'unsigned int', 4, 'VALID: dword &0x80 create-gate (HpPtrProto 6d1ea9)')
add(0x4008, 'pad_4008',            'char[4]', 4)
add(0x400C, 'needsInitFlag',       'unsigned __int8', 1, 'CONFIRMED: set 1 by mode branches (HudActorAll 6ccf60+), consumed->0 in RenderHudActor (6c9fcf/6c9fea)')
add(0x400D, 'pad_400D',            'char[3]', 3)
add(0x4010, 'field_4010',          'int', 4, 'VALID: =0 init (HpPtrProto 6d1fe7)')
add(0x4014, 'field_4014',          'int', 4, 'VALID: =0 init (HpPtrProto 6d1fed)')
add(0x4018, 'enemyBarPosY',        'float', 4, 'CONFIRMED: fstp [ecx+4018h] <- stack arg4 (HudActorActorEnemy 6cebbf); init 90.0 (6d23b5); SUSPECTED axis')
add(0x401C, 'enemyBarPosX',        'float', 4, 'CONFIRMED: fstp [ecx+401Ch] <- stack arg0 (6cebb6); SUSPECTED axis')
add(0x4020, 'hudVecA',             'float[4]', 16, 'VALID: vec4 set {0,-1,0,0} mode 4798 / {-0.3,-0.7,0.3,0} init (HudActorAll 6ccf42-5a, HpPtrProto 6d23cc-ea)')
add(0x4030, 'flag_4030',           'unsigned __int8', 1, 'VALID: byte flag =0/=1 (HudActorAll 6cce68)')
add(0x4031, 'pad_4031',            'char[3]', 3)
add(0x4034, 'hudClipRect',         'float[4]', 16, 'VALID: rect = globals {-10,190,170,570} (HudActorAll 6ccf16-3a)')
add(0x4044, 'flag_4044',           'unsigned __int8', 1, 'VALID: byte flag =1 (HudActorAll 6cce6f); gates ActorActor (6ce829)')
add(0x4045, 'pad_4045',            'char[3]', 3)
add(0x4048, 'modeFilterFn',        'int', 4, 'CONFIRMED: fn ptr Menu2D_Filter_* assigned per mode (IsOne 6cce76, IsOneOr8235 6cd061, IsNot8323, IsNot8516Nor8302)')
add(0x404C, 'flag_404C',           'unsigned __int8', 1, 'VALID: byte flag =1/=0 (HudActorAll 6cce80)')
add(0x404D, 'pad_404D',            'char[3]', 3)
add(0x4050, 'hudModeId',           'int', 4, 'CONFIRMED: = n20 mode arg, dispatched by giant switch (HudActorAll 6cce44-4d)')
add(0x4054, 'flag_4054',           'unsigned __int8', 1, 'VALID: byte =0 (HudActorAll 6cce87)')
add(0x4055, 'pad_4055',            'char[3]', 3)
add(0x4058, 'field_4058',          'int', 4, 'VALID: dword =0 (HudActorAll 6cce8e)')
add(0x405C, 'field_405C',          'int', 4, 'VALID: dword =0 (HudActorAll 6cce98)')
add(0x4060, 'hudState',            'int', 4, 'CONFIRMED: ctor=3 (6c7f76); !=0 enables render (RenderHudActor 6c9fb0)')
add(0x4064, 'flag_4064',           'unsigned __int8', 1, 'CONFIRMED: ctor=0 (6c7f80)')
add(0x4065, 'pad_4065',            'char[3]', 3)

off = 0
for o, n, t, s, nt in F:
    assert o == off, f"gap at {hex(o)} expected {hex(off)}"
    off += s
assert off == TSZ, f"total {hex(off)} != {hex(TSZ)}"
lines = ['#pragma pack(push, 1)', 'struct FFX_BtlUIHud {']
for o, n, t, s, nt in F:
    m = re.match(r'^(.*?)(\[[0-9a-fA-FxX]+\](?:\[[0-9a-fA-FxX]+\])*)$', t)
    if m:
        base, dims = m.group(1), m.group(2)
        decl = f'  {base} {n}{dims}; /* +0x{o:04X}' + (f' {nt}' if nt else '') + ' */'
    else:
        decl = f'  {t} {n}; /* +0x{o:04X}' + (f' {nt}' if nt else '') + ' */'
    lines.append(decl)
lines.append('};')
lines.append('#pragma pack(pop)')
decl = '\n'.join(lines)
open('work/_btluihud/FFX_BtlUIHud.h', 'w').write(decl + '\n')
print(f"OK {len(F)} members, size 0x{off:X}")
