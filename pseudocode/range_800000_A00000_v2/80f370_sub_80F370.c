// Function: sub_80F370
// Address: 0x80f370
__int16 *__cdecl sub_80F370(int a1, __int16 *a2)
{
  int n0x2000; // eax
  int v4; // esi
  int v5; // ebx
  void *v7; // eax
  int v8; // esi
  _DWORD *v9; // edi
  int v10; // eax
  int v11; // edi
  int v12; // esi
  int v13; // esi
  int v14; // edi
  int v15; // [esp+Ch] [ebp-4h]
  int v16; // [esp+Ch] [ebp-4h]
  int v17; // [esp+18h] [ebp+8h]

  v15 = *(_DWORD *)(a1 + 544);
  n0x2000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( n0x2000 == 4096 )
    {
      v11 = *(_DWORD *)(sub_800F80((_DWORD *)(a1 + 768), *(_DWORD *)(a1 + 544), a2[1]) + 188);
      v12 = v11 + 96 * (*(unsigned __int16 *)(v11 + 14) + 3);
      *(_DWORD *)v12 = v15;
      *(_WORD *)(v12 + 4) = (int)*(float *)(v15 + 64);
      *(_WORD *)(v12 + 6) = (int)*(float *)(v15 + 76);
      n1065353216 = *(_DWORD *)(v15 + 48);
      unk_C8F52C = *(_DWORD *)(v15 + 52);
      unk_C8F530 = *(_DWORD *)(v15 + 56);
      unk_C8F534 = *(_DWORD *)(v15 + 60);
      *(_DWORD *)(v12 + 16) = n1065353216;
      *(_DWORD *)(v12 + 20) = unk_C8F52C;
      *(_DWORD *)(v12 + 24) = unk_C8F530;
      *(float *)(v12 + 28) = 0.0;
      ++*(_WORD *)(v11 + 14);
      return a2 + 2;
    }
    else if ( n0x2000 == 0x2000 )
    {
      v4 = *(_DWORD *)(sub_800E80(0, 0, 18, 1) + 188);
      v5 = **(_DWORD **)(v4 + 4);
      v17 = v4;
      sub_831440(v5, -1, 15360);
      sub_831410(v5, -1, 12000);
      if ( sub_8037A0(v5, 2, 1, 0) )
      {
        v7 = (void *)sub_7B7E30(0);
        if ( !v7 )
          v7 = &unk_2333500;
        *(_DWORD *)(v4 + 8) = v7;
        sub_8033D0((int)v7, v5, 2, 0, 0, *(_DWORD *)(a1 + 808));
        sub_803650(v5);
        v8 = 0;
        v16 = sub_830490(v5);
        if ( v16 > 0 )
        {
          v9 = (_DWORD *)(v17 + 160);
          do
          {
            *(v9 - 32) = sub_82AE90(v5, v8);
            v10 = sub_82AE70(v5, v8++);
            *v9++ = v10;
          }
          while ( v8 < v16 );
        }
        return a2 + 1;
      }
      else
      {
        return a2 + 3;
      }
    }
    else
    {
      return a2;
    }
  }
  else
  {
    v13 = a2[1];
    v14 = sub_7FF6A0(*(_DWORD *)(a1 + 936), 96 * (v13 + 3));
    *(_DWORD *)(v15 + 188) = v14;
    *(_WORD *)(v14 + 12) = v13;
    *(_WORD *)(v14 + 14) = 0;
    *(_BYTE *)(v14 + 16) = 0;
    LOWORD(v13) = a2[3];
    *(_DWORD *)v14 = (char *)&unk_12A2280 + 32 * sub_7FE9C0(a2[2]);
    *(_DWORD *)(v14 + 4) = (char *)&unk_12A2280 + 32 * sub_7FE9C0((__int16)v13);
    *(_BYTE *)(v15 + 187) = 18;
    sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
    return a2 + 4;
  }
}
