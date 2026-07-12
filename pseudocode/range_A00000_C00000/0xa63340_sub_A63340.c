// Function: sub_A63340
// Address: 0xa63340
// Size: 0xaf
// Prototype: int __cdecl(char *String, int)

char *__cdecl sub_A63340(char *Buffer_1, char **a2)
{
  char *Buffer; // esi
  char n13; // al
  int v4; // edi
  char **v5; // ebx
  char *Buffer_2; // eax
  char v7; // al

  Buffer = Buffer_1;
  n13 = *Buffer_1;
  v4 = 0;
  if ( *Buffer_1 )
  {
    v5 = a2;
    while ( 1 )
    {
      if ( n13 == 13 )
      {
LABEL_20:
        ++Buffer;
LABEL_21:
        unk_22C92C0 = v4;
        return Buffer + 1;
      }
      if ( n13 == 10 )
        goto LABEL_21;
      if ( n13 != 32 && n13 != 9 )
        break;
LABEL_17:
      n13 = *++Buffer;
      if ( !n13 )
        goto LABEL_18;
    }
    if ( n13 == 48 && Buffer[1] == 120 )
    {
      Buffer += 2;
      sscanf(Buffer, "%x", &Buffer_1);
      Buffer_2 = Buffer_1;
    }
    else
    {
      Buffer_2 = (char *)atoi(Buffer);
      Buffer_1 = Buffer_2;
    }
    *v5++ = Buffer_2;
    ++v4;
    while ( 1 )
    {
      v7 = *++Buffer;
      if ( !v7 )
        break;
      switch ( v7 )
      {
        case 13:
          goto LABEL_20;
        case 10:
          goto LABEL_21;
        case 32:
        case 9:
          goto LABEL_17;
      }
    }
LABEL_18:
    if ( !v4 )
      goto LABEL_22;
    unk_22C92C0 = v4;
    return Buffer + 1;
  }
  else
  {
LABEL_22:
    unk_22C92C0 = v4;
    return (char *)-1;
  }
}

