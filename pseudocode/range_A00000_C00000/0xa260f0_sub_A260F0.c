// Function: sub_A260F0
// Address: 0xa260f0
// Size: 0xbb
// Prototype: 

int __stdcall sub_A260F0(int a1, int a2, char **a3)
{
  char *v3; // edx
  int v4; // eax
  char v5; // bl
  int n5381; // esi
  int v7; // eax
  int v8; // esi
  unsigned int v9; // ebx
  int v10; // edi
  int v11; // eax
  int v13; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  savedregs = (int)&savedregs;
  v3 = *a3;
  v4 = unk_1984C6C;
  v5 = **a3;
  v13 = unk_1984C6C;
  n5381 = 5381;
  if ( v5 )
  {
    do
    {
      v7 = v5;
      v5 = *++v3;
      n5381 = v7 + 33 * n5381;
    }
    while ( v5 );
    v4 = unk_1984C6C;
  }
  v8 = n5381 & 0x7FFFFFFF;
  v9 = 0;
  if ( (*(_DWORD *)(v4 + 16) & 0x7FFFFFFF) != 0 )
  {
    v10 = 0;
    do
    {
      v11 = *(_DWORD *)(v4 + 20);
      if ( *(_BYTE *)(v11 + v10) && *(_DWORD *)(v11 + v10 + 4) == v8 && a2 == sub_A28D10(*(_DWORD *)(v11 + v10 + 12)) )
        (*(void (__cdecl **)(_DWORD, char **))(*(_DWORD *)(v13 + 20) + v10 + 8))(
          *(_DWORD *)(*(_DWORD *)(v13 + 20) + v10 + 12),
          a3 + 4);
      ++v9;
      v10 += 16;
      v4 = v13;
    }
    while ( v9 < (*(_DWORD *)(v13 + 16) & 0x7FFFFFFFu) );
  }
  return 1;
}

