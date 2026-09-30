#!/bin/bash
# mcp.sh — one-shot MCP JSON-RPC call to idalib server (session-less: re-inits each time)
URL=http://192.168.122.85:8745/mcp
REQ=$(cat)
# initialize
INIT=$(curl -s -X POST "$URL" -H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream' \
  -d '{"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"yngm-unknown","version":"1.0"}}}')
SESS=$(echo "$INIT" | grep -i -o 'mcp-session-id: [^[:space:]]*' | head -1 | cut -d' ' -f2)
HDR=(-H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream')
[ -n "$SESS" ] && HDR+=(-H "mcp-session-id: $SESS")
# initialized notification
curl -s -X POST "$URL" "${HDR[@]}" -d '{"jsonrpc":"2.0","method":"notifications/initialized"}' > /dev/null
# actual call (stdin = full request object)
echo "$REQ" | curl -s -X POST "$URL" "${HDR[@]}" -d @- | sed -e 's/^data: //' | grep -v '^event:' | grep -v '^:ping' | grep -v '^$'
