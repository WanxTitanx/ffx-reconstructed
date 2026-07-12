// Function: sub_AE3F60
// Address: 0xae3f60
// Size: 0xb5
// Prototype: 

int sub_AE3F60()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9C748, (int)Registry, (int)"PShaderProgramBase", 1, 1, (int)GlobalTypeAccessor, 0);
  unk_C9C7D8 |= 2u;
  dword_C9C748[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderProgramBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C748, (int)&unk_C9D770);
  Phyre_PObject_SetField68(dword_C9C748, (int)&unk_C9D780);
  Phyre_PObject_SetField6C(dword_C9C748, (int)&unk_C9D790);
  unk_C9C7D8 &= ~2u;
  dword_C9C748[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderProgramBase>::`vftable';
  return atexit(sub_AFD620);
}

