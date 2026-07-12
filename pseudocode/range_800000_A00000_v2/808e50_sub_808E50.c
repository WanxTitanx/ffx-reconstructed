// Function: sub_808E50
// Address: 0x808e50
int __cdecl sub_808E50(int a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  unsigned int n0x4000; // eax
  int v5; // esi
  int v7; // esi
  int v8; // ebx
  int v9; // edx
  int v10; // esi
  int v11; // edi
  int i; // ecx
  int j; // ecx
  bool v14; // zf
  char v15; // al
  int n4; // [esp+1Ch] [ebp-38h]
  int v17; // [esp+24h] [ebp-30h]
  int v18; // [esp+28h] [ebp-2Ch]
  int v19; // [esp+2Ch] [ebp-28h]
  int v20[4]; // [esp+30h] [ebp-24h] BYREF
  float v21[3]; // [esp+40h] [ebp-14h] BYREF
  float v22; // [esp+4Ch] [ebp-8h]

  v2 = *(_DWORD *)(a1 + 544);
  v3 = a2;
  n0x4000 = *(_WORD *)(a1 + 538) & 0xF000;
  v18 = v2;
  if ( n0x4000 > 0x2000 )
  {
    if ( n0x4000 == 12288 )
    {
      v15 = sub_82CBE0(0);
      if ( !unk_11A0048 )
      {
        unk_11A0048 = 1;
        unk_11A0049 = v15;
      }
      return a2 + 2;
    }
    else if ( n0x4000 == 0x4000 )
    {
      if ( unk_11A0048 )
      {
        sub_82CBE0(unk_11A0049);
        unk_11A0048 = 0;
      }
      return a2 + 2;
    }
    else
    {
      return a2;
    }
  }
  else if ( n0x4000 == 0x2000 )
  {
    v8 = *(_DWORD *)(v2 + 188);
    if ( v8 )
    {
      v9 = v8 + 16;
      v10 = a2 + 16;
      v11 = *(_DWORD *)(a1 + 544);
      v19 = a1;
      v17 = v8 + 16;
      n4 = 4;
      do
      {
        if ( *(_WORD *)(v10 - 14) )
        {
          v18 = sub_800F80((_DWORD *)(a1 + 768), v11, *(_WORD *)(v10 - 14));
          sub_6EDA80(v20, v11 + 144, v18 + 144);
          sub_6ED4B0(v19, v20);
          sub_6ED4B0(v20, v18 + 48);
          sub_6EDA30((int)v20, (int)v20, *(float *)&v20[3]);
          sub_6EDA30((int)v20, (int)v20, 0.000030517578);
          sub_6ED4B0(v19 + 16, v20);
        }
        else
        {
          *(_QWORD *)&n1065353216 = *(_QWORD *)v8;
          n1065353216_2 = *(_DWORD *)(v8 + 8);
          n1065353216_3 = *(_DWORD *)(v8 + 12);
          *(_QWORD *)(v10 - 16) = *(_QWORD *)&n1065353216;
          *(_DWORD *)(v10 - 8) = n1065353216_2;
          *(_DWORD *)(v10 - 4) = n1065353216_3;
          *(_QWORD *)&n1065353216 = *(_QWORD *)v9;
          n1065353216_2 = *(_DWORD *)(v9 + 8);
          n1065353216_3 = *(_DWORD *)(v9 + 12);
          *(_QWORD *)v10 = *(_QWORD *)&n1065353216;
          *(_DWORD *)(v10 + 8) = n1065353216_2;
          *(_DWORD *)(v10 + 12) = n1065353216_3;
        }
        sub_6ED830(v19, v19);
        sub_6EDA80(v21, v19, v8);
        sub_6EDA30((int)v21, (int)v21, *(float *)(v18 + 76));
        sub_6EDA30((int)v21, (int)v21, 0.00390625);
        sub_6ED3D0(v21, v21, v8);
        v22 = 1.0;
        sub_6ED4B0(v19, v21);
        sub_6EDA80(v21, v19 + 16, v17);
        sub_6EDA30((int)v21, (int)v21, *(float *)(v18 + 76));
        sub_6EDA30((int)v21, (int)v21, 0.00390625);
        sub_6ED3D0(v21, v21, v17);
        for ( i = 0; i < 4; ++i )
        {
          if ( v21[i] > 1.0 )
            v21[i] = 1.0;
        }
        for ( j = 0; j < 4; ++j )
        {
          if ( v21[j] < 0.0 )
            v21[j] = 0.0;
        }
        v22 = 1.0;
        sub_6ED4B0(v19 + 16, v21);
        v19 += 32;
        v9 = v17 + 32;
        v10 += 2;
        v8 += 32;
        v14 = n4-- == 1;
        v17 += 32;
      }
      while ( !v14 );
      sub_8364B0(0, a1);
      sub_836390(0, a1 + 16);
      sub_8364B0(1, a1 + 32);
      sub_836390(1, a1 + 48);
      sub_8364B0(2, a1 + 64);
      sub_836390(2, a1 + 80);
      sub_836390(3, a1 + 112);
      v3 = a2;
    }
    return v3 + 10;
  }
  else if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( n0x4000 == 4096 )
    {
      v5 = *(_DWORD *)(v2 + 188);
      sub_8364B0(0, v5);
      sub_8364B0(1, v5 + 32);
      sub_8364B0(2, v5 + 64);
      sub_836390(0, v5 + 16);
      sub_836390(1, v5 + 48);
      sub_836390(2, v5 + 80);
      sub_836390(3, v5 + 112);
      sub_7FF0F0(*(_DWORD *)(a1 + 936), *(_DWORD *)(v2 + 188));
      *(_DWORD *)(v2 + 188) = 0;
      return a2 + 2;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    v7 = sub_7FF6A0(*(_DWORD *)(a1 + 936), 128);
    *(_DWORD *)(v2 + 188) = v7;
    sub_836240(0, v7);
    sub_836240(1, v7 + 32);
    sub_836240(2, v7 + 64);
    sub_836170(0, v7 + 16);
    sub_836170(1, v7 + 48);
    sub_836170(2, v7 + 80);
    sub_836170(3, v7 + 112);
    return a2 + 2;
  }
}
