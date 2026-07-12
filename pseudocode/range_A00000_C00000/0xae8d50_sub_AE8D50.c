// Function: sub_AE8D50
// Address: 0xae8d50
// Size: 0xb4
// Prototype: 

int sub_AE8D50()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CACB00,
    (int)Registry,
    (int)"PAnimationSpuTargetBlenderController",
    16,
    4,
    (int)dword_CABD28,
    0);
  unk_CACB90 |= 2u;
  dword_CACB00[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationSpuTargetBlenderController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CACB00, (int)&unk_CACBD0);
  Phyre_PObject_SetField68(dword_CACB00, (int)&unk_CACBE0);
  Phyre_PObject_SetField6C(dword_CACB00, (int)&unk_CACBF0);
  unk_CACB90 &= ~2u;
  dword_CACB00[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationSpuTargetBlenderController>::`vftable';
  return atexit(sub_B00F10);
}

