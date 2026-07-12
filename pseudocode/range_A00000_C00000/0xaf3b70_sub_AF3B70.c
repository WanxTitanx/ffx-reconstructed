// Function: sub_AF3B70
// Address: 0xaf3b70
// Size: 0xb7
// Prototype: 

int sub_AF3B70()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1943FB8,
    (int)Registry,
    (int)"PMeshParticleSystemBase",
    12780,
    4,
    (int)dword_19435E8,
    0);
  unk_1944048 |= 2u;
  dword_1943FB8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PMeshParticleSystemBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943FB8, (int)&unk_1979E20);
  Phyre_PObject_SetField68(dword_1943FB8, (int)&unk_197D010);
  Phyre_PObject_SetField6C(dword_1943FB8, (int)&unk_1980200);
  unk_1944048 &= ~2u;
  dword_1943FB8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PMeshParticleSystemBase>::`vftable';
  return atexit(sub_B08930);
}

