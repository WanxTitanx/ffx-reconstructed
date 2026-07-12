// Function: sub_AE9150
// Address: 0xae9150
// Size: 0xb5
// Prototype: 

int sub_AE9150()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAD9A8,
    (int)Registry,
    (int)"PBlendableAnimationSource",
    76,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CADA38 |= 2u;
  dword_CAD9A8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PBlendableAnimationSource>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAD9A8, (int)&unk_CAE220);
  Phyre_PObject_SetField68(dword_CAD9A8, (int)&unk_CAE270);
  Phyre_PObject_SetField6C(dword_CAD9A8, (int)&unk_CAE2C0);
  unk_CADA38 &= ~2u;
  dword_CAD9A8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PBlendableAnimationSource>::`vftable';
  return atexit(sub_B01240);
}

