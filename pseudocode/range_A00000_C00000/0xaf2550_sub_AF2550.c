// Function: sub_AF2550
// Address: 0xaf2550
// Size: 0xb4
// Prototype: 

int sub_AF2550()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_19411F0,
    (int)Registry,
    (int)"PInputSourceTouchTwoFingerDragY",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_1941280 |= 2u;
  dword_19411F0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceTouchTwoFingerDragY>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19411F0, (int)&unk_1942400);
  Phyre_PObject_SetField68(dword_19411F0, (int)&unk_1942420);
  Phyre_PObject_SetField6C(dword_19411F0, (int)&unk_1942440);
  unk_1941280 &= ~2u;
  dword_19411F0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceTouchTwoFingerDragY>::`vftable';
  return atexit(sub_B080E0);
}

