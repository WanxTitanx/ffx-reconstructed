// Function: sub_AF1890
// Address: 0xaf1890
// Size: 0xb4
// Prototype: 

int sub_AF1890()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1941580,
    (int)Registry,
    (int)"PInputSourceMotionAngularVelocityY",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_1941610 |= 2u;
  dword_1941580[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionAngularVelocityY>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941580, (int)&unk_1942700);
  Phyre_PObject_SetField68(dword_1941580, (int)&unk_1942720);
  Phyre_PObject_SetField6C(dword_1941580, (int)&unk_1942740);
  unk_1941610 &= ~2u;
  dword_1941580[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionAngularVelocityY>::`vftable';
  return atexit(sub_B07EC0);
}

