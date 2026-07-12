// Function: sub_AED420
// Address: 0xaed420
// Size: 0xb5
// Prototype: 

int sub_AED420()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBEC38,
    (int)Registry,
    (int)"PPhysicsInterfaceBase",
    16,
    4,
    (int)GlobalTypeAccessor,
    1);
  unk_CBECC8 |= 2u;
  dword_CBEC38[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsInterfaceBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBEC38, (int)&unk_CC9510);
  Phyre_PObject_SetField68(dword_CBEC38, (int)&unk_CC9520);
  Phyre_PObject_SetField6C(dword_CBEC38, (int)&unk_CC9530);
  unk_CBECC8 &= ~2u;
  dword_CBEC38[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsInterfaceBase>::`vftable';
  return atexit(sub_B04DB0);
}

