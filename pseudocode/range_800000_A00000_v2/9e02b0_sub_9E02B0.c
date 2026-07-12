// Function: sub_9E02B0
// Address: 0x9e02b0
_DWORD *__thiscall sub_9E02B0(_DWORD *this)
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    this,
    (int)Registry,
    (int)"PInputSourceMotionLinearAccelerationZ",
    24,
    4,
    (int)&unk_1940AD0,
    0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionLinearAccelerationZ>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1942880);
  Phyre_PObject_SetField68(this, (int)&unk_19428A0);
  Phyre_PObject_SetField6C(this, (int)&unk_19428C0);
  return this;
}
