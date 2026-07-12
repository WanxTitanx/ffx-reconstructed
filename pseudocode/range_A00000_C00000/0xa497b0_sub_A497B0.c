// Function: sub_A497B0
// Address: 0xa497b0
// Size: 0x75a
// Prototype: 

int sub_A497B0()
{
  _BYTE *v0; // ebx
  double v1; // st7
  double v2; // st6
  double v3; // st5
  double v4; // st4
  int result; // eax
  double v6; // st3
  int n19; // edi
  float *v8; // ecx
  float *v10; // esi
  double v11; // rt0
  _DWORD *v12; // eax
  int v13; // eax
  double v14; // st3
  double v15; // st7
  int v16; // [esp+1Ch] [ebp-1B0h]
  float *v17; // [esp+20h] [ebp-1ACh]
  int n17; // [esp+24h] [ebp-1A8h]
  float v19; // [esp+28h] [ebp-1A4h]
  float v20; // [esp+28h] [ebp-1A4h]
  float v21; // [esp+28h] [ebp-1A4h]
  float v22; // [esp+28h] [ebp-1A4h]
  float v23; // [esp+28h] [ebp-1A4h]
  float v24; // [esp+28h] [ebp-1A4h]
  float v25; // [esp+28h] [ebp-1A4h]
  float v26; // [esp+28h] [ebp-1A4h]
  float v27; // [esp+28h] [ebp-1A4h]
  float v28; // [esp+28h] [ebp-1A4h]
  float v29; // [esp+28h] [ebp-1A4h]
  float v30; // [esp+2Ch] [ebp-1A0h]
  float v31; // [esp+2Ch] [ebp-1A0h]
  float v32; // [esp+2Ch] [ebp-1A0h]
  float v33; // [esp+2Ch] [ebp-1A0h]
  float v34; // [esp+2Ch] [ebp-1A0h]
  float v35; // [esp+2Ch] [ebp-1A0h]
  float v36; // [esp+2Ch] [ebp-1A0h]
  float v37; // [esp+2Ch] [ebp-1A0h]
  float v38; // [esp+2Ch] [ebp-1A0h]
  float v39; // [esp+2Ch] [ebp-1A0h]
  float v40; // [esp+2Ch] [ebp-1A0h]
  float v41; // [esp+2Ch] [ebp-1A0h]
  float v42; // [esp+2Ch] [ebp-1A0h]
  float v43; // [esp+2Ch] [ebp-1A0h]
  float v44; // [esp+2Ch] [ebp-1A0h]
  float v45; // [esp+2Ch] [ebp-1A0h]
  int v46; // [esp+30h] [ebp-19Ch] BYREF
  float v47; // [esp+34h] [ebp-198h]
  float v48; // [esp+38h] [ebp-194h]
  float v49; // [esp+3Ch] [ebp-190h]
  int n128; // [esp+40h] [ebp-18Ch]
  int n128_1; // [esp+44h] [ebp-188h]
  int n128_2; // [esp+48h] [ebp-184h]
  int n64; // [esp+4Ch] [ebp-180h]
  float v54; // [esp+50h] [ebp-17Ch]
  float v55; // [esp+54h] [ebp-178h]
  float v56; // [esp+58h] [ebp-174h]
  float v57; // [esp+5Ch] [ebp-170h]
  int n128_3; // [esp+60h] [ebp-16Ch]
  int n128_4; // [esp+64h] [ebp-168h]
  int n128_5; // [esp+68h] [ebp-164h]
  int n64_1; // [esp+6Ch] [ebp-160h]
  float v62; // [esp+70h] [ebp-15Ch]
  float v63; // [esp+74h] [ebp-158h]
  float v64; // [esp+78h] [ebp-154h]
  float v65; // [esp+7Ch] [ebp-150h]
  int n128_6; // [esp+80h] [ebp-14Ch]
  int n128_7; // [esp+84h] [ebp-148h]
  int n128_8; // [esp+88h] [ebp-144h]
  int n64_2; // [esp+8Ch] [ebp-140h]
  float v70; // [esp+90h] [ebp-13Ch]
  float v71; // [esp+94h] [ebp-138h]
  float v72; // [esp+98h] [ebp-134h]
  float v73; // [esp+9Ch] [ebp-130h]
  int n128_9; // [esp+A0h] [ebp-12Ch]
  int n128_10; // [esp+A4h] [ebp-128h]
  int n128_11; // [esp+A8h] [ebp-124h]
  int n64_3; // [esp+ACh] [ebp-120h]
  int v78; // [esp+C0h] [ebp-10Ch]
  int v79; // [esp+C4h] [ebp-108h]
  char Str[256]; // [esp+C8h] [ebp-104h] BYREF

  v0 = (_BYTE *)(dword_2305834[0] + 77408);
  v78 = 0;
  v79 = 0;
  sub_A4B260();
  v1 = 0.0;
  v2 = 0.0625;
  v3 = 2048.0;
  v4 = 256.0;
  result = dword_2305834[0] + 71724;
  v6 = 208.0;
  n17 = 0;
  v16 = dword_2305834[0] + 71724;
  do
  {
    n19 = 0;
    v8 = (float *)result;
    v17 = (float *)result;
    do
    {
      if ( *v0++ )
      {
        v10 = (float *)dword_1A860EC;
        v11 = v6;
        *dword_1A860EC = 32772;
        v12 = dword_1A860EC;
        *((_DWORD *)v10 + 2) = 1298;
        v12[1] = 805978112;
        v10[3] = 0.0;
        v10[12] = *(v8 - 91);
        v10[13] = *(v8 - 90);
        *((_DWORD *)v10 + 14) = 8448;
        *((_DWORD *)v10 + 15) = 0x8000;
        v10[24] = *(v8 - 87);
        v10[25] = *(v8 - 86);
        *((_DWORD *)v10 + 26) = 8448;
        v10[27] = 0.0;
        v10[36] = *(v8 - 7);
        v10[37] = *(v8 - 6);
        *((_DWORD *)v10 + 38) = 8448;
        v10[39] = 0.0;
        v10[48] = *(v8 - 3);
        v13 = *((_DWORD *)v8 - 2);
        v10[5] = v1;
        v10[4] = v1;
        *((_DWORD *)v10 + 49) = v13;
        *((_DWORD *)v10 + 50) = 8448;
        v10[51] = 0.0;
        v10[6] = *(v8 - 88);
        v10[7] = v1;
        v10[17] = v1;
        v19 = *(v8 - 84);
        v10[18] = v19;
        v10[16] = v19;
        v10[19] = v1;
        v10[28] = v1;
        v20 = *(v8 - 4);
        v10[30] = v20;
        v10[29] = v20;
        v10[31] = v1;
        v21 = *v8;
        *((_DWORD *)v10 + 44) = 64;
        *((_DWORD *)v10 + 32) = 64;
        *((_DWORD *)v10 + 20) = 64;
        v10[42] = v21;
        *((_DWORD *)v10 + 8) = 64;
        *((_DWORD *)v10 + 45) = 64;
        v10[41] = v21;
        *((_DWORD *)v10 + 33) = 64;
        v10[40] = v21;
        *((_DWORD *)v10 + 21) = 64;
        *((_DWORD *)v10 + 9) = 64;
        v10[43] = v1;
        *((_DWORD *)v10 + 46) = 64;
        v14 = (double)*((int *)v10 + 12);
        *((_DWORD *)v10 + 34) = 64;
        *((_DWORD *)v10 + 22) = 64;
        *((_DWORD *)v10 + 10) = 64;
        *((_DWORD *)v10 + 47) = 128;
        *((_DWORD *)v10 + 35) = 128;
        *((_DWORD *)v10 + 23) = 128;
        *((_DWORD *)v10 + 11) = 128;
        v22 = v14;
        *(float *)&v46 = v22 * v2 - v3 + v4;
        v23 = (float)*((int *)v10 + 13);
        v47 = v23 * v2 - v3 + v11;
        v24 = (float)*((int *)v10 + 24);
        v54 = v24 * v2 - v3 + v4;
        v25 = (float)*((int *)v10 + 25);
        v55 = v25 * v2 - v3 + v11;
        v26 = (float)*((int *)v10 + 36);
        v62 = v26 * v2 - v3 + v4;
        v27 = (float)*((int *)v10 + 37);
        v63 = v27 * v2 - v3 + v11;
        v28 = (float)*((int *)v10 + 48);
        v70 = v4 + v28 * v2 - v3;
        v29 = (float)*((int *)v10 + 49);
        v71 = v11 + v2 * v29 - v3;
        v48 = v10[4] / v10[6];
        v49 = v10[5] / v10[6];
        v56 = v10[16] / v10[18];
        v57 = v10[17] / v10[18];
        v64 = v10[28] / v10[30];
        v65 = v10[29] / v10[30];
        v72 = v10[40] / v10[42];
        v15 = v10[41] / v10[42];
        n128 = 128;
        n128_1 = 128;
        n128_2 = 128;
        v73 = v15;
        n64 = 64;
        n128_3 = 128;
        n128_4 = 128;
        n128_5 = 128;
        n64_1 = 64;
        n128_6 = 128;
        n128_7 = 128;
        n128_8 = 128;
        n64_2 = 64;
        n128_9 = 128;
        n128_10 = 128;
        n128_11 = 128;
        n64_3 = 64;
        sub_63EAE0((int)&v46, Str, 1);
        if ( !n17 )
        {
          v30 = (float)*((int *)v10 + 12);
          *(float *)&v46 = v30 * 0.0625 - 2048.0 + 256.0;
          v31 = (float)(2 * *((_DWORD *)v10 + 13) - *((_DWORD *)v10 + 37));
          v47 = v31 * 0.0625 - 2048.0 + 208.0;
          v32 = (float)*((int *)v10 + 24);
          v54 = v32 * 0.0625 - 2048.0 + 256.0;
          v33 = (float)(2 * *((_DWORD *)v10 + 25) - *((_DWORD *)v10 + 49));
          v55 = v33 * 0.0625 - 2048.0 + 208.0;
          v34 = (float)*((int *)v10 + 36);
          v62 = v34 * 0.0625 - 2048.0 + 256.0;
          v35 = (float)*((int *)v10 + 13);
          v63 = v35 * 0.0625 - 2048.0 + 208.0;
          v36 = (float)*((int *)v10 + 48);
          v70 = v36 * 0.0625 - 2048.0 + 256.0;
          v37 = (float)*((int *)v10 + 25);
          v71 = 0.0625 * v37 - 2048.0 + 208.0;
          sub_63EAE0((int)&v46, Str, 1);
        }
        if ( n19 == 19 )
        {
          v38 = (float)*((int *)v10 + 24);
          *(float *)&v46 = v38 * 0.0625 - 2048.0 + 256.0;
          v39 = (float)*((int *)v10 + 13);
          v47 = v39 * 0.0625 - 2048.0 + 208.0;
          v40 = (float)(2 * *((_DWORD *)v10 + 24) - *((_DWORD *)v10 + 12));
          v54 = v40 * 0.0625 - 2048.0 + 256.0;
          v41 = (float)*((int *)v10 + 25);
          v55 = v41 * 0.0625 - 2048.0 + 208.0;
          v42 = (float)*((int *)v10 + 48);
          v62 = v42 * 0.0625 - 2048.0 + 256.0;
          v43 = (float)*((int *)v10 + 37);
          v63 = v43 * 0.0625 - 2048.0 + 208.0;
          v44 = (float)(2 * *((_DWORD *)v10 + 48) - *((_DWORD *)v10 + 36));
          v70 = v44 * 0.0625 - 2048.0 + 256.0;
          v45 = (float)*((int *)v10 + 49);
          v71 = 0.0625 * v45 - 2048.0 + 208.0;
          sub_63EAE0((int)&v46, Str, 1);
        }
        v8 = v17;
        v1 = 0.0;
        v2 = 0.0625;
        v3 = 2048.0;
        v6 = 208.0;
        v4 = 256.0;
      }
      ++n19;
      v8 += 4;
      v17 = v8;
    }
    while ( n19 < 20 );
    result = v16 + 336;
    ++n17;
    v16 += 336;
  }
  while ( n17 < 17 );
  return result;
}

