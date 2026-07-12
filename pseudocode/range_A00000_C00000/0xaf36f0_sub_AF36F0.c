// Function: sub_AF36F0
// Address: 0xaf36f0
// Size: 0xb5
// Prototype: 

int sub_AF36F0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_19442B0, (int)Registry, (int)"PLegacyGlowBase", 120, 4, (int)GlobalTypeAccessor, 0);
  unk_1944340 |= 2u;
  dword_19442B0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PLegacyGlowBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19442B0, (int)&unk_1983BD0);
  Phyre_PObject_SetField68(dword_19442B0, (int)&unk_1983C50);
  Phyre_PObject_SetField6C(dword_19442B0, (int)&unk_1983CD0);
  unk_1944340 &= ~2u;
  dword_19442B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PLegacyGlowBase>::`vftable';
  return atexit(sub_B08870);
}

