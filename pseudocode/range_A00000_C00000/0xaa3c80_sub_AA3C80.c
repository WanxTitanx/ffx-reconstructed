// Function: sub_AA3C80
// Address: 0xaa3c80
// Size: 0x8e
// Prototype: int __cdecl(int, int, int, void *)

int __cdecl sub_AA3C80(int a1, _DWORD *a2, int a3, void *a4)
{
  int v4; // ebx

  v4 = a2[5];
  sub_AA3EB0(a2);
  if ( a3 )
  {
    ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))sub_AA4FA0)(
      a2[*(_DWORD *)(a1 + 28) + 3],
      *a2,
      a3,
      a2[1],
      *(_DWORD *)(a3 + 4 * a2[1]),
      (float)*(int *)(v4 + 16));
    return 1;
  }
  else
  {
    memset(a4, 0, 4 * a2[*(_DWORD *)(a1 + 28) + 3]);
    return 0;
  }
}

