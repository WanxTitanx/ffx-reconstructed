// Function: sub_A63620
// Address: 0xa63620
// Size: 0x411
// Prototype: 

int __cdecl sub_A63620(char *Buffer_1, int a2)
{
  char *Buffer; // eax
  char *v3; // ebx
  int n2; // esi
  char n26; // cl
  char n42; // cl
  _BYTE *v7; // ecx
  char *Buffer_2; // edi
  char n45; // bl
  char *v10; // eax
  int v12; // edi
  char *v13; // edx
  char n13; // cl
  char n34; // cl
  char n10; // cl
  char *v17; // edi
  char n26_2; // cl
  char *v19; // eax
  char n26_1; // cl

  Buffer = Buffer_1;
  v3 = (char *)a2;
  n2 = 0;
  *(_BYTE *)(a2 + 16) = 0;
  *(_BYTE *)(a2 + 528) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  while ( 1 )
  {
LABEL_2:
    while ( 1 )
    {
      n26 = *Buffer;
      if ( *Buffer != 59 )
        break;
      while ( n26 != 10 )
      {
        if ( n26 == 26 || !n26 )
          goto LABEL_107;
        n26 = *++Buffer;
        if ( n26 == 13 )
        {
          Buffer += 2;
          goto LABEL_2;
        }
      }
LABEL_22:
      ++Buffer;
    }
    if ( n26 == 47 )
      break;
    switch ( n26 )
    {
      case 13:
        Buffer += 2;
        break;
      case 10:
      case 9:
      case 32:
        goto LABEL_22;
      case 35:
        *((_DWORD *)v3 + 1) = Buffer;
        n2 = 0;
        ++Buffer;
        v7 = &unk_C87AA0;
        Buffer_2 = Buffer;
        n45 = 45;
LABEL_27:
        if ( n45 <= 0 )
        {
          nullsub_34();
          return -1;
        }
        while ( *v7 )
        {
          if ( *Buffer != *v7 )
          {
            for ( ; *v7; ++v7 )
              ;
            ++v7;
            ++n2;
            Buffer = Buffer_2;
            --n45;
            goto LABEL_27;
          }
          ++Buffer;
          ++v7;
        }
        if ( !n2 )
          goto LABEL_107;
        if ( n2 == 1 || n2 == 2 || n2 == 3 || n2 == 4 || n2 == 5 || n2 == 6 )
          goto LABEL_79;
        v3 = (char *)a2;
        if ( n2 != 7 && n2 != 8 )
        {
          if ( n2 == 9 || n2 == 10 || n2 == 11 )
            goto LABEL_79;
          if ( n2 != 12 && n2 != 13 )
          {
            if ( n2 == 14 || n2 == 15 || n2 == 16 )
              goto LABEL_79;
            if ( n2 != 17 && n2 != 18 )
            {
              if ( n2 == 19 || n2 == 20 || n2 == 21 )
                goto LABEL_79;
              if ( n2 != 22 && n2 != 23 )
              {
                switch ( n2 )
                {
                  case 24:
                  case 25:
                  case 26:
                    goto LABEL_79;
                  case 27:
                    continue;
                  case 28:
                  case 29:
                    goto LABEL_79;
                }
                if ( n2 != 30 && n2 != 31 )
                {
                  if ( n2 == 32
                    || n2 == 33
                    || n2 == 34
                    || n2 == 35
                    || n2 == 36
                    || n2 == 37
                    || n2 == 38
                    || n2 == 39
                    || n2 == 40
                    || n2 == 41
                    || n2 == 42
                    || n2 == 43
                    || n2 == 44 )
                  {
LABEL_79:
                    v10 = sub_A63340(Buffer, (char **)(a2 + 552));
                    *(_DWORD *)(a2 + 616) = unk_22C92C0;
                    *(_DWORD *)a2 = v10;
                    *(_DWORD *)(a2 + 8) = v10 - Buffer_1;
                    return n2;
                  }
LABEL_106:
                  n2 = -1;
LABEL_107:
                  *(_DWORD *)a2 = Buffer;
                  *(_DWORD *)(a2 + 8) = Buffer - Buffer_1;
                  return n2;
                }
              }
            }
          }
        }
        break;
      case 26:
      case 0:
        goto LABEL_106;
      default:
        goto LABEL_84;
    }
  }
  if ( *++Buffer == 42 )
  {
    while ( 1 )
    {
      n42 = *++Buffer;
      switch ( n42 )
      {
        case 26:
        case 0:
          goto LABEL_107;
        case 10:
          ++*((_DWORD *)v3 + 137);
          break;
        case 13:
          ++*((_DWORD *)v3 + 137);
          ++Buffer;
          break;
        default:
          if ( n42 == 42 && Buffer[1] == 47 )
          {
            Buffer += 2;
            goto LABEL_2;
          }
          break;
      }
    }
  }
  --Buffer;
LABEL_84:
  v12 = 0;
LABEL_85:
  if ( v12 )
  {
    v13 = v3 + 272;
  }
  else
  {
    v13 = v3 + 16;
    v12 = 1;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      n13 = *Buffer;
      if ( *Buffer == 59 )
        goto LABEL_116;
      if ( n13 == 13 )
        goto LABEL_121;
      if ( n13 == 10 )
        goto LABEL_122;
      if ( n13 != 32 )
        break;
      ++Buffer;
    }
    if ( n13 == 9 )
    {
      while ( 1 )
      {
        n34 = *++Buffer;
        switch ( n34 )
        {
          case 59:
            goto LABEL_116;
          case 13:
            goto LABEL_121;
          case 10:
            goto LABEL_122;
        }
        if ( n34 != 9 && n34 != 32 )
        {
          if ( n34 == 34 )
            goto LABEL_108;
          if ( n34 != 26 && n34 )
            goto LABEL_85;
          goto LABEL_106;
        }
      }
    }
    if ( n13 == 34 )
      break;
    if ( n13 == 26 || !n13 )
      goto LABEL_106;
    *v13++ = n13;
    ++Buffer;
    *v13 = 0;
    ++*((_DWORD *)v3 + 3);
  }
LABEL_108:
  n10 = *++Buffer;
  if ( n10 != 59 )
  {
    v17 = v3 + 528;
    while ( n10 != 13 )
    {
      if ( n10 == 10 )
        goto LABEL_122;
      if ( n10 == 26 || !n10 )
        goto LABEL_106;
      ++Buffer;
      if ( n10 == 34 )
      {
        n26_1 = *Buffer;
        if ( *Buffer == 13 )
          goto LABEL_121;
        while ( n26_1 != 10 )
        {
          if ( n26_1 == 26 || !n26_1 )
            goto LABEL_106;
          n26_1 = *++Buffer;
          if ( n26_1 == 13 )
            goto LABEL_121;
        }
        goto LABEL_122;
      }
      *v17++ = n10;
      *v17 = 0;
      n10 = *Buffer;
      if ( *Buffer == 59 )
        goto LABEL_116;
    }
    goto LABEL_121;
  }
LABEL_116:
  n26_2 = *Buffer;
  if ( *Buffer == 13 )
  {
LABEL_121:
    ++Buffer;
    goto LABEL_122;
  }
  while ( n26_2 != 10 )
  {
    if ( n26_2 == 26 || !n26_2 )
      goto LABEL_106;
    n26_2 = *++Buffer;
    if ( n26_2 == 13 )
      goto LABEL_121;
  }
LABEL_122:
  ++*((_DWORD *)v3 + 137);
  v19 = Buffer + 1;
  *(_DWORD *)a2 = v19;
  *(_DWORD *)(a2 + 8) = v19 - Buffer_1;
  return n2;
}

