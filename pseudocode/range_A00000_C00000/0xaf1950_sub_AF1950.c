// Function: sub_AF1950
// Address: 0xaf1950
// Size: 0xb4
// Prototype: 

int sub_AF1950()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1941618,
    (int)Registry,
    (int)"PInputSourceMotionAngularVelocityZ",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_19416A8 |= 2u;
  dword_1941618[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionAngularVelocityZ>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941618, (int)&unk_1942760);
  Phyre_PObject_SetField68(dword_1941618, (int)&unk_1942780);
  Phyre_PObject_SetField6C(dword_1941618, (int)&unk_19427A0);
  unk_19416A8 &= ~2u;
  dword_1941618[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionAngularVelocityZ>::`vftable';
  return atexit(sub_B07EE0);
}

