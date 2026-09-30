import idautils
import idc
import ida_funcs

# Search for functions that reference the width table pattern
# The width table is at offset 0x30 in the FTCX header (width_table_ptr)
# and has size at offset 0x34 (width_table_size)

print("Searching for width table usage patterns...")

# Look for functions that reference 0x30 or 0x34 as offsets from a base pointer
for seg_ea in idautils.Segments():
    seg_name = idc.get_segm_name(seg_ea)
    if "text" in seg_name.lower() or "CODE" in seg_name:
        for head in idautils.Heads(idc.get_segm_start(seg_ea), idc.get_segm_end(seg_ea)):
            disasm = idc.GetDisasm(head)
            # Look for patterns like [eax+30h] or [ecx+34h] which could be width table access
            if "[eax+30h]" in disasm or "[ecx+30h]" in disasm or "[edx+30h]" in disasm:
                func = ida_funcs.get_func(head)
                if func:
                    print(f"0x{head:08X}: {disasm} (func: {idc.get_func_name(func.start_ea)})")
