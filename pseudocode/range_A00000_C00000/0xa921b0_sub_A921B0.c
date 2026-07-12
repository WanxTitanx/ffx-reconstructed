// Function: sub_A921B0
// Address: 0xa921b0
// Size: 0xce
// Prototype: int __cdecl(int, void *)

int __cdecl sub_A921B0(_DWORD *a1, char *a2)
{
  char *v2; // esi
  _DWORD *v3; // ebx
  int n7; // edi
  _QWORD *v5; // eax
  int v6; // esi
  _BYTE *v7; // eax

  v2 = a2;
  memset(a2, 0, 0x70u);
  *((_DWORD *)a2 + 16) = a1;
  *((_DWORD *)a2 + 19) = 0;
  *((_DWORD *)a2 + 17) = 0;
  if ( *a1 )
  {
    v3 = calloc_0(1u, 0x48u);
    memset(v3, 0, 0x48u);
    *((_DWORD *)a2 + 26) = v3;
    v3[1] = -971228160;
    n7 = 0;
    do
    {
      if ( n7 == 7 )
      {
        v3[10] = v2 + 4;
      }
      else
      {
        v5 = calloc_0(1u, 0x14u);
        *v5 = 0;
        v5[1] = 0;
        *((_DWORD *)v5 + 4) = 0;
        v3[n7 + 3] = v5;
      }
      v6 = v3[n7 + 3];
      *(_QWORD *)v6 = 0;
      *(_QWORD *)(v6 + 8) = 0;
      *(_DWORD *)(v6 + 16) = 0;
      v7 = malloc_0(0x100u);
      *(_DWORD *)(v6 + 8) = v7;
      *(_DWORD *)(v6 + 12) = v7;
      ++n7;
      *v7 = 0;
      *(_DWORD *)(v6 + 16) = 256;
      v2 = a2;
    }
    while ( n7 < 15 );
  }
  return 0;
}

