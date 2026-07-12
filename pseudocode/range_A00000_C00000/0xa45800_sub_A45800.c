// Function: sub_A45800
// Address: 0xa45800
// Size: 0x51
// Prototype: 

int __cdecl sub_A45800(int a1, int a2)
{
  unsigned __int8 v2; // bl
  int v3; // esi

  v2 = *(_BYTE *)(unk_2305834 + 40 * a2 + 2089);
  v3 = 0;
  while ( v3 == a1 || FFX_Party_IsMemberActive(v3) != 1 || ((unsigned __int8)(1 << v3) & v2) == 0 )
  {
    if ( ++v3 >= 7 )
      return 0;
  }
  return 1;
}

