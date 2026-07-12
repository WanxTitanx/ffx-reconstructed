// Function: LuaGC_MarkUserData
// Address: 0x950100
int __cdecl LuaGC_MarkUserData(int a1, _DWORD *a2)
{
  unsigned int i_1; // edx
  unsigned int i; // eax

  i_1 = a2[7];
  if ( !i_1 )
    return 1;
  for ( ; i_1 < a2[2]; i_1 += 8 )
  {
    if ( (*(_BYTE *)(i_1 + 4) & 0x40) != 0 && (*(_BYTE *)(*(_DWORD *)i_1 + 5) & 3) != 0 )
      LuaGC_Mark(a1, *(_DWORD *)i_1);
  }
  if ( *(_BYTE *)(a1 + 49) == 1 )
  {
    for ( i = a2[7] + 8 * a2[8]; i_1 < i; i_1 += 8 )
      *(_DWORD *)(i_1 + 4) = 0;
  }
  return 8 * a2[8] + 112;
}
