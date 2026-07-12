// Function: sub_A69F10
// Address: 0xa69f10
// Size: 0xcd
// Prototype: 

unsigned int __cdecl sub_A69F10(int a1, _WORD *a2, unsigned __int16 *i_1)
{
  unsigned __int16 *i_2; // ebx
  int v4; // esi
  int v5; // edx
  unsigned __int16 *i; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // esi
  _WORD *v10; // eax
  int v11; // edi
  int v12; // edx
  _WORD *j; // esi
  int v15; // [esp+1Ch] [ebp+10h]

  i_2 = i_1;
  v4 = a1;
  *(_DWORD *)a1 |= 8u;
  *(_DWORD *)(a1 + 28) = (char *)a2 - a1;
  v5 = 0;
  for ( i = i_1; v5 < *(__int16 *)(a1 + 18); i += 32 )
  {
    *i = 0;
    ++v5;
  }
  v7 = a1 + 32;
  v15 = a1 + 32;
  if ( *(_BYTE *)(a1 + 33) != 0xFF )
  {
    do
    {
      v8 = 0;
      v9 = v7 + 32;
      if ( *(__int16 *)(v7 + 2) > 0 )
      {
        do
        {
          sub_A69FE0(v9, i_2);
          ++v8;
          v9 += 28;
        }
        while ( v8 < *(__int16 *)(v15 + 2) );
      }
      v7 = v9;
      v15 = v9;
    }
    while ( *(_BYTE *)(v9 + 1) != 0xFF );
    v4 = a1;
  }
  *a2 = *(_WORD *)(v4 + 20);
  v10 = a2 + 8;
  v11 = 0;
  if ( *(__int16 *)(v4 + 18) > 0 )
  {
    do
    {
      v12 = *i_2;
      *v10++ = v12;
      for ( j = i_2 + 1; (__int16)v12 > 0; ++j )
      {
        *v10 = *j;
        --v12;
        ++v10;
      }
      ++v11;
      i_2 += 32;
    }
    while ( v11 < *(__int16 *)(a1 + 18) );
  }
  return ((unsigned int)v10 + 15) & 0xFFFFFFF0;
}

