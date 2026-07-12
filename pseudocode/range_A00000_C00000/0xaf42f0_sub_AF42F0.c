// Function: sub_AF42F0
// Address: 0xaf42f0
// Size: 0xb7
// Prototype: 

int sub_AF42F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_19446D8,
    (int)Registry,
    (int)"PScreenSpaceReflectionBase",
    148,
    4,
    (int)dword_19435E8,
    0);
  unk_1944768 |= 2u;
  dword_19446D8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PScreenSpaceReflectionBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19446D8, (int)&unk_1984650);
  Phyre_PObject_SetField68(dword_19446D8, (int)&unk_19846F0);
  Phyre_PObject_SetField6C(dword_19446D8, (int)&unk_1984790);
  unk_1944768 &= ~2u;
  dword_19446D8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PScreenSpaceReflectionBase>::`vftable';
  return atexit(sub_B08A70);
}

