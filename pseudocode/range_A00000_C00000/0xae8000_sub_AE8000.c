// Function: sub_AE8000
// Address: 0xae8000
// Size: 0xb5
// Prototype: 

int sub_AE8000()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAA428,
    (int)Registry,
    (int)"PAnimationClipBindingChannelMap",
    4,
    2,
    (int)GlobalTypeAccessor,
    0);
  unk_CAA4B8 |= 2u;
  dword_CAA428[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationClipBinding::PAnimationClipBindingChannelMap>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAA428, (int)&unk_CAA760);
  Phyre_PObject_SetField68(dword_CAA428, (int)&unk_CAA770);
  Phyre_PObject_SetField6C(dword_CAA428, (int)&unk_CAA780);
  unk_CAA4B8 &= ~2u;
  dword_CAA428[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationClipBinding::PAnimationClipBindingChannelMap>::`vftable';
  return atexit(sub_B00400);
}

