// Function: sub_AE3C60
// Address: 0xae3c60
// Size: 0xb4
// Prototype: 

int sub_AE3C60()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9BF90,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferTexture3D",
    16,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C020 |= 2u;
  dword_C9BF90[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferTexture3D>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9BF90, (int)&unk_C9D3E0);
  Phyre_PObject_SetField68(dword_C9BF90, (int)&unk_C9D3F0);
  Phyre_PObject_SetField6C(dword_C9BF90, (int)&unk_C9D400);
  unk_C9C020 &= ~2u;
  dword_C9BF90[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferTexture3D>::`vftable';
  return atexit(sub_AFD5A0);
}

