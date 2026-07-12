// Function: sub_AE6E80
// Address: 0xae6e80
// Size: 0xbe
// Prototype: 

int sub_AE6E80()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA7F28,
    (int)Registry,
    (int)"PDynamicMeshInstance",
    12,
    4,
    (int)GlobalTypeAccessor,
    4);
  unk_CA7FB8 |= 2u;
  dword_CA7F28[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PDynamicMeshInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA7F28, (int)&unk_CA7FF0);
  Phyre_PObject_SetField68(dword_CA7F28, (int)&unk_CA8000);
  Phyre_PObject_SetField6C(dword_CA7F28, (int)&unk_CA8010);
  dword_CA7F28[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PDynamicMeshInstance>::`vftable';
  unk_CA7FB8 = unk_CA7FB8 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFF7D0);
}

