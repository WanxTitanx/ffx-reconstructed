// Function: sub_9CBF80
// Address: 0x9cbf80
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_9CBF80@<eax>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3)
{
  double v4; // st5
  long double v5; // st6
  float v6; // xmm0_4
  float v7; // xmm1_4
  double v8; // st7
  double v9; // st7
  double v10; // st6
  double v11; // st7
  double v12; // st7
  double v13; // st5
  double v14; // st4
  double v15; // st3
  double v16; // st6
  int result; // eax
  float v18[4]; // [esp-60h] [ebp-6Ch] BYREF
  float v19; // [esp-50h] [ebp-5Ch] BYREF
  float v20; // [esp-4Ch] [ebp-58h]
  float v21; // [esp-48h] [ebp-54h]
  float v22; // [esp-44h] [ebp-50h]
  float v23; // [esp-40h] [ebp-4Ch] BYREF
  float v24; // [esp-3Ch] [ebp-48h]
  float v25; // [esp-38h] [ebp-44h]
  float v26; // [esp-34h] [ebp-40h]
  float v27; // [esp-30h] [ebp-3Ch] BYREF
  float v28; // [esp-2Ch] [ebp-38h]
  float v29; // [esp-28h] [ebp-34h]
  float v30; // [esp-24h] [ebp-30h]
  float v31; // [esp-14h] [ebp-20h]
  float v32; // [esp-10h] [ebp-1Ch] BYREF
  float v33; // [esp-Ch] [ebp-18h] BYREF
  float v34; // [esp-8h] [ebp-14h]
  float v35; // [esp-4h] [ebp-10h]
  int v36; // [esp+0h] [ebp-Ch]
  void *v37; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v36 = a2;
  v37 = retaddr;
  *(_DWORD *)(a1 + 608) = *a3;
  *(_DWORD *)(a1 + 612) = a3[1];
  *(_DWORD *)(a1 + 616) = a3[2];
  *(_DWORD *)(a1 + 620) = a3[3];
  v33 = *(float *)(a1 + 612);
  v32 = *(float *)(a1 + 620);
  v35 = *(float *)(a1 + 616);
  v23 = v33 * flt_C64B48 + v32 * flt_C64B40 - v35 * flt_C64B44;
  v34 = *(float *)(a1 + 608);
  v31 = -v34;
  v19 = -v34;
  v20 = -v33;
  v21 = -v35;
  v22 = v32;
  v24 = v35 * flt_C64B40 + v32 * flt_C64B44 - v34 * flt_C64B48;
  v25 = v32 * flt_C64B48 + v34 * flt_C64B44 - v33 * flt_C64B40;
  v26 = flt_C64B40 * (float)-v34 - flt_C64B44 * v33 - flt_C64B48 * v35;
  sub_9C5A60(&v19);
  v4 = flt_C64B44;
  v5 = flt_C64B48;
  v19 = v25 * flt_C64B44 - v24 * flt_C64B48;
  v20 = v23 * flt_C64B48 - v25 * flt_C64B40;
  v21 = v24 * flt_C64B40 - v23 * flt_C64B44;
  v31 = v25 * flt_C64B48 + v23 * flt_C64B40 + v24 * flt_C64B44;
  if ( v31 >= -0.9999998807907104 )
  {
    v31 = v31 + 1.0 + v31 + 1.0;
    v31 = sqrt(v31);
    v8 = v31;
    v31 = 1.0 / v31;
    v27 = v19 * v31;
    v28 = v20 * v31;
    v29 = v31 * v21;
    v30 = v8 * 0.5;
  }
  else
  {
    v31 = fabs(v5);
    if ( v31 <= 0.70710677 )
    {
      v31 = v4 * v4 + flt_C64B40 * flt_C64B40;
      v31 = sqrt(v31);
      v7 = 0.0;
      v31 = 1.0 / v31;
      v23 = -flt_C64B44 * v31;
      v6 = v23;
      v24 = v31 * flt_C64B40;
    }
    else
    {
      v31 = v4 * v4 + v5 * v5;
      v31 = sqrt(v31);
      v6 = 0.0;
      v31 = 1.0 / v31;
      v24 = -flt_C64B48 * v31;
      v25 = v31 * flt_C64B44;
      v7 = v25;
    }
    v27 = v6;
    v28 = v24;
    v29 = v7;
    v30 = 0.0;
  }
  sub_982BB0(&v27);
  v19 = -v27;
  v20 = -v28;
  v21 = -v29;
  v23 = v19 * v32 + v30 * v34 + v20 * v35 - v21 * v33;
  v24 = v20 * v32 + v30 * v33 + v21 * v34 - v19 * v35;
  v25 = v30 * v35 + v21 * v32 + v19 * v33 - v20 * v34;
  v26 = v32 * v30 - v19 * v34 - v20 * v33 - v21 * v35;
  sub_982BB0(&v23);
  v9 = 0.05000000074505806;
  if ( *(float *)(a1 + 480) >= 0.05000000074505806 && *(float *)(a1 + 484) >= 0.05000000074505806 )
  {
    sub_9C9C30((float *)a1, (int)&v27, &v33, v18, &v32);
    v31 = fabs(v33);
    if ( v31 > 0.00000011920929 )
    {
      if ( v33 <= (double)v32 )
      {
        v10 = -v32;
        if ( v10 > v33 )
          v33 = v10;
      }
      else
      {
        v33 = v32;
      }
      sub_997300(&v19, v18, &v33);
      v27 = v19;
      v28 = v20;
      v29 = v21;
      v30 = v22;
    }
    v9 = 0.05000000074505806;
  }
  v32 = *(float *)(a1 + 488);
  if ( v32 >= v9 )
  {
    sub_9C9DF0(&v23, &v33, (int)v18);
    v31 = fabs(v33);
    if ( v31 > 0.00000011920929 )
    {
      v11 = v32;
      if ( v33 > (double)v32 || (v11 = -v32, v11 > v33) )
        v33 = v11;
      sub_997300(&v19, v18, &v33);
      v23 = v19;
      v24 = v20;
      v25 = v21;
      v26 = v22;
    }
  }
  v12 = v23;
  v13 = v30;
  v14 = v26;
  v15 = v25;
  v16 = v24;
  v23 = v23 * v30 + v26 * v27 + v25 * v28 - v24 * v29;
  *(float *)(a1 + 608) = v23;
  v24 = v16 * v13 + v14 * v28 + v12 * v29 - v15 * v27;
  *(float *)(a1 + 612) = v24;
  v25 = v15 * v13 + v14 * v29 + v16 * v27 - v12 * v28;
  *(float *)(a1 + 616) = v25;
  v26 = v13 * v14 - v12 * v27 - v16 * v28 - v15 * v29;
  result = LODWORD(v26);
  *(float *)(a1 + 620) = v26;
  return result;
}
