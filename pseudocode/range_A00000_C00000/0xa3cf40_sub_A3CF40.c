// Function: sub_A3CF40
// Address: 0xa3cf40
// Size: 0x7a
// Prototype: _DWORD __cdecl(_DWORD *, size_t Size)

int __cdecl sub_A3CF40(int *a1, size_t Size)
{
  int result; // eax
  _DWORD *v3; // edx
  size_t Size_1; // eax
  char v5; // zf
  int v6; // ecx

  if ( Size <= a1[1] )
  {
    v3 = dword_1A858B4;
    Size_1 = dword_1A858B4[622];
    if ( Size_1 <= Size )
      Size_1 = Size;
    dword_1A858B4[622] = Size_1;
    v5 = (a1[1] - a1[3] >= Size ? a1[3] : 0) == 0;
    a1[2] = a1[1] - a1[3] >= Size ? a1[3] : 0;
    result = sub_A3C070(v3[1], *a1, v5);
    if ( result )
    {
      v6 = a1[2];
      a1[3] = Size + v6;
      result += v6;
    }
  }
  else
  {
    IggyGDrawSendWarning(
      0,
      "GDraw dynamic vertex buffer usage of %d bytes in one call larger than buffer size %d",
      Size,
      a1[1]);
    return 0;
  }
  return result;
}

