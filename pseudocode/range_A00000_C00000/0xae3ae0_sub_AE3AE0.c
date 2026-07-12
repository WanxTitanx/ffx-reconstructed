// Function: sub_AE3AE0
// Address: 0xae3ae0
// Size: 0xb4
// Prototype: 

int sub_AE3AE0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C158,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferStructuredBuffer",
    20,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C1E8 |= 2u;
  dword_C9C158[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferStructuredBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C158, (int)&unk_C9D4D0);
  Phyre_PObject_SetField68(dword_C9C158, (int)&unk_C9D4F0);
  Phyre_PObject_SetField6C(dword_C9C158, (int)&unk_C9D510);
  unk_C9C1E8 &= ~2u;
  dword_C9C158[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferStructuredBuffer>::`vftable';
  return atexit(sub_AFD560);
}

