// Function: sub_AF1DD0
// Address: 0xaf1dd0
// Size: 0xb4
// Prototype: 

int sub_AF1DD0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1941320,
    (int)Registry,
    (int)"PInputSourceMotionQuatY",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_19413B0 |= 2u;
  dword_1941320[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionQuatY>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941320, (int)&unk_1942580);
  Phyre_PObject_SetField68(dword_1941320, (int)&unk_19425A0);
  Phyre_PObject_SetField6C(dword_1941320, (int)&unk_19425C0);
  unk_19413B0 &= ~2u;
  dword_1941320[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionQuatY>::`vftable';
  return atexit(sub_B07FA0);
}

