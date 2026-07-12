// Function: sub_AF2D30
// Address: 0xaf2d30
// Size: 0xb7
// Prototype: 

int sub_AF2D30()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1943680,
    (int)Registry,
    (int)"PDeferredLightingBase",
    16276,
    4,
    (int)dword_19435E8,
    0);
  unk_1943710 |= 2u;
  dword_1943680[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PDeferredLightingBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943680, (int)&unk_19451A0);
  Phyre_PObject_SetField68(dword_1943680, (int)&unk_1949140);
  Phyre_PObject_SetField6C(dword_1943680, (int)&unk_194D0E0);
  unk_1943710 &= ~2u;
  dword_1943680[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PDeferredLightingBase>::`vftable';
  return atexit(sub_B086D0);
}

