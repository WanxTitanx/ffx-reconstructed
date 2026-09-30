import idautils, idc
pats = ['Vector2_RegisterClassDescriptor', 'Vector3_RegisterClassDescriptor', 'Vector4_RegisterClassDescriptor',
        'PObject_RegisterClassDescriptor', 'PColor_RegisterClassDescriptor', 'PInputMapper_ClassDescriptor',
        'PString_RegisterClassDescriptor', 'PRefCountObject_Register', 'PAllocator_Register']
for p in pats:
    hits = [(f, idc.get_func_name(f)) for f in idautils.Functions() if p.lower() in (idc.get_func_name(f) or '').lower()]
    print(p, '->', len(hits))
    for f, n in hits[:5]:
        print('   ', hex(f), n)
