// Function: sub_A9ED90
// Address: 0xa9ed90
// Size: 0x56
// Prototype: 

int __cdecl sub_A9ED90(int a1, int a2, _DWORD *a3, int a4, int a5)
{
  int v5; // esi
  int v6; // edx
  _DWORD *v7; // ecx

  v5 = a5;
  v6 = 0;
  if ( a5 <= 0 )
    return 0;
  v7 = a3;
  do
  {
    if ( *(_DWORD *)((char *)v7 + a4 - (_DWORD)a3) )
      a3[v6++] = *v7;
    ++v7;
    --v5;
  }
  while ( v5 );
  if ( v6 )
    return sub_A9F130(a3, v6, sub_A93CA0);
  else
    return 0;
}

