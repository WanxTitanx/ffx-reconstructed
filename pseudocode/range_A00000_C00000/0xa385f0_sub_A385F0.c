// Function: sub_A385F0
// Address: 0xa385f0
// Size: 0x75
// Prototype: 

int __cdecl sub_A385F0(_DWORD *i_1, unsigned __int8 *n4_2, int a3, int n4)
{
  int n4_1; // eax
  int v5; // ebx
  _DWORD *i; // edi
  int v7; // edi
  unsigned __int8 *n4_3; // esi
  _BYTE *i_2; // ebx

  n4_1 = n4;
  if ( n4 == 4 )
  {
    v5 = a3;
    n4_1 = (int)n4_2;
    for ( i = i_1; v5; --v5 )
    {
      *i++ = (*(_DWORD *)(n4_1 + 4) | *(_DWORD *)n4_1)
           - (((unsigned int)(*(_DWORD *)(n4_1 + 4) ^ *(_DWORD *)n4_1) >> 1) & 0x7F7F7F7F);
      n4_1 += 8;
    }
  }
  else if ( n4 == 1 )
  {
    v7 = a3;
    if ( a3 )
    {
      n4_3 = n4_2;
      i_2 = i_1;
      do
      {
        n4_1 = (n4_3[1] + *n4_3 + 1) / 2;
        *i_2++ = n4_1;
        n4_3 += 2;
        --v7;
      }
      while ( v7 );
    }
  }
  return n4_1;
}

