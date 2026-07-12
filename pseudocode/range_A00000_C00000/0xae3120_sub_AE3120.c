// Function: sub_AE3120
// Address: 0xae3120
// Size: 0xb5
// Prototype: 

int sub_AE3120()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9B980,
    (int)Registry,
    (int)"PShaderParameterDefinition",
    16,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C9BA10 |= 2u;
  dword_C9B980[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterDefinition>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9B980, (int)&unk_C9BD00);
  Phyre_PObject_SetField68(dword_C9B980, (int)&unk_C9BD10);
  Phyre_PObject_SetField6C(dword_C9B980, (int)&unk_C9BD20);
  unk_C9BA10 &= ~2u;
  dword_C9B980[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterDefinition>::`vftable';
  return atexit(sub_AFD300);
}

