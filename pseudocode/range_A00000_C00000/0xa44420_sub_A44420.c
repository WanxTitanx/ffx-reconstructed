// Function: sub_A44420
// Address: 0xa44420
// Size: 0x1c2
// Prototype: int __cdecl(int, float, float, float, int)

int __cdecl sub_A44420(int *a1, float a2, float a3, float a4, int a5)
{
  int v5; // esi
  int v6; // edi
  double i; // st7
  double i_3; // st3
  int v10; // [esp+10h] [ebp-5Ch]
  float v11; // [esp+18h] [ebp-54h]
  float i_2; // [esp+18h] [ebp-54h]
  float v13; // [esp+2Ch] [ebp-40h]
  float v14; // [esp+30h] [ebp-3Ch]
  int v15; // [esp+34h] [ebp-38h] BYREF
  int v16; // [esp+38h] [ebp-34h] BYREF
  float v17; // [esp+3Ch] [ebp-30h]
  float i_1; // [esp+40h] [ebp-2Ch]
  int v19; // [esp+44h] [ebp-28h] BYREF
  int v20; // [esp+48h] [ebp-24h] BYREF
  float v21; // [esp+4Ch] [ebp-20h]
  float v22; // [esp+50h] [ebp-1Ch]
  int v23; // [esp+58h] [ebp-14h] BYREF
  float v24; // [esp+5Ch] [ebp-10h]
  float v25; // [esp+60h] [ebp-Ch]

  unk_1A85F34 = 0.0;
  v5 = *a1;
  v14 = 999999.0;
  v6 = (int)(a1 + 4);
  i_1 = 0.0;
  v19 = 10 * v5;
  v17 = (float)(10 * v5);
  v13 = 1.0 / v17;
  i_5 = 0.0;
  v11 = 0.0;
  v10 = (int)(a1 + 4);
  if ( a5 )
    sub_88A440((int)&v20, v10, v5, v11);
  else
    sub_88A410((int)&v20, v10, v5, v11);
  for ( i = i_1; ; i = i_1 )
  {
    i_2 = i;
    if ( a5 )
      sub_88A440((int)&v23, v6, v5, i_2);
    else
      sub_88A410((int)&v23, v6, v5, i_2);
    *(float *)&v19 = *(float *)&v23 - *(float *)&v20;
    *(float *)&v15 = v24 - v21;
    *(float *)&v16 = v25 - v22;
    v17 = sqrt(*(float *)&v19 * *(float *)&v19 + *(float *)&v15 * *(float *)&v15 + *(float *)&v16 * *(float *)&v16);
    unk_1A85F34 = v17 + unk_1A85F34;
    *(float *)&v19 = *(float *)&v23 - a2;
    *(float *)&v15 = v24 - a3;
    *(float *)&v16 = v25 - a4;
    v17 = *(float *)&v19 * *(float *)&v19 + *(float *)&v15 * *(float *)&v15 + *(float *)&v16 * *(float *)&v16;
    if ( v14 <= (double)v17 )
    {
      i_3 = i_1;
    }
    else
    {
      v14 = v17;
      i_3 = i_1;
      i_5 = i_1;
    }
    v20 = v23;
    v21 = v24;
    v22 = v25;
    i_1 = i_3 + v13;
    if ( i_1 > 1.0 )
      break;
  }
  sub_A44120(a1, a2, a3, a4, (float *)&v19, (float *)&v15, (float *)&v16, a5);
  return nullsub_47("\nsp_near_size=%f\n", unk_1A85F34);
}

