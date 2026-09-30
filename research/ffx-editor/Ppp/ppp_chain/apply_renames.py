import idc, ida_bytes, ida_name

SN_FORCE = 0x800
SN_NOCHECK = 0x100
# 0x230FFE0: antigo nome era FFX_MagicHost_Instance (sessao anterior). Evidencia nova:
# +8 = threshold allocator, +16 = freelist grande, +32 = array de descritores 32B,
# +4 = ptr p/ host runtime (+112/+120). = instancia do MagicHost que contem a PPP resource table.
old = idc.get_name(0x230FFE0) or ""
print("0x230FFE0 old:", old)
print("set FFX_MagicHost_Instance_PppResourceTable ->", idc.set_name(0x230FFE0, "FFX_MagicHost_Instance_PppResourceTable", SN_FORCE))

# 0x12F2030 = &byte_11333C4[1829996]: arena runtime da tabela (escrita por 0x80065F).
try:
    ida_bytes.create_data(0x12F2030, ida_bytes.FF_QWORD, 8, ida_bytes.BADADDR)
except Exception as e:
    print("create_data:", e)
print("0x12F2030 set ->", ida_name.set_name(0x12F2030, "FFX_PppResourceDescriptorTableArena", SN_FORCE | SN_NOCHECK))
print("0x12F2050 set ->", ida_name.set_name(0x12F2050, "FFX_PppResourceDescriptorTableArena_copies", SN_FORCE | SN_NOCHECK))
