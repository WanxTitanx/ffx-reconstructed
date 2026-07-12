// Function: sub_A10B40
// Address: 0xa10b40
// Size: 0x26

char __stdcall sub_A10B40(int a1)
{
  if ( a1 ) /*0xa10b48*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10b51*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10b5e*/
  return 1; /*0xa10b55*/
}