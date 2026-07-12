// Function: sub_AF3330
// Address: 0xaf3330
// Size: 0xb7
// Prototype: 

int sub_AF3330()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1944180, (int)Registry, (int)"PGlow", 172, 4, (int)&unk_1944218, 0);
  unk_1944210 |= 2u;
  dword_1944180[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PGlow>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944180, (int)&unk_19839C0);
  Phyre_PObject_SetField68(dword_1944180, (int)&unk_1983A70);
  Phyre_PObject_SetField6C(dword_1944180, (int)&unk_1983B20);
  unk_1944210 &= ~2u;
  dword_1944180[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PGlow>::`vftable';
  return atexit(sub_B087D0);
}

