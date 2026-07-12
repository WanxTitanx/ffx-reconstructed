// Function: sub_AE3DE0
// Address: 0xae3de0
// Size: 0xb4
// Prototype: 

int sub_AE3DE0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C028,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferTextureCubeMap",
    16,
    4,
    (int)dword_C9BDC8,
    0);
  unk_C9C0B8 |= 2u;
  dword_C9C028[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferTextureCubeMap>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C028, (int)&unk_C9D410);
  Phyre_PObject_SetField68(dword_C9C028, (int)&unk_C9D420);
  Phyre_PObject_SetField6C(dword_C9C028, (int)&unk_C9D430);
  unk_C9C0B8 &= ~2u;
  dword_C9C028[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferTextureCubeMap>::`vftable';
  return atexit(sub_AFD5E0);
}

