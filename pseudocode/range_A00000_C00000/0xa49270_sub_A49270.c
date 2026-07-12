// Function: sub_A49270
// Address: 0xa49270
// Size: 0x9d
// Prototype: 

BOOL __cdecl sub_A49270(float *a1, float *a2)
{
  double v2; // st7
  double v3; // st6
  float v5; // [esp+10h] [ebp-4h]

  if ( 9.9999998e10 != *a1 && *a2 != 9.9999998e10 )
  {
    v5 = *a2;
    v2 = *a1;
    if ( v5 <= v2 )
    {
      if ( v5 >= v2 )
        return sub_A57000(a1[1], a1[3], a2[1], a2[3]) != 0;
      v3 = a2[2];
    }
    else
    {
      v2 = v5;
      v3 = a1[2];
    }
    if ( v3 < v2 )
      return 0;
    return sub_A57000(a1[1], a1[3], a2[1], a2[3]) != 0;
  }
  return 0;
}

