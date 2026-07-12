// Function: sub_A7B7D0
// Address: 0xa7b7d0
// Size: 0xb9
// Prototype: char *__cdecl(int, const char *)

char *__cdecl sub_A7B7D0(int n7_1, const char *a2)
{
  int n7; // eax
  char *result; // eax
  char v4; // dl
  char v5; // al
  const char *i; // ecx
  char v7; // al
  char *v8; // edx
  int v9; // esi
  int v10; // ebx
  char *v11; // esi
  int v12; // eax
  char *v13; // [esp+8h] [ebp+8h]

  n7 = n7_1;
  if ( n7_1 >= 0 )
  {
    if ( n7_1 > 7 )
      n7 = 7;
  }
  else
  {
    n7 = 0;
  }
  result = (char *)unk_22FB4DC[n7];
  v13 = result;
  if ( result )
  {
    v4 = 0;
    v5 = *a2;
    for ( i = a2 + 1; v5; ++i )
    {
      v4 ^= v5;
      v5 = *i;
    }
    v7 = v4;
    v8 = v13;
    v9 = *(_DWORD *)&v13[4 * (v7 & 0xF)];
    if ( v9 && (v10 = *(_DWORD *)&v13[v9], v11 = &v13[v9 + 4], v10) )
    {
      while ( 1 )
      {
        v12 = strcmp(&v8[(unsigned int)&unk_FFFFFF & *(_DWORD *)v11], a2);
        if ( v12 )
          v12 = v12 < 0 ? -1 : 1;
        if ( !v12 )
          break;
        v8 = v13;
        v11 += 4 * HIBYTE(*(_DWORD *)v11) + 4;
        if ( !--v10 )
          return 0;
      }
      return (char *)(v11 - v13);
    }
    else
    {
      return 0;
    }
  }
  return result;
}

