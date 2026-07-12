// Function: sub_8E6700
// Address: 0x8e6700
char __cdecl sub_8E6700(__int16 a1, float a2, float a3, float a4)
{
  char *MagicEntryById; // eax
  char *v5; // esi
  float v7; // [esp+4h] [ebp-2Ch]
  float v8; // [esp+8h] [ebp-28h]
  float v9; // [esp+Ch] [ebp-24h]
  char v10; // [esp+10h] [ebp-20h]
  float v11; // [esp+14h] [ebp-1Ch]
  float v12; // [esp+28h] [ebp-8h]
  float v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h] BYREF
  float v15; // [esp+40h] [ebp+10h]
  float v16; // [esp+40h] [ebp+10h]

  MagicEntryById = FFX_Battle_GetMagicEntryById(a1, &v14);
  v5 = (char *)(v14 + *(unsigned __int16 *)MagicEntryById);
  v10 = MagicEntryById[20];
  v9 = FFX_Menu2D_ScaleY_1080to416(46.0);
  v8 = FFX_Menu2D_ScaleX_1920to512(38.0);
  v12 = FFX_Menu2D_ScaleY_1080to416(7.0) + a3;
  v7 = v12;
  v13 = FFX_Menu2D_ScaleX_1920to512(180.0) + a2;
  sub_8E6AF0(v13, v7, v8, v9, v10, 128, 128, 128, 128);
  v15 = FFX_Menu2D_ScaleY_1080to416(8.0) + a3;
  v11 = v15;
  v16 = FFX_Menu2D_ScaleX_1920to512(240.0) + a2;
  return FFX_Menu2D_DrawKernelString(v5, v16, v11, a4, 0.77999997);
}
