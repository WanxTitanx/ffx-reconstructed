// Function: sub_AE0750
// Address: 0xae0750
// Size: 0xbe
// Prototype: 

int sub_AE0750()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(MEMORY[0xC90610], (int)Registry, (int)"PClassMember", 20, 4, (int)GlobalTypeAccessor, 0);
  unk_C906A0 |= 2u;
  MEMORY[0xC90610][0] = &Phyre::PClassDescriptorAbstract<Phyre::PClassMember>::`vftable';
  Phyre_PObject_SetInstanceOffset(MEMORY[0xC90610], (int)&unk_C90700);
  Phyre_PObject_SetField68(MEMORY[0xC90610], (int)&unk_C90720);
  Phyre_PObject_SetField6C(MEMORY[0xC90610], (int)&unk_C90740);
  MEMORY[0xC90610][0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PClassMember>::`vftable';
  unk_C906A0 = unk_C906A0 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFA000);
}

