// Function: sub_8D0980
// Address: 0x8d0980
int sub_8D0980()
{
  int MenuSlotIndex; // esi
  float v2; // [esp+0h] [ebp-Ch]
  int v3; // [esp+4h] [ebp-8h]

  MenuSlotIndex = FFX_Party_GetMenuSlotIndex();
  sub_8DCE30();
  sub_8DCE30();
  sub_8C1770();
  sub_8C0BB0();
  sub_8F5C10();
  sub_8E71D0(5);
  *(float *)&v3 = FFX_Menu2D_ScaleY_1080to416(231.0);
  v2 = FFX_Menu2D_ScaleX_1920to512(210.0);
  sub_8FF490(MenuSlotIndex, v2, v3);
  sub_8D2240(MenuSlotIndex);
  return sub_8C0C90();
}
