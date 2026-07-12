// Function: sub_A64E40
// Address: 0xa64e40
// Size: 0x25
// Prototype: 

int __cdecl sub_A64E40(_WORD *a1)
{
  int n61440; // eax

  n61440 = 61440;
  if ( (*a1 & 0xF000) == 0 )
    return nullsub_93("%7x e_anmm(%4d)", a1, (__int16)a1[1]);
  return n61440;
}

