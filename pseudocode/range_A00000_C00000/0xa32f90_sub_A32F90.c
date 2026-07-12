// Function: sub_A32F90
// Address: 0xa32f90
// Size: 0x91

_DWORD *__thiscall sub_A32F90(_DWORD *this)
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-20h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor(); /*0xa32fc0*/
  Registry = Phyre_TypeSystem_GetRegistry(); /*0xa32fca*/
  Phyre_PClassDescriptor_ctor(this, (int)Registry, (int)"PGameSettings", 12, 4, (int)GlobalTypeAccessor, 0); /*0xa32fd2*/
  *(this + 36) |= 2u; /*0xa32fd7*/
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PGame::PGameSettings>::`vftable'; /*0xa32fec*/
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1A857D0); /*0xa32ff2*/
  Phyre_PObject_SetField68(this, (int)&unk_1A857E0); /*0xa32ffe*/
  Phyre_PObject_SetField6C(this, (int)&unk_1A857F0); /*0xa3300a*/
  return this; /*0xa33011*/
}