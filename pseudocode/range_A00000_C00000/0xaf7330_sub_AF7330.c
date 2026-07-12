// Function: sub_AF7330
// Address: 0xaf7330
// Size: 0xbe
// Prototype: 

int sub_AF7330()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(Size_5, (int)Registry, (int)"POccluderGeometryInstance", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_1A854B0 |= 2u;
  Size_5[0] = &Phyre::PClassDescriptorAbstract<Phyre::POccluderGeometry::POccluderGeometryInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(Size_5, (int)&unk_1A85550);
  Phyre_PObject_SetField68(Size_5, (int)&unk_1A85560);
  Phyre_PObject_SetField6C(Size_5, (int)&unk_1A85570);
  Size_5[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::POccluderGeometry::POccluderGeometryInstance>::`vftable';
  unk_1A854B0 = unk_1A854B0 & 0xFFFFFFF5 | 8;
  return atexit(sub_B0A5C0);
}

