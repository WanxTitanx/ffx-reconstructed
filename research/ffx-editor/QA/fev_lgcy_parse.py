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

def main(path):
    d = open(path, 'rb').read()
    body = 0x152
    end = body + 403997
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
        name_idx = u32(d, o); o += 4
        # optional extra field: check if next 16 bytes are a valid uuid
        if is_uuid(d, o):
            uuid_off = o
        else:
            extra = u32(d, o); o += 4
            uuid_off = o
            print(f"{'  '*depth}  !! extra field {extra} at 0x{ev_off:X}+8")
        uuid = d[uuid_off:uuid_off+16].hex()
        o = uuid_off + 16
        # params 0x90
        o += 0x90
        print(f"{'  '*depth}event at 0x{ev_off:X}: type=0x{etype:08X} nameIdx={name_idx} uuid={uuid[:8]}...")
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
        vol = u32(d, o); o += 4
        pitch = u32(d, o); o += 4
        mp = u32(d, o); o += 4
        mpf = u32(d, o); o += 4
        sub_groups = u32(d, o); o += 4
        events = u32(d, o); o += 4
        print(f"{'  '*depth}eventCategory {name!r} vol={vol} pitch={pitch} mp={mp} flags={mpf} subGroups={sub_groups} events={events}")
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
        o += 0x30
        entries = u32(d, o); o += 4
        print(f"{'  '*depth}soundDef at 0x{sd_off:X}: {name!r} entries={entries}")
        for i in range(entries):
            e_off = o
            stream_name, o = read_fev_string(d, o)
            bank_name, o = read_fev_string(d, o)
            stream_index = u32(d, o); o += 4
            ms = u32(d, o); o += 4
            x = u32(d, o); o += 4
            z1 = u32(d, o); o += 4
            z2 = u32(d, o); o += 4
            z3 = u32(d, o); o += 4
            z4 = u32(d, o); o += 4
            print(f"{'  '*depth}  entry[{i}] at 0x{e_off:X}: stream={stream_name!r} bank={bank_name!r} idx={stream_index} ms={ms} x={x} {z1},{z2},{z3},{z4}")
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
    print(f"LGCY end: 0x{end:X}, remaining: {end - o}")
    if end - o > 0:
        print(f"  remaining: {d[o:o+min(64, end-o)].hex(' ')}")

if __name__ == '__main__':
    main(sys.argv[1])
