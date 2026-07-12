// Function: sub_AE1320
// Address: 0xae1320
// Size: 0xb4
// Prototype: 

int sub_AE1320()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C93AE8, (int)Registry, (int)"PInstancesComponent", 20, 4, (int)dword_C91C18, 0);
  unk_C93B78 |= 2u;
  dword_C93AE8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInstancesComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C93AE8, (int)&unk_C93D80);
  Phyre_PObject_SetField68(dword_C93AE8, (int)&unk_C93DA0);
  Phyre_PObject_SetField6C(dword_C93AE8, (int)&unk_C93DC0);
  unk_C93B78 &= ~2u;
  dword_C93AE8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInstancesComponent>::`vftable';
  return atexit(sub_AFAD30);
}

