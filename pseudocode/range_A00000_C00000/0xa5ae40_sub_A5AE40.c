// Function: sub_A5AE40
// Address: 0xa5ae40
// Size: 0x1f0
// Prototype: int(void)

int sub_A5AE40()
{
  int v0; // edx
  int v1; // eax
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // kr04_4
  int result; // eax
  int v7; // [esp+Ch] [ebp-3Ch]
  int v8; // [esp+10h] [ebp-38h]
  int v9; // [esp+14h] [ebp-34h]
  float v10; // [esp+18h] [ebp-30h]
  float v11; // [esp+1Ch] [ebp-2Ch]
  int *v12; // [esp+20h] [ebp-28h]
  int v13; // [esp+24h] [ebp-24h]
  int v14; // [esp+28h] [ebp-20h]
  float v15; // [esp+2Ch] [ebp-1Ch]
  int v16; // [esp+30h] [ebp-18h]
  float v17; // [esp+30h] [ebp-18h]
  int v18; // [esp+34h] [ebp-14h]
  int v19; // [esp+38h] [ebp-10h]

  v0 = dword_2305834[0];
  v1 = *(__int16 *)dword_2305834[0];
  *(float *)(dword_2305834[0] + 71176) = 0.0;
  v2 = dword_2305834[0];
  v9 = v0;
  *(float *)(dword_2305834[0] + 71172) = 0.0;
  v3 = dword_2305834[0];
  v8 = v2;
  v7 = dword_2305834[0];
  *(float *)(dword_2305834[0] + 71168) = 0.0;
  v13 = dword_2305834[0];
  *(float *)(dword_2305834[0] + 71164) = 0.0;
  v12 = (int *)(dword_2305834[0] + 8);
  v4 = *(_DWORD *)(dword_2305834[0] + 8);
  v19 = *(_DWORD *)(dword_2305834[0] + 12);
  HIWORD(v18) = HIWORD(v4);
  if ( v1 )
  {
    do
    {
      v14 = v1 - 1;
      v16 = *(__int16 *)(dword_2305834[0] + 4 * HIWORD(v19) + 63496) / 2;
      v5 = *(__int16 *)(dword_2305834[0] + 4 * HIWORD(v19) + 63498);
      v11 = (float)((__int16)v4 - v16);
      v15 = (float)(SHIWORD(v18) - v5 / 2);
      v10 = (float)((__int16)v4 + v16);
      v17 = (float)(SHIWORD(v18) + v5 / 2);
      if ( v11 < (double)*(float *)(v13 + 71164) )
        *(float *)(v13 + 71164) = v11;
      v3 = v7;
      if ( v15 < (double)*(float *)(v7 + 71168) )
        *(float *)(v7 + 71168) = v15;
      v2 = v8;
      if ( v10 > (double)*(float *)(v8 + 71172) )
        *(float *)(v8 + 71172) = v10;
      v0 = v9;
      if ( v17 > (double)*(float *)(v9 + 71176) )
        *(float *)(v9 + 71176) = v17;
      v12 += 4;
      v4 = *v12;
      v19 = v12[1];
      --v1;
      v18 = *v12;
    }
    while ( v14 );
  }
  *(float *)(dword_2305834[0] + 71180) = *(float *)(v13 + 71164);
  *(float *)(dword_2305834[0] + 71188) = *(float *)(v2 + 71172);
  *(float *)(dword_2305834[0] + 71184) = *(float *)(v3 + 71168);
  result = dword_2305834[0];
  *(float *)(dword_2305834[0] + 71192) = *(float *)(v0 + 71176);
  return result;
}

