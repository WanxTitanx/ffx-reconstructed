// Function: sub_9AD400
// Address: 0x9ad400
int __userpurge sub_9AD400@<eax>(int a1@<ecx>, int a2@<ebp>, float *a3, int a4, int a5, char a6)
{
  double v6; // st7
  double v7; // st5
  double v8; // st7
  double v9; // st6
  double v10; // st3
  double v11; // st6
  double v12; // st3
  double v13; // st5
  double v14; // st4
  double v15; // st7
  double v16; // st4
  double v17; // st3
  int result; // eax
  double v19; // st7
  double v20; // st5
  double v21; // st5
  double v22; // st3
  double v23; // st2
  float v24; // [esp+0h] [ebp-140h]
  float v25; // [esp+18h] [ebp-128h]
  float v26; // [esp+1Ch] [ebp-124h]
  float v27; // [esp+20h] [ebp-120h]
  float v28; // [esp+24h] [ebp-11Ch] BYREF
  float v29; // [esp+28h] [ebp-118h]
  float v30; // [esp+2Ch] [ebp-114h]
  int v31; // [esp+30h] [ebp-110h]
  float v32; // [esp+34h] [ebp-10Ch] BYREF
  float v33; // [esp+38h] [ebp-108h]
  float v34; // [esp+3Ch] [ebp-104h]
  int v35; // [esp+40h] [ebp-100h]
  float v36; // [esp+44h] [ebp-FCh]
  float v37; // [esp+48h] [ebp-F8h]
  float v38; // [esp+4Ch] [ebp-F4h]
  float v39; // [esp+50h] [ebp-F0h]
  float v40; // [esp+54h] [ebp-ECh] BYREF
  float v41; // [esp+58h] [ebp-E8h]
  float v42; // [esp+5Ch] [ebp-E4h]
  float v43; // [esp+6Ch] [ebp-D4h] BYREF
  float v44; // [esp+70h] [ebp-D0h]
  float v45; // [esp+74h] [ebp-CCh] BYREF
  float v46; // [esp+78h] [ebp-C8h]
  float v47; // [esp+7Ch] [ebp-C4h]
  int v48; // [esp+80h] [ebp-C0h]
  float v49; // [esp+88h] [ebp-B8h]
  float v50; // [esp+8Ch] [ebp-B4h]
  float v51; // [esp+90h] [ebp-B0h]
  float v52; // [esp+94h] [ebp-ACh]
  float v53; // [esp+98h] [ebp-A8h]
  float v54; // [esp+9Ch] [ebp-A4h]
  float v55; // [esp+A0h] [ebp-A0h]
  float v56; // [esp+A4h] [ebp-9Ch]
  float v57; // [esp+A8h] [ebp-98h]
  float v58; // [esp+ACh] [ebp-94h]
  float v59[13]; // [esp+B0h] [ebp-90h] BYREF
  _DWORD v60[23]; // [esp+E4h] [ebp-5Ch] BYREF
  _UNKNOWN *retaddr; // [esp+140h] [ebp+0h]

  v60[20] = a2;
  v60[21] = retaddr;
  v6 = a3[12] - a3[28];
  v43 = 0.0;
  v48 = 0;
  v40 = v6;
  v41 = a3[13] - a3[29];
  v42 = a3[14] - a3[30];
  v55 = a3[20];
  v56 = a3[16];
  v53 = a3[24];
  v45 = v40 * v56 + v41 * v55 + v42 * v53;
  v52 = a3[17];
  v54 = a3[21];
  v57 = a3[25];
  v46 = v41 * v54 + v40 * v52 + v42 * v57;
  v58 = a3[18];
  v49 = a3[22];
  v44 = a3[26];
  v7 = v58;
  v8 = v44;
  v9 = v49;
  v47 = v42 * v44 + v40 * v58 + v41 * v49;
  v39 = a3[6];
  v58 = a3[2];
  v50 = a3[10];
  v59[0] = v58 * v7 + v39 * v49 + v50 * v44;
  v51 = a3[5];
  v44 = a3[1];
  v49 = a3[9];
  v26 = v51 * v9 + v44 * v7 + v49 * v8;
  v37 = a3[4];
  v36 = *a3;
  v10 = v9 * v37;
  v11 = v36;
  v12 = v7 * v36 + v10;
  v13 = a3[8];
  v14 = v8 * v13 + v12;
  v15 = v37;
  v25 = v14;
  v27 = v39 * v54 + v58 * v52 + v50 * v57;
  v16 = v44;
  v17 = v49;
  v44 = v52 * v44 + v54 * v51 + v49 * v57;
  v49 = v37 * v54 + v36 * v52 + v13 * v57;
  v60[7] = 0;
  v60[11] = 0;
  v60[15] = 0;
  v37 = v58 * v56 + v39 * v55 + v50 * v53;
  *(float *)&v60[6] = v37;
  *(float *)&v60[8] = v49;
  *(float *)&v60[9] = v44;
  *(float *)&v60[10] = v27;
  *(float *)&v60[12] = v25;
  *(float *)&v60[13] = v26;
  *(float *)&v60[14] = v59[0];
  v36 = v17 * v53 + v16 * v56 + v51 * v55;
  v38 = v15 * v55 + v11 * v56 + v53 * v13;
  *(float *)&v60[4] = v38;
  v59[1] = v38;
  *(float *)&v60[5] = v36;
  v59[2] = v36;
  v24 = *(float *)(a1 + 12);
  v59[3] = v37;
  v59[4] = 0.0;
  v59[5] = v49;
  v59[6] = v44;
  v59[7] = v27;
  v59[8] = 0.0;
  v59[9] = v25;
  v59[10] = v26;
  v59[11] = v59[0];
  v59[12] = 0.0;
  *(float *)v60 = v45;
  *(float *)&v60[1] = v46;
  *(float *)&v60[2] = v47;
  v60[3] = 0;
  result = sub_9ACED0(v60, &v40, &v45, &v43, v59, LODWORD(v24));
  if ( (_BYTE)result )
  {
    v52 = a3[17];
    v56 = a3[16];
    v58 = a3[18];
    if ( a6 )
    {
      v19 = v46;
      v31 = 0;
      v20 = v45;
      v45 = v46 * v52 + v45 * v56 + v47 * v58;
      v54 = a3[21];
      v28 = -v45;
      v55 = a3[20];
      v57 = a3[22];
      v46 = v20 * v55 + v54 * v46 + v57 * v47;
      v51 = a3[25];
      v29 = -v46;
      v53 = a3[24];
      v50 = a3[26];
      v47 = v47 * v50 + v19 * v51 + v20 * v53;
      v30 = -v47;
      v32 = v45 * v43;
      v33 = v46 * v43;
      v34 = v47 * v43;
      v21 = v41;
      v22 = v40;
      v59[0] = v41 * v52 + v40 * v56 + v42 * v58;
      v23 = v59[0] + a3[28];
      v48 = 0;
      v40 = v23;
      v59[0] = v22 * v55 + v54 * v41 + v57 * v42;
      v41 = v59[0] + a3[29];
      v59[0] = v21 * v51 + v22 * v53 + v42 * v50;
      v42 = v59[0] + a3[30];
      v45 = v40 + v32;
      v46 = v41 + v33;
      v47 = v42 + v34;
      return (*(int (__thiscall **)(int, float *, float *, float))(*(_DWORD *)a4 + 12))(
               a4,
               &v28,
               &v45,
               COERCE_FLOAT(LODWORD(v43)));
    }
    else
    {
      v31 = 0;
      v59[0] = v41 * v52 + v40 * v56 + v42 * v58;
      v28 = v59[0] + a3[28];
      v54 = a3[21];
      v55 = a3[20];
      v57 = a3[22];
      v59[0] = v40 * v55 + v54 * v41 + v57 * v42;
      v29 = v59[0] + a3[29];
      v51 = a3[25];
      v53 = a3[24];
      v50 = a3[26];
      v59[0] = v42 * v50 + v41 * v51 + v40 * v53;
      v30 = v59[0] + a3[30];
      v32 = v46 * v52 + v45 * v56 + v47 * v58;
      v33 = v45 * v55 + v54 * v46 + v57 * v47;
      v35 = 0;
      v34 = v46 * v51 + v45 * v53 + v47 * v50;
      return (*(int (__thiscall **)(int, float *, float *, float))(*(_DWORD *)a4 + 12))(
               a4,
               &v32,
               &v28,
               COERCE_FLOAT(LODWORD(v43)));
    }
  }
  return result;
}
