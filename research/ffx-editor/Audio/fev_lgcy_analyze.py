import struct, sys

sys.stdout.reconfigure(encoding='utf-8', errors='replace')

def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def u16(d, o): return struct.unpack_from('<H', d, o)[0]

def read_fev_string(d, o):
    ln = u32(d, o)
    if ln == 0:
        return "", o + 4
    s = d[o+4 : o+4+ln-1].decode('ascii', 'replace')
    return s, o + 4 + ln

def main(path):
    d = open(path, 'rb').read()
    print(f"file size: {len(d)}")
    assert d[0:4] == b'RIFF' and d[8:12] == b'FEV '
    ver = u32(d, 0x14)
    print(f"FEV version: 0x{ver:08X}")

    pos = 0x0C
    lgcy = None
    while pos + 8 <= len(d):
        cid = d[pos:pos+4]
        sz = u32(d, pos+4)
        print(f"chunk {cid!r} at 0x{pos:X} size={sz}")
        if cid == b'LIST':
            sub = pos + 8
            stype = d[sub:sub+4]
            print(f"  LIST type {stype!r}")
            sub += 4
            while sub + 8 <= pos + 8 + sz:
                scid = d[sub:sub+4]
                ssz = u32(d, sub+4)
                print(f"  subchunk {scid!r} at 0x{sub:X} size={ssz}")
                if scid == b'LGCY':
                    lgcy = (sub+8, ssz)
                sub += 8 + ssz + (ssz & 1)
        pos += 8 + sz + (sz & 1)

    lo, lsz = lgcy
    print(f"\n=== LGCY body at 0x{lo:X} size={lsz} ===")
    o = lo
    end = lo + lsz

    sdp = u32(d, o); o += 4
    sdp64 = u32(d, o); o += 4
    print(f"soundDefPoolSize   = {sdp} (0x{sdp:X})  /24 = {sdp/24 if sdp%24==0 else '?'}")
    print(f"soundDef64PoolSize = {sdp64} (0x{sdp64:X}) /32 = {sdp64/32 if sdp64%32==0 else '?'}")

    bankname, o = read_fev_string(d, o)
    print(f"bank name: {bankname!r} (next 0x{o:X})")

    wave_banks = u32(d, o); o += 4
    languages = u32(d, o); o += 4
    print(f"waveBanks={wave_banks} languages={languages}")

    # FIX 2026-09-16 (FMT-AUDIO audit): wavebank entry carries a u64 content hash
    # + u32 suffix between maxStreams and the name string — the old layout read
    # the name over the hash bytes and desynced the whole LGCY walk (crash in
    # parse_category). Verified vs ffx_music.fev LGCY @0x174:
    #   mode=0x80 maxStreams=10 hash=0xCD6B5B29B151A767 suffix=0 name='ffx_music_bank00'.
    for i in range(wave_banks):
        wb_off = o
        mode = u32(d, o); o += 4
        max_streams = u32(d, o); o += 4
        h = u32(d, o) | (u32(d, o + 4) << 32); o += 8
        suffix = u32(d, o); o += 4
        name, o = read_fev_string(d, o)
        print(f"  wavebank[{i}] at 0x{wb_off:X}: mode=0x{mode:08X} maxStreams={max_streams} hash=0x{h:016X} suffix={suffix} name={name!r}")

    # NOTE 2026-09-16: the LGCY block does NOT carry language name strings —
    # those live in the LANG chunk (count + len-prefixed names, e.g. 'default').
    # The string right after the wavebank table is the ROOT CATEGORY name
    # ('master' in FMOD convention), consumed below by parse_category.

    # FIX 2026-09-16 (FMT-AUDIO audit): wavebank entries include hash u64 +
    # suffix u32 (fixed above); the category root is NAMED ('master' — FMOD
    # convention; the string the old layout swallowed as a wavebank name was
    # actually this). Tree verified vs ffx_music.fev: master -> music.
    def parse_category(o, depth):
        name, o = read_fev_string(d, o)
        vol = u32(d, o); o += 4
        pitch = u32(d, o); o += 4
        mp = u32(d, o); o += 4
        mpf = u32(d, o); o += 4
        sub = u32(d, o); o += 4
        print(f"{'  '*depth}category {name!r} vol={vol} pitch={pitch} maxPlaybacks={mp} flags={mpf} subCats={sub}")
        for j in range(sub):
            o = parse_category(o, depth+1)
        return o

    o = parse_category(o, 0)
    print(f"after category tree: 0x{o:X}")

    event_groups = u32(d, o); o += 4
    print(f"eventGroups={event_groups}")

    # FIX 2026-09-16 (FMT-AUDIO audit): the v0x45 event region is a FLAT list of
    # records, each anchored by a {u32 guidLen==16, u32 objIndex, byte[16] guid}
    # triple where objIndex is a global sequential index starting at 2.
    #   - group header records are UNNAMED: {u32=1, u32 nameLen?, u32, u32 recCount,
    #     16, objIdx, guid, params}; an empty group can be just 4 u32s.
    #   - event records carry a fevstring label first ('master' = the mixer
    #     category every FFX event sits in), then {16, objIdx, guid, params}.
    #   - header field3 = record count INCLUDING the group header itself
    #     (ffx_music.fev: 89 = idx 2..90 = exactly 89 FSB samples;
    #     0201.fev: group2 count=20 = 20 FSB samples; 0000.fev: ~1366 records
    #     for a 1365-sample bank).
    # Per-record param blocks are variable-size (~210B for simple events, larger
    # for layered ones) and NOT yet field-decoded -> semantic walk is PARTIAL.
    # The walker below enumerates records via the anchor pattern, which is
    # robust to unknown param layouts. Named label is recovered by looking
    # backwards for the fevstring that ends exactly at the anchor.
    def is_uuid(o2):
        if o2 + 16 > end: return False
        s3 = u16(d, o2 + 6); s4 = (d[o2 + 8] << 8) | d[o2 + 9]
        return (s3 & 0xF000) == 0x4000 and 0x8000 <= s4 <= 0xBFFF

    def label_before(anchor):
        # fevstring ends right before `anchor` minus the fields between name and
        # guidLen that group headers carry; try the simple name-first case and
        # also scanning back up to 48B for a plausible len-prefixed string.
        for back in range(0, 48):
            s0 = anchor - back
            if s0 < o: break
            if s0 + 4 > anchor: continue
            nl = u32(d, s0)
            if 1 <= nl <= 40 and s0 + 4 + nl == anchor:
                nm = d[s0+4:s0+4+nl]
                if nm.endswith(b'\x00') and all(32 <= b < 127 or b == 0 for b in nm[:-1]):
                    return nm[:-1].decode('ascii', 'replace')
        return None

    anchors = []
    scan = o
    # Records are NOT u32-aligned: fevstring name prefixes have arbitrary byte
    # lengths, so the {16, idx, guid} anchor can start at any byte offset.
    while scan + 24 <= end:
        if u32(d, scan) == 16 and is_uuid(scan + 8):
            anchors.append((scan, u32(d, scan + 4)))
            scan += 24
        else:
            scan += 1
    print(f"event/group records: {len(anchors)} anchors")
    if anchors:
        idxs = [a[1] for a in anchors]
        contiguous = all(idxs[i] == idxs[i-1] + 1 for i in range(1, len(idxs)))
        named = sum(1 for a, _ in anchors if label_before(a) is not None)
        print(f"  objIndex {idxs[0]}..{idxs[-1]} contiguous={contiguous} labeled={named} unnamed={len(anchors)-named}")
        labels = {}
        for a, ix in anchors:
            lab = label_before(a)
            if lab is not None: labels[lab] = labels.get(lab, 0) + 1
        for lab, n in sorted(labels.items(), key=lambda kv: -kv[1])[:8]:
            print(f"  label {lab!r}: {n} records")
        gaps = [(idxs[i-1], idxs[i], hex(anchors[i][0])) for i in range(1, len(idxs)) if idxs[i] != idxs[i-1] + 1]
        if gaps:
            print(f"  index gaps (unnamed headers or non-v4 guids): {gaps[:10]}")
        print(f"  NOTE: per-record param blocks (~0xD0+ bytes) are structurally opaque — PARTIAL")

    print(f"LGCY end: 0x{end:X}")

if __name__ == '__main__':
    main(sys.argv[1])
