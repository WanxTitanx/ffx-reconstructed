// Function: sub_987590
// Address: 0x987590
int __thiscall sub_987590(int this, _DWORD *a2, int a3, int a4)
{
  int v4; // ebx
  int v6; // edx
  int v7; // eax
  _DWORD *v8; // ecx
  int result; // eax

  v4 = a4;
  if ( !a4 )
    v4 = *(_DWORD *)(this + 200);
  v6 = *(_DWORD *)(this + 276);
  v7 = 0;
  if ( v6 > 0 )
  {
    v8 = *(_DWORD **)(this + 284);
    while ( *v8 != *a2 )
    {
      ++v7;
      ++v8;
      if ( v7 >= v6 )
        goto LABEL_9;
    }
    v6 = v7;
  }
LABEL_9:
  result = *(_DWORD *)(this + 276);
  if ( v6 < result )
  {
    *(_DWORD *)(*(_DWORD *)(this + 284) + 4 * v6) = *(_DWORD *)(*(_DWORD *)(this + 284) + 4 * result - 4);
    --*(_DWORD *)(this + 276);
    return (*(int (__thiscall **)(_DWORD, int, _DWORD *, int))(**(_DWORD **)(this + 304) + 8))(
             *(_DWORD *)(this + 304),
             v4,
             a2,
             a3);
  }
  return result;
}
