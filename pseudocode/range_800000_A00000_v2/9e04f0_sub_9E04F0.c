// Function: sub_9E04F0
// Address: 0x9e04f0
_DWORD *__thiscall sub_9E04F0(_DWORD *this)
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"PInputSourceMotionQuatZ", 24, 4, (int)&unk_1940AD0, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionQuatZ>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_19425E0);
  Phyre_PObject_SetField68(this, (int)&unk_1942600);
  Phyre_PObject_SetField6C(this, (int)&unk_1942620);
  return this;
}
