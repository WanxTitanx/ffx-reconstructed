// Function: sub_AF1E90
// Address: 0xaf1e90
// Size: 0xb4
// Prototype: 

int sub_AF1E90()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_19413B8,
    (int)Registry,
    (int)"PInputSourceMotionQuatZ",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_1941448 |= 2u;
  dword_19413B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionQuatZ>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19413B8, (int)&unk_19425E0);
  Phyre_PObject_SetField68(dword_19413B8, (int)&unk_1942600);
  Phyre_PObject_SetField6C(dword_19413B8, (int)&unk_1942620);
  unk_1941448 &= ~2u;
  dword_19413B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMotionQuatZ>::`vftable';
  return atexit(sub_B07FC0);
}

