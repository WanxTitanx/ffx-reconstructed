import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 7b: normaliza os INFRA confirmados pelos sweeps (classificacao final)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

infra_confirmados = {
    "pppDrawMatrixLoop": "so a1 (flag a1+156 e projecao de node)",
    "pppDrawMatrixNoRot": "offset transform so em a3[32..34]+globais",
    "pppDrawMatrixWood": "setup projecao/copia so em a3",
    "pppKeDMat": "FFX_MagicHost_CopyProjectedMatrix — projeta+copia matriz, sem payload",
    "pppKeDMatFr": "setup matriz child transform HUD",
    "pppKeDMatPht": "projeta no portrait + copy transform",
    "pppKeDMatPhtFr": "projeta no ex (2 offsets do fp.h)",
    "pppKeLnsLpSft": "so le a2[0]=target id; acumula transform nos nos internos",
    "pppKeShpTail": "push transform node; nao le a2",
    "pppKeShpTail2": "idem Tail (push transform node, sem payload)",
    "pppKeShpTail2X": "idem Tail (push transform node, sem payload)",
    "pppKeShpTailX": "push transform node TypeB; a2 nunca lido",
    "pppDrawShapeRev": "node base a2; slot control em a3 (tex_id/timing/flags)",
    "pppKeMvYpEff": "atan2 sobre estado do no(a1); nao toca a2",
    "pppMatrixLoc": "copia posicao de referencia do node p/ estado; a2 nao lido",
    "pppMatrixLoop": "build Euler matrix to global a partir de node/estado; a2 nao lido",
    "pppMatrixXZY": "ApplyEulerYZXTransform; a2 nao lido",
    "pppMatrixYXZ": "ApplyEulerZXYTransform; a2 nao lido",
    "pppMatrixZXY": "ApplyEulerYXZTransform; a2 nao lido",
}

for op, desc in infra_confirmados.items():
    v = fam.get(op)
    if v:
        v["status"] = "SEM_PAYLOAD"
        v["payload_consumer"] = False
        v["editable"] = False
        v["window"] = None
        v["usage"] = (v.get("usage") or "") + f" [ONDA7b sweep: INFRA — {desc}]"

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
emb = {k: v for k, v in fam.items() if v.get("payload_consumer")}
json.dump(emb, open(r"work/magic_editor/_embedded_families.json", "w", encoding="ascii"), ensure_ascii=True, indent=1)
print(f"INFRA normalizados: {len(infra_confirmados)} | embedded: {len(emb)}")

from collections import Counter
c = Counter((v.get("status") or '') for v in fam.values())
print("status:", dict(c))
