// Function: sub_AE9670
// Address: 0xae9670
// Size: 0xb4
// Prototype: 

int sub_AE9670()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAF388,
    (int)Registry,
    (int)"PTriggerReceiverComponent",
    44,
    4,
    (int)dword_C91C18,
    0);
  unk_CAF418 |= 2u;
  dword_CAF388[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PTriggerReceiverComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAF388, (int)&unk_CAF4B0);
  Phyre_PObject_SetField68(dword_CAF388, (int)&unk_CAF4E0);
  Phyre_PObject_SetField6C(dword_CAF388, (int)&unk_CAF510);
  unk_CAF418 &= ~2u;
  dword_CAF388[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PTriggerReceiverComponent>::`vftable';
  return atexit(sub_B02040);
}

