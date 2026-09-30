#!/usr/bin/env bash
# Compile the Lua 5.2.1 candidate set on the Windows VM and fetch the disassembly.
set -euo pipefail
VM=${VM:-windows11-dev-next}
SDK=${SDK:-'/mnt/nvme-samsung/PSVITA SDK LEAk/PhyreEngine'}
HERE=$(cd "$(dirname "$0")" && pwd)

scp -q "$HERE/build_lua.bat" "$VM:C:/IDA_DB/build_lua.bat"
ssh "$VM" 'powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path C:/IDA_DB/lua/all | Out-Null"'
ssh "$VM" 'cmd /c "rd /s /q C:\IDA_DB\lua\all 2>nul & mkdir C:\IDA_DB\lua\all 2>nul"' || true
ssh "$VM" 'powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path C:/IDA_DB/lua/all | Out-Null"'
scp -q -r "$SDK/External/lua/src/"*.c "$SDK/External/lua/src/"*.h "$VM:C:/IDA_DB/lua/all/"
ssh "$VM" 'cmd /c C:\IDA_DB\build_lua.bat'
mkdir -p "$HERE/lua_all_out"
scp -q -r "$VM:C:/IDA_DB/lua/all/dis" "$HERE/lua_all_out/"
python3 "$HERE/definitive_match.py" "$HERE/lua_all_out/dis" "$HERE/inventory.tsv" "$HERE/../..//recon/lua/confirmed.json"
