// Function: sub_AE2820
// Address: 0xae2820
// Size: 0xa4
// Prototype: 

int sub_AE2820()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9A7D0, (int)Registry, (int)"PDynamicMesh", 28, 16, (int)GlobalTypeAccessor, 4);
  unk_C9A860 |= 2u;
  dword_C9A7D0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PDynamicMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9A7D0, (int)&unk_C9A9B0);
  Phyre_PObject_SetField68(dword_C9A7D0, (int)&unk_C9A9D0);
  Phyre_PObject_SetField6C(dword_C9A7D0, (int)&unk_C9A9F0);
  return atexit(sub_AFCC10);
}

