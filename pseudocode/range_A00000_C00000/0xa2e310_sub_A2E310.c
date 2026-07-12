// Function: sub_A2E310
// Address: 0xa2e310
// Size: 0x5c

int __cdecl sub_A2E310(const char *a1)
{
  int v1; // esi
  int v2; // eax

  if ( !a1 ) /*0xa2e31a*/
    return 0; /*0xa2e31a*/
  v1 = unk_1A85354; /*0xa2e31c*/
  if ( !unk_1A85354 ) /*0xa2e324*/
    return 0; /*0xa2e360*/
  while ( 1 )
  {
    v2 = strcmp(*(const char **)(v1 + 4), a1); /*0xa2e334*/
    if ( v2 )
      v2 = v2 < 0 ? -1 : 1;
    if ( !v2 ) /*0xa2e357*/
      break; /*0xa2e357*/
    v1 = *(_DWORD *)(v1 + 8); /*0xa2e359*/
    if ( !v1 ) /*0xa2e35e*/
      return 0; /*0xa2e35e*/
  }
  return v1; /*0xa2e360*/
}