// Function: sub_8EE060
// Address: 0x8ee060
int __cdecl sub_8EE060(int a1, _BYTE *i_1, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int result; // eax
  _BYTE *i; // esi

  result = unknown_libname_654(a1);
  for ( i = i_1; *i; a3 += 10 )
    result = sub_8EEEE0(result, i++, a3, a4, a5, a6, a7, a8, a9);
  return result;
}
