// Function: sub_AE3660
// Address: 0xae3660
// Size: 0xb4
// Prototype: 

int sub_AE3660()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C320,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferRWByteAddressBuffer",
    24,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C3B0 |= 2u;
  dword_C9C320[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferRWByteAddressBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C320, (int)&unk_C9D5F0);
  Phyre_PObject_SetField68(dword_C9C320, (int)&unk_C9D610);
  Phyre_PObject_SetField6C(dword_C9C320, (int)&unk_C9D630);
  unk_C9C3B0 &= ~2u;
  dword_C9C320[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferRWByteAddressBuffer>::`vftable';
  return atexit(sub_AFD4A0);
}

