// Function: sub_A744E0
// Address: 0xa744e0
// Size: 0x519
// Prototype: 

int __cdecl sub_A744E0(int a1, int a2, __int16 *a3)
{
  int v3; // ebx
  int v5; // edx
  int result; // eax
  int v7; // esi
  double v8; // st7
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  double v14; // st6
  int v15; // eax
  double v16; // st6
  double v17; // st5
  double v18; // st4
  double v19; // st3
  double v20; // st2
  double v21; // st7
  double v22; // st2
  double v23; // st1
  double v24; // rt1
  double v25; // st3
  double v26; // st7
  double v27; // st3
  double v28; // st7
  int v29; // [esp+20h] [ebp-2Ch] BYREF
  float v30; // [esp+24h] [ebp-28h]
  float v31; // [esp+28h] [ebp-24h]
  float v32; // [esp+2Ch] [ebp-20h]
  float v33; // [esp+30h] [ebp-1Ch]
  int v34; // [esp+34h] [ebp-18h]
  float v35; // [esp+38h] [ebp-14h]
  float v36; // [esp+3Ch] [ebp-10h]
  float v37; // [esp+40h] [ebp-Ch]
  float v38; // [esp+44h] [ebp-8h]
  int v39; // [esp+48h] [ebp-4h]
  int v40; // [esp+54h] [ebp+8h]
  int v41; // [esp+54h] [ebp+8h]
  float v42; // [esp+54h] [ebp+8h]
  float v43; // [esp+54h] [ebp+8h]
  float v44; // [esp+54h] [ebp+8h]
  float v45; // [esp+54h] [ebp+8h]
  float v46; // [esp+54h] [ebp+8h]
  float v47; // [esp+54h] [ebp+8h]
  float v48; // [esp+54h] [ebp+8h]
  float v49; // [esp+54h] [ebp+8h]
  float v50; // [esp+54h] [ebp+8h]
  float v51; // [esp+54h] [ebp+8h]
  float v52; // [esp+54h] [ebp+8h]
  float v53; // [esp+54h] [ebp+8h]
  float v54; // [esp+54h] [ebp+8h]
  float v55; // [esp+54h] [ebp+8h]
  float v56; // [esp+54h] [ebp+8h]
  float v57; // [esp+58h] [ebp+Ch]
  float v58; // [esp+58h] [ebp+Ch]
  float v59; // [esp+58h] [ebp+Ch]
  float v60; // [esp+58h] [ebp+Ch]
  float v61; // [esp+58h] [ebp+Ch]
  float v62; // [esp+58h] [ebp+Ch]
  float v63; // [esp+58h] [ebp+Ch]
  float v64; // [esp+58h] [ebp+Ch]
  float v65; // [esp+58h] [ebp+Ch]
  float v66; // [esp+58h] [ebp+Ch]
  float v67; // [esp+58h] [ebp+Ch]
  float v68; // [esp+58h] [ebp+Ch]
  float v69; // [esp+58h] [ebp+Ch]

  v3 = *(__int16 *)(a1 + 16);
  v5 = a1 + 48;
  *(_DWORD *)(a2 + 4) = v3;
  *(_DWORD *)a2 = *(_DWORD *)a1;
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 44);
  *(_WORD *)(a2 + 16) = *(_WORD *)(a1 + 22);
  result = a1 + *(_DWORD *)(a1 + 8);
  v34 = a1 + 48;
  v7 = a2 + 32;
  v39 = result;
  if ( v3 > 0 )
  {
    v8 = 3.0;
    do
    {
      *(_DWORD *)(v7 + 64) = *(_DWORD *)(v5 + 20);
      *(_DWORD *)(v7 + 68) = *(_DWORD *)(v5 + 24);
      *(_DWORD *)(v7 + 72) = *(_DWORD *)(v5 + 28);
      *(_DWORD *)v7 = *(_DWORD *)v5;
      *(_DWORD *)(v7 + 4) = *(_DWORD *)(v5 + 4);
      *(_DWORD *)(v7 + 8) = *(_DWORD *)(v5 + 8);
      v9 = 3 * *(__int16 *)(v5 + 12);
      v10 = *(__int16 *)(v39 + 6 * *(__int16 *)(v5 + 12) + 2);
      v38 = (float)*(__int16 *)(v39 + 6 * *(__int16 *)(v5 + 12));
      v40 = v10;
      v11 = *(__int16 *)(v39 + 2 * v9 + 4);
      v33 = (float)v40;
      v41 = v11;
      v12 = *(__int16 *)(v5 + 14);
      v31 = (float)v41;
      v42 = (float)*(__int16 *)(v39 + 6 * v12);
      v57 = (float)*(__int16 *)(v39 + 6 * v12 + 2);
      LODWORD(v35) = *(__int16 *)(v39 + 6 * v12 + 4);
      v13 = *(__int16 *)(v5 + 16);
      v32 = (float)SLODWORD(v35);
      LODWORD(v35) = *(__int16 *)(v39 + 6 * v13);
      v14 = (double)SLODWORD(v35);
      LODWORD(v35) = *(__int16 *)(v39 + 6 * v13 + 2);
      v15 = *(__int16 *)(v39 + 6 * v13 + 4);
      v36 = v14;
      v35 = (float)SLODWORD(v35);
      v30 = (float)v15;
      v16 = v38;
      v37 = (v42 + v38 + v36) / v8;
      v17 = v33;
      v33 = (v57 + v33 + v35) / v8;
      v18 = v32;
      v19 = v30;
      v20 = (v32 + v31 + v30) / v8;
      v21 = v31;
      v38 = v20;
      v22 = v37;
      *(float *)(v7 + 80) = v37;
      v23 = v33;
      *(float *)(v7 + 84) = v33;
      *(float *)(v7 + 88) = v38;
      *(float *)(v7 + 16) = v16 - v22;
      v24 = v19;
      *(float *)(v7 + 20) = v17 - v23;
      v25 = v21 - v38;
      v26 = v38;
      *(float *)(v7 + 24) = v25;
      v27 = v37;
      *(float *)(v7 + 32) = v42 - v37;
      *(float *)(v7 + 36) = v57 - v23;
      *(float *)(v7 + 40) = v18 - v26;
      *(float *)(v7 + 48) = v36 - v27;
      *(float *)(v7 + 52) = v35 - v23;
      *(float *)(v7 + 56) = v24 - v26;
      v43 = (float)a3[3];
      v58 = (float)a3[6];
      sub_7E6610(v58);
      *(float *)(v7 + 96) = v58 + v43;
      v44 = (float)a3[4];
      v59 = (float)a3[7];
      sub_7E6610(v59);
      *(float *)(v7 + 100) = v59 + v44;
      v45 = (float)a3[5];
      v60 = (float)a3[8];
      sub_7E6610(v60);
      *(float *)(v7 + 104) = v60 + v45;
      v46 = (float)a3[9];
      v61 = (float)a3[12];
      sub_7E6610(v61);
      *(float *)(v7 + 112) = v61 + v46;
      v47 = (float)a3[10];
      v62 = (float)a3[13];
      sub_7E6610(v62);
      *(float *)(v7 + 116) = v62 + v47;
      v48 = (float)a3[11];
      v63 = (float)a3[14];
      sub_7E6610(v63);
      *(float *)(v7 + 120) = v63 + v48;
      *(float *)(v7 + 136) = 0.0;
      *(float *)(v7 + 132) = 0.0;
      *(float *)(v7 + 128) = 0.0;
      v49 = (float)a3[15];
      v64 = (float)a3[18];
      sub_7E6610(v64);
      *(float *)(v7 + 144) = v64 + v49;
      v50 = (float)a3[16];
      v65 = (float)a3[19];
      sub_7E6610(v65);
      *(float *)(v7 + 148) = v65 + v50;
      v51 = (float)a3[17];
      v66 = (float)a3[20];
      sub_7E6610(v66);
      *(float *)(v7 + 152) = v66 + v51;
      v52 = (float)a3[21];
      v67 = (float)a3[24];
      sub_7E6610(v67);
      *(float *)(v7 + 160) = v67 + v52;
      v53 = (float)a3[22];
      v68 = (float)a3[25];
      sub_7E6610(v68);
      *(float *)(v7 + 164) = v68 + v53;
      v54 = (float)a3[23];
      v69 = (float)a3[26];
      sub_7E6610(v69);
      *(float *)(v7 + 168) = v69 + v54;
      *(_DWORD *)(v7 + 176) = a3[27];
      *(_DWORD *)(v7 + 180) = a3[28] + sub_7E5C50(a3[29]);
      if ( *(_WORD *)(a2 + 18) == 1 )
      {
        sub_7E7DE0(0.0, 0.0, v37, v38, (int)&v29);
        *(float *)(v7 + 80) = *(float *)&v29;
        *(float *)(v7 + 88) = 0.0;
      }
      result = a3[2];
      v55 = (float)result;
      v56 = v55 * 0.000244140625;
      v28 = v56;
      if ( !*(_WORD *)(a2 + 18) )
      {
        *(float *)(v7 + 96) = *(float *)(v7 + 96) * v28;
        *(float *)(v7 + 100) = *(float *)(v7 + 100) * v28;
        *(float *)(v7 + 104) = *(float *)(v7 + 104) * v28;
        *(float *)(v7 + 112) = v28 * *(float *)(v7 + 112);
        *(float *)(v7 + 116) = *(float *)(v7 + 116) * v28;
        *(float *)(v7 + 120) = *(float *)(v7 + 120) * v28;
      }
      if ( *(_WORD *)(a2 + 18) == 1 )
      {
        *(float *)(v7 + 96) = *(float *)(v7 + 96) * v28;
        *(float *)(v7 + 100) = *(float *)(v7 + 100) * v28;
        *(float *)(v7 + 112) = v28 * *(float *)(v7 + 112);
        *(float *)(v7 + 116) = v28 * *(float *)(v7 + 116);
      }
      v8 = 3.0;
      v5 = v34 + 32;
      --v3;
      v7 += 256;
      v34 += 32;
    }
    while ( v3 > 0 );
  }
  return result;
}

