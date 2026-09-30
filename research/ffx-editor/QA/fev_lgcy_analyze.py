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

    for i in range(wave_banks):
        wb_off = o
        mode = u32(d, o); o += 4
        max_streams = u32(d, o); o += 4
        name, o = read_fev_string(d, o)
        print(f"  wavebank[{i}] at 0x{wb_off:X}: mode=0x{mode:08X} maxStreams={max_streams} name={name!r}")

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

    def parse_event_sound(o, depth):
        name_idx = u16(d, o); o += 2
        o += 0x08
        o += 0x04
        o += 0x04
        o += 0x04
        o += 0x08
        o += 0x04
        o += 0x04
        o += 0x08
        o += 0x0C
        o += 0x08
        print(f"{'  '*depth}  sound nameIdx={name_idx}")
        return o

    def parse_event_envelope(o, depth):
        o += 0x04
        dsp, o = read_fev_string(d, o)
        o += 0x04
        o += 0x04
        o += 0x04
        points = u32(d, o); o += 4
        o += points * 0x08
        o += points * 0x04
        o += 0x04
        o += 0x04
        print(f"{'  '*depth}  envelope dsp={dsp!r} points={points}")
        return o

    def parse_event_complex(o, depth):
        layers = u32(d, o); o += 4
        print(f"{'  '*depth}complex layers={layers}")
        for i in range(layers):
            o += 0x02
            o += 0x02
            o += 0x02
            o += 0x02
            sounds = u16(d, o); o += 2
            envelopes = u16(d, o); o += 2
            for j in range(sounds):
                o = parse_event_sound(o, depth+1)
            for j in range(envelopes):
                o = parse_event_envelope(o, depth+1)
        params = u32(d, o); o += 4
        for i in range(params):
            pname, o = read_fev_string(d, o)
            o += 0x10
            o += 0x04
            o += 0x04
            sust = u32(d, o); o += 4
            o += sust * 0x04
        props = u32(d, o); o += 4
        for i in range(props):
            pname, o = read_fev_string(d, o)
            ptype = u32(d, o); o += 4
            if ptype == 2:
                pval, o = read_fev_string(d, o)
            else:
                pval = u32(d, o); o += 4
        return o

    def parse_event_simple(o, depth):
        o += 0x04
        o = parse_event_sound(o, depth+1)
        return o

    def parse_event(o, depth):
        ev_off = o
        etype = u32(d, o); o += 4
        name, o = read_fev_string(d, o)
        o += 0x08
        o += 0x04
        o += 0x04
        o += 0x04
        o += 0x04
        o += 0x04
        o += 0x0C
        o += 0x08
        o += 0x04
        o += 0x2C
        o += 0x08
        o += 0x08
        o += 0x04
        o += 0x08
        o += 0x08
        o += 0x04
        o += 0x04
        o += 0x04
        print(f"{'  '*depth}event at 0x{ev_off:X}: type=0x{etype:08X} name={name!r}")
        if (etype & 0x18) == 0x08:
            o = parse_event_complex(o, depth+1)
        elif (etype & 0x18) == 0x10:
            o = parse_event_simple(o, depth+1)
        else:
            print(f"{'  '*depth}  !! unknown event type 0x{etype:08X}")
        cats = u32(d, o); o += 4
        for i in range(cats):
            cname, o = read_fev_string(d, o)
        return o

    def parse_event_category(o, depth):
        name, o = read_fev_string(d, o)
        props = u32(d, o); o += 4
        for i in range(props):
            pname, o = read_fev_string(d, o)
            ptype = u32(d, o); o += 4
            if ptype == 2:
                pval, o = read_fev_string(d, o)
            else:
                pval = u32(d, o); o += 4
        sub_groups = u32(d, o); o += 4
        events = u32(d, o); o += 4
        print(f"{'  '*depth}eventCategory {name!r} subGroups={sub_groups} events={events}")
        for j in range(sub_groups):
            o = parse_event_category(o, depth+1)
        for j in range(events):
            o = parse_event(o, depth+1)
        return o

    for i in range(event_groups):
        o = parse_event_category(o, 0)

    print(f"after event groups: 0x{o:X}")

    sound_defs = u32(d, o); o += 4
    print(f"soundDefs={sound_defs}")

    def parse_sound_def(o, depth):
        sd_off = o
        name, o = read_fev_string(d, o)
        o += 0x08
        o += 0x04
        o += 0x08
        o += 0x04
        o += 0x08
        o += 0x04
        o += 0x04
        o += 0x04
        o += 0x08
        o += 0x04
        entries = u32(d, o); o += 4
        print(f"{'  '*depth}soundDef at 0x{sd_off:X}: {name!r} entries={entries}")
        for i in range(entries):
            e_off = o
            etype = u32(d, o); o += 4
            weight = u32(d, o); o += 4
            if etype == 0:
                stream_name, o = read_fev_string(d, o)
                bank_name, o = read_fev_string(d, o)
                stream_index = u32(d, o); o += 4
                ms = u32(d, o); o += 4
                print(f"{'  '*depth}  entry[{i}] at 0x{e_off:X}: type=0 wavetable stream={stream_name!r} bank={bank_name!r} index={stream_index} lenMs={ms}")
            elif etype == 1:
                o += 0x08
                print(f"{'  '*depth}  entry[{i}] at 0x{e_off:X}: type=1 oscillator")
            elif etype in (2, 3):
                print(f"{'  '*depth}  entry[{i}] at 0x{e_off:X}: type={etype}")
            else:
                print(f"{'  '*depth}  entry[{i}] at 0x{e_off:X}: !! unknown type {etype}")
        return o

    for i in range(sound_defs):
        o = parse_sound_def(o, 0)

    print(f"after sound defs: 0x{o:X}")

    reverb_defs = u32(d, o); o += 4
    print(f"reverbDefs={reverb_defs}")
    for i in range(reverb_defs):
        name, o = read_fev_string(d, o)
        o += 0x30
        o += 0x08
        o += 0x4C
        print(f"  reverbDef[{i}] {name!r}")

    print(f"after reverb defs: 0x{o:X}")
    print(f"LGCY end: 0x{end:X}, remaining bytes: {end - o}")
    if end - o > 0:
        print(f"  remaining: {d[o:o+min(64, end-o)].hex(' ')}")
        for marker in [b'comp', b'sett', b'lnks', b'cues', b'prms', b'scns', b'thms', b'tlns', b'sgms']:
            idx = d.find(marker, o, end)
            if idx >= 0:
                print(f"  marker {marker!r} found at 0x{idx:X}")

if __name__ == '__main__':
    main(sys.argv[1])
