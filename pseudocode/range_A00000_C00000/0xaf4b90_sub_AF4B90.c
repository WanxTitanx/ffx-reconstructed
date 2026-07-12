// Function: sub_AF4B90
// Address: 0xaf4b90
// Size: 0xb5
// Prototype: 

int sub_AF4B90()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1A84C88,
    (int)Registry,
    (int)"PBitmapFontCharInfo",
    48,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_1A84D18 |= 2u;
  dword_1A84C88[0] = &Phyre::PClassDescriptorAbstract<Phyre::PText::PBitmapFontCharInfo>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1A84C88, (int)&unk_1A851D0);
  Phyre_PObject_SetField68(dword_1A84C88, (int)&unk_1A85200);
  Phyre_PObject_SetField6C(dword_1A84C88, (int)&unk_1A85230);
  unk_1A84D18 &= ~2u;
  dword_1A84C88[0] = &Phyre::PClassDescriptorConcrete<Phyre::PText::PBitmapFontCharInfo>::`vftable';
  return atexit(sub_B090B0);
}

