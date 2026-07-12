// Function: sub_AE2E10
// Address: 0xae2e10
// Size: 0xb5
// Prototype: 

int sub_AE2E10()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9B720,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferLocation",
    2,
    2,
    (int)GlobalTypeAccessor,
    0);
  unk_C9B7B0 |= 2u;
  dword_C9B720[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferLocation>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9B720, (int)&unk_C9BC40);
  Phyre_PObject_SetField68(dword_C9B720, (int)&unk_C9BC50);
  Phyre_PObject_SetField6C(dword_C9B720, (int)&unk_C9BC60);
  unk_C9B7B0 &= ~2u;
  dword_C9B720[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PShaderParameterCaptureBufferLocation>::`vftable';
  return atexit(sub_AFD280);
}

