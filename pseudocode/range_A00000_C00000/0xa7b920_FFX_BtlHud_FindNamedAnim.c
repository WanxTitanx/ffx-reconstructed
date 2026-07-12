// Function: FFX_BtlHud_FindNamedAnim
// Address: 0xa7b920
// Size: 0xa6
// Prototype: char *__cdecl(int n2, const char *btidu)

char *__cdecl FFX_BtlHud_FindNamedAnim(int n2, const char *btidu)
{
  int n2_1; // eax
  int v3; // ebx
  char v5; // dl
  char v6; // al
  const char *i; // ecx
  int v8; // esi
  int v9; // edi
  _DWORD *v10; // esi
  int v11; // eax

  n2_1 = n2;
  if ( n2 >= 0 )
  {
    if ( n2 > 7 )
      n2_1 = 7;
  }
  else
  {
    n2_1 = 0;
  }
  v3 = unk_22FB4DC[n2_1];
  if ( !v3 )
    return 0;
  v5 = 0;
  v6 = *btidu;
  for ( i = btidu + 1; v6; ++i )
  {
    v5 ^= v6;
    v6 = *i;
  }
  v8 = *(_DWORD *)(v3 + 4 * (v5 & 0xF) + 64);
  if ( !v8 )
    return 0;
  v9 = *(_DWORD *)(v8 + v3);
  v10 = (_DWORD *)(v3 + v8 + 4);
  if ( !v9 )
    return 0;
  while ( 1 )
  {
    v11 = strcmp((const char *)(v3 + *v10), btidu);
    if ( v11 )
      v11 = v11 < 0 ? -1 : 1;
    if ( !v11 )
      break;
    v10 += 3;
    if ( !--v9 )
      return 0;
  }
  return (char *)v10 - v3;
}

