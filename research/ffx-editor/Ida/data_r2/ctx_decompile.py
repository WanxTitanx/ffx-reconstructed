#!/usr/bin/env python3
import sys, json, re
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
sess, _ = post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"data-r2","version":"1"}}})
post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool, args):
    _, body = post({"jsonrpc":"2.0","id":2,"method":"tools/call","params":{"name":tool,"arguments":args}}, sess)
    d = json.loads(body); r = d.get('result', d)
    return r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)

pairs = [
 ('CA80E8','DEAD_PModifierNetworkInstanceArray_GetSingleton_4FACC0'),
 ('C9AD1C','DEAD_PShape_ClassDescriptor_GetSingleton'),
 ('C91C10','DEAD_PCluster_GetStaticSlot_C91C18'),
 ('C93F90','DEAD_PAssetRef_GetStaticSlot_C93F98'),
 ('C9434C','DEAD_PRandomGenerator_GetStaticSlot_C94350'),
 ('1A855B0','DEAD_Phyre_PGameSettings_GetSize'),
 ('CCC868','DEAD_FFX_AsyncQ_GetContextEx'),
 ('C91658','DEAD_PClassDescriptorConcrete_PArrayU8_GetClassPtr'),
 ('CA9770','DEAD_Phyre_AnimationDescriptor_GetSizePtr'),
 ('C9B048','DEAD_PLightType_GetSingleton'),
 ('CA4590','DEAD_PShadowCasterType_GetSingleton'),
 ('CAE7B0','DEAD_Phyre_PCaller_GetSize21Ptr'),
 ('CB0AB8','DEAD_Phyre_PAttachableComponent_GetSize41Ptr'),
 ('CAFB68','DEAD_Phyre_PTimerComponent_GetSize60Ptr'),
 ('C90E2C','DEAD_GetStaticSlot_C90E30'),
 ('CA2F04','DEAD_Phyre_File_GetDirectoryListHead'),
 ('C940C4','DEAD_Phyre_EventSystem_Init'),
 ('CBD9B0','Phyre_AnimationScheduler_Execute'),
 ('C94EFC','DEAD_Phyre_Timer_InitFrequencySingleton'),
 ('C9424C','Phyre_Timer_TreeInit'),
 ('CA310C','Phyre_File_AddDirectoryEntry'),
 ('C59564','FFX_Menu_ItemListInit'),
 ('C0A09C','Phyre_PApplication_Constructor'),
 ('B6E681','LuaLex_readDecimalEscape'),
 ('18DED08','FFX_Battle_SnapshotFieldLightingState'),
 ('C53414','FFX_FieldDebug_ActorFieldList'),
 ('13009D0','FFX_Mgrp_AddMseqRecord'),
 ('113FCF0','FFX_MagicHost_CopyTransformToGlobals'),
 ('C24F0C','PhyreInit_C24F0C_destructor'),
 ('CA34CC','DEAD_Phyre_resource_streamHandler'),
]
out = {}
for tgt, fn in pairs:
    lf = json.loads(call('lookup_funcs', {'queries':[fn]}))
    fa = lf[0]['fn']['addr'] if lf and lf[0].get('fn') else None
    if not fa:
        out[tgt] = {'func': fn, 'err': 'nofunc'}; print(tgt, 'NOFUNC', fn); continue
    d = json.loads(call('decompile', {'addr': fa}))
    code = d.get('code','')
    hits = [ln.strip() for ln in code.splitlines() if tgt in ln]
    out[tgt] = {'func': fn, 'faddr': fa, 'hits': hits[:10]}
    print(tgt, fn, len(hits))
    for h in hits[:5]: print('   ', h[:150])
json.dump(out, open('/home/wanderson/Documents/ffx-editor-main/work/_data_r2/ctx_decompile.json','w'), indent=1)
