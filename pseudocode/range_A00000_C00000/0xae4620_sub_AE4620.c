// Function: sub_AE4620
// Address: 0xae4620
// Size: 0xb4
// Prototype: 

int sub_AE4620()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA1468,
    (int)Registry,
    (int)"PShaderPassParameterLocationTypesConstantBuffer",
    24,
    4,
    (int)dword_CA1338,
    0);
  unk_CA14F8 |= 2u;
  dword_CA1468[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPassParameterLocationTypesConstantBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA1468, (int)&unk_CA1CB0);
  Phyre_PObject_SetField68(dword_CA1468, (int)&unk_CA1CD0);
  Phyre_PObject_SetField6C(dword_CA1468, (int)&unk_CA1CF0);
  unk_CA14F8 &= ~2u;
  dword_CA1468[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPassParameterLocationTypesConstantBuffer>::`vftable';
  return atexit(sub_AFD9F0);
}

