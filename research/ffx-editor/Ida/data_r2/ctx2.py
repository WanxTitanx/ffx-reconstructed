#!/usr/bin/env python3
import sys, json
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post
sess, _ = post({"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"data-r2","version":"1"}}})
post({"jsonrpc":"2.0","method":"notifications/initialized"}, sess)
def call(tool, args):
    _, body = post({"jsonrpc":"2.0","id":2,"method":"tools/call","params":{"name":tool,"arguments":args}}, sess)
    d = json.loads(body); r = d.get('result', d)
    return r['content'][0]['text'] if isinstance(r, dict) and 'content' in r else json.dumps(r)
pairs = [
 ('C94A1C','Phyre_Quat_RegisterClassDescriptor'),
 ('CCC868','FFEscMenu_DestroySingleton'),
 ('CA2F04','Phyre_File_AddEntry'),
 ('CA2F08','Phyre_File_RemoveDirectoryEntry'),
 ('CA310C','PhyreInit_TextureFormat_RGBA8'),
 ('C940C4','Phyre_Event_CheckAndReset'),
 ('18DED08','FFX_BtlUI_HudTextureOverride'),
 ('C9AD1C','DEAD_PDynamicSegmentDesc_ClassDescriptor_GetSingleton_C'),
 ('C0A09C','Phyre_PostProcessing_RegisterAllEffects'),
 ('C59564','FFX_Menu_ItemListInput'),
 ('CA34CC','PCD_NullThunk_AFE250'),
 ('CBD9B0','Phyre_AnimationScheduler_Process'),
]
for tgt, fn in pairs:
    lf = json.loads(call('lookup_funcs', {'queries':[fn]}))
    fa = lf[0]['fn']['addr'] if lf and lf[0].get('fn') else None
    if not fa:
        print(tgt,'NOFUNC',fn); continue
    d = json.loads(call('decompile', {'addr': fa}))
    code = d.get('code','')
    hits = [ln.strip() for ln in code.splitlines() if tgt in ln]
    print('##', tgt, fn, fa, len(hits))
    for h in hits[:6]: print('   ', h[:160])
