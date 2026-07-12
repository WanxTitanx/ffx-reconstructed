// Function: sub_AE1F20
// Address: 0xae1f20
// Size: 0xb5
// Prototype: 

int sub_AE1F20()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C98730, (int)Registry, (int)"PVertexStream", 12, 4, (int)GlobalTypeAccessor, 0);
  unk_C987C0 |= 2u;
  dword_C98730[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGeometry::PVertexStream>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C98730, (int)&unk_C98880);
  Phyre_PObject_SetField68(dword_C98730, (int)&unk_C98890);
  Phyre_PObject_SetField6C(dword_C98730, (int)&unk_C988A0);
  unk_C987C0 &= ~2u;
  dword_C98730[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGeometry::PVertexStream>::`vftable';
  return atexit(sub_AFC4A0);
}

