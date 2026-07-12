// Function: sub_AE9210
// Address: 0xae9210
// Size: 0xb5
// Prototype: 

int sub_AE9210()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAE550, (int)Registry, (int)"PLocator", 12, 4, (int)GlobalTypeAccessor, 0);
  unk_CAE5E0 |= 2u;
  dword_CAE550[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PLocator>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAE550, (int)&unk_CAE770);
  Phyre_PObject_SetField68(dword_CAE550, (int)&unk_CAE780);
  Phyre_PObject_SetField6C(dword_CAE550, (int)&unk_CAE790);
  unk_CAE5E0 &= ~2u;
  dword_CAE550[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PLocator>::`vftable';
  return atexit(sub_B01920);
}

