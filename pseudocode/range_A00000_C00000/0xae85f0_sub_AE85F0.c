// Function: sub_AE85F0
// Address: 0xae85f0
// Size: 0xb4
// Prototype: 

int sub_AE85F0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CABA08, (int)Registry, (int)"PTimeIntervalController", 24, 4, (int)dword_CAB920, 0);
  unk_CABA98 |= 2u;
  dword_CABA08[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PTimeIntervalController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CABA08, (int)&unk_CABB50);
  Phyre_PObject_SetField68(dword_CABA08, (int)&unk_CABB70);
  Phyre_PObject_SetField6C(dword_CABA08, (int)&unk_CABB90);
  unk_CABA98 &= ~2u;
  dword_CABA08[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PTimeIntervalController>::`vftable';
  return atexit(sub_B00BA0);
}

