// Function: sub_AE1640
// Address: 0xae1640
// Size: 0xbe
// Prototype: 

int sub_AE1640()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C94350, (int)Registry, (int)"PRandomGenerator", 1, 1, (int)GlobalTypeAccessor, 0);
  unk_C943E0 |= 2u;
  dword_C94350[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRandom::PRandomGenerator>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C94350, (int)&unk_C94420);
  Phyre_PObject_SetField68(dword_C94350, (int)&unk_C94430);
  Phyre_PObject_SetField6C(dword_C94350, (int)&unk_C94440);
  dword_C94350[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRandom::PRandomGenerator>::`vftable';
  unk_C943E0 = unk_C943E0 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFB0B0);
}

