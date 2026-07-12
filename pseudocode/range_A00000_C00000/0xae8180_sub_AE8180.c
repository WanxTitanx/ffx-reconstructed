// Function: sub_AE8180
// Address: 0xae8180
// Size: 0xb5
// Prototype: 

int sub_AE8180()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAA7E8, (int)Registry, (int)"PAnimationClip", 32, 4, (int)GlobalTypeAccessor, 0);
  unk_CAA878 |= 2u;
  dword_CAA7E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationClip>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAA7E8, (int)&unk_CAADA0);
  Phyre_PObject_SetField68(dword_CAA7E8, (int)&unk_CAADC0);
  Phyre_PObject_SetField6C(dword_CAA7E8, (int)&unk_CAADE0);
  unk_CAA878 &= ~2u;
  dword_CAA7E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationClip>::`vftable';
  return atexit(sub_B004C0);
}

