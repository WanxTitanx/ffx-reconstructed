// Function: sub_AEB2E0
// Address: 0xaeb2e0
// Size: 0xb5
// Prototype: 

int sub_AEB2E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBAB20, (int)Registry, (int)"PLODGroup", 72, 4, (int)GlobalTypeAccessor, 0);
  unk_CBABB0 |= 2u;
  dword_CBAB20[0] = &Phyre::PClassDescriptorAbstract<Phyre::PLOD::PLODGroup>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBAB20, (int)&unk_CBB110);
  Phyre_PObject_SetField68(dword_CBAB20, (int)&unk_CBB160);
  Phyre_PObject_SetField6C(dword_CBAB20, (int)&unk_CBB1B0);
  unk_CBABB0 &= ~2u;
  dword_CBAB20[0] = &Phyre::PClassDescriptorConcrete<Phyre::PLOD::PLODGroup>::`vftable';
  return atexit(sub_B03DC0);
}

