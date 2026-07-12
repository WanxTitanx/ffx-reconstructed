// Function: sub_AE28D0
// Address: 0xae28d0
// Size: 0xb5
// Prototype: 

int sub_AE28D0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9A738,
    (int)Registry,
    (int)"PDynamicSegmentDesc",
    16,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C9A7C8 |= 2u;
  dword_C9A738[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PDynamicMesh::PDynamicSegmentDesc>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9A738, (int)&unk_C9AB30);
  Phyre_PObject_SetField68(dword_C9A738, (int)&unk_C9AB40);
  Phyre_PObject_SetField6C(dword_C9A738, (int)&unk_C9AB50);
  unk_C9A7C8 &= ~2u;
  dword_C9A738[0] = &off_B1682C;
  return atexit(sub_AFCC30);
}

