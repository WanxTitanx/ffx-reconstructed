// Function: sub_AE9AE0
// Address: 0xae9ae0
// Size: 0xb7
// Prototype: 

int sub_AE9AE0()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAFF10,
    (int)Registry,
    (int)"PCameraControllerComponent",
    704,
    4,
    (int)dword_CAF8D0,
    0);
  unk_CAFFA0 |= 2u;
  dword_CAFF10[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGameplay::PCameraControllerComponent>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAFF10, (int)&unk_CB0270);
  Phyre_PObject_SetField68(dword_CAFF10, (int)&unk_CB0530);
  Phyre_PObject_SetField6C(dword_CAFF10, (int)&unk_CB07F0);
  unk_CAFFA0 &= ~2u;
  dword_CAFF10[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGameplay::PCameraControllerComponent>::`vftable';
  return atexit(sub_B023D0);
}

