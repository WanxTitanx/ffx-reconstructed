// Function: sub_AE4560
// Address: 0xae4560
// Size: 0xb5
// Prototype: 

int sub_AE4560()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA1338,
    (int)Registry,
    (int)"PShaderPassParameterLocationTypesBase",
    16,
    2,
    (int)GlobalTypeAccessor,
    0);
  unk_CA13C8 |= 2u;
  dword_CA1338[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPassParameterLocationTypesBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA1338, (int)&unk_CA1C20);
  Phyre_PObject_SetField68(dword_CA1338, (int)&unk_CA1C30);
  Phyre_PObject_SetField6C(dword_CA1338, (int)&unk_CA1C40);
  unk_CA13C8 &= ~2u;
  dword_CA1338[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPassParameterLocationTypesBase>::`vftable';
  return atexit(sub_AFD9D0);
}

