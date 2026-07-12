// Function: sub_AE9BA0
// Address: 0xae9ba0
// Size: 0xb4
// Prototype: 

int sub_AE9BA0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CB0AC0, (int)Registry, (int)"PAttachableComponent", 108, 4, (int)dword_C91C18, 0);
  unk_CB0B50 |= 2u;
  dword_CB0AC0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PAttachableComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CB0AC0, (int)&unk_CB0E70);
  Phyre_PObject_SetField68(dword_CB0AC0, (int)&unk_CB0EE0);
  Phyre_PObject_SetField6C(dword_CB0AC0, (int)&unk_CB0F50);
  unk_CB0B50 &= ~2u;
  dword_CB0AC0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PAttachableComponent>::`vftable';
  return atexit(sub_B02690);
}

