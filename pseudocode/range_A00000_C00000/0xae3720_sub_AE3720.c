// Function: sub_AE3720
// Address: 0xae3720
// Size: 0xb4
// Prototype: 

int sub_AE3720()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C1F0,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferRWStructuredBuffer",
    20,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C280 |= 2u;
  dword_C9C1F0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferRWStructuredBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C1F0, (int)&unk_C9D530);
  Phyre_PObject_SetField68(dword_C9C1F0, (int)&unk_C9D550);
  Phyre_PObject_SetField6C(dword_C9C1F0, (int)&unk_C9D570);
  unk_C9C280 &= ~2u;
  dword_C9C1F0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferRWStructuredBuffer>::`vftable';
  return atexit(sub_AFD4C0);
}

