// Function: sub_AE53F0
// Address: 0xae53f0
// Size: 0xb4
// Prototype: 

int sub_AE53F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA3EF0, (int)Registry, (int)"PTextureCubeMap", 104, 4, (int)&unk_CB3AD0, 0);
  unk_CA3F80 |= 2u;
  dword_CA3EF0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTextureCubeMap>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA3EF0, (int)&unk_CA4020);
  Phyre_PObject_SetField68(dword_CA3EF0, (int)&unk_CA4090);
  Phyre_PObject_SetField6C(dword_CA3EF0, (int)&unk_CA4100);
  unk_CA3F80 &= ~2u;
  dword_CA3EF0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTextureCubeMap>::`vftable';
  return atexit(sub_AFE3F0);
}

