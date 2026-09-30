import idautils
import idc

# Search for functions that reference tile dimensions (14, 18) or width table patterns
print("Searching for font-related functions...")

# Look for references to 0x0E (14) and 0x12 (18) near each other
for seg_ea in idautils.Segments():
    seg_name = idc.get_segm_name(seg_ea)
    if "text" in seg_name.lower() or "CODE" in seg_name:
        for head in idautils.Heads(idc.get_segm_start(seg_ea), idc.get_segm_end(seg_ea)):
            disasm = idc.GetDisasm(head)
            # Look for immediate 14 (0x0E) or 18 (0x12) in common patterns
            if "0Eh" in disasm or "12h" in disasm:
                func = ida_funcs.get_func(head)
                if func:
                    print(f"0x{head:08X}: {disasm} (func: {idc.get_func_name(func.start_ea)})")
