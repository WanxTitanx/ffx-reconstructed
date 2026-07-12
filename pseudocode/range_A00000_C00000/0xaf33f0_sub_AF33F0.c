// Function: sub_AF33F0
// Address: 0xaf33f0
// Size: 0xb7
// Prototype: 

int sub_AF33F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1944050, (int)Registry, (int)"PGlowBase", 144, 4, (int)dword_19435E8, 0);
  unk_19440E0 |= 2u;
  dword_1944050[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PGlowBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944050, (int)&unk_19833F0);
  Phyre_PObject_SetField68(dword_1944050, (int)&unk_1983480);
  Phyre_PObject_SetField6C(dword_1944050, (int)&unk_1983510);
  unk_19440E0 &= ~2u;
  dword_1944050[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PGlowBase>::`vftable';
  return atexit(sub_B087F0);
}

