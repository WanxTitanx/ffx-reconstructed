// Function: sub_AE20A0
// Address: 0xae20a0
// Size: 0xb5
// Prototype: 

int sub_AE20A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C988B0, (int)Registry, (int)"PDataBlockBase", 24, 4, (int)GlobalTypeAccessor, 0);
  unk_C98940 |= 2u;
  dword_C988B0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PDataBlockBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C988B0, (int)&unk_C98BC0);
  Phyre_PObject_SetField68(dword_C988B0, (int)&unk_C98BE0);
  Phyre_PObject_SetField6C(dword_C988B0, (int)&unk_C98C00);
  unk_C98940 &= ~2u;
  dword_C988B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PDataBlockBase>::`vftable';
  return atexit(sub_AFC520);
}

