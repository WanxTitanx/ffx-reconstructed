// Function: sub_AE38A0
// Address: 0xae38a0
// Size: 0xb4
// Prototype: 

int sub_AE38A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C580,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferRWTexture3D",
    16,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C610 |= 2u;
  dword_C9C580[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferRWTexture3D>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C580, (int)&unk_C9D470);
  Phyre_PObject_SetField68(dword_C9C580, (int)&unk_C9D480);
  Phyre_PObject_SetField6C(dword_C9C580, (int)&unk_C9D490);
  unk_C9C610 &= ~2u;
  dword_C9C580[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferRWTexture3D>::`vftable';
  return atexit(sub_AFD500);
}

