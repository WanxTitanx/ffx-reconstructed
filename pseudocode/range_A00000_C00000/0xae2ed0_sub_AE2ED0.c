// Function: sub_AE2ED0
// Address: 0xae2ed0
// Size: 0xb4
// Prototype: 

int sub_AE2ED0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9B7B8,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferLocationSize",
    4,
    2,
    (int)dword_C9B720,
    0);
  unk_C9B848 |= 2u;
  dword_C9B7B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferLocationSize>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9B7B8, (int)&unk_C9BC70);
  Phyre_PObject_SetField68(dword_C9B7B8, (int)&unk_C9BC80);
  Phyre_PObject_SetField6C(dword_C9B7B8, (int)&unk_C9BC90);
  unk_C9B848 &= ~2u;
  dword_C9B7B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferLocationSize>::`vftable';
  return atexit(sub_AFD2A0);
}

