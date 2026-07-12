// Function: sub_A9F070
// Address: 0xa9f070
// Size: 0x55
// Prototype: 

int __cdecl sub_A9F070(int a1, int a2, int a3, _DWORD *a4, int a5, int a6, int a7)
{
  int v7; // esi
  int v8; // edx
  _DWORD *v9; // ecx

  v7 = a6;
  v8 = 0;
  if ( a6 <= 0 )
    return 0;
  v9 = a4;
  do
  {
    if ( *(_DWORD *)((char *)v9 + a5 - (_DWORD)a4) )
      a4[v8++] = *v9;
    ++v9;
    --v7;
  }
  while ( v7 );
  if ( v8 )
    return sub_A9F3C0(a4, v8, a7);
  else
    return 0;
}

