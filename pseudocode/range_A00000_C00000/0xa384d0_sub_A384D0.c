// Function: sub_A384D0
// Address: 0xa384d0
// Size: 0x86
// Prototype: 

int __cdecl sub_A384D0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // esi
  int result; // eax
  int v9; // ecx
  int v10; // ebx
  int v11; // edi

  v7 = a4;
  if ( !a4 )
    return sub_A385F0(a1, a5, a3, a7);
  result = a3;
  if ( !a3 )
    return sub_A38560(a1, a2, a5, a6, a4, a7);
  v9 = a6;
  v10 = a1;
  v11 = a5;
  do
  {
    sub_A38670(v10, v11, v11 + v9, result, a7);
    v10 += a2;
    v11 += 2 * a6;
    result = a3;
    v9 = a6;
    --v7;
  }
  while ( v7 );
  return result;
}

