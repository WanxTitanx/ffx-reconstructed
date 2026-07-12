// Function: sub_AF20D0
// Address: 0xaf20d0
// Size: 0xb4
// Prototype: 

int sub_AF20D0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1940E60,
    (int)Registry,
    (int)"PInputSourceMouseDeltaY",
    40,
    4,
    (int)dword_1940AD0,
    0);
  unk_1940EF0 |= 2u;
  dword_1940E60[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMouseDeltaY>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940E60, (int)&unk_1942250);
  Phyre_PObject_SetField68(dword_1940E60, (int)&unk_1942280);
  Phyre_PObject_SetField6C(dword_1940E60, (int)&unk_19422B0);
  unk_1940EF0 &= ~2u;
  dword_1940E60[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMouseDeltaY>::`vftable';
  return atexit(sub_B08020);
}

