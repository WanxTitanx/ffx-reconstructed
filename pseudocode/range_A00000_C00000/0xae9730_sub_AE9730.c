// Function: sub_AE9730
// Address: 0xae9730
// Size: 0xb4
// Prototype: 

int sub_AE9730()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAF540, (int)Registry, (int)"PQuarryComponent", 92, 4, (int)dword_C91C18, 0);
  unk_CAF5D0 |= 2u;
  dword_CAF540[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PQuarryComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAF540, (int)&unk_CAF660);
  Phyre_PObject_SetField68(dword_CAF540, (int)&unk_CAF6C0);
  Phyre_PObject_SetField6C(dword_CAF540, (int)&unk_CAF720);
  unk_CAF5D0 &= ~2u;
  dword_CAF540[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PQuarryComponent>::`vftable';
  return atexit(sub_B02090);
}

