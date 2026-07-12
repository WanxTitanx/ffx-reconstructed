// Function: sub_AE4260
// Address: 0xae4260
// Size: 0xc0
// Prototype: 

int sub_AE4260()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9C878, (int)Registry, (int)"PShaderVertexProgram", 1264, 4, (int)&unk_CB3740, 0);
  unk_C9C908 |= 2u;
  dword_C9C878[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderVertexProgram>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C878, (int)&unk_C9D7A0);
  Phyre_PObject_SetField68(dword_C9C878, (int)&unk_C9DC90);
  Phyre_PObject_SetField6C(dword_C9C878, (int)&unk_C9E180);
  dword_C9C878[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderVertexProgram>::`vftable';
  unk_C9C908 = unk_C9C908 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFD6A0);
}

