// Function: sub_8016A0
// Address: 0x8016a0
int __cdecl sub_8016A0(int a1, __int16 a2, int a3)
{
  __int16 v3; // dx
  int v4; // esi
  int v5; // eax

  v3 = 0;
  v4 = *(_DWORD *)(a1 + 4 * a3 + 16);
  if ( *(_WORD *)(a1 + 52) == 1 )
    return -1;
  v5 = 0;
  while ( *(__int16 *)(v4 + 2 * v5) >= 0 )
  {
    v5 = ++v3;
    if ( v3 >= (int)(unsigned __int16)(*(_WORD *)(a1 + 52) - 1) )
      return -1;
  }
  *(_WORD *)(v4 + 2 * v3) = a2;
  ++*(_WORD *)(a1 + 56);
  return 0;
}
