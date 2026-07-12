// Function: sub_AEA0E0
// Address: 0xaea0e0
// Size: 0xb4
// Prototype: 

int sub_AEA0E0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB1F50, (int)Registry, (int)"PSpriteAnimationInfoChar", 40, 4, (int)dword_CB1EB8, 0);
  unk_CB1FE0 |= 2u;
  dword_CB1F50[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSprite::PSpriteAnimationInfoChar>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB1F50, (int)&unk_CB2D50);
  Phyre_PObject_SetField68(dword_CB1F50, (int)&unk_CB2D80);
  Phyre_PObject_SetField6C(dword_CB1F50, (int)&unk_CB2DB0);
  unk_CB1FE0 &= ~2u;
  dword_CB1F50[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSprite::PSpriteAnimationInfoChar>::`vftable';
  return atexit(sub_B02BD0);
}

