// Function: sub_A9C780
// Address: 0xa9c780
// Size: 0x1b9
// Prototype: 

float *__fastcall sub_A9C780(int a1, unsigned int a2, int a3)
{
  float *v3; // ecx
  float *v4; // edi
  float *result; // eax
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm1_4

  v3 = (float *)(a1 + 16);
  v4 = (float *)(a2 - 32 + 4 * (a3 >> 1));
  result = &v4[a3 - (a3 >> 1) + 7];
  do
  {
    v6 = *result;
    v7 = *result - v4[7];
    v8 = *(result - 1);
    v9 = v8 + v4[6];
    v10 = v8 - v4[6];
    *(result - 1) = v9;
    *result = v6 + v4[7];
    v4[6] = (float)(*(v3 - 4) * v10) + (float)(*(v3 - 3) * v7);
    v4[7] = (float)(*(v3 - 4) * v7) - (float)(*(v3 - 3) * v10);
    v11 = *(result - 2);
    v12 = v11 - v4[5];
    v13 = *(result - 3);
    v14 = v13 + v4[4];
    v15 = v13 - v4[4];
    *(result - 3) = v14;
    *(result - 2) = v11 + v4[5];
    v4[4] = (float)(v3[1] * v12) + (float)(v15 * *v3);
    v4[5] = (float)(v12 * *v3) - (float)(v3[1] * v15);
    v16 = *(result - 4);
    v17 = v16 - v4[3];
    v18 = *(result - 5);
    v19 = v18 + v4[2];
    v20 = v18 - v4[2];
    *(result - 5) = v19;
    *(result - 4) = v16 + v4[3];
    v4[2] = (float)(v3[5] * v17) + (float)(v3[4] * v20);
    v4[3] = (float)(v3[4] * v17) - (float)(v3[5] * v20);
    v21 = *(result - 6);
    v22 = *(result - 7);
    v23 = v22 + *v4;
    v24 = v22 - *v4;
    v25 = v21 - v4[1];
    *(result - 7) = v23;
    *(result - 6) = v21 + v4[1];
    *v4 = (float)(v3[9] * v25) + (float)(v3[8] * v24);
    v4 -= 8;
    result -= 8;
    v26 = (float)(v3[8] * v25) - (float)(v3[9] * v24);
    v3 += 16;
    v4[9] = v26;
  }
  while ( (unsigned int)v4 >= a2 );
  return result;
}

