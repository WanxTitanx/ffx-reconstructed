// Function: sub_8FCE90
// Address: 0x8fce90
void __cdecl sub_8FCE90(int *a1, __int16 *a2)
{
  __int16 v2; // ax
  __int16 v3; // ax
  double v4; // st7
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  int i; // esi
  char v9; // [esp-4h] [ebp-11Ch]
  __int16 v10; // [esp+0h] [ebp-118h]
  float v11; // [esp+4h] [ebp-114h]
  float v12; // [esp+18h] [ebp-100h] BYREF
  float v13; // [esp+1Ch] [ebp-FCh] BYREF
  char *Str; // [esp+20h] [ebp-F8h]
  float v15; // [esp+24h] [ebp-F4h]
  float v16; // [esp+28h] [ebp-F0h]
  int v17[4]; // [esp+2Ch] [ebp-ECh] BYREF
  int v18; // [esp+3Ch] [ebp-DCh]
  int v19; // [esp+40h] [ebp-D8h]
  int v20; // [esp+44h] [ebp-D4h]
  int v21; // [esp+48h] [ebp-D0h]
  float v22; // [esp+4Ch] [ebp-CCh]
  float v23; // [esp+50h] [ebp-C8h]
  float v24; // [esp+54h] [ebp-C4h]
  float v25; // [esp+58h] [ebp-C0h]
  int v26; // [esp+5Ch] [ebp-BCh]
  int v27; // [esp+60h] [ebp-B8h]
  int v28; // [esp+64h] [ebp-B4h]
  int v29; // [esp+68h] [ebp-B0h]
  int n2001; // [esp+ACh] [ebp-6Ch]
  int v31; // [esp+B4h] [ebp-64h]
  _DWORD v32[2]; // [esp+BCh] [ebp-5Ch] BYREF
  float v33; // [esp+C4h] [ebp-54h]
  float v34[19]; // [esp+C8h] [ebp-50h]

  v33 = -2.0;
  v34[0] = -2.0;
  v34[1] = 0.0;
  v34[2] = -2.0;
  v2 = a2[2];
  v34[3] = 2.0;
  v10 = v2;
  LOBYTE(v2) = *((_BYTE *)a1 + 27);
  v34[4] = -2.0;
  v34[5] = -1.0;
  v9 = v2;
  v3 = *a2;
  v34[6] = 0.0;
  v34[8] = 0.0;
  v34[7] = -2.0;
  v32[0] = 0;
  v34[9] = 1.0;
  v32[1] = 0;
  v34[10] = 0.0;
  v34[12] = 0.0;
  v34[15] = 0.0;
  v34[11] = 2.0;
  v34[14] = 2.0;
  v34[16] = 2.0;
  v34[17] = 2.0;
  v34[18] = 2.0;
  v34[13] = -2.0;
  Str = (char *)sub_8ACF00(v3, v9, v10, 1, v32);
  v15 = sub_640F20();
  FFX_Menu2D_GetAtlasDimensions_structural(*a2, &v13, &v12);
  v4 = v15;
  v5 = *((unsigned __int8 *)a1 + 1);
  v6 = *((unsigned __int8 *)a1 + 2);
  v7 = *((unsigned __int8 *)a1 + 3);
  v18 = *(unsigned __int8 *)a1;
  v26 = v18;
  v31 = 0;
  n2001 = 2001;
  v19 = v5;
  v20 = v6;
  v21 = v7;
  v27 = v5;
  v28 = v6;
  v29 = v7;
  for ( i = 0; i < 10; ++i )
  {
    v17[0] = a1[1];
    *(float *)&v17[1] = flt_C5D784 * *((float *)a2 + 6) + *((float *)a1 + 2);
    *(float *)&v17[2] = *((float *)a2 + 2) / v13;
    *(float *)&v17[3] = *((float *)a2 + 3) / v12;
    v22 = *((float *)a2 + 7) * flt_C5D784 + *((float *)a1 + 1);
    v23 = flt_C5D784 * (*((float *)a2 + 8) + *((float *)a2 + 6)) + *((float *)a1 + 2);
    v24 = *((float *)a2 + 4) / v13;
    v25 = *((float *)a2 + 5) / v12;
    v16 = v34[2 * i] / v4;
    v11 = v16;
    v16 = v34[2 * i - 1] / v4;
    sub_640810((int)v17, Str, v16, v11, 0);
    v4 = v15;
  }
}
