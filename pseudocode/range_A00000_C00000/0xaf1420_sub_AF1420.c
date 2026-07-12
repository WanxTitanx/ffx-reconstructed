// Function: sub_AF1420
// Address: 0xaf1420
// Size: 0xb5
// Prototype: 

int sub_AF1420()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1941910, (int)Registry, (int)"PInputMap", 8, 4, (int)GlobalTypeAccessor, 0);
  unk_19419A0 |= 2u;
  dword_1941910[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputMap>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1941910, (int)&unk_1942910);
  Phyre_PObject_SetField68(dword_1941910, (int)&unk_1942920);
  Phyre_PObject_SetField6C(dword_1941910, (int)&unk_1942930);
  unk_19419A0 &= ~2u;
  dword_1941910[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputMap>::`vftable';
  return atexit(sub_B07E00);
}

