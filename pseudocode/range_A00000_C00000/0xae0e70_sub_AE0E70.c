// Function: sub_AE0E70
// Address: 0xae0e70
// Size: 0xb5
// Prototype: 

int sub_AE0E70()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C91C18, (int)Registry, (int)"PComponent", 12, 4, (int)GlobalTypeAccessor, 0);
  unk_C91CA8 |= 2u;
  dword_C91C18[0] = &Phyre::PClassDescriptorAbstract<Phyre::PComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C91C18, (int)&unk_C91D90);
  Phyre_PObject_SetField68(dword_C91C18, (int)&unk_C91DA0);
  Phyre_PObject_SetField6C(dword_C91C18, (int)&unk_C91DB0);
  unk_C91CA8 &= ~2u;
  dword_C91C18[0] = &Phyre::PClassDescriptorConcrete<Phyre::PComponent>::`vftable';
  return atexit(sub_AFA5A0);
}

