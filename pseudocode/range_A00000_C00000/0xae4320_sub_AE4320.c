// Function: sub_AE4320
// Address: 0xae4320
// Size: 0xb7
// Prototype: 

int sub_AE4320()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA1598, (int)Registry, (int)"PShaderPass", 596, 4, (int)&unk_CB3448, 0);
  unk_CA1628 |= 2u;
  dword_CA1598[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPass>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA1598, (int)&unk_CA1DA0);
  Phyre_PObject_SetField68(dword_CA1598, (int)&unk_CA2000);
  Phyre_PObject_SetField6C(dword_CA1598, (int)&unk_CA2260);
  unk_CA1628 &= ~2u;
  dword_CA1598[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPass>::`vftable';
  return atexit(sub_AFD970);
}

