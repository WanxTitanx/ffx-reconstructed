// Function: sub_AE22E0
// Address: 0xae22e0
// Size: 0xb5
// Prototype: 

int sub_AE22E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C98EC8,
    (int)Registry,
    (int)"PIndexDataBlockBase",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C98F58 |= 2u;
  dword_C98EC8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PIndexDataBlockBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C98EC8, (int)&unk_C990E0);
  Phyre_PObject_SetField68(dword_C98EC8, (int)&unk_C99100);
  Phyre_PObject_SetField6C(dword_C98EC8, (int)&unk_C99120);
  unk_C98F58 &= ~2u;
  dword_C98EC8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PIndexDataBlockBase>::`vftable';
  return atexit(sub_AFC650);
}

