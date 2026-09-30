import idautils
import idc

# Search for references to "FTCX" magic (0x58544346) or width table usage
print("Searching for FTCX references...")

# Look for the magic number in data references
magic = 0x58544346
for seg_ea in idautils.Segments():
    seg_name = idc.get_segm_name(seg_ea)
    if "data" in seg_name.lower() or "DATA" in seg_name:
        for head in idautils.Heads(idc.get_segm_start(seg_ea), idc.get_segm_end(seg_ea)):
            val = idc.get_wide_dword(head)
            if val == magic:
                print(f"Found FTCX magic at 0x{head:08X}")
                # Find xrefs
                for xref in idautils.XrefsTo(head):
                    func = ida_funcs.get_func(xref.frm)
                    if func:
                        print(f"  Referenced from 0x{xref.frm:08X} in {idc.get_func_name(func.start_ea)}")
