// Function: sub_80A0F0
// Address: 0x80a0f0
int __usercall sub_80A0F0@<eax>(int a1@<ebp>, int a2, int a3)
{
  float *v3; // edi
  unsigned int n45056; // eax
  int v5; // eax
  int v6; // eax
  float v8; // [esp+4h] [ebp-64h]
  float v9; // [esp+8h] [ebp-60h]
  float v10; // [esp+8h] [ebp-60h]
  float v11; // [esp+Ch] [ebp-5Ch]
  float v12; // [esp+Ch] [ebp-5Ch]
  float v13; // [esp+10h] [ebp-58h]
  float v14; // [esp+10h] [ebp-58h]
  float v15; // [esp+10h] [ebp-58h]
  float v16; // [esp+14h] [ebp-54h]
  float v17; // [esp+14h] [ebp-54h]
  float v18; // [esp+14h] [ebp-54h]
  float v19; // [esp+18h] [ebp-50h]
  int v20; // [esp+28h] [ebp-40h]
  float v21; // [esp+28h] [ebp-40h]
  float v22; // [esp+28h] [ebp-40h]
  float v23; // [esp+28h] [ebp-40h]
  float v24; // [esp+28h] [ebp-40h]
  float v25; // [esp+28h] [ebp-40h]
  float v26; // [esp+28h] [ebp-40h]
  float v27; // [esp+28h] [ebp-40h]
  float v28; // [esp+28h] [ebp-40h]
  float v29; // [esp+28h] [ebp-40h]
  float v30; // [esp+28h] [ebp-40h]
  float v31; // [esp+28h] [ebp-40h]
  float v32; // [esp+28h] [ebp-40h]
  float v33; // [esp+28h] [ebp-40h]
  float v34; // [esp+28h] [ebp-40h]
  float v35; // [esp+28h] [ebp-40h]
  float v36; // [esp+2Ch] [ebp-3Ch] BYREF
  float v37; // [esp+30h] [ebp-38h]
  float v38; // [esp+34h] [ebp-34h]
  float v39; // [esp+38h] [ebp-30h]
  float v40; // [esp+3Ch] [ebp-2Ch] BYREF
  float v41; // [esp+40h] [ebp-28h]
  float v42; // [esp+44h] [ebp-24h]
  float v43; // [esp+48h] [ebp-20h]
  int v44; // [esp+5Ch] [ebp-Ch]
  void *v45; // [esp+60h] [ebp-8h]
  void *retaddr; // [esp+68h] [ebp+0h]

  v44 = a1;
  v45 = retaddr;
  v3 = *(float **)(a2 + 544);
  n45056 = *(_WORD *)(a2 + 538) & 0xF000;
  if ( n45056 > 0x6000 )
  {
    if ( (*(_WORD *)(a2 + 538) & 0xF000u) > 0x9000 )
    {
      if ( n45056 == 40960 )
      {
        sub_908440();
        sub_643CC0(0);
      }
      else
      {
        if ( n45056 != 45056 )
        {
LABEL_27:
          v20 = a3;
          goto LABEL_28;
        }
        v36 = v3[16] * 0.00390625;
        v37 = v3[17] * 0.00390625;
        v38 = 0.00390625 * v3[18];
        v39 = 1.0;
        v40 = v3[12] * 0.0625;
        v41 = v3[13] * 0.0625;
        v42 = 0.0625 * v3[14];
        v43 = 1.0;
        sub_908400(&v36, &v40);
        sub_908440();
        v33 = v42 * 0.00390625;
        v18 = v33;
        v34 = v41 * 0.00390625;
        v15 = v34;
        v35 = 0.00390625 * v40;
        sub_643CE0(v36, v37, v38, v35, v15, v18, 1);
      }
    }
    else
    {
      if ( n45056 != 36864 )
      {
        if ( n45056 == 28672 )
        {
          v6 = sub_908960();
          sub_90A2B0(v6 | 4);
          return a3 + 2;
        }
        if ( n45056 == 0x8000 )
        {
          v5 = sub_908960();
          sub_90A2B0(v5 & 0xFFFFFFFB);
          return a3 + 2;
        }
        goto LABEL_27;
      }
      sub_908580(8);
      v21 = v3[14] * 0.0625;
      v19 = v21;
      v22 = v3[13] * 0.0625;
      v16 = v22;
      v23 = 0.0625 * v3[12];
      v13 = v23;
      v24 = v3[18] * 0.00390625;
      v11 = v24;
      v25 = v3[17] * 0.00390625;
      v9 = v25;
      v26 = 0.00390625 * v3[16];
      sub_90A230(v26, v9, v11, v13, v16, v19);
      sub_643CC0(1);
      v27 = v3[14] * 0.0625 * 0.00390625;
      v17 = v27;
      v28 = v3[13] * 0.0625 * 0.00390625;
      v14 = v28;
      v29 = 0.0625 * v3[12] * 0.00390625;
      v12 = v29;
      v30 = v3[18] * 0.00390625;
      v10 = v30;
      v31 = v3[17] * 0.00390625;
      v8 = v31;
      v32 = 0.00390625 * v3[16];
      sub_643CE0(v32, v8, v10, v12, v14, v17, 0);
    }
    sub_644B70();
    return a3 + 2;
  }
  if ( n45056 == 24576 )
  {
    sub_80A630(v3 + 16);
    return a3 + 2;
  }
  if ( (*(_WORD *)(a2 + 538) & 0xF000u) > 0x3000 )
  {
    if ( n45056 == 0x4000 )
    {
      sub_909E20(256);
      sub_90A1D0((int)v3[16], (int)v3[17], (int)v3[18], (int)v3[15]);
      return a3 + 2;
    }
    if ( n45056 == 20480 )
    {
      sub_909E10(256);
      return a3 + 2;
    }
    goto LABEL_27;
  }
  if ( n45056 == 12288 )
  {
    sub_909E20(4);
    sub_909E10(1);
    *(_DWORD *)a2 = word_C8F508[0];
    *(float *)(a2 + 4) = word_C8F50C;
    *(float *)(a2 + 8) = word_C8F510;
    *(float *)(a2 + 12) = word_C8F514[0];
    sub_90A270(a2);
    sub_80A630(a2);
    goto LABEL_9;
  }
  if ( (*(_WORD *)(a2 + 538) & 0xF000) != 0 )
  {
    if ( n45056 == 4096 )
    {
      sub_80AD60();
      return a3 + 2;
    }
    if ( n45056 == 0x2000 )
    {
      sub_909E10(4);
      sub_909E20(1);
      *(float *)(a2 + 12) = 1.0;
      *(float *)(a2 + 8) = 1.0;
      *(float *)(a2 + 4) = 1.0;
      *(float *)a2 = 1.0;
      sub_90A270(a2);
      sub_80A610(v3 + 16);
LABEL_9:
      sub_80A5D0(*(float *)a2, *(float *)(a2 + 4), *(float *)(a2 + 8), COERCE_INT(*(float *)(a2 + 12)));
      return a3 + 2;
    }
    goto LABEL_27;
  }
  n964689920 = *((_QWORD *)v3 + 8);
  flt_C8F988 = v3[18];
  flt_C8F98C[0] = v3[19];
  v20 = a3 + 2;
LABEL_28:
  *(float *)a2 = v3[16] * 0.0078125;
  *(float *)(a2 + 4) = v3[17] * 0.0078125;
  *(float *)(a2 + 8) = v3[18] * 0.0078125;
  *(float *)(a2 + 12) = 0.0078125 * v3[19];
  if ( *(float *)a2 < 0.0 )
    *(float *)a2 = 0.0;
  if ( *(float *)(a2 + 4) < 0.0 )
    *(float *)(a2 + 4) = 0.0;
  if ( *(float *)(a2 + 8) < 0.0 )
    *(float *)(a2 + 8) = 0.0;
  if ( *(float *)(a2 + 12) < 0.0 )
    *(float *)(a2 + 12) = 0.0;
  if ( *(float *)a2 > 1.0 )
    *(float *)a2 = 1.0;
  if ( *(float *)(a2 + 4) > 1.0 )
    *(float *)(a2 + 4) = 1.0;
  if ( *(float *)(a2 + 8) > 1.0 )
    *(float *)(a2 + 8) = 1.0;
  if ( *(float *)(a2 + 12) > 1.0 )
    *(float *)(a2 + 12) = 1.0;
  sub_909E20(4);
  sub_90A270(a2);
  sub_643820(*(float *)a2, *(float *)(a2 + 4), *(float *)(a2 + 8), COERCE_INT(*(float *)(a2 + 12)));
  return v20;
}
