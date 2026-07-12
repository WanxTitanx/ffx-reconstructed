// Function: sub_AE3EA0
// Address: 0xae3ea0
// Size: 0xb4
// Prototype: 

int sub_AE3EA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9BE60,
    (int)Registry,
    (int)"PShaderParameterCaptureConstantBuffer",
    16,
    4,
    (int)dword_C9BDC8,
    0);
  unk_C9BEF0 |= 2u;
  dword_C9BE60[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureConstantBuffer>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9BE60, (int)&unk_C9D650);
  Phyre_PObject_SetField68(dword_C9BE60, (int)&unk_C9D660);
  Phyre_PObject_SetField6C(dword_C9BE60, (int)&unk_C9D670);
  unk_C9BEF0 &= ~2u;
  dword_C9BE60[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureConstantBuffer>::`vftable';
  return atexit(sub_AFD600);
}

