// Function: sub_9ACED0
// Address: 0x9aced0
// bad sp value at call has been detected, the output may be wrong!
char __userpurge sub_9ACED0@<al>(
        float a1@<ecx>,
        int a2@<ebp>,
        int a3,
        float *a4,
        int a5,
        float *a6,
        _DWORD *a7,
        float a8)
{
  int v9; // eax
  float *v10; // ecx
  double v11; // st7
  float *v12; // esi
  double v13; // st6
  double v14; // st7
  double v15; // st5
  double v16; // st4
  float v18; // edi
  double v19; // st7
  float v20; // ecx
  float v21; // edx
  int v22; // ecx
  int v23; // esi
  int (__thiscall *v24)(int); // eax
  double v25; // st7
  double v26; // st7
  float v27; // ecx
  double v28; // st7
  double v29; // st7
  long double v30; // st7
  float v31; // ecx
  float v32; // [esp-70h] [ebp-7Ch] BYREF
  float v33; // [esp-6Ch] [ebp-78h]
  float v34; // [esp-68h] [ebp-74h]
  float v35; // [esp-64h] [ebp-70h]
  float v36; // [esp-60h] [ebp-6Ch] BYREF
  float v37; // [esp-5Ch] [ebp-68h]
  float v38; // [esp-58h] [ebp-64h]
  int v39; // [esp-54h] [ebp-60h]
  float v40; // [esp-50h] [ebp-5Ch]
  float v41; // [esp-4Ch] [ebp-58h]
  float v42; // [esp-48h] [ebp-54h]
  float v43; // [esp-44h] [ebp-50h]
  float v44; // [esp-40h] [ebp-4Ch] BYREF
  float v45; // [esp-3Ch] [ebp-48h]
  double v46; // [esp-38h] [ebp-44h]
  float v47; // [esp-2Ch] [ebp-38h]
  float v48; // [esp-28h] [ebp-34h]
  float *v49; // [esp-24h] [ebp-30h]
  float v50; // [esp-20h] [ebp-2Ch]
  float v51; // [esp-1Ch] [ebp-28h]
  float v52; // [esp-18h] [ebp-24h]
  float v53; // [esp-14h] [ebp-20h]
  float v54; // [esp-10h] [ebp-1Ch]
  float v55; // [esp-8h] [ebp-14h]
  char v56; // [esp-1h] [ebp-Dh]
  int v57; // [esp+0h] [ebp-Ch]
  void *v58; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v57 = a2;
  v58 = retaddr;
  v50 = a1;
  v9 = *(_DWORD *)(LODWORD(a1) + 4);
  v10 = *(float **)(LODWORD(a1) + 8);
  v11 = *(float *)(v9 + 32) * *(float *)(v9 + 16);
  v49 = v10 + 16;
  v43 = 0.0;
  v52 = v11;
  v53 = v10[16];
  v44 = v10[24] - v53;
  v54 = v10[17];
  v45 = v10[25] - v54;
  v55 = v10[18];
  *(float *)&v46 = v10[26] - v55;
  v36 = v10[20] - v53;
  v37 = v10[21] - v54;
  v38 = v10[22] - v55;
  v40 = v37 * *(float *)&v46 - v38 * v45;
  v41 = v38 * v44 - *(float *)&v46 * v36;
  v42 = v45 * v36 - v37 * v44;
  v48 = v41 * v41 + v40 * v40 + v42 * v42;
  v48 = sqrt(v48);
  v12 = (float *)a3;
  v48 = 1.0 / v48;
  v40 = v40 * v48;
  v41 = v41 * v48;
  v42 = v48 * v42;
  v51 = *(float *)a3;
  v36 = v51 - v53;
  v53 = *(float *)(a3 + 4);
  v37 = v53 - v54;
  v54 = *(float *)(a3 + 8);
  v38 = v54 - v55;
  v13 = v41;
  v14 = v40;
  v15 = v42;
  v55 = v38 * v42 + v36 * v40 + v37 * v41;
  v16 = v55;
  if ( v55 < 0.0 )
  {
    v55 = v16 * -1.0;
    v40 = v14 * -1.0;
    v41 = v13 * -1.0;
    v42 = -1.0 * v15;
    v16 = v55;
    v14 = v40;
    v13 = v41;
    v15 = v42;
  }
  v46 = v52 + a8;
  if ( v52 <= v16 )
  {
    v48 = 0.0 * v15 + v14 * 0.0 + v13 * 0.0;
    if ( v48 >= 0.0 )
      return 0;
  }
  v56 = 0;
  if ( v46 <= v16 )
    return 0;
  v36 = *(float *)a3;
  v37 = *(float *)(a3 + 4);
  v38 = *(float *)(a3 + 8);
  v39 = *(_DWORD *)(a3 + 12);
  v32 = v40;
  v33 = v41;
  v34 = v42;
  v35 = v43;
  if ( sub_9ADC30(v49, &v32, &v36) )
  {
    HIDWORD(v46) = 0;
    v36 = v40 * v55;
    v37 = v41 * v55;
    v38 = v55 * v42;
    v44 = v51 - v36;
    v18 = v44;
    v40 = v44;
    v19 = v53 - v37;
    v53 = 0.0;
    v45 = v19;
    v20 = v45;
    v55 = v45;
    v41 = v45;
    *(float *)&v46 = v54 - v38;
    v21 = *(float *)&v46;
    v54 = *(float *)&v46;
    v42 = *(float *)&v46;
  }
  else
  {
    v22 = *(_DWORD *)(LODWORD(a1) + 8);
    v23 = 0;
    v24 = *(int (__thiscall **)(int))(*(_DWORD *)v22 + 84);
    v48 = v46 * v46;
    if ( v24(v22) <= 0 )
      return 0;
    v18 = v40;
    v54 = v42;
    v53 = v43;
    v55 = v41;
    do
    {
      (*(void (__thiscall **)(_DWORD, int, float *, float *))(**(_DWORD **)(LODWORD(v50) + 8) + 88))(
        *(_DWORD *)(LODWORD(v50) + 8),
        v23,
        &v44,
        &v36);
      v25 = sub_9ACCF0(&v44, &v36, (float *)a3, (int)&v32);
      if ( v48 > v25 )
      {
        v18 = v32;
        v55 = v33;
        v41 = v33;
        v54 = v34;
        v42 = v34;
        v56 = 1;
        v53 = v35;
      }
      ++v23;
    }
    while ( v23 < (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(v50) + 8) + 84))(*(_DWORD *)(LODWORD(v50) + 8)) );
    v40 = v18;
    if ( !v56 )
      return 0;
    v20 = v55;
    v21 = v54;
    v12 = (float *)a3;
  }
  v26 = *v12;
  HIDWORD(v46) = 0;
  v44 = v26 - v40;
  v45 = v12[1] - v41;
  *(float *)&v46 = v12[2] - v42;
  v48 = v44 * v44 + v45 * v45 + *(float *)&v46 * *(float *)&v46;
  if ( (v52 - 0.0) * (v52 - 0.0) > v48 )
  {
    *(float *)a5 = v44;
    *(float *)(a5 + 4) = v45;
    *(double *)(a5 + 8) = v46;
    v51 = *(float *)(a5 + 4);
    v50 = *(float *)a5;
    v49 = *(float **)(a5 + 8);
    v47 = v50 * v50 + v51 * v51 + *(float *)&v49 * *(float *)&v49;
    v47 = sqrt(v47);
    v27 = v55;
    v47 = 1.0 / v47;
    v28 = v47;
    *(float *)a5 = v50 * v47;
    *(float *)(a5 + 4) = v51 * v28;
    *(float *)(a5 + 8) = v28 * *(float *)&v49;
    *a4 = v18;
    v29 = v52;
    a4[1] = v27;
    v46 = v29;
    v30 = v48;
    a4[2] = v54;
    a4[3] = v53;
    v47 = sqrt(v30);
    *a6 = -(v46 - v47);
    return 1;
  }
  v47 = 0.0 * *(float *)&v46 + v44 * 0.0 + v45 * 0.0;
  if ( v47 >= 0.0 )
    return 0;
  *a4 = v18;
  a4[1] = v20;
  v31 = v53;
  a4[2] = v21;
  a4[3] = v31;
  *a7 = 0;
  return 1;
}
