// Function: sub_A8FAC0
// Address: 0xa8fac0
// Size: 0x1b4
// Prototype: int(void)

int __fastcall sub_A8FAC0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v3; // edi
  int n6_2; // eax
  size_t Size; // esi
  void *v6; // edi
  int v7; // edi
  int v8; // esi
  void *v9; // edi
  size_t Count; // esi
  void *v11; // edi
  int n6_3; // esi
  size_t Count_1; // esi
  void *v14; // edi
  int n6_1; // [esp+Ch] [ebp-14h]
  int n6; // [esp+10h] [ebp-10h]
  int v18; // [esp+14h] [ebp-Ch]
  int v19; // [esp+18h] [ebp-8h]

  v3 = a1;
  v18 = 0;
  n6_2 = sub_42EB10(a2, 32);
  n6 = n6_2;
  if ( n6_2 >= 0 && n6_2 <= a2[4] - 8 )
  {
    Size = n6_2 + 1;
    v6 = calloc_0(n6_2 + 1, 1u);
    memset(v6, 0, Size);
    a1[3] = v6;
    sub_A90440(n6);
    v7 = sub_42EB10(a2, 32);
    if ( v7 < 0 || v7 > (a2[4] - (a2[1] + 7) / 8 - *a2) >> 2 )
    {
      v3 = a1;
    }
    else
    {
      a1[2] = v7;
      v8 = v7 + 1;
      v9 = calloc_0(v7 + 1, 4u);
      memset(v9, 0, 4 * v8);
      Count = a1[2] + 1;
      *a1 = v9;
      v11 = calloc_0(Count, 4u);
      memset(v11, 0, 4 * Count);
      a1[1] = v11;
      v3 = a1;
      v19 = 0;
      if ( (int)a1[2] <= 0 )
        return v18 + n6 + 12;
      while ( 1 )
      {
        n6_3 = sub_42EB10(a2, 32);
        n6_1 = n6_3;
        if ( n6_3 < 0 || n6_3 > a2[4] - (a2[1] + 7) / 8 - *a2 )
          break;
        *(_DWORD *)(v3[1] + 4 * v19) = n6_3;
        Count_1 = n6_3 + 1;
        v14 = calloc_0(Count_1, 1u);
        memset(v14, 0, Count_1);
        *(_DWORD *)(*a1 + 4 * v19) = v14;
        v3 = a1;
        sub_A90440(n6_1);
        v18 += n6_1 + 4;
        if ( ++v19 >= a1[2] )
          return v18 + n6 + 12;
      }
    }
  }
  sub_A90030(v3);
  return -133;
}

