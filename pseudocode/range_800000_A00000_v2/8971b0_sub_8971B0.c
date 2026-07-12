// Function: sub_8971B0
// Address: 0x8971b0
unsigned int sub_8971B0()
{
  unsigned int result; // eax
  double v1; // st7
  int KernelString_Table0; // esi
  int v3; // [esp+4h] [ebp-2Ch]
  float v4; // [esp+8h] [ebp-28h]
  float v5; // [esp+Ch] [ebp-24h]
  float v6; // [esp+Ch] [ebp-24h]
  float v7; // [esp+Ch] [ebp-24h]
  float v8; // [esp+10h] [ebp-20h]
  float v9; // [esp+10h] [ebp-20h]
  float v10; // [esp+10h] [ebp-20h]
  float v11; // [esp+14h] [ebp-1Ch]
  float v12; // [esp+14h] [ebp-1Ch]
  int v13; // [esp+1Ch] [ebp-14h]
  int v14; // [esp+24h] [ebp-Ch] BYREF
  double v15; // [esp+28h] [ebp-8h]

  result = n9_0[0] - 3;
  if ( result <= 1 )
  {
    v13 = unk_133D6FA;
    v1 = FFX_Menu2D_ScaleY_1080to416(511.0);
    sub_901300(n9_0[1], (int)v1, v13);
    v11 = FFX_Menu2D_ScaleY_1080to416(25.0);
    *((float *)&v15 + 1) = (double)unk_133D700 * 0.5;
    v8 = *((float *)&v15 + 1);
    v5 = FFX_Menu2D_ScaleY_1080to416(522.0);
    *((float *)&v15 + 1) = (float)MEMORY[0x133D6FC];
    FFX_Menu2D_DrawFilledRect(*((float *)&v15 + 1), v5, v8, v11, 0x80008AFF, 0x8036D2FF);
    v12 = FFX_Menu2D_ScaleY_1080to416(25.0);
    *((float *)&v15 + 1) = (double)unk_133D700 * 0.5;
    v9 = *((float *)&v15 + 1);
    v6 = FFX_Menu2D_ScaleY_1080to416(522.0);
    *((float *)&v15 + 1) = (double)unk_133D700 * 0.5 + (double)MEMORY[0x133D6FC];
    FFX_Menu2D_DrawFilledRect(*((float *)&v15 + 1), v6, v9, v12, 0x8036D2FF, 0x80008AFF);
    v15 = (double)MEMORY[0x133D702];
    v7 = FFX_Menu2D_ScaleY_1080to416(63.0);
    v4 = FFX_Menu2D_ScaleX_1920to512(48.0);
    *(float *)&v3 = FFX_Menu2D_ScaleY_1080to416(502.0);
    *((float *)&v15 + 1) = v15 - FFX_Menu2D_ScaleX_1920to512(24.0);
    FFX_Menu2D_DrawTexQuadSolid(
      0x190u,
      *((float *)&v15 + 1),
      v3,
      v4,
      v7,
      COERCE_INT(0.68945312),
      COERCE_INT(0.55957031),
      COERCE_INT(0.73632812),
      COERCE_INT(0.62109375));
    KernelString_Table0 = FFX_Btl_GetKernelString_Table0(12304, 0);
    sub_905290(KernelString_Table0, (int)&v14, 0, 0.77999997);
    v10 = FFX_Menu2D_ScaleY_1080to416(186.0);
    *((float *)&v15 + 1) = (512.0 - *(float *)&v14) * 0.5;
    return sub_9016B0(0, KernelString_Table0, *((float *)&v15 + 1), v10, 0, 0.77999997, 1.0);
  }
  return result;
}
