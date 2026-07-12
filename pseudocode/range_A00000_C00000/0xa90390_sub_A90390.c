// Function: sub_A90390
// Address: 0xa90390
// Size: 0x83
// Prototype: 

int __fastcall sub_A90390(int a1, const char *a2)
{
  _DWORD *v4; // edx
  unsigned int v5; // ecx
  _BYTE *v6; // eax
  int v7; // edx
  _DWORD *v8; // ebx
  char v9; // cl

  *(_DWORD *)a1 = realloc_0(*(void **)a1, 4 * *(_DWORD *)(a1 + 8) + 8);
  v4 = realloc_0(*(void **)(a1 + 4), 4 * *(_DWORD *)(a1 + 8) + 8);
  *(_DWORD *)(a1 + 4) = v4;
  v5 = strlen(a2);
  v4[*(_DWORD *)(a1 + 8)] = v5;
  v6 = malloc_0(v5 + 1);
  v7 = *(_DWORD *)(a1 + 8);
  v8 = *(_DWORD **)a1;
  *(_DWORD *)(*(_DWORD *)a1 + 4 * v7) = v6;
  do
  {
    v9 = *a2;
    *v6++ = *a2++;
  }
  while ( v9 );
  *(_DWORD *)(a1 + 8) = v7 + 1;
  v8[v7 + 1] = 0;
  return v7 + 1;
}

