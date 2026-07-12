// Function: sub_AE8530
// Address: 0xae8530
// Size: 0xb4
// Prototype: 

int sub_AE8530()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CAB920, (int)Registry, (int)"PTimeController", 8, 4, (int)dword_CAB858, 0);
  unk_CAB9B0 |= 2u;
  dword_CAB920[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PTimeController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAB920, (int)&unk_CAB9E0);
  Phyre_PObject_SetField68(dword_CAB920, (int)&unk_CAB9F0);
  Phyre_PObject_SetField6C(dword_CAB920, (int)&unk_CABA00);
  unk_CAB9B0 &= ~2u;
  dword_CAB920[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PTimeController>::`vftable';
  return atexit(sub_B00B40);
}

