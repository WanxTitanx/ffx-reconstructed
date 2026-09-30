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
