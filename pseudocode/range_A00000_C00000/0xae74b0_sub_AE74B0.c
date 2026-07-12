// Function: sub_AE74B0
// Address: 0xae74b0
// Size: 0xb4
// Prototype: 

int sub_AE74B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA90D0, (int)Registry, (int)"PIndirectArgsBuffer", 24, 4, (int)&unk_CB3D48, 0);
  unk_CA9160 |= 2u;
  dword_CA90D0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PIndirectArgsBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA90D0, (int)&unk_CA91A0);
  Phyre_PObject_SetField68(dword_CA90D0, (int)&unk_CA91C0);
  Phyre_PObject_SetField6C(dword_CA90D0, (int)&unk_CA91E0);
  unk_CA9160 &= ~2u;
  dword_CA90D0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PIndirectArgsBuffer>::`vftable';
  return atexit(sub_AFFAA0);
}

