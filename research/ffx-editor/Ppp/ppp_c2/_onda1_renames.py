import json, subprocess, sys

# Renames na DB canonica (regra de ouro IDA) — 2026-08-02 Onda 1
# Funcoes ja renomeadas pela comunidade/sessao anterior (FFX_PppHandler_Rand*), mas os
# KeMdlTfdUv* ainda estavam com nome generico (FFX_KR_AccumulateTableOffset_*).
renames = {
    "0x74a0c0": "FFX_PppHandler_KeMdlTfdUv3",
    "0x749d60": "FFX_PppHandler_KeMdlTfdUv2",
}

batch = {"globals": [{"addr": a, "name": n} for a, n in renames.items()]}
r = subprocess.run(
    ["python", "scripts/ida_mcp_client.py", "--port", "13337", "rename", json.dumps(batch)],
    capture_output=True, text=True, encoding="utf-8", errors="replace")
print("STDOUT:", r.stdout[-800:])
print("STDERR:", r.stderr[-400:])
