// Function: sub_AE41A0
// Address: 0xae41a0
// Size: 0xb5
// Prototype: 

int sub_AE41A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C7E0,
    (int)Registry,
    (int)"PShaderStreamDefinition",
    16,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C9C870 |= 2u;
  dword_C9C7E0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderStreamDefinition>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C7E0, (int)&unk_C9D320);
  Phyre_PObject_SetField68(dword_C9C7E0, (int)&unk_C9D330);
  Phyre_PObject_SetField6C(dword_C9C7E0, (int)&unk_C9D340);
  unk_C9C870 &= ~2u;
  dword_C9C7E0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderStreamDefinition>::`vftable';
  return atexit(sub_AFD680);
}

