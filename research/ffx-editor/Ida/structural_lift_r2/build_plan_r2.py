#!/usr/bin/env python3
"""structural-r2: build rename plan from all verified evidence."""
import json, re, struct, collections
OUT='/home/wanderson/Documents/ffx-editor-main/work/_structural_r2'
sf={f['addr']:f['name'] for f in json.load(open(OUT+'/structural_funcs_now.json'))}
p2i={int(k,16):v for k,v in json.load(open(OUT+'/magiccoreop_ptr2idx.json')).items()}
plan=[]  # (addr, old, new, evidence, kind)
def add(a,new,ev,kind):
    plan.append((a.lower(), sf[a], new, ev, kind))

# --- A. MagicCoreOp: all 73 verified; fix A9_AD (slots A9+AD only)
for a,n in sf.items():
    m=re.match(r'^FFX_MagicCoreOp_([0-9A-F]{2})(_([0-9A-F]{2}))?_([A-Za-z0-9]+)_structural$',n)
    if not m: continue
    idxs=p2i[int(a,16)]
    c1=int(m.group(1),16); c2=int(m.group(3),16) if m.group(3) else None
    if c2 is None:
        new=n.replace('_structural','')
        add(a,new,f'core-op table[0x{c1:02X}]@0xC48EC8 (CONFIRMED position)','POS_VERIFIED')
    elif c2==c1+1 and idxs==[c1,c2]:
        new=n.replace('_structural','')
        add(a,new,f'core-op table[0x{c1:02X},0x{c2:02X}]@0xC48EC8 (CONFIRMED position)','POS_VERIFIED')
    else:
        # range claim mismatch -> And-form
        lo,hi=idxs[0],idxs[-1]
        tail=m.group(4)
        new=f'FFX_MagicCoreOp_{lo:02X}And{hi:02X}_{tail}'
        add(a,new,f'core-op table slots {[hex(i) for i in idxs]}@0xC48EC8 (claimed {m.group(1)}_{m.group(3)} range; actual={",".join(hex(i) for i in idxs)})','POS_MISLABEL')

# --- B. MagicSideOp (14) verified
for a,n in sf.items():
    m=re.match(r'^FFX_MagicSideOp_(\d+)_structural$',n)
    if m: add(a,n.replace('_structural',''),f'side-op table[{int(m.group(1))}]@0xC48E78 (CONFIRMED position)','POS_VERIFIED')

# --- C. MagicPostProc (8) verified
for a,n in sf.items():
    m=re.match(r'^FFX_MagicPostProc_(\d+)(_([A-Za-z0-9_]+))?_structural$',n)
    if m: add(a,n.replace('_structural',''),f'postproc table[{int(m.group(1))}]@0xC492C8 (CONFIRMED position)','POS_VERIFIED')

# --- D. SoundCmd table @0xC3A3A4 idx=cmd-17
sound_tbl={}
raw=open(OUT+'/soundcmd_table.bin','rb').read()
for i in range(0,len(raw)-3,4):
    off=0x1A4+i-0x1A4  # base at file offset 0x1A4
    v=struct.unpack_from('<I',raw,i)[0]
    if v and 0x401000<=v<0xC00000:
        sound_tbl[i-0x1A4]=v  # byte offset from table base
# build idx->ptr
idx2ptr={ (0xC3A3A4-0xC3A200)*0//4:0 }
idx2ptr={}
for i in range(0,len(raw)-3,4):
    v=struct.unpack_from('<I',raw,i)[0]
    if v and 0x401000<=v<0xC00000:
        idx2ptr[i//4 - (0xC3A3A4-0xC3A200)//4]=v
ptr2cmd={v:k+17 for k,v in idx2ptr.items()}
for a,n in sf.items():
    if not n.startswith('FFX_SoundCmd_'): continue
    ai=int(a,16)
    if ai in ptr2cmd:
        cmd=ptr2cmd[ai]
        m=re.match(r'^FFX_SoundCmd_Handler(Cmd|PlayTrack_?)(\d+)_sync_structural$',n)
        claimed=int(m.group(2)) if m else None
        if claimed==cmd:
            add(a,n.replace('_structural',''),f'sound-cmd table[{cmd-17}]@0xC3A3A4 = cmd {cmd} (RegistCommandSync: table[ArgList-17]) (CONFIRMED)','POS_VERIFIED')
        else:
            new=re.sub(r'HandlerCmd\d+','',n)
            new=f'FFX_SoundCmd_HandlerCmd{cmd}_sync'
            add(a,new,f'sound-cmd table[{cmd-17}]@0xC3A3A4 = cmd {cmd} (claimed {claimed}) (MISLABEL-FIX)','POS_MISLABEL')
# outliers
add('0x708600','FMOD_FileSystem_Open','pushed to FMOD::System::setFileSystem as open cb @0x7069ef (next to FMOD_FileSystem_Read/Close); body=PStreamReaderFile ctor + *a3=size *a4=handle','MISLABEL_FIX')
add('0x710d30','FFX_SoundCmd_LoadLoopPMapFile','called by FFX_SoundCmd_CreateLoopRequest on "loop" section miss; body=ReadEntireFile + PMapPair list parse','MISLABEL_FIX')
add('0x711ab0','FFX_Math_ComposeClampedDrawMatrix','body=Mat4x4Mul x3 + perspective divide + neg-component clamp + Vec4Scale; called by DrawPrimitive/SpriteDraw_Setup/RenderNode','MISLABEL_FIX')

# --- E. MagicCoreOp-table cross-module occupants
cross=[('0x81a5e0','FFX_MagicCoreOp_12to17_DrawParticlePass'),
       ('0x817200','FFX_MagicCoreOp_21_WriteRoot84_88'),
       ('0x81b9e0','FFX_MagicCoreOp_24to25_DrawBackgroundEffect'),
       ('0x81c000','FFX_MagicCoreOp_4D_DrawFieldGeometryPass'),
       ('0x819010','FFX_MagicCoreOp_5F_DebugModelBrowserDrawCharacter'),
       ('0x81c600','FFX_MagicCoreOp_6F_DrawBgAnimGeometry'),
       ('0x819590','FFX_MagicCoreOp_8C_DrawBackgroundRoom'),
       ('0x808e50','FFX_MagicCoreOp_A8_DebugModelBrowserDrawEnabled'),
       ('0x803860','FFX_MagicCoreOp_AA_Ps3DataTextureIdToEntry')]
for a,new in cross:
    idxs=p2i[int(a,16)]
    add(a,new,f'core-op table slots {[hex(i) for i in idxs]}@0xC48EC8 (CONFIRMED position; kept descriptor tail)','POS_VERIFIED')

# --- F. ATEL stragglers
atel=[('0x7b8110','FFX_Atel_Camera_Func6036_INTRET','Camera funcspace[54].INTRET; body tail-calls FFX_Camera_Internal_OpJ'),
      ('0x85aed0','FFX_Atel_Common_Func00E4_FLOATRET','Common funcspace[228].FLOATRET; pops float operand, SetFloatSlotsF'),
      ('0x85f520','FFX_Atel_Common_Func000C_INTRET','Common funcspace[12].INTRET; pops operand, SetControlledInstance'),
      ('0x878170','FFX_Atel_Debug_FuncC057_INTRET','Debug funcspace[87].INTRET; pops operand, memcpy to save_ram')]
for a,new,ev in atel: add(a,new,ev,'POS_VERIFIED')

# --- G. MagicHostContextTable @0xC64CE8 occupants
ctx_keep=['0x788ea0','0x7948b0','0x795e30','0x7bc040','0x798940','0x800010',
          '0x8368f0','0x82b5e0','0x8001e0','0x7882c0','0x7ecfe0','0x72c820',
          '0x72cc00','0x72ca10','0x82d860','0x7e45e0','0x7e4b40','0x7e6690',
          '0x9088d0','0x7fd9a0','0x7bb9d0','0x7bfff0']
rawc=open(OUT+'/magic_host_ctx_full.bin','rb').read()
ctxoff={}
for i in range(0,len(rawc)-3,4):
    v=struct.unpack_from('<I',rawc,i)[0]
    if v: ctxoff[v]=i
for a in ctx_keep:
    off=ctxoff.get(int(a,16))
    add(a,sf[a].replace('_structural',''),f'g_FFX_MagicHostContextTable[+0x{off:03X}] slot + body-verified semantics','CTX_VERIFIED')
ctx_fix=[('0x7b7010','FFX_Battle_BuildActorActionOrderList','ctx[+0x368]; body: builds 31-entry action-order byte list from pool bitmask + byte_112C895 priority table'),
         ('0x78cae0','FFX_Battle_ProcessActorDeathMode','ctx[+0x610]; body: switch on death mode, sets pad1060[14], calls FFX_Battle_InitActorDeathPosition'),
         ('0x795790','FFX_Btl_IsActorDeathStateSeqSet','ctx[+0xA00]; body: IsValidBattleSlot && actor->deathStateSeq'),
         ('0x7eb210','FFX_MagicHost_RemoveCallbackMode32Thunk','ctx[+0x4DC]; body: tail-calls FFX_Magic_RemoveCallbackSlot(a1,32)'),
         ('0x7e3d40','FFX_MagicHost_Oef2RelocateSectionsThunk','ctx[+0xB38]; body: tail-calls FFX_Magic_Oef2RelocateDataSections(a1,a1+a1[15])'),
         ('0x643820','FFX_MagicHost_UpdateShadowClrScaleThunk','ctx[+0xE94]; body: tail-calls FFX_ShadowMap_UpdateClrScaleFactor(char0,4 floats)')]
for a,new,ev in ctx_fix: add(a,new,ev,'MISLABEL_FIX')

# --- H. SoundSpuCmd (14) body-verified
for a,n in sf.items():
    if n.startswith('FFX_SoundSpuCmd_'):
        add(a,n.replace('_structural',''),'body-verified: pushes claimed opcode to g_FFX_SoundSpuCmdQueueCursor','BODY_VERIFIED')

# --- I. FFX_Field keeps
field_keep=['0x7e7030','0x7d9500','0x7d91f0','0x86ca90','0x86f010','0x8703e0',
 '0x871b60','0x7d7970','0x885c80','0x83f2e0','0x7d7910','0x7d7380','0x871980',
 '0x7d7950','0x7e2630','0x7e7240','0x7e1bd0','0x81b4f0','0x81e4c0','0x81cd80',
 '0x7d7410','0x8694b0','0x8423c0','0x8615f0','0x875d90','0x885420','0x882900',
 '0x872b70','0x7d7210','0x7d4210','0x7fbb40','0x7ec370','0x7e6d60','0x7e8ee0',
 '0x7e7360','0x782960','0x865d60','0x86a570','0x7d9470','0x7d9a10','0x8656e0',
 '0x7d9a20','0x7e2570','0x7d7310','0x7e1a80','0x7e7d90']
for a in field_keep:
    add(a,sf[a].replace('_structural',''),'body-decompiled; claimed role consistent','BODY_VERIFIED')
# 0x7ecfe0 already added via ctx_keep; dedupe later
field_fix=[('0x87b4a0','FFX_FieldDebug_DrawActorActionTableFloat','body: sprintf("%f",ActionTableByType(a1)[11]) + DrawQuadGlyphWithBorder; sits in debug-cb table @0xC5387C+0x3C'),
           ('0x82ac30','FFX_Field_ReadMotionField1284','body: returns *(float*)(arg+1284); clears nothing (was ClearRenderTargets mislabel)'),
           ('0x82b610','FFX_Chr_SetScaleUniform','body: chr[23]=chr[24]=chr[25]=arg (uniform scale XYZ); called by ChEvent scaleActorUniform'),
           ('0x7e6c90','FFX_Field_ComputeDeltaQuadrant','body: classifies (a3-a1,a4-a2) into quadrant n2 (0-3) — angle/direction helper called by RayCircleIntersect; not save/load')]
for a,new,ev in field_fix: add(a,new,ev,'MISLABEL_FIX')

# --- J. singletons / small tables / vtables
singles=[('0x8b1580','FFX_Save_LoadOrchestrator','save-state cb table @0xC59FC0[+0x30,+0x54]; body=save-load UI orchestration'),
 ('0x8e0340','FFX_FieldUI_DispatchSlot1','registered cb @0xC5B2B0 array; empty slot impl'),
 ('0x8e2720','FFX_Abmap_RenderFramePath','cb array @0xC5B2F8; body=menu draw pipeline (clip/rect/renderstate)'),
 ('0x8e27b0','FFX_Abmap_UIMode19DeactivateCb','cb array @0xC5B304; body=ReleaseGpuOnExit+clear flag (deactivate)'),
 ('0x8e2870','FFX_Abmap_UIMode20FieldHandoff','cb array @0xC5B318; body calls Menu2D_DispatchCallback(20) — mode literal confirmed'),
 ('0x8384f0','FFX_Mseq_WriteBlendedTransformChannels','pair @0xC49790; writer called by DispatchTransformChannelWriter'),
 ('0x8382c0','FFX_Mseq_DispatchTransformChannelWriter','pair @0xC49794; body dispatches blended-vs-sampled writer by flag byte'),
 ('0x6a5b20','FFX_Phyre_BindYuvVideoTextureSamplers','4 slots @0xB47E28..0xB47EB0 (descriptor table); name consistent'),
 ('0x6e2320','FFX_BtlUI_HudGaugeLogic','vtable-ish slot @0xB4AADC/0xB4AAEC; empty impl (stub cb)'),
 ('0x6e2a20','FFX_BtlUI_HudGaugeDraw','slot @0xB4AB38; InterlockedCompareExchange+memcpy+vtable call'),
 ('0x6dca00','FFX_BtlUI_HudGaugeSubEntry','refd inside jump-table @0x6dd1d6; gauge sub-entry accumulator'),
 ('0xaf1d10','Phyre_StaticInitPInputSourceMotionQuatXDescriptor','body embeds "PInputSourceMotionQuatX" in PClassDescriptor_ctor'),
 ('0xaf1dd0','Phyre_StaticInitPInputSourceMotionQuatYDescriptor','descriptor-init cluster @0xB0D190-9C; sibling of confirmed X/W'),
 ('0xaf1c50','Phyre_StaticInitPInputSourceMotionQuatWDescriptor','descriptor-init cluster @0xB0D190-9C; sibling of confirmed X/Y'),
 ('0xae3a20','Phyre_StaticInitPShaderParameterCaptureBufferStreamDescriptor','MISLABEL-FIX: body does PClassDescriptor_ctor("PShaderParameterCaptureBufferStream") — not save/load'),
 ('0xae5dc0','FFX_Phyre_RegisterPParameterBufferBaseWithAtExit','body: PClassDescriptor_ctor("PParameterBufferBase")+SetFields+atexit(dtor)'),
 ('0x7cfc00','FFX_Menu2D_MenuDefDataFieldValue_20w','refd @0x7c8673; menu-def field-value printer (sprintf+20w field)'),
 ('0x866680','FFX_FieldActor_DispatchTriggerTypeEvaluation','refd @0x871193; body switches on **a1 trigger-type byte -> UpdateMovementStep/EventOpcodeSplitter'),
 ('0x8b3630','FFX_Save_InitBufferTableLoop','refd @0x8b3c2f; body inits save buffer table (2-entry loop)'),
 ('0x8b5580','FFX_Menu_List_AuxAlwaysTrueCb','refd @0x8b500b; body returns 1 (always-true cb)'),
 ('0x8e4140','FFX_Save_PersistDataVersionCb','refd @0x8e471c; save persist-data version callback'),
 ('0xa47d50','FFX_Abmap_NodePlacementAnim','refd @0xa48901; body iterates placement slots updating transforms'),
 ('0x640120','FFX_Phyre_BindRenderTargetStack','body: GetRenderEngine+GetFieldRenderStack+AllocBufferSlot'),
 ('0x69bcc0','FFX_Phyre_ClassifyLitShaderFamilyByAssetPath','body: path-string compares (".dae","/chr/","PhyreChrLitShader")'),
]
for a,new,ev in singles:
    kind='MISLABEL_FIX' if 'MISLABEL' in ev else 'LIFT_CONFIRMED'
    add(a,new,ev,kind)

# Phyre ScriptGet/Init octet+quad (12)
for a,n in sf.items():
    if n.startswith(('Phyre_ScriptGetPInputSourceMotionQuat','Phyre_InitPInputSourceMotionQuat')):
        add(a,n.replace('_structural',''),'body-verified: class-name string + typeInfo chain match the named Quat axis','BODY_VERIFIED')

# RunPhase wrappers
for a,n in (('0x800530','FFX_Magic_RunPhase0Wrapper'),('0x800590','FFX_Magic_RunPhase1Wrapper'),('0x800950','FFX_Magic_RunPhase2Wrapper')):
    add(a,n,'body-verified: calls FFX_Magic_RunRuntimeRootPhase(0,<phase>) + phase table slots @0xC48D90/0xC48DD0','BODY_VERIFIED')

# dedupe by addr (last wins)
d={}
for r in plan: d[r[0]]=r
plan=[d[k] for k in sorted(d, key=lambda x:int(x,16))]
json.dump(plan, open(OUT+'/rename_plan_r2.json','w'), indent=0)
import collections
print('plan:',len(plan))
print(collections.Counter(r[4] for r in plan))
print('\n--- fixes ---')
for r in plan:
    if 'FIX' in r[4] or 'MISLABEL' in r[4]: print(r[0],r[1],'->',r[2])
