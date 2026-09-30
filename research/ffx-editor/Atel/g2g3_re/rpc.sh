#!/bin/bash
# rpc.sh <payload-json> — POST to idalib MCP server
curl -s -m 300 http://192.168.122.85:8745/mcp \
  -H 'Content-Type: application/json' \
  -H 'Accept: application/json, text/event-stream' \
  -d "$1"
