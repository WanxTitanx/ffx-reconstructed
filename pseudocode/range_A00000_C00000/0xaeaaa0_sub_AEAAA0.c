// Function: sub_AEAAA0
// Address: 0xaeaaa0
// Size: 0xc0
// Prototype: 

int sub_AEAAA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB3870,
    (int)Registry,
    (int)"PShaderGeometryProgramD3D11",
    1252,
    4,
    (int)&unk_CB36A8,
    0);
  unk_CB3900 |= 2u;
  dword_CB3870[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderGeometryProgramD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3870, (int)&unk_CB7B10);
  Phyre_PObject_SetField68(dword_CB3870, (int)&unk_CB8000);
  Phyre_PObject_SetField6C(dword_CB3870, (int)&unk_CB84F0);
  dword_CB3870[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderGeometryProgramD3D11>::`vftable';
  unk_CB3900 = unk_CB3900 & 0xFFFFFFF5 | 8;
  return atexit(sub_B037D0);
}

