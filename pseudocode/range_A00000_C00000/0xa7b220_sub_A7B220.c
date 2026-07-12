// Function: sub_A7B220
// Address: 0xa7b220
// Size: 0x64
// Prototype: 

int __cdecl sub_A7B220(int a1, int n15_1, int n15_2, int a4)
{
  int n15; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  int *i; // esi

  n15 = n15_1;
  if ( n15_1 >= 0 )
  {
    if ( n15_1 > 15 )
      n15 = 15;
  }
  else
  {
    n15 = 0;
  }
  v5 = a1;
  v6 = unk_22FB4DC[a1];
  if ( v6 )
  {
    n15 = *(_DWORD *)(v6 + 4 * n15 + 144);
    if ( n15 )
    {
      v7 = *(_DWORD *)(n15 + v6);
      for ( i = (int *)(n15 + v6 + 4); v7; --v7 )
      {
        n15 = *i++;
        if ( n15_2 == n15 )
        {
          n15 = sub_A7B460(v5, n15_2, a4);
          v5 = a1;
        }
      }
    }
  }
  return n15;
}

