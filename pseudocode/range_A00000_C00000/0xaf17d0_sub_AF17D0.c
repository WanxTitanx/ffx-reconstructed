// Function: sub_AF17D0
// Address: 0xaf17d0
// Size: 0xb4
// Prototype: 

int sub_AF17D0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_19414E8,
    (int)Registry,
    (int)"PInputSourceMotionAngularVelocityX",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_1941578 |= 2u;
  dword_19414E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionAngularVelocityX>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19414E8, (int)&unk_19426A0);
  Phyre_PObject_SetField68(dword_19414E8, (int)&unk_19426C0);
  Phyre_PObject_SetField6C(dword_19414E8, (int)&unk_19426E0);
  unk_1941578 &= ~2u;
  dword_19414E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionAngularVelocityX>::`vftable';
  return atexit(sub_B07EA0);
}

