// Function: sub_AA3590
// Address: 0xaa3590
// Size: 0xa4
// Prototype: 

int __fastcall sub_AA3590(_DWORD *a1, int a2, int a3, _DWORD *a4, int a5)
{
  int v5; // edi
  _DWORD *v6; // esi
  int result; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  int v11; // [esp+8h] [ebp-8h]

  v5 = *(_DWORD *)(a2 + 1284);
  if ( !a3 )
    return 0;
  v6 = a4;
  if ( !a4 )
    return 0;
  result = sub_A92150(a1, 4 * v5);
  v11 = result;
  if ( v5 > 0 )
  {
    v8 = a3 - (_DWORD)a4;
    v9 = result - (_DWORD)a4;
    do
    {
      v10 = (a5 * (*v6 & 0x7FFF) + (0x10000 - a5) * (*(_DWORD *)((char *)v6 + v8) & 0x7FFF) + 0x8000) >> 16;
      *(_DWORD *)((char *)v6 + v9) = v10;
      if ( (*(_DWORD *)((char *)v6 + v8) & 0x8000) != 0 && (*v6 & 0x8000) != 0 )
        *(_DWORD *)((char *)v6 + v9) = v10 | 0x8000;
      ++v6;
      --v5;
    }
    while ( v5 );
    return v11;
  }
  return result;
}

