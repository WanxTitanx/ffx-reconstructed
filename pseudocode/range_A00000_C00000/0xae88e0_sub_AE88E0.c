// Function: sub_AE88E0
// Address: 0xae88e0
// Size: 0xb4
// Prototype: 

int sub_AE88E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CABF68, (int)Registry, (int)"PAnimationController", 20, 4, (int)dword_CABD28, 0);
  unk_CABFF8 |= 2u;
  dword_CABF68[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CABF68, (int)&unk_CAC060);
  Phyre_PObject_SetField68(dword_CABF68, (int)&unk_CAC080);
  Phyre_PObject_SetField6C(dword_CABF68, (int)&unk_CAC0A0);
  unk_CABFF8 &= ~2u;
  dword_CABF68[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationController>::`vftable';
  return atexit(sub_B00CC0);
}

