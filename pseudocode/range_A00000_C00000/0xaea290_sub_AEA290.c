// Function: sub_AEA290
// Address: 0xaea290
// Size: 0xb5
// Prototype: 

int sub_AEA290()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB1D88, (int)Registry, (int)"PSubTextureInfo", 20, 4, (int)GlobalTypeAccessor, 0);
  unk_CB1E18 |= 2u;
  dword_CB1D88[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSprite::PSubTextureInfo>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB1D88, (int)&unk_CB2C60);
  Phyre_PObject_SetField68(dword_CB1D88, (int)&unk_CB2C80);
  Phyre_PObject_SetField6C(dword_CB1D88, (int)&unk_CB2CA0);
  unk_CB1E18 &= ~2u;
  dword_CB1D88[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSprite::PSubTextureInfo>::`vftable';
  return atexit(sub_B02C30);
}

