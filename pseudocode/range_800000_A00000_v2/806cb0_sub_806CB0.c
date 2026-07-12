// Function: sub_806CB0
// Address: 0x806cb0
int __cdecl sub_806CB0(int i_2)
{
  int i_1; // ecx
  int i; // eax

  i_1 = i_2;
  for ( i = *(_DWORD *)(i_2 + 8); !*(_BYTE *)(i + 13); i = *(_DWORD *)(i + 8) )
    i_1 = i;
  return i_1;
}
