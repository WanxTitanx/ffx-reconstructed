// Function: sub_A64F60
// Address: 0xa64f60
// Size: 0x1f
// Prototype: 

int __cdecl sub_A64F60(_WORD *a1, int a2)
{
  int result; // eax

  result = (int)a1;
  if ( (*a1 & 0xF000) != 0 )
    return nullsub_93("%7x e_weapon_shadow", a2);
  return result;
}

