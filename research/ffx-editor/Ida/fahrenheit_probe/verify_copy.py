#!/usr/bin/env python3
"""Verifica nomes aplicados na COPY (ffxoficial_COPY.i64) via RPC do IDA GUI."""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import mcp_call as mc  # noqa: E402


def main() -> int:
    mc.ensure_session()

    print("== lookup_funcs ==")
    r = mc.unwrap(mc.rpc("tools/call", {"name": "lookup_funcs",
                                        "arguments": {"queries": ["0x785000", "0x685950", "0xA572E0", "0xA53DE0", "0xA45010"]}}))
    print(json.dumps(r, indent=1, ensure_ascii=False)[:2500])

    print("== get_global_value (asmreg_vf0 @ 0xC0A004) ==")
    r = mc.unwrap(mc.rpc("tools/call", {"name": "get_global_value", "arguments": {"addr": "0xC0A004"}}))
    print(json.dumps(r, indent=1, ensure_ascii=False)[:1200])

    print("== type_query (lpamng @ 0x2305834) ==")
    r = mc.unwrap(mc.rpc("tools/call", {"name": "type_query", "arguments": {"addr": "0x2305834"}}))
    print(json.dumps(r, indent=1, ensure_ascii=False)[:1200])
    return 0


if __name__ == "__main__":
    sys.exit(main())
