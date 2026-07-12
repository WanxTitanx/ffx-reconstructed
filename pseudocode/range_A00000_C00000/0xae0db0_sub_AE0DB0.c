// Function: sub_AE0DB0
// Address: 0xae0db0
// Size: 0xb5
// Prototype: 

int sub_AE0DB0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C91958,
    (int)Registry,
    (int)"PClusterDependencyList",
    8,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C919E8 |= 2u;
  dword_C91958[0] = &Phyre::PClassDescriptorAbstract<Phyre::PClusterDependencyList>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C91958, (int)&unk_C91B50);
  Phyre_PObject_SetField68(dword_C91958, (int)&unk_C91B60);
  Phyre_PObject_SetField6C(dword_C91958, (int)&unk_C91B70);
  unk_C919E8 &= ~2u;
  dword_C91958[0] = &Phyre::PClassDescriptorConcrete<Phyre::PClusterDependencyList>::`vftable';
  return atexit(sub_AFA510);
}

