// Function: sub_AE1700
// Address: 0xae1700
// Size: 0xb4
// Prototype: 

int sub_AE1700()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C96B40, (int)Registry, (int)"PClusterHeader", 84, 4, (int)&unk_C970F8, 0);
  unk_C96BD0 |= 2u;
  dword_C96B40[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSerialization::PBinary::PClusterHeader>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C96B40, (int)&unk_C96FE0);
  Phyre_PObject_SetField68(dword_C96B40, (int)&unk_C97040);
  Phyre_PObject_SetField6C(dword_C96B40, (int)&unk_C970A0);
  unk_C96BD0 &= ~2u;
  dword_C96B40[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSerialization::PBinary::PClusterHeader>::`vftable';
  return atexit(sub_AFB720);
}

