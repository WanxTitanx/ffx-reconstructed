// Function: sub_803280
// Address: 0x803280
int __cdecl sub_803280(int a1, int a2, int n2, int a4)
{
  int n8_2; // eax
  int n8_3; // eax
  int v6; // edx
  int v7; // esi
  int v8; // esi
  int n8; // edi
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int *v13; // esi
  int n8_1; // [esp+4h] [ebp-10h]
  int n8_4; // [esp+8h] [ebp-Ch]
  int v16; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]

  sub_832190(a2, 1);
  if ( sub_80F790(a2) )
    return sub_80F5C0(a1, n2, a4);
  n8_3 = sub_830490(a2);
  v6 = a1;
  n8_1 = n8_3;
  v7 = n8_3 + 1;
  *(_BYTE *)(a1 + 6) = n2;
  n8_2 = 0;
  v8 = a1 + 16 * v7;
  n8 = 0;
  v16 = v8;
  *(_DWORD *)a1 = a2;
  v17 = a1 + 16;
  n8_4 = 0;
  if ( n8_1 > 0 )
  {
    do
    {
      if ( sub_82AE50(a2, n8) )
      {
        n8_2 = n8_4;
      }
      else
      {
        *(_WORD *)(v17 + 8) |= 1u;
        *(_DWORD *)v17 = unknown_libname_742(v8);
        v10 = sub_830580(a2, n8, 0);
        *(_DWORD *)(v17 + 4) = unknown_libname_742(v10);
        *(_WORD *)(v17 + 10) = n8;
        v11 = sub_8304D0(a2, n8);
        sub_830510(a2, n8, v16);
        v12 = v16 + ((v11 + 15) & 0xFFFFFF0);
        if ( n2 == 2 )
          v12 = sub_A69F10(v16, v16 + ((v11 + 15) & 0xFFFFFF0), a4);
        v17 += 16;
        v8 = v12;
        n8_2 = n8_4 + 1;
        v16 = v8;
        ++n8_4;
      }
      ++n8;
    }
    while ( n8 < n8_1 );
    v6 = a1;
  }
  *(_WORD *)(v6 + 4) = n8_2;
  if ( v6 < (int)&unk_1F00000 )
  {
    v13 = (int *)&unk_11A11C0;
    n8_2 = 0;
    while ( *v13 != a2 )
    {
      ++n8_2;
      v13 += 4;
      if ( n8_2 >= 8 )
      {
        v13 = (int *)&unk_11A11C0;
        n8_2 = 0;
        while ( *v13 )
        {
          ++n8_2;
          v13 += 4;
          if ( n8_2 >= 8 )
          {
            n8_2 = nullsub_35(1);
            v6 = a1;
            goto LABEL_19;
          }
        }
        break;
      }
    }
LABEL_19:
    *v13 = a2;
    v13[1] = v6;
  }
  return n8_2;
}
