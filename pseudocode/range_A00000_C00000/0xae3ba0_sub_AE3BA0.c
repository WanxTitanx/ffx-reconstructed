// Function: sub_AE3BA0
// Address: 0xae3ba0
// Size: 0xb4
// Prototype: 

int sub_AE3BA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9BEF8,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferTexture2D",
    16,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9BF88 |= 2u;
  dword_C9BEF8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferTexture2D>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9BEF8, (int)&unk_C9D3B0);
  Phyre_PObject_SetField68(dword_C9BEF8, (int)&unk_C9D3C0);
  Phyre_PObject_SetField6C(dword_C9BEF8, (int)&unk_C9D3D0);
  unk_C9BF88 &= ~2u;
  dword_C9BEF8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferTexture2D>::`vftable';
  return atexit(sub_AFD580);
}

