// Function: sub_AE8FC0
// Address: 0xae8fc0
// Size: 0xb5
// Prototype: 

int sub_AE8FC0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CACDB0,
    (int)Registry,
    (int)"PAnimationNetworkInstanceTarget",
    24,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CACE40 |= 2u;
  dword_CACDB0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationNetworkInstanceTarget>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CACDB0, (int)&unk_CAD7C0);
  Phyre_PObject_SetField68(dword_CACDB0, (int)&unk_CAD7E0);
  Phyre_PObject_SetField6C(dword_CACDB0, (int)&unk_CAD800);
  unk_CACE40 &= ~2u;
  dword_CACDB0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationNetworkInstanceTarget>::`vftable';
  return atexit(sub_B00FB0);
}

