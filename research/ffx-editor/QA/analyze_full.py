import struct, sys, os

def u32(b, o): return struct.unpack_from('<I', b, o)[0]
def i32(b, o): return struct.unpack_from('<i', b, o)[0]

def vlq_unpack(b, pos):
    value = 0; shift = 0
    while True:
        raw = b[pos]; pos += 1
        value |= (raw & 0x7F) << shift
        shift += 7
        if not (raw & 0x80): break
    return value, pos

def parse(path):
    b = open(path, 'rb').read()
    print(f"=== {os.path.basename(path)} ({len(b)} bytes) ===")
    hsize = u32(b, 4)
    ns_size = u32(b, 8)
    inst_count = u32(b, 0x10)
    arr_fix_size = u32(b, 0x14); arr_fix_count = u32(b, 0x18)
    ptr_fix_size = u32(b, 0x1C); ptr_fix_count = u32(b, 0x20)
    pta_fix_size = u32(b, 0x24); pta_fix_count = u32(b, 0x28)
    ptrs_in_arrays = u32(b, 0x2C)
    user_fix_count = u32(b, 0x30); user_fix_size = u32(b, 0x34)
    total_data = u32(b, 0x38)
    hdr_cls_inst = u32(b, 0x3C); hdr_cls_child = u32(b, 0x40)
    print(f"instLists={inst_count} arrFix={arr_fix_size}B/{arr_fix_count} ptrFix={ptr_fix_size}B/{ptr_fix_count} ptaFix={pta_fix_size}B/{pta_fix_count}")
    print(f"userFix={user_fix_count}x12B data={user_fix_size}B totalData={total_data} hdrClsInst={hdr_cls_inst} hdrClsChild={hdr_cls_child}")

    ns = hsize
    type_count = u32(b, ns+8); class_count = u32(b, ns+12); member_count = u32(b, ns+16)
    strtab_size = u32(b, ns+20)
    types_off = ns + 32
    classes_off = types_off + type_count*4
    members_off = classes_off + class_count*36
    strtab_off = members_off + member_count*24
    def cstr(off):
        if off >= strtab_size: return f"<oob:{off}>"
        s = strtab_off + off; e = b.index(b'\x00', s, strtab_off+strtab_size)
        return b[s:e].decode('ascii','replace')
    class_names = {}
    for i in range(class_count):
        o = classes_off + i*36
        class_names[i] = cstr(u32(b, o+8))
    # member -> class mapping (members are per-class in order)
    member_class = {}
    m_idx = 0
    for i in range(class_count):
        cnt = u32(b, classes_off + i*36 + 12)
        for _ in range(cnt):
            member_class[m_idx] = i; m_idx += 1

    after_ns = ns + ns_size
    pos = after_ns
    print(f"\n--- InstanceListHeaders @0x{pos:x} ---")
    il_headers = []
    for i in range(inst_count):
        o = pos + i*36
        cd = u32(b,o); cnt = u32(b,o+4); sz = u32(b,o+8); objsz = u32(b,o+12); arrsz = u32(b,o+16)
        pia = u32(b,o+20); afc = u32(b,o+24); pfc = u32(b,o+28); pafc = u32(b,o+32)
        cls = class_names.get(cd-1, f"classID_{cd}")
        il_headers.append((cd,cnt,sz,objsz,arrsz,pia,afc,pfc,pafc))
        print(f"  IL[{i}] classID={cd} ({cls}) count={cnt} size={sz} objects={objsz} arrays={arrsz} ptrsInArrays={pia} arrFix={afc} ptrFix={pfc} ptaFix={pafc}")
    pos += inst_count*36

    print(f"\n--- ObjectData @0x{pos:x} ({total_data} bytes) ---")
    obj_start = pos
    for i,(cd,cnt,sz,objsz,arrsz,pia,afc,pfc,pafc) in enumerate(il_headers):
        cls = class_names.get(cd-1, f"classID_{cd}")
        print(f"  IL[{i}] {cls} x{cnt} @0x{pos:x} (objects {objsz}B + arrays {arrsz}B)")
        # dump first object
        for j in range(min(cnt, 2)):
            o = pos + j*sz  # note: objects are contiguous, size = m_size
            print(f"    obj[{j}] @0x{o:x}: {b[o:o+min(sz,64)].hex(' ')}")
        pos += sz * cnt
    print(f"  object data ends @0x{pos:x} (expected 0x{obj_start+total_data:x})")

    print(f"\n--- UserFixupData @0x{pos:x} ({user_fix_size}B) ---")
    ufd = pos; pos += user_fix_size
    print(f"  data: {b[ufd:pos]!r}")
    print(f"\n--- UserFixups @0x{pos:x} ({user_fix_count}x12B) ---")
    for i in range(user_fix_count):
        o = pos + i*12
        tid = u32(b,o); sz = u32(b,o+4); off = u32(b,o+8)
        print(f"  userFix[{i}] typeID={tid} size={sz} offset={off} -> {b[ufd+off:ufd+off+sz]!r}")
    pos += user_fix_count*12

    print(f"\n--- HeaderClassChildCounts @0x{pos:x} ({hdr_cls_inst}x4B) ---")
    pos += hdr_cls_inst*4
    print(f"--- HeaderClassChildren @0x{pos:x} ({hdr_cls_child}x16B) ---")
    pos += hdr_cls_child*16

    print(f"\n--- PointerArrayFixups @0x{pos:x} ({pta_fix_size}B) ---")
    pos += pta_fix_size
    print(f"--- PointerFixups @0x{pos:x} ({ptr_fix_size}B) ---")
    pos += ptr_fix_size
    print(f"--- ArrayFixups @0x{pos:x} ({arr_fix_size}B) ---")
    pos += arr_fix_size
    print(f"--- END @0x{pos:x} (file={len(b)}) ---")

if __name__ == '__main__':
    parse(sys.argv[1])
