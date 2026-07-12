// Function: sub_A10C00
// Address: 0xa10c00
// Size: 0x26

char __stdcall sub_A10C00(int a1)
{
  if ( a1 ) /*0xa10c08*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10c11*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10c1e*/
  return 1; /*0xa10c15*/
}