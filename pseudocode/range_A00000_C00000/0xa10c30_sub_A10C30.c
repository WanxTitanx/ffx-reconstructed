// Function: sub_A10C30
// Address: 0xa10c30
// Size: 0x26

char __stdcall sub_A10C30(int a1)
{
  if ( a1 ) /*0xa10c38*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10c41*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10c4e*/
  return 1; /*0xa10c45*/
}