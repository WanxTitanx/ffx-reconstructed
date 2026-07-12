// Function: sub_AE31E0
// Address: 0xae31e0
// Size: 0xc0
// Prototype: 

int sub_AE31E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9CA40, (int)Registry, (int)"PShaderComputeProgram", 1252, 4, (int)&unk_CB3908, 0);
  unk_C9CAD0 |= 2u;
  dword_C9CA40[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderComputeProgram>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9CA40, (int)&unk_CA0410);
  Phyre_PObject_SetField68(dword_C9CA40, (int)&unk_CA0900);
  Phyre_PObject_SetField6C(dword_C9CA40, (int)&unk_CA0DF0);
  dword_C9CA40[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderComputeProgram>::`vftable';
  unk_C9CAD0 = unk_C9CAD0 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFD3E0);
}

