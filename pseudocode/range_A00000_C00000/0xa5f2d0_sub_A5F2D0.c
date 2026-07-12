// Function: sub_A5F2D0
// Address: 0xa5f2d0
// Size: 0x70

int __cdecl sub_A5F2D0(int *a1, int a2)
{
  *a1 = ((a2 - (int)a1) / 16 - 1) | 0x70000000; /*0xa5f2ea*/
  a1[2] = 0; /*0xa5f2ec*/
  a1[4] = 1; /*0xa5f2f3*/
  a1[5] = 805306368; /*0xa5f2fa*/
  a1[6] = -286331154; /*0xa5f301*/
  a1[7] = 0; /*0xa5f308*/
  a1[8] = 68; /*0xa5f30f*/
  a1[10] = 66; /*0xa5f316*/
  a1[12] = 196621; /*0xa5f31d*/
  a1[14] = 71; /*0xa5f324*/
  a1[16] = 1; /*0xa5f32b*/
  a1[18] = 20; /*0xa5f332*/
  return 80; /*0xa5f33e*/
}