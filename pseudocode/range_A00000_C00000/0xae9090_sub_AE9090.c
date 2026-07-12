// Function: sub_AE9090
// Address: 0xae9090
// Size: 0xb7
// Prototype: 

int sub_AE9090()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CADA40, (int)Registry, (int)"PAnimatableComponent", 132, 4, (int)dword_C91C18, 4);
  unk_CADAD0 |= 2u;
  dword_CADA40[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimatableComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CADA40, (int)&unk_CAE310);
  Phyre_PObject_SetField68(dword_CADA40, (int)&unk_CAE3A0);
  Phyre_PObject_SetField6C(dword_CADA40, (int)&unk_CAE430);
  unk_CADAD0 &= ~2u;
  dword_CADA40[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimatableComponent>::`vftable';
  return atexit(sub_B01220);
}

