// Function: sub_AEE780
// Address: 0xaee780
// Size: 0xbd
// Prototype: 

int sub_AEE780()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CC9A40,
    (int)Registry,
    (int)"PClassCallableMethodScript",
    52,
    4,
    (int)MEMORY[0xC90610],
    0);
  unk_CC9AD0 |= 2u;
  dword_CC9A40[0] = &Phyre::PClassDescriptorAbstract<Phyre::PScripting::PClassCallableMethodScript>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CC9A40, (int)&unk_CC9B60);
  Phyre_PObject_SetField68(dword_CC9A40, (int)&unk_CC9BA0);
  Phyre_PObject_SetField6C(dword_CC9A40, (int)&unk_CC9BE0);
  dword_CC9A40[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PScripting::PClassCallableMethodScript>::`vftable';
  unk_CC9AD0 = unk_CC9AD0 & 0xFFFFFFF5 | 8;
  return atexit(sub_B06000);
}

