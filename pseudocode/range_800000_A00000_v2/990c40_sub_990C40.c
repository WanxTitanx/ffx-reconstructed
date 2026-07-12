// Function: sub_990C40
// Address: 0x990c40
int __thiscall sub_990C40(_DWORD *this, int a2, _WORD *a3, _WORD *a4, int a5, int a6)
{
  int v6; // edx
  int v7; // edi
  int v8; // esi
  int v9; // ebx
  bool v10; // al
  int v11; // ecx
  int v12; // ebx
  bool v13; // al
  int v14; // ecx
  int result; // eax
  int v16; // [esp+Ch] [ebp-4h]
  bool v17; // [esp+27h] [ebp+17h]

  v6 = a6;
  v7 = a5;
  v8 = *(this + 37) + 16 * a5;
  v9 = 0;
  while ( v7 < v6 )
  {
    v16 = v9 + 1;
    v10 = *a4 >= *(_WORD *)v8;
    v11 = *(_DWORD *)(v8 + 12);
    v12 = ((v10
         && *(_WORD *)(v8 + 6) >= *a3
         && a4[1] >= *(_WORD *)(v8 + 2)
         && a4[2] >= *(_WORD *)(v8 + 4)
         && *(_WORD *)(v8 + 8) >= a3[1]
         && *(_WORD *)(v8 + 10) >= a3[2]
          ? -1
          : v10
         && *(_WORD *)(v8 + 6) >= *a3
         && a4[1] >= *(_WORD *)(v8 + 2)
         && a4[2] >= *(_WORD *)(v8 + 4)
         && *(_WORD *)(v8 + 8) >= a3[1]
         && *(_WORD *)(v8 + 10) >= a3[2]) >> 31)
        & 1;
    v13 = v11 >= 0;
    v17 = v11 >= 0;
    if ( v11 >= 0 )
    {
      if ( !v12 )
        goto LABEL_6;
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 4))(a2, v11 >> 21, v11 & 0x1FFFFF);
      v13 = v17;
      v6 = a6;
    }
    if ( v12 )
      goto LABEL_8;
LABEL_6:
    if ( v13 )
    {
LABEL_8:
      v8 += 16;
      ++v7;
      goto LABEL_9;
    }
    v14 = -*(_DWORD *)(v8 + 12);
    v8 += -16 * *(_DWORD *)(v8 + 12);
    v7 += v14;
LABEL_9:
    v9 = v16;
  }
  result = dword_193F244;
  if ( dword_193F244 < v9 )
    result = v9;
  dword_193F244 = result;
  return result;
}
