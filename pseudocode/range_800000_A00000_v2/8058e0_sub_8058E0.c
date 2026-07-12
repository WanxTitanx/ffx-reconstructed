// Function: sub_8058E0
// Address: 0x8058e0
int __cdecl sub_8058E0(int *a1, int a2, __int16 *a3, float *a4)
{
  int v4; // ebx
  float v5; // ecx
  _DWORD *v6; // ecx
  int result; // eax
  int *v8; // esi
  int v9; // eax
  int v10; // eax
  __int16 *i_4; // esi
  int v12; // edi
  bool v13; // zf
  int v14; // ecx
  int n4096; // eax
  __int16 *i_1; // edx
  float *v17; // esi
  int v18; // eax
  double v19; // st7
  int v20; // eax
  double v21; // st7
  int v22; // eax
  double v23; // st6
  float *v24; // ebx
  float *v25; // eax
  double v26; // st5
  float *v27; // edi
  float *v28; // esi
  double v29; // st7
  double v30; // st4
  double v31; // st3
  double v32; // st2
  float v33; // esi
  float *v34; // eax
  float *v35; // eax
  __int16 *v36; // ebx
  double v37; // st7
  double v38; // st7
  double v39; // st7
  double v40; // st7
  double v41; // st7
  double v42; // st7
  double v43; // st7
  double v44; // st7
  double v45; // st7
  double v46; // st7
  double v47; // st7
  double v48; // st7
  __int16 *i_2; // ecx
  int v50; // ebx
  __int16 *i_5; // edx
  int v52; // eax
  int *v53; // esi
  int v54; // [esp-Ch] [ebp-1A0h]
  char v55[4]; // [esp+10h] [ebp-184h] BYREF
  char v56[4]; // [esp+14h] [ebp-180h] BYREF
  int *v57; // [esp+18h] [ebp-17Ch]
  float *v58; // [esp+1Ch] [ebp-178h]
  int v59; // [esp+20h] [ebp-174h]
  __int16 *v60; // [esp+24h] [ebp-170h]
  float v61; // [esp+28h] [ebp-16Ch]
  float v62; // [esp+2Ch] [ebp-168h]
  float v63; // [esp+30h] [ebp-164h]
  float v64; // [esp+34h] [ebp-160h]
  int v65; // [esp+3Ch] [ebp-158h]
  float v66; // [esp+40h] [ebp-154h]
  int v67; // [esp+44h] [ebp-150h]
  int *v68; // [esp+48h] [ebp-14Ch]
  float v69; // [esp+4Ch] [ebp-148h]
  float v70; // [esp+50h] [ebp-144h]
  int v71; // [esp+54h] [ebp-140h]
  __int16 *i_3; // [esp+58h] [ebp-13Ch]
  float v73; // [esp+5Ch] [ebp-138h]
  __int16 *i; // [esp+60h] [ebp-134h]
  float v75; // [esp+64h] [ebp-130h]
  float v76; // [esp+68h] [ebp-12Ch]
  float v77; // [esp+6Ch] [ebp-128h]
  float v78; // [esp+70h] [ebp-124h]
  float v79; // [esp+74h] [ebp-120h]
  double v80; // [esp+78h] [ebp-11Ch]
  char v81[80]; // [esp+80h] [ebp-114h] BYREF
  _BYTE v82[64]; // [esp+D0h] [ebp-C4h] BYREF
  _BYTE v83[48]; // [esp+110h] [ebp-84h] BYREF
  float v84; // [esp+140h] [ebp-54h]
  float v85; // [esp+144h] [ebp-50h]
  float v86; // [esp+148h] [ebp-4Ch]
  _BYTE v87[48]; // [esp+150h] [ebp-44h] BYREF
  float v88; // [esp+180h] [ebp-14h]
  float v89; // [esp+184h] [ebp-10h]
  float v90; // [esp+188h] [ebp-Ch]
  float v91; // [esp+18Ch] [ebp-8h]

  v4 = a2;
  v5 = *a4;
  *(_DWORD *)(a2 + 12) = a3;
  v60 = a3;
  *(_DWORD *)(a2 + 4) = 0;
  *(float *)(a2 + 32) = a4[2];
  *(_DWORD *)(a2 + 8) = a1;
  v54 = *a1;
  v57 = a1;
  v59 = a2;
  v58 = a4;
  v61 = v5;
  sub_833EE0(v54, v56, v55, v81);
  v6 = (_DWORD *)*((_DWORD *)a4 + 1);
  *(_DWORD *)(a2 + 16) = *v6;
  *(_DWORD *)(a2 + 20) = v6[1];
  *(_DWORD *)(a2 + 24) = v6[2];
  *(_DWORD *)(a2 + 28) = v6[3];
  LODWORD(v78) = a2 + 48;
  result = 0;
  v8 = a1 + 4;
  v68 = a1 + 4;
  v71 = 0;
  if ( *((_WORD *)a1 + 2) )
  {
    do
    {
      v9 = unknown_libname_741(v8[1]);
      sub_6ED4A0(v83, v9);
      v84 = v84 * 1000.0;
      v85 = v85 * 1000.0;
      v86 = 1000.0 * v86;
      sub_7E82C0(v82, LODWORD(v61), v83);
      v10 = unknown_libname_741(*v8);
      i_4 = (__int16 *)(v10 + 32);
      v12 = v10 + *(_DWORD *)(v10 + 8);
      v13 = *(_BYTE *)(v10 + 33) == 0xFF;
      v65 = v12;
      for ( i = (__int16 *)(v10 + 32); !v13; i = i_1 )
      {
        if ( *((_BYTE *)i_4 + 1) != 16 )
        {
          nullsub_34();
          nullsub_35(1);
        }
        v14 = i_4[1];
        n4096 = v14 + *(_DWORD *)(v4 + 4);
        i_1 = i_4 + 16;
        i_3 = i_4 + 16;
        if ( n4096 >= 4096 )
        {
          i_1 += 14 * v14;
        }
        else
        {
          *(_DWORD *)(v4 + 4) = n4096;
          v67 = 0;
          if ( i_4[1] > 0 )
          {
            *(float *)&v17 = v78;
            do
            {
              LODWORD(v79) = (unsigned __int16)i_1[4];
              v80 = (double)SLODWORD(v79);
              v17[12] = v80 * 0.000244140625;
              LODWORD(v79) = (unsigned __int16)i_1[5];
              v80 = (double)SLODWORD(v79);
              v17[13] = v80 * 0.000244140625;
              LODWORD(v79) = (unsigned __int16)i_1[6];
              v80 = (double)SLODWORD(v79);
              v17[16] = v80 * 0.000244140625;
              LODWORD(v79) = (unsigned __int16)i_1[7];
              v80 = (double)SLODWORD(v79);
              v17[17] = v80 * 0.000244140625;
              LODWORD(v79) = (unsigned __int16)i_1[8];
              v80 = (double)SLODWORD(v79);
              v17[20] = v80 * 0.000244140625;
              LODWORD(v79) = (unsigned __int16)i_1[9];
              v80 = (double)SLODWORD(v79);
              v17[21] = 0.000244140625 * v80;
              v18 = 2 * *i_1;
              v75 = *(float *)(v12 + 16 * *i_1);
              v76 = *(float *)(v12 + 8 * v18 + 4);
              v19 = *(float *)(v12 + 8 * v18 + 8);
              v20 = i_1[1];
              *((float *)&v80 + 1) = v19;
              v20 *= 2;
              v77 = *(float *)(v12 + 8 * v20);
              v73 = *(float *)(v12 + 8 * v20 + 4);
              v21 = *(float *)(v12 + 8 * v20 + 8);
              v22 = i_1[2];
              v66 = v21;
              v22 *= 2;
              v70 = *(float *)(v12 + 8 * v22);
              v69 = *(float *)(v12 + 8 * v22 + 4);
              v79 = *(float *)(v12 + 8 * v22 + 8);
              v23 = v75;
              v75 = (v77 + v75 + v70) / 3.0;
              v24 = v17 + 24;
              v25 = (float *)LODWORD(v78);
              v26 = v76;
              v27 = v17 + 4;
              v28 = v17 + 8;
              v76 = (v73 + v76 + v69) / 3.0;
              v29 = *((float *)&v80 + 1);
              *((float *)&v80 + 1) = (v66 + *((float *)&v80 + 1) + v79) / 3.0;
              v30 = v75;
              *v24 = v75;
              v31 = v76;
              v28[17] = v76;
              v32 = *((float *)&v80 + 1);
              v28[18] = *((float *)&v80 + 1);
              *(v28 - 8) = v23 - v30;
              *(v28 - 7) = v26 - v31;
              *(v28 - 6) = v29 - v32;
              *(v28 - 5) = 1.0;
              *v27 = v77 - v30;
              *(v28 - 3) = v73 - v31;
              *(v28 - 2) = v66 - v32;
              *(v28 - 1) = 1.0;
              *v28 = v70 - v30;
              v25[9] = v69 - v31;
              v25[10] = v79 - v32;
              v25[11] = 1.0;
              v25[27] = 1.0;
              sub_6ED4A0(v87, v82);
              v90 = 0.0;
              v89 = 0.0;
              v88 = 0.0;
              v91 = 1.0;
              sub_6ED420(v24, v82, v24);
              sub_6ED420(LODWORD(v78), v87, LODWORD(v78));
              sub_6ED420(v27, v87, v27);
              sub_6ED420(v28, v87, v28);
              v33 = v78;
              v34 = v58;
              *(float *)(LODWORD(v78) + 176) = *(float *)(LODWORD(v78) + 100);
              *(float *)(LODWORD(v33) + 188) = 0.0;
              *(float *)(LODWORD(v33) + 184) = 0.0;
              *(float *)(LODWORD(v33) + 180) = 0.0;
              v35 = (float *)*((_DWORD *)v34 + 1);
              v62 = *v24 - *v35;
              v63 = *(float *)(LODWORD(v33) + 100) - v35[1];
              v64 = *(float *)(LODWORD(v33) + 104) - v35[2];
              *((float *)&v80 + 1) = sqrt(v63 * v63 + v62 * v62 + v64 * v64);
              v36 = v60;
              v37 = *((float *)&v80 + 1);
              *(float *)(LODWORD(v33) + 112) = v62 / *((float *)&v80 + 1);
              *(float *)(LODWORD(v33) + 116) = v63 / v37;
              *(float *)(LODWORD(v33) + 120) = v64 / v37;
              *(float *)(LODWORD(v33) + 124) = v37;
              *(_DWORD *)(LODWORD(v33) + 180) = unk_C8F508[0];
              *(_DWORD *)(LODWORD(v33) + 184) = unk_C8F50C;
              *(_DWORD *)(LODWORD(v33) + 188) = unk_C8F510;
              *(_DWORD *)(LODWORD(v33) + 192) = unk_C8F514;
              *(_DWORD *)(LODWORD(v33) + 144) = unk_C8F508[0];
              *(_DWORD *)(LODWORD(v33) + 148) = unk_C8F50C;
              *(_DWORD *)(LODWORD(v33) + 152) = unk_C8F510;
              *(_DWORD *)(LODWORD(v33) + 156) = unk_C8F514;
              HIDWORD(v80) = v36[2];
              v38 = (double)SHIDWORD(v80);
              HIDWORD(v80) = v36[3];
              v78 = v38;
              v77 = (float)SHIDWORD(v80);
              v39 = v77;
              sub_7E6610(v77);
              *(float *)(LODWORD(v33) + 128) = (v39 + v78) * 0.00390625;
              HIDWORD(v80) = v36[4];
              v40 = (double)SHIDWORD(v80);
              HIDWORD(v80) = v36[5];
              v78 = v40;
              v77 = (float)SHIDWORD(v80);
              v41 = v77;
              sub_7E6610(v77);
              *(float *)(LODWORD(v33) + 132) = (v41 + v78) * 0.00390625;
              HIDWORD(v80) = v36[6];
              v42 = (double)SHIDWORD(v80);
              HIDWORD(v80) = v36[7];
              v78 = v42;
              v77 = (float)SHIDWORD(v80);
              v43 = v77;
              sub_7E6610(v77);
              *(float *)(LODWORD(v33) + 184) = (v43 + v78) * 0.00390625;
              HIDWORD(v80) = v36[8];
              v44 = (double)SHIDWORD(v80);
              HIDWORD(v80) = v36[9];
              v78 = v44;
              v77 = (float)SHIDWORD(v80);
              v45 = v77;
              sub_7E6610(v77);
              *(float *)(LODWORD(v33) + 188) = (v45 + v78) * 0.00390625;
              HIDWORD(v80) = v36[11];
              *((float *)&v80 + 1) = (float)SHIDWORD(v80);
              v46 = *((float *)&v80 + 1);
              sub_7E6610(*((float *)&v80 + 1));
              *(float *)(LODWORD(v33) + 160) = v46;
              HIDWORD(v80) = v36[12];
              *((float *)&v80 + 1) = (float)SHIDWORD(v80);
              v47 = *((float *)&v80 + 1);
              sub_7E6610(*((float *)&v80 + 1));
              *(float *)(LODWORD(v33) + 164) = v47;
              HIDWORD(v80) = v36[13];
              *((float *)&v80 + 1) = (float)SHIDWORD(v80);
              v48 = *((float *)&v80 + 1);
              sub_7E6610(*((float *)&v80 + 1));
              *(float *)(LODWORD(v33) + 168) = v48;
              *(_WORD *)(LODWORD(v33) + 72) = v36[14] + sub_7E5C60(v36[15]) + 16;
              *(_WORD *)(LODWORD(v33) + 74) = 0;
              i_2 = i;
              v50 = v67;
              i_5 = i_3;
              *(_DWORD *)(LODWORD(v33) + 56) = *((_DWORD *)i + 2);
              v12 = v65;
              *(_DWORD *)(LODWORD(v33) + 60) = *((_DWORD *)i_2 + 3);
              *(_BYTE *)(LODWORD(v33) + 88) = *((_BYTE *)i_2 + 4);
              *(_BYTE *)(LODWORD(v33) + 89) = *((_BYTE *)i_2 + 5);
              *(_BYTE *)(LODWORD(v33) + 90) = *((_BYTE *)i_2 + 6);
              *(_BYTE *)(LODWORD(v33) + 91) = *((_BYTE *)i_2 + 7);
              v52 = i_2[1];
              i_1 = i_5 + 14;
              v17 = (float *)(LODWORD(v33) + 192);
              i_3 = i_1;
              v78 = *(float *)&v17;
              v67 = v50 + 1;
            }
            while ( v50 + 1 < v52 );
            v4 = v59;
          }
        }
        v13 = *((_BYTE *)i_1 + 1) == 0xFF;
        i_4 = i_1;
      }
      v53 = v68;
      unknown_libname_741(*v68);
      unknown_libname_741(*v53);
      result = *((unsigned __int16 *)v57 + 2);
      v8 = v53 + 4;
      v68 = v8;
      ++v71;
    }
    while ( v71 < result );
  }
  return result;
}
