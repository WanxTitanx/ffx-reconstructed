// Function: sub_A10C60
// Address: 0xa10c60
// Size: 0x26

char __stdcall sub_A10C60(int a1)
{
  if ( a1 ) /*0xa10c68*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10c71*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10c7e*/
  return 1; /*0xa10c75*/
}