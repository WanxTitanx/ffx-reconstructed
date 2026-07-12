// Function: sub_9BD190
// Address: 0x9bd190
int __cdecl sub_9BD190(int a1, int a2)
{
  int result; // eax
  double v3; // st7
  double v4; // st5
  double v5; // st6
  double v6; // st4
  double v7; // st3
  double v8; // st2
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st6
  double v13; // st6
  double v14; // st5
  float v15; // [esp-30h] [ebp-3Ch]
  float v16; // [esp-30h] [ebp-3Ch]
  float v17; // [esp-30h] [ebp-3Ch]
  float v18; // [esp-2Ch] [ebp-38h]
  float v19; // [esp-2Ch] [ebp-38h]
  float v20; // [esp-2Ch] [ebp-38h]
  float v21; // [esp-28h] [ebp-34h]
  float v22; // [esp-28h] [ebp-34h]
  float v23; // [esp-28h] [ebp-34h]
  float v24; // [esp-8h] [ebp-14h]
  float v25; // [esp-4h] [ebp-10h]

  result = a1;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 192) )
    {
      v25 = *(float *)(a1 + 32);
      v24 = *(float *)(a1 + 48);
      v3 = *(float *)(a1 + 16);
      v4 = *(float *)a2;
      v5 = *(float *)(a2 + 4);
      v6 = *(float *)(a2 + 8);
      v15 = v24 * v6 + v25 * v5 + v3 * v4;
      v7 = *(float *)(a1 + 20);
      v18 = *(float *)(a1 + 36) * v5 + v7 * v4 + *(float *)(a1 + 52) * v6;
      v8 = v5 * *(float *)(a1 + 40);
      v9 = *(float *)(a1 + 24);
      v21 = v6 * *(float *)(a1 + 56) + v4 * v9 + v8;
      v16 = *(float *)(a1 + 176) * v15;
      v19 = *(float *)(a1 + 180) * v18;
      v22 = *(float *)(a1 + 184) * v21;
      v10 = v16;
      v11 = v9 * v22 + v3 * v16 + v7 * v19;
      v12 = v19;
      v17 = v11;
      v20 = *(float *)(a1 + 36) * v19 + v25 * v10 + *(float *)(a1 + 40) * v22;
      v13 = v12 * *(float *)(a1 + 52) + v10 * v24;
      v14 = *(float *)(a1 + 56);
      *(float *)a2 = v17;
      *(float *)(a2 + 4) = v20;
      v23 = v22 * v14 + v13;
      *(float *)(a2 + 8) = v23;
      *(_DWORD *)(a2 + 12) = 0;
      return 0;
    }
  }
  return result;
}
