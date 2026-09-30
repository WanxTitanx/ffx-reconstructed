#!/usr/bin/env python3
"""voice_mapper_decode.py — FFX voice-mapper (ML\\0\\0) codec + analyzer.

Jarvis-VOICE-MAPPER research lane, 2026-09-18.
Evidence base: FFX.exe IDB decompiles —
  LoadMapperData       0x70AC80  (loads VoiceIDMapper.txt + Voice{US,JP}/VoiceFevMapper.txt)
  LoadVoiceProject     0x70A720  (setId -> .fev via VoiceFevMapper, 21 project slots)
  InitBattleVoiceProject 0x70AB20 (loads ffx_{us,jp}_voice_btl.fev)
  ReadEventData        0x70AEC0  (voiceId -> name via VoiceIDMapper linear scan)
  FFX_FmodShout_PlaySound 0x70E560 (voiceId -> subsound name in voice_btl_iop_bank00.fsb)

Format (both files, despite the .txt extension they are binary):
    u32  magic "ML\\0\\0" (0x00004C4C)
    u32  count
    count x { u32 id, u32 nameOff }     # nameOff is absolute file offset
    NUL-terminated name blob

VoiceIDMapper id-space (voiceId):
    ordinary : id = N*0x1000 + speakerPack, where N is the 6-digit decimal
               line number of the event name and
               speakerPack = ((c1-'a'+1)<<6) | (c2-'a'+1)   [two 6-bit fields]
               inverse   : name = "%06d" % (id>>12) + pack2pair(id&0xFFF)
    legacy   : ids 1..44      -> "21xxxxxx" battle-shout names (iop .fsb subsounds)
    nagisetsu: ids 0x189..0x18E -> "NN_nagisetsu" names (voice_nagisetsu.fev)
    routing  : id > 0x33000000            -> battle group (voice_btl.fev)
               id in BATTLE_FORCED        -> battle group
               else -> mVoiceGroup[atoi(name[:2])]  (prefix = bank slot 0..20)

VoiceFevMapper id-space (setId == scene/map id, cmd9 arg):
    setId -> fev project name(s); multi-map (one set may map to several .fev).
    Sets 393..398 -> "ffx_voice_nagisetsu" + NonVoiceSetMode flag.
    Set 270 -> "ffx_voice270" (blitzball, forces group slot 0).
    Set 368 -> voice01 pinned; set 127 -> us_voice08 pinned (US build only).

Usage:
    voice_mapper_decode.py <mapper.txt>                    # dump stats
    voice_mapper_decode.py <idmapper> --decode-id 0x1D33981
    voice_mapper_decode.py <idmapper> --encode-name 030309yn
    voice_mapper_decode.py <fevmapper> --expand-sets       # set -> [fev...]
    voice_mapper_decode.py --selftest
"""
import struct, sys, os, re, collections

MAGIC = b"ML\x00\x00"
BATTLE_THRESHOLD = 0x33000000            # voiceId > this -> battle group
BATTLE_FORCED = {0x08341504, 0x0C545504, 0x28745504, 0x28746504, 0x00000504}
JP_ONLY_REJECT = range(0x0290D1C1, 0x029101C1 + 1)   # 010509ga..010512ga
NAGISETSU_IDS = range(0x189, 0x18F)
SET_RANGE_MAX = 0x1F4                    # (setId-1) <= 0x1F3  -> 1..500
NONVOICE_SETS = range(393, 399)          # sets 393..398 -> NonVoiceSetMode
NAME_RE = re.compile(r"^(\d{6})([a-z]{2})$")

SPEAKERS = {
    "td": "Tidus", "yn": "Yuna", "an": "Auron", "km": "Kimahri",
    "wk": "Wakka", "rr": "Lulu", "rk": "Rikku", "sm": "Seymour",
    "jc": "Jecht(?)", "ga": "crowd-a", "gb": "crowd-b", "gc": "crowd-c",
    "gd": "crowd-d", "ge": "crowd-e", "gf": "crowd-f", "gg": "crowd-g",
    "gh": "crowd-h", "gi": "crowd-i", "am": "announcer(?)", "bs": "boss(?)",
    "sd": "side(?)", "dn": "(?)", "yr": "blitz-announcer(?)",
}


def pair2pack(pair: str) -> int:
    return ((ord(pair[0]) - 0x60) << 6) | (ord(pair[1]) - 0x60)


def pack2pair(pack: int) -> str:
    c1, c2 = (pack >> 6) & 0x3F, pack & 0x3F
    if not (1 <= c1 <= 26 and 1 <= c2 <= 26):
        return "??"
    return chr(0x60 + c1) + chr(0x60 + c2)


def encode_name(name: str):
    """voiceId <- 'NNNNNNcc' name (None if not a patterned name)."""
    m = NAME_RE.match(name)
    if not m:
        return None
    return int(m.group(1)) * 0x1000 + pair2pack(m.group(2))


def decode_id(voice_id: int) -> str:
    return "%06d%s" % (voice_id >> 12, pack2pair(voice_id & 0xFFF))


def load_mapper(path: str):
    data = open(path, "rb").read()
    assert data[:4] == MAGIC, "bad magic %r" % data[:4]
    count = struct.unpack_from("<I", data, 4)[0]
    recs = []
    for i in range(count):
        vid, off = struct.unpack_from("<II", data, 8 + 8 * i)
        end = data.index(b"\x00", off)
        recs.append((vid, data[off:end].decode("ascii", "replace"), off))
    return recs


def classify(vid: int, name: str):
    """-> (kind, route)  kind: formula|legacy|nagisetsu|other
       route: btl|bankNN|special0|unmatched"""
    if vid in BATTLE_FORCED or vid > BATTLE_THRESHOLD:
        route = "btl"
    elif vid in NAGISETSU_IDS or name.endswith("_nagisetsu"):
        route = "special0"
    elif NAME_RE.match(name):
        route = "bank%02d" % int(name[:2])
    else:
        route = "unmatched"
    if vid in NAGISETSU_IDS:
        kind = "nagisetsu"
    elif encode_name(name) == vid:
        kind = "formula"
    elif NAME_RE.match(name):
        kind = "legacy"
    else:
        kind = "other"
    return kind, route


def analyze_idmapper(path):
    recs = load_mapper(path)
    stat = collections.Counter()
    speakers = collections.Counter()
    for vid, name, _ in recs:
        kind, route = classify(vid, name)
        stat[(kind, route)] += 1
        m = NAME_RE.match(name)
        if m:
            speakers[m.group(2)] += 1
    return recs, stat, speakers


def expand_sets(path):
    """fevmapper -> {setId: [fevName,...]} preserving record order."""
    sets = collections.OrderedDict()
    for vid, name, _ in load_mapper(path):
        sets.setdefault(vid, []).append(name)
    return sets


def _selftest():
    # pack/codec roundtrips
    assert pair2pack("td") == 0x504 and pack2pair(0x504) == "td"   # '000000td' = 0x504 = BATTLE_FORCED
    assert encode_name("000000td") == 0x504
    for n in ("030309yn", "165701td", "010101an", "200001rk"):
        assert decode_id(encode_name(n)) == n
    # legacy ids are NOT formula-produced
    assert encode_name("210101td") != 1
    print("selftest OK")
    return 0


def main(argv):
    if "--selftest" in argv:
        return _selftest()
    if len(argv) < 2:
        print(__doc__)
        return 1
    path = argv[1]
    if "--decode-id" in argv:
        vid = int(argv[argv.index("--decode-id") + 1], 0)
        print("%-10s -> %s" % (hex(vid), decode_id(vid)))
        return 0
    if "--encode-name" in argv:
        n = argv[argv.index("--encode-name") + 1]
        print("%-12s -> %s" % (n, encode_name(n)))
        return 0
    recs = load_mapper(path)
    print("%s : %d records" % (path, len(recs)))
    if "--expand-sets" in argv:
        sets = expand_sets(path)
        print("distinct set ids:", len(sets))
        for s, fevs in list(sets.items())[:12]:
            print("  set %-4d -> %s" % (s, ", ".join(fevs)))
        return 0
    for vid, name, off in recs[:10]:
        print("  0x%08X  @0x%05X  %s" % (vid, off, name))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
