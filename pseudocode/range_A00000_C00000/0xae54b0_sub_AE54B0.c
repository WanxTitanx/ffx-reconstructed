// Function: sub_AE54B0
// Address: 0xae54b0
// Size: 0xb4
// Prototype: 

int sub_AE54B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA3E58, (int)Registry, (int)"PTextureCubeMapBase", 32, 4, (int)dword_CA3530, 0);
  unk_CA3EE8 |= 2u;
  dword_CA3E58[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTextureCubeMapBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA3E58, (int)&unk_CA3FC0);
  Phyre_PObject_SetField68(dword_CA3E58, (int)&unk_CA3FE0);
  Phyre_PObject_SetField6C(dword_CA3E58, (int)&unk_CA4000);
  unk_CA3EE8 &= ~2u;
  dword_CA3E58[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTextureCubeMapBase>::`vftable';
  return atexit(sub_AFE410);
}

