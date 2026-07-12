// Function: sub_8EB270
// Address: 0x8eb270
int __cdecl sub_8EB270(
        int a1,
        int a2,
        int a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 a8)
{
  double v8; // st7
  double v9; // st6
  double v10; // st5
  char *Str; // [esp+Ch] [ebp-B4h]
  float v13; // [esp+14h] [ebp-ACh] BYREF
  float v14; // [esp+18h] [ebp-A8h] BYREF
  float v15; // [esp+1Ch] [ebp-A4h]
  int v16; // [esp+20h] [ebp-A0h]
  int v17; // [esp+24h] [ebp-9Ch] BYREF
  int v18; // [esp+28h] [ebp-98h] BYREF
  float v19; // [esp+2Ch] [ebp-94h] BYREF
  float v20[5]; // [esp+30h] [ebp-90h] BYREF
  float v21; // [esp+44h] [ebp-7Ch] BYREF
  float v22; // [esp+48h] [ebp-78h] BYREF
  float v23; // [esp+4Ch] [ebp-74h] BYREF
  float v24[27]; // [esp+50h] [ebp-70h] BYREF

  v24[25] = 0.0;
  v24[26] = 0.0;
  Str = FFX_Menu2D_TexHandleByAtlasId(15808);
  FFX_Menu2D_GetAtlasDimensions_structural(15808, &v14, &v13);
  v24[23] = 0.0;
  *(float *)&v16 = (float)a2;
  v8 = *(float *)&v16;
  v17 = v16;
  *(float *)&v16 = (float)a3;
  LODWORD(v20[1]) = a5;
  LODWORD(v20[2]) = a6;
  v9 = *(float *)&v16;
  v18 = v16;
  LODWORD(v20[3]) = a7;
  LODWORD(v20[4]) = a8;
  v16 = 15 * (a4 % 17);
  *(float *)&v16 = (float)v16;
  v10 = *(float *)&v16;
  v16 = 18 * (a4 / 17);
  v19 = v10 / v14;
  *(float *)&v16 = (float)v16;
  LODWORD(v24[1]) = a5;
  LODWORD(v24[2]) = a6;
  LODWORD(v24[3]) = a7;
  LODWORD(v24[4]) = a8;
  v20[0] = *(float *)&v16 / v13;
  v21 = v8 + 10.0;
  v22 = v9 + 16.0;
  v15 = (float)(15 * (a4 % 17) + 15);
  v23 = v15 / v14;
  v15 = (float)(18 * (a4 / 17) + 18);
  LODWORD(v24[21]) = 500;
  v24[0] = v15 / v13;
  if ( sub_8E5A20((float *)&v17, (float *)&v18, &v21, &v22, &v19, v20, &v23, v24) )
    sub_63F090((int)&v17, Str, 1, 0, 0.0);
  return a1;
}
