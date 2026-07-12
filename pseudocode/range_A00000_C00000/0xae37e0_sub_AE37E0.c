// Function: sub_AE37E0
// Address: 0xae37e0
// Size: 0xb4
// Prototype: 

int sub_AE37E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C4E8,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferRWTexture2D",
    16,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C578 |= 2u;
  dword_C9C4E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferRWTexture2D>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C4E8, (int)&unk_C9D440);
  Phyre_PObject_SetField68(dword_C9C4E8, (int)&unk_C9D450);
  Phyre_PObject_SetField6C(dword_C9C4E8, (int)&unk_C9D460);
  unk_C9C578 &= ~2u;
  dword_C9C4E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferRWTexture2D>::`vftable';
  return atexit(sub_AFD4E0);
}

