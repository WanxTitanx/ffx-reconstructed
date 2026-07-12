// Function: sub_8FAE40
// Address: 0x8fae40
void __cdecl sub_8FAE40(int *a1, __int16 *a2, float a3)
{
  char v3; // al
  __int16 v4; // ax
  double v5; // st7
  int v6; // ecx
  float v7; // esi
  float v8; // edx
  float v9; // ecx
  float v10; // eax
  double v11; // st7
  double v12; // st4
  double v13; // st5
  double v14; // st7
  char *Str_1; // edi
  int i; // esi
  char v17; // [esp-4h] [ebp-118h]
  __int16 v18; // [esp+0h] [ebp-114h]
  char *Str_2; // [esp+4h] [ebp-110h]
  float v20; // [esp+18h] [ebp-FCh] BYREF
  float v21; // [esp+1Ch] [ebp-F8h] BYREF
  float v22; // [esp+20h] [ebp-F4h]
  char *Str; // [esp+24h] [ebp-F0h]
  int v24; // [esp+28h] [ebp-ECh] BYREF
  float v25; // [esp+2Ch] [ebp-E8h] BYREF
  float v26; // [esp+30h] [ebp-E4h] BYREF
  float v27[5]; // [esp+34h] [ebp-E0h] BYREF
  float v28; // [esp+48h] [ebp-CCh] BYREF
  float v29; // [esp+4Ch] [ebp-C8h] BYREF
  float v30; // [esp+50h] [ebp-C4h] BYREF
  float v31[25]; // [esp+54h] [ebp-C0h] BYREF
  _DWORD v32[2]; // [esp+B8h] [ebp-5Ch] BYREF
  float v33; // [esp+C0h] [ebp-54h]
  float v34[19]; // [esp+C4h] [ebp-50h] BYREF

  v33 = -2.0;
  v34[0] = -2.0;
  v34[1] = 0.0;
  memset(&v34[15], 0, 16);
  v34[2] = -2.0;
  v34[3] = 2.0;
  v34[7] = 2.0;
  v32[0] = 0;
  v34[10] = 2.0;
  v32[1] = 0;
  v34[12] = 2.0;
  v34[13] = 2.0;
  v34[14] = 2.0;
  v18 = a2[2];
  v34[4] = -2.0;
  v3 = *((_BYTE *)a1 + 27);
  v34[5] = -2.0;
  v34[9] = -2.0;
  v17 = v3;
  v34[6] = 0.0;
  v4 = *a2;
  v34[8] = 0.0;
  v34[11] = 0.0;
  *(float *)&Str = COERCE_FLOAT(sub_8ACF00(v4, v17, v18, 1, v32));
  v5 = sub_640F20();
  v6 = *a2;
  v22 = v5;
  FFX_Menu2D_GetAtlasDimensions_structural(v6, &v20, &v21);
  LODWORD(v7) = *(unsigned __int8 *)a1;
  LODWORD(v8) = *((unsigned __int8 *)a1 + 1);
  v24 = a1[1];
  LODWORD(v9) = *((unsigned __int8 *)a1 + 2);
  LODWORD(v10) = *((unsigned __int8 *)a1 + 3);
  v11 = *((float *)a2 + 6) * a3 * flt_C5D778;
  v12 = *((float *)a1 + 2);
  v31[23] = 0.0;
  LODWORD(v31[21]) = 2000;
  v27[1] = v7;
  v27[2] = v8;
  v25 = v11 + v12;
  v27[3] = v9;
  v13 = *((float *)a2 + 2);
  v27[4] = v10;
  v31[1] = v7;
  v31[2] = v8;
  v31[3] = v9;
  v31[4] = v10;
  v26 = v13 / v20;
  v27[0] = *((float *)a2 + 3) / v21;
  v28 = *((float *)a2 + 7) * a3 * flt_C5D778 + *((float *)a1 + 1);
  v29 = flt_C5D778 * (a3 * (*((float *)a2 + 8) + *((float *)a2 + 6))) + *((float *)a1 + 2);
  v30 = *((float *)a2 + 4) / v20;
  v31[0] = *((float *)a2 + 5) / v21;
  if ( sub_8E5A20((float *)&v24, &v25, &v28, &v29, &v26, v27, &v30, v31) )
  {
    v14 = v22;
    Str_1 = Str;
    for ( i = 0; i < 8; ++i )
    {
      *(float *)&Str = v34[2 * i] / v14;
      Str_2 = Str;
      *(float *)&Str = v34[2 * i - 1] / v14;
      sub_640810((int)&v24, Str_1, *(float *)&Str, *(float *)&Str_2, 0);
      v14 = v22;
    }
  }
}
