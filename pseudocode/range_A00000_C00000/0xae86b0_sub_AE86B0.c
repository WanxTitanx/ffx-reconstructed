// Function: sub_AE86B0
// Address: 0xae86b0
// Size: 0xb4
// Prototype: 

int sub_AE86B0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CABBA8,
    (int)Registry,
    (int)"PTimeScaleOffsetController",
    20,
    4,
    (int)dword_CAB920,
    0);
  unk_CABC38 |= 2u;
  dword_CABBA8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PTimeScaleOffsetController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CABBA8, (int)&unk_CABCD0);
  Phyre_PObject_SetField68(dword_CABBA8, (int)&unk_CABCF0);
  Phyre_PObject_SetField6C(dword_CABBA8, (int)&unk_CABD10);
  unk_CABC38 &= ~2u;
  dword_CABBA8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PTimeScaleOffsetController>::`vftable';
  return atexit(sub_B00C00);
}

