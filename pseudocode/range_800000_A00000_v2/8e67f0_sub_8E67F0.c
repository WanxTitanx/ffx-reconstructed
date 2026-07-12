// Function: sub_8E67F0
// Address: 0x8e67f0
char __cdecl sub_8E67F0(int a1, float a2, float a3, float a4)
{
  _BYTE *v4; // edi
  char *v5; // esi
  char result; // al
  float v7; // [esp+4h] [ebp-30h]
  float v8; // [esp+8h] [ebp-2Ch]
  float v9; // [esp+Ch] [ebp-28h]
  float v10; // [esp+Ch] [ebp-28h]
  char v11; // [esp+10h] [ebp-24h]
  float v12; // [esp+10h] [ebp-24h]
  float v13; // [esp+14h] [ebp-20h]
  float v14; // [esp+14h] [ebp-20h]
  _BYTE v15[4]; // [esp+2Ch] [ebp-8h] BYREF
  float v16; // [esp+30h] [ebp-4h]
  float v17; // [esp+44h] [ebp+10h]
  float v18; // [esp+44h] [ebp+10h]

  v4 = (_BYTE *)sub_7ABBF0(a1, v15);
  v5 = (char *)sub_7ABE10(a1);
  v11 = v4[5] + 2 * v4[4] + 1;
  v9 = FFX_Menu2D_ScaleY_1080to416(46.0);
  v8 = FFX_Menu2D_ScaleX_1920to512(38.0);
  v16 = FFX_Menu2D_ScaleY_1080to416(7.0) + a3;
  v7 = v16;
  v16 = FFX_Menu2D_ScaleX_1920to512(180.0) + a2;
  sub_8E6AF0(v16, v7, v8, v9, v11, 128, 128, 128, 128);
  v16 = FFX_Menu2D_ScaleY_1080to416(8.0) + a3;
  v13 = v16;
  v16 = FFX_Menu2D_ScaleX_1920to512(240.0) + a2;
  FFX_Menu2D_DrawKernelString(v5, v16, v13, a4, 0.77999997);
  result = v4[4];
  if ( result == v4[6] )
  {
    v14 = FFX_Menu2D_ScaleY_1080to416(46.0);
    v12 = FFX_Menu2D_ScaleX_1920to512(38.0);
    v17 = FFX_Menu2D_ScaleY_1080to416(7.0) + a3;
    v10 = v17;
    v18 = FFX_Menu2D_ScaleX_1920to512(180.0) + a2;
    return sub_8E6AF0(v18, v10, v12, v14, 49, 128, 128, 128, 128);
  }
  return result;
}
