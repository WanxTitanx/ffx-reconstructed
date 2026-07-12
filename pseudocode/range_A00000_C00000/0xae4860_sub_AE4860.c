// Function: sub_AE4860
// Address: 0xae4860
// Size: 0xb4
// Prototype: 

int sub_AE4860()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA2930, (int)Registry, (int)"PSamplerState", 36, 4, (int)&unk_CB3C00, 0);
  unk_CA29C0 |= 2u;
  dword_CA2930[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PSamplerState>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA2930, (int)&unk_CA2E80);
  Phyre_PObject_SetField68(dword_CA2930, (int)&unk_CA2EB0);
  Phyre_PObject_SetField6C(dword_CA2930, (int)&unk_CA2EE0);
  unk_CA29C0 &= ~2u;
  dword_CA2930[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PSamplerState>::`vftable';
  return atexit(sub_AFDC80);
}

