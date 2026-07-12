// Function: sub_8111B0
// Address: 0x8111b0
int __cdecl sub_8111B0(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int n127; // ecx

  v4 = sub_800F50(*(unsigned __int8 *)(*(_DWORD *)(a2 + 32) + (*(unsigned __int16 *)(a4 + 76) << 8) + 24));
  if ( (*(_WORD *)(a1 + 538) & 0x1000) != 0 )
  {
    LOBYTE(n127) = (byte_119FEDC[v4] - 1) & ((byte_119FEDC[v4] - 1 <= 0) - 1);
  }
  else
  {
    n127 = byte_119FEDC[v4] + 1;
    if ( n127 >= 127 )
    {
      byte_119FEDC[v4] = 127;
      return a3 + 2;
    }
  }
  byte_119FEDC[v4] = n127;
  return a3 + 2;
}
