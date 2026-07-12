// Function: sub_AE8A60
// Address: 0xae8a60
// Size: 0xb5
// Prototype: 

int sub_AE8A60()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAC0B8,
    (int)Registry,
    (int)"PAnimationSlotFilterDeferredLoad",
    8,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CAC148 |= 2u;
  dword_CAC0B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationSlotFilterDeferredLoad>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAC0B8, (int)&unk_CAC520);
  Phyre_PObject_SetField68(dword_CAC0B8, (int)&unk_CAC530);
  Phyre_PObject_SetField6C(dword_CAC0B8, (int)&unk_CAC540);
  unk_CAC148 &= ~2u;
  dword_CAC0B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationSlotFilterDeferredLoad>::`vftable';
  return atexit(sub_B00D20);
}

