// Function: sub_A7AE20
// Address: 0xa7ae20
// Size: 0x68
// Prototype: int __cdecl(float)

double __cdecl sub_A7AE20(float a1)
{
  double result; // st7
  double v2; // st5
  double v3; // st6
  double v4; // rt1
  double v5; // st5
  double v6; // st7
  double v7; // st5
  double v8; // rt0
  double v9; // st5
  double v10; // st7
  float v11; // [esp+8h] [ebp+8h]
  float v12; // [esp+8h] [ebp+8h]

  result = a1;
  v2 = 6.283184051513672;
  if ( a1 > 3.141592025756836 )
  {
    while ( 1 )
    {
      v4 = v2;
      v5 = result - v2;
      v6 = v4;
      v11 = v5;
      if ( v11 <= 3.141592025756836 )
        break;
      v2 = v6;
      result = v11;
    }
    v3 = v6;
    result = v11;
  }
  else
  {
    v3 = 6.283184051513672;
  }
  v7 = -3.141592025756836;
  if ( result < -3.141592025756836 )
  {
    while ( 1 )
    {
      v8 = v7;
      v9 = result;
      v10 = v8;
      v12 = v9 + v3;
      if ( v12 >= v8 )
        break;
      v7 = v10;
      result = v12;
    }
    return v12;
  }
  return result;
}

