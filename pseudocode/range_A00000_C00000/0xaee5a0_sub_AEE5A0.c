// Function: sub_AEE5A0
// Address: 0xaee5a0
// Size: 0xb5
// Prototype: 

int sub_AEE5A0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF6E8, (int)Registry, (int)"PRaycastResult", 40, 4, (int)GlobalTypeAccessor, 0);
  unk_CBF778 |= 2u;
  dword_CBF6E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PRaycastResult>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF6E8, (int)&unk_CC8F40);
  Phyre_PObject_SetField68(dword_CBF6E8, (int)&unk_CC8F70);
  Phyre_PObject_SetField6C(dword_CBF6E8, (int)&unk_CC8FA0);
  unk_CBF778 &= ~2u;
  dword_CBF6E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PRaycastResult>::`vftable';
  return atexit(sub_B050B0);
}

