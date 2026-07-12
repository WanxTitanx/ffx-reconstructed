// Function: sub_AE3A20
// Address: 0xae3a20
// Size: 0xb5
// Prototype: 

int sub_AE3A20()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9BD30,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferStream",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C9BDC0 |= 2u;
  dword_C9BD30[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferStream>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9BD30, (int)&unk_C9D350);
  Phyre_PObject_SetField68(dword_C9BD30, (int)&unk_C9D360);
  Phyre_PObject_SetField6C(dword_C9BD30, (int)&unk_C9D370);
  unk_C9BDC0 &= ~2u;
  dword_C9BD30[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferStream>::`vftable';
  return atexit(sub_AFD540);
}

