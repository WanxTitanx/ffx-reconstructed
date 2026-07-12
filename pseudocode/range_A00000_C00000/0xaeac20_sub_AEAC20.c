// Function: sub_AEAC20
// Address: 0xaeac20
// Size: 0xb7
// Prototype: 

int sub_AEAC20()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB34E0, (int)Registry, (int)"PShaderPassStateD3D11", 380, 4, (int)dword_CA1630, 0);
  unk_CB3570 |= 2u;
  dword_CB34E0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPassStateD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB34E0, (int)&unk_CB98B0);
  Phyre_PObject_SetField68(dword_CB34E0, (int)&unk_CB9A30);
  Phyre_PObject_SetField6C(dword_CB34E0, (int)&unk_CB9BB0);
  unk_CB3570 &= ~2u;
  dword_CB34E0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPassStateD3D11>::`vftable';
  return atexit(sub_B03810);
}

