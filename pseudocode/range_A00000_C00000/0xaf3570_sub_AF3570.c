// Function: sub_AF3570
// Address: 0xaf3570
// Size: 0xb7
// Prototype: 

int sub_AF3570()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_19440E8, (int)Registry, (int)"PGlowGPUBase", 172, 4, (int)dword_1944050, 0);
  unk_1944178 |= 2u;
  dword_19440E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PGlowGPUBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19440E8, (int)&unk_19835A0);
  Phyre_PObject_SetField68(dword_19440E8, (int)&unk_1983650);
  Phyre_PObject_SetField6C(dword_19440E8, (int)&unk_1983700);
  unk_1944178 &= ~2u;
  dword_19440E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PGlowGPUBase>::`vftable';
  return atexit(sub_B08830);
}

