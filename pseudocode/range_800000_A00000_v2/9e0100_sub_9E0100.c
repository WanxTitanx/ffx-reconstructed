// Function: sub_9E0100
// Address: 0x9e0100
_DWORD *__thiscall sub_9E0100(_DWORD *this)
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    this,
    (int)Registry,
    (int)"PInputSourceMotionAngularVelocityZ",
    24,
    4,
    (int)&unk_1940AD0,
    0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionAngularVelocityZ>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1942760);
  Phyre_PObject_SetField68(this, (int)&unk_1942780);
  Phyre_PObject_SetField6C(this, (int)&unk_19427A0);
  return this;
}
