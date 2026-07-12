// Function: sub_AE8770
// Address: 0xae8770
// Size: 0xa3
// Prototype: 

int sub_AE8770()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CABD28, (int)Registry, (int)"PAnimationDataSource", 12, 16, (int)dword_CAB858, 0);
  unk_CABDB8 |= 2u;
  dword_CABD28[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationDataSource>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CABD28, (int)&unk_CABDF0);
  Phyre_PObject_SetField68(dword_CABD28, (int)&unk_CABE00);
  Phyre_PObject_SetField6C(dword_CABD28, (int)&unk_CABE10);
  return atexit(sub_B00C50);
}

