// Function: sub_AE8820
// Address: 0xae8820
// Size: 0xb4
// Prototype: 

int sub_AE8820()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CABE20,
    (int)Registry,
    (int)"PAnimationEventController",
    20,
    4,
    (int)dword_CABD28,
    0);
  unk_CABEB0 |= 2u;
  dword_CABE20[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationEventController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CABE20, (int)&unk_CABF10);
  Phyre_PObject_SetField68(dword_CABE20, (int)&unk_CABF30);
  Phyre_PObject_SetField6C(dword_CABE20, (int)&unk_CABF50);
  unk_CABEB0 &= ~2u;
  dword_CABE20[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationEventController>::`vftable';
  return atexit(sub_B00C80);
}

