// Function: sub_AE25E0
// Address: 0xae25e0
// Size: 0xb5
// Prototype: 

int sub_AE25E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C998E8, (int)Registry, (int)"PMaterialSet", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_C99978 |= 2u;
  dword_C998E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PMaterialSet>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C998E8, (int)&unk_C99B70);
  Phyre_PObject_SetField68(dword_C998E8, (int)&unk_C99B80);
  Phyre_PObject_SetField6C(dword_C998E8, (int)&unk_C99B90);
  unk_C99978 &= ~2u;
  dword_C998E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PMaterialSet>::`vftable';
  return atexit(sub_AFC810);
}

