// Function: sub_AEA350
// Address: 0xaea350
// Size: 0xb5
// Prototype: 

int sub_AEA350()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB1E20, (int)Registry, (int)"PTextureAtlasInfo", 12, 4, (int)GlobalTypeAccessor, 0);
  unk_CB1EB0 |= 2u;
  dword_CB1E20[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSprite::PTextureAtlasInfo>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB1E20, (int)&unk_CB2CC0);
  Phyre_PObject_SetField68(dword_CB1E20, (int)&unk_CB2CD0);
  Phyre_PObject_SetField6C(dword_CB1E20, (int)&unk_CB2CE0);
  unk_CB1EB0 &= ~2u;
  dword_CB1E20[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSprite::PTextureAtlasInfo>::`vftable';
  return atexit(sub_B02C50);
}

