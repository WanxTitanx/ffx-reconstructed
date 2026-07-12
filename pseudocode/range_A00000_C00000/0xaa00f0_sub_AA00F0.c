// Function: sub_AA00F0
// Address: 0xaa00f0
// Size: 0x1ce
// Prototype: 

_DWORD *__cdecl sub_AA00F0(int a1, int a2)
{
  int v2; // edi
  _DWORD *v3; // ebx
  int v4; // esi
  int v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // esi
  int *v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // ecx
  _DWORD *v16; // edx
  int v17; // edx
  int *v18; // eax
  int v19; // ecx
  unsigned int *v21; // [esp+Ch] [ebp-Ch]
  int v22; // [esp+10h] [ebp-8h]
  _DWORD *v23; // [esp+14h] [ebp-4h]
  int v24; // [esp+20h] [ebp+8h]

  v2 = 0;
  v3 = calloc_0(1u, 0xB18u);
  v23 = v3;
  memset(v3, 0, 0xB18u);
  v4 = a2;
  v24 = *(_DWORD *)(a1 + 28);
  *v3 = sub_42EB10(a2, 24);
  v3[1] = sub_42EB10(a2, 24);
  v3[2] = sub_42EB10(a2, 24) + 1;
  v3[3] = sub_42EB10(a2, 6) + 1;
  v5 = sub_42EB10(a2, 8);
  v3[5] = v5;
  if ( v5 >= 0 )
  {
    v22 = 0;
    if ( (int)v3[3] <= 0 )
    {
LABEL_12:
      v10 = 0;
      if ( v2 <= 0 )
      {
LABEL_17:
        v13 = v3[5];
        v14 = *(_DWORD *)(v24 + 24);
        if ( v13 < v14 )
        {
          v15 = 0;
          if ( v2 <= 0 )
          {
LABEL_24:
            v17 = 1;
            v18 = *(int **)(v24 + 4 * v13 + 1824);
            v19 = *v18;
            if ( *v18 >= 1 )
            {
              if ( v19 <= 0 )
              {
LABEL_28:
                v3[4] = v17;
                return v3;
              }
              while ( 1 )
              {
                v17 *= v3[3];
                if ( v17 > v18[1] )
                  break;
                if ( --v19 <= 0 )
                  goto LABEL_28;
              }
            }
          }
          else
          {
            v16 = v3 + 70;
            while ( *v16 < v14 )
            {
              v3 = v23;
              if ( !*(_DWORD *)(*(_DWORD *)(v24 + 4 * *v16 + 1824) + 12) )
                break;
              ++v15;
              ++v16;
              if ( v15 >= v2 )
              {
                v13 = v23[5];
                goto LABEL_24;
              }
            }
          }
        }
      }
      else
      {
        v11 = v3 + 70;
        while ( 1 )
        {
          v12 = sub_42EB10(a2, 8);
          if ( v12 < 0 )
            break;
          *v11 = v12;
          ++v10;
          ++v11;
          if ( v10 >= v2 )
          {
            v3 = v23;
            goto LABEL_17;
          }
        }
        v3 = v23;
      }
    }
    else
    {
      v21 = v3 + 6;
      while ( 1 )
      {
        v6 = sub_42EB10(v4, 3);
        v7 = sub_42EB10(a2, 1);
        if ( v7 < 0 )
          break;
        if ( v7 )
        {
          v8 = sub_42EB10(a2, 5);
          if ( v8 < 0 )
            break;
          v6 |= 8 * v8;
        }
        v9 = 0;
        for ( *v21 = v6; v6; v6 >>= 1 )
          v9 += v6 & 1;
        v2 += v9;
        ++v22;
        ++v21;
        if ( v22 >= v3[3] )
          goto LABEL_12;
        v4 = a2;
      }
    }
  }
  memset(v3, 0, 0xB18u);
  free_1(v3);
  return 0;
}

