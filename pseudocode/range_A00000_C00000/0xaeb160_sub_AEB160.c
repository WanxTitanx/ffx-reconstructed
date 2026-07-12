// Function: sub_AEB160
// Address: 0xaeb160
// Size: 0xb4
// Prototype: 

int sub_AEB160()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB3A38, (int)Registry, (int)"PTexture3DD3D11", 104, 4, (int)dword_CA3AC8, 0);
  unk_CB3AC8 |= 2u;
  dword_CB3A38[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PTexture3DD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3A38, (int)&unk_CBA660);
  Phyre_PObject_SetField68(dword_CB3A38, (int)&unk_CBA6D0);
  Phyre_PObject_SetField6C(dword_CB3A38, (int)&unk_CBA740);
  unk_CB3AC8 &= ~2u;
  dword_CB3A38[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PTexture3DD3D11>::`vftable';
  return atexit(sub_B038F0);
}

