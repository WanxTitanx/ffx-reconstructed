// Function: sub_A51720
// Address: 0xa51720
// Size: 0xa68
// Prototype: 

void __cdecl sub_A51720(int a1, _DWORD *a2, int a3)
{
  double v3; // st6
  double v4; // st5
  double v5; // st5
  double v6; // st6
  int n2; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  _DWORD *v11; // ebx
  int v12; // eax
  double v13; // st6
  double v14; // st5
  double v15; // st5
  double v16; // st6
  _DWORD *v17; // edx
  double v18; // st7
  bool v19; // zf
  float v20; // [esp+10h] [ebp-A8h]
  float v21; // [esp+14h] [ebp-A4h]
  float v22; // [esp+14h] [ebp-A4h]
  float v23; // [esp+14h] [ebp-A4h]
  float v24; // [esp+14h] [ebp-A4h]
  float v25; // [esp+14h] [ebp-A4h]
  float v26; // [esp+14h] [ebp-A4h]
  float v27; // [esp+14h] [ebp-A4h]
  float v28; // [esp+14h] [ebp-A4h]
  float v29; // [esp+18h] [ebp-A0h]
  float v30; // [esp+18h] [ebp-A0h]
  float v31; // [esp+18h] [ebp-A0h]
  float v32; // [esp+18h] [ebp-A0h]
  float v33; // [esp+18h] [ebp-A0h]
  float v34; // [esp+18h] [ebp-A0h]
  float v35; // [esp+18h] [ebp-A0h]
  float v36; // [esp+18h] [ebp-A0h]
  float v37; // [esp+18h] [ebp-A0h]
  float v38; // [esp+18h] [ebp-A0h]
  float v39; // [esp+18h] [ebp-A0h]
  float v40; // [esp+18h] [ebp-A0h]
  int v41[2]; // [esp+1Ch] [ebp-9Ch] BYREF
  float v42; // [esp+24h] [ebp-94h]
  float v43; // [esp+28h] [ebp-90h]
  int n64; // [esp+2Ch] [ebp-8Ch]
  int n64_1; // [esp+30h] [ebp-88h]
  int n64_2; // [esp+34h] [ebp-84h]
  int n128; // [esp+38h] [ebp-80h]
  float v48; // [esp+3Ch] [ebp-7Ch]
  float v49; // [esp+40h] [ebp-78h]
  float v50; // [esp+44h] [ebp-74h]
  float v51; // [esp+48h] [ebp-70h]
  int n64_3; // [esp+4Ch] [ebp-6Ch]
  int n64_4; // [esp+50h] [ebp-68h]
  int n64_5; // [esp+54h] [ebp-64h]
  int n128_1; // [esp+58h] [ebp-60h]
  float v56; // [esp+5Ch] [ebp-5Ch]
  float v57; // [esp+60h] [ebp-58h]
  float v58; // [esp+64h] [ebp-54h]
  float v59; // [esp+68h] [ebp-50h]
  int n64_6; // [esp+6Ch] [ebp-4Ch]
  int n64_7; // [esp+70h] [ebp-48h]
  int n64_8; // [esp+74h] [ebp-44h]
  int n128_2; // [esp+78h] [ebp-40h]
  float v64; // [esp+7Ch] [ebp-3Ch]
  float v65; // [esp+80h] [ebp-38h]
  float v66; // [esp+84h] [ebp-34h]
  float v67; // [esp+88h] [ebp-30h]
  int n64_9; // [esp+8Ch] [ebp-2Ch]
  int n64_10; // [esp+90h] [ebp-28h]
  int n64_11; // [esp+94h] [ebp-24h]
  int n128_3; // [esp+98h] [ebp-20h]
  int v72; // [esp+ACh] [ebp-Ch]
  int v73; // [esp+B0h] [ebp-8h]
  int v74; // [esp+C8h] [ebp+10h]

  v20 = *(float *)(dword_2305834[0] + 70480) * 0.699999988079071;
  *(_DWORD *)a1 = *a2;
  *(_DWORD *)(a1 + 4) = a2[1];
  *(float *)(a1 + 8) = 0.0;
  *(float *)(a1 + 12) = 1.0;
  v72 = 0;
  v73 = 0;
  sub_6ED420(a1 + 48, dword_2305834[0] + 70624, a1);
  if ( *(float *)(a1 + 60) > 0.0 )
  {
    sub_6ED560(a1 + 48, a1 + 48, *(float *)(a1 + 60));
    *(_DWORD *)(a1 + 16) = a2[2];
    *(_DWORD *)(a1 + 20) = a2[3];
    *(float *)(a1 + 24) = 0.0;
    *(float *)(a1 + 28) = 1.0;
    sub_6ED420(a1 + 64, dword_2305834[0] + 70880, a1 + 16);
    sub_6ED560(a1 + 64, a1 + 64, *(float *)(a1 + 60));
    *(_DWORD *)(a1 + 32) = a2[4];
    *(_DWORD *)(a1 + 36) = a2[5];
    *(float *)(a1 + 40) = 0.0;
    *(float *)(a1 + 44) = 1.0;
    sub_6ED420(a1 + 80, dword_2305834[0] + 70880, a1 + 32);
    sub_6ED560(a1 + 80, a1 + 80, *(float *)(a1 + 60));
    *(_DWORD *)(a1 + 96) = (int)(*(float *)(a1 + 48) * 16.0);
    *(_DWORD *)(a1 + 100) = (int)(*(float *)(a1 + 52) * 16.0);
    *(_DWORD *)(a1 + 112) = (int)(*(float *)(a1 + 64) * 16.0);
    *(_DWORD *)(a1 + 116) = (int)(*(float *)(a1 + 68) * 16.0);
    v3 = *(float *)(a1 + 64) + *(float *)(a1 + 64);
    *(_DWORD *)(a1 + 112) += *(_DWORD *)(a1 + 96);
    *(_DWORD *)(a1 + 116) += *(_DWORD *)(a1 + 100);
    v21 = v3;
    *(float *)(a1 + 64) = v21;
    *(float *)(a1 + 68) = *(float *)(a1 + 68) + *(float *)(a1 + 68);
    *(_DWORD *)(a1 + 144) = (int)(v21 * 16.0);
    *(_DWORD *)(a1 + 148) = (int)(*(float *)(a1 + 68) * 16.0);
    v22 = (float)*(int *)(a1 + 144);
    v4 = (double)*(int *)(a1 + 148);
    *(_DWORD *)(a1 + 144) = *(_DWORD *)(a1 + 96) + (int)(v22 / v20);
    v23 = v4;
    *(_DWORD *)(a1 + 148) = *(_DWORD *)(a1 + 100) + (int)(v23 / v20);
    *(_DWORD *)(a1 + 128) = (int)(*(float *)(a1 + 80) * 16.0);
    *(_DWORD *)(a1 + 132) = (int)(*(float *)(a1 + 84) * 16.0);
    v5 = *(float *)(a1 + 80) + *(float *)(a1 + 80);
    *(_DWORD *)(a1 + 128) += *(_DWORD *)(a1 + 96);
    *(_DWORD *)(a1 + 132) += *(_DWORD *)(a1 + 100);
    v24 = v5;
    *(float *)(a1 + 80) = v24;
    *(float *)(a1 + 84) = *(float *)(a1 + 84) + *(float *)(a1 + 84);
    *(_DWORD *)(a1 + 160) = (int)(v24 * 16.0);
    *(_DWORD *)(a1 + 164) = (int)(16.0 * *(float *)(a1 + 84));
    v25 = (float)*(int *)(a1 + 160);
    v6 = (double)*(int *)(a1 + 164);
    *(_DWORD *)(a1 + 160) = *(_DWORD *)(a1 + 96) + (int)(v25 / v20);
    v26 = v6;
    *(_DWORD *)(a1 + 164) = *(_DWORD *)(a1 + 100) + (int)(v26 / v20);
    while ( (word_23056E8 & 0x100) != 0 )
      ;
    n2 = 2;
    do
    {
      v8 = unk_1A860F0;
      v9 = (*(_DWORD *)(a1 + 480) << 15) | 0x30004000;
      *unk_1A860F0 = 32773;
      v10 = unk_1A860F0;
      *(_DWORD *)(v8 + 8) = 1374;
      *(_DWORD *)(v10 + 4) = v9;
      *(_DWORD *)(v8 + 12) = 0;
      *(_QWORD *)(v8 + 16) = *(int *)(a1 + 320);
      *(_DWORD *)(v8 + 24) = 1;
      *(_DWORD *)(v8 + 28) = 0;
      *(_QWORD *)(v8 + 64) = *(int *)(a1 + 324);
      *(_DWORD *)(v8 + 72) = 1;
      *(_DWORD *)(v8 + 76) = 0;
      *(_QWORD *)(v8 + 112) = *(int *)(a1 + 328);
      *(_DWORD *)(v8 + 120) = 1;
      *(_DWORD *)(v8 + 124) = 0;
      *(_QWORD *)(v8 + 160) = *(int *)(a1 + 332);
      *(_DWORD *)(v8 + 168) = 1;
      *(_DWORD *)(v8 + 172) = 0;
      *(_QWORD *)(v8 + 208) = *(int *)(a1 + 336);
      *(_DWORD *)(v8 + 216) = 1;
      *(_DWORD *)(v8 + 220) = 0;
      *(_DWORD *)(v8 + 40) = *(_DWORD *)(a1 + 484);
      *(_DWORD *)(v8 + 44) = 0x8000;
      *(_DWORD *)(v8 + 56) = *(_DWORD *)(a1 + 484);
      *(_DWORD *)(v8 + 60) = 0;
      *(_DWORD *)(v8 + 88) = *(_DWORD *)(a1 + 484);
      *(_DWORD *)(v8 + 92) = 0;
      *(_DWORD *)(v8 + 104) = *(_DWORD *)(a1 + 484);
      *(_DWORD *)(v8 + 108) = 0;
      *(_DWORD *)(v8 + 136) = *(_DWORD *)(a1 + 488);
      *(_DWORD *)(v8 + 140) = 0;
      *(_DWORD *)(v8 + 152) = *(_DWORD *)(a1 + 488);
      *(_DWORD *)(v8 + 156) = 0;
      *(_DWORD *)(v8 + 184) = *(_DWORD *)(a1 + 488);
      *(_DWORD *)(v8 + 188) = 0;
      *(_DWORD *)(v8 + 200) = *(_DWORD *)(a1 + 488);
      *(_DWORD *)(v8 + 204) = 0;
      *(_DWORD *)(v8 + 232) = *(_DWORD *)(a1 + 484);
      *(_DWORD *)(v8 + 236) = 0;
      *(_DWORD *)(v8 + 248) = *(_DWORD *)(a1 + 484);
      *(_DWORD *)(v8 + 252) = 0;
      --n2;
    }
    while ( n2 );
    v74 = a3 - 1;
    v11 = a2 + 4;
    do
    {
      v12 = v11[2];
      v11 += 6;
      *(_DWORD *)a1 = v12;
      *(_DWORD *)(a1 + 4) = *(v11 - 3);
      sub_6ED420(a1 + 48, dword_2305834[0] + 70624, a1);
      if ( *(float *)(a1 + 60) <= 0.0 )
        break;
      sub_6ED560(a1 + 48, a1 + 48, *(float *)(a1 + 60));
      *(_DWORD *)(a1 + 16) = *(v11 - 2);
      *(_DWORD *)(a1 + 20) = *(v11 - 1);
      sub_6ED420(a1 + 64, dword_2305834[0] + 70880, a1 + 16);
      sub_6ED560(a1 + 64, a1 + 64, *(float *)(a1 + 60));
      *(_DWORD *)(a1 + 32) = *v11;
      *(_DWORD *)(a1 + 36) = v11[1];
      sub_6ED420(a1 + 80, dword_2305834[0] + 70880, a1 + 32);
      sub_6ED560(a1 + 80, a1 + 80, *(float *)(a1 + 60));
      *(_DWORD *)(a1 + 208) = (int)(*(float *)(a1 + 48) * 16.0);
      *(_DWORD *)(a1 + 212) = (int)(*(float *)(a1 + 52) * 16.0);
      *(_DWORD *)(a1 + 224) = (int)(*(float *)(a1 + 64) * 16.0);
      *(_DWORD *)(a1 + 228) = (int)(*(float *)(a1 + 68) * 16.0);
      v13 = *(float *)(a1 + 64) + *(float *)(a1 + 64);
      *(_DWORD *)(a1 + 224) += *(_DWORD *)(a1 + 208);
      *(_DWORD *)(a1 + 228) += *(_DWORD *)(a1 + 212);
      v27 = v13;
      *(float *)(a1 + 64) = v27;
      *(float *)(a1 + 68) = *(float *)(a1 + 68) + *(float *)(a1 + 68);
      *(_DWORD *)(a1 + 256) = (int)(v27 * 16.0);
      *(_DWORD *)(a1 + 260) = (int)(*(float *)(a1 + 68) * 16.0);
      v29 = (float)*(int *)(a1 + 256);
      v14 = (double)*(int *)(a1 + 260);
      *(_DWORD *)(a1 + 256) = *(_DWORD *)(a1 + 208) + (int)(v29 / v20);
      v30 = v14;
      *(_DWORD *)(a1 + 260) = *(_DWORD *)(a1 + 212) + (int)(v30 / v20);
      *(_DWORD *)(a1 + 240) = (int)(*(float *)(a1 + 80) * 16.0);
      *(_DWORD *)(a1 + 244) = (int)(*(float *)(a1 + 84) * 16.0);
      v15 = *(float *)(a1 + 80) + *(float *)(a1 + 80);
      *(_DWORD *)(a1 + 240) += *(_DWORD *)(a1 + 208);
      *(_DWORD *)(a1 + 244) += *(_DWORD *)(a1 + 212);
      v28 = v15;
      *(float *)(a1 + 80) = v28;
      *(float *)(a1 + 84) = *(float *)(a1 + 84) + *(float *)(a1 + 84);
      *(_DWORD *)(a1 + 272) = (int)(v28 * 16.0);
      *(_DWORD *)(a1 + 276) = (int)(16.0 * *(float *)(a1 + 84));
      v31 = (float)*(int *)(a1 + 272);
      v16 = (double)*(int *)(a1 + 276);
      *(_DWORD *)(a1 + 272) = *(_DWORD *)(a1 + 208) + (int)(v31 / v20);
      v32 = v16;
      *(_DWORD *)(a1 + 276) = *(_DWORD *)(a1 + 212) + (int)(v32 / v20);
      v17 = (_DWORD *)unk_1A860F0;
      *(_DWORD *)(unk_1A860F0 + 32) = *(_DWORD *)(a1 + 112);
      *(_DWORD *)(unk_1A860F0 + 36) = *(_DWORD *)(a1 + 116);
      v17[12] = *(_DWORD *)(a1 + 224);
      v17[13] = *(_DWORD *)(a1 + 228);
      v17[20] = *(_DWORD *)(a1 + 128);
      v17[21] = *(_DWORD *)(a1 + 132);
      v17[24] = *(_DWORD *)(a1 + 240);
      v17[25] = *(_DWORD *)(a1 + 244);
      v17[32] = *(_DWORD *)(a1 + 144);
      v17[33] = *(_DWORD *)(a1 + 148);
      v17[36] = *(_DWORD *)(a1 + 256);
      v18 = (double)(int)v17[32];
      v17[37] = *(_DWORD *)(a1 + 260);
      v17[44] = *(_DWORD *)(a1 + 160);
      v17[45] = *(_DWORD *)(a1 + 164);
      v17[48] = *(_DWORD *)(a1 + 272);
      v17[49] = *(_DWORD *)(a1 + 276);
      v17[56] = *(_DWORD *)(a1 + 96);
      v17[57] = *(_DWORD *)(a1 + 100);
      v17[60] = *(_DWORD *)(a1 + 208);
      v17[61] = *(_DWORD *)(a1 + 212);
      v33 = v18;
      *(float *)v41 = v33 * 0.0625 - 2048.0 + 256.0;
      v34 = (float)(int)v17[33];
      *(float *)&v41[1] = v34 * 0.0625 - 2048.0 + 208.0;
      v35 = (float)(int)v17[36];
      v48 = v35 * 0.0625 - 2048.0 + 256.0;
      v36 = (float)(int)v17[37];
      n64 = 64;
      n64_1 = 64;
      n64_2 = 64;
      n128 = 128;
      n64_3 = 64;
      n64_4 = 64;
      n64_5 = 64;
      n128_1 = 128;
      v49 = v36 * 0.0625 - 2048.0 + 208.0;
      v42 = 0.03125;
      v43 = 0.125;
      v50 = 0.109375;
      v51 = 0.125;
      v37 = (float)(int)v17[44];
      v56 = v37 * 0.0625 - 2048.0 + 256.0;
      v38 = (float)(int)v17[45];
      v57 = v38 * 0.0625 - 2048.0 + 208.0;
      v39 = (float)(int)v17[48];
      v64 = v39 * 0.0625 - 2048.0 + 256.0;
      v40 = (float)(int)v17[49];
      n64_6 = 64;
      n64_7 = 64;
      n64_8 = 64;
      n128_2 = 128;
      n64_9 = 64;
      n64_10 = 64;
      n64_11 = 64;
      n128_3 = 128;
      v65 = 0.0625 * v40 - 2048.0 + 208.0;
      v58 = 0.03125;
      v59 = 0.234375;
      v67 = 0.234375;
      v66 = 0.109375;
      sub_63EAE0((int)v41, 0, 9);
      v42 = 0.03125;
      v43 = 0.0;
      v50 = 0.109375;
      v59 = 0.109375;
      v66 = 0.109375;
      v67 = 0.109375;
      v51 = 0.0;
      v58 = 0.03125;
      sub_63EAE0((int)v41, 0, 12);
      *(_DWORD *)(a1 + 96) = *(_DWORD *)(a1 + 208);
      *(_DWORD *)(a1 + 100) = *(_DWORD *)(a1 + 212);
      *(_DWORD *)(a1 + 104) = *(_DWORD *)(a1 + 216);
      *(_DWORD *)(a1 + 108) = *(_DWORD *)(a1 + 220);
      *(_DWORD *)(a1 + 112) = *(_DWORD *)(a1 + 224);
      *(_DWORD *)(a1 + 116) = *(_DWORD *)(a1 + 228);
      *(_DWORD *)(a1 + 120) = *(_DWORD *)(a1 + 232);
      *(_DWORD *)(a1 + 124) = *(_DWORD *)(a1 + 236);
      *(_DWORD *)(a1 + 128) = *(_DWORD *)(a1 + 240);
      *(_DWORD *)(a1 + 132) = *(_DWORD *)(a1 + 244);
      *(_DWORD *)(a1 + 136) = *(_DWORD *)(a1 + 248);
      *(_DWORD *)(a1 + 140) = *(_DWORD *)(a1 + 252);
      *(_DWORD *)(a1 + 144) = *(_DWORD *)(a1 + 256);
      *(_DWORD *)(a1 + 148) = *(_DWORD *)(a1 + 260);
      v19 = v74-- == 1;
      *(_DWORD *)(a1 + 152) = *(_DWORD *)(a1 + 264);
      *(_DWORD *)(a1 + 156) = *(_DWORD *)(a1 + 268);
      *(_DWORD *)(a1 + 160) = *(_DWORD *)(a1 + 272);
      *(_DWORD *)(a1 + 164) = *(_DWORD *)(a1 + 276);
      *(_DWORD *)(a1 + 168) = *(_DWORD *)(a1 + 280);
      *(_DWORD *)(a1 + 172) = *(_DWORD *)(a1 + 284);
    }
    while ( !v19 );
  }
}

