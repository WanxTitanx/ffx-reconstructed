// Function: sub_A4AC20
// Address: 0xa4ac20
// Size: 0x63e
// Prototype: 

void sub_A4AC20()
{
  _BYTE *v0; // esi
  int v1; // ecx
  double v2; // st6
  double v3; // st5
  double v4; // st2
  double v5; // rt1
  double v6; // st6
  int v7; // eax
  float *v8; // edx
  int n20; // edi
  float *v11; // ecx
  double v12; // st2
  int v13; // eax
  bool v14; // zf
  int v15; // [esp-94h] [ebp-A0h]
  float v16; // [esp-90h] [ebp-9Ch]
  float v17; // [esp-8Ch] [ebp-98h]
  float v18; // [esp-80h] [ebp-8Ch]
  float v19; // [esp-7Ch] [ebp-88h]
  float v20; // [esp-70h] [ebp-7Ch]
  float v21; // [esp-6Ch] [ebp-78h]
  float v22; // [esp-60h] [ebp-6Ch]
  float v23; // [esp-5Ch] [ebp-68h]
  float v24; // [esp-50h] [ebp-5Ch]
  float v25; // [esp-4Ch] [ebp-58h]
  float v26; // [esp-40h] [ebp-4Ch]
  float v27; // [esp-30h] [ebp-3Ch]
  float v28; // [esp-2Ch] [ebp-38h]
  float v29; // [esp-20h] [ebp-2Ch]
  float v30; // [esp-1Ch] [ebp-28h]
  int v31; // [esp-10h] [ebp-1Ch]
  int v32; // [esp-Ch] [ebp-18h]
  int v33; // [esp-8h] [ebp-14h]
  float v34; // [esp-4h] [ebp-10h]
  float v35; // [esp-4h] [ebp-10h]
  float v36; // [esp-4h] [ebp-10h]
  float v37; // [esp-4h] [ebp-10h]
  float v38; // [esp-4h] [ebp-10h]
  float v39; // [esp-4h] [ebp-10h]
  int n17; // [esp-4h] [ebp-10h]

  v0 = (_BYTE *)(dword_2305834[0] + 77408);
  if ( !unk_12FB790 )
  {
    v15 = *(_DWORD *)(sub_639180("NoTexture", 10) + 148);
    v1 = 0;
    v32 = 0;
    v34 = (float)(*(_DWORD *)(dword_2305834[0] + 71320) & 0x1FF);
    v35 = v34 * 0.00390625 - 1.0;
    v2 = v35;
    v16 = v35;
    v17 = v35;
    v36 = v35 + 2.0;
    v18 = v36;
    v21 = v36;
    v22 = v36;
    v23 = v36;
    v3 = v2;
    v19 = v2;
    v20 = v2;
    v37 = 1.0 - v2;
    v24 = v37;
    v25 = v37 + 0.5;
    v4 = v37;
    v38 = v37 + 2.0;
    v26 = v38;
    v27 = v4;
    v5 = v38;
    v39 = v25 + 2.0;
    v28 = v39;
    v30 = v39;
    v6 = v4;
    v29 = v5;
    v7 = dword_2305834[0] + 71388;
    v31 = dword_2305834[0] + 71388;
    n17 = 17;
    do
    {
      v33 = 4 * v1 + 12;
      v8 = (float *)v7;
      n20 = 20;
      do
      {
        if ( *v0++ )
        {
          unk_C8F7D0 = v16;
          unk_C8F7D4 = v17;
          unk_C8F7D8 = 1.0;
          flt_C8F7DC = 0.0;
          unk_C8F7E0 = *(v8 - 4);
          v11 = (float *)dword_1A860EC;
          unk_C8F7D0 = unk_C8F7E0 * v3;
          unk_C8F7D4 = v17 * unk_C8F7E0;
          unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
          *dword_1A860EC = LODWORD(unk_C8F7D0);
          v11[1] = unk_C8F7D4;
          v11[2] = unk_C8F7D8;
          v11[3] = flt_C8F7DC;
          unk_C8F7D0 = v18;
          unk_C8F7D4 = v19;
          unk_C8F7D8 = 1.0;
          flt_C8F7DC = 0.0;
          unk_C8F7E0 = *v8;
          unk_C8F7D0 = v18 * unk_C8F7E0;
          unk_C8F7D4 = v19 * unk_C8F7E0;
          unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
          v11[4] = unk_C8F7D0;
          v11[5] = unk_C8F7D4;
          v11[6] = unk_C8F7D8;
          v11[7] = flt_C8F7DC;
          unk_C8F7D0 = v20;
          unk_C8F7D4 = v21;
          unk_C8F7D8 = 1.0;
          flt_C8F7DC = 0.0;
          unk_C8F7E0 = v8[80];
          unk_C8F7D0 = unk_C8F7E0 * v3;
          unk_C8F7D4 = v21 * unk_C8F7E0;
          unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
          v11[8] = unk_C8F7D0;
          v11[9] = unk_C8F7D4;
          v11[10] = unk_C8F7D8;
          v11[11] = flt_C8F7DC;
          unk_C8F7D0 = v22;
          unk_C8F7D4 = v23;
          unk_C8F7D8 = 1.0;
          flt_C8F7DC = 0.0;
          unk_C8F7E0 = v8[84];
          unk_C8F7D0 = v23 * unk_C8F7E0;
          unk_C8F7D4 = unk_C8F7D0;
          unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
          v11[12] = unk_C8F7D0;
          v11[13] = unk_C8F7D4;
          v11[14] = unk_C8F7D8;
          v11[15] = flt_C8F7DC;
          unk_C8F7D0 = v24;
          unk_C8F7D4 = v25;
          unk_C8F7D8 = 1.0;
          flt_C8F7DC = 0.0;
          unk_C8F7E0 = *(v8 - 4);
          unk_C8F7D0 = v6 * unk_C8F7E0;
          unk_C8F7D4 = v25 * unk_C8F7E0;
          unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
          v11[16] = unk_C8F7D0;
          v11[17] = unk_C8F7D4;
          v11[18] = unk_C8F7D8;
          v11[19] = flt_C8F7DC;
          unk_C8F7D0 = v26;
          unk_C8F7D4 = v25;
          unk_C8F7D8 = 1.0;
          flt_C8F7DC = 0.0;
          unk_C8F7E0 = *v8;
          unk_C8F7D0 = v26 * unk_C8F7E0;
          unk_C8F7D4 = v25 * unk_C8F7E0;
          unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
          v11[20] = unk_C8F7D0;
          v11[21] = unk_C8F7D4;
          v11[22] = unk_C8F7D8;
          v11[23] = flt_C8F7DC;
          unk_C8F7D0 = v27;
          unk_C8F7D4 = v28;
          unk_C8F7D8 = 1.0;
          flt_C8F7DC = 0.0;
          unk_C8F7E0 = v8[80];
          unk_C8F7D0 = v6 * unk_C8F7E0;
          unk_C8F7D4 = v28 * unk_C8F7E0;
          unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
          v11[24] = unk_C8F7D0;
          v11[25] = unk_C8F7D4;
          v11[26] = unk_C8F7D8;
          v11[27] = flt_C8F7DC;
          unk_C8F7D0 = v29;
          unk_C8F7D4 = v30;
          unk_C8F7D8 = 1.0;
          flt_C8F7DC = 0.0;
          unk_C8F7E0 = v8[84];
          unk_C8F7D0 = v29 * unk_C8F7E0;
          unk_C8F7D4 = v30 * unk_C8F7E0;
          unk_C8F7D8 = unk_C8F7E0 * (float)1.0;
          v11[28] = unk_C8F7D0;
          v12 = *v11;
          v11[29] = unk_C8F7D4;
          v11[30] = unk_C8F7D8;
          v11[31] = flt_C8F7DC;
          v13 = *(_DWORD *)(v15 + 24);
          *(float *)(v33 + v13 - 12) = v12 * 512.0;
          *(float *)(v33 + v13 - 8) = 1.0 - v11[1] * 512.0;
          *(float *)(v33 + v13 - 4) = v11[4] * 512.0;
          v32 += 16;
          *(float *)(v33 + v13) = 1.0 - v11[5] * 512.0;
          *(float *)(v33 + v13 + 4) = v11[8] * 512.0;
          *(float *)(v33 + v13 + 8) = 1.0 - v11[9] * 512.0;
          *(float *)(v33 + v13 + 12) = v11[12] * 512.0;
          *(float *)(v33 + v13 + 16) = 1.0 - v11[13] * 512.0;
          *(float *)(v33 + v13 + 20) = v11[16] * 512.0;
          *(float *)(v33 + v13 + 24) = 1.0 - v11[17] * 512.0;
          *(float *)(v33 + v13 + 28) = v11[20] * 512.0;
          *(float *)(v33 + v13 + 32) = 1.0 - v11[21] * 512.0;
          *(float *)(v33 + v13 + 36) = v11[24] * 512.0;
          *(float *)(v33 + v13 + 40) = 1.0 - v11[25] * 512.0;
          *(float *)(v33 + v13 + 44) = v11[28] * 512.0;
          v33 += 64;
          *(float *)(v33 + v13 - 16) = 1.0 - v11[29] * 512.0;
        }
        v8 += 4;
        --n20;
      }
      while ( n20 );
      v1 = v32;
      v7 = v31 + 336;
      v14 = n17-- == 1;
      v31 += 336;
    }
    while ( !v14 );
  }
}

