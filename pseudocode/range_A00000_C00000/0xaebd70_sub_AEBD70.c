// Function: sub_AEBD70
// Address: 0xaebd70
// Size: 0xb5
// Prototype: 

int sub_AEBD70()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBBFF8, (int)Registry, (int)"PRenderStream", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_CBC088 |= 2u;
  dword_CBBFF8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PRenderStream>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBBFF8, (int)&unk_CBD0A0);
  Phyre_PObject_SetField68(dword_CBBFF8, (int)&unk_CBD0B0);
  Phyre_PObject_SetField6C(dword_CBBFF8, (int)&unk_CBD0C0);
  unk_CBC088 &= ~2u;
  dword_CBBFF8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PRenderStream>::`vftable';
  return atexit(sub_B04390);
}

