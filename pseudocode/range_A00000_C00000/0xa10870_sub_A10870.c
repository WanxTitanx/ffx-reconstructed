// Function: sub_A10870
// Address: 0xa10870
// Size: 0x26
// Prototype: 

char __stdcall sub_A10870(int a1)
{
  if ( a1 )
    (**(void (__thiscall ***)(int, _DWORD))(a1 - 4))(a1 - 4, 0);
  else
    ((void (__stdcall *)(_DWORD))*MEMORY[0])(0);
  return 1;
}

