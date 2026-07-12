// Function: sub_9D12E0
// Address: 0x9d12e0
int __userpurge sub_9D12E0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4, float *a5, float *a6)
{
  int result; // eax
  int v7; // edx
  int v8; // ecx
  double v9; // st7
  int v10; // xmm0_4
  double v11; // st7
  double v12; // st7
  int v13; // xmm0_4
  double v14; // st7
  double v15; // st7
  int v16; // xmm0_4
  double v17; // st7
  double v18; // st7
  double v19; // st7
  int v20; // xmm0_4
  int v21; // xmm0_4
  float v22[4]; // [esp+1Ch] [ebp-ACh] BYREF
  float v23[5]; // [esp+2Ch] [ebp-9Ch] BYREF
  int v24; // [esp+40h] [ebp-88h]
  int v25; // [esp+44h] [ebp-84h]
  int v26; // [esp+48h] [ebp-80h]
  _DWORD v27[12]; // [esp+4Ch] [ebp-7Ch] BYREF
  _DWORD v28[19]; // [esp+7Ch] [ebp-4Ch] BYREF
  _UNKNOWN *retaddr; // [esp+C8h] [ebp+0h]

  v28[16] = a2;
  v28[17] = retaddr;
  result = a3;
  v26 = a3;
  if ( a3 )
  {
    v7 = *(_DWORD *)(a1 + 24);
    v8 = *(_DWORD *)(a1 + 20);
    v25 = *(_DWORD *)(v7 + 352);
    v9 = *a6 - *(float *)(v7 + 64);
    v24 = *(_DWORD *)(v8 + 352);
    v28[0] = *(_DWORD *)(v7 + 16);
    v10 = *(_DWORD *)(v7 + 32);
    v23[0] = v9;
    v11 = a6[1];
    v28[1] = v10;
    v12 = v11 - *(float *)(v7 + 68);
    v28[2] = *(_DWORD *)(v7 + 48);
    v13 = *(_DWORD *)(v7 + 20);
    v23[1] = v12;
    v28[4] = v13;
    v14 = a6[2] - *(float *)(v7 + 72);
    v28[5] = *(_DWORD *)(v7 + 36);
    v28[6] = *(_DWORD *)(v7 + 52);
    v23[2] = v14;
    v15 = *a5 - *(float *)(v8 + 64);
    v28[8] = *(_DWORD *)(v7 + 24);
    v28[9] = *(_DWORD *)(v7 + 40);
    v16 = *(_DWORD *)(v7 + 56);
    v22[0] = v15;
    v17 = a5[1];
    v28[10] = v16;
    v18 = v17 - *(float *)(v8 + 68);
    v27[0] = *(_DWORD *)(v8 + 16);
    v27[1] = *(_DWORD *)(v8 + 32);
    v22[1] = v18;
    v19 = a5[2] - *(float *)(v8 + 72);
    v27[2] = *(_DWORD *)(v8 + 48);
    v27[4] = *(_DWORD *)(v8 + 20);
    v20 = *(_DWORD *)(v8 + 36);
    v22[2] = v19;
    v27[5] = v20;
    v27[6] = *(_DWORD *)(v8 + 52);
    v27[8] = *(_DWORD *)(v8 + 24);
    v27[9] = *(_DWORD *)(v8 + 40);
    v21 = *(_DWORD *)(v8 + 56);
    v23[3] = 0.0;
    v22[3] = 0.0;
    v28[3] = 0;
    v28[7] = 0;
    v28[11] = 0;
    v27[3] = 0;
    v27[7] = 0;
    v27[10] = v21;
    v27[11] = 0;
    return sub_9C5670(v27, v28, v22, v23, a4, v8 + 416, v24, v7 + 416, v25);
  }
  return result;
}
