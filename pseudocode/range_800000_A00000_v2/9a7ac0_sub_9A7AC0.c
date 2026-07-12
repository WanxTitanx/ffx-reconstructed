// Function: sub_9A7AC0
// Address: 0x9a7ac0
// bad sp value at call has been detected, the output may be wrong!
int __usercall sub_9A7AC0@<eax>(int a1@<ebp>, float *a2, float *a3, float *a4, float a5, int a6)
{
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st6
  float v12; // [esp-40h] [ebp-4Ch] BYREF
  float v13; // [esp-3Ch] [ebp-48h]
  float v14; // [esp-38h] [ebp-44h]
  int v15; // [esp-34h] [ebp-40h]
  float v16; // [esp-30h] [ebp-3Ch] BYREF
  float v17; // [esp-2Ch] [ebp-38h]
  float v18; // [esp-28h] [ebp-34h]
  float v19; // [esp-14h] [ebp-20h]
  float v20; // [esp-10h] [ebp-1Ch]
  float v21; // [esp-Ch] [ebp-18h]
  float v22; // [esp-8h] [ebp-14h]
  float v23; // [esp-4h] [ebp-10h]
  int v24; // [esp+0h] [ebp-Ch]
  void *v25; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v24 = a1;
  v25 = retaddr;
  v6 = *a3;
  v15 = 0;
  v16 = v6 * a5;
  v17 = a3[1] * a5;
  v18 = a5 * a3[2];
  v12 = a2[12] + v16;
  v13 = a2[13] + v17;
  v7 = a2[14];
  *(float *)(a6 + 48) = v12;
  v8 = v7 + v18;
  *(float *)(a6 + 52) = v13;
  v14 = v8;
  *(float *)(a6 + 56) = v14;
  *(_DWORD *)(a6 + 60) = v15;
  v21 = a4[1];
  v22 = *a4;
  v20 = a4[2];
  v23 = v22 * v22 + v21 * v21 + v20 * v20;
  v23 = sqrt(v23);
  v9 = v23;
  if ( v23 * a5 <= 0.7853981852531433 )
  {
    v10 = a5;
  }
  else
  {
    v23 = 0.7853981852531433 / a5;
    v10 = a5;
    v9 = v23;
  }
  if ( v23 >= 0.001 )
  {
    v19 = v9 * 0.5 * v10;
    v19 = sin(v19);
    v19 = v19 / v23;
    v12 = v19 * v22;
    v13 = v19 * v21;
    v14 = v19 * v20;
  }
  else
  {
    v23 = v10 * 0.5 - v10 * v10 * v10 * 0.02083333395421505 * v9 * v9;
    v12 = v23 * v22;
    v13 = v23 * v21;
    v14 = v23 * v20;
  }
  sub_5FE290(&v12);
  sub_982BB0(&v16);
  return sub_603C50(&v16);
}
