// Function: sub_AE8E10
// Address: 0xae8e10
// Size: 0xb4
// Prototype: 

int sub_AE8E10()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CACC00,
    (int)Registry,
    (int)"PAnimationTargetBlenderController",
    16,
    4,
    (int)dword_CABD28,
    0);
  unk_CACC90 |= 2u;
  dword_CACC00[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationTargetBlenderController>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CACC00, (int)&unk_CACCD0);
  Phyre_PObject_SetField68(dword_CACC00, (int)&unk_CACCE0);
  Phyre_PObject_SetField6C(dword_CACC00, (int)&unk_CACCF0);
  unk_CACC90 &= ~2u;
  dword_CACC00[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAnimation::PAnimationTargetBlenderController>::`vftable';
  return atexit(sub_B00F40);
}

