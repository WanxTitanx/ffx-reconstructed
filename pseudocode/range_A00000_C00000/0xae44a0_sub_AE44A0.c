// Function: sub_AE44A0
// Address: 0xae44a0
// Size: 0xb4
// Prototype: 

int sub_AE44A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA13D0,
    (int)Registry,
    (int)"PShaderPassParameterLocationTypes",
    24,
    4,
    (int)&unk_CA1338,
    0);
  unk_CA1460 |= 2u;
  dword_CA13D0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderPassParameterLocationTypes>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA13D0, (int)&unk_CA1C50);
  Phyre_PObject_SetField68(dword_CA13D0, (int)&unk_CA1C70);
  Phyre_PObject_SetField6C(dword_CA13D0, (int)&unk_CA1C90);
  unk_CA1460 &= ~2u;
  dword_CA13D0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderPassParameterLocationTypes>::`vftable';
  return atexit(sub_AFD9B0);
}

