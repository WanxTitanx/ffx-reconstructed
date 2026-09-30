import struct, sys

def u32(d, o): return struct.unpack_from('<I', d, o)[0]
def u16(d, o): return struct.unpack_from('<H', d, o)[0]
def u8(d, o): return d[o]

def read_fev_string(d, o):
    ln = u32(d, o)
    if ln == 0:
        return "", o + 4
    s = d[o+4 : o+4+ln-1].decode('ascii', 'replace')
    return s, o + 4 + ln

def is_uuid(d, o):
    if o + 16 > len(d): return False
    seg1 = u32(d, o); seg2 = u16(d, o+4); seg3 = u16(d, o+6); seg4 = (d[o+8]<<8)|d[o+9]
    if seg1 == 0 or seg2 == 0 or seg3 == 0 or seg4 == 0: return False
    if (seg3 & 0xF000) != 0x4000: return False
    if (seg4 & 0xF000) < 0x8000 or (seg4 & 0xF000) > 0xB000: return False
    return True

def find_lgcy(d):
    """Locate the LGCY sub-chunk inside LIST/PROJ (word-aligned RIFF walk).
    FIX 2026-09-16 (FMT-AUDIO audit): replaces the hardcoded body=0x152 /
    size=403997 constants that only matched one specific file."""
    pos = 0x0C
    while pos + 8 <= len(d):
        cid = d[pos:pos+4]
        sz = u32(d, pos+4)
        if cid == b'LIST':
            sub = pos + 8
            sub += 4  # skip list type (PROJ)
            lend = pos + 8 + sz
            while sub + 8 <= lend:
                scid = d[sub:sub+4]
                ssz = u32(d, sub+4)
                if scid == b'LGCY':
                    return sub + 8, sub + 8 + ssz
                sub += 8 + ssz + (ssz & 1)
        pos += 8 + sz + (sz & 1)
    return None, None

def main(path):
    d = open(path, 'rb').read()
    body, end = find_lgcy(d)
    if body is None:
        print("no LGCY chunk found")
        return
    print(f"LGCY body=0x{body:X} end=0x{end:X} size={end-body}")
    o = body

    sdp = u32(d, o); o += 4
    sdp64 = u32(d, o); o += 4
    print(f"soundDefPoolSize={sdp} soundDef64PoolSize={sdp64}")
    bankname, o = read_fev_string(d, o)
    print(f"bankName={bankname!r}")
    wave_banks = u32(d, o); o += 4
    languages = u32(d, o); o += 4
    print(f"waveBanks={wave_banks} languages={languages}")
    for i in range(wave_banks):
        mode = u32(d, o); o += 4
        ms = u32(d, o); o += 4
        h = u32(d, o) | (u32(d, o+4) << 32); o += 8
        suffix = u32(d, o); o += 4
        name, o = read_fev_string(d, o)
        print(f"  wavebank[{i}] mode=0x{mode:08X} maxStreams={ms} hash=0x{h:016X} suffix={suffix} name={name!r}")

    def parse_category(o, depth):
        name, o = read_fev_string(d, o)
        vol = u32(d, o); o += 4
        pitch = u32(d, o); o += 4
        mp = u32(d, o); o += 4
        mpf = u32(d, o); o += 4
        sub = u32(d, o); o += 4
        print(f"{'  '*depth}category {name!r} vol={vol} pitch={pitch} mp={mp} flags={mpf} subCats={sub}")
        for j in range(sub):
            o = parse_category(o, depth+1)
        return o

    o = parse_category(o, 0)
    print(f"after category tree: 0x{o:X}")

    event_groups = u32(d, o); o += 4
    print(f"eventGroups={event_groups}")

    # FIX 2026-09-16 (FMT-AUDIO audit): v0x45 stores the event region as a FLAT
    # list of records anchored by {u32 guidLen==16, u32 objIndex, byte[16] guid}
    # where objIndex is global-sequential from 2. Group headers are unnamed
    # ({u32=1, u32 nameLen?, u32, u32 recCount, 16, idx, guid, params}; the
    # recCount field includes the header itself — ffx_music.fev 89 = idx 2..90
    # = 89 FSB samples; 0201.fev group2 count 20 = 20 FSB samples). Event
    # records prepend a fevstring label ('master' = the mixer category every
    # FFX event uses). Param blocks are variable-size and not field-decoded
    # (PARTIAL). Old nested category/event/sounddef walk was file-specific and
    # desynced on real data; replaced by this bounded anchor enumeration.
    def is_uuid2(o2):
        if o2 + 16 > end: return False
        s3 = u16(d, o2 + 6); s4 = (d[o2 + 8] << 8) | d[o2 + 9]
        return (s3 & 0xF000) == 0x4000 and 0x8000 <= s4 <= 0xBFFF

    def label_before(anchor):
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
    while scan + 24 <= end:  # byte-stepped: anchors can sit at odd offsets
        if u32(d, scan) == 16 and is_uuid2(scan + 8):
            anchors.append((scan, u32(d, scan + 4)))
            scan += 24
        else:
            scan += 1

    print(f"event/group records: {len(anchors)} anchors")
    if anchors:
        idxs = [a[1] for a in anchors]
        contiguous = all(idxs[i] == idxs[i-1] + 1 for i in range(1, len(idxs)))
        labels = {}
        for a, ix in anchors:
            lab = label_before(a)
            if lab is not None: labels[lab] = labels.get(lab, 0) + 1
        named = sum(labels.values())
        print(f"  objIndex {idxs[0]}..{idxs[-1]} contiguous={contiguous} labeled={named} unnamed={len(anchors)-named}")
        for lab, n in sorted(labels.items(), key=lambda kv: -kv[1])[:8]:
            print(f"  label {lab!r}: {n} records")
        gaps = [(idxs[i-1], idxs[i], hex(anchors[i][0])) for i in range(1, len(idxs)) if idxs[i] != idxs[i-1] + 1]
        if gaps:
            print(f"  index gaps (group headers / non-v4 guids): {gaps[:10]}")
        print("  per-record param blocks are opaque (PARTIAL)")

    print(f"LGCY end: 0x{end:X}")

if __name__ == '__main__':
    main(sys.argv[1])
