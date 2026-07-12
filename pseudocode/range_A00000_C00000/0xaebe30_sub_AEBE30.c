// Function: sub_AEBE30
// Address: 0xaebe30
// Size: 0xb5
// Prototype: 

int sub_AEBE30()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBBF60, (int)Registry, (int)"PRenderStreamInput", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_CBBFF0 |= 2u;
  dword_CBBF60[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PRenderStreamInput>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBBF60, (int)&unk_CBD070);
  Phyre_PObject_SetField68(dword_CBBF60, (int)&unk_CBD080);
  Phyre_PObject_SetField6C(dword_CBBF60, (int)&unk_CBD090);
  unk_CBBFF0 &= ~2u;
  dword_CBBF60[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PRenderStreamInput>::`vftable';
  return atexit(sub_B043B0);
}

