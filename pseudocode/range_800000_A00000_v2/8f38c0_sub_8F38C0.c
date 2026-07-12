// Function: sub_8F38C0
// Address: 0x8f38c0
double __cdecl sub_8F38C0(int a1, int a2)
{
  double v2; // st7
  float v4; // [esp+8h] [ebp+8h]
  float v5; // [esp+8h] [ebp+8h]
  float v6; // [esp+8h] [ebp+8h]

  v4 = (float)a1;
  v2 = v4;
  v5 = (float)a2;
  v6 = v2 / v5;
  return (float)(v6 * v6);
}
