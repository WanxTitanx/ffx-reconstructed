// Function: sub_AE0C30
// Address: 0xae0c30
// Size: 0xbd
// Prototype: 

int sub_AE0C30()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C91180,
    (int)Registry,
    (int)"PClassDataMemberDynamic",
    48,
    4,
    (int)MEMORY[0xC90610],
    4);
  unk_C91210 |= 2u;
  dword_C91180[0] = &Phyre::PClassDescriptorAbstract<Phyre::PClassDataMemberDynamic>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C91180, (int)&unk_C912A0);
  Phyre_PObject_SetField68(dword_C91180, (int)&unk_C912D0);
  Phyre_PObject_SetField6C(dword_C91180, (int)&unk_C91300);
  dword_C91180[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PClassDataMemberDynamic>::`vftable';
  unk_C91210 = unk_C91210 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFA3A0);
}

