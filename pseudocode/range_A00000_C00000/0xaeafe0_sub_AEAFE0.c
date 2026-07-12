// Function: sub_AEAFE0
// Address: 0xaeafe0
// Size: 0xb4
// Prototype: 

int sub_AEAFE0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB3CB0, (int)Registry, (int)"PStructuredBufferD3D11", 72, 4, (int)dword_CA8D30, 0);
  unk_CB3D40 |= 2u;
  dword_CB3CB0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PStructuredBufferD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3CB0, (int)&unk_CBA900);
  Phyre_PObject_SetField68(dword_CB3CB0, (int)&unk_CBA950);
  Phyre_PObject_SetField6C(dword_CB3CB0, (int)&unk_CBA9A0);
  unk_CB3D40 &= ~2u;
  dword_CB3CB0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PStructuredBufferD3D11>::`vftable';
  return atexit(sub_B038B0);
}

