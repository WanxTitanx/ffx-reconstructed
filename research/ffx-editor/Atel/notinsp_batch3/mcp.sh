#!/bin/bash
# JSON-RPC helper for ida-pro-mcp @ 192.168.122.85:8745 (NOT-INSPECTED batch3, session via cookie-less single-worker)
URL=http://192.168.122.85:8745/mcp
ID_FILE=/home/wanderson/Documents/ffx-editor-main/work/_notinsp_batch3/.rpc_id
ID=$(( $(cat "$ID_FILE" 2>/dev/null || echo 100) + 1 )); echo $ID > "$ID_FILE"
NAME="$1"; ARGS="$2"
curl -s -m 300 -X POST "$URL" -H 'Content-Type: application/json' -H 'Accept: application/json, text/event-stream' \
  -d "{\"jsonrpc\":\"2.0\",\"id\":$ID,\"method\":\"tools/call\",\"params\":{\"name\":\"$NAME\",\"arguments\":$ARGS}}"
