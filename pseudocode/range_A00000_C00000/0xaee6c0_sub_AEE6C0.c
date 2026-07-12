// Function: sub_AEE6C0
// Address: 0xaee6c0
// Size: 0xb5
// Prototype: 

int sub_AEE6C0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CC9910,
    (int)Registry,
    (int)"PAsyncProcessHeader",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CC99A0 |= 2u;
  dword_CC9910[0] = &Phyre::PClassDescriptorAbstract<Phyre::PScripting::PAsyncProcessHeader>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CC9910, (int)&unk_CC99E0);
  Phyre_PObject_SetField68(dword_CC9910, (int)&unk_CC9A00);
  Phyre_PObject_SetField6C(dword_CC9910, (int)&unk_CC9A20);
  unk_CC99A0 &= ~2u;
  dword_CC9910[0] = &Phyre::PClassDescriptorConcrete<Phyre::PScripting::PAsyncProcessHeader>::`vftable';
  return atexit(sub_B05FA0);
}

