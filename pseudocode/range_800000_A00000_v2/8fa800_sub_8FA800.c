// Function: sub_8FA800
// Address: 0x8fa800
double __cdecl sub_8FA800(int n32, float a2)
{
  double result; // st7
  float v3; // [esp+0h] [ebp-8h]

  n32_1 = n32;
  if ( n32 == 32 || n32 == 33 || n32 == 34 )
  {
    result = a2;
    v3 = a2;
LABEL_19:
    sub_9062B0(601, v3);
    return result;
  }
  if ( (unsigned int)(n32 - 64) <= 0xF )
  {
    result = a2;
    v3 = a2;
    if ( (n32 & 1) == 0 )
    {
      sub_9062B0(600, a2);
      return result;
    }
    goto LABEL_19;
  }
  if ( (unsigned int)(n32 - 48) <= 9 )
  {
    if ( sub_8ACEE0() != 1 || (unsigned int)(n32 - 49) > 1 )
    {
      sub_9062B0(n32 + 560, a2);
      return a2;
    }
    if ( n32 == 49 )
    {
      sub_9062B0(610, a2);
      return a2;
    }
    if ( n32 == 50 )
    {
      sub_9062B0(609, a2);
      return a2;
    }
  }
  if ( n32 != 96 )
    return 0.0;
  sub_9062B0(624, a2);
  return a2;
}
