// Function: sub_9B2910
// Address: 0x9b2910
char __userpurge sub_9B2910@<al>(int a1@<ecx>, int a2@<ebp>, float *a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // eax
  double v9; // st7
  double v10; // st6
  char v11; // cl
  float v12; // xmm0_4
  __int16 v13; // ax
  int v14; // xmm0_4
  double v15; // st7
  double v16; // st6
  float v17; // xmm0_4
  __int16 v18; // ax
  int v19; // xmm0_4
  unsigned int v20; // xmm0_4
  double v21; // st7
  double v22; // st6
  unsigned int v23; // ecx
  float v24; // xmm0_4
  __int16 v25; // ax
  int v26; // xmm0_4
  int v27; // xmm0_4
  double v28; // st7
  double v29; // st6
  char v30; // cl
  int v31; // xmm0_4
  int v32; // xmm0_4
  float v34; // [esp-70h] [ebp-7Ch] BYREF
  float v35; // [esp-6Ch] [ebp-78h]
  float v36; // [esp-68h] [ebp-74h]
  int v37; // [esp-64h] [ebp-70h]
  unsigned int v38; // [esp-60h] [ebp-6Ch]
  int v39; // [esp-5Ch] [ebp-68h]
  int v40; // [esp-58h] [ebp-64h]
  unsigned int v41; // [esp-54h] [ebp-60h]
  float v42; // [esp-40h] [ebp-4Ch]
  float v43; // [esp-3Ch] [ebp-48h]
  float v44; // [esp-38h] [ebp-44h]
  float v45; // [esp-30h] [ebp-3Ch]
  float v46; // [esp-2Ch] [ebp-38h]
  float v47; // [esp-28h] [ebp-34h]
  float v48; // [esp-18h] [ebp-24h]
  float v49; // [esp-14h] [ebp-20h]
  int v50; // [esp-10h] [ebp-1Ch]
  int v51; // [esp-Ch] [ebp-18h]
  float v52; // [esp-8h] [ebp-14h]
  int v53; // [esp-4h] [ebp-10h]
  int v54; // [esp+0h] [ebp-Ch]
  void *v55; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v54 = a2;
  v55 = retaddr;
  v53 = a1;
  LOWORD(v38) = v38 & 0xFFF0;
  *(float *)a8 = *a3;
  *(float *)(a8 + 4) = a3[1];
  *(float *)(a8 + 8) = a3[2];
  *(float *)(a8 + 12) = a3[3];
  *(_WORD *)(a8 + 16) |= 0xFu;
  v49 = COERCE_FLOAT(sub_9B3740(a3, a4, a5, a6, a7));
  v51 = sub_9B3740(a3, a4, a6, a7, a5);
  v48 = COERCE_FLOAT(sub_9B3740(a3, a4, a7, a5, a6));
  v50 = sub_9B3740(a3, a5, a7, a6, a4);
  if ( v49 < 0.0 || (v8 = v51, v51 < 0) || v48 < 0.0 || v50 < 0 )
  {
    *(_BYTE *)(a8 + 36) = 1;
    return 0;
  }
  if ( v49 == 0.0 && !v51 && v48 == 0.0 && !v50 )
    return 0;
  v52 = 3.4028235e38;
  if ( v49 != 0.0 )
  {
    sub_9B2DD0(a3, a4, a5, a6, &v34);
    v49 = v34 - *a3;
    v9 = v49;
    v42 = v49;
    v49 = v35 - a3[1];
    v10 = v49;
    v43 = v49;
    v49 = v36 - a3[2];
    v44 = v49;
    v47 = v49;
    v45 = v9;
    v46 = v10;
    v49 = v45 * v42 + v46 * v43 + v49 * v49;
    if ( v49 < 3.402823466385289e38 )
    {
      v11 = v38;
      v12 = v49;
      *(float *)a8 = v34;
      *(float *)(a8 + 4) = v35;
      *(float *)(a8 + 8) = v36;
      *(_DWORD *)(a8 + 12) = v37;
      v13 = *(_WORD *)(a8 + 16);
      v52 = v12;
      v14 = v39;
      *(_WORD *)(a8 + 16) = v13 & 0xFFF0 | v11 & 7;
      *(_DWORD *)(a8 + 20) = v14;
      *(_DWORD *)(a8 + 24) = v40;
      *(_QWORD *)(a8 + 28) = v41;
    }
    v8 = v51;
  }
  if ( v8 )
  {
    sub_9B2DD0(a3, a4, a6, a7, &v34);
    v49 = v34 - *a3;
    v15 = v49;
    v45 = v49;
    v49 = v35 - a3[1];
    v16 = v49;
    v46 = v49;
    v49 = v36 - a3[2];
    v47 = v49;
    v44 = v49;
    v42 = v15;
    v43 = v16;
    v49 = v43 * v46 + v42 * v45 + v49 * v49;
    if ( v52 > (double)v49 )
    {
      *(float *)a8 = v34;
      v17 = v49;
      *(float *)(a8 + 4) = v35;
      *(float *)(a8 + 8) = v36;
      *(_DWORD *)(a8 + 12) = v37;
      v18 = *(_WORD *)(a8 + 16);
      v52 = v17;
      v19 = v39;
      *(_WORD *)(a8 + 16) = v18 & 0xFFF0 | v38 & 1 | (2 * (v38 & 6));
      *(_DWORD *)(a8 + 20) = v19;
      *(_DWORD *)(a8 + 28) = v40;
      v20 = v41;
      *(_DWORD *)(a8 + 24) = 0;
      *(_DWORD *)(a8 + 32) = v20;
    }
  }
  if ( v48 != 0.0 )
  {
    sub_9B2DD0(a3, a4, a7, a5, &v34);
    v48 = v34 - *a3;
    v21 = v48;
    v45 = v48;
    v48 = v35 - a3[1];
    v22 = v48;
    v46 = v48;
    v48 = v36 - a3[2];
    v47 = v48;
    v44 = v48;
    v42 = v21;
    v43 = v22;
    v48 = v43 * v46 + v42 * v45 + v48 * v48;
    if ( v52 > (double)v48 )
    {
      v23 = v38;
      *(float *)a8 = v34;
      v24 = v48;
      *(float *)(a8 + 4) = v35;
      *(float *)(a8 + 8) = v36;
      *(_DWORD *)(a8 + 12) = v37;
      v25 = *(_WORD *)(a8 + 16);
      v52 = v24;
      v26 = v39;
      *(_WORD *)(a8 + 16) = v25 & 0xFFF0 | v23 & 1 | (4 * (v23 & 2)) | (v23 >> 1) & 2;
      *(_DWORD *)(a8 + 20) = v26;
      *(_DWORD *)(a8 + 24) = v41;
      v27 = v40;
      *(_DWORD *)(a8 + 28) = 0;
      *(_DWORD *)(a8 + 32) = v27;
    }
  }
  if ( v50 )
  {
    sub_9B2DD0(a3, a5, a7, a6, &v34);
    v48 = v34 - *a3;
    v28 = v48;
    v45 = v48;
    v48 = v35 - a3[1];
    v29 = v48;
    v46 = v48;
    v48 = v36 - a3[2];
    v47 = v48;
    v44 = v48;
    v42 = v28;
    v43 = v29;
    v48 = v43 * v46 + v42 * v45 + v48 * v48;
    if ( v52 > (double)v48 )
    {
      v30 = v38;
      *(float *)a8 = v34;
      *(float *)(a8 + 4) = v35;
      v31 = v39;
      *(float *)(a8 + 8) = v36;
      *(_DWORD *)(a8 + 12) = v37;
      *(_WORD *)(a8 + 16) = *(_WORD *)(a8 + 16) & 0xFFF0 | v30 & 4 | (2 * (v30 & 1 | (2 * (v30 & 2))));
      *(_DWORD *)(a8 + 24) = v31;
      *(_DWORD *)(a8 + 28) = v41;
      v32 = v40;
      *(_DWORD *)(a8 + 20) = 0;
      *(_DWORD *)(a8 + 32) = v32;
    }
  }
  return 1;
}
