// Function: sub_AF14E0
// Address: 0xaf14e0
// Size: 0xa4
// Prototype: 

int sub_AF14E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1940AD0, (int)Registry, (int)"PInputSource", 24, 16, (int)GlobalTypeAccessor, 4);
  unk_1940B60 |= 2u;
  dword_1940AD0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSource>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940AD0, (int)&unk_1941D20);
  Phyre_PObject_SetField68(dword_1940AD0, (int)&unk_1941D40);
  Phyre_PObject_SetField6C(dword_1940AD0, (int)&unk_1941D60);
  return atexit(sub_B07E20);
}

