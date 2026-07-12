// Function: FFX_Menu2D_DrawFilledRect
// Address: 0x8f4b20
void __cdecl FFX_Menu2D_DrawFilledRect(float a1, float a2, float a3, float a4, unsigned int a5, unsigned int a6)
{
  int v6; // [esp+0h] [ebp-ACh] BYREF
  float v7; // [esp+4h] [ebp-A8h] BYREF
  int v8; // [esp+8h] [ebp-A4h] BYREF
  int v9; // [esp+Ch] [ebp-A0h] BYREF
  int v10[38]; // [esp+10h] [ebp-9Ch] BYREF

  v7 = a1;
  *(float *)&v6 = a2;
  *(float *)&v9 = a1 + a3;
  *(float *)&v8 = a2 + a4;
  if ( sub_8E58E0(&v7, (float *)&v6, (float *)&v9, (float *)&v8) )
  {
    *(float *)v10 = v7;
    v10[4] = (unsigned __int8)a5;
    v10[1] = v6;
    v10[8] = v9;
    v10[5] = BYTE1(a5);
    v10[9] = v8;
    v10[6] = BYTE2(a5);
    v10[7] = HIBYTE(a5);
    v10[12] = (unsigned __int8)a6;
    v10[13] = BYTE1(a6);
    v10[14] = BYTE2(a6);
    v10[34] = 0;
    v10[15] = HIBYTE(a6);
    sub_63F090((int)v10, 0, 1, 0, 0.0);
  }
}
