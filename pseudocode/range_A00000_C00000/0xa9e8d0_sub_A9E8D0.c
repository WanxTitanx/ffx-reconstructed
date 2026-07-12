// Function: sub_A9E8D0
// Address: 0xa9e8d0
// Size: 0x19e
// Prototype: 

int __cdecl sub_A9E8D0(_DWORD *a1, int **a2, int a3, int a4, int a5)
{
  int *v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int i_1; // esi
  int v10; // ecx
  int **v11; // ebx
  int v12; // ecx
  int v13; // edx
  int v14; // edi
  int *i_2; // eax
  int *v16; // esi
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // esi
  int v21; // ebx
  int v22; // edx
  int v23; // eax
  int *v24; // ecx
  int i; // [esp+Ch] [ebp-1Ch]
  int v27; // [esp+10h] [ebp-18h]
  int v28; // [esp+14h] [ebp-14h]
  int v29; // [esp+18h] [ebp-10h]
  int *v30; // [esp+1Ch] [ebp-Ch]
  int *i_3; // [esp+20h] [ebp-8h]
  int v32; // [esp+24h] [ebp-4h]

  v5 = *a2;
  v6 = (*a2)[2];
  v30 = *a2;
  v7 = (a5 * a1[9]) >> 1;
  v29 = v6;
  if ( (*a2)[1] < v7 )
    v7 = v5[1];
  v8 = v7 - *v5;
  v27 = *a2[4];
  if ( v8 > 0 )
  {
    v28 = v8 / v6;
    i_1 = sub_A92150(a1, 4 * ((*a2[4] + v8 / v6 - 1) / *a2[4]));
    v10 = 0;
    for ( i = i_1; v10 < a5; ++v10 )
    {
      if ( *(_DWORD *)(a4 + 4 * v10) )
        break;
    }
    if ( v10 != a5 )
    {
      v11 = a2;
      v12 = 0;
      v32 = 0;
      if ( (int)a2[2] > 0 )
      {
        v13 = v28;
        do
        {
          v14 = 0;
          if ( v13 > 0 )
          {
            i_2 = (int *)i_1;
            i_3 = (int *)i_1;
            do
            {
              if ( !v12 )
              {
                v16 = v11[4];
                if ( v16[2] <= 0 )
                  return 0;
                v17 = sub_A94200(v11[4], (int)(a1 + 1));
                if ( v17 < 0 )
                  return 0;
                v18 = *(_DWORD *)(v16[6] + 4 * v17);
                if ( v18 == -1 )
                  return 0;
                if ( v18 >= v30[4] )
                  return 0;
                v19 = v11[7][v18];
                *i_3 = v19;
                if ( !v19 )
                  return 0;
                v12 = v32;
                i_2 = i_3;
                v13 = v28;
              }
              v20 = 0;
              if ( v27 > 0 )
              {
                v21 = v29 * v14;
                do
                {
                  if ( v14 >= v13 )
                    break;
                  v22 = *(_DWORD *)(*i_2 + 4 * v20);
                  v23 = 1 << v12;
                  v12 = v32;
                  if ( (v23 & v30[v22 + 6]) != 0 )
                  {
                    v24 = *(int **)(a2[5][v22] + 4 * v32);
                    if ( v24 && sub_A93630(v24, a3, v21 + *v30, a5, a1 + 1, v29) == -1 )
                      return 0;
                    v12 = v32;
                  }
                  v21 += v29;
                  i_2 = i_3;
                  v13 = v28;
                  ++v20;
                  ++v14;
                }
                while ( v20 < v27 );
                v11 = a2;
              }
              i_3 = ++i_2;
            }
            while ( v14 < v13 );
            i_1 = i;
          }
          v32 = ++v12;
        }
        while ( v12 < (int)v11[2] );
      }
    }
  }
  return 0;
}

