// Function: sub_8E6970
// Address: 0x8e6970
unsigned __int8 __cdecl sub_8E6970(unsigned __int8 *a1, float a2, float a3, float a4)
{
  int v5; // eax
  char *v6; // esi
  unsigned __int8 result; // al
  float v8; // [esp+4h] [ebp-28h]
  float v9; // [esp+8h] [ebp-24h]
  float v10; // [esp+Ch] [ebp-20h]
  float v11; // [esp+Ch] [ebp-20h]
  char v12; // [esp+10h] [ebp-1Ch]
  float v13; // [esp+10h] [ebp-1Ch]
  float v14; // [esp+14h] [ebp-18h]
  float v15; // [esp+14h] [ebp-18h]
  float v16; // [esp+34h] [ebp+8h]
  float v17; // [esp+34h] [ebp+8h]
  float v18; // [esp+34h] [ebp+8h]
  float v19; // [esp+34h] [ebp+8h]
  float v20; // [esp+3Ch] [ebp+10h]
  float v21; // [esp+3Ch] [ebp+10h]

  v5 = sub_7852B0();
  v6 = (char *)sub_7A0C70(*(unsigned __int16 *)a1, a1[4], v5, 0);
  v12 = a1[5] + 2 * a1[4] + 1;
  v10 = FFX_Menu2D_ScaleY_1080to416(46.0);
  v9 = FFX_Menu2D_ScaleX_1920to512(38.0);
  v16 = FFX_Menu2D_ScaleY_1080to416(7.0) + a3;
  v8 = v16;
  v17 = FFX_Menu2D_ScaleX_1920to512(180.0) + a2;
  sub_8E6AF0(v17, v8, v9, v10, v12, 128, 128, 128, 128);
  v18 = FFX_Menu2D_ScaleY_1080to416(8.0) + a3;
  v14 = v18;
  v19 = FFX_Menu2D_ScaleX_1920to512(240.0) + a2;
  FFX_Menu2D_DrawKernelString(v6, v19, v14, a4, 0.77999997);
  result = a1[4];
  if ( result == a1[6] )
  {
    v15 = FFX_Menu2D_ScaleY_1080to416(46.0);
    v13 = FFX_Menu2D_ScaleX_1920to512(38.0);
    v20 = FFX_Menu2D_ScaleY_1080to416(7.0) + a3;
    v11 = v20;
    v21 = FFX_Menu2D_ScaleX_1920to512(180.0) + a2;
    return sub_8E6AF0(v21, v11, v13, v15, 49, 128, 128, 128, 128);
  }
  return result;
}
