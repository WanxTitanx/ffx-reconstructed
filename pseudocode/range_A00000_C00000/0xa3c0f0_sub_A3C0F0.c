// Function: sub_A3C0F0
// Address: 0xa3c0f0
// Size: 0x3f
// Prototype: _DWORD __cdecl(int, int, int i)

int __cdecl sub_A3C0F0(int a1, int a2, int i)
{
  int i_1; // ebx
  int v4; // edi

  i_1 = i;
  v4 = 0;
  if ( i > 0 )
  {
    do
    {
      v4 += 2 * a2 * a1;
      a1 = (a1 >> 1 == 0) + (a1 >> 1);
      a2 = (a2 >> 1 == 0) + (a2 >> 1);
      --i_1;
    }
    while ( i_1 );
  }
  return v4;
}

