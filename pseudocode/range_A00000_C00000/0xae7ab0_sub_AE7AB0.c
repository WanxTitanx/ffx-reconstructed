// Function: sub_AE7AB0
// Address: 0xae7ab0
// Size: 0xb5
// Prototype: 

int sub_AE7AB0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA9778,
    (int)Registry,
    (int)"PAnimationSlotListIndex",
    16,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA9808 |= 2u;
  dword_CA9778[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationSlotListIndex>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA9778, (int)&unk_CA9960);
  Phyre_PObject_SetField68(dword_CA9778, (int)&unk_CA9970);
  Phyre_PObject_SetField6C(dword_CA9778, (int)&unk_CA9980);
  unk_CA9808 &= ~2u;
  dword_CA9778[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationSlotListIndex>::`vftable';
  return atexit(sub_B000A0);
}

