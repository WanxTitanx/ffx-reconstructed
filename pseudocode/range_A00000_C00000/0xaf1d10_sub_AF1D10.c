// Function: sub_AF1D10
// Address: 0xaf1d10
// Size: 0xb4
// Prototype: 

int sub_AF1D10()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1941288,
    (int)Registry,
    (int)"PInputSourceMotionQuatX",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_1941318 |= 2u;
  dword_1941288[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionQuatX>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941288, (int)&unk_1942520);
  Phyre_PObject_SetField68(dword_1941288, (int)&unk_1942540);
  Phyre_PObject_SetField6C(dword_1941288, (int)&unk_1942560);
  unk_1941318 &= ~2u;
  dword_1941288[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionQuatX>::`vftable';
  return atexit(sub_B07F80);
}

