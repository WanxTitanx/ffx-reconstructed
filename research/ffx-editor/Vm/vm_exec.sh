#!/bin/bash
# vm_exec.sh — run a command on windows11-dev-next via QGA and print output
# Usage: vm_exec.sh "command string" [max_wait_seconds]
# NOTE: this QGA build reaps finished children fast and its guest-exec-status
# error leaks the format string ("PID lld does not exist") — so we poll
# immediately and often, collecting the cumulative out-data on the way.
VM=windows11-dev-next
MAXW=${2:-20}
ARGS=$(python3 -c 'import json,sys; print(json.dumps({"path":"cmd.exe","arg":["/c",sys.argv[1]],"capture-output":True}))' "$1")
RESP=$(virsh -c qemu:///system qemu-agent-command $VM "{\"execute\":\"guest-exec\",\"arguments\":$ARGS}")
PID=$(echo "$RESP" | python3 -c 'import sys,json; print(json.load(sys.stdin)["return"]["pid"])')
OUT=""
DEADLINE=$((SECONDS+MAXW))
while [ $SECONDS -lt $DEADLINE ]; do
  OUT=$(virsh -c qemu:///system qemu-agent-command $VM "{\"execute\":\"guest-exec-status\",\"arguments\":{\"pid\":$PID}}" 2>/dev/null)
  if echo "$OUT" | grep -q '"exited": *true'; then break; fi
  if [ -z "$OUT" ]; then break; fi   # reaped/unknown: use last good OUT
  sleep 0.4
done
echo "$OUT" | python3 -c 'import sys,json,base64; d=json.load(sys.stdin)["return"]; print(base64.b64decode(d.get("out-data","")).decode("utf-8","replace"),end=""); print(base64.b64decode(d.get("err-data","")).decode("utf-8","replace"),end="")'
