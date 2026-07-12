// Function: sub_A30A40
// Address: 0xa30a40
// Size: 0x91
// Prototype: 

_DWORD *__thiscall sub_A30A40(_DWORD *this)
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-20h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"POccluderGeometryInstance", 8, 4, (int)GlobalTypeAccessor, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::POccluderGeometry::POccluderGeometryInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1A85550);
  Phyre_PObject_SetField68(this, (int)&unk_1A85560);
  Phyre_PObject_SetField6C(this, (int)&unk_1A85570);
  return this;
}

