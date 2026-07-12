// Function: sub_AE89A0
// Address: 0xae89a0
// Size: 0xb4
// Prototype: 

int sub_AE89A0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAC150, (int)Registry, (int)"PAnimationSlotFilter", 32, 4, (int)dword_CABD28, 0);
  unk_CAC1E0 |= 2u;
  dword_CAC150[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationSlotFilter>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAC150, (int)&unk_CAC550);
  Phyre_PObject_SetField68(dword_CAC150, (int)&unk_CAC570);
  Phyre_PObject_SetField6C(dword_CAC150, (int)&unk_CAC590);
  unk_CAC1E0 &= ~2u;
  dword_CAC150[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationSlotFilter>::`vftable';
  return atexit(sub_B00D00);
}

