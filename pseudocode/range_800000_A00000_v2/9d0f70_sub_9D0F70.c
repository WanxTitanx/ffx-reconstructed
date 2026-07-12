// Function: sub_9D0F70
// Address: 0x9d0f70
float *__userpurge sub_9D0F70@<eax>(int a1@<ecx>, float a2@<ebp>, float *a3, float *a4)
{
  float *result; // eax
  float *v5; // eax
  float *v6; // ecx
  float v7; // xmm0_4
  float v8[12]; // [esp-70h] [ebp-7Ch] BYREF
  float v9[19]; // [esp-40h] [ebp-4Ch] BYREF
  float retaddr; // [esp+Ch] [ebp+0h]

  v9[16] = a2;
  v9[17] = retaddr;
  result = a4;
  if ( a3 )
  {
    v5 = *(float **)(a1 + 24);
    v6 = *(float **)(a1 + 20);
    v9[0] = v5[4];
    v9[1] = v5[8];
    v9[2] = v5[12];
    v9[4] = v5[5];
    v9[5] = v5[9];
    v9[6] = v5[13];
    v9[8] = v5[6];
    v9[9] = v5[10];
    v9[10] = v5[14];
    v8[0] = v6[4];
    v8[1] = v6[8];
    v8[2] = v6[12];
    v8[4] = v6[5];
    v8[5] = v6[9];
    v8[6] = v6[13];
    v8[8] = v6[6];
    v8[9] = v6[10];
    v7 = v6[14];
    v9[3] = 0.0;
    v9[7] = 0.0;
    v9[11] = 0.0;
    v8[3] = 0.0;
    v8[7] = 0.0;
    v8[10] = v7;
    v8[11] = 0.0;
    return sub_9D0850(a3, a4, v8, v9, v6 + 104, v5 + 104);
  }
  return result;
}
