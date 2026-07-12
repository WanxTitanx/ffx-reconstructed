// Function: sub_AE5330
// Address: 0xae5330
// Size: 0xb4
// Prototype: 

int sub_AE5330()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA3AC8, (int)Registry, (int)"PTexture3DBase", 40, 4, (int)dword_CA3530, 0);
  unk_CA3B58 |= 2u;
  dword_CA3AC8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTexture3DBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA3AC8, (int)&unk_CA3C80);
  Phyre_PObject_SetField68(dword_CA3AC8, (int)&unk_CA3CB0);
  Phyre_PObject_SetField6C(dword_CA3AC8, (int)&unk_CA3CE0);
  unk_CA3B58 &= ~2u;
  dword_CA3AC8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTexture3DBase>::`vftable';
  return atexit(sub_AFE3A0);
}

