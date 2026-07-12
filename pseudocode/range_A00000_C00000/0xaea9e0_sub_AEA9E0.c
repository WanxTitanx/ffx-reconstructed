// Function: sub_AEA9E0
// Address: 0xaea9e0
// Size: 0xc0
// Prototype: 

int sub_AEA9E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB37D8,
    (int)Registry,
    (int)"PShaderFragmentProgramD3D11",
    1252,
    4,
    (int)&unk_CB36A8,
    0);
  unk_CB3868 |= 2u;
  dword_CB37D8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderFragmentProgramD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB37D8, (int)&unk_CB6C40);
  Phyre_PObject_SetField68(dword_CB37D8, (int)&unk_CB7130);
  Phyre_PObject_SetField6C(dword_CB37D8, (int)&unk_CB7620);
  dword_CB37D8[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderFragmentProgramD3D11>::`vftable';
  unk_CB3868 = unk_CB3868 & 0xFFFFFFF5 | 8;
  return atexit(sub_B037B0);
}

