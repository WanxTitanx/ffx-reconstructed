// Function: sub_AE2C90
// Address: 0xae2c90
// Size: 0xb4
// Prototype: 

int sub_AE2C90()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9B560, (int)Registry, (int)"PConstantBuffer", 60, 4, (int)&unk_CB3DE0, 0);
  unk_C9B5F0 |= 2u;
  dword_C9B560[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PConstantBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9B560, (int)&unk_C9B660);
  Phyre_PObject_SetField68(dword_C9B560, (int)&unk_C9B6A0);
  Phyre_PObject_SetField6C(dword_C9B560, (int)&unk_C9B6E0);
  unk_C9B5F0 &= ~2u;
  dword_C9B560[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PConstantBuffer>::`vftable';
  return atexit(sub_AFD230);
}

