// Function: sub_AEADA0
// Address: 0xaeada0
// Size: 0xc0
// Prototype: 

int sub_AEADA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB3740,
    (int)Registry,
    (int)"PShaderVertexProgramD3D11",
    1264,
    4,
    (int)dword_CB36A8,
    0);
  unk_CB37D0 |= 2u;
  dword_CB3740[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderVertexProgramD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3740, (int)&unk_CB5D70);
  Phyre_PObject_SetField68(dword_CB3740, (int)&unk_CB6260);
  Phyre_PObject_SetField6C(dword_CB3740, (int)&unk_CB6750);
  dword_CB3740[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderVertexProgramD3D11>::`vftable';
  unk_CB37D0 = unk_CB37D0 & 0xFFFFFFF5 | 8;
  return atexit(sub_B03850);
}

