// Function: sub_AEA7B0
// Address: 0xaea7b0
// Size: 0xa3
// Prototype: 

int sub_AEA7B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB3B68, (int)Registry, (int)"PRenderTargetD3D11", 40, 16, (int)dword_CA4168, 0);
  unk_CB3BF8 |= 2u;
  dword_CB3B68[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PRenderTargetD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3B68, (int)&unk_CB4BD0);
  Phyre_PObject_SetField68(dword_CB3B68, (int)&unk_CB4C00);
  Phyre_PObject_SetField6C(dword_CB3B68, (int)&unk_CB4C30);
  return atexit(sub_B03750);
}

