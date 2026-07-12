// Function: sub_AEB220
// Address: 0xaeb220
// Size: 0xb4
// Prototype: 

int sub_AEB220()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB3AD0, (int)Registry, (int)"PTextureCubeMapD3D11", 104, 4, (int)dword_CA3E58, 0);
  unk_CB3B60 |= 2u;
  dword_CB3AD0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTextureCubeMapD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3AD0, (int)&unk_CBA7B0);
  Phyre_PObject_SetField68(dword_CB3AD0, (int)&unk_CBA820);
  Phyre_PObject_SetField6C(dword_CB3AD0, (int)&unk_CBA890);
  unk_CB3B60 &= ~2u;
  dword_CB3AD0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTextureCubeMapD3D11>::`vftable';
  return atexit(sub_B03910);
}

