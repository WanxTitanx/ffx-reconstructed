// Function: sub_A10BD0
// Address: 0xa10bd0
// Size: 0x26

char __stdcall sub_A10BD0(int a1)
{
  if ( a1 ) /*0xa10bd8*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10be1*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10bee*/
  return 1; /*0xa10be5*/
}