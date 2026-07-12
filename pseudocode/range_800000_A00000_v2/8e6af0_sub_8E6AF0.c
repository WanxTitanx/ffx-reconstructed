// Function: sub_8E6AF0
// Address: 0x8e6af0
void __cdecl sub_8E6AF0(
        int a1,
        float a2,
        float a3,
        float a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 a8,
        unsigned __int8 a9)
{
  double v9; // st5
  char *Str; // [esp+Ch] [ebp-B4h]
  float v11; // [esp+14h] [ebp-ACh] BYREF
  float v12; // [esp+18h] [ebp-A8h] BYREF
  int v13; // [esp+1Ch] [ebp-A4h]
  float v14; // [esp+20h] [ebp-A0h]
  int v15; // [esp+24h] [ebp-9Ch] BYREF
  float v16; // [esp+28h] [ebp-98h] BYREF
  float v17; // [esp+2Ch] [ebp-94h] BYREF
  float v18[5]; // [esp+30h] [ebp-90h] BYREF
  float v19; // [esp+44h] [ebp-7Ch] BYREF
  float v20; // [esp+48h] [ebp-78h] BYREF
  float v21; // [esp+4Ch] [ebp-74h] BYREF
  float v22[27]; // [esp+50h] [ebp-70h] BYREF

  Str = FFX_Menu2D_TexHandleByAtlasId(15808);
  FFX_Menu2D_GetAtlasDimensions_structural(15808, &v12, &v11);
  v15 = a1;
  LODWORD(v18[1]) = a6;
  v16 = a2;
  LODWORD(v18[2]) = a7;
  v22[23] = 0.0;
  LODWORD(v18[3]) = a8;
  LODWORD(v18[4]) = a9;
  v13 = 15 * (a5 % 17);
  *(float *)&v13 = (float)v13;
  v9 = *(float *)&v13;
  v13 = 18 * (a5 / 17);
  v17 = v9 / v12;
  *(float *)&v13 = (float)v13;
  LODWORD(v22[1]) = a6;
  LODWORD(v22[2]) = a7;
  LODWORD(v22[3]) = a8;
  LODWORD(v22[4]) = a9;
  v18[0] = *(float *)&v13 / v11;
  v19 = *(float *)&a1 + a3;
  v20 = a2 + a4;
  v14 = (float)(15 * (a5 % 17) + 15);
  v21 = v14 / v12;
  v14 = (float)(18 * (a5 / 17) + 18);
  LODWORD(v22[21]) = 500;
  v22[0] = v14 / v11;
  if ( sub_8E5A20((float *)&v15, &v16, &v19, &v20, &v17, v18, &v21, v22) )
    sub_63F090((int)&v15, Str, 1, 0, 0.0);
}
