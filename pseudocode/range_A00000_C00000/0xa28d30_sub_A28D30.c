// Function: sub_A28D30
// Address: 0xa28d30
// Size: 0x1e
// Prototype: 

double *__cdecl sub_A28D30(double *a1, int a2)
{
  double *result; // eax
  float v3; // [esp+8h] [ebp+8h]

  result = a1;
  if ( a1 )
  {
    *(_DWORD *)a1 = 4;
    v3 = (float)a2;
    result[1] = v3;
  }
  return result;
}

