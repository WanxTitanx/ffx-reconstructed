// Function: sub_9A4470
// Address: 0x9a4470
int __thiscall sub_9A4470(int this, float *a2, float *a3)
{
  int v3; // edx
  int v4; // esi
  double v5; // st2
  double v6; // st7
  double v7; // st7
  double v8; // st7
  int result; // eax
  double v10; // st7
  double v11; // st6
  int v12; // edi
  float *i; // esi
  double v14; // st7
  float v15; // [esp-40h] [ebp-4Ch]
  float v16; // [esp-40h] [ebp-4Ch]
  float v17; // [esp-3Ch] [ebp-48h]
  float v18; // [esp-3Ch] [ebp-48h]
  float v19; // [esp-38h] [ebp-44h]
  float v20; // [esp-38h] [ebp-44h]
  float v21; // [esp-30h] [ebp-3Ch]
  float v22; // [esp-30h] [ebp-3Ch]
  float v23; // [esp-2Ch] [ebp-38h]
  float v24; // [esp-2Ch] [ebp-38h]
  float v25; // [esp-28h] [ebp-34h]
  float v26; // [esp-28h] [ebp-34h]
  float v27; // [esp-20h] [ebp-2Ch]
  float v28; // [esp-20h] [ebp-2Ch]
  float v29; // [esp-1Ch] [ebp-28h]
  float v30; // [esp-1Ch] [ebp-28h]
  float v31; // [esp-18h] [ebp-24h]
  float v32; // [esp-18h] [ebp-24h]
  float v33; // [esp-10h] [ebp-1Ch]
  float v34; // [esp-10h] [ebp-1Ch]
  float v35; // [esp-10h] [ebp-1Ch]
  float v36; // [esp-10h] [ebp-1Ch]
  float v37; // [esp-10h] [ebp-1Ch]
  float v38; // [esp-10h] [ebp-1Ch]
  float v39; // [esp-10h] [ebp-1Ch]
  float v40; // [esp-Ch] [ebp-18h]
  float v41; // [esp-Ch] [ebp-18h]
  float v42; // [esp-Ch] [ebp-18h]
  float v43; // [esp-8h] [ebp-14h]
  float v44; // [esp-8h] [ebp-14h]
  int this_1; // [esp-4h] [ebp-10h]

  v3 = *(_DWORD *)(this + 1176) - 1;
  this_1 = this;
  if ( v3 >= 0 )
  {
    v4 = 288 * v3 + this + 40;
    do
    {
      v43 = *(float *)(v4 - 20);
      v40 = *(float *)(v4 - 24);
      v5 = *(float *)(v4 - 16);
      v33 = a2[2] * v5 + a2[1] * v43 + v40 * *a2;
      v27 = v33 + a2[12];
      v34 = v40 * a2[4] + a2[5] * v43 + a2[6] * v5;
      v29 = v34 + a2[13];
      v35 = v5 * a2[10] + v43 * a2[9] + v40 * a2[8];
      v6 = v35 + a2[14];
      *(float *)(v4 + 24) = v27;
      *(float *)(v4 + 28) = v29;
      v31 = v6;
      *(float *)(v4 + 32) = v31;
      *(_DWORD *)(v4 + 36) = 0;
      v41 = *(float *)(v4 - 4);
      v44 = *(float *)v4;
      v7 = *(float *)(v4 - 8);
      v36 = a3[1] * v41 + v7 * *a3 + *(float *)v4 * a3[2];
      v21 = v36 + a3[12];
      v4 -= 288;
      v37 = a3[5] * v41 + a3[4] * v7 + a3[6] * v44;
      v23 = v37 + a3[13];
      v38 = v44 * a3[10] + v41 * a3[9] + v7 * a3[8];
      v8 = v38 + a3[14];
      *(float *)(v4 + 296) = v21;
      *(float *)(v4 + 300) = v23;
      v25 = v8;
      *(float *)(v4 + 304) = v25;
      result = 0;
      *(_DWORD *)(v4 + 308) = 0;
      v15 = *(float *)(v4 + 312) - *(float *)(v4 + 296);
      v17 = *(float *)(v4 + 316) - *(float *)(v4 + 300);
      v19 = *(float *)(v4 + 320) - *(float *)(v4 + 304);
      v10 = *(float *)(v4 + 332) * v17 + *(float *)(v4 + 328) * v15;
      v11 = *(float *)(v4 + 336);
      ++*(_DWORD *)(v4 + 408);
      --v3;
      *(float *)(v4 + 344) = v10 + v11 * v19;
    }
    while ( v3 >= 0 );
  }
  v12 = *(_DWORD *)(this + 1176) - 1;
  if ( v12 >= 0 )
  {
    result = 288 * v12;
    for ( i = (float *)(288 * v12 + this + 88); ; i -= 72 )
    {
      v42 = *(float *)(this + 1180);
      v14 = i[2];
      if ( v42 < v14 )
        break;
      v16 = *(i - 2) * v14;
      v18 = *(i - 1) * v14;
      v20 = v14 * *i;
      v22 = *(i - 6) - v16;
      v24 = *(i - 5) - v18;
      v26 = *(i - 4) - v20;
      v28 = *(i - 10) - v22;
      v30 = *(i - 9) - v24;
      v32 = *(i - 8) - v26;
      v39 = v28 * v28 + v30 * v30 + v32 * v32;
      if ( v39 > v42 * v42 )
        break;
      if ( unk_193F648 )
      {
        result = unk_193F648(i - 18, *(_DWORD *)(this + 1168), *(_DWORD *)(this + 1172));
        goto LABEL_11;
      }
LABEL_12:
      if ( --v12 < 0 )
        return result;
    }
    result = sub_9A4760(v12);
LABEL_11:
    this = this_1;
    goto LABEL_12;
  }
  return result;
}
