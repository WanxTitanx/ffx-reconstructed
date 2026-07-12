// Function: sub_8E9750
// Address: 0x8e9750
int __cdecl sub_8E9750(
        int a1,
        int a2,
        int a3,
        int a4,
        unsigned __int8 n128,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 a8)
{
  int v8; // edx
  int v9; // esi
  __int16 v10; // cx
  double v11; // st7
  int v12; // eax
  char *Str; // [esp+Ch] [ebp-E0h]
  float v15; // [esp+18h] [ebp-D4h] BYREF
  float v16; // [esp+1Ch] [ebp-D0h] BYREF
  double v17; // [esp+20h] [ebp-CCh]
  double v18; // [esp+28h] [ebp-C4h]
  int v19[38]; // [esp+30h] [ebp-BCh] BYREF
  char *v20; // [esp+C8h] [ebp-24h]
  _DWORD v21[7]; // [esp+CCh] [ebp-20h]

  v20 = (char *)&loc_6DFFFF + 1;
  v21[0] = 8323236;
  v21[1] = (char *)&loc_6000A3 + 1;
  v21[2] = 7733479;
  v21[3] = (char *)&loc_600035 + 2;
  v21[4] = byte_6E0098;
  v21[5] = sub_600000;
  v21[6] = 6946861;
  unk_187168C = a1;
  v19[36] = 0;
  v19[37] = 0;
  Str = FFX_Menu2D_TexHandleByAtlasId(15808);
  FFX_Menu2D_GetAtlasDimensions_structural(15808, &v16, &v15);
  v19[34] = 0;
  v8 = SLOWORD(v21[2 * a2 - 1]);
  *(float *)v19 = (float)a3;
  HIDWORD(v18) = v8;
  v19[32] = 1;
  *(float *)&v19[1] = (float)a4;
  v17 = (double)v8;
  v9 = *((__int16 *)&v20 + 4 * a2 + 1);
  HIDWORD(v18) = v9;
  *(float *)&v19[2] = v17 / v16;
  v17 = (double)v9;
  v10 = v21[2 * a2];
  v11 = v17 / v15;
  v19[4] = n128;
  v19[5] = a6;
  v19[6] = a7;
  HIDWORD(v17) = a7;
  v12 = a3 + v10 - v8;
  LOWORD(v8) = HIWORD(v21[2 * a2]);
  v19[7] = a8;
  *(float *)&v19[3] = v11;
  *(float *)&v19[8] = (float)v12;
  *(float *)&v19[9] = (float)(a4 + (__int16)v8 - v9);
  v18 = (double)v10;
  *(float *)&v19[10] = v18 / v16;
  v18 = (double)(__int16)v8;
  v19[12] = n128;
  v19[13] = a6;
  v19[14] = a7;
  v19[15] = a8;
  *(float *)&v19[11] = v18 / v15;
  sub_63F090((int)v19, Str, 1, 0, 0.0);
  return unk_187168C;
}
