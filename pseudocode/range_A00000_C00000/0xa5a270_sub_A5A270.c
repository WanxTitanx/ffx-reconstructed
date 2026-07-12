// Function: sub_A5A270
// Address: 0xa5a270
// Size: 0x63
// Prototype: 

__int16 __cdecl sub_A5A270(int a1)
{
  unsigned __int8 n3; // al
  __int16 result; // ax

  n3 = ++*(_BYTE *)(a1 + 41);
  *(_BYTE *)(a1 + 35) = 1;
  if ( n3 < 3u )
  {
    result = *(_WORD *)(a1 + 2)
           + ((unsigned __int64)(715827883LL * *(__int16 *)(a1 + 6)) >> 32)
           + *(__int16 *)(a1 + 6) * (3 - n3) / 3
           + ((unsigned int)((unsigned __int64)(715827883LL * *(__int16 *)(a1 + 6)) >> 32) >> 31);
  }
  else
  {
    result = *(_WORD *)(a1 + 2);
    *(_DWORD *)(a1 + 52) = 0;
  }
  *(_WORD *)(a1 + 10) = result;
  return result;
}

