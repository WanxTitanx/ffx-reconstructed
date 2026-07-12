// Function: sub_AEB0A0
// Address: 0xaeb0a0
// Size: 0xb4
// Prototype: 

int sub_AEB0A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB39A0, (int)Registry, (int)"PTexture2DD3D11", 116, 4, (int)dword_CA3738, 0);
  unk_CB3A30 |= 2u;
  dword_CB39A0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTexture2DD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB39A0, (int)&unk_CBA4E0);
  Phyre_PObject_SetField68(dword_CB39A0, (int)&unk_CBA560);
  Phyre_PObject_SetField6C(dword_CB39A0, (int)&unk_CBA5E0);
  unk_CB3A30 &= ~2u;
  dword_CB39A0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTexture2DD3D11>::`vftable';
  return atexit(sub_B038D0);
}

