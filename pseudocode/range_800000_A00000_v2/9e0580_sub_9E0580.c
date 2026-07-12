// Function: sub_9E0580
// Address: 0x9e0580
_DWORD *__thiscall sub_9E0580(_DWORD *this)
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"PInputSourceMouseButton", 32, 4, (int)&unk_1940AD0, 0);
  *(this + 36) |= 2u;
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMouseButton>::`vftable';
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1942160);
  Phyre_PObject_SetField68(this, (int)&unk_1942180);
  Phyre_PObject_SetField6C(this, (int)&unk_19421A0);
  return this;
}
