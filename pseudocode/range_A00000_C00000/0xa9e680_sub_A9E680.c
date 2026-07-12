// Function: sub_A9E680
// Address: 0xa9e680
// Size: 0x235
// Prototype: 

int __fastcall sub_A9E680(float *buf, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ecx
  int v7; // esi
  int v8; // kr00_4
  int v9; // kr10_4
  int v10; // ebx
  float *buf_1; // esi
  int v12; // edx
  int v13; // ecx
  int v14; // edi
  unsigned int v15; // edi
  int v16; // eax
  int v17; // edx
  float v18; // xmm0_4
  float *v19; // eax
  float v20; // xmm0_4
  int v21; // edi
  float *v22; // edx
  unsigned int v23; // edi
  float *v24; // ecx
  float v25; // xmm0_4
  float *v26; // eax
  float v27; // xmm0_4
  int result; // eax
  int v29; // [esp+Ch] [ebp-10h]
  int v30; // [esp+10h] [ebp-Ch]
  int v31; // [esp+14h] [ebp-8h]
  int v33; // [esp+24h] [ebp+8h]
  int v34; // [esp+28h] [ebp+Ch]
  int v35; // [esp+2Ch] [ebp+10h]
  int v36; // [esp+2Ch] [ebp+10h]
  int v37; // [esp+2Ch] [ebp+10h]
  int v38; // [esp+30h] [ebp+14h]

  v6 = 0;
  if ( a5 )
    v6 = a4;
  v7 = 0;
  if ( a5 )
    v7 = a6;
  v31 = (int)*(&off_B899B8 + *(_DWORD *)(a2 + 4 * v6));
  v30 = (int)*(&off_B899B8 + *(_DWORD *)(a2 + 4 * v7));
  v29 = *(_DWORD *)(a3 + 4 * a5);
  v8 = *(_DWORD *)(a3 + 4 * v6);
  v35 = v29 / 4 - v8 / 4;
  v38 = v35 + v8 / 2;
  v9 = *(_DWORD *)(a3 + 4 * v7);
  v10 = v29 / 4 + v29 / 2 - v9 / 4;
  buf_1 = buf;
  v12 = v9 / 2 + v10;
  v33 = v9 / 2;
  v13 = 0;
  v34 = v12;
  if ( v35 > 0 )
  {
    memset(buf, 0, 4 * v35);
    v13 = v29 / 4 - v8 / 4;
  }
  v14 = v35 + v8 / 2;
  v36 = 0;
  if ( v13 < v38 )
  {
    if ( v38 - v13 >= 4 )
    {
      v15 = ((unsigned int)(v38 - v13 - 4) >> 2) + 1;
      v16 = (int)&buf[v13 + 2];
      v17 = v31 + 8;
      v36 = 4 * v15;
      v13 += 4 * v15;
      buf_1 = buf;
      do
      {
        v18 = *(float *)(v17 - 8) * *(float *)(v16 - 8);
        v17 += 16;
        v16 += 16;
        *(float *)(v16 - 24) = v18;
        *(float *)(v16 - 20) = *(float *)(v17 - 20) * *(float *)(v16 - 20);
        *(float *)(v16 - 16) = *(float *)(v16 - 16) * *(float *)(v17 - 16);
        *(float *)(v16 - 12) = *(float *)(v17 - 12) * *(float *)(v16 - 12);
        --v15;
      }
      while ( v15 );
      v14 = v38;
      v12 = v9 / 2 + v10;
    }
    if ( v13 < v14 )
    {
      v19 = (float *)(v31 + 4 * v36);
      buf_1 = buf;
      do
      {
        v20 = *v19++ * buf[v13++];
        buf[v13 - 1] = v20;
      }
      while ( v13 < v14 );
    }
  }
  v21 = v33 - 1;
  if ( v10 < v12 )
  {
    if ( v12 - v10 >= 4 )
    {
      v22 = (float *)(v30 - 8 + 4 * v21);
      v23 = ((unsigned int)(v9 / 2 - 4) >> 2) + 1;
      v24 = &buf_1[v10 + 2];
      v10 += 4 * v23;
      v37 = v33 - 1 - 4 * v23;
      do
      {
        v25 = v22[2] * *(v24 - 2);
        v22 -= 4;
        v24 += 4;
        *(v24 - 6) = v25;
        *(v24 - 5) = v22[5] * *(v24 - 5);
        *(v24 - 4) = v22[4] * *(v24 - 4);
        *(v24 - 3) = v22[3] * *(v24 - 3);
        --v23;
      }
      while ( v23 );
      v12 = v34;
      v21 = v37;
    }
    if ( v10 < v12 )
    {
      v26 = (float *)(v30 + 4 * v21);
      do
      {
        v27 = *v26-- * buf_1[v10++];
        buf_1[v10 - 1] = v27;
      }
      while ( v10 < v12 );
    }
  }
  result = v29;
  if ( v10 < v29 )
  {
    memset(&buf_1[v10], 0, 4 * (v29 - v10));
    return 0;
  }
  return result;
}

