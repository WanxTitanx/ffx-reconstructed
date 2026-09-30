#!/bin/bash
# helper: MCP JSON-RPC call (id auto)
ID=${3:-$$}
curl -s -m 60 -X POST http://192.168.122.85:8745/mcp \
  -H "Content-Type: application/json" -H "Accept: application/json, text/event-stream" \
  -d "{\"jsonrpc\":\"2.0\",\"id\":$ID,\"method\":\"tools/call\",\"params\":{\"name\":\"$1\",\"arguments\":$2}}"
