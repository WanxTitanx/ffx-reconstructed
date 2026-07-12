// Function: sub_A44120
// Address: 0xa44120
// Size: 0x2f8
// Prototype: int __cdecl(int, float, float, float, int, int, int, int)

double __cdecl sub_A44120(int *a1, float a2, float a3, float a4, float *a5, float *a6, float *a7, int a8)
{
  int v8; // esi
  int v9; // edi
  int n40; // ebx
  double v11; // st6
  double v12; // st5
  double v13; // st4
  double v14; // st7
  double v16; // st7
  float v17; // [esp+10h] [ebp-5Ch]
  float v18; // [esp+14h] [ebp-58h]
  float v19; // [esp+18h] [ebp-54h]
  float v20; // [esp+18h] [ebp-54h]
  float v21; // [esp+18h] [ebp-54h]
  float v22; // [esp+1Ch] [ebp-50h]
  float v23; // [esp+1Ch] [ebp-50h]
  float v24; // [esp+1Ch] [ebp-50h]
  float v25; // [esp+20h] [ebp-4Ch]
  float v28; // [esp+24h] [ebp-48h]
  float v29; // [esp+34h] [ebp-38h]
  float v30; // [esp+34h] [ebp-38h]
  float v31; // [esp+34h] [ebp-38h]
  float v32; // [esp+34h] [ebp-38h]
  float v33; // [esp+34h] [ebp-38h]
  float v34; // [esp+34h] [ebp-38h]
  float v35; // [esp+34h] [ebp-38h]
  int v36; // [esp+38h] [ebp-34h] BYREF
  float v37; // [esp+3Ch] [ebp-30h]
  float v38; // [esp+40h] [ebp-2Ch]
  int v39; // [esp+48h] [ebp-24h] BYREF
  float v40; // [esp+4Ch] [ebp-20h]
  float v41; // [esp+50h] [ebp-1Ch]
  int v42; // [esp+58h] [ebp-14h] BYREF
  float v43; // [esp+5Ch] [ebp-10h]
  float v44; // [esp+60h] [ebp-Ch]

  v8 = *a1;
  v9 = (int)(a1 + 4);
  n40 = 0;
  v18 = 10.0 / unk_1A85F34;
  while ( 1 )
  {
    v29 = (float)(n40 * n40 + 1);
    v28 = v18 / v29;
    v30 = unk_1A85F30 - v28;
    if ( a8 )
      sub_88A440((int)&v42, v9, v8, v30);
    else
      sub_88A410((int)&v42, v9, v8, v30);
    v19 = *(float *)&v42 - a2;
    v22 = v43 - a3;
    v31 = v44 - a4;
    v17 = v19 * v19 + v22 * v22 + v31 * v31;
    v32 = unk_1A85F30 + v28;
    if ( a8 )
      sub_88A440((int)&v39, v9, v8, v32);
    else
      sub_88A410((int)&v39, v9, v8, v32);
    v20 = *(float *)&v39 - a2;
    v23 = v40 - a3;
    v33 = v41 - a4;
    v25 = v20 * v20 + v23 * v23 + v33 * v33;
    if ( a8 )
      sub_88A440((int)&v36, v9, v8, unk_1A85F30);
    else
      sub_88A410((int)&v36, v9, v8, unk_1A85F30);
    v21 = *(float *)&v36 - a2;
    v11 = v37;
    v24 = v37 - a3;
    v12 = v38;
    v34 = v38 - a4;
    v35 = v21 * v21 + v24 * v24 + v34 * v34;
    v13 = v17;
    if ( v25 == v17 )
      break;
    if ( v25 <= v13 )
    {
      if ( v35 > (double)v25 )
      {
        unk_1A85F30 = unk_1A85F30 + v28;
        if ( unk_1A85F30 > 1.0 )
        {
          *a5 = *(float *)&v36;
          *a6 = v11;
          *a7 = v12;
          return (float)(unk_1A85F30 - v28);
        }
        *a5 = *(float *)&v39;
        *a6 = v40;
        v14 = v41;
        goto LABEL_20;
      }
    }
    else if ( v35 > v13 )
    {
      unk_1A85F30 = unk_1A85F30 - v28;
      if ( unk_1A85F30 < 0.0 )
      {
        *a5 = *(float *)&v36;
        *a6 = v11;
        *a7 = v12;
        return (float)(v28 + unk_1A85F30);
      }
      *a5 = *(float *)&v42;
      *a6 = v43;
      v14 = v44;
      goto LABEL_20;
    }
    v14 = v38;
    *a5 = *(float *)&v36;
    *a6 = v11;
LABEL_20:
    ++n40;
    *a7 = v14;
    if ( n40 >= 40 )
      return unk_1A85F30;
  }
  v16 = v38;
  *a5 = *(float *)&v36;
  *a6 = v11;
  *a7 = v16;
  return unk_1A85F30;
}

