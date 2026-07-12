// Function: sub_AA19D0
// Address: 0xaa19d0
// Size: 0x1b2
// Prototype: int __cdecl(int, int, int, void *)

int __cdecl sub_AA19D0(int a1, _DWORD *a2, _DWORD *a3, float *a4)
{
  __int64 v4; // rax
  _DWORD *v5; // edx
  int v6; // ebx
  int n255; // ecx
  int v8; // esi
  int v9; // edi
  int *v10; // eax
  int v11; // eax
  int n255_1; // edi
  unsigned int v13; // edx
  float *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm0_4
  int v18; // [esp+8h] [ebp-10h]
  int v19; // [esp+Ch] [ebp-Ch]
  _DWORD *v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]

  v18 = a2[324];
  v4 = *(int *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 64) + 4) + 28) + 4 * *(_DWORD *)(a1 + 28));
  LODWORD(v4) = v4 - HIDWORD(v4);
  v5 = a3;
  v6 = (int)v4 >> 1;
  if ( a3 )
  {
    n255 = *a3 * *(_DWORD *)(a2[324] + 832);
    v8 = 0;
    if ( n255 >= 0 )
    {
      if ( n255 > 255 )
        n255 = 255;
    }
    else
    {
      n255 = 0;
    }
    v9 = 1;
    v21 = 1;
    if ( (int)a2[321] > 1 )
    {
      v10 = a2 + 66;
      v20 = a2 + 66;
      do
      {
        v19 = *v10;
        v11 = v5[*v10];
        if ( (v11 & 0x7FFF) == v11 )
        {
          v8 = *(_DWORD *)(v18 + 4 * v19 + 836);
          n255_1 = (v11 & 0x7FFF) * *(_DWORD *)(v18 + 832);
          if ( n255_1 >= 0 )
          {
            if ( n255_1 > 255 )
              n255_1 = 255;
          }
          else
          {
            n255_1 = 0;
          }
          sub_AA25C0(v8, n255, n255_1, a4);
          n255 = n255_1;
          v9 = v21;
        }
        ++v9;
        v10 = v20 + 1;
        v5 = a3;
        v21 = v9;
        ++v20;
      }
      while ( v9 < a2[321] );
    }
    if ( v8 < v6 )
    {
      if ( v6 - v8 >= 4 )
      {
        v13 = ((unsigned int)(v6 - v8 - 4) >> 2) + 1;
        v14 = &a4[v8 + 2];
        v8 += 4 * v13;
        do
        {
          v15 = dword_B8F068[n255] * *(v14 - 2);
          v14 += 4;
          *(v14 - 6) = v15;
          *(v14 - 5) = *(v14 - 5) * dword_B8F068[n255];
          *(v14 - 4) = dword_B8F068[n255] * *(v14 - 4);
          *(v14 - 3) = dword_B8F068[n255] * *(v14 - 3);
          --v13;
        }
        while ( v13 );
      }
      for ( ; v8 < v6; a4[v8 - 1] = v16 )
        v16 = a4[v8++] * dword_B8F068[n255];
    }
    return 1;
  }
  else
  {
    memset(a4, 0, 4 * v6);
    return 0;
  }
}

