// Function: sub_AF43B0
// Address: 0xaf43b0
// Size: 0xb7
// Prototype: 

int sub_AF43B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1944808,
    (int)Registry,
    (int)"PScreenSpaceReflectionD3D11",
    148,
    4,
    (int)dword_19446D8,
    0);
  unk_1944898 |= 2u;
  dword_1944808[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PScreenSpaceReflectionD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1944808, (int)&unk_1984830);
  Phyre_PObject_SetField68(dword_1944808, (int)&unk_19848D0);
  Phyre_PObject_SetField6C(dword_1944808, (int)&unk_1984970);
  unk_1944898 &= ~2u;
  dword_1944808[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PScreenSpaceReflectionD3D11>::`vftable';
  return atexit(sub_B08A90);
}

