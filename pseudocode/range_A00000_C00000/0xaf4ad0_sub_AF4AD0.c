// Function: sub_AF4AD0
// Address: 0xaf4ad0
// Size: 0xbe
// Prototype: 

int sub_AF4AD0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1A84D20, (int)Registry, (int)"PBitmapFont", 36, 4, (int)GlobalTypeAccessor, 0);
  unk_1A84DB0 |= 2u;
  dword_1A84D20[0] = &Phyre::PClassDescriptorAbstract<Phyre::PText::PBitmapFont>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1A84D20, (int)&unk_1A85260);
  Phyre_PObject_SetField68(dword_1A84D20, (int)&unk_1A85290);
  Phyre_PObject_SetField6C(dword_1A84D20, (int)&unk_1A852C0);
  dword_1A84D20[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PText::PBitmapFont>::`vftable';
  unk_1A84DB0 = unk_1A84DB0 & 0xFFFFFFF5 | 8;
  return atexit(sub_B09090);
}

