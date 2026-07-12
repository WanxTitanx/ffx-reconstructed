// Function: sub_9A4820
// Address: 0x9a4820
int __thiscall sub_9A4820(float *this, float *src)
{
  int n2; // edx
  double v3; // st7
  int n2_1; // ecx
  long double v5; // st7
  double v6; // st7
  int n3; // eax
  float v8; // [esp-50h] [ebp-5Ch]
  float v9; // [esp-50h] [ebp-5Ch]
  float v10; // [esp-50h] [ebp-5Ch]
  float v11; // [esp-50h] [ebp-5Ch]
  float v12; // [esp-4Ch] [ebp-58h]
  float v13; // [esp-4Ch] [ebp-58h]
  float v14; // [esp-4Ch] [ebp-58h]
  float v15; // [esp-4Ch] [ebp-58h]
  float v16; // [esp-48h] [ebp-54h]
  float v17; // [esp-48h] [ebp-54h]
  float v18; // [esp-48h] [ebp-54h]
  float v19; // [esp-48h] [ebp-54h]
  float v20; // [esp-40h] [ebp-4Ch]
  float v21; // [esp-40h] [ebp-4Ch]
  float v22; // [esp-40h] [ebp-4Ch]
  float v23; // [esp-40h] [ebp-4Ch]
  float v24; // [esp-3Ch] [ebp-48h]
  float v25; // [esp-3Ch] [ebp-48h]
  float v26; // [esp-3Ch] [ebp-48h]
  float v27; // [esp-3Ch] [ebp-48h]
  float v28; // [esp-38h] [ebp-44h]
  float v29; // [esp-38h] [ebp-44h]
  float v30; // [esp-38h] [ebp-44h]
  float v31; // [esp-38h] [ebp-44h]
  float v32; // [esp-30h] [ebp-3Ch]
  float v33; // [esp-30h] [ebp-3Ch]
  float v34; // [esp-30h] [ebp-3Ch]
  float v35; // [esp-30h] [ebp-3Ch]
  float v36; // [esp-2Ch] [ebp-38h]
  float v37; // [esp-2Ch] [ebp-38h]
  float v38; // [esp-2Ch] [ebp-38h]
  float v39; // [esp-2Ch] [ebp-38h]
  float v40; // [esp-28h] [ebp-34h]
  float v41; // [esp-28h] [ebp-34h]
  float v42; // [esp-28h] [ebp-34h]
  float v43; // [esp-28h] [ebp-34h]
  float v44; // [esp-14h] [ebp-20h]
  float v45; // [esp-10h] [ebp-1Ch]
  float v46; // [esp-10h] [ebp-1Ch]
  float v47; // [esp-Ch] [ebp-18h]
  float v48; // [esp-Ch] [ebp-18h]
  float v49; // [esp-8h] [ebp-14h]
  float v50; // [esp-8h] [ebp-14h]
  float v51; // [esp-8h] [ebp-14h]
  float v52; // [esp-8h] [ebp-14h]
  float v53; // [esp-8h] [ebp-14h]
  float v54; // [esp-4h] [ebp-10h]
  float v55; // [esp-4h] [ebp-10h]

  n2 = -1;
  v49 = *(this + 24);
  v3 = src[20];
  if ( v3 > v49 )
  {
    v3 = v49;
    n2 = 0;
  }
  v50 = *(this + 96);
  if ( v3 > v50 )
  {
    v3 = v50;
    n2 = 1;
  }
  v51 = *(this + 168);
  if ( v3 > v51 )
  {
    v3 = v51;
    n2 = 2;
  }
  if ( v3 > *(this + 240) )
    n2 = 3;
  v52 = 0.0;
  v54 = 0.0;
  v47 = 0.0;
  v45 = 0.0;
  if ( n2 )
  {
    v20 = *src - *(this + 76);
    v24 = src[1] - *(this + 77);
    v28 = src[2] - *(this + 78);
    v32 = *(this + 220) - *(this + 148);
    v36 = *(this + 221) - *(this + 149);
    v40 = *(this + 222) - *(this + 150);
    v8 = v40 * v24 - v36 * v28;
    v12 = v28 * v32 - v40 * v20;
    v16 = v20 * v36 - v32 * v24;
    v52 = v8 * v8 + v12 * v12 + v16 * v16;
  }
  if ( n2 != 1 )
  {
    v21 = *src - *(this + 4);
    v25 = src[1] - *(this + 5);
    v29 = src[2] - *(this + 6);
    v9 = *(this + 220) - *(this + 148);
    v13 = *(this + 221) - *(this + 149);
    v17 = *(this + 222) - *(this + 150);
    v33 = v17 * v25 - v13 * v29;
    v37 = v29 * v9 - v17 * v21;
    v41 = v21 * v13 - v9 * v25;
    v54 = v33 * v33 + v37 * v37 + v41 * v41;
  }
  if ( n2 != 2 )
  {
    v22 = *src - *(this + 4);
    v26 = src[1] - *(this + 5);
    v30 = src[2] - *(this + 6);
    v10 = *(this + 220) - *(this + 76);
    v14 = *(this + 221) - *(this + 77);
    v18 = *(this + 222) - *(this + 78);
    v34 = v18 * v26 - v14 * v30;
    v38 = v30 * v10 - v18 * v22;
    v42 = v22 * v14 - v10 * v26;
    v47 = v34 * v34 + v38 * v38 + v42 * v42;
  }
  if ( n2 != 3 )
  {
    v23 = *src - *(this + 4);
    v27 = src[1] - *(this + 5);
    v31 = src[2] - *(this + 6);
    v11 = *(this + 148) - *(this + 76);
    v15 = *(this + 149) - *(this + 77);
    v19 = *(this + 150) - *(this + 78);
    v35 = v19 * v27 - v15 * v31;
    v39 = v31 * v11 - v19 * v23;
    v43 = v23 * v15 - v11 * v27;
    v45 = v35 * v35 + v39 * v39 + v43 * v43;
  }
  n2_1 = -1;
  v53 = fabs(v52);
  v5 = v54;
  v55 = -9.9999998e17;
  v44 = fabs(v5);
  v48 = fabs(v47);
  v46 = fabs(v45);
  if ( v53 > -9.999999843067494e17 )
  {
    n2_1 = 0;
    v55 = v53;
  }
  v6 = v55;
  if ( v44 > (double)v55 )
  {
    v6 = v44;
    n2_1 = 1;
  }
  if ( v48 > v6 )
  {
    v6 = v48;
    n2_1 = 2;
  }
  n3 = 3;
  if ( v46 <= v6 )
    return n2_1;
  return n3;
}
