// Function: sub_985860
// Address: 0x985860
int __thiscall sub_985860(int this, int a2)
{
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int result; // eax
  int v7; // edx
  _DWORD *v8; // ecx
  int v9; // eax
  int *v10; // ecx
  int v11; // edx

  v3 = *(_DWORD *)(a2 + 200);
  if ( v3 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 80) + 36))(*(_DWORD *)(this + 80));
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 36))(v4, v3, *(_DWORD *)(this + 24));
    (*(void (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 80) + 8))(
      *(_DWORD *)(this + 80),
      v3,
      *(_DWORD *)(this + 24));
    *(_DWORD *)(a2 + 200) = 0;
  }
  v5 = *(_DWORD *)(this + 8);
  result = 0;
  v7 = v5;
  if ( v5 > 0 )
  {
    v8 = *(_DWORD **)(this + 16);
    while ( *v8 != a2 )
    {
      ++result;
      ++v8;
      if ( result >= v5 )
        goto LABEL_9;
    }
    v7 = result;
  }
LABEL_9:
  if ( v7 < v5 )
  {
    v9 = *(_DWORD *)(this + 16);
    v10 = (int *)(v9 + 4 * v7);
    v11 = *v10;
    *v10 = *(_DWORD *)(v9 + 4 * v5 - 4);
    result = *(_DWORD *)(this + 16);
    *(_DWORD *)(result + 4 * v5 - 4) = v11;
    --*(_DWORD *)(this + 8);
  }
  return result;
}
