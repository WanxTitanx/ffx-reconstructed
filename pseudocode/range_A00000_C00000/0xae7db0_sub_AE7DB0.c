// Function: sub_AE7DB0
// Address: 0xae7db0
// Size: 0xb4
// Prototype: 

int sub_AE7DB0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAA0B8, (int)Registry, (int)"PAnimationChannel", 52, 4, (int)dword_CA9F30, 0);
  unk_CAA148 |= 2u;
  dword_CAA0B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationChannel>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAA0B8, (int)&unk_CAA1E0);
  Phyre_PObject_SetField68(dword_CAA0B8, (int)&unk_CAA220);
  Phyre_PObject_SetField6C(dword_CAA0B8, (int)&unk_CAA260);
  unk_CAA148 &= ~2u;
  dword_CAA0B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationChannel>::`vftable';
  return atexit(sub_B00360);
}

