// Function: sub_A107E0
// Address: 0xa107e0
// Size: 0x26
// Prototype: 

char __stdcall sub_A107E0(int a1)
{
  if ( a1 )
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0);
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0);
  return 1;
}

