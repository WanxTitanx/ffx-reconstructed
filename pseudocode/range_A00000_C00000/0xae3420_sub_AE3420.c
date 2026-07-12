// Function: sub_AE3420
// Address: 0xae3420
// Size: 0xb4
// Prototype: 

int sub_AE3420()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C288,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferByteAddressBuffer",
    20,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C318 |= 2u;
  dword_C9C288[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferByteAddressBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C288, (int)&unk_C9D590);
  Phyre_PObject_SetField68(dword_C9C288, (int)&unk_C9D5B0);
  Phyre_PObject_SetField6C(dword_C9C288, (int)&unk_C9D5D0);
  unk_C9C318 &= ~2u;
  dword_C9C288[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferByteAddressBuffer>::`vftable';
  return atexit(sub_AFD440);
}

