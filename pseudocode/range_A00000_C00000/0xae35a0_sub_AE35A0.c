// Function: sub_AE35A0
// Address: 0xae35a0
// Size: 0xb4
// Prototype: 

int sub_AE35A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9C450,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferIndexDataBlock",
    16,
    4,
    (int)&unk_C9BDC8,
    0);
  unk_C9C4E0 |= 2u;
  dword_C9C450[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferIndexDataBlock>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C450, (int)&unk_C9D6B0);
  Phyre_PObject_SetField68(dword_C9C450, (int)&unk_C9D6C0);
  Phyre_PObject_SetField6C(dword_C9C450, (int)&unk_C9D6D0);
  unk_C9C4E0 &= ~2u;
  dword_C9C450[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferIndexDataBlock>::`vftable';
  return atexit(sub_AFD480);
}

