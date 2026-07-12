// Function: sub_AF1A10
// Address: 0xaf1a10
// Size: 0xb4
// Prototype: 

int sub_AF1A10()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_19416B0,
    (int)Registry,
    (int)"PInputSourceMotionLinearAccelerationX",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_1941740 |= 2u;
  dword_19416B0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionLinearAccelerationX>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19416B0, (int)&unk_19427C0);
  Phyre_PObject_SetField68(dword_19416B0, (int)&unk_19427E0);
  Phyre_PObject_SetField6C(dword_19416B0, (int)&unk_1942800);
  unk_1941740 &= ~2u;
  dword_19416B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionLinearAccelerationX>::`vftable';
  return atexit(sub_B07F00);
}

