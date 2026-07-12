// Function: sub_A2F560
// Address: 0xa2f560
// Size: 0x7e
// Prototype: 

_DWORD *__cdecl sub_A2F560(_DWORD *a1, _DWORD *a2, int a3, double (__cdecl *a4)(int))
{
  float v5; // [esp+18h] [ebp-4h]
  float v6; // [esp+30h] [ebp+14h]
  float v7; // [esp+30h] [ebp+14h]

  v5 = a4(a3);
  v6 = v5 - a4((int)a2);
  if ( v6 >= 0.00000011920929 )
  {
    v7 = v5 / v6;
    sub_50ED40((int)a1, v7, a3, (int)a2);
    return a1;
  }
  else
  {
    *a1 = *a2;
    a1[1] = a2[1];
    a1[2] = a2[2];
    a1[3] = a2[3];
    return a1;
  }
}

