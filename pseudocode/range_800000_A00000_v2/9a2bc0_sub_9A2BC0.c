// Function: sub_9A2BC0
// Address: 0x9a2bc0
void __thiscall sub_9A2BC0(char *this)
{
  *(_DWORD *)this = &btDbvtBroadphase::`vftable';
  if ( *(this + 152) )
  {
    (***((void (__thiscall ****)(_DWORD, _DWORD))this + 24))(*((_DWORD *)this + 24), 0);
    sub_9D4D50(*((_DWORD *)this + 24));
  }
  `eh vector destructor iterator'(this + 4, 0x28u, 2, (void (__thiscall *)(void *))sub_987900);
  *(_DWORD *)this = &btBroadphaseInterface::`vftable';
}
