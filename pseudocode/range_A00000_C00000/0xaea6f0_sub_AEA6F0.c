// Function: sub_AEA6F0
// Address: 0xaea6f0
// Size: 0xb4
// Prototype: 

int sub_AEA6F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB3D48, (int)Registry, (int)"PIndirectArgsBufferD3D11", 24, 4, (int)dword_CA9038, 0);
  unk_CB3DD8 |= 2u;
  dword_CB3D48[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PIndirectArgsBufferD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3D48, (int)&unk_CBA9F0);
  Phyre_PObject_SetField68(dword_CB3D48, (int)&unk_CBAA10);
  Phyre_PObject_SetField6C(dword_CB3D48, (int)&unk_CBAA30);
  unk_CB3DD8 &= ~2u;
  dword_CB3D48[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PIndirectArgsBufferD3D11>::`vftable';
  return atexit(sub_B03730);
}

