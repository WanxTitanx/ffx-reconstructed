// Function: sub_9AE580
// Address: 0x9ae580
char __usercall sub_9AE580@<al>(int a1@<ecx>, int a2@<ebp>)
{
  float **v3; // edx
  unsigned int i; // edi
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  float v10; // xmm0_4
  int v11; // edx
  int v12; // eax
  float v13; // xmm0_4
  int v14; // eax
  int v15; // ecx
  float v16; // xmm0_4
  int v17; // edx
  char result; // al
  float *v19; // eax
  float *v20; // ecx
  double v21; // st7
  double v22; // st7
  int v23; // edi
  double v24; // st7
  double v25; // st6
  double v26; // st5
  double v27; // st6
  int v28; // edx
  int v29; // eax
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // eax
  float v34; // xmm0_4
  int v35; // edx
  float *v36; // ecx
  float *v37; // eax
  double v38; // st7
  float *v39; // eax
  float *v40; // ecx
  float *v41; // eax
  double v42; // st7
  double v43; // st7
  double v44; // st7
  float *v45; // eax
  double v46; // st7
  float *v47; // eax
  int v48; // [esp-68h] [ebp-74h]
  int v49; // [esp-68h] [ebp-74h]
  float v50; // [esp-50h] [ebp-5Ch] BYREF
  float v51; // [esp-4Ch] [ebp-58h]
  float v52; // [esp-48h] [ebp-54h]
  int v53; // [esp-44h] [ebp-50h]
  float v54; // [esp-40h] [ebp-4Ch] BYREF
  float v55; // [esp-3Ch] [ebp-48h]
  float v56; // [esp-38h] [ebp-44h]
  int v57; // [esp-34h] [ebp-40h]
  float v58; // [esp-30h] [ebp-3Ch] BYREF
  float v59; // [esp-2Ch] [ebp-38h]
  float v60; // [esp-28h] [ebp-34h]
  int v61; // [esp-24h] [ebp-30h]
  float v62; // [esp-20h] [ebp-2Ch] BYREF
  float v63; // [esp-1Ch] [ebp-28h]
  float v64; // [esp-18h] [ebp-24h]
  int v65; // [esp-14h] [ebp-20h]
  float v66; // [esp-4h] [ebp-10h]
  int v67; // [esp+0h] [ebp-Ch]
  void *v68; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v67 = a2;
  v68 = retaddr;
  v3 = *(float ***)(a1 + 392);
  switch ( (unsigned int)v3[8] )
  {
    case 1u:
      for ( i = 0; i < 3; ++i )
      {
        v5 = *(_DWORD *)(a1 + 392);
        v62 = 0.0;
        v6 = *(_DWORD *)(v5 + 32);
        v63 = 0.0;
        *(_DWORD *)(v5 + 4 * v6 + 16) = 0;
        --*(_DWORD *)(a1 + 384);
        *(_DWORD *)(v5 + 4 * *(_DWORD *)(v5 + 32)) = *(_DWORD *)(a1 + 4 * *(_DWORD *)(a1 + 384) + 368);
        v7 = *(_DWORD *)(v5 + 32) + 1;
        v8 = *(_DWORD *)(v5 + 4 * v7 - 4);
        *(_DWORD *)(v5 + 32) = v7;
        v64 = 0.0;
        v65 = 0;
        *(&v62 + i) = 1.0;
        sub_9B1530(&v62, v8);
        if ( (unsigned __int8)sub_9AE580(a1) )
          goto LABEL_7;
        v9 = *(_DWORD *)(a1 + 392);
        --*(_DWORD *)(v9 + 32);
        v10 = v62;
        *(_DWORD *)(a1 + 4 * (*(_DWORD *)(a1 + 384))++ + 368) = *(_DWORD *)(v9 + 4 * *(_DWORD *)(v9 + 32));
        v11 = *(_DWORD *)(a1 + 392);
        v12 = *(_DWORD *)(v11 + 32);
        v54 = -v10;
        v13 = v63;
        *(_DWORD *)(v11 + 4 * v12 + 16) = 0;
        --*(_DWORD *)(a1 + 384);
        *(_DWORD *)(v11 + 4 * *(_DWORD *)(v11 + 32)) = *(_DWORD *)(a1 + 4 * *(_DWORD *)(a1 + 384) + 368);
        v14 = *(_DWORD *)(v11 + 32);
        v15 = *(_DWORD *)(v11 + 4 * v14);
        v55 = -v13;
        v16 = v64;
        *(_DWORD *)(v11 + 32) = v14 + 1;
        v56 = -v16;
        v57 = 0;
        sub_9B1530(&v54, v15);
        if ( (unsigned __int8)sub_9AE580(a1) )
          goto LABEL_7;
        v17 = *(_DWORD *)(a1 + 392);
        --*(_DWORD *)(v17 + 32);
        *(_DWORD *)(a1 + 4 * (*(_DWORD *)(a1 + 384))++ + 368) = *(_DWORD *)(v17 + 4 * *(_DWORD *)(v17 + 32));
      }
      result = 0;
      break;
    case 2u:
      v19 = v3[1];
      v20 = *v3;
      v21 = v19[4];
      v19 += 4;
      v22 = v21 - (*v3)[4];
      v23 = 0;
      v65 = 0;
      v58 = v22;
      v59 = v19[1] - v20[5];
      v60 = v19[2] - v20[6];
      v24 = v60;
      v25 = v59;
      v26 = 0.0;
      while ( 1 )
      {
        v54 = v26;
        v55 = v26;
        v56 = v26;
        *(&v54 + v23) = 1.0;
        v62 = v25 * v56 - v55 * v24;
        v63 = v54 * v24 - v56 * v58;
        v27 = v26;
        v64 = v58 * v55 - v54 * v59;
        v66 = v62 * v62 + v63 * v63 + v64 * v64;
        if ( v66 > v26 )
        {
          v28 = *(_DWORD *)(a1 + 392);
          *(_DWORD *)(v28 + 4 * *(_DWORD *)(v28 + 32) + 16) = 0;
          --*(_DWORD *)(a1 + 384);
          *(_DWORD *)(v28 + 4 * *(_DWORD *)(v28 + 32)) = *(_DWORD *)(a1 + 4 * *(_DWORD *)(a1 + 384) + 368);
          v29 = *(_DWORD *)(v28 + 32) + 1;
          v30 = *(_DWORD *)(v28 + 4 * v29 - 4);
          *(_DWORD *)(v28 + 32) = v29;
          sub_9B1530(&v62, v30);
          if ( (unsigned __int8)sub_9AE580(a1) )
            goto LABEL_7;
          v31 = *(_DWORD *)(a1 + 392);
          --*(_DWORD *)(v31 + 32);
          v32 = *(_DWORD *)(a1 + 384);
          v33 = *(_DWORD *)(v31 + 4 * *(_DWORD *)(v31 + 32));
          v50 = -v62;
          v34 = v63;
          *(_DWORD *)(a1 + 4 * v32 + 368) = v33;
          ++*(_DWORD *)(a1 + 384);
          v51 = -v34;
          v48 = *(_DWORD *)(a1 + 392);
          v52 = -v64;
          v53 = 0;
          sub_9B11D0(v48, &v50);
          if ( (unsigned __int8)sub_9AE580(a1) )
            goto LABEL_7;
          v35 = *(_DWORD *)(a1 + 392);
          v24 = v60;
          v27 = 0.0;
          --*(_DWORD *)(v35 + 32);
          *(_DWORD *)(a1 + 4 * (*(_DWORD *)(a1 + 384))++ + 368) = *(_DWORD *)(v35 + 4 * *(_DWORD *)(v35 + 32));
        }
        if ( (unsigned int)++v23 >= 3 )
          break;
        v26 = v27;
        v25 = v59;
      }
      result = 0;
      break;
    case 3u:
      v36 = *v3;
      v37 = v3[2];
      v65 = 0;
      v54 = v37[4] - v36[4];
      v55 = v37[5] - v36[5];
      v38 = v37[6];
      v39 = v3[1] + 4;
      v56 = v38 - v36[6];
      v58 = *v39 - v36[4];
      v59 = v39[1] - v36[5];
      v60 = v39[2] - v36[6];
      v62 = v59 * v56 - v60 * v55;
      v63 = v60 * v54 - v56 * v58;
      v64 = v55 * v58 - v59 * v54;
      v66 = v62 * v62 + v63 * v63 + v64 * v64;
      if ( v66 <= 0.0 )
        goto LABEL_21;
      sub_9B11D0(v3, &v62);
      if ( (unsigned __int8)sub_9AE580(a1) )
        goto LABEL_7;
      sub_9B2770(*(_DWORD *)(a1 + 392));
      v50 = -v62;
      v51 = -v63;
      v49 = *(_DWORD *)(a1 + 392);
      v52 = -v64;
      v53 = 0;
      sub_9B11D0(v49, &v50);
      if ( (unsigned __int8)sub_9AE580(a1) )
        goto LABEL_7;
      sub_9B2770(*(_DWORD *)(a1 + 392));
      result = 0;
      break;
    case 4u:
      v40 = v3[3];
      v41 = v3[2];
      v53 = 0;
      v42 = v41[4];
      v57 = 0;
      v43 = v42 - v40[4];
      v61 = 0;
      v50 = v43;
      v51 = v41[5] - v40[5];
      v44 = v41[6];
      v45 = v3[1];
      v52 = v44 - v40[6];
      v54 = v45[4] - v40[4];
      v55 = v45[5] - v40[5];
      v46 = v45[6];
      v47 = *v3;
      v56 = v46 - v40[6];
      v58 = v47[4] - v40[4];
      v59 = v47[5] - v40[5];
      v60 = v47[6] - v40[6];
      v66 = fabs(sub_9B12D0(&v58, &v54, &v50));
      if ( v66 <= 0.0 )
        goto LABEL_21;
LABEL_7:
      result = 1;
      break;
    default:
LABEL_21:
      result = 0;
      break;
  }
  return result;
}
