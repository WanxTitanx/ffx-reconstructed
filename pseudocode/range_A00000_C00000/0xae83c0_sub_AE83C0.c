// Function: sub_AE83C0
// Address: 0xae83c0
// Size: 0xb5
// Prototype: 

int sub_AE83C0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAB580, (int)Registry, (int)"PAnimationEventList", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_CAB610 |= 2u;
  dword_CAB580[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationEventList>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAB580, (int)&unk_CAB800);
  Phyre_PObject_SetField68(dword_CAB580, (int)&unk_CAB810);
  Phyre_PObject_SetField6C(dword_CAB580, (int)&unk_CAB820);
  unk_CAB610 &= ~2u;
  dword_CAB580[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationEventList>::`vftable';
  return atexit(sub_B00A80);
}

