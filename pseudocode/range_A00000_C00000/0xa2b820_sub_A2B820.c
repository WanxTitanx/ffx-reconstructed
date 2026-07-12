// Function: sub_A2B820
// Address: 0xa2b820
// Size: 0x91
// Prototype: 

_DWORD *__thiscall sub_A2B820(_DWORD *this)
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-20h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"PBitmapFont", 36, 4, (int)GlobalTypeAccessor, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PText::PBitmapFont>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1A85260);
  Phyre_PObject_SetField68(this, (int)&unk_1A85290);
  Phyre_PObject_SetField6C(this, (int)&unk_1A852C0);
  return this;
}

