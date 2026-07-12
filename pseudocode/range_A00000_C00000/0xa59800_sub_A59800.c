// Function: sub_A59800
// Address: 0xa59800
// Size: 0x54
// Prototype: 

char __cdecl sub_A59800(int a1)
{
  __int16 n3; // ax

  LOBYTE(n3) = ++*(_BYTE *)(a1 + 41);
  if ( (unsigned __int8)n3 < 3u )
  {
    n3 = *(_WORD *)(a1 + 2)
       + ((unsigned __int64)(715827883LL * *(__int16 *)(a1 + 6)) >> 32)
       + *(__int16 *)(a1 + 6) * (unsigned __int8)n3 / 3
       + ((unsigned int)((unsigned __int64)(715827883LL * *(__int16 *)(a1 + 6)) >> 32) >> 31);
    *(_WORD *)(a1 + 10) = n3;
  }
  else
  {
    *(_BYTE *)(a1 + 35) = 0;
    *(_DWORD *)(a1 + 52) = 0;
  }
  return n3;
}

