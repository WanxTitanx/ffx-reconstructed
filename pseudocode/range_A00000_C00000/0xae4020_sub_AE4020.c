// Function: sub_AE4020
// Address: 0xae4020
// Size: 0xb5
// Prototype: 

int sub_AE4020()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C6B0,
    (int)Registry,
    (int)"PShaderProgramParamsAndStreams",
    16,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C9C740 |= 2u;
  dword_C9C6B0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderProgramParamsAndStreams>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C6B0, (int)&unk_C9D740);
  Phyre_PObject_SetField68(dword_C9C6B0, (int)&unk_C9D750);
  Phyre_PObject_SetField6C(dword_C9C6B0, (int)&unk_C9D760);
  unk_C9C740 &= ~2u;
  dword_C9C6B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderProgramParamsAndStreams>::`vftable';
  return atexit(sub_AFD640);
}

