// Function: sub_A3F440
// Address: 0xa3f440
// Size: 0x91
// Prototype: 

_DWORD *__thiscall sub_A3F440(_DWORD *this)
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-20h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"POccluderGeometryObject", 48, 16, (int)GlobalTypeAccessor, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::POccluderGeometry::POccluderGeometryObject>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1A85B10);
  Phyre_PObject_SetField68(this, (int)&unk_1A85B40);
  Phyre_PObject_SetField6C(this, (int)&unk_1A85B70);
  return this;
}

