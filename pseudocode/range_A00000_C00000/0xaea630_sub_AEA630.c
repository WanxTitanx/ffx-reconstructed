// Function: sub_AEA630
// Address: 0xaea630
// Size: 0xb4
// Prototype: 

int sub_AEA630()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB3DE0, (int)Registry, (int)"PConstantBufferD3D11", 60, 4, (int)dword_C9B4C8, 0);
  unk_CB3E70 |= 2u;
  dword_CB3DE0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PConstantBufferD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3DE0, (int)&unk_CB4D80);
  Phyre_PObject_SetField68(dword_CB3DE0, (int)&unk_CB4DC0);
  Phyre_PObject_SetField6C(dword_CB3DE0, (int)&unk_CB4E00);
  unk_CB3E70 &= ~2u;
  dword_CB3DE0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PConstantBufferD3D11>::`vftable';
  return atexit(sub_B03710);
}

