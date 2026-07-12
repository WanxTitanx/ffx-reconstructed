// Function: sub_803140
// Address: 0x803140
int __cdecl sub_803140(int a1, int a2, int n2, int a4)
{
  int n8; // eax
  int n8_3; // eax
  int v6; // ecx
  int n8_2; // edx
  int v8; // esi
  int n8_5; // edi
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
  n8_2 = n8_3;
  v17 = a1 + 16 * (n8_3 + 1);
  *(_BYTE *)(a1 + 6) = n2;
  v8 = a1 + 16;
  n8 = 0;
  n8_5 = 0;
  n8_4 = n8_2;
  *(_DWORD *)a1 = a2;
  v16 = a1 + 16;
  if ( n8_2 > 0 )
  {
    n8_1 = n8_2;
    do
    {
      if ( !sub_82AE50(a2, n8_5) )
        *(_WORD *)(v8 + 8) |= 1u;
      *(_DWORD *)v8 = unknown_libname_742(v17);
      v10 = sub_830580(a2, n8_5, 0);
      *(_DWORD *)(v8 + 4) = unknown_libname_742(v10);
      *(_WORD *)(v8 + 10) = n8_5;
      v11 = sub_8304D0(a2, n8_5);
      sub_830510(a2, n8_5, v17);
      v12 = v17 + ((v11 + 15) & 0xFFFFFF0);
      if ( n2 == 2 )
        v12 = sub_A69F10(v17, v17 + ((v11 + 15) & 0xFFFFFF0), a4);
      v8 = v16 + 16;
      ++n8_5;
      v17 = v12;
      v16 += 16;
    }
    while ( n8_5 < n8_4 );
    v6 = a1;
    n8 = n8_1;
  }
  *(_WORD *)(v6 + 4) = n8;
  if ( v6 < (int)&unk_1F00000 )
  {
    v13 = (int *)&unk_11A11C0;
    n8 = 0;
    while ( *v13 != a2 )
    {
      ++n8;
      v13 += 4;
      if ( n8 >= 8 )
      {
        v13 = (int *)&unk_11A11C0;
        n8 = 0;
        while ( *v13 )
        {
          ++n8;
          v13 += 4;
          if ( n8 >= 8 )
          {
            n8 = nullsub_35(1);
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
  return n8;
}
