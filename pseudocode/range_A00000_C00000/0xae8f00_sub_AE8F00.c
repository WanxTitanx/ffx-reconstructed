// Function: sub_AE8F00
// Address: 0xae8f00
// Size: 0xb5
// Prototype: 

int sub_AE8F00()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CACE48,
    (int)Registry,
    (int)"PAnimationNetworkInstance",
    60,
    4,
    (int)GlobalTypeAccessor,
    4);
  unk_CACED8 |= 2u;
  dword_CACE48[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationNetworkInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CACE48, (int)&unk_CAD820);
  Phyre_PObject_SetField68(dword_CACE48, (int)&unk_CAD860);
  Phyre_PObject_SetField6C(dword_CACE48, (int)&unk_CAD8A0);
  unk_CACED8 &= ~2u;
  dword_CACE48[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationNetworkInstance>::`vftable';
  return atexit(sub_B00F90);
}

