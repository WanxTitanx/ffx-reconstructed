// Function: sub_8955D0
// Address: 0x8955d0
unsigned int sub_8955D0()
{
  unsigned int result; // eax
  double v1; // st7
  double v2; // st7
  _BYTE *KernelString_Table0; // esi
  float v4; // [esp+4h] [ebp-12Ch]
  int v5; // [esp+8h] [ebp-128h]
  float v6; // [esp+8h] [ebp-128h]
  float v7; // [esp+Ch] [ebp-124h]
  float v8; // [esp+Ch] [ebp-124h]
  float v9; // [esp+Ch] [ebp-124h]
  float v10; // [esp+10h] [ebp-120h]
  int v11; // [esp+10h] [ebp-120h]
  int v12; // [esp+14h] [ebp-11Ch]
  int v13; // [esp+18h] [ebp-118h]
  int v14; // [esp+18h] [ebp-118h]
  int KernelString_Table0_1; // [esp+20h] [ebp-110h] BYREF
  double n16; // [esp+24h] [ebp-10Ch]
  _BYTE KernelString_Table0_2[256]; // [esp+2Ch] [ebp-104h] BYREF

  result = (__int16)n7_5 - 3;
  if ( result <= 1 )
  {
    sub_901280(n16, (__int16)unk_133D6D8 + 10, (__int16)unk_133D6DA - 8, -2139062144);
    v10 = FFX_Menu2D_ScaleY_1080to416(25.0);
    *((float *)&n16 + 1) = FFX_Menu2D_ScaleX_1920to512(20.0) + (double)MEMORY[0x133D6CE];
    v7 = *((float *)&n16 + 1);
    *(float *)&v5 = FFX_Menu2D_ScaleY_1080to416(522.0);
    *((float *)&n16 + 1) = 160.0 - FFX_Menu2D_ScaleX_1920to512(10.0);
    FFX_Menu2D_DrawFilledRect(*((float *)&n16 + 1), v5, v7, v10, 0x80000000, 0x80000000);
    v13 = (int)(FFX_Menu2D_ScaleX_1920to512(20.0) + (double)MEMORY[0x133D6CE]);
    v12 = unk_133D6D4;
    v11 = unk_133D6D0;
    v8 = FFX_Menu2D_ScaleY_1080to416(25.0);
    v1 = FFX_Menu2D_ScaleX_1920to512(20.0);
    n16 = (double)n16;
    *((float *)&n16 + 1) = (v1 + (double)MEMORY[0x133D6CE]) * (n16 * 0.0625);
    v6 = *((float *)&n16 + 1);
    v4 = FFX_Menu2D_ScaleY_1080to416(522.0);
    *((float *)&n16 + 1) = 160.0 - FFX_Menu2D_ScaleX_1920to512(10.0);
    sub_8F4C40(*((float *)&n16 + 1), v4, v6, v8, v11, v12, v13);
    v14 = MEMORY[0x133D6CE];
    v2 = FFX_Menu2D_ScaleY_1080to416(511.0);
    sub_901300(160, (int)v2, v14);
    if ( IsPlaying == 1 )
    {
      KernelString_Table0 = (_BYTE *)FFX_Btl_GetKernelString_Table0(12306, 0);
    }
    else if ( IsPlaying )
    {
      KernelString_Table0 = (_BYTE *)KernelString_Table0_1;
    }
    else
    {
      sub_6414A0(744, KernelString_Table0_2, 256);
      KernelString_Table0 = KernelString_Table0_2;
    }
    sub_905290((int)KernelString_Table0, (int)&KernelString_Table0_1, 0, 0.77999997);
    v9 = FFX_Menu2D_ScaleY_1080to416(186.0);
    *((float *)&n16 + 1) = (512.0 - *(float *)&KernelString_Table0_1) * 0.5;
    return sub_9016B0(0, (int)KernelString_Table0, *((float *)&n16 + 1), v9, 0, 0.77999997, 1.0);
  }
  return result;
}
