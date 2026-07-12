// Function: sub_8B08D0
// Address: 0x8b08d0
int __cdecl sub_8B08D0(int a1)
{
  int result; // eax

  result = sub_785F90(a1);
  dword_C59564 = a1 != 1 ? 18 : 4;
  *(_DWORD *)unk_1841CE8 = 0;
  unk_1841CEC = 0;
  unk_1841CF0 = 0;
  *(_DWORD *)unk_1841CF4 = 0;
  return result;
}
