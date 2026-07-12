// Function: sub_A2B780
// Address: 0xa2b780
// Size: 0x92
// Prototype: _DWORD __cdecl()

_DWORD *__thiscall sub_A2B780(_DWORD *this)
{
  _DWORD *Registry; // eax
  int v4; // [esp-14h] [ebp-2Ch]
  void *GlobalTypeAccessor; // [esp-8h] [ebp-20h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  v4 = unk_1A852E4;
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, v4, 8, 4, (int)GlobalTypeAccessor, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1A852F0);
  Phyre_PObject_SetField68(this, (int)&unk_1A85300);
  Phyre_PObject_SetField6C(this, (int)&unk_1A85310);
  return this;
}

