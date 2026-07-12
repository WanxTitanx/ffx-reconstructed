// Function: sub_8145A0
// Address: 0x8145a0
int __cdecl sub_8145A0(int a1, int a2)
{
  char *v2; // eax

  v2 = (char *)&unk_12A2280
     + 32 * sub_7FE890(LODWORD(flt_12A80C0[*(unsigned __int8 *)(*(_DWORD *)(a1 + 544) + 24)]), 0, 0);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      v2[23] &= ~1u;
      return a2 + 4;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    v2[23] |= 1u;
    return a2 + 4;
  }
}
