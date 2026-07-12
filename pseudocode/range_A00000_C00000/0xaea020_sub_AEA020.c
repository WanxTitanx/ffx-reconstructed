// Function: sub_AEA020
// Address: 0xaea020
// Size: 0xb5
// Prototype: 

int sub_AEA020()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CB1EB8,
    (int)Registry,
    (int)"PSpriteAnimationInfo",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CB1F48 |= 2u;
  dword_CB1EB8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSprite::PSpriteAnimationInfo>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB1EB8, (int)&unk_CB2CF0);
  Phyre_PObject_SetField68(dword_CB1EB8, (int)&unk_CB2D10);
  Phyre_PObject_SetField6C(dword_CB1EB8, (int)&unk_CB2D30);
  unk_CB1F48 &= ~2u;
  dword_CB1EB8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSprite::PSpriteAnimationInfo>::`vftable';
  return atexit(sub_B02BB0);
}

