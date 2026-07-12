// Function: sub_AEA860
// Address: 0xaea860
// Size: 0xb4
// Prototype: 

int sub_AEA860()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB3C00, (int)Registry, (int)"PSamplerStateD3D11", 36, 4, (int)dword_CA2898, 0);
  unk_CB3C90 |= 2u;
  dword_CB3C00[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PSamplerStateD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3C00, (int)&unk_CBA450);
  Phyre_PObject_SetField68(dword_CB3C00, (int)&unk_CBA480);
  Phyre_PObject_SetField6C(dword_CB3C00, (int)&unk_CBA4B0);
  unk_CB3C90 &= ~2u;
  dword_CB3C00[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PSamplerStateD3D11>::`vftable';
  return atexit(sub_B03770);
}

