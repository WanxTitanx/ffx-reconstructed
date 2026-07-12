// Function: sub_AEAB60
// Address: 0xaeab60
// Size: 0xb7
// Prototype: 

int sub_AEAB60()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB3448, (int)Registry, (int)"PShaderPassD3D11", 596, 4, (int)dword_CA1500, 0);
  unk_CB34D8 |= 2u;
  dword_CB3448[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPassD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3448, (int)&unk_CB9D30);
  Phyre_PObject_SetField68(dword_CB3448, (int)&unk_CB9F90);
  Phyre_PObject_SetField6C(dword_CB3448, (int)&unk_CBA1F0);
  unk_CB34D8 &= ~2u;
  dword_CB3448[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPassD3D11>::`vftable';
  return atexit(sub_B037F0);
}

