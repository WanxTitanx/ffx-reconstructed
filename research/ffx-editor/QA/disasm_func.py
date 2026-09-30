import idc
import idautils
import ida_funcs
import ida_hexrays

addr = 0x88C7D0
print(f"Function at 0x{addr:08X}:")
print(f"Name: {idc.get_func_name(addr)}")
func = ida_funcs.get_func(addr)
if func:
    print(f"Size: {func.size}")
    
    # Try to decompile
    try:
        cfunc = ida_hexrays.decompile(addr)
        if cfunc:
            print("\nDecompiled:")
            print(str(cfunc))
    except Exception as e:
        print(f"Decompile error: {e}")
        
    # Disassemble instructions
    print("\nDisassembly:")
    for head in idautils.Heads(func.start_ea, func.end_ea):
        print(f"0x{head:08X}: {idc.GetDisasm(head)}")
else:
    print("Function not found")
