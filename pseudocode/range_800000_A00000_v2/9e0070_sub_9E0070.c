// Function: sub_9E0070
// Address: 0x9e0070
_DWORD *__thiscall sub_9E0070(_DWORD *this)
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    this,
    (int)Registry,
    (int)"PInputSourceMotionAngularVelocityY",
    24,
    4,
    (int)&unk_1940AD0,
    0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMotionAngularVelocityY>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1942700);
  Phyre_PObject_SetField68(this, (int)&unk_1942720);
  Phyre_PObject_SetField6C(this, (int)&unk_1942740);
  return this;
}
