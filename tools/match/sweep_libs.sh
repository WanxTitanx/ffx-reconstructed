#!/usr/bin/env bash
P='/mnt/nvme-samsung/PSVITA SDK LEAk/PhyreEngine/Lib/Win32'
EXE=/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe
OUT=sweep_results.txt
: > "$OUT"
for lib in lua.lib expat.lib squish.lib LinearMath.lib BulletCollision.lib BulletDynamics.lib BulletMultiThreaded.lib SceHeatWave.lib RecastNavigation.lib; do
  for v in vs2012 vs2013; do
    echo "### $lib $v $(date +%H:%M:%S)" >> "$OUT"
    timeout 1200 python3 -u lib_vs_exe.py "$P/$v/$lib" "$EXE" >> "$OUT" 2>&1
    echo "rc=$?" >> "$OUT"
  done
done
echo "SWEEP_DONE $(date)" >> "$OUT"
