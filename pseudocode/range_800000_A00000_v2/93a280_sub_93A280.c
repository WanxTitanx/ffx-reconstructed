// Function: sub_93A280
// Address: 0x93a280
int __cdecl sub_93A280(int a1, char *Str)
{
  int *v2; // edi
  int v4; // eax
  int v5; // eax
  size_t Size; // esi
  int v7; // eax
  int v8; // ebx
  _DWORD *v9; // esi
  _DWORD *v10; // ecx
  int v11; // edx
  unsigned int v12; // eax
  _DWORD *v13; // ebx
  int v14; // eax
  float v15; // edi
  int v16; // esi
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  float v21; // ecx
  int v22; // ebx
  _DWORD *v23; // eax
  int v24; // edx
  int v25; // edx
  int v26; // esi
  int v27; // eax
  _DWORD *v28; // ecx
  unsigned int v29; // eax
  unsigned int v30; // eax
  int v31; // esi
  int v32; // esi
  float v33; // [esp+10h] [ebp-40h] BYREF
  int v34; // [esp+14h] [ebp-3Ch]
  int v35; // [esp+18h] [ebp-38h]
  int v36; // [esp+1Ch] [ebp-34h]
  int v37; // [esp+20h] [ebp-30h]
  int *v38; // [esp+24h] [ebp-2Ch]
  int v39; // [esp+28h] [ebp-28h]
  void *v40; // [esp+2Ch] [ebp-24h]
  int v41; // [esp+30h] [ebp-20h]
  float v42; // [esp+34h] [ebp-1Ch]
  int v43; // [esp+38h] [ebp-18h]
  _DWORD v44[4]; // [esp+3Ch] [ebp-14h]

  v39 = a1;
  v44[0] = 0;
  v44[1] = 2;
  v44[2] = 4;
  v44[3] = 6;
  v2 = (int *)sub_924750();
  v38 = v2;
  if ( sub_9243C0(v2, Str) )
  {
    v4 = v2[6];
    v43 = v4;
    if ( !v4 )
    {
      v4 = 1;
      v43 = 1;
    }
    v5 = 4 * v4;
    Size = 4 * v5;
    v42 = 0.0;
    v41 = v5;
    v40 = (void *)sub_9258A0(4 * v5);
    memset(v40, 0, Size);
    v7 = v43;
    v8 = 0;
    if ( v43 > 0 )
    {
      v9 = v40;
      do
      {
        v10 = (_DWORD *)v2[5];
        if ( v10[9] == v8 )
        {
          v11 = 0;
          if ( v2[4] > 0 )
          {
            do
            {
              if ( (*v10 & 1) != 0 )
                v12 = *v10 & 2 | 4;
              else
                v12 = *v10 & 2;
              ++v11;
              ++v9[v12 >> 1];
              v10 += 22;
            }
            while ( v11 < v2[4] );
            v7 = v43;
          }
        }
        ++v8;
        v9 += 4;
      }
      while ( v8 < v7 );
    }
    v13 = v40;
    v14 = 0;
    if ( v41 > 0 )
    {
      v15 = 0.0;
      do
      {
        if ( *((_DWORD *)v40 + v14) )
          ++LODWORD(v15);
        ++v14;
      }
      while ( v14 < v41 );
      v42 = v15;
      v2 = v38;
    }
    v33 = v42;
    v16 = sub_9258A0(12 * LODWORD(v42));
    v17 = v41;
    v34 = v16;
    v35 = *v2;
    v18 = 0;
    v36 = 0;
    if ( v41 > 0 )
    {
      v19 = 0;
      do
      {
        if ( v13[v18] )
        {
          *(_DWORD *)(v19 + v16) = v44[v18 & 3];
          *(_DWORD *)(v19 + v16 + 4) = v13[v18];
          *(_DWORD *)(v19 + v16 + 8) = (unsigned int)v18 >> 2;
          v16 = v34;
          v17 = v41;
          v19 += 12;
        }
        ++v18;
      }
      while ( v18 < v17 );
    }
    v20 = v39;
    sub_927BE0(v39, &v33);
    v21 = 0.0;
    v22 = 0;
    v42 = 0.0;
    if ( v41 > 0 )
    {
      v23 = v40;
      v24 = v41;
      do
      {
        if ( v23[v22] )
        {
          v37 = v22 & 3;
          v43 = (unsigned int)v22 >> 2;
          v38 = (int *)v2[5];
          v25 = sub_9282A0(v20, LODWORD(v21));
          if ( v25 )
          {
            v26 = 0;
            if ( v2[4] > 0 )
            {
              v27 = v43;
              v28 = v38 + 18;
              do
              {
                if ( *(v28 - 9) == v27 )
                {
                  if ( (*(v28 - 18) & 1) != 0 )
                    v29 = *(v28 - 18) & 2 | 4;
                  else
                    v29 = *(v28 - 18) & 2;
                  v30 = v29 >> 1;
                  if ( v30 == v37 )
                  {
                    switch ( v30 )
                    {
                      case 0u:
                        *(_DWORD *)v25 = *v28;
                        *(_DWORD *)(v25 + 4) = v28[1];
                        *(_DWORD *)(v25 + 8) = v28[2];
                        *(_WORD *)(v25 + 12) = *((_WORD *)v28 - 34);
                        *(_WORD *)(v25 + 14) = *((_WORD *)v28 - 32);
                        *(_WORD *)(v25 + 16) = *((_WORD *)v28 - 30);
                        v25 += 20;
                        break;
                      case 1u:
                        *(_DWORD *)v25 = *v28;
                        *(_DWORD *)(v25 + 4) = v28[1];
                        *(_DWORD *)(v25 + 8) = v28[2];
                        *(_WORD *)(v25 + 12) = *((_WORD *)v28 - 34);
                        *(_WORD *)(v25 + 14) = *((_WORD *)v28 - 32);
                        *(_WORD *)(v25 + 16) = *((_WORD *)v28 - 30);
                        v25 += 32;
                        break;
                      case 2u:
                        *(_DWORD *)v25 = *v28;
                        *(_DWORD *)(v25 + 4) = v28[2];
                        *(_DWORD *)(v25 + 8) = v28[1];
                        *(_DWORD *)(v25 + 12) = v28[3];
                        *(_WORD *)(v25 + 16) = *((_WORD *)v28 - 34);
                        *(_WORD *)(v25 + 18) = *((_WORD *)v28 - 30);
                        *(_WORD *)(v25 + 20) = *((_WORD *)v28 - 32);
                        *(_WORD *)(v25 + 22) = *((_WORD *)v28 - 28);
                        v25 += 24;
                        break;
                      case 3u:
                        *(_DWORD *)v25 = *v28;
                        *(_DWORD *)(v25 + 4) = v28[2];
                        *(_DWORD *)(v25 + 8) = v28[1];
                        *(_DWORD *)(v25 + 12) = v28[3];
                        *(_WORD *)(v25 + 16) = *((_WORD *)v28 - 34);
                        *(_WORD *)(v25 + 18) = *((_WORD *)v28 - 30);
                        *(_WORD *)(v25 + 20) = *((_WORD *)v28 - 32);
                        *(_WORD *)(v25 + 22) = *((_WORD *)v28 - 28);
                        v25 += 40;
                        break;
                      default:
                        break;
                    }
                  }
                  v27 = v43;
                }
                ++v26;
                v28 += 22;
              }
              while ( v26 < v2[4] );
            }
            v20 = v39;
            LODWORD(v21) = ++LODWORD(v42);
          }
          else
          {
            v21 = v42;
          }
          v24 = v41;
          v23 = v40;
        }
        ++v22;
      }
      while ( v22 < v24 );
    }
    v31 = v20 + 144;
    sub_921530(v31, v2[1], *v2);
    v42 = sub_921410(v31);
    v32 = v39;
    sub_9281D0(*(_DWORD *)(v39 + 20) + *(_DWORD *)(*(_DWORD *)(v39 + 20) + 8), v2[1], *v2, v42);
    sub_928540(v32, v42);
    sub_9242D0(v2);
    return 1;
  }
  else
  {
    if ( v2 )
      sub_9242D0(v2);
    return 0;
  }
}
