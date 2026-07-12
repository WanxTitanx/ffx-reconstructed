// Function: sub_AEC830
// Address: 0xaec830
// Size: 0xb5
// Prototype: 

int sub_AEC830()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBE2F0,
    (int)Registry,
    (int)"PScriptCallbackHandler",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CBE380 |= 2u;
  dword_CBE2F0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PScripting::PScriptCallbackHandler>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBE2F0, (int)&unk_CBE3E0);
  Phyre_PObject_SetField68(dword_CBE2F0, (int)&unk_CBE3F0);
  Phyre_PObject_SetField6C(dword_CBE2F0, (int)&unk_CBE400);
  unk_CBE380 &= ~2u;
  dword_CBE2F0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PScripting::PScriptCallbackHandler>::`vftable';
  return atexit(sub_B04A60);
}

