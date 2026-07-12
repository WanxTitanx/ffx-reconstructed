// Function: sub_A92150
// Address: 0xa92150
// Size: 0x60
// Prototype: 

int __fastcall sub_A92150(_DWORD *a1, int a2)
{
  size_t Size; // edi
  _DWORD *v4; // eax
  int v5; // ecx
  int result; // eax

  Size = (a2 + 7) & 0xFFFFFFF8;
  if ( (signed int)(Size + a1[18]) > a1[19] )
  {
    if ( a1[17] )
    {
      v4 = malloc_0(8u);
      a1[20] += a1[18];
      v4[1] = a1[21];
      *v4 = a1[17];
      a1[21] = v4;
    }
    a1[19] = Size;
    a1[17] = malloc_0(Size);
    a1[18] = 0;
  }
  v5 = a1[18];
  result = v5 + a1[17];
  a1[18] = Size + v5;
  return result;
}

