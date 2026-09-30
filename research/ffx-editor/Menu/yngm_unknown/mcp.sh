#!/bin/bash
# mcp.sh — one-shot MCP JSON-RPC call to the ida-pro-mcp/idalib server.
# usage: echo '<full request json>' | mcp.sh        (reads request from stdin)
#    or: mcp.sh '<tool>' '<args-json>'              (builds tools/call request)
URL=http://192.168.122.85:8745/mcp
if [ -n "$1" ]; then
  REQ="{\"jsonrpc\":\"2.0\",\"id\":1,\"method\":\"tools/call\",\"params\":{\"name\":\"$1\",\"arguments\":${2:-\{\}}}}"
else
  REQ=$(cat)
fi
INIT=$(curl -s -i -X POST "$URL" -H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream' \
  -d '{"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"yngm-unknown","version":"1.0"}}}')
SESS=$(echo "$INIT" | tr -d '\r' | grep -i -o 'mcp-session-id: [^[:space:]]*' | head -1 | cut -d' ' -f2)
HDR=(-H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream')
[ -n "$SESS" ] && HDR+=(-H "mcp-session-id: $SESS")
curl -s -X POST "$URL" "${HDR[@]}" -d '{"jsonrpc":"2.0","method":"notifications/initialized"}' > /dev/null
echo "$REQ" | curl -s -X POST "$URL" "${HDR[@]}" -d @- | sed -e 's/^data: //' | grep -v '^event:' | grep -v '^:ping' | grep -v '^$'
