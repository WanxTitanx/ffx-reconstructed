// Function: sub_AF97B0
// Address: 0xaf97b0
// Size: 0xb5
// Prototype: 

int sub_AF97B0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(Size_6, (int)Registry, (int)"PGameSettings", 12, 4, (int)GlobalTypeAccessor, 0);
  unk_1A85648 |= 2u;
  Size_6[0] = &Phyre::PClassDescriptorAbstract<Phyre::PGame::PGameSettings>::`vftable';
  Phyre_PObject_SetInstanceOffset(Size_6, (int)&unk_1A857D0);
  Phyre_PObject_SetField68(Size_6, (int)&unk_1A857E0);
  Phyre_PObject_SetField6C(Size_6, (int)&unk_1A857F0);
  unk_1A85648 &= ~2u;
  Size_6[0] = &Phyre::PClassDescriptorConcrete<Phyre::PGame::PGameSettings>::`vftable';
  return atexit(sub_B0B830);
}

