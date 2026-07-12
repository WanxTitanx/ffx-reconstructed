// Function: sub_A10BA0
// Address: 0xa10ba0
// Size: 0x26

char __stdcall sub_A10BA0(int a1)
{
  if ( a1 ) /*0xa10ba8*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10bb1*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10bbe*/
  return 1; /*0xa10bb5*/
}