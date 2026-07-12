// Function: sub_AF2010
// Address: 0xaf2010
// Size: 0xb4
// Prototype: 

int sub_AF2010()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1940DC8,
    (int)Registry,
    (int)"PInputSourceMouseDeltaX",
    40,
    4,
    (int)dword_1940AD0,
    0);
  unk_1940E58 |= 2u;
  dword_1940DC8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMouseDeltaX>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940DC8, (int)&unk_19421C0);
  Phyre_PObject_SetField68(dword_1940DC8, (int)&unk_19421F0);
  Phyre_PObject_SetField6C(dword_1940DC8, (int)&unk_1942220);
  unk_1940E58 &= ~2u;
  dword_1940DC8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMouseDeltaX>::`vftable';
  return atexit(sub_B08000);
}

