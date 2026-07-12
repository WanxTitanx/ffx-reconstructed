// Function: sub_98EA30
// Address: 0x98ea30
void __userpurge sub_98EA30(int a1@<ecx>, int a2@<ebp>, int a3, float *a4, float *a5)
{
  double v5; // st7
  double v6; // st6
  float v7; // xmm1_4
  double v8; // st4
  float v9; // xmm2_4
  float v10; // xmm3_4
  double v11; // st2
  double v12; // st6
  double v13; // st5
  double v14; // st4
  double v15; // rtt
  double v16; // st4
  double v17; // st6
  double v18; // st7
  int v19; // eax
  int v20; // eax
  float v21; // [esp-50h] [ebp-5Ch]
  float v22; // [esp-50h] [ebp-5Ch]
  float v23; // [esp-4Ch] [ebp-58h]
  float v24; // [esp-4Ch] [ebp-58h]
  float v25; // [esp-48h] [ebp-54h]
  float v26; // [esp-48h] [ebp-54h]
  float v27; // [esp-40h] [ebp-4Ch]
  float v28; // [esp-3Ch] [ebp-48h]
  float v29; // [esp-38h] [ebp-44h]
  float v30; // [esp-34h] [ebp-40h]
  float v31; // [esp-30h] [ebp-3Ch]
  float v32; // [esp-30h] [ebp-3Ch]
  float v33; // [esp-2Ch] [ebp-38h]
  float v34; // [esp-2Ch] [ebp-38h]
  float v35; // [esp-2Ch] [ebp-38h]
  float v36; // [esp-2Ch] [ebp-38h]
  float v37; // [esp-28h] [ebp-34h]
  float v38; // [esp-28h] [ebp-34h]
  float v39; // [esp-28h] [ebp-34h]
  float v40; // [esp-28h] [ebp-34h]
  float v41; // [esp-20h] [ebp-2Ch]
  float v42; // [esp-1Ch] [ebp-28h]
  float v43; // [esp-18h] [ebp-24h]
  _WORD v44[4]; // [esp-14h] [ebp-20h] BYREF
  float v45; // [esp-Ch] [ebp-18h] BYREF
  __int16 v46; // [esp-8h] [ebp-14h]
  int v47; // [esp+0h] [ebp-Ch]
  void *v48; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v47 = a2;
  v48 = retaddr;
  if ( *(_BYTE *)(a1 + 72) )
  {
    v42 = *(float *)(a1 + 16);
    v5 = *a4;
    v33 = a4[1];
    v37 = a4[2];
    if ( v42 > v5 )
      v5 = v42;
    v6 = v33;
    v7 = *(float *)(a1 + 20);
    if ( v7 > (double)v33 )
      v6 = v7;
    v8 = v37;
    v9 = *(float *)(a1 + 24);
    if ( v9 > (double)v37 )
      v8 = v9;
    v10 = *(float *)(a1 + 32);
    v11 = v5;
    if ( v5 > v10 )
      v11 = v10;
    v30 = *(float *)(a1 + 36);
    if ( v6 > v30 )
      v6 = v30;
    v41 = *(float *)(a1 + 40);
    if ( v8 > v41 )
      v8 = v41;
    v31 = v11 - v42;
    v28 = *(float *)(a1 + 20);
    v34 = v6 - v28;
    v27 = *(float *)(a1 + 24);
    v38 = v8 - v27;
    v29 = *(float *)(a1 + 48);
    v21 = v29 * v31;
    v45 = *(float *)(a1 + 52);
    v23 = v34 * v45;
    v43 = *(float *)(a1 + 56);
    v44[0] = (int)v21 & 0xFFFE;
    v25 = v38 * v43;
    v44[1] = (int)v23 & 0xFFFE;
    v44[2] = (int)v25 & 0xFFFE;
    v12 = *a5;
    v35 = a5[1];
    v39 = a5[2];
    if ( v42 > v12 )
      v12 = v42;
    v13 = v35;
    if ( v7 > (double)v35 )
      v13 = v7;
    v14 = v39;
    if ( v9 > (double)v39 )
      v14 = v9;
    v15 = v14;
    v16 = v12;
    v17 = v15;
    v18 = v16;
    if ( v16 > v10 )
      v18 = v10;
    if ( v13 > v30 )
      v13 = v30;
    if ( v17 > v41 )
      v17 = v41;
    v22 = v18 - v42;
    v24 = v13 - v28;
    v26 = v17 - v27;
    v32 = v22 * v29;
    v36 = v24 * v45;
    v40 = v26 * v43;
    LOWORD(v45) = (int)(v32 + 1.0) | 1;
    HIWORD(v45) = (int)(v36 + 1.0) | 1;
    v46 = (int)(v40 + 1.0) | 1;
    v19 = *(_DWORD *)(a1 + 156);
    if ( v19 )
    {
      v20 = v19 - 1;
      if ( v20 )
      {
        if ( v20 == 1 )
          sub_990B10(*(_DWORD *)(a1 + 148), a3, v44, &v45);
      }
      else
      {
        sub_991860((_DWORD *)a1, a3, v44, &v45);
      }
    }
    else
    {
      sub_990C40((_DWORD *)a1, a3, v44, &v45, 0, *(_DWORD *)(a1 + 68));
    }
  }
  else
  {
    sub_991930(a3, a4, a5);
  }
}
