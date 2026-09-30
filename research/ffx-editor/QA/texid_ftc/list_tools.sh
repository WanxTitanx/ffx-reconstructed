#!/bin/bash
URL=http://192.168.122.85:8745/mcp
INIT=$(curl -s -i -X POST "$URL" -H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream' \
  -d '{"jsonrpc":"2.0","id":1,"method":"initialize","params":{"protocolVersion":"2025-03-26","capabilities":{},"clientInfo":{"name":"texid-ftc","version":"1.0"}}}')
SESS=$(echo "$INIT" | tr -d '\r' | grep -i -o 'mcp-session-id: [^[:space:]]*' | head -1 | cut -d' ' -f2)
HDR=(-H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream')
[ -n "$SESS" ] && HDR+=(-H "mcp-session-id: $SESS")
curl -s -X POST "$URL" "${HDR[@]}" -d '{"jsonrpc":"2.0","method":"notifications/initialized"}' > /dev/null
curl -s -X POST "$URL" "${HDR[@]}" -d '{"jsonrpc":"2.0","id":2,"method":"tools/list","params":{}}' | sed -e 's/^data: //' | grep -v '^event:' | grep -v '^:ping' | grep -v '^$'
