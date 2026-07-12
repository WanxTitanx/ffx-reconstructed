// Function: sub_AF4170
// Address: 0xaf4170
// Size: 0xb4
// Prototype: 

int sub_AF4170()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1943D08,
    (int)Registry,
    (int)"PScreenSpaceAmbientOcclusionD3D11",
    40,
    4,
    (int)dword_1943BD8,
    0);
  unk_1943D98 |= 2u;
  dword_1943D08[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusionD3D11>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943D08, (int)&unk_19797F0);
  Phyre_PObject_SetField68(dword_1943D08, (int)&unk_1979820);
  Phyre_PObject_SetField6C(dword_1943D08, (int)&unk_1979850);
  unk_1943D98 &= ~2u;
  dword_1943D08[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusionD3D11>::`vftable';
  return atexit(sub_B08A30);
}

