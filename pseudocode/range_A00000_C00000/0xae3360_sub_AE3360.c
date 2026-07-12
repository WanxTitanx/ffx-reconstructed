// Function: sub_AE3360
// Address: 0xae3360
// Size: 0xc0
// Prototype: 

int sub_AE3360()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9C9A8, (int)Registry, (int)"PShaderGeometryProgram", 1252, 4, (int)&unk_CB3870, 0);
  unk_C9CA38 |= 2u;
  dword_C9C9A8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderGeometryProgram>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C9A8, (int)&unk_C9F540);
  Phyre_PObject_SetField68(dword_C9C9A8, (int)&unk_C9FA30);
  Phyre_PObject_SetField6C(dword_C9C9A8, (int)&unk_C9FF20);
  dword_C9C9A8[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderGeometryProgram>::`vftable';
  unk_C9CA38 = unk_C9CA38 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFD420);
}

