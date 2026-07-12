// Function: sub_A72310
// Address: 0xa72310
// Size: 0x68

int __cdecl sub_A72310(int a1)
{
  int v1; // esi
  int v2; // edi
  int *v3; // ebx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  bool v7; // zf

  v1 = 0; /*0xa7231b*/
  v2 = 0; /*0xa7231d*/
  v3 = (int *)(a1 + 16); /*0xa7231f*/
  if ( *(_WORD *)(a1 + 4) ) /*0xa72322*/
  {
    do /*0xa7236e*/
    {
      v4 = unknown_libname_741(*v3) + 32; /*0xa7232f*/
      if ( *(_BYTE *)(v4 + 1) != 0xFF ) /*0xa72339*/
      {
        do /*0xa7235f*/
        {
          v5 = *(__int16 *)(v4 + 2); /*0xa72340*/
          v1 += 768 * v5; /*0xa7234a*/
          v6 = v4 + 28 * v5; /*0xa72355*/
          v7 = *(_BYTE *)(v6 + 33) == 0xFF; /*0xa72358*/
          v4 = v6 + 32; /*0xa7235c*/
        }
        while ( !v7 ); /*0xa7235f*/
      }
      ++v2; /*0xa72364*/
      v3 += 4; /*0xa72369*/
    }
    while ( v2 < *(unsigned __int16 *)(a1 + 4) ); /*0xa7236e*/
  }
  return v1 + 64; /*0xa72370*/
}