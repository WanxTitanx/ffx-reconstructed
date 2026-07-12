// Function: sub_A10CE0
// Address: 0xa10ce0
// Size: 0x26

char __stdcall sub_A10CE0(int a1)
{
  if ( a1 ) /*0xa10ce8*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10cf1*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10cfe*/
  return 1; /*0xa10cf5*/
}