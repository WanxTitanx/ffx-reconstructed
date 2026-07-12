// Function: sub_AF1B90
// Address: 0xaf1b90
// Size: 0xb4
// Prototype: 

int sub_AF1B90()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_19417E0,
    (int)Registry,
    (int)"PInputSourceMotionLinearAccelerationZ",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_1941870 |= 2u;
  dword_19417E0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionLinearAccelerationZ>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19417E0, (int)&unk_1942880);
  Phyre_PObject_SetField68(dword_19417E0, (int)&unk_19428A0);
  Phyre_PObject_SetField6C(dword_19417E0, (int)&unk_19428C0);
  unk_1941870 &= ~2u;
  dword_19417E0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionLinearAccelerationZ>::`vftable';
  return atexit(sub_B07F40);
}

