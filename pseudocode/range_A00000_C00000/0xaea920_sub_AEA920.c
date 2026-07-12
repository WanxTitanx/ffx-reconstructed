// Function: sub_AEA920
// Address: 0xaea920
// Size: 0xc0
// Prototype: 

int sub_AEA920()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB3908,
    (int)Registry,
    (int)"PShaderComputeProgramD3D11",
    1252,
    4,
    (int)&unk_CB36A8,
    0);
  unk_CB3998 |= 2u;
  dword_CB3908[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderComputeProgramD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3908, (int)&unk_CB89E0);
  Phyre_PObject_SetField68(dword_CB3908, (int)&unk_CB8ED0);
  Phyre_PObject_SetField6C(dword_CB3908, (int)&unk_CB93C0);
  dword_CB3908[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderComputeProgramD3D11>::`vftable';
  unk_CB3998 = unk_CB3998 & 0xFFFFFFF5 | 8;
  return atexit(sub_B03790);
}

