// Function: sub_816710
// Address: 0x816710
int __cdecl sub_816710(int a1, int a2)
{
  *(_WORD *)(*(_DWORD *)(a1 + 544) + 26) = *(_WORD *)(a2 + 2)
                                         + (*(_WORD *)(*((_DWORD *)&unk_12A40C4
                                                       + 8 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 544) + 20))
                                                     + 26)
                                          & 0x7FF0);
  return a2 + 4;
}
