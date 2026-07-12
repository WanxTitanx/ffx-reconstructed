// Function: sub_9B6390
// Address: 0x9b6390
int __usercall sub_9B6390@<eax>(int a1@<ecx>, int a2@<ebp>)
{
  float v3; // xmm0_4
  double v4; // st7
  float *v5; // ecx
  double v6; // st7
  float *v7; // eax
  double v8; // st7
  double v9; // st5
  double v10; // st6
  double v11; // st4
  double v12; // st7
  double v13; // st5
  double v14; // st6
  double v15; // st5
  double v16; // st3
  double v17; // st2
  double v18; // st5
  double v19; // st3
  double v20; // st4
  double v21; // st1
  double v22; // st2
  double v23; // st1
  int result; // eax
  float v25; // [esp-94h] [ebp-A0h]
  float v26; // [esp-90h] [ebp-9Ch]
  float v27; // [esp-8Ch] [ebp-98h]
  float v28; // [esp-88h] [ebp-94h]
  float v29; // [esp-84h] [ebp-90h]
  float v30; // [esp-80h] [ebp-8Ch]
  float v31; // [esp-7Ch] [ebp-88h]
  float v32; // [esp-78h] [ebp-84h]
  float v33; // [esp-74h] [ebp-80h]
  int v34; // [esp-70h] [ebp-7Ch] BYREF
  float v35; // [esp-40h] [ebp-4Ch]
  float v36; // [esp-3Ch] [ebp-48h]
  float v37; // [esp-38h] [ebp-44h]
  int v38; // [esp-34h] [ebp-40h]
  float v39; // [esp-30h] [ebp-3Ch]
  float v40; // [esp-2Ch] [ebp-38h]
  float v41; // [esp-28h] [ebp-34h]
  int v42; // [esp-24h] [ebp-30h]
  float v43; // [esp-20h] [ebp-2Ch]
  float v44; // [esp-1Ch] [ebp-28h]
  float v45; // [esp-18h] [ebp-24h]
  int v46; // [esp-14h] [ebp-20h]
  int v47; // [esp+0h] [ebp-Ch]
  void *v48; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v47 = a2;
  v48 = retaddr;
  v3 = *(float *)(a1 + 16);
  v4 = *(float *)(a1 + 52);
  v5 = (float *)(a1 + 16);
  v41 = v4;
  v35 = v3;
  v6 = v5[10];
  v36 = v5[4];
  v45 = v6;
  v37 = v5[8];
  v39 = v5[1];
  v40 = v5[5];
  v43 = v5[2];
  v44 = v5[6];
  v7 = (float *)sub_9B56A0(v5, (int)&v34, (float *)(a1 + 416));
  v8 = v7[8];
  v9 = v7[9];
  v10 = v7[10];
  v29 = v8 * v37 + v9 * v41 + v10 * v45;
  v26 = v8 * v36 + v9 * v40 + v10 * v44;
  v11 = v8 * v35;
  v12 = v39;
  v13 = v10 * v43 + v9 * v39 + v11;
  v14 = v43;
  v28 = v13;
  v15 = v7[4];
  v16 = v7[5];
  v17 = v7[6];
  v38 = 0;
  v42 = 0;
  v46 = 0;
  v30 = v15 * v37 + v16 * v41 + v17 * v45;
  v27 = v15 * v36 + v16 * v40 + v17 * v44;
  v25 = v15 * v35 + v16 * v39 + v17 * v43;
  v18 = *v7;
  v19 = v7[1];
  v20 = v7[2];
  v32 = v18 * v37 + v19 * v41 + v20 * v45;
  v37 = v32;
  v21 = v19 * v40;
  v39 = v25;
  v40 = v27;
  v22 = v18 * v36 + v21;
  v41 = v30;
  v23 = v20 * v44;
  v43 = v28;
  v44 = v26;
  v45 = v29;
  v31 = v22 + v23;
  v33 = v12 * v19 + v18 * v35 + v14 * v20;
  *(float *)(a1 + 272) = v33;
  *(float *)(a1 + 276) = v31;
  *(float *)(a1 + 280) = v37;
  *(_DWORD *)(a1 + 284) = v38;
  *(float *)(a1 + 288) = v39;
  *(float *)(a1 + 292) = v40;
  *(float *)(a1 + 296) = v41;
  *(_DWORD *)(a1 + 300) = v42;
  *(float *)(a1 + 304) = v43;
  *(float *)(a1 + 308) = v44;
  *(float *)(a1 + 312) = v45;
  result = v46;
  *(_DWORD *)(a1 + 316) = v46;
  return result;
}
