#!/usr/bin/env bash
P='/mnt/nvme-samsung/PSVITA SDK LEAk/PhyreEngine/Lib/Win32'
EXE=/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe
for spec in expat.lib:vs2012 expat.lib:vs2013 squish.lib:vs2012 squish.lib:vs2013 LinearMath.lib:vs2012 LinearMath.lib:vs2013 BulletCollision.lib:vs2012 BulletCollision.lib:vs2013 BulletDynamics.lib:vs2012 BulletDynamics.lib:vs2013 BulletMultiThreaded.lib:vs2012 BulletMultiThreaded.lib:vs2013 SceHeatWave.lib:vs2012 SceHeatWave.lib:vs2013 RecastNavigation.lib:vs2012 RecastNavigation.lib:vs2013 lua.lib:vs2012 lua.lib:vs2013; do
  lib=${spec%%:*}
  v=${spec##*:}
  echo "### $lib $v $(date +%H:%M:%S)"
  timeout 3000 python3 -u lib_vs_exe.py "$P/$v/$lib" "$EXE" 2>&1 | grep -E 'sections examined|bytes examined|agreement|identical'
done
echo "SWEEP3_DONE $(date)"
