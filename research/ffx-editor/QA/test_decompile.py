import ida_hexrays, ida_funcs

# Try a known simple function - the FFX_Save_ComputeCrc16 from the spec at 0x8b1400
for addr in [0x8b1400, 0x88CA30]:
    f = ida_funcs.get_func(addr)
    if not f:
        print(f"0x{addr:X}: no func")
        continue
    try:
        cf = ida_hexrays.decompile(f.start_ea)
        if cf:
            text = str(cf)
            print(f"0x{addr:X}: {len(text)} chars, first 200: {text[:200]}")
        else:
            print(f"0x{addr:X}: decompile returned None")
    except Exception as e:
        print(f"0x{addr:X}: exception {e}")
