// Function: sub_806C90
// Address: 0x806c90
int __cdecl sub_806C90(int i_2)
{
  int i_1; // ecx
  int i; // eax

  i_1 = i_2;
  for ( i = *(_DWORD *)(i_2 + 8); !*(_BYTE *)(i + 13); i = *(_DWORD *)(i + 8) )
    i_1 = i;
  return i_1;
}
