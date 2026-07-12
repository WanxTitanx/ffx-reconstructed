// Function: sub_A753F0
// Address: 0xa753f0
// Size: 0x246
// Prototype: 

int __cdecl sub_A753F0(_DWORD *a1, float *a2)
{
  float *v3; // esi
  int n512; // ecx
  double v5; // st7
  float *v6; // eax
  double v7; // st7
  double v8; // st5
  double n512_3; // st1
  int n416; // ecx
  double n416_3; // st1
  int n511; // ecx
  double n511_3; // st1
  int n415; // ecx
  double v15; // st4
  double v16; // st7
  float *v17; // eax
  double n415_3; // st3
  int n1856; // edi
  double v20; // st5
  double v21; // st6
  double v22; // st4
  double v23; // st3
  double v24; // st2
  int result; // eax
  float v26; // [esp+0h] [ebp-14h]
  float v27; // [esp+Ch] [ebp-8h]
  float v28; // [esp+Ch] [ebp-8h]
  float v29; // [esp+Ch] [ebp-8h]
  float v30; // [esp+Ch] [ebp-8h]
  float v31; // [esp+Ch] [ebp-8h]
  float v32; // [esp+10h] [ebp-4h]
  int n512_1; // [esp+1Ch] [ebp+8h]
  float n512_2; // [esp+1Ch] [ebp+8h]
  int n416_1; // [esp+1Ch] [ebp+8h]
  float n416_2; // [esp+1Ch] [ebp+8h]
  int n511_1; // [esp+1Ch] [ebp+8h]
  float n511_2; // [esp+1Ch] [ebp+8h]
  int n415_1; // [esp+1Ch] [ebp+8h]
  float n415_2; // [esp+1Ch] [ebp+8h]
  float v41; // [esp+1Ch] [ebp+8h]
  float v42; // [esp+20h] [ebp+Ch]

  *a1 = 0;
  v3 = (float *)(a1 + 8);
  n512 = 0;
  n512_1 = 0;
  v42 = *a2 + 2048.0;
  v5 = a2[1] + 2048.0;
  v6 = v3;
  v32 = v5;
  v7 = v42 - 256.0;
  v8 = v32 - 208.0;
  do
  {
    ++n512;
    v6 += 22;
    n512_2 = (float)n512_1;
    n512_3 = n512_2;
    n512_1 = n512;
    *(v6 - 18) = n512_3 + v7;
    v27 = v8;
    *(v6 - 17) = v27;
    *(v6 - 16) = 0.0;
    *(v6 - 8) = n512_3 * 0.001953125;
    *(v6 - 7) = 0.0;
  }
  while ( n512 < 512 );
  n416 = 0;
  n416_1 = 0;
  do
  {
    v28 = v42 + 256.0;
    v6[4] = v28;
    ++n416;
    v6 += 22;
    n416_2 = (float)n416_1;
    n416_3 = n416_2;
    n416_1 = n416;
    *(v6 - 17) = n416_3 + v8;
    *(v6 - 16) = 0.0;
    *(v6 - 8) = 1.0;
    *(v6 - 7) = n416_3 * 0.001953125;
  }
  while ( n416 < 416 );
  n511 = 511;
  n511_1 = 511;
  do
  {
    v6 += 22;
    --n511;
    n511_2 = (float)n511_1;
    n511_3 = n511_2;
    n511_1 = n511;
    *(v6 - 18) = n511_3 + v7;
    v29 = v32 + 208.0;
    *(v6 - 17) = v29;
    *(v6 - 16) = 0.0;
    *(v6 - 8) = n511_3 * 0.001953125;
    *(v6 - 7) = 0.8125;
  }
  while ( n511 >= 0 );
  n415 = 415;
  n415_1 = 415;
  v15 = v7;
  v16 = 0.0;
  v17 = v6 + 5;
  do
  {
    v30 = v15;
    *(v17 - 1) = v30;
    v17 += 22;
    --n415;
    n415_2 = (float)n415_1;
    n415_3 = n415_2;
    n415_1 = n415;
    *(v17 - 22) = n415_3 + v8;
    *(v17 - 21) = 0.0;
    v17[9] = 0.0;
    v17[10] = n415_3 * 0.001953125;
  }
  while ( n415 >= 0 );
  n1856 = 1856;
  v20 = v42;
  v41 = (v42 - 1792.0) * 0.001953125;
  v21 = v32;
  v31 = 0.001953125 * (v32 - 1840.0);
  v22 = 0.001;
  v23 = v41;
  v24 = v31;
  while ( 1 )
  {
    *v3 = v20;
    v3[8] = -1.1801041e-38;
    v3[9] = -1.1801041e-38;
    v3[1] = v21;
    v3[2] = v16;
    v3[12] = v23;
    v3[13] = v24;
    v3[16] = v16;
    v3[17] = v16;
    v3[18] = v16;
    v26 = v22;
    result = sub_7E6690(v26);
    v3 += 22;
    *(v3 - 3) = 0.0099999998;
    v16 = 0.0;
    *(v3 - 2) = 0.0;
    *(v3 - 1) = 0.0;
    if ( !--n1856 )
      break;
    v21 = v32;
    v20 = v42;
    v23 = v41;
    v24 = v31;
    v22 = 0.001;
  }
  return result;
}

