// Function: sub_AEF3E0
// Address: 0xaef3e0
// Size: 0xbd
// Prototype: 

int sub_AEF3E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CCBF88,
    (int)Registry,
    (int)"BrokenScreenPolygonDynamicMeshInstance",
    12,
    4,
    (int)dword_CA7F28,
    0);
  unk_CCC018 |= 2u;
  dword_CCBF88[0] = &Phyre::PClassDescriptorAbstract<BrokenScreenPolygonDynamicMeshInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CCBF88, (int)&unk_CCC020);
  Phyre_PObject_SetField68(dword_CCBF88, (int)&unk_CCC030);
  Phyre_PObject_SetField6C(dword_CCBF88, (int)&unk_CCC040);
  dword_CCBF88[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<BrokenScreenPolygonDynamicMeshInstance>::`vftable';
  unk_CCC018 = unk_CCC018 & 0xFFFFFFF5 | 8;
  return atexit(sub_B06AC0);
}

