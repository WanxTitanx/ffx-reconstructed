// Function: sub_A10CB0
// Address: 0xa10cb0
// Size: 0x26

char __stdcall sub_A10CB0(int a1)
{
  if ( a1 ) /*0xa10cb8*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10cc1*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10cce*/
  return 1; /*0xa10cc5*/
}