// Function: sub_AEA410
// Address: 0xaea410
// Size: 0xb5
// Prototype: 

int sub_AEA410()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB3158,
    (int)Registry,
    (int)"PSpriteAnimationInfoInstance",
    40,
    8,
    (int)GlobalTypeAccessor,
    0);
  unk_CB31E8 |= 2u;
  dword_CB3158[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSprite::PSpriteAnimationInfoInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB3158, (int)&unk_CB32D0);
  Phyre_PObject_SetField68(dword_CB3158, (int)&unk_CB3300);
  Phyre_PObject_SetField6C(dword_CB3158, (int)&unk_CB3330);
  unk_CB31E8 &= ~2u;
  dword_CB3158[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSprite::PSpriteAnimationInfoInstance>::`vftable';
  return atexit(sub_B034F0);
}

