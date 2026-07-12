// Function: sub_81BCD0
// Address: 0x81bcd0
int __cdecl sub_81BCD0(int a1, int a2)
{
  int v3; // edi
  int v4; // ecx
  int n0x2000; // eax
  int v7; // edx
  int v8; // esi
  int v9; // eax
  _DWORD *i; // edx
  __int16 n4; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]
  unsigned __int16 *v13; // [esp+20h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 544);
  v4 = v3;
  n0x2000 = *(_WORD *)(a1 + 538) & 0x7000;
  if ( (*(_WORD *)(a1 + 538) & 0x7000) != 0 )
  {
    if ( n0x2000 == 4096 )
    {
      n4 = 4;
    }
    else
    {
      if ( n0x2000 != 0x2000 )
        return a2;
      v4 = sub_800F80((_DWORD *)(a1 + 768), v3, *(_WORD *)(a2 + 4));
      n4 = 6;
    }
    if ( !*(_WORD *)(a1 + 530) )
    {
      if ( *(_BYTE *)(v4 + 187) == 9 )
      {
        v13 = *(unsigned __int16 **)(v4 + 168);
        v7 = 40 * (unsigned __int16)(v13[1]++ % (int)*v13);
        *(_DWORD *)&v13[v7 + 16] = word_C8F508[0];
        *(float *)&v13[v7 + 18] = word_C8F50C;
        *(float *)&v13[v7 + 20] = word_C8F510;
        *(float *)&v13[v7 + 22] = word_C8F514[0];
        *(_DWORD *)&v13[v7 + 16] = a2 + *(__int16 *)(a2 + 2);
        *(_DWORD *)&v13[v7 + 18] = 0;
        HIBYTE(v13[v7 + 20]) = 1;
        *(_DWORD *)&v13[v7 + 54] = word_C8F508[0];
        *(float *)&v13[v7 + 56] = word_C8F50C;
        *(float *)&v13[v7 + 58] = word_C8F510;
        *(float *)&v13[v7 + 60] = word_C8F514[0];
        v12 = v7 * 2;
        v13[v7 + 54] = (v3 - (__int64)*(int *)(a1 + 800)) / 256;
        *(_QWORD *)&n1065353216 = *(_QWORD *)(v3 + 96);
        n1065353216_2 = *(_DWORD *)(v3 + 104);
        n1065353216_3 = *(_DWORD *)(v3 + 108);
        *(_QWORD *)&v13[v7 + 32] = *(_QWORD *)&n1065353216;
        *(_DWORD *)&v13[v7 + 36] = n1065353216_2;
        *(_DWORD *)&v13[v7 + 38] = n1065353216_3;
        *(_QWORD *)&n1065353216 = *(_QWORD *)(v3 + 128);
        n1065353216_2 = *(_DWORD *)(v3 + 136);
        n1065353216_3 = *(_DWORD *)(v3 + 140);
        *(_QWORD *)&v13[v7 + 40] = *(_QWORD *)&n1065353216;
        *(_DWORD *)&v13[v7 + 44] = n1065353216_2;
        *(_DWORD *)&v13[v7 + 46] = n1065353216_3;
        if ( *(__int16 *)(a1 + 538) >= 0 )
        {
          *(_QWORD *)&n1065353216 = *(_QWORD *)(v3 + 64);
          n1065353216_2 = *(_DWORD *)(v3 + 72);
          n1065353216_3 = *(_DWORD *)(v3 + 76);
          *(_QWORD *)&v13[v7 + 24] = *(_QWORD *)&n1065353216;
          *(_DWORD *)&v13[v7 + 28] = n1065353216_2;
          *(_DWORD *)&v13[v7 + 30] = n1065353216_3;
        }
        else
        {
          sub_7EA760(&v13[v7 + 24], v3 + 144, 16.0);
        }
        *(_DWORD *)((char *)v13 + v12 + 92) = 0;
        return a2 + n4;
      }
      printf("anmm should never be NULL in original PS2 version.\n");
    }
    return a2 + n4;
  }
  *(_BYTE *)(v3 + 187) = 9;
  v8 = *(unsigned __int16 *)(a2 + 2);
  v9 = sub_7FF6A0(*(_DWORD *)(a1 + 936), 80 * v8 + 112);
  *(_DWORD *)(v3 + 188) = v9;
  *(_WORD *)v9 = v8;
  *(_WORD *)(v9 + 2) = 0;
  *(_WORD *)(v9 + 4) = *(_WORD *)(v3 + 196);
  *(_WORD *)(v9 + 6) = *(_WORD *)(v3 + 198);
  *(_DWORD *)(v9 + 8) = *(_DWORD *)(v3 + 200);
  *(_DWORD *)(v3 + 168) = v9;
  for ( i = (_DWORD *)(v9 + 32); (_WORD)v8; i += 20 )
  {
    v8 += 0xFFFF;
    *i = 0;
  }
  sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
  return a2 + 4;
}
