// Function: LuaGC_MarkTableDefault
// Address: 0x950170
int __cdecl LuaGC_MarkTableDefault(int a1, int a2)
{
  int v2; // edx
  int result; // eax
  unsigned int i; // ebx
  unsigned int j; // edx

  v2 = 0;
  result = *(_DWORD *)(a2 + 16);
  for ( i = result + 20 * (1 << *(_BYTE *)(a2 + 7)); v2 < *(_DWORD *)(a2 + 28); ++v2 )
  {
    result = *(_DWORD *)(a2 + 12);
    if ( (*(_BYTE *)(result + 8 * v2 + 4) & 0x40) != 0 )
    {
      result = *(_DWORD *)(result + 8 * v2);
      if ( (*(_BYTE *)(result + 5) & 3) != 0 )
        result = LuaGC_Mark(a1, result);
    }
  }
  for ( j = *(_DWORD *)(a2 + 16); j < i; j += 20 )
  {
    if ( *(_DWORD *)(j + 4) )
    {
      if ( (*(_BYTE *)(j + 12) & 0x40) != 0 )
      {
        result = *(_DWORD *)(j + 8);
        if ( (*(_BYTE *)(result + 5) & 3) != 0 )
          result = LuaGC_Mark(a1, *(_DWORD *)(j + 8));
      }
      if ( (*(_BYTE *)(j + 4) & 0x40) != 0 )
      {
        result = *(_DWORD *)j;
        if ( (*(_BYTE *)(*(_DWORD *)j + 5) & 3) != 0 )
          result = LuaGC_Mark(a1, *(_DWORD *)j);
      }
    }
    else if ( (*(_BYTE *)(j + 12) & 0x40) != 0 )
    {
      result = *(_DWORD *)(j + 8);
      if ( (*(_BYTE *)(result + 5) & 3) != 0 )
        *(_DWORD *)(j + 12) = 11;
    }
  }
  return result;
}
