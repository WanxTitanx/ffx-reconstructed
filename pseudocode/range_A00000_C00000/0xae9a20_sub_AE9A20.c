// Function: sub_AE9A20
// Address: 0xae9a20
// Size: 0xb4
// Prototype: 

int sub_AE9A20()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAFD60, (int)Registry, (int)"PSplineFollowerComponent", 28, 4, (int)dword_C91C18, 0);
  unk_CAFDF0 |= 2u;
  dword_CAFD60[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PSplineFollowerComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAFD60, (int)&unk_CAFEB0);
  Phyre_PObject_SetField68(dword_CAFD60, (int)&unk_CAFED0);
  Phyre_PObject_SetField6C(dword_CAFD60, (int)&unk_CAFEF0);
  unk_CAFDF0 &= ~2u;
  dword_CAFD60[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PSplineFollowerComponent>::`vftable';
  return atexit(sub_B02370);
}

