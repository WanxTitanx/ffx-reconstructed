#!/usr/bin/env python3
"""apply_hud.py — [type-lift-r3] apply FFX_BtlUIHud prototypes + verify + save.

ORDER MATTERS: idb_save runs after EVERY batch so a session crash cannot lose
applied types (the previous run lost 18 applied protos + the struct decl when
the server died mid-verify). Verify happens AFTER the save checkpoint.
"""
import json, sys, time, os
sys.path.insert(0, "work/_btluihud")
from mcpc import call

# (addr, signature-with-name, evidence note)
EDITS = [
    ("0x6d24c0", "struct FFX_BtlUIHud *__cdecl FFX_BtlUI_HudActorAtbMpPtrProto(void)",
     "returns global HUD ptr ds:0CDEC18; mov eax,[0CDEC18];retn"),
    ("0x644c60", "int __cdecl FFX_BtlUI_ClearHudActorBuffer(void)",
     "thunk: call getter; mov ecx,eax; jmp 6D18B0 -> rep stosd 0x40 at +0xFE8"),
    ("0x643160", "void __cdecl FFX_FieldParticle_SetHudBarEnemyPosition(float x, float y)",
     "fld [ebp+y/x] -> pushes -> getter -> HudActorActorEnemy(hud,x,y)"),
    ("0x644bb0", "void *__cdecl FFX_BtlUI_CopyActorAtbMpState(void *a1, void *a2, int a3, int a4, float a5, float *a6, float *a7, FFX_BattleContext *ctx, float a9, float a10, struct FFX_BtlUIHud *hud, int a12)",
     "hud at last stack slot ebp+30 (mov ecx,[ebp+actorData]); retn 0 cdecl; returns edx out-ptr"),
    ("0x6d2660", "void __cdecl FFX_BtlUI_HudActorAtbApPtrProto(struct FFX_BtlUIHud *this, int a2, float *a3, int a4, int a5)",
     "this=arg_0 on stack (mov ebx,[ebp+arg_0]); arg_8 float* out (fstp [eax]); cdecl retn 0"),
    ("0x6d1c70", "int __thiscall FFX_BtlUI_HudActorAtbHpPtrProto(struct FFX_BtlUIHud *this)",
     "mov esi,ecx; early eax=0x15; inits sort tabs/flag arrays/fontcache/textures"),
    ("0x6d2d40", "int __thiscall FFX_BtlUI_HudActorAtbTPtrProto(struct FFX_BtlUIHud *this)",
     "mov esi,ecx; returns eax=0x13 (6d2e49)"),
    ("0x6d2f20", "int __thiscall FFX_BtlUI_HudActorAtbStPtrProto(struct FFX_BtlUIHud *this)",
     "mov esi,ecx; checks +74/+78/+7C/+80 flags; eax=1 early"),
    ("0x6d4f50", "void __thiscall FFX_BtlUI_HudActor_RenderPostProcessEffect(struct FFX_BtlUIHud *this)",
     "mov edi,ecx; +4 ready byte, +74/75 stream flags, retn 0"),
    ("0x6d57b0", "void __thiscall FFX_BtlUI_HudActor_RenderWithPostProcess(struct FFX_BtlUIHud *this)",
     "mov esi,ecx; +5 gate byte, +8 float, retn 0 (EH funclets aside)"),
    ("0x6d2910", "int __thiscall FFX_BtlUI_HudActorAtbCtPtrProto(struct FFX_BtlUIHud *this, float *dst)",
     "mov edx,[ebp+dst]; fld [ecx+10h]; retn 4; returns lea eax,[ebx+1] 0/1"),
    ("0x6d1930", "void __thiscall FFX_BtlUI_HudActorAtbPartyProtoData(struct FFX_BtlUIHud *this, int idx)",
     "lea edi,[ecx+eax*4]; add ecx,2FACh; slot<<0xA into protoBlocks; retn 4"),
    ("0x6d1bf0", "int __thiscall FFX_BtlUI_HudActorAtbEnemyPartyProtoData(struct FFX_BtlUIHud *this, int idx)",
     "mov eax,[ecx+eax*4] idx into entryTab; returns 0 or 0x13; retn 4"),
    ("0x6cebb0", "void __thiscall FFX_BtlUI_HudActorActorEnemy(struct FFX_BtlUIHud *this, float x, float y)",
     "fstp [ecx+401Ch]=arg_0(x); fstp [ecx+4018h]=arg_4(y); retn 8"),
    ("0x6c85c0", "void __thiscall FFX_BtlUI_ComputeHudActorScreenPositions(struct FFX_BtlUIHud *this, int a2, int a3)",
     "mov edx,ecx; iterates actorNode[8] at +0xDE8; retn 8"),
    ("0x6ced00", "void __thiscall FFX_BtlUI_HudActorStringFormatSkip(struct FFX_BtlUIHud *this, int a2, int a3)",
     "mov ebx,ecx; arg_0->esi, arg_4 cmp==4; retn 8"),
    ("0x6d0200", "void __thiscall FFX_BtlUI_HudActorAtbStProtoData(struct FFX_BtlUIHud *this, int a2, int a3)",
     "mov edi,ecx; retn 8"),
    ("0x6ce820", "void __thiscall FFX_BtlUI_HudActorActorActor(struct FFX_BtlUIHud *this, int a2)",
     "ecx->? uses +0xDE8 lea; +0x4044 byte gate; retn 4"),
    ("0x6ce260", "void __thiscall FFX_BtlUI_HudActorActorMp(struct FFX_BtlUIHud *this, int a2)",
     "mov ebx,ecx; retn 4"),
    ("0x6ce620", "char __thiscall FFX_BtlUI_HudActorActorAp(struct FFX_BtlUIHud *this, int a2, int a3, int a4, int a5, int a6, int a7)",
     "mov ebx,ecx; returns al 0/1 (6ce66a/6ce6f9); lea edx,[ebx+2AE9h]; retn 18h"),
    ("0x6cce40", "void __thiscall FFX_BtlUI_HudActorAll(struct FFX_BtlUIHud *this, int a2, char predecessor, int instanceIdx, int hudModeId, int n65, int a7)",
     "edi=ecx; n20->+0x4050 modeId (switch); sub_6F5630->ActorMp arg; retn 18h"),
    ("0x6d1420", "void __thiscall FFX_BtlUI_HudActorAtbOvrProtoData(struct FFX_BtlUIHud *this, int idx, int a3, int a4, float a5, int a6, int a7)",
     "ecx=this via ebx; lea ecx,[eax+0DEAh]; fld arg_C; retn 18h"),
    ("0x6d1660", "void __thiscall FFX_BtlUI_HudActorAtbEnemyProtoData(struct FFX_BtlUIHud *this, int idx, int a3, int a4, float a5, int a6, int a7)",
     "mov edx,ecx; lea ecx,[eax+0DEAh] idx*4 table; fld arg_C; retn 18h"),
    ("0x6c9f80", "void __thiscall FFX_BtlUI_RenderHudActor(struct FFX_BtlUIHud *this, int a2, int a3, char a4)",
     "mov esi,ecx; +0x4060 state gate; arg_4 cmp==4 mode; arg_8 byte bl; retn 0Ch"),
    ("0x6d3130", "float *__thiscall FFX_BtlUI_HudActorAtbPartyPtrProto(struct FFX_BtlUIHud *this, float *outVec4, float f2, float f3, int a5, float f6, int a7, int a8, int a9, float f10, float f11, int a12, float f13)",
     "edi=ecx; arg_0 float* out (writes vec4, returned in eax); fld args C,10,18,28,2C,34; retn 30h"),
    ("0x6d3780", "void __thiscall FFX_BtlUI_HudActorDrawSortedActorList(struct FFX_BtlUIHud *this, float f1, float f2, float f3, int a5, float f6, float f7, int a8, float f9)",
     "edi=ecx; [edi]==1 gate; fld args 8,C,10,18,1C,24; retn 20h"),
    ("0x6c9090", "char __thiscall FFX_BtlUI_CullHudActorsByFrustum(struct FFX_BtlUIHud *this, float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33, char a17, float a18, float a19, float a20)",
     "esi=ecx; lea ecx,[ebp+arg_0] = by-value 4x4 matrix (16 floats); returns al 0/1; retn 50h"),
    ("0x6c7ec0", "struct FFX_BtlUIHud *__thiscall FFX_ShaderParameter_ProcessGroup(struct FFX_BtlUIHud *this)",
     "ctor: PInstanceList_Init(+4), self-node +4C, locks +290/+2A0, PSharedPtr +3FC4/+3FA8, +4060=3,+4064=0; returns eax=this"),
]

BREAK_MARKERS = ("Decompilation failed", "decompilation failed", "BAD SP",
                 "bad sp", "/* ERROR", "could not", "positive sp", "wrong sp",
                 "spoils", "analysis yielded no")

def snapshot(addrs):
    old = {}
    if os.path.exists("work/_btluihud/old_protos_r3.json"):
        old = json.load(open("work/_btluihud/old_protos_r3.json"))
    missing = [a for a in addrs if a not in old]
    for i in range(0, len(missing), 40):
        res = call("func_profile", {"queries": [{"addr": a, "include_prototype": True} for a in missing[i:i+40]]})
        arr = res if isinstance(res, list) else res.get("result") or []
        for pack in arr:
            for it in (pack.get("data") or []):
                a = (it.get("addr") or "").lower()
                if a and it.get("prototype"):
                    old[a] = it["prototype"]
    json.dump(old, open("work/_btluihud/old_protos_r3.json", "w"), indent=1)
    return old

def declare_struct():
    import re
    src = open('work/_btluihud/FFX_BtlUIHud.h').read()
    src = re.sub(r'/\*.*?\*/', '', src, flags=re.S)
    src = re.sub(r'#pragma.*', '', src)
    src = re.sub(r'\s+', ' ', src).strip()
    r = call('declare_type', {'decls': src})
    ok = False
    for it in (r if isinstance(r, list) else []):
        if not it.get('error'):
            ok = True
        else:
            print('  declare_type err:', it.get('error')[:200], flush=True)
    return ok

def verify(addrs):
    bad = []
    probe = list(addrs[:2]) + ["0x6537b0"]
    for a in probe:
        try:
            r = call("decompile", {"addr": a, "include_addresses": False})
        except Exception as e:
            print(f"    !! decompile RPC died at {a}: {e}", flush=True)
            bad.append(a); continue
        code = ""
        if isinstance(r, list):
            code = "\n".join(x.get("code", "") for x in r if isinstance(x, dict))
        elif isinstance(r, dict):
            code = r.get("code") or ""
        if not code or any(m in code for m in BREAK_MARKERS):
            bad.append(a)
            print(f"    !! decompile broke at {a}", flush=True)
    return bad

def save_idb():
    r = call("idb_save", {})
    print(f"  idb_save -> {json.dumps(r)[:120]}", flush=True)

def main():
    mode = sys.argv[1] if len(sys.argv) > 1 else "all"
    addrs = [e[0] for e in EDITS]
    if mode in ("all", "snap"):
        print("== snapshot old prototypes", flush=True)
        old = snapshot(addrs)
        print(f"  {len(old)} protos on record", flush=True)

    if mode in ("all", "declare"):
        print("== declare FFX_BtlUIHud", flush=True)
        print("  ok:", declare_struct(), flush=True)
        save_idb()

    if mode in ("all", "apply"):
        print("== apply batches of 5 (save after each)", flush=True)
        apply_res = {}
        if os.path.exists("work/_btluihud/apply_res_r3.json"):
            apply_res = json.load(open("work/_btluihud/apply_res_r3.json"))
        for i in range(0, len(EDITS), 5):
            chunk = EDITS[i:i+5]
            edits = [{"addr": a, "signature": s} for a, s, _ in chunk]
            r = call("type_apply_batch", {"batch": {"edits": edits, "stop_on_error": False}})
            items = (r or {}).get("results") or []
            for it in items:
                a = (it.get("edit", {}).get("addr") or "").lower()
                apply_res[a] = {"ok": it.get("ok"), "error": it.get("error")}
            print(f"  batch {i//5}: applied={r.get('applied')} failed={r.get('failed')}", flush=True)
            for it in items:
                if not it.get("ok"):
                    print("    FAIL", it.get("edit",{}).get("addr"), it.get("error"), flush=True)
            json.dump(apply_res, open("work/_btluihud/apply_res_r3.json","w"), indent=1)
            save_idb()
            bad = verify([a for a,_,_ in chunk])
            if bad:
                print(f"  !! decompiler issue after batch {i//5} — STOPPING (types already saved)", flush=True)
                sys.exit(2)
            time.sleep(0.5)

    if mode in ("all", "comments"):
        print("== annotate comments", flush=True)
        items = [{"addr": a, "comment": f"[type-lift-r3] FFX_BtlUIHud (0x4068): {note}",
                  "scope": "func", "dedupe": True} for a, _, note in EDITS]
        call("append_comments", {"items": items})
        save_idb()

    print("== DONE", flush=True)

if __name__ == "__main__":
    main()
