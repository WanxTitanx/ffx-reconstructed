// Function: sub_AE32A0
// Address: 0xae32a0
// Size: 0xc0
// Prototype: 

int sub_AE32A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9C910, (int)Registry, (int)"PShaderFragmentProgram", 1252, 4, (int)&unk_CB37D8, 0);
  unk_C9C9A0 |= 2u;
  dword_C9C910[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderFragmentProgram>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C910, (int)&unk_C9E670);
  Phyre_PObject_SetField68(dword_C9C910, (int)&unk_C9EB60);
  Phyre_PObject_SetField6C(dword_C9C910, (int)&unk_C9F050);
  dword_C9C910[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderFragmentProgram>::`vftable';
  unk_C9C9A0 = unk_C9C9A0 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFD400);
}

