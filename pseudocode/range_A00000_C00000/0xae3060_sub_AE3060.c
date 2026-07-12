// Function: sub_AE3060
// Address: 0xae3060
// Size: 0xb4
// Prototype: 

int sub_AE3060()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9B8E8,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferLocationTypeConstantBuffer",
    16,
    4,
    (int)dword_C9B720,
    0);
  unk_C9B978 |= 2u;
  dword_C9B8E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferLocationTypeConstantBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9B8E8, (int)&unk_C9BCD0);
  Phyre_PObject_SetField68(dword_C9B8E8, (int)&unk_C9BCE0);
  Phyre_PObject_SetField6C(dword_C9B8E8, (int)&unk_C9BCF0);
  unk_C9B978 &= ~2u;
  dword_C9B8E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferLocationTypeConstantBuffer>::`vftable';
  return atexit(sub_AFD2E0);
}

