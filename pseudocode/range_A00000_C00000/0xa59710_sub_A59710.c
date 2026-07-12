// Function: sub_A59710
// Address: 0xa59710
// Size: 0x45
// Prototype: _DWORD __cdecl(int (__cdecl *sub_A49440)(int, int), _DWORD *)

int __cdecl sub_A59710(int (__cdecl *sub_A49440)(int, int), _DWORD *a2)
{
  int n0xFFFF; // eax
  int v3; // edi
  int v4; // esi

  n0xFFFF = dword_2305834[0];
  v3 = *(__int16 *)(dword_2305834[0] + 2);
  v4 = dword_2305834[0] + 2056;
  if ( *(_WORD *)(dword_2305834[0] + 2) )
  {
    n0xFFFF = 0xFFFF;
    do
    {
      --v3;
      if ( *(_WORD *)(v4 + 6) != 0xFFFF )
      {
        n0xFFFF = sub_A49440(v4, (int)a2);
        if ( n0xFFFF )
          return n0xFFFF;
        n0xFFFF = 0xFFFF;
      }
      v4 += 40;
    }
    while ( v3 );
  }
  return n0xFFFF;
}

