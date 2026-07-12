// Function: sub_9E0460
// Address: 0x9e0460
_DWORD *__thiscall sub_9E0460(_DWORD *this)
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"PInputSourceMotionQuatY", 24, 4, (int)&unk_1940AD0, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionQuatY>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1942580);
  Phyre_PObject_SetField68(this, (int)&unk_19425A0);
  Phyre_PObject_SetField6C(this, (int)&unk_19425C0);
  return this;
}
