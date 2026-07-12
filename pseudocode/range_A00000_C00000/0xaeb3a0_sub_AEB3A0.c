// Function: sub_AEB3A0
// Address: 0xaeb3a0
// Size: 0xb5
// Prototype: 

int sub_AEB3A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBAA88, (int)Registry, (int)"PLODLevel", 36, 4, (int)GlobalTypeAccessor, 0);
  unk_CBAB18 |= 2u;
  dword_CBAA88[0] = &Phyre::PClassDescriptorAbstract<Phyre::PLOD::PLODLevel>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBAA88, (int)&unk_CBB080);
  Phyre_PObject_SetField68(dword_CBAA88, (int)&unk_CBB0B0);
  Phyre_PObject_SetField6C(dword_CBAA88, (int)&unk_CBB0E0);
  unk_CBAB18 &= ~2u;
  dword_CBAA88[0] = &Phyre::PClassDescriptorConcrete<Phyre::PLOD::PLODLevel>::`vftable';
  return atexit(sub_B03DE0);
}

