// Function: sub_AE0940
// Address: 0xae0940
// Size: 0xa4
// Prototype: 

int sub_AE0940()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(unk_C90B90, (int)Registry, (int)"PCluster", 80, 16, (int)GlobalTypeAccessor, 0);
  unk_C90C20 |= 2u;
  unk_C90B90[0] = &Phyre::PClassDescriptorAbstract<Phyre::PCluster>::`vftable';
  Phyre_PObject_SetInstanceOffset(unk_C90B90, (int)&unk_C90D00);
  Phyre_PObject_SetField68(unk_C90B90, (int)&unk_C90D50);
  Phyre_PObject_SetField6C(unk_C90B90, (int)&unk_C90DA0);
  return atexit(sub_AFA160);
}

