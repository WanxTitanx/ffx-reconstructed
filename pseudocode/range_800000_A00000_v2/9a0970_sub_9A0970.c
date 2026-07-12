// Function: sub_9A0970
// Address: 0x9a0970
int __stdcall sub_9A0970(int a1, int a2)
{
  void (__thiscall ***v2)(_DWORD, _DWORD); // ecx
  int result; // eax

  v2 = *(void (__thiscall ****)(_DWORD, _DWORD))(a1 + 8);
  if ( v2 )
  {
    (**v2)(v2, 0);
    result = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)a2 + 48))(a2, *(_DWORD *)(a1 + 8));
    *(_DWORD *)(a1 + 8) = 0;
  }
  return result;
}
