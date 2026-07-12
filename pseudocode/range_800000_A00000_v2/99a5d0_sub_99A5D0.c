// Function: sub_99A5D0
// Address: 0x99a5d0
// bad sp value at call has been detected, the output may be wrong!
int __userpurge sub_99A5D0@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int a5, int a6)
{
  int v7; // ecx
  int v8; // edx
  float *v9; // eax
  double v10; // st7
  double v11; // st4
  double v12; // st3
  double v13; // st6
  double v14; // st5
  int result; // eax
  char v16; // cl
  int v17; // eax
  int *v18; // ecx
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  float v25[4]; // [esp-1A0h] [ebp-1ACh] BYREF
  float v26[4]; // [esp-190h] [ebp-19Ch] BYREF
  float v27[4]; // [esp-180h] [ebp-18Ch] BYREF
  float v28[7]; // [esp-170h] [ebp-17Ch] BYREF
  float v29; // [esp-154h] [ebp-160h]
  float v30; // [esp-150h] [ebp-15Ch]
  float v31; // [esp-14Ch] [ebp-158h]
  float v32; // [esp-148h] [ebp-154h]
  float v33; // [esp-144h] [ebp-150h]
  int v34; // [esp-140h] [ebp-14Ch]
  float v35; // [esp-13Ch] [ebp-148h]
  float v36; // [esp-138h] [ebp-144h]
  float v37; // [esp-134h] [ebp-140h]
  float v38; // [esp-130h] [ebp-13Ch] BYREF
  float v39; // [esp-12Ch] [ebp-138h]
  float v40; // [esp-128h] [ebp-134h]
  int v41; // [esp-124h] [ebp-130h]
  float v42; // [esp-114h] [ebp-120h]
  float v43; // [esp-110h] [ebp-11Ch]
  float v44; // [esp-10Ch] [ebp-118h]
  float v45; // [esp-108h] [ebp-114h]
  float v46; // [esp-104h] [ebp-110h]
  _DWORD v47[16]; // [esp-100h] [ebp-10Ch] BYREF
  _DWORD v48[28]; // [esp-C0h] [ebp-CCh] BYREF
  float v49; // [esp-50h] [ebp-5Ch] BYREF
  float v50; // [esp-4Ch] [ebp-58h]
  float v51; // [esp-48h] [ebp-54h]
  int v52; // [esp-44h] [ebp-50h]
  float v53; // [esp-40h] [ebp-4Ch]
  float v54; // [esp-3Ch] [ebp-48h]
  float v55; // [esp-38h] [ebp-44h]
  int v56; // [esp-34h] [ebp-40h]
  float v57; // [esp-30h] [ebp-3Ch]
  float v58; // [esp-2Ch] [ebp-38h]
  float v59; // [esp-28h] [ebp-34h]
  int v60; // [esp-24h] [ebp-30h]
  float v61; // [esp-20h] [ebp-2Ch]
  float v62; // [esp-1Ch] [ebp-28h]
  float v63; // [esp-18h] [ebp-24h]
  int v64; // [esp-14h] [ebp-20h]
  int v65; // [esp-Ch] [ebp-18h]
  int v66; // [esp-8h] [ebp-14h]
  int v67; // [esp-4h] [ebp-10h]
  int v68; // [esp+0h] [ebp-Ch]
  void *v69; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v68 = a2;
  v69 = retaddr;
  v34 = a5;
  v7 = *a1;
  v49 = *(float *)(v7 + 16);
  v50 = *(float *)(v7 + 20);
  v51 = *(float *)(v7 + 24);
  v52 = *(_DWORD *)(v7 + 28);
  v53 = *(float *)(v7 + 32);
  v54 = *(float *)(v7 + 36);
  v55 = *(float *)(v7 + 40);
  v56 = *(_DWORD *)(v7 + 44);
  v57 = *(float *)(v7 + 48);
  v58 = *(float *)(v7 + 52);
  v59 = *(float *)(v7 + 56);
  v60 = *(_DWORD *)(v7 + 60);
  v61 = *(float *)(v7 + 64);
  v62 = *(float *)(v7 + 68);
  v63 = *(float *)(v7 + 72);
  v64 = *(_DWORD *)(v7 + 76);
  v47[0] = *(_DWORD *)(v7 + 80);
  v47[1] = *(_DWORD *)(v7 + 84);
  v47[2] = *(_DWORD *)(v7 + 88);
  v47[3] = *(_DWORD *)(v7 + 92);
  v47[4] = *(_DWORD *)(v7 + 96);
  v47[5] = *(_DWORD *)(v7 + 100);
  v47[6] = *(_DWORD *)(v7 + 104);
  v47[7] = *(_DWORD *)(v7 + 108);
  v8 = *(_DWORD *)(v7 + 204);
  v47[8] = *(_DWORD *)(v7 + 112);
  v47[9] = *(_DWORD *)(v7 + 116);
  v47[10] = *(_DWORD *)(v7 + 120);
  v47[11] = *(_DWORD *)(v7 + 124);
  v47[12] = *(_DWORD *)(v7 + 128);
  v47[13] = *(_DWORD *)(v7 + 132);
  v47[14] = *(_DWORD *)(v7 + 136);
  v47[15] = *(_DWORD *)(v7 + 140);
  v9 = (float *)(*(_DWORD *)(v8 + 24) + 80 * a6);
  v44 = v9[13];
  v46 = v9[12];
  v43 = v9[14];
  v10 = v46;
  v41 = 0;
  v46 = v46 * v49 + v44 * v50 + v43 * v51;
  v38 = v46 + v61;
  v46 = v10 * v53 + v44 * v54 + v43 * v55;
  v39 = v46 + v62;
  v46 = v43 * v59 + v44 * v58 + v10 * v57;
  v40 = v46 + v63;
  v43 = v9[6];
  v36 = v9[2];
  v44 = v9[10];
  v37 = v57 * v36 + v58 * v43 + v59 * v44;
  v42 = v9[5];
  v46 = v9[1];
  v45 = v9[9];
  v11 = v42;
  v12 = v45;
  v31 = v59 * v45 + v58 * v42 + v57 * v46;
  v42 = v9[4];
  v45 = *v9;
  v35 = v9[8];
  v13 = v42;
  v14 = v45;
  v33 = v59 * v35 + v58 * v42 + v57 * v45;
  v30 = v53 * v36 + v54 * v43 + v55 * v44;
  v29 = v53 * v46 + v54 * v11 + v55 * v12;
  v32 = v53 * v45 + v54 * v42 + v55 * v35;
  v42 = v49 * v36 + v50 * v43 + v51 * v44;
  v45 = v12 * v51 + v11 * v50 + v49 * v46;
  v35 = v35 * v51 + v13 * v50 + v14 * v49;
  *(float *)&v48[16] = v35;
  *(float *)&v48[17] = v45;
  *(float *)v48 = v35;
  *(float *)&v48[1] = v45;
  *(float *)&v48[18] = v42;
  *(float *)&v48[2] = v42;
  *(float *)&v48[20] = v32;
  v48[19] = 0;
  v48[3] = 0;
  *(float *)&v48[4] = v32;
  *(float *)&v48[21] = v29;
  *(float *)&v48[5] = v29;
  *(float *)&v48[22] = v30;
  *(float *)&v48[6] = v30;
  v48[23] = 0;
  v48[7] = 0;
  *(float *)&v48[24] = v33;
  *(float *)&v48[8] = v33;
  *(float *)&v48[25] = v31;
  *(float *)&v48[9] = v31;
  *(float *)&v48[26] = v37;
  *(float *)&v48[10] = v37;
  v48[27] = 0;
  v48[11] = 0;
  *(float *)&v48[12] = v38;
  *(float *)&v48[13] = v39;
  *(float *)&v48[14] = v40;
  v48[15] = 0;
  (*(void (__thiscall **)(int, _DWORD *, float *, float *, int, int))(*(_DWORD *)a5 + 4))(a5, v48, v25, v27, a3, a4);
  result = (*(int (__thiscall **)(_DWORD, int, float *, float *))(**(_DWORD **)(a1[1] + 204) + 4))(
             *(_DWORD *)(a1[1] + 204),
             a1[1] + 16,
             v28,
             v26);
  v16 = 1;
  if ( v25[0] > (double)v26[0] || v28[0] > (double)v27[0] )
    v16 = 0;
  if ( v25[2] > (double)v26[2] || v28[2] > (double)v27[2] )
    v16 = 0;
  if ( v25[1] <= (double)v26[1] && v28[1] <= (double)v27[1] && v16 )
  {
    sub_6043A0(v48);
    sub_99C500(v48);
    v17 = *a1;
    v37 = *(float *)(*a1 + 204);
    *(_DWORD *)(v17 + 204) = v34;
    if ( !*(_DWORD *)(a1[5] + 4 * a6) )
      *(_DWORD *)(a1[5] + 4 * a6) = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)a1[2] + 4))(
                                      a1[2],
                                      *a1,
                                      a1[1],
                                      a1[6]);
    v18 = (int *)a1[4];
    v66 = a6;
    v19 = v18[36] == *a1;
    v20 = *v18;
    v65 = -1;
    if ( v19 )
      (*(void (__stdcall **)(int, int, int))(v20 + 4))(v65, v66, v67);
    else
      (*(void (__stdcall **)(int, int, int))(v20 + 8))(v65, v66, v67);
    v67 = a1[4];
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a1[5] + 4 * a6) + 4))(
      *(_DWORD *)(a1[5] + 4 * a6),
      *a1,
      a1[1],
      a1[3]);
    v21 = *(_DWORD *)(a1[3] + 20);
    if ( v21 )
    {
      if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v21 + 44))(v21) & 2) != 0 )
      {
        v22 = a1[3];
        v38 = 1.0;
        v39 = 1.0;
        v40 = 1.0;
        v41 = 0;
        (*(void (__thiscall **)(_DWORD, float *, float *, float *))(**(_DWORD **)(v22 + 20) + 48))(
          *(_DWORD *)(v22 + 20),
          v25,
          v27,
          &v38);
        v23 = a1[3];
        v38 = 1.0;
        v39 = 1.0;
        v40 = 1.0;
        v41 = 0;
        (*(void (__thiscall **)(_DWORD, float *, float *, float *))(**(_DWORD **)(v23 + 20) + 48))(
          *(_DWORD *)(v23 + 20),
          v28,
          v26,
          &v38);
      }
    }
    *(float *)(*a1 + 204) = v37;
    sub_6043A0(&v49);
    return sub_99C500(v47);
  }
  return result;
}
