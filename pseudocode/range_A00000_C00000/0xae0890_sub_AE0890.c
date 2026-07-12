// Function: sub_AE0890
// Address: 0xae0890
// Size: 0xa4
// Prototype: 

int sub_AE0890()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(MEMORY[0xC90A18], (int)Registry, (int)"PNamespace", 28, 16, (int)GlobalTypeAccessor, 8);
  unk_C90AA8 |= 2u;
  MEMORY[0xC90A18][0] = &Phyre::PClassDescriptorAbstract<Phyre::PNamespace>::`vftable';
  Phyre_PObject_SetInstanceOffset(MEMORY[0xC90A18], (int)&unk_C90B20);
  Phyre_PObject_SetField68(MEMORY[0xC90A18], (int)&unk_C90B40);
  Phyre_PObject_SetField6C(MEMORY[0xC90A18], (int)&unk_C90B60);
  return atexit(sub_AFA0B0);
}

