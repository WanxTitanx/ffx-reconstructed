// Function: sub_814540
// Address: 0x814540
int __cdecl sub_814540(int a1, int a2)
{
  int v2; // esi

  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    return a2;
  v2 = sub_7E3720(*(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(*(_DWORD *)(a1 + 544) + 30) + 864), 5, *(__int16 *)(a2 + 2));
  sub_876210(7);
  sub_875F30(7, *(__int16 *)(a2 + 4), v2);
  return a2 + 6;
}
