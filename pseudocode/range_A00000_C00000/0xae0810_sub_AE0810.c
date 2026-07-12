// Function: sub_AE0810
// Address: 0xae0810
// Size: 0x5f
// Prototype: 

int sub_AE0810()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-8h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    MEMORY[0xC90760],
    (int)Registry,
    (int)"PClassDescriptor",
    148,
    16,
    (int)GlobalTypeAccessor,
    24);
  unk_C907F0 |= 2u;
  unk_C907C4 = &unk_C90830;
  unk_C907C8 = &unk_C908D0;
  unk_C907CC = &unk_C90970;
  MEMORY[0xC90760][0] = &Phyre::PClassDescriptorForClassDescriptor::`vftable';
  return atexit(sub_AFA040);
}

