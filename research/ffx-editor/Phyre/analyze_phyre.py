import struct, sys, os

def u32(b, o): return struct.unpack_from('<I', b, o)[0]
def i32(b, o): return struct.unpack_from('<i', b, o)[0]

def parse(path):
    b = open(path, 'rb').read()
    print(f"=== {os.path.basename(path)} ({len(b)} bytes) ===")
    magic = b[0:4]
    print(f"magic: {magic!r} (LE) / {magic[::-1]!r} (BE)")
    hsize = u32(b, 4)
    print(f"headerSize: 0x{hsize:x} ({hsize})  low-byte={chr(hsize&0xff)!r}")
    ns_size = u32(b, 8)
    plat = b[12:16]
    print(f"packedNamespaceSize: 0x{ns_size:x} ({ns_size})")
    print(f"platformID: {plat!r}")
    print(f"platformVersion: {u32(b,16)}")
    print(f"instanceListCount: {u32(b,0x10)}")
    print(f"arrayFixupSize: {u32(b,0x14)}  arrayFixupCount: {u32(b,0x18)}")
    print(f"pointerFixupSize: {u32(b,0x1C)}  pointerFixupCount: {u32(b,0x20)}")
    print(f"pointerArrayFixupSize: {u32(b,0x24)}  pointerArrayFixupCount: {u32(b,0x28)}")
    print(f"pointersInArraysCount: {u32(b,0x2C)}")
    print(f"userFixupCount: {u32(b,0x30)}  userFixupDataSize: {u32(b,0x34)}")
    print(f"totalDataSize: {u32(b,0x38)}")
    print(f"headerClassInstanceCount: {u32(b,0x3C)}  headerClassChildCount: {u32(b,0x40)}")
    print(f"physicsEngineID: 0x{u32(b,0x44):x}")
    # D3D11 extension
    print(f"[D3D11] indexBufferSize: {u32(b,0x48)}  vertexBufferSize: {u32(b,0x4C)}  maxTextureBufferSize: {u32(b,0x50)}")

    # Packed namespace
    ns = hsize
    pns_hdr = u32(b, ns)
    pns_size = u32(b, ns+4)
    type_count = u32(b, ns+8)
    class_count = u32(b, ns+12)
    member_count = u32(b, ns+16)
    strtab_size = u32(b, ns+20)
    dbuf_count = u32(b, ns+24)
    dbuf_size = u32(b, ns+28)
    print(f"\n--- PackedNamespace @0x{ns:x} ---")
    print(f"nsHeader: 0x{pns_hdr:08x}  nsSize: 0x{pns_size:x}  typeCount: {type_count}  classCount: {class_count}  memberCount: {member_count}")
    print(f"stringTableSize: {strtab_size}  defaultBufferCount: {dbuf_count}  defaultBufferSize: {dbuf_size}")

    types_off = ns + 32
    classes_off = types_off + type_count*4
    members_off = classes_off + class_count*36
    strtab_off = members_off + member_count*24
    print(f"types@0x{types_off:x} classes@0x{classes_off:x} members@0x{members_off:x} strtab@0x{strtab_off:x}")

    # Types
    print("\nTypes:")
    for i in range(type_count):
        no = u32(b, types_off + i*4)
        print(f"  type[{i}] nameOffset={no}")

    # Class descriptors
    print("\nClasses:")
    class_names = {}
    for i in range(class_count):
        o = classes_off + i*36
        super_id = i32(b, o)
        size_align = u32(b, o+4)
        name_off = u32(b, o+8)
        dm_count = u32(b, o+12)
        off_parent = i32(b, o+16)
        off_base = i32(b, o+20)
        off_base_alloc = i32(b, o+24)
        flags = u32(b, o+28)
        dbuf_off = u32(b, o+32)
        size = size_align & 0x0FFFFFFF
        align = size_align >> 28
        name = ""
        if name_off < strtab_size:
            s = strtab_off + name_off
            e = b.index(b'\x00', s)
            name = b[s:e].decode('ascii', 'replace')
        class_names[i] = name
        print(f"  class[{i}] name={name!r} super={super_id} size={size} align={align} nameOff={name_off} members={dm_count} offParent={off_parent} offBase={off_base} flags=0x{flags:x} dbufOff={dbuf_off}")

    # Data members
    print("\nDataMembers:")
    for i in range(member_count):
        o = members_off + i*24
        name_off = u32(b, o)
        type_id = u32(b, o+4)
        val_off = u32(b, o+8)
        size = u32(b, o+12)
        flags = u32(b, o+16)
        fixed_arr = u32(b, o+20)
        name = ""
        if name_off < strtab_size:
            s = strtab_off + name_off
            e = b.index(b'\x00', s)
            name = b[s:e].decode('ascii', 'replace')
        print(f"  member[{i}] name={name!r} typeID={type_id} valOff={val_off} size={size} flags=0x{flags:x} fixedArr={fixed_arr}")

    # String table dump
    print(f"\nStringTable ({strtab_size} bytes @0x{strtab_off:x}):")
    s = strtab_off
    end = s + strtab_size
    idx = 0
    while s < end:
        e = b.find(b'\x00', s, end)
        if e < 0: e = end
        if e > s:
            print(f"  [{idx}] @{s-strtab_off}: {b[s:e].decode('ascii','replace')!r}")
        idx += 1
        s = e + 1

    # After namespace: instance lists
    after_ns = ns + ns_size
    print(f"\n--- After namespace @0x{after_ns:x} ---")
    print(f"first 64 bytes: {b[after_ns:after_ns+64].hex(' ')}")

    return b, after_ns

if __name__ == '__main__':
    parse(sys.argv[1])
