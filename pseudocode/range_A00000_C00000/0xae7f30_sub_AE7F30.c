// Function: sub_AE7F30
// Address: 0xae7f30
// Size: 0xcb
// Prototype: 

int sub_AE7F30()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAA558,
    (int)Registry,
    (int)"PAnimationClipBinding",
    8,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CAA5E8 |= 2u;
  dword_CAA558[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationClipBinding>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAA558, (int)&unk_CAA7C0);
  Phyre_PObject_SetField68(dword_CAA558, (int)&unk_CAA7D0);
  Phyre_PObject_SetField6C(dword_CAA558, (int)&unk_CAA7E0);
  psub_5110D0 = sub_5110D0;
  dword_CAA558[0] = &Phyre::PClassDescriptorHeader<Phyre::PAnimation::PAnimationClipBinding>::`vftable';
  unk_CAA5E8 = unk_CAA5E8 & 0xFFFFFFF1 | 4;
  return atexit(sub_B003E0);
}

