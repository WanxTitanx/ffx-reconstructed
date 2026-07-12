// Function: sub_AE1940
// Address: 0xae1940
// Size: 0xb5
// Prototype: 

int sub_AE1940()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C97338,
    (int)Registry,
    (int)"PInstanceListHeader",
    36,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C973C8 |= 2u;
  dword_C97338[0] = &Phyre::PClassDescriptorAbstract<Phyre::PSerialization::PBinary::PInternal::PInstanceListHeader>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C97338, (int)&unk_C97560);
  Phyre_PObject_SetField68(dword_C97338, (int)&unk_C97590);
  Phyre_PObject_SetField6C(dword_C97338, (int)&unk_C975C0);
  unk_C973C8 &= ~2u;
  dword_C97338[0] = &Phyre::PClassDescriptorConcrete<Phyre::PSerialization::PBinary::PInternal::PInstanceListHeader>::`vftable';
  return atexit(sub_AFB8D0);
}

