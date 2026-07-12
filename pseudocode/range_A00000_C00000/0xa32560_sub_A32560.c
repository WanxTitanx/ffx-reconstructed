// Function: sub_A32560
// Address: 0xa32560
// Size: 0x5c
// Prototype: 

int __cdecl sub_A32560(const char *a1)
{
  int v1; // esi
  int v2; // eax

  if ( !a1 )
    return 0;
  v1 = unk_1A85578;
  if ( !unk_1A85578 )
    return 0;
  while ( 1 )
  {
    v2 = strcmp(*(const char **)(v1 + 4), a1);
    if ( v2 )
      v2 = v2 < 0 ? -1 : 1;
    if ( !v2 )
      break;
    v1 = *(_DWORD *)(v1 + 8);
    if ( !v1 )
      return 0;
  }
  return v1;
}

