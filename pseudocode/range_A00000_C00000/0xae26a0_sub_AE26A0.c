// Function: sub_AE26A0
// Address: 0xae26a0
// Size: 0xb5
// Prototype: 

int sub_AE26A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C99C80, (int)Registry, (int)"PMesh", 56, 4, (int)GlobalTypeAccessor, 0);
  unk_C99D10 |= 2u;
  dword_C99C80[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PMesh>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C99C80, (int)&unk_C9A570);
  Phyre_PObject_SetField68(dword_C99C80, (int)&unk_C9A5B0);
  Phyre_PObject_SetField6C(dword_C99C80, (int)&unk_C9A5F0);
  unk_C99D10 &= ~2u;
  dword_C99C80[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PMesh>::`vftable';
  return atexit(sub_AFC950);
}

