// Function: sub_998900
// Address: 0x998900
int __thiscall sub_998900(float *this, int a2, float *a3)
{
  int result; // eax

  result = sub_997B00(this, (int)a3);
  if ( a2 )
  {
    *a3 = *a3 * -1.0;
    a3[1] = a3[1] * -1.0;
    a3[2] = -1.0 * a3[2];
  }
  return result;
}
