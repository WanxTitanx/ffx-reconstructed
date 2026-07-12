// Function: sub_8002B0
// Address: 0x8002B0
// Size: 0x2b

int __cdecl sub_8002B0(_BYTE *a1, char a2)
{
  int v3; // eax

  if ( *a1 != 2 )
    return -1;
  v3 = a2 & 1;
  if ( dword_23C3648[v3] )
    return -1;
  dword_23C3648[v3] = a1;
  return 0;
}
