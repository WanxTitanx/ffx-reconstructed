// Function: sub_AF3FF0
// Address: 0xaf3ff0
// Size: 0xb4
// Prototype: 

int sub_AF3FF0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1943C70,
    (int)Registry,
    (int)"PScreenSpaceAmbientOcclusion",
    40,
    4,
    (int)dword_1943D08,
    0);
  unk_1943D00 |= 2u;
  dword_1943C70[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusion>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943C70, (int)&unk_1979880);
  Phyre_PObject_SetField68(dword_1943C70, (int)&unk_19798B0);
  Phyre_PObject_SetField6C(dword_1943C70, (int)&unk_19798E0);
  unk_1943D00 &= ~2u;
  dword_1943C70[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusion>::`vftable';
  return atexit(sub_B089F0);
}

