"""F8 UnX/ProjectX recon — PE scan + hashes + strings (read-only).

Fase 0 da Operacao Demonio (Jarvis-WIRE). Nada escreve fora de work/f8_recon/.
"""
import hashlib
import os
import re
import struct

OUT = os.path.dirname(os.path.abspath(__file__))

ARTIFACTS = [
    r"C:\Users\wande\Downloads\Compressed\UnX_0_9_1_9\unx.dll",
    r"C:\Users\wande\Downloads\Compressed\UnX_0_9_1_9\dxgi.dll",
    r"C:\Users\wande\Downloads\Compressed\UnX_0_9_1_9\ReShade32.dll",
    r"C:\Users\wande\Downloads\Compressed\UnX_0_9_1_9\UnX_Calibrate.exe",
    r"C:\Users\wande\Downloads\Compressed\UnX_0_9_1_9\unx.pdb",
    r"C:\Users\wande\Downloads\Compressed\UnX_0_9_1_9\dxgi.pdb",
    r"C:\Users\wande\Downloads\Compressed\UnX_0_9_1_9\ReShade32_SpecialK32.pdb",
    r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\_isolated\dxgi.dll",
    r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\_isolated\unx.dll",
    r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\_isolated\dinput8.dll",
    r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\_isolated\dxgi.ini",
]


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def pe_info(path):
    with open(path, "rb") as f:
        data = f.read()
    if data[:2] != b"MZ":
        return {"error": "not a PE"}
    e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
    if data[e_lfanew:e_lfanew + 4] != b"PE\0\0":
        return {"error": "no PE signature"}
    machine, nsect = struct.unpack_from("<HH", data, e_lfanew + 4)
    opt_size = struct.unpack_from("<H", data, e_lfanew + 20)[0]
    opt_off = e_lfanew + 24
    magic = struct.unpack_from("<H", data, opt_off)[0]
    is_pe32 = magic == 0x10B
    img_base = struct.unpack_from("<I", data, opt_off + 28)[0] if is_pe32 else \
        struct.unpack_from("<Q", data, opt_off + 24)[0]
    dd_off = opt_off + 96
    exp_rva, exp_size = struct.unpack_from("<II", data, dd_off)
    imp_rva, imp_size = struct.unpack_from("<II", data, dd_off + 8)

    def rva_to_off(rva):
        for i in range(nsect):
            off = opt_off + opt_size + i * 40
            vsize = struct.unpack_from("<I", data, off + 8)[0]
            vaddr = struct.unpack_from("<I", data, off + 12)[0]
            rsize = struct.unpack_from("<I", data, off + 16)[0]
            rptr = struct.unpack_from("<I", data, off + 20)[0]
            if vaddr <= rva < vaddr + max(vsize, rsize):
                return rptr + (rva - vaddr)
        return None

    def read_cstr(off):
        end = data.index(b"\0", off)
        return data[off:end].decode("ascii", "replace")

    exports = []
    if exp_rva and exp_size:
        eo = rva_to_off(exp_rva)
        if eo is not None:
            nfuncs = struct.unpack_from("<I", data, eo + 20)[0]
            names_rva = struct.unpack_from("<I", data, eo + 32)[0]
            names_off = rva_to_off(names_rva)
            for i in range(nfuncs):
                nrva = struct.unpack_from("<I", data, names_off + i * 4)[0]
                noff = rva_to_off(nrva)
                if noff is not None:
                    exports.append(read_cstr(noff))

    imports = []
    if imp_rva and imp_size:
        io = rva_to_off(imp_rva)
        while io is not None:
            dll_rva = struct.unpack_from("<I", data, io + 12)[0]
            if dll_rva == 0:
                break
            doff = rva_to_off(dll_rva)
            dll_name = read_cstr(doff) if doff is not None else "?"
            funcs = []
            oft_rva = struct.unpack_from("<I", data, io)[0]
            ft_rva = struct.unpack_from("<I", data, io + 16)[0]
            trva = oft_rva or ft_rva
            toff = rva_to_off(trva)
            while toff is not None:
                val = struct.unpack_from("<I", data, toff)[0]
                if val == 0:
                    break
                if val & 0x80000000:
                    funcs.append(f"ord#{val & 0xFFFF}")
                else:
                    noff = rva_to_off(val + 2)
                    funcs.append(read_cstr(noff) if noff is not None else "?")
                toff += 4
            imports.append((dll_name, funcs))
            io += 20

    sections = []
    for i in range(nsect):
        off = opt_off + opt_size + i * 40
        name = data[off:off + 8].rstrip(b"\0").decode("ascii", "replace")
        vsize = struct.unpack_from("<I", data, off + 8)[0]
        vaddr = struct.unpack_from("<I", data, off + 12)[0]
        rsize = struct.unpack_from("<I", data, off + 16)[0]
        rptr = struct.unpack_from("<I", data, off + 20)[0]
        chars = struct.unpack_from("<I", data, off + 36)[0]
        sections.append({"name": name, "va": vaddr, "vsize": vsize,
                         "raw": rptr, "rawsize": rsize, "chars": hex(chars)})

    return {"machine": hex(machine), "sections": len(sections),
            "opt": opt_size, "pe32": is_pe32, "imageBase": hex(img_base),
            "exports": exports, "imports": imports, "sections_detail": sections}



def extract_strings(path, min_len=5):
    with open(path, "rb") as f:
        data = f.read()
    ascii_str = re.findall(rb"[\x20-\x7e]{%d,}" % min_len, data)
    utf16 = re.findall(rb"(?:[\x20-\x7e]\x00){%d,}" % min_len, data)
    return ([s.decode("ascii") for s in ascii_str],
            ["".join(chr(b) for b in s[::2]) for s in utf16])


def main():
    lines = []
    for p in ARTIFACTS:
        if not os.path.exists(p):
            lines.append(f"MISSING {p}")
            continue
        h = sha256(p)
        sz = os.path.getsize(p)
        info = pe_info(p)
        if "error" in info:
            lines.append(f"{p}\n  size={sz} sha256={h}\n  {info['error']}")
        else:
            lines.append(f"{p}\n  size={sz} sha256={h}\n"
                         f"  machine={info['machine']} pe32={info['pe32']} "
                         f"imageBase={info['imageBase']} sections={info['sections']}\n"
                         f"  exports({len(info['exports'])}): {', '.join(info['exports'][:40])}\n"
                         f"  imports({len(info['imports'])} dlls):")
            for dll, funcs in info["imports"]:
                lines.append(f"    {dll}: {', '.join(funcs[:50])}"
                             + (f" ... +{len(funcs)-50}" if len(funcs) > 50 else ""))
            for s in info["sections_detail"]:
                lines.append(f"    sect {s['name']:8s} va=0x{s['va']:X} "
                             f"vsize=0x{s['vsize']:X} raw=0x{s['raw']:X} "
                             f"rawsize=0x{s['rawsize']:X} chars={s['chars']}")
        lines.append("")

    with open(os.path.join(OUT, "manifest.txt"), "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print("\n".join(lines[:60]))

    a, u = extract_strings(ARTIFACTS[0])
    with open(os.path.join(OUT, "unx_strings_ascii.txt"), "w", encoding="utf-8") as f:
        f.write("\n".join(a))
    with open(os.path.join(OUT, "unx_strings_utf16.txt"), "w", encoding="utf-8") as f:
        f.write("\n".join(u))
    print(f"\nunx.dll strings: ascii={len(a)} utf16={len(u)} -> saved")


if __name__ == "__main__":
    main()
