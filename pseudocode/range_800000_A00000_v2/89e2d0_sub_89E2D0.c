// Function: sub_89E2D0
// Address: 0x89e2d0
unsigned __int8 *__cdecl sub_89E2D0(unsigned __int8 *a1, int a2)
{
  __int16 v3; // ax
  int v4; // edx
  int v6; // [esp+10h] [ebp+8h]

  if ( *a1 >= 0x30u )
    v3 = *a1 - 48;
  else
    v3 = a1[1] + 160;
  v4 = v3;
  *(_WORD *)(a2 + 2) = 20;
  *(float *)(a2 + 28) = (float)(unsigned __int8)byte_C58F03[4 * v3];
  *(float *)(a2 + 32) = 8.0;
  *(float *)(a2 + 8) = (float)(unsigned __int8)byte_C58F00[4 * v3];
  v6 = (unsigned __int8)byte_C58F01[4 * v3];
  *(float *)(a2 + 12) = (float)v6;
  *(float *)(a2 + 16) = *(float *)(a2 + 28) + *(float *)(a2 + 8);
  *(float *)(a2 + 20) = *(float *)(a2 + 12) + 8.0;
  *(_WORD *)(a2 + 38) = (unsigned __int8)byte_C58F02[4 * v4];
  *(_WORD *)(a2 + 4) = (byte_C58F02[4 * v4] & 8) != 0;
  return a1;
}
