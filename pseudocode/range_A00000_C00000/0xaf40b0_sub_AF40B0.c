// Function: sub_AF40B0
// Address: 0xaf40b0
// Size: 0xb4
// Prototype: 

int sub_AF40B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1943BD8,
    (int)Registry,
    (int)"PScreenSpaceAmbientOcclusionBase",
    40,
    4,
    (int)dword_19435E8,
    0);
  unk_1943C68 |= 2u;
  dword_1943BD8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusionBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943BD8, (int)&unk_1979760);
  Phyre_PObject_SetField68(dword_1943BD8, (int)&unk_1979790);
  Phyre_PObject_SetField6C(dword_1943BD8, (int)&unk_19797C0);
  unk_1943C68 &= ~2u;
  dword_1943BD8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusionBase>::`vftable';
  return atexit(sub_B08A10);
}

