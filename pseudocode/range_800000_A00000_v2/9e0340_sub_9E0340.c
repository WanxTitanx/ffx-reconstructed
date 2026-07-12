// Function: sub_9E0340
// Address: 0x9e0340
_DWORD *__thiscall sub_9E0340(_DWORD *this)
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"PInputSourceMotionQuatW", 24, 4, (int)&unk_1940AD0, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionQuatW>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1942640);
  Phyre_PObject_SetField68(this, (int)&unk_1942660);
  Phyre_PObject_SetField6C(this, (int)&unk_1942680);
  return this;
}
