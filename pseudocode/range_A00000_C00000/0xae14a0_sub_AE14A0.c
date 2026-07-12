// Function: sub_AE14A0
// Address: 0xae14a0
// Size: 0xbe
// Prototype: 

int sub_AE14A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C93F98, (int)Registry, (int)"PAssetReference", 40, 4, (int)GlobalTypeAccessor, 0);
  unk_C94028 |= 2u;
  dword_C93F98[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAssetReference>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C93F98, (int)&unk_C94270);
  Phyre_PObject_SetField68(dword_C93F98, (int)&unk_C942A0);
  Phyre_PObject_SetField6C(dword_C93F98, (int)&unk_C942D0);
  dword_C93F98[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PAssetReference>::`vftable';
  unk_C94028 = unk_C94028 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFAF20);
}

