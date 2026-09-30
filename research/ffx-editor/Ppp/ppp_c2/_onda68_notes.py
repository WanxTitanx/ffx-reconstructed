import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.8 (GOAL 8h): FaceAp = stub no-op (nullsub_662) + EiZCrctDisPos addr errado
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

face = fam.get("pppFaceAp", {})
if face:
    face["status"] = "SEM_PAYLOAD"
    face["payload_consumer"] = False
    face["usage"] = (face.get("usage") or "") + " [ONDA6.8: 0x757FB0 = nullsub_662 (STUB NO-OP no PC — handler desativado, sem efeito)]"

ei = fam.get("pppEiZCrctDisPos", {})
if ei:
    ei["status"] = "SEM_PAYLOAD"
    ei["payload_consumer"] = False
    ei["usage"] = (ei.get("usage") or "") + " [ONDA6.8: addr 0x735FA0 = Menu2D_ProjectWithOffsets (funcao de menu 2D, NAO handler) — addr errado no field_map]"

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
print("FaceAp stub no-op + EiZCrctDisPos addr corrigido — notas aplicadas")
