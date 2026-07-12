// Function: sub_AECC50
// Address: 0xaecc50
// Size: 0xbe
// Prototype: 

int sub_AECC50()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBF190,
    (int)Registry,
    (int)"PPhysicsCallbackData",
    20,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CBF220 |= 2u;
  dword_CBF190[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsCallbackData>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF190, (int)&unk_CC7500);
  Phyre_PObject_SetField68(dword_CBF190, (int)&unk_CC7520);
  Phyre_PObject_SetField6C(dword_CBF190, (int)&unk_CC7540);
  dword_CBF190[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PPhysics::PPhysicsCallbackData>::`vftable';
  unk_CBF220 = unk_CBF220 & 0xFFFFFFF5 | 8;
  return atexit(sub_B04C30);
}

