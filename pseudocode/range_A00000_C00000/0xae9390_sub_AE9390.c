// Function: sub_AE9390
// Address: 0xae9390
// Size: 0xb5
// Prototype: 

int sub_AE9390()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAE7B8, (int)Registry, (int)"PSpline", 44, 4, (int)GlobalTypeAccessor, 4);
  unk_CAE848 |= 2u;
  dword_CAE7B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PSpline>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAE7B8, (int)&unk_CAEBE0);
  Phyre_PObject_SetField68(dword_CAE7B8, (int)&unk_CAEC10);
  Phyre_PObject_SetField6C(dword_CAE7B8, (int)&unk_CAEC40);
  unk_CAE848 &= ~2u;
  dword_CAE7B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PSpline>::`vftable';
  return atexit(sub_B01AE0);
}

