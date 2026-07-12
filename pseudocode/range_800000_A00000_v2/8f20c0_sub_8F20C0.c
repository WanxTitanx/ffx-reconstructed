// Function: sub_8F20C0
// Address: 0x8f20c0
int __cdecl sub_8F20C0(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+4h] [ebp-20h]
  int v6; // [esp+20h] [ebp-4h]
  float v7; // [esp+20h] [ebp-4h]

  *(float *)&v6 = (float)a4;
  v5 = v6;
  v7 = (float)a3;
  FFX_Menu2D_DrawTexQuadSolid(
    0xC8u,
    v7,
    v5,
    213.0,
    20.0,
    COERCE_INT(0.44140625),
    COERCE_INT(0.32910156),
    COERCE_INT(0.44726562),
    COERCE_INT(0.39160156));
  return sub_8F1F00(a1, a2, a3 + 21, a4 + 5, 0x80808080);
}
