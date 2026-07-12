// Function: sub_AF0790
// Address: 0xaf0790
// Size: 0xb4
// Prototype: 

int sub_AF0790()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CDEE68,
    (int)Registry,
    (int)"ClothInstancingDynamicMesh",
    40,
    4,
    (int)dword_C9A7D0,
    0);
  unk_CDEEF8 |= 2u;
  dword_CDEE68[0] = &Phyre::PClassDescriptorAbstract<Phyre::ClothInstancingDynamicMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CDEE68, (int)&unk_CDF0A0);
  Phyre_PObject_SetField68(dword_CDEE68, (int)&unk_CDF0D0);
  Phyre_PObject_SetField6C(dword_CDEE68, (int)&unk_CDF100);
  unk_CDEEF8 &= ~2u;
  dword_CDEE68[0] = &Phyre::PClassDescriptorConcrete<Phyre::ClothInstancingDynamicMesh>::`vftable';
  return atexit(sub_B075E0);
}

