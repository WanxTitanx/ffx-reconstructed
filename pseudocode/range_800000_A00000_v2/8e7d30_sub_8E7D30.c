// Function: sub_8E7D30
// Address: 0x8e7d30
void __cdecl sub_8E7D30(
        float a1,
        int a2,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        float a10,
        unsigned int a11,
        unsigned int a12)
{
  char *v12; // esi
  double v13; // st7
  double v14; // st7
  float v15; // [esp+4h] [ebp-A8h] BYREF
  float v16; // [esp+8h] [ebp-A4h] BYREF
  float v17; // [esp+Ch] [ebp-A0h]
  int v18[38]; // [esp+10h] [ebp-9Ch] BYREF
  float v19; // [esp+C4h] [ebp+18h]
  float v20; // [esp+C4h] [ebp+18h]
  int v21; // [esp+C4h] [ebp+18h]
  float v22; // [esp+C8h] [ebp+1Ch]
  float v23; // [esp+C8h] [ebp+1Ch]
  int v24; // [esp+C8h] [ebp+1Ch]

  v18[36] = 0;
  v18[37] = 0;
  v12 = FFX_Menu2D_TexHandleByAtlasId(16001);
  FFX_Menu2D_GetAtlasDimensions_structural(16001, &v15, &v16);
  *(float *)v18 = a1;
  v18[1] = a2;
  *(float *)&v18[8] = a1 + a3;
  v13 = *(float *)&a2 + a4;
  *(float *)&v18[9] = v13;
  FFX_Engine_GetTime();
  v19 = v13 * a9 + a5;
  v14 = v19 / v15;
  v20 = v14;
  FFX_Engine_GetTime();
  v22 = v14 * a10 + a6;
  v23 = v22 / v16;
  v17 = (float)(int)v20;
  *(float *)&v21 = v20 - v17;
  v17 = (float)(int)v23;
  v18[4] = (unsigned __int8)a11;
  *(float *)&v24 = v23 - v17;
  v18[5] = BYTE1(a11);
  v18[2] = v21;
  v18[3] = v24;
  v18[7] = HIBYTE(a11);
  v18[6] = BYTE2(a11);
  *(float *)&v18[10] = *(float *)&v21 + a7 / v15;
  *(float *)&v18[11] = *(float *)&v24 + a8 / v16;
  v18[12] = (unsigned __int8)a12;
  v18[13] = BYTE1(a12);
  v18[14] = BYTE2(a12);
  v18[15] = HIBYTE(a12);
  sub_63F090((int)v18, v12, 1, 0, 0.0);
}
