// Function: sub_A2B8C0
// Address: 0xa2b8c0
// Size: 0x91
// Prototype: 

_DWORD *__thiscall sub_A2B8C0(_DWORD *this)
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-20h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"PBitmapFontCharInfo", 48, 4, (int)GlobalTypeAccessor, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PText::PBitmapFontCharInfo>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1A851D0);
  Phyre_PObject_SetField68(this, (int)&unk_1A85200);
  Phyre_PObject_SetField6C(this, (int)&unk_1A85230);
  return this;
}

