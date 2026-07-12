// Function: sub_AEACE0
// Address: 0xaeace0
// Size: 0xc0
// Prototype: 

int sub_AEACE0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB36A8, (int)Registry, (int)"PShaderProgramD3D11", 1248, 4, (int)dword_C9C748, 0);
  unk_CB3738 |= 2u;
  dword_CB36A8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderProgramD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB36A8, (int)&unk_CB4ED0);
  Phyre_PObject_SetField68(dword_CB36A8, (int)&unk_CB53B0);
  Phyre_PObject_SetField6C(dword_CB36A8, (int)&unk_CB5890);
  dword_CB36A8[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderProgramD3D11>::`vftable';
  unk_CB3738 = unk_CB3738 & 0xFFFFFFF5 | 8;
  return atexit(sub_B03830);
}

