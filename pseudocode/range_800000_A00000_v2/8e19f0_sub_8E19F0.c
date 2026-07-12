// Function: sub_8E19F0
// Address: 0x8e19f0
int __cdecl sub_8E19F0(unsigned int a1, float id, float ic, int n37, int n37_1)
{
  unsigned int n999; // esi
  double v6; // st7
  double idb_1; // st7
  double v8; // st7
  double idc_1; // st7
  double v10; // st7
  int v12; // [esp+1Ch] [ebp-1Ch] BYREF
  int v13; // [esp+20h] [ebp-18h] BYREF
  double ic_1; // [esp+24h] [ebp-14h]
  char Buffer[8]; // [esp+2Ch] [ebp-Ch] BYREF
  float ida; // [esp+44h] [ebp+Ch]
  float idb; // [esp+44h] [ebp+Ch]
  float idc; // [esp+44h] [ebp+Ch]

  LOWORD(v12) = 74;
  n999 = a1 / 0xE10;
  if ( a1 / 0xE10 > 0x3E7 )
    n999 = 999;
  sprintf(Buffer, "%02d", a1 / 0x3C % 0x3C);
  sub_905290((int)Buffer, (int)&v13, n37, 0.63);
  ida = id - *(float *)&v13;
  ic_1 = ic;
  v6 = FFX_Menu2D_ScaleY_1080to416(9.0);
  *((float *)&ic_1 + 1) = ic_1 - v6;
  FFX_Menu2D_DrawStatusEffectTimerBar((int)Buffer, ida, *((float *)&ic_1 + 1), n37, 0.63, COERCE_INT(1.5));
  sub_905290((int)&v12, (int)&v13, n37, 0.63);
  if ( FFX_Game_GetRegion() <= 0 || FFX_Game_GetRegion() >= 9 )
  {
    ic_1 = ida;
    idb_1 = ida - (sub_8FA570(0) + *(float *)&v13);
  }
  else
  {
    ic_1 = ida;
    idb_1 = ida - (sub_8FA570(0) * 2.0 + *(float *)&v13);
  }
  idb = idb_1;
  if ( n37_1 == 37 )
  {
    ic_1 = ic;
    v8 = FFX_Menu2D_ScaleY_1080to416(9.0);
    *((float *)&ic_1 + 1) = ic_1 - v8;
    FFX_Menu2D_DrawStatusEffectTimerBar((int)&v12, idb, *((float *)&ic_1 + 1), 37, 0.63, COERCE_INT(1.5));
  }
  sub_905230(n999, (int)&v13, 0.63, 1.5);
  if ( FFX_Game_GetRegion() <= 0 || FFX_Game_GetRegion() >= 9 )
  {
    ic_1 = idb;
    idc_1 = idb - (sub_8FA570(0) + *(float *)&v13);
  }
  else
  {
    ic_1 = idb;
    idc_1 = idb - (sub_8FA570(0) * 2.0 + *(float *)&v13);
  }
  idc = idc_1;
  ic_1 = ic;
  v10 = FFX_Menu2D_ScaleY_1080to416(9.0);
  *((float *)&ic_1 + 1) = ic_1 - v10;
  return sub_905820(n999, idc, *((float *)&ic_1 + 1), n37, 0.63, 1.5);
}
