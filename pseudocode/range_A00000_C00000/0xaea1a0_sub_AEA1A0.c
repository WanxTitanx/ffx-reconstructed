// Function: sub_AEA1A0
// Address: 0xaea1a0
// Size: 0xb5
// Prototype: 

int sub_AEA1A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB1C58, (int)Registry, (int)"PSpriteAttributes", 48, 4, (int)GlobalTypeAccessor, 0);
  unk_CB1CE8 |= 2u;
  dword_CB1C58[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSprite::PSpriteAttributes>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB1C58, (int)&unk_CB2DE0);
  Phyre_PObject_SetField68(dword_CB1C58, (int)&unk_CB2E10);
  Phyre_PObject_SetField6C(dword_CB1C58, (int)&unk_CB2E40);
  unk_CB1CE8 &= ~2u;
  dword_CB1C58[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSprite::PSpriteAttributes>::`vftable';
  return atexit(sub_B02BF0);
}

