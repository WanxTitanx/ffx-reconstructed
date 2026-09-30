import idautils
import idc
import ida_funcs

# Search for functions that reference both 14 (0x0E) and 18 (0x12) in close proximity
# This would indicate font rendering code that uses tile dimensions

print("Searching for font rendering functions (14x18 tile dimensions)...")

found_funcs = set()

for seg_ea in idautils.Segments():
    seg_name = idc.get_segm_name(seg_ea)
    if "text" in seg_name.lower() or "CODE" in seg_name:
        for head in idautils.Heads(idc.get_segm_start(seg_ea), idc.get_segm_end(seg_ea)):
            disasm = idc.GetDisasm(head)
            # Look for immediate 14 (0x0E) or 18 (0x12)
            if "0Eh" in disasm or "12h" in disasm:
                func = ida_funcs.get_func(head)
                if func and func.start_ea not in found_funcs:
                    # Check if this function also references the other dimension
                    func_name = idc.get_func_name(func.start_ea)
                    func_size = func.end_ea - func.start_ea
                    
                    # Search within function for both dimensions
                    has_14 = False
                    has_18 = False
                    for h in idautils.Heads(func.start_ea, func.end_ea):
                        d = idc.GetDisasm(h)
                        if "0Eh" in d:
                            has_14 = True
                        if "12h" in d:
                            has_18 = True
                        if has_14 and has_18:
                            print(f"0x{func.start_ea:08X}: {func_name} (size: {func_size})")
                            found_funcs.add(func.start_ea)
                            break
