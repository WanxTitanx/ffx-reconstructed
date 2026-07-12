// Function: sub_AF2490
// Address: 0xaf2490
// Size: 0xb4
// Prototype: 

int sub_AF2490()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1941158,
    (int)Registry,
    (int)"PInputSourceTouchTwoFingerDragX",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_19411E8 |= 2u;
  dword_1941158[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceTouchTwoFingerDragX>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941158, (int)&unk_19423A0);
  Phyre_PObject_SetField68(dword_1941158, (int)&unk_19423C0);
  Phyre_PObject_SetField6C(dword_1941158, (int)&unk_19423E0);
  unk_19411E8 &= ~2u;
  dword_1941158[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceTouchTwoFingerDragX>::`vftable';
  return atexit(sub_B080C0);
}

