// Function: sub_8F5C60
// Address: 0x8f5c60
int __cdecl sub_8F5C60(int a1, int a2)
{
  return FFX_Menu2D_DrawTexQuadTinted(
           0xFFFFFFFE,
           0.0,
           COERCE_INT(0.0),
           512.0,
           416.0,
           COERCE_INT(0.0),
           COERCE_INT(0.0),
           COERCE_INT(1920.0),
           COERCE_INT(1024.0),
           a1 & 0xFF000000,
           a2 & 0xFF000000);
}
