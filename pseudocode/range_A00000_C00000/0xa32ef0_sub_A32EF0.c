// Function: sub_A32EF0
// Address: 0xa32ef0
// Size: 0x92
// Prototype: _DWORD __cdecl()

_DWORD *__thiscall sub_A32EF0(_DWORD *this)
{
  _DWORD *Registry; // eax
  int v4; // [esp-14h] [ebp-2Ch]
  void *GlobalTypeAccessor; // [esp-8h] [ebp-20h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor(); /*0xa32f20*/
  v4 = unk_1A857FC; /*0xa32f25*/
  Registry = Phyre_TypeSystem_GetRegistry(); /*0xa32f2b*/
  Phyre_PClassDescriptor_ctor(this, (int)Registry, v4, 8, 4, (int)GlobalTypeAccessor, 0); /*0xa32f33*/
  *(this + 36) |= 2u; /*0xa32f38*/
  *this = &Phyre::PClassDescriptorAbstract<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable'; /*0xa32f4d*/
  Phyre_PObject_SetInstanceOffset(this, (int)&unk_1A85800); /*0xa32f53*/
  Phyre_PObject_SetField68(this, (int)&unk_1A85810); /*0xa32f5f*/
  Phyre_PObject_SetField6C(this, (int)&unk_1A85820); /*0xa32f6b*/
  return this; /*0xa32f72*/
}