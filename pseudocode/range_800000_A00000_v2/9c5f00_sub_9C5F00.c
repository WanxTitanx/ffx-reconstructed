// Function: sub_9C5F00
// Address: 0x9c5f00
unsigned int __usercall sub_9C5F00@<eax>(int a1@<ecx>, int a2@<ebp>)
{
  unsigned int result; // eax
  bool v4; // zf
  float *v5; // eax
  double v6; // st6
  double v7; // st7
  float *v8; // eax
  double v9; // st6
  double v10; // st7
  float *v11; // ecx
  float v12; // eax
  int n3; // edx
  int v14; // eax
  int v15; // ecx
  double v16; // st7
  int v17; // xmm0_4
  double v18; // st7
  double v19; // st7
  int v20; // xmm0_4
  double v21; // st7
  double v22; // st7
  int v23; // xmm0_4
  int v24; // xmm0_4
  int v25; // [esp+14h] [ebp-104h]
  int v26; // [esp+18h] [ebp-100h]
  float v27; // [esp+1Ch] [ebp-FCh]
  float v28; // [esp+20h] [ebp-F8h]
  float v29; // [esp+24h] [ebp-F4h]
  float v30; // [esp+2Ch] [ebp-ECh] BYREF
  float v31; // [esp+30h] [ebp-E8h]
  float v32; // [esp+34h] [ebp-E4h]
  int v33; // [esp+38h] [ebp-E0h]
  float v34; // [esp+3Ch] [ebp-DCh] BYREF
  float v35; // [esp+40h] [ebp-D8h]
  float v36; // [esp+44h] [ebp-D4h]
  int v37; // [esp+48h] [ebp-D0h]
  float v38; // [esp+4Ch] [ebp-CCh]
  float v39; // [esp+50h] [ebp-C8h]
  float v40; // [esp+54h] [ebp-C4h]
  int v41; // [esp+58h] [ebp-C0h]
  float v42; // [esp+60h] [ebp-B8h]
  float v43; // [esp+64h] [ebp-B4h]
  int n3_1; // [esp+68h] [ebp-B0h]
  _DWORD v45[12]; // [esp+6Ch] [ebp-ACh] BYREF
  _DWORD v46[12]; // [esp+9Ch] [ebp-7Ch] BYREF
  float v47; // [esp+CCh] [ebp-4Ch] BYREF
  float v48; // [esp+D0h] [ebp-48h]
  float v49; // [esp+D4h] [ebp-44h]
  int v50; // [esp+D8h] [ebp-40h]
  float v51; // [esp+DCh] [ebp-3Ch]
  float v52; // [esp+E0h] [ebp-38h]
  float v53; // [esp+E4h] [ebp-34h]
  float v54; // [esp+ECh] [ebp-2Ch]
  float v55; // [esp+F0h] [ebp-28h]
  float v56; // [esp+F4h] [ebp-24h]
  _DWORD v57[3]; // [esp+10Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+118h] [ebp+0h]

  v57[0] = a2;
  v57[1] = retaddr;
  result = (unsigned int)v57 ^ __security_cookie;
  if ( *(_BYTE *)(a1 + 563) )
  {
    v4 = *(_BYTE *)(a1 + 560) == 0;
    v38 = 0.0;
    *(_DWORD *)(a1 + 640) = 0;
    v39 = 0.0;
    *(_DWORD *)(a1 + 644) = 0;
    v40 = 0.0;
    *(_DWORD *)(a1 + 648) = 0;
    v41 = 0;
    *(_DWORD *)(a1 + 28) = 0;
    *(_DWORD *)(a1 + 556) = 0;
    *(_DWORD *)(a1 + 552) = 0;
    *(_DWORD *)(a1 + 652) = 0;
    if ( v4 )
    {
      v5 = *(float **)(a1 + 20);
      n3_1 = *(int *)(a1 + 388);
      v43 = *(float *)(a1 + 384);
      v42 = *(float *)(a1 + 392);
      v6 = *(float *)&n3_1;
      *(float *)&n3_1 = v5[6] * v42 + v5[4] * v43 + v5[5] * *(float *)&n3_1;
      v38 = *(float *)&n3_1 + v5[16];
      *(float *)&n3_1 = v5[9] * v6 + v5[8] * v43 + v5[10] * v42;
      v39 = *(float *)&n3_1 + v5[17];
      *(float *)&n3_1 = v43 * v5[12] + v6 * v5[13] + v42 * v5[14];
      v7 = *(float *)&n3_1 + v5[18];
      v8 = *(float **)(a1 + 24);
      v40 = v7;
      n3_1 = *(int *)(a1 + 452);
      v43 = *(float *)(a1 + 448);
      v42 = *(float *)(a1 + 456);
      v9 = *(float *)&n3_1;
      *(float *)&n3_1 = v8[6] * v42 + v8[5] * *(float *)&n3_1 + v43 * v8[4];
      v27 = *(float *)&n3_1 + v8[16];
      *(float *)&n3_1 = v8[9] * v9 + v43 * v8[8] + v8[10] * v42;
      v28 = *(float *)&n3_1 + v8[17];
      *(float *)&n3_1 = v42 * v8[14] + v9 * v8[13] + v43 * v8[12];
      v29 = *(float *)&n3_1 + v8[18];
      v34 = v27 - v38;
      v35 = v28 - v39;
      v36 = v29 - v40;
      *(float *)&n3_1 = v34 * v34 + v35 * v35 + v36 * v36;
      if ( *(float *)&n3_1 <= 0.00000011920929 )
      {
        v47 = 1.0;
        v48 = 0.0;
        v49 = 0.0;
      }
      else
      {
        *(float *)&n3_1 = sqrt(*(float *)&n3_1);
        v33 = 0;
        *(float *)&n3_1 = 1.0 / *(float *)&n3_1;
        v30 = v34 * *(float *)&n3_1;
        v47 = v30;
        v31 = v35 * *(float *)&n3_1;
        v48 = v31;
        v32 = *(float *)&n3_1 * v36;
        v49 = v32;
      }
      v50 = 0;
      *(float *)&n3_1 = fabs(v49);
      if ( *(float *)&n3_1 <= 0.70710677 )
      {
        v43 = v47 * v47 + v48 * v48;
        *(float *)&n3_1 = sqrt(v43);
        v53 = 0.0;
        *(float *)&n3_1 = 1.0 / *(float *)&n3_1;
        v51 = -v48 * *(float *)&n3_1;
        v52 = v47 * *(float *)&n3_1;
        v54 = -v49 * v52;
        v55 = v49 * v51;
        v10 = *(float *)&n3_1 * v43;
      }
      else
      {
        v43 = v48 * v48 + v49 * v49;
        *(float *)&n3_1 = sqrt(v43);
        v51 = 0.0;
        *(float *)&n3_1 = 1.0 / *(float *)&n3_1;
        v52 = -v49 * *(float *)&n3_1;
        v53 = v48 * *(float *)&n3_1;
        v54 = *(float *)&n3_1 * v43;
        v55 = -v47 * v53;
        v10 = v47 * v52;
      }
      *(float *)&v11 = COERCE_FLOAT(&v47);
      v56 = v10;
      LODWORD(v12) = a1 + 48;
      n3 = 3;
      v43 = COERCE_FLOAT(&v47);
      LODWORD(v42) = a1 + 48;
      n3_1 = 3;
      do
      {
        if ( v12 != 0.0 )
        {
          v14 = *(_DWORD *)(a1 + 24);
          v15 = *(_DWORD *)(a1 + 20);
          v26 = *(_DWORD *)(v14 + 352);
          v25 = *(_DWORD *)(v15 + 352);
          v30 = v27 - *(float *)(v14 + 64);
          v16 = v28 - *(float *)(v14 + 68);
          v46[0] = *(_DWORD *)(v14 + 16);
          v46[1] = *(_DWORD *)(v14 + 32);
          v17 = *(_DWORD *)(v14 + 48);
          v31 = v16;
          v46[2] = v17;
          v18 = v29 - *(float *)(v14 + 72);
          v46[4] = *(_DWORD *)(v14 + 20);
          v46[5] = *(_DWORD *)(v14 + 36);
          v32 = v18;
          v19 = v38 - *(float *)(v15 + 64);
          v46[6] = *(_DWORD *)(v14 + 52);
          v46[8] = *(_DWORD *)(v14 + 24);
          v20 = *(_DWORD *)(v14 + 40);
          v34 = v19;
          v46[9] = v20;
          v21 = v39 - *(float *)(v15 + 68);
          v46[10] = *(_DWORD *)(v14 + 56);
          v45[0] = *(_DWORD *)(v15 + 16);
          v35 = v21;
          v22 = v40 - *(float *)(v15 + 72);
          v45[1] = *(_DWORD *)(v15 + 32);
          v45[2] = *(_DWORD *)(v15 + 48);
          v23 = *(_DWORD *)(v15 + 20);
          v36 = v22;
          v45[4] = v23;
          v45[5] = *(_DWORD *)(v15 + 36);
          v45[6] = *(_DWORD *)(v15 + 52);
          v45[8] = *(_DWORD *)(v15 + 24);
          v45[9] = *(_DWORD *)(v15 + 40);
          v24 = *(_DWORD *)(v15 + 56);
          v33 = 0;
          v37 = 0;
          v46[3] = 0;
          v46[7] = 0;
          v46[11] = 0;
          v45[3] = 0;
          v45[7] = 0;
          v45[10] = v24;
          v45[11] = 0;
          sub_9C5670(v45, v46, &v34, &v30, LODWORD(v43), v15 + 416, v25, v14 + 416, v26);
          v12 = v42;
          *(float *)&v11 = v43;
          n3 = n3_1;
        }
        LODWORD(v12) += 96;
        v11 += 4;
        --n3;
        v42 = v12;
        v43 = *(float *)&v11;
        n3_1 = n3;
      }
      while ( *(float *)&n3 != 0.0 );
    }
    return sub_9C65C0(
             *(_DWORD *)(a1 + 20) + 16,
             *(_DWORD *)(a1 + 24) + 16,
             *(_DWORD *)(a1 + 20) + 272,
             *(_DWORD *)(a1 + 24) + 272);
  }
  return result;
}
