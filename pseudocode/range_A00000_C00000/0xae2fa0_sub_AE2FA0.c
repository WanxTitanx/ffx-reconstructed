// Function: sub_AE2FA0
// Address: 0xae2fa0
// Size: 0xb4
// Prototype: 

int sub_AE2FA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9B850,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferLocationType",
    4,
    2,
    (int)dword_C9B720,
    0);
  unk_C9B8E0 |= 2u;
  dword_C9B850[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferLocationType>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9B850, (int)&unk_C9BCA0);
  Phyre_PObject_SetField68(dword_C9B850, (int)&unk_C9BCB0);
  Phyre_PObject_SetField6C(dword_C9B850, (int)&unk_C9BCC0);
  unk_C9B8E0 &= ~2u;
  dword_C9B850[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferLocationType>::`vftable';
  return atexit(sub_AFD2C0);
}

