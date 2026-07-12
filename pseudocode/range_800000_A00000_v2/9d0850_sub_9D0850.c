// Function: sub_9D0850
// Address: 0x9d0850
float *__thiscall sub_9D0850(float *this, float *a2, float *a3, float *a4, float *a5, float *a6)
{
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st6
  double v12; // st7
  double v13; // st4
  double v14; // st5
  double v15; // st6
  double v16; // st7
  double v17; // st7
  double v18; // st7
  float v20; // [esp-20h] [ebp-2Ch]
  float v21; // [esp-20h] [ebp-2Ch]
  float v22; // [esp-20h] [ebp-2Ch]
  float v23; // [esp-20h] [ebp-2Ch]
  float v24; // [esp-20h] [ebp-2Ch]
  float v25; // [esp-1Ch] [ebp-28h]
  float v26; // [esp-1Ch] [ebp-28h]
  float v27; // [esp-1Ch] [ebp-28h]
  float v28; // [esp-1Ch] [ebp-28h]
  float v29; // [esp-1Ch] [ebp-28h]
  float v30; // [esp-18h] [ebp-24h]
  float v31; // [esp-18h] [ebp-24h]
  float v32; // [esp-18h] [ebp-24h]
  float v33; // [esp-18h] [ebp-24h]
  float v34; // [esp-18h] [ebp-24h]
  float v35; // [esp-Ch] [ebp-18h]
  float v36; // [esp-Ch] [ebp-18h]
  float v37; // [esp-4h] [ebp-10h]

  *this = 0.0;
  *(this + 1) = 0.0;
  *(this + 2) = 0.0;
  *(this + 3) = 0.0;
  v37 = a2[1];
  v8 = a2[2];
  v20 = a3[2] * v8 + a3[1] * v37 + *a2 * *a3;
  v25 = a3[5] * v37 + *a2 * a3[4] + a3[6] * v8;
  v9 = v37 * a3[9] + *a2 * a3[8];
  v10 = a3[10];
  *(this + 4) = v20;
  *(this + 5) = v25;
  v30 = v8 * v10 + v9;
  *(this + 6) = v30;
  *(this + 7) = 0.0;
  v21 = -*a2;
  v26 = -a2[1];
  v31 = -a2[2];
  v11 = v26;
  v12 = v21;
  v22 = a4[2] * v31 + *a4 * v21 + a4[1] * v26;
  v27 = a4[5] * v26 + v12 * a4[4] + a4[6] * v31;
  v13 = a4[8];
  v14 = v11 * a4[9];
  v15 = v31 * a4[10];
  *(this + 8) = v22;
  *(this + 9) = v27;
  v32 = v12 * v13 + v14 + v15;
  *(this + 10) = v32;
  *(this + 11) = 0.0;
  v23 = *a5 * *(this + 4);
  v28 = a5[1] * *(this + 5);
  v16 = a5[2] * *(this + 6);
  *(this + 12) = v23;
  *(this + 13) = v28;
  v33 = v16;
  *(this + 14) = v33;
  *(this + 15) = 0.0;
  v24 = *a6 * *(this + 8);
  v29 = a6[1] * *(this + 9);
  v17 = a6[2] * *(this + 10);
  *(this + 16) = v24;
  *(this + 17) = v29;
  v34 = v17;
  *(this + 18) = v34;
  *(this + 19) = 0.0;
  v35 = *(this + 17) * *(this + 9) + *(this + 16) * *(this + 8) + *(this + 18) * *(this + 10);
  v18 = v35;
  v36 = *(this + 13) * *(this + 5) + *(this + 12) * *(this + 4) + *(this + 14) * *(this + 6);
  *(this + 20) = v18 + v36;
  return this;
}
