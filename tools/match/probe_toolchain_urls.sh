#!/usr/bin/env bash
# Probe every plausible public source for the VS2012 (v110) C++ compiler.
#
# The target's Rich header build 50727 and linker 11.00.50727 both point at
# VS2012, so reproducing its codegen needs that exact toolchain. This script
# only checks reachability; it downloads nothing.

set -u

declare -a urls=(
    # VS2012 Update 5 offline ISOs historically served from download.microsoft.com
    "https://download.microsoft.com/download/5/E/A/5EA7D6B4-1C6B-4C36-B1C5-0B1D0E8DF8A6/VS2012_ULT_enu.iso"
    "https://download.microsoft.com/download/B/1/4/B143D10E-B4C4-4C63-A84E-CD4D3BBC4E7C/VS2012_ULT_enu.iso"
    # VS2012 express / wdexpress web installers
    "https://download.microsoft.com/download/8/6/A/86A6E8A7-2E7B-4A2C-9D2A-0B7EE7E7B4E6/wdexpress_full.exe"
    # VS2012 Update 4/5 patch packages
    "https://download.microsoft.com/download/4/1/6/416C1A4C-1C31-4B29-9C9F-1B6EE7D7AA4C/VS2012.5.iso"
    # VS2013 (shipped in the VS2012-era line, still 12.0 not 11.0)
    "https://download.microsoft.com/download/9/2/1/9210C2C1-BD48-4A0D-9C79-1F6A4B9F1E37/VS2013_RTM_ULT_ENU.iso"
    # Build tools / old SDKs
    "https://download.microsoft.com/download/E/B/A/EBA0EC9D-8F86-4C4C-9C79-9FF1E13F0F7A/SDKSETUP.EXE"
    # Azure-hosted VS2017/2019 bootstrappers (context)
    "https://aka.ms/vs/15/release/vs_buildtools.exe"
    "https://aka.ms/vs/16/release/vs_buildtools.exe"
    "https://aka.ms/vs/17/release/vs_buildtools.exe"
)

for u in "${urls[@]}"; do
    code=$(curl -s -o /dev/null -w '%{http_code} %{size_download}' -I -L --max-time 25 "$u" 2>/dev/null || echo "000 0")
    printf '%-110s %s\n' "$u" "$code"
done

echo
echo '=== VS2017 (15) catalog probe for v110 ==='
python3 - <<'PY' 2>&1 | tail -20
import json, re, urllib.request
try:
    ch = json.loads(urllib.request.urlopen(
        urllib.request.Request('https://aka.ms/vs/15/release/channel',
                               headers={'User-Agent': 'curl/8'}), timeout=60).read())
    url = [i for i in ch['channelItems'] if i['id'].endswith('Manifests.VisualStudio')][0]['payloads'][0]['url']
    data = urllib.request.urlopen(urllib.request.Request(url, headers={'User-Agent': 'curl/8'}), timeout=240).read()
    cat = json.loads(data)
    print('packages:', len(cat['packages']))
    hits = [p['id'] for p in cat['packages'] if re.search(r'v110|VS2012|\.11\.0\.', p.get('id', ''), re.I)]
    print('v110 candidates:', len(hits))
    for h in hits[:30]:
        print('  ', h)
except Exception as exc:
    print('probe failed:', exc)
PY
