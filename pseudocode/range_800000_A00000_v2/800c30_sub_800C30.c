// Function: sub_800C30
// Address: 0x800c30
__int16 *__cdecl sub_800C30(int a1, __int16 a2)
{
  __int16 *i_1; // eax
  __int16 v3; // cx
  __int16 v4; // dx
  __int16 *i; // ecx

  i_1 = *(__int16 **)(a1 + 28);
  v3 = *i_1;
  if ( *i_1 >= 0 )
  {
    while ( v3 != a2 )
    {
      v3 = i_1[1];
      ++i_1;
      if ( v3 < 0 )
        return i_1;
    }
    v4 = i_1[1];
    for ( i = i_1 + 1; v4 >= 0; ++i )
    {
      *i_1 = v4;
      i_1 = i;
      v4 = i[1];
    }
    *i_1 = -1;
  }
  return i_1;
}
