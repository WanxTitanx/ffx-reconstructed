// Function: sub_817670
// Address: 0x817670
int __cdecl sub_817670(int a1, int a2)
{
  int v2; // eax
  __int16 v3; // di
  int v4; // ecx
  _DWORD *i; // eax

  v2 = *(unsigned __int16 *)(a1 + 820);
  v3 = *(_WORD *)(a2 + 2);
  v4 = (unsigned __int16)(v3 - v2);
  for ( i = (_DWORD *)(*(_DWORD *)(a1 + 800) + (v2 << 8)); (__int16)v4 > 0; i += 64 )
  {
    *i = 0;
    i[1] = 0;
    i[2] = 0;
    --v4;
    i[3] = 0;
  }
  *(_WORD *)(a1 + 820) = v3;
  return a2 + 4;
}
