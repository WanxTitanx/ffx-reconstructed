// Function: sub_814610
// Address: 0x814610
int __cdecl sub_814610(int a1, int a2)
{
  int n10; // esi

  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    return a2;
  n10 = sub_83D7E0(LODWORD(flt_12A80C0[*(unsigned __int8 *)(*(_DWORD *)(a1 + 544) + 24)]));
  if ( n10 >= 10 )
  {
    nullsub_34();
    nullsub_35(1);
  }
  return a2 + *(__int16 *)(a2 + 2) + 2 * n10 + *(__int16 *)(a2 + *(__int16 *)(a2 + 2) + 2 * n10);
}
