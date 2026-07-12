// Function: sub_AF99E0
// Address: 0xaf99e0
// Size: 0xcb
// Prototype: 

int sub_AF99E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(Size_8, (int)Registry, (int)"POccluderGeometryObject", 48, 16, (int)GlobalTypeAccessor, 0);
  unk_1A85A20 |= 2u;
  Size_8[0] = &Phyre::PClassDescriptorAbstract<Phyre::POccluderGeometry::POccluderGeometryObject>::`vftable';
  Phyre_PObject_SetInstanceOffset(Size_8, (int)&unk_1A85B10);
  Phyre_PObject_SetField68(Size_8, (int)&unk_1A85B40);
  Phyre_PObject_SetField6C(Size_8, (int)&unk_1A85B70);
  psub_A41690 = sub_A41690;
  Size_8[0] = &Phyre::PClassDescriptorHeader<Phyre::POccluderGeometry::POccluderGeometryObject>::`vftable';
  unk_1A85A20 = unk_1A85A20 & 0xFFFFFFF1 | 4;
  return atexit(sub_B0B9E0);
}

