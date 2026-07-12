// Function: sub_A2E410
// Address: 0xa2e410
// Size: 0x4b

int __cdecl sub_A2E410(int a1)
{
  int v1; // ecx
  _DWORD *v2; // edx

  v1 = dword_1A85354; /*0xa2e413*/
  v2 = &dword_1A85354; /*0xa2e419*/
  if ( dword_1A85354 ) /*0xa2e420*/
  {
    while ( v1 + 8 != a1 + 8 ) /*0xa2e436*/
    {
      v2 = (_DWORD *)(v1 + 8); /*0xa2e438*/
      v1 = *(_DWORD *)(v1 + 8); /*0xa2e43b*/
      if ( !v1 ) /*0xa2e43f*/
        return 0; /*0xa2e445*/
    }
    if ( v1 ) /*0xa2e448*/
    {
      *v2 = *(_DWORD *)(v1 + 8); /*0xa2e44d*/
      *(_DWORD *)(v1 + 8) = 0; /*0xa2e44f*/
    }
  }
  return 0; /*0xa2e444*/
}