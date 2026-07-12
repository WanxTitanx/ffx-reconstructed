// Function: sub_AE3960
// Address: 0xae3960
// Size: 0xb4
// Prototype: 

int sub_AE3960()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C0C0,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferSampler",
    16,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C150 |= 2u;
  dword_C9C0C0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferSampler>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C0C0, (int)&unk_C9D4A0);
  Phyre_PObject_SetField68(dword_C9C0C0, (int)&unk_C9D4B0);
  Phyre_PObject_SetField6C(dword_C9C0C0, (int)&unk_C9D4C0);
  unk_C9C150 &= ~2u;
  dword_C9C0C0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferSampler>::`vftable';
  return atexit(sub_AFD520);
}

