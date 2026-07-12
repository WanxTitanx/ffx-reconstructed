// Function: sub_AE95B0
// Address: 0xae95b0
// Size: 0xbe
// Prototype: 

int sub_AE95B0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAF1E8,
    (int)Registry,
    (int)"PTriggerReceiverTypeCallbackData",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CAF278 |= 2u;
  dword_CAF1E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PTriggerReceiverTypeCallbackData>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAF1E8, (int)&unk_CAF330);
  Phyre_PObject_SetField68(dword_CAF1E8, (int)&unk_CAF350);
  Phyre_PObject_SetField6C(dword_CAF1E8, (int)&unk_CAF370);
  dword_CAF1E8[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PGameplay::PTriggerReceiverTypeCallbackData>::`vftable';
  unk_CAF278 = unk_CAF278 & 0xFFFFFFF5 | 8;
  return atexit(sub_B01FE0);
}

