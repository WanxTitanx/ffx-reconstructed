// Function: sub_A25410
// Address: 0xa25410
// Size: 0x447
// Prototype: 

int __thiscall sub_A25410(char *this, int a2)
{
  char *v3; // esi
  float *v4; // ebx
  float *v5; // edi
  float *v6; // esi
  float *v7; // eax
  float *v8; // ebx
  float *v9; // edi
  float *v10; // esi
  float *v11; // eax
  float *v12; // ebx
  float *v13; // edi
  float *v14; // esi
  float *v15; // eax
  float *this_2; // edx
  _BYTE v18[16]; // [esp+Ch] [ebp-1C4h] BYREF
  _BYTE v19[16]; // [esp+1Ch] [ebp-1B4h] BYREF
  _BYTE v20[16]; // [esp+2Ch] [ebp-1A4h] BYREF
  _BYTE v21[16]; // [esp+3Ch] [ebp-194h] BYREF
  _BYTE v22[16]; // [esp+4Ch] [ebp-184h] BYREF
  _BYTE v23[16]; // [esp+5Ch] [ebp-174h] BYREF
  _BYTE v24[16]; // [esp+6Ch] [ebp-164h] BYREF
  _BYTE v25[16]; // [esp+7Ch] [ebp-154h] BYREF
  _BYTE v26[16]; // [esp+8Ch] [ebp-144h] BYREF
  _BYTE v27[16]; // [esp+9Ch] [ebp-134h] BYREF
  _BYTE v28[16]; // [esp+ACh] [ebp-124h] BYREF
  _BYTE v29[16]; // [esp+BCh] [ebp-114h] BYREF
  _BYTE v30[16]; // [esp+CCh] [ebp-104h] BYREF
  _BYTE v31[16]; // [esp+DCh] [ebp-F4h] BYREF
  float src[16]; // [esp+ECh] [ebp-E4h] BYREF
  float v33[4]; // [esp+12Ch] [ebp-A4h] BYREF
  float v34[4]; // [esp+13Ch] [ebp-94h] BYREF
  float v35[4]; // [esp+14Ch] [ebp-84h] BYREF
  float v36[4]; // [esp+15Ch] [ebp-74h] BYREF
  int v37; // [esp+16Ch] [ebp-64h] BYREF
  float v38; // [esp+170h] [ebp-60h]
  int v39; // [esp+174h] [ebp-5Ch]
  int v40; // [esp+178h] [ebp-58h]
  float v41; // [esp+17Ch] [ebp-54h] BYREF
  float v42; // [esp+180h] [ebp-50h]
  int v43; // [esp+184h] [ebp-4Ch]
  int v44; // [esp+188h] [ebp-48h]
  float *this_1; // [esp+18Ch] [ebp-44h]
  float dst[16]; // [esp+190h] [ebp-40h] BYREF

  this_1 = (float *)this;
  sub_A13B90(a2);
  v37 = *(_DWORD *)(a2 + 64);
  v38 = *(float *)(a2 + 68);
  v39 = *(_DWORD *)(a2 + 72);
  v40 = *(_DWORD *)(a2 + 76);
  v41 = *(float *)(a2 + 48);
  v42 = *(float *)(a2 + 52);
  v43 = *(_DWORD *)(a2 + 56);
  v44 = *(_DWORD *)(a2 + 60);
  v41 = 1.0 / v41;
  v42 = 1.0 / v38;
  v33[0] = v41;
  v33[1] = 0.0;
  v33[2] = 0.0;
  v33[3] = 0.0;
  v34[0] = 0.0;
  v34[1] = v42;
  v34[2] = 0.0;
  v34[3] = 0.0;
  v35[0] = 0.0;
  v35[1] = 0.0;
  v35[2] = -1.0;
  v35[3] = 0.0;
  v36[0] = 0.0;
  v36[1] = 0.0;
  v36[2] = 0.0;
  v36[3] = 1.0;
  sub_451160(a2);
  qmemcpy(dst, src, sizeof(dst));
  sub_573E70(v28, dst);
  v3 = this + 20;
  v4 = (float *)sub_4C9D40(&v37, this + 68);
  v5 = (float *)sub_4C9D40(&v41, v3 + 32);
  v6 = (float *)sub_4C9D40(v25, v3 + 16);
  v7 = (float *)sub_4C9D40(v24, this_1 + 5);
  dst[0] = *v7;
  dst[1] = v7[1];
  dst[2] = v7[2];
  dst[3] = v7[3];
  dst[4] = *v6;
  dst[5] = v6[1];
  dst[6] = v6[2];
  dst[7] = v6[3];
  dst[8] = *v5;
  dst[9] = v5[1];
  dst[10] = v5[2];
  dst[11] = v5[3];
  dst[12] = *v4;
  dst[13] = v4[1];
  dst[14] = v4[2];
  dst[15] = v4[3];
  v8 = (float *)sub_4C9D40(v22, v31);
  v9 = (float *)sub_4C9D40(v20, v30);
  v10 = (float *)sub_4C9D40(v18, v29);
  v11 = (float *)sub_4C9D40(v27, v28);
  dst[0] = *v11;
  dst[1] = v11[1];
  dst[2] = v11[2];
  dst[3] = v11[3];
  dst[4] = *v10;
  dst[5] = v10[1];
  dst[6] = v10[2];
  dst[7] = v10[3];
  dst[8] = *v9;
  dst[9] = v9[1];
  dst[10] = v9[2];
  dst[11] = v9[3];
  dst[12] = *v8;
  dst[13] = v8[1];
  dst[14] = v8[2];
  dst[15] = v8[3];
  v12 = (float *)sub_4C9D40(v21, v36);
  v13 = (float *)sub_4C9D40(v23, v35);
  v14 = (float *)sub_4C9D40(v19, v34);
  v15 = (float *)sub_4C9D40(v26, v33);
  dst[0] = *v15;
  dst[1] = v15[1];
  dst[2] = v15[2];
  dst[3] = v15[3];
  dst[4] = *v14;
  dst[5] = v14[1];
  dst[6] = v14[2];
  dst[7] = v14[3];
  dst[8] = *v13;
  dst[9] = v13[1];
  dst[10] = v13[2];
  dst[11] = v13[3];
  dst[12] = *v12;
  this_2 = this_1;
  dst[13] = v12[1];
  dst[14] = v12[2];
  dst[15] = v12[3];
  this_1[37] = dst[0];
  this_2[38] = dst[1];
  this_2[39] = dst[2];
  this_2[40] = dst[3];
  this_2[41] = dst[4];
  this_2[42] = dst[5];
  this_2[43] = dst[6];
  this_2[44] = dst[7];
  this_2[45] = dst[8];
  this_2[46] = dst[9];
  this_2[47] = dst[10];
  this_2[48] = dst[11];
  this_2[49] = dst[12];
  this_2[50] = dst[13];
  this_2[51] = dst[14];
  this_2[52] = dst[15];
  this_2[5] = src[0];
  this_2[6] = src[1];
  this_2[7] = src[2];
  this_2[8] = src[3];
  this_2[9] = src[4];
  this_2[10] = src[5];
  this_2[11] = src[6];
  this_2[12] = src[7];
  this_2[13] = src[8];
  this_2[14] = src[9];
  this_2[15] = src[10];
  this_2[16] = src[11];
  this_2[17] = src[12];
  this_2[18] = src[13];
  this_2[19] = src[14];
  this_2[20] = src[15];
  return sub_453420(a2 + 48);
}

