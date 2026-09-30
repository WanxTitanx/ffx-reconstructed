import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 7c: fecha os 38 restantes — KeThRes* = alocadores de recursos (SEM_PAYLOAD),
# DrawMatrixFrontLoop/WoodLoop = stub nullsub_643, KeShpTail3XImm = sem handler proprio
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

count = 0
for k, v in fam.items():
    if (v.get("status") or "") != "FALTA_SCHEMA_SEM_PAYLOAD":
        continue
    if k.startswith("pppKeThRes"):
        v["status"] = "SEM_PAYLOAD"
        v["payload_consumer"] = False
        v["usage"] = (v.get("usage") or "") + " [ONDA7c: alocador de recursos KeThRes (infraestrutura de memoria, sem payload de slot)]"
        count += 1
    elif k in ("pppDrawMatrixFrontLoop", "pppDrawMatrixWoodLoop"):
        v["status"] = "SEM_PAYLOAD"
        v["payload_consumer"] = False
        v["usage"] = (v.get("usage") or "") + " [ONDA7c: 0x728AC0 = nullsub_643 (STUB NO-OP)]"
        count += 1
    elif k == "pppKeShpTail3XImm":
        v["status"] = "SEM_PAYLOAD"
        v["payload_consumer"] = False
        v["usage"] = (v.get("usage") or "") + " [ONDA7c: sem handler proprio (variante Imm do 3X)]"
        count += 1

json.dump(d, open(path, "w", encoding="utf-8"), ensure_ascii=False, indent=1)
from collections import Counter
c = Counter((v.get("status") or '') for v in fam.values())
print(f"normalizados: {count}")
print("status FINAL:", dict(c))
print("total familias:", len(fam), "| FECHADO:", c.get('FECHADO', 0))
