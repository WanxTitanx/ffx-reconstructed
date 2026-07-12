// Function: sub_A38560
// Address: 0xa38560
// Size: 0x88
// Prototype: 

int __cdecl sub_A38560(_DWORD *a1, int a2, unsigned int *a3, int n4_2, int a5, int n4)
{
  int n4_1; // eax
  int v7; // ebx
  unsigned int *v8; // esi
  _DWORD *v9; // edi
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // edi
  unsigned __int8 *v13; // esi
  _BYTE *v14; // ebx
  int v15; // ecx
  int v16; // eax

  n4_1 = n4;
  if ( n4 == 4 )
  {
    v7 = a5;
    if ( a5 )
    {
      n4_1 = n4_2;
      v8 = a3;
      v9 = a1;
      do
      {
        v10 = *(unsigned int *)((char *)v8 + n4_1);
        v11 = *v8;
        v8 = (unsigned int *)((char *)v8 + 2 * n4_2);
        n4_1 = n4_2;
        *v9 = (v10 | v11) - (((v10 ^ v11) >> 1) & 0x7F7F7F7F);
        v9 = (_DWORD *)((char *)v9 + a2);
        --v7;
      }
      while ( v7 );
    }
  }
  else if ( n4 == 1 )
  {
    v12 = a5;
    if ( a5 )
    {
      n4_1 = n4_2;
      v13 = (unsigned __int8 *)a3;
      v14 = a1;
      do
      {
        v15 = v13[n4_1];
        v16 = *v13;
        v13 += 2 * n4_2;
        *v14 = (v15 + v16 + 1) / 2;
        v14 += a2;
        n4_1 = n4_2;
        --v12;
      }
      while ( v12 );
    }
  }
  return n4_1;
}

