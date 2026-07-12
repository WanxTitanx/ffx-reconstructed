// Function: sub_990B10
// Address: 0x990b10
int __stdcall sub_990B10(int a1, int a2, _WORD *a3, _WORD *a4)
{
  int v4; // esi
  int v5; // ecx
  int result; // eax
  int v7; // ecx
  int v8; // esi
  int v9; // eax

  v4 = a1;
  v5 = *(_WORD *)(a1 + 6) >= *a3
    && *a4 >= *(_WORD *)a1
    && a4[1] >= *(_WORD *)(a1 + 2)
    && a4[2] >= *(_WORD *)(a1 + 4)
    && *(_WORD *)(a1 + 8) >= a3[1]
    && *(_WORD *)(a1 + 10) >= a3[2];
  result = (v5 | -v5) >> 31;
  v7 = *(_DWORD *)(a1 + 12) >= 0;
  if ( (v7 | -v7) < 0 )
  {
    while ( !(_BYTE)v7 )
    {
      v8 = v4 + 16;
      sub_990B10(v8, a2, a3, a4);
      v9 = *(_DWORD *)(v8 + 12);
      if ( v9 < 0 )
        v4 = v8 - 16 * v9;
      else
        v4 = v8 + 16;
      result = (*a4 >= *(_WORD *)v4
             && *(_WORD *)(v4 + 6) >= *a3
             && *(_WORD *)(v4 + 8) >= a3[1]
             && *(_WORD *)(v4 + 10) >= a3[2]
             && a4[1] >= *(_WORD *)(v4 + 2)
             && a4[2] >= *(_WORD *)(v4 + 4)
              ? -1
              : *a4 >= *(_WORD *)v4
             && *(_WORD *)(v4 + 6) >= *a3
             && *(_WORD *)(v4 + 8) >= a3[1]
             && *(_WORD *)(v4 + 10) >= a3[2]
             && a4[1] >= *(_WORD *)(v4 + 2)
             && a4[2] >= *(_WORD *)(v4 + 4)) >> 31;
      v7 = *(_DWORD *)(v4 + 12) >= 0;
      if ( (*a4 >= *(_WORD *)v4
         && *(_WORD *)(v4 + 6) >= *a3
         && *(_WORD *)(v4 + 8) >= a3[1]
         && *(_WORD *)(v4 + 10) >= a3[2]
         && a4[1] >= *(_WORD *)(v4 + 2)
         && a4[2] >= *(_WORD *)(v4 + 4)
          ? -1
          : v7) >= 0 )
        return result;
    }
    return (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 4))(
             a2,
             *(int *)(v4 + 12) >> 21,
             *(_DWORD *)(v4 + 12) & 0x1FFFFF);
  }
  return result;
}
