// Function: RenderSurface_Recreate
// Address: 0xa0e4b0
// Size: 0x65
// Prototype: int __cdecl(int, int, int, char)

int __cdecl RenderSurface_Recreate(int a1, unsigned int a2, unsigned int a3, char a4)
{
  int result; // eax
  int *v5; // esi

  if ( !a1 ) /*0xa0e4b9*/
    return 1; /*0xa0e4b9*/
  if ( *(_BYTE *)(a1 + 4) ) /*0xa0e4c3*/
    return 1; /*0xa0e4c3*/
  v5 = *(int **)a1; /*0xa0e4c9*/
  if ( !*(_DWORD *)a1 ) /*0xa0e4c9*/
    return 1; /*0xa0e4bb*/
  if ( !a4 && v5[7] == a2 && v5[8] == a3 ) /*0xa0e4e5*/
    return 0; /*0xa0e4e5*/
  if ( !sub_596120(v5) || (result = sub_59CDD0(v5)) == 0 ) /*0xa0e4fb*/
  {
    result = sub_4C41C0(v5, a2, a3, *v5, 0); /*0xa0e505*/
    if ( !result ) /*0xa0e50c*/
      return 0; /*0xa0e50e*/
  }
  return result; /*0xa0e4c0*/
}