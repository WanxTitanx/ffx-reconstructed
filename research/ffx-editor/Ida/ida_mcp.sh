#!/bin/bash
# ida_mcp.sh — one-shot MCP JSON-RPC call to the idalib/ida-pro-mcp server.
# Provenance: consolidated from per-lane work/_*/mcp.sh copies (2026-09-15, Jarvis-DEVIN).
# NOTE (Jarvis-MCP-LEGACY, 2026-09-18): kept as a curl convenience wrapper —
# LIVE callers exist in work/_*/ scripts in BOTH modes (arg mode:
# work/_sesep/mcp.sh, work/_btl/mcp.sh, work/_atel_tbl/{mcp,dump}.py,
# work/_dbgtbl/batch_{xrefs,decomp}.py, work/_grid/{dis,dc}.sh, work/_mgrp/mcp.py,
# work/_font/mcp.py, work/_pathstr/mcp.py; stdin mode: work/_grid/insn_scan.py).
# For Python work prefer the canonical client research_tools/ida_mcp_client.py
# (urllib transport, retry/backoff, session reuse, --selftest). Fold doc:
# docs/reverse/FFX_MCP_LEGACY_FOLD_2026-09-18.md
# usage: echo '<full request json>' | ida_mcp.sh        (reads request from stdin)
#    or: ida_mcp.sh '<tool>' '<args-json>'              (builds tools/call request)
# URL: env IDA_MCP_URL overrides the default VM endpoint.
URL="${IDA_MCP_URL:-http://192.168.122.85:8745/mcp}"
if [ -n "$1" ]; then
  REQ="{\"jsonrpc\":\"2.0\",\"id\":1,\"method\":\"tools/call\",\"params\":{\"name\":\"$1\",\"arguments\":${2:-\{\}}}}"
else
  REQ=$(cat)
fi
INIT=$(curl -s -i -X POST "$URL" -H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream' \
  -d '{"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"ida-mcp-cli","version":"1.0"}}}')
SESS=$(echo "$INIT" | tr -d '\r' | grep -i -o 'mcp-session-id: [^[:space:]]*' | head -1 | cut -d' ' -f2)
HDR=(-H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream')
[ -n "$SESS" ] && HDR+=(-H "mcp-session-id: $SESS")
curl -s -X POST "$URL" "${HDR[@]}" -d '{"jsonrpc":"2.0","method":"notifications/initialized"}' > /dev/null
echo "$REQ" | curl -s -X POST "$URL" "${HDR[@]}" -d @- | sed -e 's/^data: //' | grep -v '^event:' | grep -v '^:ping' | grep -v '^$'
