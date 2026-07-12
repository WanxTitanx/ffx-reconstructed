// Function: sub_AF3870
// Address: 0xaf3870
// Size: 0xb7
// Prototype: 

int sub_AF3870()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1944348, (int)Registry, (int)"PLegacyGlowGPUBase", 144, 4, (int)dword_19442B0, 0);
  unk_19443D8 |= 2u;
  dword_1944348[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PLegacyGlowGPUBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944348, (int)&unk_1983D50);
  Phyre_PObject_SetField68(dword_1944348, (int)&unk_1983DE0);
  Phyre_PObject_SetField6C(dword_1944348, (int)&unk_1983E70);
  unk_19443D8 &= ~2u;
  dword_1944348[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PLegacyGlowGPUBase>::`vftable';
  return atexit(sub_B088B0);
}

