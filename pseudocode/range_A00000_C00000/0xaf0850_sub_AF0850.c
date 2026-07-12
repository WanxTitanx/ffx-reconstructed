// Function: sub_AF0850
// Address: 0xaf0850
// Size: 0xc0
// Prototype: 

int sub_AF0850()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CDEFA0,
    (int)Registry,
    (int)"ClothInstancingDynamicMeshInstance",
    8208,
    4,
    (int)dword_CA7F28,
    0);
  unk_CDF030 |= 2u;
  dword_CDEFA0[0] = &Phyre::PClassDescriptorAbstract<Phyre::ClothInstancingDynamicMeshInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CDEFA0, (int)&unk_CDF130);
  Phyre_PObject_SetField68(dword_CDEFA0, (int)&unk_CE1140);
  Phyre_PObject_SetField6C(dword_CDEFA0, (int)&unk_CE3150);
  dword_CDEFA0[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::ClothInstancingDynamicMeshInstance>::`vftable';
  unk_CDF030 = unk_CDF030 & 0xFFFFFFF5 | 8;
  return atexit(sub_B07600);
}

