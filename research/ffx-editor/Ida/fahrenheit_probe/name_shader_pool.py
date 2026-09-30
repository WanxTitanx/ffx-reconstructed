#!/usr/bin/env python3
"""Conta blocos de shaders HLSL embutidos e renomeia o inicio da regiao."""
import ida_bytes
import ida_name
import idc
import re


def main():
    start = 0xC6DC90
    end = 0xC85EB0
    raw = ida_bytes.get_bytes(start, end - start) or b""
    hits = [m.start() for m in re.finditer(rb"Microsoft \(R\) HLSL Shader Compiler", raw)]
    print(f"blocos de shader: {len(hits)}", flush=True)
    # renomeia o inicio da regiao
    cur = ida_name.get_name(start)
    if not cur or cur.startswith(("byte_", "dword_", "unk_")):
        if ida_name.set_name(start, "FFX_Phyre_EmbeddedShaderPool",
                             ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            print(f"renomeado {hex(start)} -> FFX_Phyre_EmbeddedShaderPool", flush=True)
    idc.save_database("")
    print("db salva", flush=True)


if __name__ == "__main__":
    main()
