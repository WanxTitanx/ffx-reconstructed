import ida_bytes, ida_name, json

TABLE_BASE = 0xC48EC8  # g_FFX_MagicOpcodeTable_core
ENTRY_SIZE = 8  # u32 handler_addr + u32 name_ptr
MAX_ENTRIES = 256

entries = []
for i in range(MAX_ENTRIES):
    ea = TABLE_BASE + i * ENTRY_SIZE
    handler = ida_bytes.get_dword(ea)
    name_ptr = ida_bytes.get_dword(ea + 4)
    if handler == 0 and name_ptr == 0:
        continue
    # Try to read the name string from the name_ptr
    name = ""
    if name_ptr and name_ptr != 0xFFFFFFFF:
        try:
            name_bytes = ida_bytes.get_bytes(name_ptr, 64)
            if name_bytes:
                name = name_bytes.split(b'\x00')[0].decode('ascii', errors='replace')
        except:
            name = f"@{hex(name_ptr)}"
    entries.append({
        "idx": i,
        "handler": hex(handler),
        "name": name
    })

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\research_tools\magic_opcode_table.json", "w") as fp:
    json.dump(entries, fp, indent=1)
print(f"Dumped {len(entries)} non-zero entries from core opcode table")
print(json.dumps({"total": len(entries), "first_5": entries[:5], "last_5": entries[-5:]}, indent=1))
