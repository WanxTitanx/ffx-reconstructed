// Function: sub_8033D0
// Address: 0x8033d0
int __cdecl sub_8033D0(int a1, int a2, int n2, int a4, int a5, int a6)
{
  int n8_1; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // esi
  int n8; // edi
  int *v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // [esp+4h] [ebp-Ch]
  int v17; // [esp+8h] [ebp-8h]
  int n8_2; // [esp+Ch] [ebp-4h]
  int v19; // [esp+28h] [ebp+18h]

  sub_832190(a2, 1);
  if ( a5 && sub_80F790(a2) )
    return sub_80F5C0(a1, n2, a6);
  v7 = sub_830490(a2);
  v8 = a1;
  v9 = v7;
  v19 = a1 + 16 * (v7 + 1);
  *(_BYTE *)(a1 + 6) = n2;
  n8_1 = 0;
  v10 = a1 + 16;
  n8 = 0;
  v16 = v9;
  *(_DWORD *)a1 = a2;
  v17 = a1 + 16;
  n8_2 = 0;
  if ( v9 > 0 )
  {
    while ( sub_82AE50(a2, n8) )
    {
      if ( !a4 )
        goto LABEL_20;
      n8_1 = n8_2;
LABEL_8:
      if ( ++n8 >= v16 )
      {
        v8 = a1;
        goto LABEL_10;
      }
    }
    *(_WORD *)(v10 + 8) |= 1u;
LABEL_20:
    *(_DWORD *)v10 = unknown_libname_742(v19);
    v13 = sub_830580(a2, n8, 0);
    *(_DWORD *)(v10 + 4) = unknown_libname_742(v13);
    *(_WORD *)(v10 + 10) = n8;
    v14 = sub_8304D0(a2, n8);
    sub_830510(a2, n8, v19);
    v15 = v19 + ((v14 + 15) & 0xFFFFFF0);
    if ( n2 == 2 )
      v15 = sub_A69F10(v19, v19 + ((v14 + 15) & 0xFFFFFF0), a6);
    v19 = v15;
    v10 = v17 + 16;
    n8_1 = n8_2 + 1;
    v17 += 16;
    ++n8_2;
    goto LABEL_8;
  }
LABEL_10:
  *(_WORD *)(v8 + 4) = n8_1;
  if ( v8 < (int)&unk_1F00000 )
  {
    v12 = (int *)&unk_11A11C0;
    n8_1 = 0;
    while ( *v12 != a2 )
    {
      ++n8_1;
      v12 += 4;
      if ( n8_1 >= 8 )
      {
        v12 = (int *)&unk_11A11C0;
        n8_1 = 0;
        while ( *v12 )
        {
          ++n8_1;
          v12 += 4;
          if ( n8_1 >= 8 )
          {
            n8_1 = nullsub_35(1);
            v8 = a1;
            goto LABEL_18;
          }
        }
        break;
      }
    }
LABEL_18:
    *v12 = a2;
    v12[1] = v8;
  }
  return n8_1;
}
