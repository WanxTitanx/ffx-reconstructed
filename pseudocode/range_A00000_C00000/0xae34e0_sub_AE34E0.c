// Function: sub_AE34E0
// Address: 0xae34e0
// Size: 0xb4
// Prototype: 

int sub_AE34E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C3B8,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferDataBlock",
    16,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C448 |= 2u;
  dword_C9C3B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferDataBlock>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C3B8, (int)&unk_C9D680);
  Phyre_PObject_SetField68(dword_C9C3B8, (int)&unk_C9D690);
  Phyre_PObject_SetField6C(dword_C9C3B8, (int)&unk_C9D6A0);
  unk_C9C448 &= ~2u;
  dword_C9C3B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferDataBlock>::`vftable';
  return atexit(sub_AFD460);
}

