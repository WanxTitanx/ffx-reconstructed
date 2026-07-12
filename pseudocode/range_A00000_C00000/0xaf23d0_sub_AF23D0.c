// Function: sub_AF23D0
// Address: 0xaf23d0
// Size: 0xb4
// Prototype: 

int sub_AF23D0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1940EF8,
    (int)Registry,
    (int)"PInputSourceTouchRotate",
    24,
    4,
    (int)dword_1940AD0,
    0);
  unk_1940F88 |= 2u;
  dword_1940EF8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceTouchRotate>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940EF8, (int)&unk_19422E0);
  Phyre_PObject_SetField68(dword_1940EF8, (int)&unk_1942300);
  Phyre_PObject_SetField6C(dword_1940EF8, (int)&unk_1942320);
  unk_1940F88 &= ~2u;
  dword_1940EF8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceTouchRotate>::`vftable';
  return atexit(sub_B080A0);
}

