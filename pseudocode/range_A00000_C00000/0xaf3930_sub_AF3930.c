// Function: sub_AF3930
// Address: 0xaf3930
// Size: 0xb7
// Prototype: 

int sub_AF3930()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943E88, (int)Registry, (int)"PMLAA", 144, 4, (int)&unk_1943F20, 0);
  unk_1943F18 |= 2u;
  dword_1943E88[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PMLAA>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943E88, (int)&unk_1979C70);
  Phyre_PObject_SetField68(dword_1943E88, (int)&unk_1979D00);
  Phyre_PObject_SetField6C(dword_1943E88, (int)&unk_1979D90);
  unk_1943F18 &= ~2u;
  dword_1943E88[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PMLAA>::`vftable';
  return atexit(sub_B088D0);
}

