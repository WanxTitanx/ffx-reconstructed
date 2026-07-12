// Function: sub_AE80C0
// Address: 0xae80c0
// Size: 0xb5
// Prototype: 

int sub_AE80C0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAA4C0,
    (int)Registry,
    (int)"PAnimationClipBindingDataBlockCache",
    16,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CAA550 |= 2u;
  dword_CAA4C0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationClipBinding::PAnimationClipBindingDataBlockCache>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAA4C0, (int)&unk_CAA790);
  Phyre_PObject_SetField68(dword_CAA4C0, (int)&unk_CAA7A0);
  Phyre_PObject_SetField6C(dword_CAA4C0, (int)&unk_CAA7B0);
  unk_CAA550 &= ~2u;
  dword_CAA4C0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationClipBinding::PAnimationClipBindingDataBlockCache>::`vftable';
  return atexit(sub_B00420);
}

