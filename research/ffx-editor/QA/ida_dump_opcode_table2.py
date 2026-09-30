import ida_bytes, ida_name, ida_funcs, json

TABLE_BASE = 0xC48EC8  # g_FFX_MagicOpcodeTable_core
ENTRY_SIZE = 4  # confirmed: g_FFX_MagicOpcodeTable_core[ecx*4] at 0x80d6db
MAX_ENTRIES = 256

entries = []
for i in range(MAX_ENTRIES):
    ea = TABLE_BASE + i * ENTRY_SIZE
    handler = ida_bytes.get_dword(ea)
    if handler == 0:
        continue
    # Resolve handler function name
    hname = ""
    f = ida_funcs.get_func(handler)
    if f:
        hname = ida_name.get_name(f.start_ea) or ""
    entries.append({
        "idx": i,
        "handler": hex(handler),
        "handler_name": hname,
        "size": hex(f.size()) if f else None
    })

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\magic_opcode_table.json", "w") as fp:
    json.dump(entries, fp, indent=1)
print(f"Non-zero core opcodes: {len(entries)}/256")
for e in entries[:10]:
    print(f"  0x{e['idx']:02X} -> {e['handler']} {e['handler_name']} ({e['size']})")
