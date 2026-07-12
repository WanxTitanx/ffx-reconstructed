// Function: sub_A65750
// Address: 0xa65750
// Size: 0x6b
// Prototype: 

int __cdecl sub_A65750(int a1, int *a2)
{
  int v2; // eax

  v2 = *a2;
  if ( (*a2 & 0x2000) != 0 )
    return sub_A6BAE0(a1, a2);
  if ( (v2 & 4) != 0 )
  {
    if ( (v2 & 0x300) != 0 )
      return sub_A6BFE0(a1, a2);
    else
      return sub_A6B710(a1, a2);
  }
  else if ( (v2 & 0x80u) == 0 )
  {
    if ( (v2 & 0x300) != 0 )
      return sub_A6C8B0(a1, a2);
    else
      return sub_A6B220(a1, a2);
  }
  else if ( (v2 & 0x300) != 0 )
  {
    return sub_A6C3D0(a1, a2);
  }
  else
  {
    return sub_A6ACB0(a1, a2);
  }
}

