// Function: sub_AE2160
// Address: 0xae2160
// Size: 0xb5
// Prototype: 

int sub_AE2160()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C98D18, (int)Registry, (int)"PDynamicDataBlock", 24, 4, (int)GlobalTypeAccessor, 0);
  unk_C98DA8 |= 2u;
  dword_C98D18[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PDynamicDataBlock>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C98D18, (int)&unk_C98E70);
  Phyre_PObject_SetField68(dword_C98D18, (int)&unk_C98E90);
  Phyre_PObject_SetField6C(dword_C98D18, (int)&unk_C98EB0);
  unk_C98DA8 &= ~2u;
  dword_C98D18[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PDynamicDataBlock>::`vftable';
  return atexit(sub_AFC5D0);
}

