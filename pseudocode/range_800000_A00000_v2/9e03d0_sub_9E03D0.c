// Function: sub_9E03D0
// Address: 0x9e03d0
_DWORD *__thiscall sub_9E03D0(_DWORD *this)
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"PInputSourceMotionQuatX", 24, 4, (int)&unk_1940AD0, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionQuatX>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1942520);
  Phyre_PObject_SetField68(this, (int)&unk_1942540);
  Phyre_PObject_SetField6C(this, (int)&unk_1942560);
  return this;
}
