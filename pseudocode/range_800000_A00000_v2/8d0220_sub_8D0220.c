// Function: sub_8D0220
// Address: 0x8d0220
void __cdecl sub_8D0220(int a1, int a2, int a3, int a4, int a5)
{
  int n5; // esi
  double v6; // st7
  float v7; // [esp+0h] [ebp-20h]
  float v8; // [esp+1Ch] [ebp-4h]
  float v9; // [esp+38h] [ebp+18h]
  float v10; // [esp+38h] [ebp+18h]

  v8 = FFX_Menu2D_ScaleX_1920to512(210.0);
  v9 = (float)a5;
  n5 = 0;
  v10 = FFX_Menu2D_ScaleY_1080to416(599.0) + v9;
  v6 = v8;
  do
  {
    v7 = v6;
    sub_8D0140(a1, v7, v10, n5 + a3, a2);
    ++n5;
    v10 = FFX_Menu2D_ScaleY_1080to416(79.0) + v10;
    v6 = v8;
  }
  while ( n5 < 5 );
}
