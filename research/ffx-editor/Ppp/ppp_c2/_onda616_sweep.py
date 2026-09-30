import json, subprocess, sys, re
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 6.16: sweep automatizado dos SEM_PAYLOAD com addr — decompila e procura leituras de a2
# (payload = le a2+offset alem do id; infra = so usa a1/a3/estado)
path = r"work/magic_editor/field_map.json"
d = json.load(open(path, encoding="utf-8"))
fam = d.get("families", d)

cands = [(k, v.get("handler_addr")) for k, v in fam.items()
         if (v.get("status") or "") in ("FALTA_SCHEMA_SEM_PAYLOAD", "SEM_PAYLOAD")
         and v.get("handler_addr") and v.get("handler_addr") not in ("0x0", "0x728AC0")]

print(f"sweep de {len(cands)} SEM_PAYLOAD com addr...")
results = []
for k, addr in cands:
    try:
        r = subprocess.run(["python", "scripts/ida_mcp_client.py", "--port", "13337", "decompile", addr],
                           capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=30)
        out = r.stdout
        if not out:
            continue
        # procura leituras de a2 alem do match de id (a2+4 ou mais)
        a2reads = re.findall(r"a2\s*\+\s*(\d+)", out)
        a2idx = re.findall(r"a2\[(\d+)\]", out)
        all_reads = [int(x) for x in a2reads] + [int(x) * 4 for x in a2idx]
        max_read = max(all_reads) if all_reads else -1
        is_stub = "Stub function" in out or "nullsub" in out
        if max_read >= 4 or is_stub:
            results.append((k, addr, max_read, is_stub))
    except Exception as e:
        pass

print(f"\ncandidatos a revisar ({len(results)}):")
for k, addr, mx, stub in results:
    tag = "STUB" if stub else f"le a2+{mx}"
    print(f"  {k:22s} {addr:10s} {tag}")
