// Function: sub_AF3630
// Address: 0xaf3630
// Size: 0xb7
// Prototype: 

int sub_AF3630()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_19443E0, (int)Registry, (int)"PLegacyGlow", 144, 4, (int)&unk_1944478, 0);
  unk_1944470 |= 2u;
  dword_19443E0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PLegacyGlow>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19443E0, (int)&unk_19840B0);
  Phyre_PObject_SetField68(dword_19443E0, (int)&unk_1984140);
  Phyre_PObject_SetField6C(dword_19443E0, (int)&unk_19841D0);
  unk_1944470 &= ~2u;
  dword_19443E0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PLegacyGlow>::`vftable';
  return atexit(sub_B08850);
}

