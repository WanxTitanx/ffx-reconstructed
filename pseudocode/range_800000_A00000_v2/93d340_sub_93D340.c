// Function: sub_93D340
// Address: 0x93d340
int __cdecl sub_93D340(float *a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5[4]; // [esp+8h] [ebp-10h] BYREF

  sub_93D7D0((int)v5, a2, -1.0);
  sub_93D3D0(a1, v5);
  sub_93D7D0((int)v5, a3, -1.0);
  sub_93D3D0(a1 + 4, v5);
  sub_93D7D0((int)v5, a4, -1.0);
  result = sub_93D3D0(a1 + 8, v5);
  a1[14] = 0.0;
  a1[13] = 0.0;
  a1[12] = 0.0;
  a1[15] = 1.0;
  return result;
}
