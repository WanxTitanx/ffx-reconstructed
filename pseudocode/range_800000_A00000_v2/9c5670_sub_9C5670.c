// Function: sub_9C5670
// Address: 0x9c5670
float *__thiscall sub_9C5670(
        float *this,
        float *a2,
        float *a3,
        float *a4,
        float *a5,
        float *a6,
        float *a7,
        float a8,
        float *a9,
        float a10)
{
  double v10; // st4
  double v11; // st6
  double v12; // st6
  double v13; // st7
  double v14; // st7
  double v15; // st6
  float v16; // xmm0_4
  double v17; // st7
  double v18; // st6
  double v19; // st5
  double v20; // st7
  double v21; // st7
  double v23; // st7
  float v24; // [esp-30h] [ebp-3Ch]
  float v25; // [esp-2Ch] [ebp-38h]
  float v26; // [esp-28h] [ebp-34h]
  float v27; // [esp-20h] [ebp-2Ch]
  float v28; // [esp-20h] [ebp-2Ch]
  float v29; // [esp-20h] [ebp-2Ch]
  float v30; // [esp-20h] [ebp-2Ch]
  float v31; // [esp-20h] [ebp-2Ch]
  float v32; // [esp-1Ch] [ebp-28h]
  float v33; // [esp-1Ch] [ebp-28h]
  float v34; // [esp-1Ch] [ebp-28h]
  float v35; // [esp-1Ch] [ebp-28h]
  float v36; // [esp-1Ch] [ebp-28h]
  float v37; // [esp-1Ch] [ebp-28h]
  float v38; // [esp-18h] [ebp-24h]
  float v39; // [esp-18h] [ebp-24h]
  float v40; // [esp-18h] [ebp-24h]
  float v41; // [esp-18h] [ebp-24h]
  float v42; // [esp-18h] [ebp-24h]
  float v43; // [esp-18h] [ebp-24h]
  float v44; // [esp-10h] [ebp-1Ch]
  float v45; // [esp-10h] [ebp-1Ch]
  float v46; // [esp-Ch] [ebp-18h]
  float v47; // [esp-8h] [ebp-14h]
  float v48; // [esp-4h] [ebp-10h]

  *this = *a6;
  *(this + 1) = a6[1];
  *(this + 2) = a6[2];
  *(this + 3) = a6[3];
  v47 = *(this + 2);
  v48 = a4[1];
  v10 = a4[2];
  v11 = *(this + 1);
  v27 = v48 * v47 - v10 * v11;
  v32 = v10 * *this - v47 * *a4;
  v38 = v11 * *a4 - v48 * *this;
  v12 = v32;
  v13 = v27;
  v28 = a2[2] * v38 + *a2 * v27 + a2[1] * v32;
  v33 = a2[5] * v32 + a2[4] * v13 + a2[6] * v38;
  v14 = v13 * a2[8] + v12 * a2[9];
  v15 = v38 * a2[10];
  *(this + 4) = v28;
  *(this + 5) = v33;
  v39 = v14 + v15;
  *(this + 6) = v39;
  *(this + 7) = 0.0;
  v34 = -*(this + 1);
  v16 = -*this;
  v40 = -*(this + 2);
  v46 = a5[2];
  v17 = a5[1];
  v24 = v17 * v40 - v46 * v34;
  v25 = v46 * v16 - v40 * *a5;
  v26 = v34 * *a5 - v17 * v16;
  v29 = a3[2] * v26 + a3[1] * v25 + v24 * *a3;
  v35 = a3[5] * v25 + v24 * a3[4] + a3[6] * v26;
  v18 = v25 * a3[9] + v24 * a3[8];
  v19 = a3[10];
  *(this + 8) = v29;
  *(this + 9) = v35;
  v41 = v26 * v19 + v18;
  *(this + 10) = v41;
  *(this + 11) = 0.0;
  v30 = *a7 * *(this + 4);
  v36 = a7[1] * *(this + 5);
  v20 = a7[2] * *(this + 6);
  *(this + 12) = v30;
  *(this + 13) = v36;
  v42 = v20;
  *(this + 14) = v42;
  *(this + 15) = 0.0;
  v31 = *a9 * *(this + 8);
  v37 = a9[1] * *(this + 9);
  v21 = a9[2] * *(this + 10);
  *(this + 16) = v31;
  *(this + 17) = v37;
  v43 = v21;
  *(this + 18) = v43;
  *(this + 19) = 0.0;
  v44 = *(this + 13) * *(this + 5) + *(this + 4) * *(this + 12) + *(this + 14) * *(this + 6);
  v23 = v44 + a8 + a10;
  v45 = *(this + 17) * *(this + 9) + *(this + 16) * *(this + 8) + *(this + 18) * *(this + 10);
  *(this + 20) = v23 + v45;
  return this;
}
