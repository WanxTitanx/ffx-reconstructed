// Function: sub_AF1C50
// Address: 0xaf1c50
// Size: 0xb4
// Prototype: 

int sub_AF1C50()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1941450,
    (int)Registry,
    (int)"PInputSourceMotionQuatW",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_19414E0 |= 2u;
  dword_1941450[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionQuatW>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941450, (int)&unk_1942640);
  Phyre_PObject_SetField68(dword_1941450, (int)&unk_1942660);
  Phyre_PObject_SetField6C(dword_1941450, (int)&unk_1942680);
  unk_19414E0 &= ~2u;
  dword_1941450[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionQuatW>::`vftable';
  return atexit(sub_B07F60);
}

