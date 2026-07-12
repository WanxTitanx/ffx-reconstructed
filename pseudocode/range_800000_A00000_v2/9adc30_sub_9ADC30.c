// Function: sub_9ADC30
// Address: 0x9adc30
bool __stdcall sub_9ADC30(float *a1, float *a2, float *a3)
{
  double v3; // st6
  double v4; // st4
  double v5; // st3
  double v6; // st5
  double v7; // rt1
  double v8; // st2
  double v9; // st6
  double v10; // st2
  double v11; // st4
  double v12; // st7
  float v14; // [esp-90h] [ebp-9Ch]
  float v15; // [esp-8Ch] [ebp-98h]
  float v16; // [esp-88h] [ebp-94h]
  float v17; // [esp-80h] [ebp-8Ch]
  float v18; // [esp-7Ch] [ebp-88h]
  float v19; // [esp-78h] [ebp-84h]
  float v20; // [esp-70h] [ebp-7Ch]
  float v21; // [esp-6Ch] [ebp-78h]
  float v22; // [esp-68h] [ebp-74h]
  float v23; // [esp-60h] [ebp-6Ch]
  float v24; // [esp-5Ch] [ebp-68h]
  float v25; // [esp-58h] [ebp-64h]
  float v26; // [esp-50h] [ebp-5Ch]
  float v27; // [esp-4Ch] [ebp-58h]
  float v28; // [esp-48h] [ebp-54h]
  float v29; // [esp-40h] [ebp-4Ch]
  float v30; // [esp-40h] [ebp-4Ch]
  float v31; // [esp-3Ch] [ebp-48h]
  float v32; // [esp-3Ch] [ebp-48h]
  float v33; // [esp-38h] [ebp-44h]
  float v34; // [esp-38h] [ebp-44h]
  float v35; // [esp-24h] [ebp-30h]
  float v36; // [esp-20h] [ebp-2Ch]
  float v37; // [esp-20h] [ebp-2Ch]
  float v38; // [esp-1Ch] [ebp-28h]
  float v39; // [esp-1Ch] [ebp-28h]
  float v40; // [esp-18h] [ebp-24h]
  float v41; // [esp-18h] [ebp-24h]
  float v42; // [esp-10h] [ebp-1Ch]
  float v43; // [esp-Ch] [ebp-18h]
  float v44; // [esp-Ch] [ebp-18h]
  float v45; // [esp-8h] [ebp-14h]
  float v46; // [esp-8h] [ebp-14h]
  float v47; // [esp-8h] [ebp-14h]
  float v48; // [esp-4h] [ebp-10h]
  float v49; // [esp-4h] [ebp-10h]
  float v50; // [esp-4h] [ebp-10h]
  float v51; // [esp-4h] [ebp-10h]

  v35 = a1[4];
  v3 = *a1;
  v36 = v35 - v3;
  v43 = a1[5];
  v4 = a1[1];
  v38 = v43 - v4;
  v42 = a1[6];
  v5 = a1[2];
  v40 = v42 - v5;
  v45 = a1[8];
  v29 = v45 - v35;
  v6 = a1[9];
  v31 = v6 - v43;
  v48 = a1[10];
  v33 = v48 - v42;
  v7 = v48;
  v17 = v3 - v45;
  v18 = v4 - v6;
  v19 = v5 - v48;
  v8 = *a3 - v3;
  v9 = *a3;
  v23 = v8;
  v49 = a3[1];
  v10 = v49 - v4;
  v11 = v49;
  v24 = v10;
  v50 = a3[2];
  v25 = v50 - v5;
  v20 = v9 - v35;
  v21 = v11 - v43;
  v22 = v50 - v42;
  v14 = v9 - v45;
  v15 = v11 - v6;
  v16 = v50 - v7;
  v46 = a2[1];
  v12 = a2[2];
  v26 = v12 * v38 - v46 * v40;
  v27 = v40 * *a2 - v12 * v36;
  v28 = v36 * v46 - v38 * *a2;
  v37 = v12 * v31 - v46 * v33;
  v39 = v33 * *a2 - v12 * v29;
  v41 = v29 * v46 - v31 * *a2;
  v30 = v12 * v18 - v46 * v19;
  v32 = v19 * *a2 - v12 * v17;
  v34 = v46 * v17 - v18 * *a2;
  v51 = v27 * v24 + v26 * v23 + v28 * v25;
  v47 = v39 * v21 + v37 * v20 + v41 * v22;
  v44 = v32 * v15 + v30 * v14 + v34 * v16;
  return v51 > 0.0 && v47 > 0.0 && v44 > 0.0 || v51 <= 0.0 && v47 <= 0.0 && v44 <= 0.0;
}
