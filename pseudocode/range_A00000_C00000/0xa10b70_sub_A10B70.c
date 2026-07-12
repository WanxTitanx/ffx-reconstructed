// Function: sub_A10B70
// Address: 0xa10b70
// Size: 0x26

char __stdcall sub_A10B70(int a1)
{
  if ( a1 ) /*0xa10b78*/
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0); /*0xa10b81*/
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0); /*0xa10b8e*/
  return 1; /*0xa10b85*/
}