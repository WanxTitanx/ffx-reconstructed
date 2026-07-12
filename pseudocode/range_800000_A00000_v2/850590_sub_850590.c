// Function: sub_850590
// Address: 0x850590
int __cdecl sub_850590(char *j, int a2, int a3)
{
  int v3; // ebx
  char *j_1; // esi
  int i; // edi
  char *k; // ecx
  char *v7; // edx
  char v8; // al
  char *v9; // eax
  char *v10; // ebx
  int v11; // eax
  char Str[128]; // [esp+10h] [ebp-84h] BYREF

  v3 = a2;
  j_1 = j;
  for ( i = 0; *j_1; ++j_1 )
  {
    for ( k = j_1; *j_1; ++j_1 )
    {
      if ( *j_1 == 13 )
      {
        *j_1 = 0;
      }
      else if ( *j_1 == 10 )
      {
        *j_1 = 0;
        break;
      }
    }
    v7 = (char *)(Str - k);
    do
    {
      v8 = *k;
      k[(_DWORD)v7] = *k;
      ++k;
    }
    while ( v8 );
    if ( a3 )
    {
      v9 = strchr(Str, 46);
      v10 = v9;
      if ( !v9 )
        goto LABEL_18;
      v11 = strcmp(v9, ".anm");
      if ( v11 )
        v11 = v11 < 0 ? -1 : 1;
      if ( v11 )
      {
LABEL_18:
        v3 = a2;
      }
      else
      {
        *v10 = 0;
        v3 = a2;
        *(_DWORD *)(a2 + 4 * i++) = sub_83F050(Str);
      }
    }
    else
    {
      *(_DWORD *)(v3 + 4 * i++) = sub_83F050(Str);
    }
  }
  return i;
}
