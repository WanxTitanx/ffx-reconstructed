// Function: sub_AF1AD0
// Address: 0xaf1ad0
// Size: 0xb4
// Prototype: 

int sub_AF1AD0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1941748,
    (int)Registry,
    (int)"PInputSourceMotionLinearAccelerationY",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_19417D8 |= 2u;
  dword_1941748[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionLinearAccelerationY>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941748, (int)&unk_1942820);
  Phyre_PObject_SetField68(dword_1941748, (int)&unk_1942840);
  Phyre_PObject_SetField6C(dword_1941748, (int)&unk_1942860);
  unk_19417D8 &= ~2u;
  dword_1941748[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionLinearAccelerationY>::`vftable';
  return atexit(sub_B07F20);
}

