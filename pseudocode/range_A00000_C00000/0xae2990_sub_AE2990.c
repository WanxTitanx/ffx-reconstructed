// Function: sub_AE2990
// Address: 0xae2990
// Size: 0xb5
// Prototype: 

int sub_AE2990()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9AB98, (int)Registry, (int)"PShape", 28, 4, (int)GlobalTypeAccessor, 0);
  unk_C9AC28 |= 2u;
  dword_C9AB98[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PShape>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9AB98, (int)&unk_C9AE70);
  Phyre_PObject_SetField68(dword_C9AB98, (int)&unk_C9AE90);
  Phyre_PObject_SetField6C(dword_C9AB98, (int)&unk_C9AEB0);
  unk_C9AC28 &= ~2u;
  dword_C9AB98[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PShape>::`vftable';
  return atexit(sub_AFCD10);
}

