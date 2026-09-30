#!/usr/bin/env python3
"""K76-FINE L2: apply renames + comments to ffxoficial.exe.i64 via ida-pro-mcp JSON-RPC.
Idempotent: append_comments(dedupe=True); rename reports ok/fail per item."""
import json, subprocess, sys

URL = 'http://192.168.122.85:8745/mcp'

def call(name, args, rid=1):
    payload = {"jsonrpc":"2.0","id":rid,"method":"tools/call","params":{"name":name,"arguments":args}}
    r = subprocess.run(['curl','-s','-m','300',URL,'-H','Content-Type: application/json',
                        '-H','Accept: application/json, text/event-stream','-d',json.dumps(payload)],
                       capture_output=True, text=True)
    return json.loads(r.stdout)

RENAMES = [
  # ── math helpers mislabeled as BtlUI_* / MagicHost_* ──────────────────────
  ("0x6EDA30","FFX_Math_Vec4Scale_Ppp"),
  ("0x6ED710","FFX_Math_Vec4Mul_Ppp"),
  ("0x6ED830","FFX_Math_CopyVec4Normalize3"),
  ("0x6ED860","FFX_Math_Vec3CrossToVec4"),
  ("0x6ED700","FFX_Math_Mat4x4Mul_Thunk"),
  ("0x6ED420","FFX_Math_Mat4x4MulVec4_Copy"),
  # ── pppDrawMatrix family (progtbl 0xC3A500, w3 render slots) ─────────────
  ("0x734C40","FFX_Ppp_DrawMatrix_ComposeSwMatrix"),
  ("0x734C70","FFX_Ppp_DrawMatrixLoop_ComposeSwMatrix"),
  ("0x734CA0","FFX_Ppp_DrawMatrixFront_BuildScaledMatrix"),
  ("0x734D20","FFX_Ppp_DrawMatrixNoRot_ScaleRowsAddOffset"),
  ("0x734DC0","FFX_Ppp_DrawMatrixWood_ComposeWoodMatrix"),
  ("0x734E60","FFX_Ppp_DrawMatrixWood_BuildWoodBasis"),
  # ── pppKeShpTail* mains (w2) — position-history ring push ────────────────
  ("0x74C570","FFX_Ppp_KeShpTail_PushPosHistory"),
  ("0x74E570","FFX_Ppp_KeShpTail2_PushPosHistory"),
  ("0x74D570","FFX_Ppp_KeShpTailX_PushPosHistory"),
  ("0x74F5B0","FFX_Ppp_KeShpTail2X_PushPosHistory"),
  ("0x750390","FFX_Ppp_KeShpTail3_PushPosHistoryPva8"),
  ("0x751D80","FFX_Ppp_KeShpTail3X_PushPosHistoryPva8"),
  ("0x754000","FFX_Ppp_KeShpTailPht_PushPosHistoryPva8F"),
  ("0x7550A0","FFX_Ppp_KeShpTailLc_NullMain"),
  # ── pppKeShpTail* renders (w3) — arclength trail/ribbon renderer ─────────
  ("0x74C650","FFX_Ppp_KeShpTail_RenderTrail"),
  ("0x74E650","FFX_Ppp_KeShpTail2_RenderTrail"),
  ("0x74D650","FFX_Ppp_KeShpTailX_RenderTrail"),
  ("0x74F690","FFX_Ppp_KeShpTail2X_RenderTrail"),
  ("0x750700","FFX_Ppp_KeShpTail3_RenderTrail"),
  ("0x7520B0","FFX_Ppp_KeShpTail3X_RenderTrail"),
  ("0x7543F0","FFX_Ppp_KeShpTailPht_RenderTrail"),
  ("0x7550E0","FFX_Ppp_KeShpTailLc_NullRender"),
  # ── pppKeShpTail* inits (w7) / resets (w8) ───────────────────────────────
  ("0x74C620","FFX_Ppp_KeShpTail_InitRing31"),
  ("0x74E620","FFX_Ppp_KeShpTail2_InitRing31"),
  ("0x74D620","FFX_Ppp_KeShpTailX_InitRing31"),
  ("0x74F660","FFX_Ppp_KeShpTail2X_InitRing31"),
  ("0x7505E0","FFX_Ppp_KeShpTail3_InitPvaRing28"),
  ("0x750670","FFX_Ppp_KeShpTail3_ResetSecondary"),
  ("0x751F90","FFX_Ppp_KeShpTail3X_InitPvaRing28"),
  ("0x752020","FFX_Ppp_KeShpTail3X_ResetSecondary"),
  ("0x754270","FFX_Ppp_KeShpTailPht_InitPvaRing27"),
  ("0x754350","FFX_Ppp_KeShpTailPht_ResetSecondary"),
  ("0x7550B0","FFX_Ppp_KeShpTailLc_InitRing31"),
  # ── pppKeMdl* family — float PVA integrator + batch drawable ─────────────
  ("0x7498E0","FFX_Ppp_KeMdlTfd_FloatPvaBuildDrawable"),
  ("0x7498B0","FFX_Ppp_KeMdlTfd_InitPva"),
  ("0x72E870","FFX_Ppp_KeMdlDtt_FloatPvaSpriteDraw"),
  ("0x72E810","FFX_Ppp_KeMdlDtt_InitPva_A"),
  ("0x72E840","FFX_Ppp_KeMdlDtt_InitPva_B"),
  ("0x7491A0","FFX_Ppp_KeMdlBmp_PolygonBasisProject"),
  ("0x749180","FFX_Ppp_KeMdlBmp_NullInit"),
  ("0x749190","FFX_Ppp_KeMdlBmp_NullInit2"),
  ("0x749A20","FFX_Ppp_KeMdlTfdUv_FloatPva3BuildDrawable"),
  ("0x7499C0","FFX_Ppp_KeMdlTfdUv_InitPva3"),
  ("0x749BE0","FFX_Ppp_KeMdlTfd2_InitPva"),
  ("0x749C10","FFX_Ppp_KeMdlTfd2_FloatPvaBuildDrawable"),
  ("0x749D00","FFX_Ppp_KeMdlTfdUv2_InitPva3"),
  ("0x749D60","FFX_Ppp_KeMdlTfdUv2_FloatPva3BuildDrawable"),
  ("0x749F30","FFX_Ppp_KeMdlTfd3_InitPva"),
  ("0x749F60","FFX_Ppp_KeMdlTfd3_FloatPvaBuildDrawable2F"),
  ("0x74A060","FFX_Ppp_KeMdlTfdUv3_InitPva3"),
  ("0x74A0C0","FFX_Ppp_KeMdlTfdUv3_FloatPva3BuildDrawable2F"),
  # ── pppKeThHitBorn (slot 391) ────────────────────────────────────────────
  ("0x759E70","FFX_Ppp_KeThHitBorn_SpawnOnHitList"),
  ("0x75A000","FFX_Ppp_KeThHitBorn_ClearEnableFlag"),
  # ── shared helpers ───────────────────────────────────────────────────────
  ("0x728AC0","FFX_Ppp_SharedNullsub"),
  ("0x75EED0","FFX_Ppp_StoreVec4WithGlobalMirror"),
]

COMMENTS = [
  ("0x6EDA30","K76-FINE L2: vec4 scale — dst[0..3]=src[0..3]*s (3 stack args). Ex-name 'BtlUI_HudParty_GetPortrait' wrong. Called by DrawMatrixFront/NoRot/Wood row scaling."),
  ("0x6ED710","K76-FINE L2: vec4 componentwise multiply — dst[i]=a[i]*b[i]. Ex-name 'BtlUI_HudParty_GetTarget' wrong."),
  ("0x6ED830","K76-FINE L2: copy vec4 then Vec3NormalizeInPlace(xyz). Ex-name 'BtlUI_HudParty_GetCommand' wrong. Used by DrawMatrixWood basis build."),
  ("0x6ED860","K76-FINE L2: vec3 cross product -> vec4 (w=0). Ex-name 'BtlUI_HudParty_SetCommand' wrong."),
  ("0x6ED700","K76-FINE L2: thunk -> Phyre_Math_Mat4x4Mul (0x705AA0): out = a*b 4x4 matrix multiply. Ex-name 'Menu2D_ProjectNodeCoords' wrong."),
  ("0x6ED420","K76-FINE L2: dst(vec4) = Mat4x4MulVec4(mat, src). Ex-name 'CopySmallTransformVec4' misleading (it transforms, not copies)."),
  ("0x734C40","pppDrawMatrix w3 (slots 0x13/0xA4): node+156=0 (mode=full), node+80 = ppvSWMatrix * node+16 (Mat4x4Mul)."),
  ("0x734C70","pppDrawMatrixLoop w3 (slots 0x6D/0xFE): identical to DrawMatrix (node+156=0; node+80=ppvSWMatrix*node+16)."),
  ("0x734CA0","pppDrawMatrixFront w3 (slots 0x14/0xA5): node+156=1 (mode=front); rows0-2 = Vec4Scale(node rows, ppvMng scale @+0x60/64/68); node+128 = ppvWorldMatrix * node+64."),
  ("0x734D20","pppDrawMatrixNoRot w3 (slots 0x8B/0x11C): 3x Vec4Scale rows + Vec4Mul translation, then node+128..136 += flt_230FF50..58 global offset (no rotation on translation)."),
  ("0x734DC0","pppDrawMatrixWood w3 (slots 0x30/0xC1): node+156=2 (mode=wood); scaled rows; node+80 = ppvSWMatrixWood * node+80; node+128 = ppvSWMatrix * node+64."),
  ("0x734E60","pppDrawMatrixWood w5 (slots 0x30/0xC1): builds wood basis globals — normalizes qword_230FF30 dir, Vec3Cross 2nd axis, writes ppvWorldMatrixWood/ppvSWMatrixWood (+flt_230FF50 translation). NOT a 'free' — family-specific phase."),
  ("0x74C570","pppKeShpTail w2 (0x19/0xAA): push node pos (node+64 vec4) into tail history ring @ field[param0]+16, cap=field+160 byte, write cursor field+161 desc; reseed all slots when node+12==0; guard ppvUserStopPartF."),
  ("0x74E570","pppKeShpTail2 w2 (0x1A/0xAB): byte-identical ring push to KeShpTail (31-cap, cursor desc)."),
  ("0x74D570","pppKeShpTailX w2 (0x54/0xE5): byte-identical ring push."),
  ("0x74F5B0","pppKeShpTail2X w2 (0x63/0xF4): byte-identical ring push."),
  ("0x750390","pppKeShpTail3 w2 (0x2E/0xBF): ring of 28 vec4 @ field+48 (cursor byte field+504 desc) + 8-ch int16 PVA integrator (pos@0-14, vel@16-22/32-38, acc@24-30/40-46; pos+=vel, vel+=acc per tick) + on directive (node+12==*msg) merges 24 i16 deltas msg+32..78."),
  ("0x751D80","pppKeShpTail3X w2 (0x7C/0x10D): same as KeShpTail3 (ring28 @+48 + 8ch PVA + directive merge msg+32..78); differs in render/params."),
  ("0x754000","pppKeShpTailPht w2 (0x171): ring of 27 vec4 @ field+48 (cursor field+500) + 8ch i16 PVA + extra scalar float PVA @ field+480/484/488; directive merges i16 msg+48..94 + float msg+28/32/36."),
  ("0x7550A0","pppKeShpTailLc w2 (0x172): STUB no-op (PC-remaster stubbed handler)."),
  ("0x74C650","pppKeShpTail w3 (0x19/0xAA): trail/ribbon renderer — walks 31-slot pos ring (read cursor field+161), arclength-resamples at spacing param+28, seg count param+32, width taper param+24, colors = fieldB[param1] i16x4 and params+16..22 x ppvMng+112..118 >>19 fixed-point; per-seg scale+DrawPrimitive; flipbook timer field+162 += param+8 vs per-frame dur table stride8 (v43+8*idx+18), frames wrap at v43+6 w/ loop flag +20."),
  ("0x74E650","pppKeShpTail2 w3 (0x1A/0xAB): same arclength trail renderer as KeShpTail; extra byte params (a3+20..27,34) select flags/modes."),
  ("0x74D650","pppKeShpTailX w3 (0x54/0xE5): same arclength trail renderer; flag bytes param+34/35/36."),
  ("0x74F690","pppKeShpTail2X w3 (0x63/0xF4): same arclength trail renderer; width uses param+12->16 range; param+34 byte skips resample branch."),
  ("0x750700","pppKeShpTail3 w3 (0x2E/0xBF): trail renderer + SECOND anim state at field+656..664 (counter accumulates param+8) + mutates ppvWorldMatrix +152/156/204/220 (billboard-ify)."),
  ("0x7520B0","pppKeShpTail3X w3 (0x7C/0x10D): like KeShpTail3 + extra params +80..82 and THIRD field selector (param[3])."),
  ("0x7543F0","pppKeShpTailPht w3 (0x171): trail renderer; seg count at param+96; two color fields via param[0]/param[1] (i16x4+ >>7); ring via param[2]."),
  ("0x7550E0","pppKeShpTailLc w3 (0x172): STUB no-op render."),
  ("0x74C620","pppKeShpTail w7 init: field[param0]+160 word=31 (ring cap), +162 dword=0 (flipbook timer+frame)."),
  ("0x74E620","pppKeShpTail2 w7 init: same ring31 init."),
  ("0x74D620","pppKeShpTailX w7 init: same ring31 init."),
  ("0x74F660","pppKeShpTail2X w7 init: same ring31 init."),
  ("0x7505E0","pppKeShpTail3 w7 init: zero 8ch PVA (48B), ring cursor +504=0, +496/+500=0, +502 word=rand() (random initial phase)."),
  ("0x750670","pppKeShpTail3 w8 reset: zero second anim state +656(dword)/+660(word)/+664(byte) + region +160..204."),
  ("0x751F90","pppKeShpTail3X w7 init: same as KeShpTail3 init (PVA zero + ring cursor + rand +502)."),
  ("0x752020","pppKeShpTail3X w8 reset: same as KeShpTail3 reset."),
  ("0x754270","pppKeShpTailPht w7 init: zero PVA region +160..204 + float PVA +640/644/648 + cursor +660, +652/656 + rand +658."),
  ("0x754350","pppKeShpTailPht w8 reset: same region zeroing without rand."),
  ("0x7550B0","pppKeShpTailLc w7 init: field[param0]+160 word=31, +162 dword=0, +166 byte=0 — only live phase of the stubbed handler."),
  ("0x7498E0","pppKeMdlTfd w3 (0x2A/0xBB): 1-ch float PVA integrator on field[param2]+160/164/168 (pos+=vel, vel+=acc; directive adds msg+8/12/16); if param[1]!=0xFFFF: StoreIntIntFloatGlobals(param[5],param[6],pos) + KR_BuildBatchDrawable(node, res=param[1], fieldA=param[0], stride=4*param[7], 0,0, flag8=1, 0, ppvMng+112, ppvMng[0]+120)."),
  ("0x7498B0","pppKeMdlTfd w7+w8 init: zero field[param2]+160/164/168 (PVA state)."),
  ("0x72E870","pppKeMdlDtt w3 (0x32/0xC3): 1-ch float PVA on field[param0]+160/164/168, mode byte param[5]: <4 = PVA w/ acc float; >=4 = field+168 is a POINTER written back at end. Fixed-point color x4 via field[param1] i16 * ppvMng+112..118 * 2^-26; packed sprite/UV decode from runtime scratch (304-stride, ping-pong (frame+mode)&1); gated g_eventId!=318; UpdateTransformCoords_Bridge/Process draws."),
  ("0x72E810","pppKeMdlDtt w7 init: zero field[param0]+160..168."),
  ("0x72E840","pppKeMdlDtt w8 init: zero field[param0]+160..168 (identical body)."),
  ("0x7491A0","pppKeMdlBmp w3 (0x167): per-polygon dominant-axis projection — iterates 16-stride records in resource param[10] (lppEnv+32 table), for each poly unpacks 3 i16 verts from vertex blob (param[9] res), picks projection plane by largest |edge component|, writes projected basis back; dbgPrintf on condition; then optional draw w/ Vu0InversMatrix(ppvParMatrix*node) + TextDraw."),
  ("0x749180","pppKeMdlBmp w7: STUB no-op."),
  ("0x749190","pppKeMdlBmp w8: STUB no-op."),
  ("0x749A20","pppKeMdlTfdUv w3 (0x168): 3-ch float PVA (160/164/168, 176/180/184, 188/192/196; sel=param[2]); directive adds msg+8..16/32..40/44..52; BuildBatchDrawable passes (int)ch1pos,(int)ch2pos as UV ints."),
  ("0x7499C0","pppKeMdlTfdUv w7+w8 init: zero 9 floats +160..196 (3-ch PVA)."),
  ("0x749BE0","pppKeMdlTfd2 w7+w8 init: zero field[param2]+160..168."),
  ("0x749C10","pppKeMdlTfd2 w3 (0x169): same 1-ch PVA as Tfd; flag8 = param[29] byte (vs literal 1)."),
  ("0x749D00","pppKeMdlTfdUv2 w7+w8 init: zero 9 floats +160..196."),
  ("0x749D60","pppKeMdlTfdUv2 w3 (0x16A): same 3-ch PVA as TfdUv; flag8 = param[56] byte."),
  ("0x749F30","pppKeMdlTfd3 w7+w8 init: zero field[param2]+160..168."),
  ("0x749F60","pppKeMdlTfd3 w3 (0x16B): 1-ch PVA; flag8 = OR(param[29..33]); arg9 = SECOND field ptr node+param[3]+160."),
  ("0x74A060","pppKeMdlTfdUv3 w7+w8 init: zero 9 floats +160..196."),
  ("0x74A0C0","pppKeMdlTfdUv3 w3 (0x16C): 3-ch PVA; flag8 = OR(param[56..60]); arg9 = second field ptr node+param[3]+160."),
  ("0x759E70","pppKeThHitBorn w2 (0x187): hit-born emitter — directive (node+12==*msg) sets/clears bit0x02 of field[param1]+160 (spawn enable); then walks linked list head=*(field[param0]+160), next=*cur; for nodes w/ flag&0x800 (hit active): spawn template ppvMng[0]+60+16*msg[1] via InsertCaptureBatchEntry, parent=node, copy pos from cur+64+48*cur[54] into new field sel msg+8 via StoreVec4. flag 0x02 clear => also requires (flag&0x40)==0 AND bails if Magic_GetCurrentMagicId()==203."),
  ("0x75A000","pppKeThHitBorn w7 init: clear enable-flag byte field[param1]+160."),
  ("0x728AC0","K76-FINE L2: THE shared PPP no-op — used as filler phase by ~40 slots (pppop_bound_g 0x13E, RyjMegaBirth* 0x188-0x18B, KeShpTail3XImm 0x19C, DrawMatrixWoodLoop 0x160, DrawMatrixFrontLoop 0x199...). Whole-handler stub when in w2/w3."),
  ("0x75EED0","K76-FINE L2: writes src vec4 xyz -> dst (w preserved) AND mirrors to globals unk_C8F7A0/C8F7D0/C0A010. Ex-name 'SwapTransformState' misleading (no swap). Core store used by all KeShpTail ring pushes + KeThTp/KeThHitBorn."),
]

if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == 'rename':
        res = call('rename', {"batch": {"func": [{"addr": a, "name": n} for a, n in RENAMES]}})
        txt = res['result']['content'][0]['text']
        print('RENAME:', txt[:4000])
    elif len(sys.argv) > 1 and sys.argv[1] == 'comment':
        res = call('append_comments', {"items": [{"addr": a, "comment": c, "scope": "func", "dedupe": True} for a, c in COMMENTS]})
        txt = res['result']['content'][0]['text']
        print('COMMENT:', txt[:4000])
    elif len(sys.argv) > 1 and sys.argv[1] == 'save':
        res = call('idb_save', {})
        print('SAVE:', json.dumps(res)[:600])
