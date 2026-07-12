// Function: sub_89E570
// Address: 0x89e570
char __cdecl sub_89E570(char *a1, char *a2)
{
  char *v2; // edx
  char n48; // al
  char *v4; // ecx
  _BYTE v5[45]; // [esp+1h] [ebp-31h]
  void *v6; // [esp+2Eh] [ebp-4h]

  v2 = a1;
  v6 = &loc_494847;
  n48 = *a1;
  if ( *a1 )
  {
    v4 = a2;
    while ( 1 )
    {
      if ( n48 >= 48 && n48 <= 57 )
        goto LABEL_10;
      if ( n48 != 32 )
        break;
      *v4 = 58;
LABEL_11:
      ++v4;
      ++v2;
LABEL_12:
      n48 = *v2;
      if ( !*v2 )
      {
        *v4 = 0;
        return n48;
      }
    }
    if ( n48 < 45 || n48 > 47 )
      goto LABEL_12;
    n48 = v5[n48];
LABEL_10:
    *v4 = n48;
    goto LABEL_11;
  }
  *a2 = 0;
  return (char)a2;
}
